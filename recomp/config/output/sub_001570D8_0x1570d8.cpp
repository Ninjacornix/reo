#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001570D8
// Address: 0x1570d8 - 0x157d28
void sub_001570D8_0x1570d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001570D8_0x1570d8");
#endif

    switch (ctx->pc) {
        case 0x157390u: goto label_157390;
        default: break;
    }

    ctx->pc = 0x1570d8u;

    // 0x1570d8: 0xa0602d  daddu       $t4, $a1, $zero
    ctx->pc = 0x1570d8u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1570dc: 0x2403fffc  addiu       $v1, $zero, -0x4
    ctx->pc = 0x1570dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1570e0: 0x25820003  addiu       $v0, $t4, 0x3
    ctx->pc = 0x1570e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 12), 3));
    // 0x1570e4: 0x80582d  daddu       $t3, $a0, $zero
    ctx->pc = 0x1570e4u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1570e8: 0x434824  and         $t1, $v0, $v1
    ctx->pc = 0x1570e8u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x1570ec: 0xc0702d  daddu       $t6, $a2, $zero
    ctx->pc = 0x1570ecu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1570f0: 0x1891823  subu        $v1, $t4, $t1
    ctx->pc = 0x1570f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 12), GPR_U32(ctx, 9)));
    // 0x1570f4: 0x812a0000  lb          $t2, 0x0($t1)
    ctx->pc = 0x1570f4u;
    SET_GPR_S32(ctx, 10, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1570f8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1570f8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1570fc: 0x24630003  addiu       $v1, $v1, 0x3
    ctx->pc = 0x1570fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 3));
    // 0x157100: 0x91240000  lbu         $a0, 0x0($t1)
    ctx->pc = 0x157100u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157104: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157104u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157108: 0x91250000  lbu         $a1, 0x0($t1)
    ctx->pc = 0x157108u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15710c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15710cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157110: 0x91260000  lbu         $a2, 0x0($t1)
    ctx->pc = 0x157110u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157114: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157114u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157118: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157118u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15711c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15711cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157120: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157120u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157124: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157124u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157128: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x157128u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x15712c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15712cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157130: 0x1445025  or          $t2, $t2, $a0
    ctx->pc = 0x157130u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 4));
    // 0x157134: 0x91240000  lbu         $a0, 0x0($t1)
    ctx->pc = 0x157134u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157138: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157138u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x15713c: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x15713cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x157140: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157140u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157144: 0x1455025  or          $t2, $t2, $a1
    ctx->pc = 0x157144u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 5));
    // 0x157148: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157148u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15714c: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x15714cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x157150: 0x328c0  sll         $a1, $v1, 3
    ctx->pc = 0x157150u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x157154: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157154u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157158: 0x1044025  or          $t0, $t0, $a0
    ctx->pc = 0x157158u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 4));
    // 0x15715c: 0x1465025  or          $t2, $t2, $a2
    ctx->pc = 0x15715cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 6));
    // 0x157160: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157160u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157164: 0x28a20018  slti        $v0, $a1, 0x18
    ctx->pc = 0x157164u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)24) ? 1 : 0);
    // 0x157168: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157168u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x15716c: 0xaa5004  sllv        $t2, $t2, $a1
    ctx->pc = 0x15716cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 5) & 0x1F));
    // 0x157170: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x157170u;
    {
        const bool branch_taken_0x157170 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157170u;
            // 0x157174: 0x25290001  addiu       $t1, $t1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157170) {
            ctx->pc = 0x1571E8u;
            goto label_1571e8;
        }
    }
    ctx->pc = 0x157178u;
    // 0x157178: 0x24a5ffe8  addiu       $a1, $a1, -0x18
    ctx->pc = 0x157178u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967272));
    // 0x15717c: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x15717Cu;
    {
        const bool branch_taken_0x15717c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15717Cu;
            // 0x157180: 0x24020008  addiu       $v0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15717c) {
            ctx->pc = 0x1571A0u;
            goto label_1571a0;
        }
    }
    ctx->pc = 0x157184u;
    // 0x157184: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157184u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157188: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157188u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x15718c: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x15718cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157190: 0xa3602  srl         $a2, $t2, 24
    ctx->pc = 0x157190u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 24));
    // 0x157194: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x157194u;
    {
        const bool branch_taken_0x157194 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157194u;
            // 0x157198: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157194) {
            ctx->pc = 0x1571A8u;
            goto label_1571a8;
        }
    }
    ctx->pc = 0x15719Cu;
    // 0x15719c: 0x0  nop
    ctx->pc = 0x15719cu;
    // NOP
label_1571a0:
    // 0x1571a0: 0xa3602  srl         $a2, $t2, 24
    ctx->pc = 0x1571a0u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 24));
    // 0x1571a4: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1571a4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1571a8:
    // 0x1571a8: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1571a8u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1571ac: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1571acu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1571b0: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1571b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1571b4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1571b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1571b8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1571b8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1571bc: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1571bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1571c0: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1571c0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1571c4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1571c4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1571c8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1571c8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1571cc: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1571ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1571d0: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1571d0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1571d4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1571d4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1571d8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1571d8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1571dc: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1571DCu;
    {
        const bool branch_taken_0x1571dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1571E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1571DCu;
            // 0x1571e0: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1571dc) {
            ctx->pc = 0x1571F4u;
            goto label_1571f4;
        }
    }
    ctx->pc = 0x1571E4u;
    // 0x1571e4: 0x0  nop
    ctx->pc = 0x1571e4u;
    // NOP
label_1571e8:
    // 0x1571e8: 0xa3602  srl         $a2, $t2, 24
    ctx->pc = 0x1571e8u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 24));
    // 0x1571ec: 0xa5200  sll         $t2, $t2, 8
    ctx->pc = 0x1571ecu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
    // 0x1571f0: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1571f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
label_1571f4:
    // 0x1571f4: 0x24c3ff20  addiu       $v1, $a2, -0xE0
    ctx->pc = 0x1571f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967072));
    // 0x1571f8: 0xad660000  sw          $a2, 0x0($t3)
    ctx->pc = 0x1571f8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 6));
    // 0x1571fc: 0x2c620010  sltiu       $v0, $v1, 0x10
    ctx->pc = 0x1571fcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x157200: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x157200u;
    {
        const bool branch_taken_0x157200 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157204u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157200u;
            // 0x157204: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157200) {
            ctx->pc = 0x157258u;
            goto label_157258;
        }
    }
    ctx->pc = 0x157208u;
    // 0x157208: 0x24c3ff40  addiu       $v1, $a2, -0xC0
    ctx->pc = 0x157208u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967104));
    // 0x15720c: 0x2c620020  sltiu       $v0, $v1, 0x20
    ctx->pc = 0x15720cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x157210: 0x14400011  bnez        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x157210u;
    {
        const bool branch_taken_0x157210 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157210u;
            // 0x157214: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157210) {
            ctx->pc = 0x157258u;
            goto label_157258;
        }
    }
    ctx->pc = 0x157218u;
    // 0x157218: 0x240200bd  addiu       $v0, $zero, 0xBD
    ctx->pc = 0x157218u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 189));
    // 0x15721c: 0x14c20004  bne         $a2, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x15721Cu;
    {
        const bool branch_taken_0x15721c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x157220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15721Cu;
            // 0x157220: 0x240200bf  addiu       $v0, $zero, 0xBF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 191));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15721c) {
            ctx->pc = 0x157230u;
            goto label_157230;
        }
    }
    ctx->pc = 0x157224u;
    // 0x157224: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x157224u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x157228: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x157228u;
    {
        const bool branch_taken_0x157228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15722Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157228u;
            // 0x15722c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157228) {
            ctx->pc = 0x157258u;
            goto label_157258;
        }
    }
    ctx->pc = 0x157230u;
label_157230:
    // 0x157230: 0x14c20005  bne         $a2, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x157230u;
    {
        const bool branch_taken_0x157230 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        ctx->pc = 0x157234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157230u;
            // 0x157234: 0x240200be  addiu       $v0, $zero, 0xBE (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 190));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157230) {
            ctx->pc = 0x157248u;
            goto label_157248;
        }
    }
    ctx->pc = 0x157238u;
    // 0x157238: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x157238u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15723c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x15723Cu;
    {
        const bool branch_taken_0x15723c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15723Cu;
            // 0x157240: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15723c) {
            ctx->pc = 0x157258u;
            goto label_157258;
        }
    }
    ctx->pc = 0x157244u;
    // 0x157244: 0x0  nop
    ctx->pc = 0x157244u;
    // NOP
label_157248:
    // 0x157248: 0x54c20002  bnel        $a2, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x157248u;
    {
        const bool branch_taken_0x157248 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 2));
        if (branch_taken_0x157248) {
            ctx->pc = 0x15724Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157248u;
            // 0x15724c: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157254u;
            goto label_157254;
        }
    }
    ctx->pc = 0x157250u;
    // 0x157250: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x157250u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_157254:
    // 0x157254: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x157254u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_157258:
    // 0x157258: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x157258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15725c: 0xad640004  sw          $a0, 0x4($t3)
    ctx->pc = 0x15725cu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 4), GPR_U32(ctx, 4));
    // 0x157260: 0x14e20027  bne         $a3, $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x157260u;
    {
        const bool branch_taken_0x157260 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 2));
        ctx->pc = 0x157264u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157260u;
            // 0x157264: 0xad630008  sw          $v1, 0x8($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157260) {
            ctx->pc = 0x157300u;
            goto label_157300;
        }
    }
    ctx->pc = 0x157268u;
    // 0x157268: 0x28a20010  slti        $v0, $a1, 0x10
    ctx->pc = 0x157268u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x15726c: 0x1440001e  bnez        $v0, . + 4 + (0x1E << 2)
    ctx->pc = 0x15726Cu;
    {
        const bool branch_taken_0x15726c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15726Cu;
            // 0x157270: 0xa1402  srl         $v0, $t2, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15726c) {
            ctx->pc = 0x1572E8u;
            goto label_1572e8;
        }
    }
    ctx->pc = 0x157274u;
    // 0x157274: 0x24a5fff0  addiu       $a1, $a1, -0x10
    ctx->pc = 0x157274u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967280));
    // 0x157278: 0x10a00009  beqz        $a1, . + 4 + (0x9 << 2)
    ctx->pc = 0x157278u;
    {
        const bool branch_taken_0x157278 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x15727Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157278u;
            // 0x15727c: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157278) {
            ctx->pc = 0x1572A0u;
            goto label_1572a0;
        }
    }
    ctx->pc = 0x157280u;
    // 0x157280: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157280u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157284: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157284u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157288: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157288u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x15728c: 0xa1c02  srl         $v1, $t2, 16
    ctx->pc = 0x15728cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x157290: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157290u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157294: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x157294u;
    {
        const bool branch_taken_0x157294 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157294u;
            // 0x157298: 0xad63000c  sw          $v1, 0xC($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 12), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157294) {
            ctx->pc = 0x1572ACu;
            goto label_1572ac;
        }
    }
    ctx->pc = 0x15729Cu;
    // 0x15729c: 0x0  nop
    ctx->pc = 0x15729cu;
    // NOP
label_1572a0:
    // 0x1572a0: 0xa1402  srl         $v0, $t2, 16
    ctx->pc = 0x1572a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x1572a4: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1572a4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1572a8: 0xad62000c  sw          $v0, 0xC($t3)
    ctx->pc = 0x1572a8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 12), GPR_U32(ctx, 2));
label_1572ac:
    // 0x1572ac: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1572acu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1572b0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1572b0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1572b4: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1572b4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1572b8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1572b8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1572bc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1572bcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1572c0: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1572c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1572c4: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1572c4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1572c8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1572c8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1572cc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1572ccu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1572d0: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1572d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1572d4: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1572d4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1572d8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1572d8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1572dc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1572dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1572e0: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1572E0u;
    {
        const bool branch_taken_0x1572e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1572E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1572E0u;
            // 0x1572e4: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1572e0) {
            ctx->pc = 0x1572F4u;
            goto label_1572f4;
        }
    }
    ctx->pc = 0x1572E8u;
label_1572e8:
    // 0x1572e8: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x1572e8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x1572ec: 0xad62000c  sw          $v0, 0xC($t3)
    ctx->pc = 0x1572ecu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 12), GPR_U32(ctx, 2));
    // 0x1572f0: 0x24a50010  addiu       $a1, $a1, 0x10
    ctx->pc = 0x1572f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16));
label_1572f4:
    // 0x1572f4: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1572F4u;
    {
        const bool branch_taken_0x1572f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1572F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1572F4u;
            // 0x1572f8: 0x240d0006  addiu       $t5, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1572f4) {
            ctx->pc = 0x157364u;
            goto label_157364;
        }
    }
    ctx->pc = 0x1572FCu;
    // 0x1572fc: 0x0  nop
    ctx->pc = 0x1572fcu;
    // NOP
label_157300:
    // 0x157300: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x157300u;
    {
        const bool branch_taken_0x157300 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157300u;
            // 0x157304: 0x51023  negu        $v0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157300) {
            ctx->pc = 0x157320u;
            goto label_157320;
        }
    }
    ctx->pc = 0x157308u;
    // 0x157308: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157308u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x15730c: 0x1421025  or          $v0, $t2, $v0
    ctx->pc = 0x15730cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157310: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157310u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157314: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x157314u;
    {
        const bool branch_taken_0x157314 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157314u;
            // 0x157318: 0xad62000c  sw          $v0, 0xC($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157314) {
            ctx->pc = 0x157328u;
            goto label_157328;
        }
    }
    ctx->pc = 0x15731Cu;
    // 0x15731c: 0x0  nop
    ctx->pc = 0x15731cu;
    // NOP
label_157320:
    // 0x157320: 0xad6a000c  sw          $t2, 0xC($t3)
    ctx->pc = 0x157320u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 12), GPR_U32(ctx, 10));
    // 0x157324: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157324u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_157328:
    // 0x157328: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157328u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15732c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15732cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157330: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157330u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157334: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157334u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157338: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157338u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15733c: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x15733cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157340: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157340u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157344: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157344u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157348: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157348u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15734c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15734cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157350: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157350u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157354: 0x240d0008  addiu       $t5, $zero, 0x8
    ctx->pc = 0x157354u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x157358: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157358u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15735c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15735cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157360: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157360u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157364:
    // 0x157364: 0x24c2ff42  addiu       $v0, $a2, -0xBE
    ctx->pc = 0x157364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967106));
    // 0x157368: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x157368u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x15736c: 0x50400006  beql        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x15736Cu;
    {
        const bool branch_taken_0x15736c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15736c) {
            ctx->pc = 0x157370u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15736Cu;
            // 0x157370: 0x24060038  addiu       $a2, $zero, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 56));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157388u;
            goto label_157388;
        }
    }
    ctx->pc = 0x157374u;
    // 0x157374: 0xadcd0000  sw          $t5, 0x0($t6)
    ctx->pc = 0x157374u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 13));
    // 0x157378: 0x8d62000c  lw          $v0, 0xC($t3)
    ctx->pc = 0x157378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x15737c: 0x3e00008  jr          $ra
    ctx->pc = 0x15737Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15737Cu;
            // 0x157380: 0xad62001c  sw          $v0, 0x1C($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 28), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1571A0u: goto label_1571a0;
            case 0x1571A8u: goto label_1571a8;
            case 0x1571E8u: goto label_1571e8;
            case 0x1571F4u: goto label_1571f4;
            case 0x157230u: goto label_157230;
            case 0x157248u: goto label_157248;
            case 0x157254u: goto label_157254;
            case 0x157258u: goto label_157258;
            case 0x1572A0u: goto label_1572a0;
            case 0x1572ACu: goto label_1572ac;
            case 0x1572E8u: goto label_1572e8;
            case 0x1572F4u: goto label_1572f4;
            case 0x157300u: goto label_157300;
            case 0x157320u: goto label_157320;
            case 0x157328u: goto label_157328;
            case 0x157364u: goto label_157364;
            case 0x157388u: goto label_157388;
            case 0x157390u: goto label_157390;
            case 0x1573E0u: goto label_1573e0;
            case 0x1573F8u: goto label_1573f8;
            case 0x157418u: goto label_157418;
            case 0x157474u: goto label_157474;
            case 0x1574C8u: goto label_1574c8;
            case 0x1574D0u: goto label_1574d0;
            case 0x157500u: goto label_157500;
            case 0x157504u: goto label_157504;
            case 0x157540u: goto label_157540;
            case 0x157548u: goto label_157548;
            case 0x15755Cu: goto label_15755c;
            case 0x157574u: goto label_157574;
            case 0x1575D0u: goto label_1575d0;
            case 0x157600u: goto label_157600;
            case 0x157604u: goto label_157604;
            case 0x157640u: goto label_157640;
            case 0x157648u: goto label_157648;
            case 0x157698u: goto label_157698;
            case 0x1576C8u: goto label_1576c8;
            case 0x1576CCu: goto label_1576cc;
            case 0x157708u: goto label_157708;
            case 0x157710u: goto label_157710;
            case 0x157760u: goto label_157760;
            case 0x157788u: goto label_157788;
            case 0x157790u: goto label_157790;
            case 0x157794u: goto label_157794;
            case 0x1577ACu: goto label_1577ac;
            case 0x1577C8u: goto label_1577c8;
            case 0x157820u: goto label_157820;
            case 0x157850u: goto label_157850;
            case 0x157854u: goto label_157854;
            case 0x157890u: goto label_157890;
            case 0x157898u: goto label_157898;
            case 0x1578E8u: goto label_1578e8;
            case 0x157918u: goto label_157918;
            case 0x15791Cu: goto label_15791c;
            case 0x157958u: goto label_157958;
            case 0x157960u: goto label_157960;
            case 0x1579B0u: goto label_1579b0;
            case 0x1579E0u: goto label_1579e0;
            case 0x1579E4u: goto label_1579e4;
            case 0x157A20u: goto label_157a20;
            case 0x157A28u: goto label_157a28;
            case 0x157A78u: goto label_157a78;
            case 0x157AE0u: goto label_157ae0;
            case 0x157AE4u: goto label_157ae4;
            case 0x157B18u: goto label_157b18;
            case 0x157B1Cu: goto label_157b1c;
            case 0x157B58u: goto label_157b58;
            case 0x157B60u: goto label_157b60;
            case 0x157BB0u: goto label_157bb0;
            case 0x157BE0u: goto label_157be0;
            case 0x157BE4u: goto label_157be4;
            case 0x157C20u: goto label_157c20;
            case 0x157C28u: goto label_157c28;
            case 0x157C78u: goto label_157c78;
            case 0x157CA0u: goto label_157ca0;
            case 0x157CA8u: goto label_157ca8;
            case 0x157CACu: goto label_157cac;
            case 0x157CC4u: goto label_157cc4;
            case 0x157CE0u: goto label_157ce0;
            case 0x157CF4u: goto label_157cf4;
            case 0x157CF8u: goto label_157cf8;
            case 0x157CFCu: goto label_157cfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157384u;
    // 0x157384: 0x0  nop
    ctx->pc = 0x157384u;
    // NOP
label_157388:
    // 0x157388: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x157388u;
    {
        const bool branch_taken_0x157388 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15738Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157388u;
            // 0x15738c: 0x240400ff  addiu       $a0, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157388) {
            ctx->pc = 0x1573E0u;
            goto label_1573e0;
        }
    }
    ctx->pc = 0x157390u;
label_157390:
    // 0x157390: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x157390u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x157394: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157394u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157398: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157398u;
    {
        const bool branch_taken_0x157398 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157398) {
            ctx->pc = 0x15739Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157398u;
            // 0x15739c: 0xa5200  sll         $t2, $t2, 8 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1573E0u;
            goto label_1573e0;
        }
    }
    ctx->pc = 0x1573A0u;
    // 0x1573a0: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x1573a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x1573a4: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x1573a4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x1573a8: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1573a8u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1573ac: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1573acu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1573b0: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1573b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1573b4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1573b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1573b8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1573b8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1573bc: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1573bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1573c0: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1573c0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1573c4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1573c4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1573c8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1573c8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1573cc: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1573ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1573d0: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1573d0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1573d4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1573d4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1573d8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1573d8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1573dc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1573dcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_1573e0:
    // 0x1573e0: 0x28a20019  slti        $v0, $a1, 0x19
    ctx->pc = 0x1573e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)25) ? 1 : 0);
    // 0x1573e4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1573E4u;
    {
        const bool branch_taken_0x1573e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1573E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1573E4u;
            // 0x1573e8: 0xa1e02  srl         $v1, $t2, 24 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1573e4) {
            ctx->pc = 0x1573F8u;
            goto label_1573f8;
        }
    }
    ctx->pc = 0x1573ECu;
    // 0x1573ec: 0xc51023  subu        $v0, $a2, $a1
    ctx->pc = 0x1573ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x1573f0: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x1573f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x1573f4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1573f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_1573f8:
    // 0x1573f8: 0x1064ffe5  beq         $v1, $a0, . + 4 + (-0x1B << 2)
    ctx->pc = 0x1573F8u;
    {
        const bool branch_taken_0x1573f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1573FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1573F8u;
            // 0x1573fc: 0x28a2001f  slti        $v0, $a1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)31) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1573f8) {
            ctx->pc = 0x157390u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_157390;
        }
    }
    ctx->pc = 0x157400u;
    // 0x157400: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x157400u;
    {
        const bool branch_taken_0x157400 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157404u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157400u;
            // 0x157404: 0xa1f82  srl         $v1, $t2, 30 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157400) {
            ctx->pc = 0x157418u;
            goto label_157418;
        }
    }
    ctx->pc = 0x157408u;
    // 0x157408: 0x2402003e  addiu       $v0, $zero, 0x3E
    ctx->pc = 0x157408u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 62));
    // 0x15740c: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x15740cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157410: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157410u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157414: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x157414u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_157418:
    // 0x157418: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x157418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15741c: 0x1462004f  bne         $v1, $v0, . + 4 + (0x4F << 2)
    ctx->pc = 0x15741Cu;
    {
        const bool branch_taken_0x15741c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x157420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15741Cu;
            // 0x157420: 0x28a2001d  slti        $v0, $a1, 0x1D (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15741c) {
            ctx->pc = 0x15755Cu;
            goto label_15755c;
        }
    }
    ctx->pc = 0x157424u;
    // 0x157424: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x157424u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x157428: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157428u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15742c: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x15742Cu;
    {
        const bool branch_taken_0x15742c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x15742c) {
            ctx->pc = 0x157430u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15742Cu;
            // 0x157430: 0xa5080  sll         $t2, $t2, 2 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157474u;
            goto label_157474;
        }
    }
    ctx->pc = 0x157434u;
    // 0x157434: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157434u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157438: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157438u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x15743c: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x15743cu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157440: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157440u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157444: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157444u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157448: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157448u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15744c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15744cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157450: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157450u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157454: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157454u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157458: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157458u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15745c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15745cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157460: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157460u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157464: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157464u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157468: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157468u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15746c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15746cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157470: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157470u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157474:
    // 0x157474: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x157474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x157478: 0x14a20013  bne         $a1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x157478u;
    {
        const bool branch_taken_0x157478 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x15747Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157478u;
            // 0x15747c: 0xa37c2  srl         $a2, $t2, 31 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157478) {
            ctx->pc = 0x1574C8u;
            goto label_1574c8;
        }
    }
    ctx->pc = 0x157480u;
    // 0x157480: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157480u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157484: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157484u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157488: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157488u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15748c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x15748cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x157490: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157490u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157494: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157494u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157498: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157498u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15749c: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x15749cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1574a0: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1574a0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1574a4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1574a4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1574a8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1574a8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1574ac: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1574acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1574b0: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1574b0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1574b4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1574b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1574b8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1574b8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1574bc: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1574BCu;
    {
        const bool branch_taken_0x1574bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1574C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1574BCu;
            // 0x1574c0: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1574bc) {
            ctx->pc = 0x1574D0u;
            goto label_1574d0;
        }
    }
    ctx->pc = 0x1574C4u;
    // 0x1574c4: 0x0  nop
    ctx->pc = 0x1574c4u;
    // NOP
label_1574c8:
    // 0x1574c8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1574c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1574cc: 0xa5040  sll         $t2, $t2, 1
    ctx->pc = 0x1574ccu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
label_1574d0:
    // 0x1574d0: 0x28a20013  slti        $v0, $a1, 0x13
    ctx->pc = 0x1574d0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)19) ? 1 : 0);
    // 0x1574d4: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1574D4u;
    {
        const bool branch_taken_0x1574d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1574D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1574D4u;
            // 0x1574d8: 0xa24c2  srl         $a0, $t2, 19 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1574d4) {
            ctx->pc = 0x157540u;
            goto label_157540;
        }
    }
    ctx->pc = 0x1574DCu;
    // 0x1574dc: 0x24a5ffed  addiu       $a1, $a1, -0x13
    ctx->pc = 0x1574dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967277));
    // 0x1574e0: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1574E0u;
    {
        const bool branch_taken_0x1574e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1574E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1574E0u;
            // 0x1574e4: 0x2402000d  addiu       $v0, $zero, 0xD (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1574e0) {
            ctx->pc = 0x157500u;
            goto label_157500;
        }
    }
    ctx->pc = 0x1574E8u;
    // 0x1574e8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1574e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1574ec: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x1574ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x1574f0: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x1574f0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x1574f4: 0xa24c2  srl         $a0, $t2, 19
    ctx->pc = 0x1574f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 19));
    // 0x1574f8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1574F8u;
    {
        const bool branch_taken_0x1574f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1574FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1574F8u;
            // 0x1574fc: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1574f8) {
            ctx->pc = 0x157504u;
            goto label_157504;
        }
    }
    ctx->pc = 0x157500u;
label_157500:
    // 0x157500: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157500u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_157504:
    // 0x157504: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157504u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157508: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157508u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15750c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15750cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157510: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157510u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157514: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157514u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157518: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157518u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15751c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15751cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157520: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157520u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157524: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157524u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157528: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157528u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15752c: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x15752cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157530: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157530u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157534: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157534u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157538: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157538u;
    {
        const bool branch_taken_0x157538 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15753Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157538u;
            // 0x15753c: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157538) {
            ctx->pc = 0x157548u;
            goto label_157548;
        }
    }
    ctx->pc = 0x157540u;
label_157540:
    // 0x157540: 0xa5340  sll         $t2, $t2, 13
    ctx->pc = 0x157540u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 13));
    // 0x157544: 0x24a5000d  addiu       $a1, $a1, 0xD
    ctx->pc = 0x157544u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 13));
label_157548:
    // 0x157548: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x157548u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x15754c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x15754cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x157550: 0x46200b  movn        $a0, $v0, $a2
    ctx->pc = 0x157550u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
    // 0x157554: 0xad640010  sw          $a0, 0x10($t3)
    ctx->pc = 0x157554u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 16), GPR_U32(ctx, 4));
    // 0x157558: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x157558u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
label_15755c:
    // 0x15755c: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x15755Cu;
    {
        const bool branch_taken_0x15755c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15755Cu;
            // 0x157560: 0xa1f02  srl         $v1, $t2, 28 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 10), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15755c) {
            ctx->pc = 0x157574u;
            goto label_157574;
        }
    }
    ctx->pc = 0x157564u;
    // 0x157564: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x157564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x157568: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157568u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15756c: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x15756cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157570: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x157570u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
label_157574:
    // 0x157574: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x157574u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x157578: 0x14620093  bne         $v1, $v0, . + 4 + (0x93 << 2)
    ctx->pc = 0x157578u;
    {
        const bool branch_taken_0x157578 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x15757Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157578u;
            // 0x15757c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157578) {
            ctx->pc = 0x1577C8u;
            goto label_1577c8;
        }
    }
    ctx->pc = 0x157580u;
    // 0x157580: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x157580u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x157584: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157584u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157588: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157588u;
    {
        const bool branch_taken_0x157588 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157588) {
            ctx->pc = 0x15758Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157588u;
            // 0x15758c: 0xa5100  sll         $t2, $t2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1575D0u;
            goto label_1575d0;
        }
    }
    ctx->pc = 0x157590u;
    // 0x157590: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157590u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157594: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157594u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157598: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157598u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15759c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15759cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1575a0: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1575a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1575a4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1575a4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1575a8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1575a8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1575ac: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1575acu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1575b0: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1575b0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1575b4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1575b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1575b8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1575b8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1575bc: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1575bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1575c0: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1575c0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1575c4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1575c4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1575c8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1575c8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1575cc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1575ccu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_1575d0:
    // 0x1575d0: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x1575d0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x1575d4: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1575D4u;
    {
        const bool branch_taken_0x1575d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1575D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1575D4u;
            // 0x1575d8: 0xa3f42  srl         $a3, $t2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 10), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1575d4) {
            ctx->pc = 0x157640u;
            goto label_157640;
        }
    }
    ctx->pc = 0x1575DCu;
    // 0x1575dc: 0x24a5ffe3  addiu       $a1, $a1, -0x1D
    ctx->pc = 0x1575dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967267));
    // 0x1575e0: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1575E0u;
    {
        const bool branch_taken_0x1575e0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1575E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1575E0u;
            // 0x1575e4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1575e0) {
            ctx->pc = 0x157600u;
            goto label_157600;
        }
    }
    ctx->pc = 0x1575E8u;
    // 0x1575e8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1575e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1575ec: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x1575ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x1575f0: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x1575f0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x1575f4: 0xa3f42  srl         $a3, $t2, 29
    ctx->pc = 0x1575f4u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 10), 29));
    // 0x1575f8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1575F8u;
    {
        const bool branch_taken_0x1575f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1575FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1575F8u;
            // 0x1575fc: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1575f8) {
            ctx->pc = 0x157604u;
            goto label_157604;
        }
    }
    ctx->pc = 0x157600u;
label_157600:
    // 0x157600: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157600u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_157604:
    // 0x157604: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157604u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157608: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157608u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15760c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15760cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157610: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157610u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157614: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157614u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157618: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157618u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15761c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15761cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157620: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157620u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157624: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157624u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157628: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157628u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15762c: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x15762cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157630: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157630u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157634: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157634u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157638: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157638u;
    {
        const bool branch_taken_0x157638 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15763Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157638u;
            // 0x15763c: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157638) {
            ctx->pc = 0x157648u;
            goto label_157648;
        }
    }
    ctx->pc = 0x157640u;
label_157640:
    // 0x157640: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x157640u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x157644: 0x24a50003  addiu       $a1, $a1, 0x3
    ctx->pc = 0x157644u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_157648:
    // 0x157648: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157648u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15764c: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x15764cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157650: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157650u;
    {
        const bool branch_taken_0x157650 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157650) {
            ctx->pc = 0x157654u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157650u;
            // 0x157654: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157698u;
            goto label_157698;
        }
    }
    ctx->pc = 0x157658u;
    // 0x157658: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157658u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x15765c: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x15765cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157660: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157660u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157664: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157664u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157668: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157668u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15766c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15766cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157670: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157670u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157674: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157674u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157678: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157678u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x15767c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15767cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157680: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157680u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157684: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157684u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157688: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157688u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x15768c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15768cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157690: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157690u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157694: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157694u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157698:
    // 0x157698: 0x28a20011  slti        $v0, $a1, 0x11
    ctx->pc = 0x157698u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x15769c: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x15769Cu;
    {
        const bool branch_taken_0x15769c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1576A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15769Cu;
            // 0x1576a0: 0xa3442  srl         $a2, $t2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15769c) {
            ctx->pc = 0x157708u;
            goto label_157708;
        }
    }
    ctx->pc = 0x1576A4u;
    // 0x1576a4: 0x24a5ffef  addiu       $a1, $a1, -0x11
    ctx->pc = 0x1576a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967279));
    // 0x1576a8: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1576A8u;
    {
        const bool branch_taken_0x1576a8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1576ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1576A8u;
            // 0x1576ac: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1576a8) {
            ctx->pc = 0x1576C8u;
            goto label_1576c8;
        }
    }
    ctx->pc = 0x1576B0u;
    // 0x1576b0: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1576b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1576b4: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x1576b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x1576b8: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x1576b8u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x1576bc: 0xa3442  srl         $a2, $t2, 17
    ctx->pc = 0x1576bcu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
    // 0x1576c0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1576C0u;
    {
        const bool branch_taken_0x1576c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1576C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1576C0u;
            // 0x1576c4: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1576c0) {
            ctx->pc = 0x1576CCu;
            goto label_1576cc;
        }
    }
    ctx->pc = 0x1576C8u;
label_1576c8:
    // 0x1576c8: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1576c8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1576cc:
    // 0x1576cc: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1576ccu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1576d0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1576d0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1576d4: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1576d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1576d8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1576d8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1576dc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1576dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1576e0: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1576e0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1576e4: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1576e4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1576e8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1576e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1576ec: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1576ecu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1576f0: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1576f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1576f4: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1576f4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1576f8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1576f8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1576fc: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1576fcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157700: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157700u;
    {
        const bool branch_taken_0x157700 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157700u;
            // 0x157704: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157700) {
            ctx->pc = 0x157710u;
            goto label_157710;
        }
    }
    ctx->pc = 0x157708u;
label_157708:
    // 0x157708: 0xa53c0  sll         $t2, $t2, 15
    ctx->pc = 0x157708u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 15));
    // 0x15770c: 0x24a5000f  addiu       $a1, $a1, 0xF
    ctx->pc = 0x15770cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
label_157710:
    // 0x157710: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157710u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157714: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157714u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157718: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157718u;
    {
        const bool branch_taken_0x157718 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157718) {
            ctx->pc = 0x15771Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157718u;
            // 0x15771c: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157760u;
            goto label_157760;
        }
    }
    ctx->pc = 0x157720u;
    // 0x157720: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157720u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157724: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157724u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157728: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157728u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15772c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15772cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157730: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157730u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157734: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157734u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157738: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157738u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15773c: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x15773cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157740: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157740u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157744: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157744u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157748: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157748u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15774c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15774cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157750: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157750u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157754: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157754u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157758: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157758u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15775c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15775cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157760:
    // 0x157760: 0x28a20011  slti        $v0, $a1, 0x11
    ctx->pc = 0x157760u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x157764: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x157764u;
    {
        const bool branch_taken_0x157764 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157764u;
            // 0x157768: 0xa2442  srl         $a0, $t2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157764) {
            ctx->pc = 0x157790u;
            goto label_157790;
        }
    }
    ctx->pc = 0x15776Cu;
    // 0x15776c: 0x24a5ffef  addiu       $a1, $a1, -0x11
    ctx->pc = 0x15776cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967279));
    // 0x157770: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x157770u;
    {
        const bool branch_taken_0x157770 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157770u;
            // 0x157774: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157770) {
            ctx->pc = 0x157788u;
            goto label_157788;
        }
    }
    ctx->pc = 0x157778u;
    // 0x157778: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157778u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15777c: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x15777cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157780: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157780u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157784: 0xa2442  srl         $a0, $t2, 17
    ctx->pc = 0x157784u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
label_157788:
    // 0x157788: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x157788u;
    {
        const bool branch_taken_0x157788 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15778Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157788u;
            // 0x15778c: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157788) {
            ctx->pc = 0x157794u;
            goto label_157794;
        }
    }
    ctx->pc = 0x157790u;
label_157790:
    // 0x157790: 0x24a5000f  addiu       $a1, $a1, 0xF
    ctx->pc = 0x157790u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
label_157794:
    // 0x157794: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157794u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157798: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157798u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x15779c: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x15779Cu;
    {
        const bool branch_taken_0x15779c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1577A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15779Cu;
            // 0x1577a0: 0x61b40  sll         $v1, $a2, 13 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 13));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15779c) {
            ctx->pc = 0x1577ACu;
            goto label_1577ac;
        }
    }
    ctx->pc = 0x1577A4u;
    // 0x1577a4: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x1577a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x1577a8: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x1577a8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
label_1577ac:
    // 0x1577ac: 0x71700  sll         $v0, $a3, 28
    ctx->pc = 0x1577acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 28));
    // 0x1577b0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1577b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1577b4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1577b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1577b8: 0x42082  srl         $a0, $a0, 2
    ctx->pc = 0x1577b8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 2));
    // 0x1577bc: 0xad630018  sw          $v1, 0x18($t3)
    ctx->pc = 0x1577bcu;
    WRITE32(ADD32(GPR_U32(ctx, 11), 24), GPR_U32(ctx, 3));
    // 0x1577c0: 0x1000014d  b           . + 4 + (0x14D << 2)
    ctx->pc = 0x1577C0u;
    {
        const bool branch_taken_0x1577c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1577C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1577C0u;
            // 0x1577c4: 0x441025  or          $v0, $v0, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1577c0) {
            ctx->pc = 0x157CF8u;
            goto label_157cf8;
        }
    }
    ctx->pc = 0x1577C8u;
label_1577c8:
    // 0x1577c8: 0x54620145  bnel        $v1, $v0, . + 4 + (0x145 << 2)
    ctx->pc = 0x1577C8u;
    {
        const bool branch_taken_0x1577c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1577c8) {
            ctx->pc = 0x1577CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1577C8u;
            // 0x1577cc: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157CE0u;
            goto label_157ce0;
        }
    }
    ctx->pc = 0x1577D0u;
    // 0x1577d0: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1577d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1577d4: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x1577d4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1577d8: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x1577D8u;
    {
        const bool branch_taken_0x1577d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1577d8) {
            ctx->pc = 0x1577DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1577D8u;
            // 0x1577dc: 0xa5100  sll         $t2, $t2, 4 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 4));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157820u;
            goto label_157820;
        }
    }
    ctx->pc = 0x1577E0u;
    // 0x1577e0: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x1577e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x1577e4: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x1577e4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x1577e8: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1577e8u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1577ec: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1577ecu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1577f0: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1577f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1577f4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1577f4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1577f8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1577f8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1577fc: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1577fcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157800: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157800u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157804: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157804u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157808: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157808u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15780c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15780cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157810: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157810u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157814: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157814u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157818: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157818u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15781c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15781cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157820:
    // 0x157820: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x157820u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x157824: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x157824u;
    {
        const bool branch_taken_0x157824 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157824u;
            // 0x157828: 0xa3f42  srl         $a3, $t2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 10), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157824) {
            ctx->pc = 0x157890u;
            goto label_157890;
        }
    }
    ctx->pc = 0x15782Cu;
    // 0x15782c: 0x24a5ffe3  addiu       $a1, $a1, -0x1D
    ctx->pc = 0x15782cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967267));
    // 0x157830: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x157830u;
    {
        const bool branch_taken_0x157830 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157830u;
            // 0x157834: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157830) {
            ctx->pc = 0x157850u;
            goto label_157850;
        }
    }
    ctx->pc = 0x157838u;
    // 0x157838: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157838u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x15783c: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x15783cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157840: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157840u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157844: 0xa3f42  srl         $a3, $t2, 29
    ctx->pc = 0x157844u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 10), 29));
    // 0x157848: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x157848u;
    {
        const bool branch_taken_0x157848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15784Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157848u;
            // 0x15784c: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157848) {
            ctx->pc = 0x157854u;
            goto label_157854;
        }
    }
    ctx->pc = 0x157850u;
label_157850:
    // 0x157850: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157850u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_157854:
    // 0x157854: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157854u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157858: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157858u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15785c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15785cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157860: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157860u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157864: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157864u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157868: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157868u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15786c: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x15786cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157870: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157870u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157874: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157874u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157878: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157878u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15787c: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x15787cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157880: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157880u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157884: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157884u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157888: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157888u;
    {
        const bool branch_taken_0x157888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15788Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157888u;
            // 0x15788c: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157888) {
            ctx->pc = 0x157898u;
            goto label_157898;
        }
    }
    ctx->pc = 0x157890u;
label_157890:
    // 0x157890: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x157890u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x157894: 0x24a50003  addiu       $a1, $a1, 0x3
    ctx->pc = 0x157894u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_157898:
    // 0x157898: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157898u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15789c: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x15789cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1578a0: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x1578A0u;
    {
        const bool branch_taken_0x1578a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1578a0) {
            ctx->pc = 0x1578A4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1578A0u;
            // 0x1578a4: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1578E8u;
            goto label_1578e8;
        }
    }
    ctx->pc = 0x1578A8u;
    // 0x1578a8: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x1578a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x1578ac: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x1578acu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x1578b0: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1578b0u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1578b4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1578b4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1578b8: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1578b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1578bc: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1578bcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1578c0: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1578c0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1578c4: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1578c4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1578c8: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1578c8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x1578cc: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1578ccu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1578d0: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1578d0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1578d4: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1578d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1578d8: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1578d8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1578dc: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1578dcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1578e0: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1578e0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1578e4: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1578e4u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_1578e8:
    // 0x1578e8: 0x28a20011  slti        $v0, $a1, 0x11
    ctx->pc = 0x1578e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x1578ec: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1578ECu;
    {
        const bool branch_taken_0x1578ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1578F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1578ECu;
            // 0x1578f0: 0xa3442  srl         $a2, $t2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1578ec) {
            ctx->pc = 0x157958u;
            goto label_157958;
        }
    }
    ctx->pc = 0x1578F4u;
    // 0x1578f4: 0x24a5ffef  addiu       $a1, $a1, -0x11
    ctx->pc = 0x1578f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967279));
    // 0x1578f8: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1578F8u;
    {
        const bool branch_taken_0x1578f8 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1578FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1578F8u;
            // 0x1578fc: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1578f8) {
            ctx->pc = 0x157918u;
            goto label_157918;
        }
    }
    ctx->pc = 0x157900u;
    // 0x157900: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157900u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157904: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157904u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157908: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157908u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x15790c: 0xa3442  srl         $a2, $t2, 17
    ctx->pc = 0x15790cu;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
    // 0x157910: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x157910u;
    {
        const bool branch_taken_0x157910 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157910u;
            // 0x157914: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157910) {
            ctx->pc = 0x15791Cu;
            goto label_15791c;
        }
    }
    ctx->pc = 0x157918u;
label_157918:
    // 0x157918: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157918u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_15791c:
    // 0x15791c: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x15791cu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157920: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157920u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157924: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157924u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157928: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157928u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15792c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15792cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157930: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157930u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157934: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157934u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157938: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157938u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15793c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15793cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157940: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157940u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157944: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157944u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157948: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157948u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x15794c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x15794cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157950: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157950u;
    {
        const bool branch_taken_0x157950 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157950u;
            // 0x157954: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157950) {
            ctx->pc = 0x157960u;
            goto label_157960;
        }
    }
    ctx->pc = 0x157958u;
label_157958:
    // 0x157958: 0xa53c0  sll         $t2, $t2, 15
    ctx->pc = 0x157958u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 15));
    // 0x15795c: 0x24a5000f  addiu       $a1, $a1, 0xF
    ctx->pc = 0x15795cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
label_157960:
    // 0x157960: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157960u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157964: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157964u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157968: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157968u;
    {
        const bool branch_taken_0x157968 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157968) {
            ctx->pc = 0x15796Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157968u;
            // 0x15796c: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1579B0u;
            goto label_1579b0;
        }
    }
    ctx->pc = 0x157970u;
    // 0x157970: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157970u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157974: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157974u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157978: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157978u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x15797c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x15797cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157980: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157980u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157984: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157984u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157988: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157988u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15798c: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x15798cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157990: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157990u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157994: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157994u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157998: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157998u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x15799c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x15799cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1579a0: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x1579a0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1579a4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1579a4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1579a8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1579a8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1579ac: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1579acu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_1579b0:
    // 0x1579b0: 0x28a20011  slti        $v0, $a1, 0x11
    ctx->pc = 0x1579b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x1579b4: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x1579B4u;
    {
        const bool branch_taken_0x1579b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1579B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1579B4u;
            // 0x1579b8: 0xa2442  srl         $a0, $t2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1579b4) {
            ctx->pc = 0x157A20u;
            goto label_157a20;
        }
    }
    ctx->pc = 0x1579BCu;
    // 0x1579bc: 0x24a5ffef  addiu       $a1, $a1, -0x11
    ctx->pc = 0x1579bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967279));
    // 0x1579c0: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1579C0u;
    {
        const bool branch_taken_0x1579c0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x1579C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1579C0u;
            // 0x1579c4: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1579c0) {
            ctx->pc = 0x1579E0u;
            goto label_1579e0;
        }
    }
    ctx->pc = 0x1579C8u;
    // 0x1579c8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x1579c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1579cc: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x1579ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x1579d0: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x1579d0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x1579d4: 0xa2442  srl         $a0, $t2, 17
    ctx->pc = 0x1579d4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
    // 0x1579d8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1579D8u;
    {
        const bool branch_taken_0x1579d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1579DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1579D8u;
            // 0x1579dc: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1579d8) {
            ctx->pc = 0x1579E4u;
            goto label_1579e4;
        }
    }
    ctx->pc = 0x1579E0u;
label_1579e0:
    // 0x1579e0: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x1579e0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_1579e4:
    // 0x1579e4: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x1579e4u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1579e8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1579e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1579ec: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x1579ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1579f0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x1579f0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x1579f4: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x1579f4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x1579f8: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x1579f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1579fc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x1579fcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157a00: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157a00u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157a04: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157a04u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157a08: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157a08u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157a0c: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157a0cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157a10: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157a10u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157a14: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157a14u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157a18: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157A18u;
    {
        const bool branch_taken_0x157a18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157A18u;
            // 0x157a1c: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157a18) {
            ctx->pc = 0x157A28u;
            goto label_157a28;
        }
    }
    ctx->pc = 0x157A20u;
label_157a20:
    // 0x157a20: 0xa53c0  sll         $t2, $t2, 15
    ctx->pc = 0x157a20u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 15));
    // 0x157a24: 0x24a5000f  addiu       $a1, $a1, 0xF
    ctx->pc = 0x157a24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
label_157a28:
    // 0x157a28: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157a28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157a2c: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157a2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157a30: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157A30u;
    {
        const bool branch_taken_0x157a30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157a30) {
            ctx->pc = 0x157A34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157A30u;
            // 0x157a34: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157A78u;
            goto label_157a78;
        }
    }
    ctx->pc = 0x157A38u;
    // 0x157a38: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157a38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157a3c: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157a3cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157a40: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157a40u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157a44: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157a44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157a48: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157a48u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157a4c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157a4cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157a50: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157a50u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157a54: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157a54u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157a58: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157a58u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157a5c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157a5cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157a60: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157a60u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157a64: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157a64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157a68: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157a68u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157a6c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157a6cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157a70: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157a70u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157a74: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157a74u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157a78:
    // 0x157a78: 0x61340  sll         $v0, $a2, 13
    ctx->pc = 0x157a78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 13));
    // 0x157a7c: 0x71f00  sll         $v1, $a3, 28
    ctx->pc = 0x157a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 28));
    // 0x157a80: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x157a80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x157a84: 0x42082  srl         $a0, $a0, 2
    ctx->pc = 0x157a84u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 2));
    // 0x157a88: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x157a88u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x157a8c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x157a8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x157a90: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157a90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157a94: 0x14400012  bnez        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x157A94u;
    {
        const bool branch_taken_0x157a94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157A94u;
            // 0x157a98: 0xad630014  sw          $v1, 0x14($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 20), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157a94) {
            ctx->pc = 0x157AE0u;
            goto label_157ae0;
        }
    }
    ctx->pc = 0x157A9Cu;
    // 0x157a9c: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157a9cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157aa0: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157aa0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157aa4: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157aa4u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157aa8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157aa8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157aac: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157aacu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157ab0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157ab0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157ab4: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157ab4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157ab8: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157ab8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157abc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157abcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157ac0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157ac0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157ac4: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157ac4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157ac8: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157ac8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157acc: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157accu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157ad0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157ad0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157ad4: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157ad4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157ad8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x157AD8u;
    {
        const bool branch_taken_0x157ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157AD8u;
            // 0x157adc: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157ad8) {
            ctx->pc = 0x157AE4u;
            goto label_157ae4;
        }
    }
    ctx->pc = 0x157AE0u;
label_157ae0:
    // 0x157ae0: 0xa5100  sll         $t2, $t2, 4
    ctx->pc = 0x157ae0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 4));
label_157ae4:
    // 0x157ae4: 0x28a2001d  slti        $v0, $a1, 0x1D
    ctx->pc = 0x157ae4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)29) ? 1 : 0);
    // 0x157ae8: 0x1440001b  bnez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x157AE8u;
    {
        const bool branch_taken_0x157ae8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157AE8u;
            // 0x157aec: 0xa3f42  srl         $a3, $t2, 29 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 10), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157ae8) {
            ctx->pc = 0x157B58u;
            goto label_157b58;
        }
    }
    ctx->pc = 0x157AF0u;
    // 0x157af0: 0x24a5ffe3  addiu       $a1, $a1, -0x1D
    ctx->pc = 0x157af0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967267));
    // 0x157af4: 0x10a00008  beqz        $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x157AF4u;
    {
        const bool branch_taken_0x157af4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157AF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157AF4u;
            // 0x157af8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157af4) {
            ctx->pc = 0x157B18u;
            goto label_157b18;
        }
    }
    ctx->pc = 0x157AFCu;
    // 0x157afc: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157afcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157b00: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157b00u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157b04: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157b04u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157b08: 0xa3f42  srl         $a3, $t2, 29
    ctx->pc = 0x157b08u;
    SET_GPR_S32(ctx, 7, (int32_t)SRL32(GPR_U32(ctx, 10), 29));
    // 0x157b0c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157B0Cu;
    {
        const bool branch_taken_0x157b0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157B0Cu;
            // 0x157b10: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157b0c) {
            ctx->pc = 0x157B1Cu;
            goto label_157b1c;
        }
    }
    ctx->pc = 0x157B14u;
    // 0x157b14: 0x0  nop
    ctx->pc = 0x157b14u;
    // NOP
label_157b18:
    // 0x157b18: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157b18u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_157b1c:
    // 0x157b1c: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157b1cu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b20: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b20u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b24: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157b24u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b28: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b28u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b2c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157b2cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157b30: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157b30u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b34: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157b34u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157b38: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b38u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b3c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157b3cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157b40: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157b40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b44: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157b44u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157b48: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b4c: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157b4cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157b50: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157B50u;
    {
        const bool branch_taken_0x157b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157B50u;
            // 0x157b54: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157b50) {
            ctx->pc = 0x157B60u;
            goto label_157b60;
        }
    }
    ctx->pc = 0x157B58u;
label_157b58:
    // 0x157b58: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x157b58u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x157b5c: 0x24a50003  addiu       $a1, $a1, 0x3
    ctx->pc = 0x157b5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 3));
label_157b60:
    // 0x157b60: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157b60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157b64: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157b64u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157b68: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157B68u;
    {
        const bool branch_taken_0x157b68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157b68) {
            ctx->pc = 0x157B6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157B68u;
            // 0x157b6c: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157BB0u;
            goto label_157bb0;
        }
    }
    ctx->pc = 0x157B70u;
    // 0x157b70: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157b70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157b74: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157b74u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157b78: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157b78u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b7c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b7cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b80: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157b80u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b84: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b84u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b88: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157b88u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157b8c: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157b8cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157b90: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157b90u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157b94: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157b94u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157b98: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157b98u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157b9c: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157b9cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157ba0: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157ba0u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157ba4: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157ba4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157ba8: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157ba8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157bac: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157bacu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157bb0:
    // 0x157bb0: 0x28a20011  slti        $v0, $a1, 0x11
    ctx->pc = 0x157bb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x157bb4: 0x1440001a  bnez        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x157BB4u;
    {
        const bool branch_taken_0x157bb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157BB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157BB4u;
            // 0x157bb8: 0xa3442  srl         $a2, $t2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157bb4) {
            ctx->pc = 0x157C20u;
            goto label_157c20;
        }
    }
    ctx->pc = 0x157BBCu;
    // 0x157bbc: 0x24a5ffef  addiu       $a1, $a1, -0x11
    ctx->pc = 0x157bbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967279));
    // 0x157bc0: 0x10a00007  beqz        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x157BC0u;
    {
        const bool branch_taken_0x157bc0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157BC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157BC0u;
            // 0x157bc4: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157bc0) {
            ctx->pc = 0x157BE0u;
            goto label_157be0;
        }
    }
    ctx->pc = 0x157BC8u;
    // 0x157bc8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157bc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157bcc: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157bccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157bd0: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157bd0u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157bd4: 0xa3442  srl         $a2, $t2, 17
    ctx->pc = 0x157bd4u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
    // 0x157bd8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x157BD8u;
    {
        const bool branch_taken_0x157bd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157BD8u;
            // 0x157bdc: 0xa85004  sllv        $t2, $t0, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157bd8) {
            ctx->pc = 0x157BE4u;
            goto label_157be4;
        }
    }
    ctx->pc = 0x157BE0u;
label_157be0:
    // 0x157be0: 0x100502d  daddu       $t2, $t0, $zero
    ctx->pc = 0x157be0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_157be4:
    // 0x157be4: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157be4u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157be8: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157be8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157bec: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157becu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157bf0: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157bf0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157bf4: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157bf4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157bf8: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157bf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157bfc: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157bfcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157c00: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157c00u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157c04: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157c04u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157c08: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157c08u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157c0c: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157c0cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157c10: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157c10u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157c14: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157c14u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157c18: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x157C18u;
    {
        const bool branch_taken_0x157c18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157C18u;
            // 0x157c1c: 0x1024025  or          $t0, $t0, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157c18) {
            ctx->pc = 0x157C28u;
            goto label_157c28;
        }
    }
    ctx->pc = 0x157C20u;
label_157c20:
    // 0x157c20: 0xa53c0  sll         $t2, $t2, 15
    ctx->pc = 0x157c20u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 15));
    // 0x157c24: 0x24a5000f  addiu       $a1, $a1, 0xF
    ctx->pc = 0x157c24u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
label_157c28:
    // 0x157c28: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157c28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157c2c: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157c2cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157c30: 0x54400011  bnel        $v0, $zero, . + 4 + (0x11 << 2)
    ctx->pc = 0x157C30u;
    {
        const bool branch_taken_0x157c30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x157c30) {
            ctx->pc = 0x157C34u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x157C30u;
            // 0x157c34: 0xa5040  sll         $t2, $t2, 1 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x157C78u;
            goto label_157c78;
        }
    }
    ctx->pc = 0x157C38u;
    // 0x157c38: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157c38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157c3c: 0xa85004  sllv        $t2, $t0, $a1
    ctx->pc = 0x157c3cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 5) & 0x1F));
    // 0x157c40: 0x81280000  lb          $t0, 0x0($t1)
    ctx->pc = 0x157c40u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157c44: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157c44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157c48: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157c48u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157c4c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157c4cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157c50: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157c50u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157c54: 0x91230000  lbu         $v1, 0x0($t1)
    ctx->pc = 0x157c54u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157c58: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157c58u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
    // 0x157c5c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157c5cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157c60: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157c60u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157c64: 0x91220000  lbu         $v0, 0x0($t1)
    ctx->pc = 0x157c64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x157c68: 0x1034025  or          $t0, $t0, $v1
    ctx->pc = 0x157c68u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x157c6c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x157c6cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x157c70: 0x84200  sll         $t0, $t0, 8
    ctx->pc = 0x157c70u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 8));
    // 0x157c74: 0x1024025  or          $t0, $t0, $v0
    ctx->pc = 0x157c74u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | GPR_U64(ctx, 2));
label_157c78:
    // 0x157c78: 0x28a20011  slti        $v0, $a1, 0x11
    ctx->pc = 0x157c78u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)17) ? 1 : 0);
    // 0x157c7c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x157C7Cu;
    {
        const bool branch_taken_0x157c7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157C80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157C7Cu;
            // 0x157c80: 0xa2442  srl         $a0, $t2, 17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157c7c) {
            ctx->pc = 0x157CA8u;
            goto label_157ca8;
        }
    }
    ctx->pc = 0x157C84u;
    // 0x157c84: 0x24a5ffef  addiu       $a1, $a1, -0x11
    ctx->pc = 0x157c84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967279));
    // 0x157c88: 0x10a00005  beqz        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x157C88u;
    {
        const bool branch_taken_0x157c88 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x157C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157C88u;
            // 0x157c8c: 0x2402000f  addiu       $v0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157c88) {
            ctx->pc = 0x157CA0u;
            goto label_157ca0;
        }
    }
    ctx->pc = 0x157C90u;
    // 0x157c90: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x157c90u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x157c94: 0x481006  srlv        $v0, $t0, $v0
    ctx->pc = 0x157c94u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 2) & 0x1F));
    // 0x157c98: 0x1425025  or          $t2, $t2, $v0
    ctx->pc = 0x157c98u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | GPR_U64(ctx, 2));
    // 0x157c9c: 0xa2442  srl         $a0, $t2, 17
    ctx->pc = 0x157c9cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 17));
label_157ca0:
    // 0x157ca0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x157CA0u;
    {
        const bool branch_taken_0x157ca0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157CA0u;
            // 0x157ca4: 0x25290004  addiu       $t1, $t1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157ca0) {
            ctx->pc = 0x157CACu;
            goto label_157cac;
        }
    }
    ctx->pc = 0x157CA8u;
label_157ca8:
    // 0x157ca8: 0x24a5000f  addiu       $a1, $a1, 0xF
    ctx->pc = 0x157ca8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
label_157cac:
    // 0x157cac: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x157cacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x157cb0: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157cb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157cb4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x157CB4u;
    {
        const bool branch_taken_0x157cb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157CB4u;
            // 0x157cb8: 0x71700  sll         $v0, $a3, 28 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 28));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157cb4) {
            ctx->pc = 0x157CC4u;
            goto label_157cc4;
        }
    }
    ctx->pc = 0x157CBCu;
    // 0x157cbc: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157cbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157cc0: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x157cc0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
label_157cc4:
    // 0x157cc4: 0x61b40  sll         $v1, $a2, 13
    ctx->pc = 0x157cc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 13));
    // 0x157cc8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x157cc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x157ccc: 0x42082  srl         $a0, $a0, 2
    ctx->pc = 0x157cccu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 2));
    // 0x157cd0: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x157cd0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x157cd4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x157CD4u;
    {
        const bool branch_taken_0x157cd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x157CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157CD4u;
            // 0x157cd8: 0xad620018  sw          $v0, 0x18($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 24), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157cd4) {
            ctx->pc = 0x157CFCu;
            goto label_157cfc;
        }
    }
    ctx->pc = 0x157CDCu;
    // 0x157cdc: 0x0  nop
    ctx->pc = 0x157cdcu;
    // NOP
label_157ce0:
    // 0x157ce0: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x157ce0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x157ce4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x157CE4u;
    {
        const bool branch_taken_0x157ce4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x157CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157CE4u;
            // 0x157ce8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x157ce4) {
            ctx->pc = 0x157CF4u;
            goto label_157cf4;
        }
    }
    ctx->pc = 0x157CECu;
    // 0x157cec: 0x24a5ffe0  addiu       $a1, $a1, -0x20
    ctx->pc = 0x157cecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967264));
    // 0x157cf0: 0x25290004  addiu       $t1, $t1, 0x4
    ctx->pc = 0x157cf0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4));
label_157cf4:
    // 0x157cf4: 0xad620018  sw          $v0, 0x18($t3)
    ctx->pc = 0x157cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 24), GPR_U32(ctx, 2));
label_157cf8:
    // 0x157cf8: 0xad620014  sw          $v0, 0x14($t3)
    ctx->pc = 0x157cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 20), GPR_U32(ctx, 2));
label_157cfc:
    // 0x157cfc: 0x24a20007  addiu       $v0, $a1, 0x7
    ctx->pc = 0x157cfcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 7));
    // 0x157d00: 0x210c3  sra         $v0, $v0, 3
    ctx->pc = 0x157d00u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 3));
    // 0x157d04: 0x1221021  addu        $v0, $t1, $v0
    ctx->pc = 0x157d04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x157d08: 0x2442fff8  addiu       $v0, $v0, -0x8
    ctx->pc = 0x157d08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967288));
    // 0x157d0c: 0x4c1023  subu        $v0, $v0, $t4
    ctx->pc = 0x157d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x157d10: 0xadc20000  sw          $v0, 0x0($t6)
    ctx->pc = 0x157d10u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 0), GPR_U32(ctx, 2));
    // 0x157d14: 0x8d63000c  lw          $v1, 0xC($t3)
    ctx->pc = 0x157d14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x157d18: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x157d18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x157d1c: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x157d1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x157d20: 0x3e00008  jr          $ra
    ctx->pc = 0x157D20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x157D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x157D20u;
            // 0x157d24: 0xad63001c  sw          $v1, 0x1C($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1571A0u: goto label_1571a0;
            case 0x1571A8u: goto label_1571a8;
            case 0x1571E8u: goto label_1571e8;
            case 0x1571F4u: goto label_1571f4;
            case 0x157230u: goto label_157230;
            case 0x157248u: goto label_157248;
            case 0x157254u: goto label_157254;
            case 0x157258u: goto label_157258;
            case 0x1572A0u: goto label_1572a0;
            case 0x1572ACu: goto label_1572ac;
            case 0x1572E8u: goto label_1572e8;
            case 0x1572F4u: goto label_1572f4;
            case 0x157300u: goto label_157300;
            case 0x157320u: goto label_157320;
            case 0x157328u: goto label_157328;
            case 0x157364u: goto label_157364;
            case 0x157388u: goto label_157388;
            case 0x157390u: goto label_157390;
            case 0x1573E0u: goto label_1573e0;
            case 0x1573F8u: goto label_1573f8;
            case 0x157418u: goto label_157418;
            case 0x157474u: goto label_157474;
            case 0x1574C8u: goto label_1574c8;
            case 0x1574D0u: goto label_1574d0;
            case 0x157500u: goto label_157500;
            case 0x157504u: goto label_157504;
            case 0x157540u: goto label_157540;
            case 0x157548u: goto label_157548;
            case 0x15755Cu: goto label_15755c;
            case 0x157574u: goto label_157574;
            case 0x1575D0u: goto label_1575d0;
            case 0x157600u: goto label_157600;
            case 0x157604u: goto label_157604;
            case 0x157640u: goto label_157640;
            case 0x157648u: goto label_157648;
            case 0x157698u: goto label_157698;
            case 0x1576C8u: goto label_1576c8;
            case 0x1576CCu: goto label_1576cc;
            case 0x157708u: goto label_157708;
            case 0x157710u: goto label_157710;
            case 0x157760u: goto label_157760;
            case 0x157788u: goto label_157788;
            case 0x157790u: goto label_157790;
            case 0x157794u: goto label_157794;
            case 0x1577ACu: goto label_1577ac;
            case 0x1577C8u: goto label_1577c8;
            case 0x157820u: goto label_157820;
            case 0x157850u: goto label_157850;
            case 0x157854u: goto label_157854;
            case 0x157890u: goto label_157890;
            case 0x157898u: goto label_157898;
            case 0x1578E8u: goto label_1578e8;
            case 0x157918u: goto label_157918;
            case 0x15791Cu: goto label_15791c;
            case 0x157958u: goto label_157958;
            case 0x157960u: goto label_157960;
            case 0x1579B0u: goto label_1579b0;
            case 0x1579E0u: goto label_1579e0;
            case 0x1579E4u: goto label_1579e4;
            case 0x157A20u: goto label_157a20;
            case 0x157A28u: goto label_157a28;
            case 0x157A78u: goto label_157a78;
            case 0x157AE0u: goto label_157ae0;
            case 0x157AE4u: goto label_157ae4;
            case 0x157B18u: goto label_157b18;
            case 0x157B1Cu: goto label_157b1c;
            case 0x157B58u: goto label_157b58;
            case 0x157B60u: goto label_157b60;
            case 0x157BB0u: goto label_157bb0;
            case 0x157BE0u: goto label_157be0;
            case 0x157BE4u: goto label_157be4;
            case 0x157C20u: goto label_157c20;
            case 0x157C28u: goto label_157c28;
            case 0x157C78u: goto label_157c78;
            case 0x157CA0u: goto label_157ca0;
            case 0x157CA8u: goto label_157ca8;
            case 0x157CACu: goto label_157cac;
            case 0x157CC4u: goto label_157cc4;
            case 0x157CE0u: goto label_157ce0;
            case 0x157CF4u: goto label_157cf4;
            case 0x157CF8u: goto label_157cf8;
            case 0x157CFCu: goto label_157cfc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x157D28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
