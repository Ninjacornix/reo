#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00102940
// Address: 0x102940 - 0x102ac0
void sub_00102940_0x102940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00102940_0x102940");
#endif

    switch (ctx->pc) {
        case 0x102970u: goto label_102970;
        default: break;
    }

    ctx->pc = 0x102940u;

    // 0x102940: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x102940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x102944: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x102944u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x102948: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x102948u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x10294c: 0x34423840  ori         $v0, $v0, 0x3840
    ctx->pc = 0x10294cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14400);
    // 0x102950: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x102950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x102954: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x102954u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x102958: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x102958u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10295c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x10295cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x102960: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x102960u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x102964: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x102964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x102968: 0xc040a3c  jal         func_1028F0
    ctx->pc = 0x102968u;
    SET_GPR_U32(ctx, 31, 0x102970u);
    ctx->pc = 0x10296Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x102968u;
            // 0x10296c: 0x8c540000  lw          $s4, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1028F0u;
    if (runtime->hasFunction(0x1028F0u)) {
        auto targetFn = runtime->lookupFunction(0x1028F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102970u; }
        if (ctx->pc != 0x102970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001028F0_0x1028f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x102970u; }
        if (ctx->pc != 0x102970u) { return; }
    }
    ctx->pc = 0x102970u;
label_102970:
    // 0x102970: 0x2c420002  sltiu       $v0, $v0, 0x2
    ctx->pc = 0x102970u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x102974: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x102974u;
    {
        const bool branch_taken_0x102974 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x102978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102974u;
            // 0x102978: 0x3c021000  lui         $v0, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x102974) {
            ctx->pc = 0x102984u;
            goto label_102984;
        }
    }
    ctx->pc = 0x10297Cu;
    // 0x10297c: 0x10000048  b           . + 4 + (0x48 << 2)
    ctx->pc = 0x10297Cu;
    {
        const bool branch_taken_0x10297c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x102980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10297Cu;
            // 0x102980: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10297c) {
            ctx->pc = 0x102AA0u;
            goto label_102aa0;
        }
    }
    ctx->pc = 0x102984u;
label_102984:
    // 0x102984: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x102984u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x102988: 0x34423900  ori         $v0, $v0, 0x3900
    ctx->pc = 0x102988u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)14592);
    // 0x10298c: 0x34633910  ori         $v1, $v1, 0x3910
    ctx->pc = 0x10298cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)14608);
    // 0x102990: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x102990u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x102994: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x102994u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x102998: 0x34843920  ori         $a0, $a0, 0x3920
    ctx->pc = 0x102998u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)14624);
    // 0x10299c: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x10299cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x1029a0: 0xae650000  sw          $a1, 0x0($s3)
    ctx->pc = 0x1029a0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 5));
    // 0x1029a4: 0x34c63930  ori         $a2, $a2, 0x3930
    ctx->pc = 0x1029a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)14640);
    // 0x1029a8: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x1029a8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x1029ac: 0x3c0f1000  lui         $t7, 0x1000
    ctx->pc = 0x1029acu;
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)4096 << 16));
    // 0x1029b0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1029b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1029b4: 0x34a53940  ori         $a1, $a1, 0x3940
    ctx->pc = 0x1029b4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)14656);
    // 0x1029b8: 0x35ef3950  ori         $t7, $t7, 0x3950
    ctx->pc = 0x1029b8u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) | (uint64_t)(uint16_t)14672);
    // 0x1029bc: 0x3c101000  lui         $s0, 0x1000
    ctx->pc = 0x1029bcu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)4096 << 16));
    // 0x1029c0: 0xae620004  sw          $v0, 0x4($s3)
    ctx->pc = 0x1029c0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4), GPR_U32(ctx, 2));
    // 0x1029c4: 0x36103960  ori         $s0, $s0, 0x3960
    ctx->pc = 0x1029c4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)14688);
    // 0x1029c8: 0x3c0e1000  lui         $t6, 0x1000
    ctx->pc = 0x1029c8u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)4096 << 16));
    // 0x1029cc: 0x3c111000  lui         $s1, 0x1000
    ctx->pc = 0x1029ccu;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)4096 << 16));
    // 0x1029d0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1029d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1029d4: 0x35ce3970  ori         $t6, $t6, 0x3970
    ctx->pc = 0x1029d4u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)14704);
    // 0x1029d8: 0x36313870  ori         $s1, $s1, 0x3870
    ctx->pc = 0x1029d8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) | (uint64_t)(uint16_t)14448);
    // 0x1029dc: 0x3c0c1000  lui         $t4, 0x1000
    ctx->pc = 0x1029dcu;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)4096 << 16));
    // 0x1029e0: 0xae620008  sw          $v0, 0x8($s3)
    ctx->pc = 0x1029e0u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 8), GPR_U32(ctx, 2));
    // 0x1029e4: 0x358c3880  ori         $t4, $t4, 0x3880
    ctx->pc = 0x1029e4u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) | (uint64_t)(uint16_t)14464);
    // 0x1029e8: 0x3c0b1000  lui         $t3, 0x1000
    ctx->pc = 0x1029e8u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)4096 << 16));
    // 0x1029ec: 0x3c0d1000  lui         $t5, 0x1000
    ctx->pc = 0x1029ecu;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)4096 << 16));
    // 0x1029f0: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x1029f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1029f4: 0x356b3800  ori         $t3, $t3, 0x3800
    ctx->pc = 0x1029f4u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) | (uint64_t)(uint16_t)14336);
    // 0x1029f8: 0x35ad38d0  ori         $t5, $t5, 0x38D0
    ctx->pc = 0x1029f8u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) | (uint64_t)(uint16_t)14544);
    // 0x1029fc: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x1029fcu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x102a00: 0xae62000c  sw          $v0, 0xC($s3)
    ctx->pc = 0x102a00u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 12), GPR_U32(ctx, 2));
    // 0x102a04: 0x34c63890  ori         $a2, $a2, 0x3890
    ctx->pc = 0x102a04u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)14480);
    // 0x102a08: 0x3c071000  lui         $a3, 0x1000
    ctx->pc = 0x102a08u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)4096 << 16));
    // 0x102a0c: 0x3c091000  lui         $t1, 0x1000
    ctx->pc = 0x102a0cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)4096 << 16));
    // 0x102a10: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x102a10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x102a14: 0x34e73830  ori         $a3, $a3, 0x3830
    ctx->pc = 0x102a14u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)14384);
    // 0x102a18: 0x35293860  ori         $t1, $t1, 0x3860
    ctx->pc = 0x102a18u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)14432);
    // 0x102a1c: 0x3c081000  lui         $t0, 0x1000
    ctx->pc = 0x102a1cu;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)4096 << 16));
    // 0x102a20: 0xae620010  sw          $v0, 0x10($s3)
    ctx->pc = 0x102a20u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 16), GPR_U32(ctx, 2));
    // 0x102a24: 0x35083820  ori         $t0, $t0, 0x3820
    ctx->pc = 0x102a24u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 8) | (uint64_t)(uint16_t)14368);
    // 0x102a28: 0x149202  srl         $s2, $s4, 8
    ctx->pc = 0x102a28u;
    SET_GPR_S32(ctx, 18, (int32_t)SRL32(GPR_U32(ctx, 20), 8));
    // 0x102a2c: 0x3c0a1000  lui         $t2, 0x1000
    ctx->pc = 0x102a2cu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)4096 << 16));
    // 0x102a30: 0x8de40000  lw          $a0, 0x0($t7)
    ctx->pc = 0x102a30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x102a34: 0x354a3850  ori         $t2, $t2, 0x3850
    ctx->pc = 0x102a34u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) | (uint64_t)(uint16_t)14416);
    // 0x102a38: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x102a38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x102a3c: 0xae640014  sw          $a0, 0x14($s3)
    ctx->pc = 0x102a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 20), GPR_U32(ctx, 4));
    // 0x102a40: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x102a40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x102a44: 0xae630018  sw          $v1, 0x18($s3)
    ctx->pc = 0x102a44u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 24), GPR_U32(ctx, 3));
    // 0x102a48: 0x8dc40000  lw          $a0, 0x0($t6)
    ctx->pc = 0x102a48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x102a4c: 0xae64001c  sw          $a0, 0x1C($s3)
    ctx->pc = 0x102a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 28), GPR_U32(ctx, 4));
    // 0x102a50: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x102a50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x102a54: 0xae630020  sw          $v1, 0x20($s3)
    ctx->pc = 0x102a54u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 32), GPR_U32(ctx, 3));
    // 0x102a58: 0x8d840000  lw          $a0, 0x0($t4)
    ctx->pc = 0x102a58u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x102a5c: 0xae640024  sw          $a0, 0x24($s3)
    ctx->pc = 0x102a5cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 36), GPR_U32(ctx, 4));
    // 0x102a60: 0x8d630000  lw          $v1, 0x0($t3)
    ctx->pc = 0x102a60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x102a64: 0xae630028  sw          $v1, 0x28($s3)
    ctx->pc = 0x102a64u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 40), GPR_U32(ctx, 3));
    // 0x102a68: 0x8da40000  lw          $a0, 0x0($t5)
    ctx->pc = 0x102a68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x102a6c: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x102a6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x102a70: 0x8ce50000  lw          $a1, 0x0($a3)
    ctx->pc = 0x102a70u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x102a74: 0x8d260000  lw          $a2, 0x0($t1)
    ctx->pc = 0x102a74u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x102a78: 0x8d070000  lw          $a3, 0x0($t0)
    ctx->pc = 0x102a78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x102a7c: 0xa663002e  sh          $v1, 0x2E($s3)
    ctx->pc = 0x102a7cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 46), (uint16_t)GPR_U32(ctx, 3));
    // 0x102a80: 0xa664002c  sh          $a0, 0x2C($s3)
    ctx->pc = 0x102a80u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 44), (uint16_t)GPR_U32(ctx, 4));
    // 0x102a84: 0xa6650030  sh          $a1, 0x30($s3)
    ctx->pc = 0x102a84u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 48), (uint16_t)GPR_U32(ctx, 5));
    // 0x102a88: 0xa6660032  sh          $a2, 0x32($s3)
    ctx->pc = 0x102a88u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 50), (uint16_t)GPR_U32(ctx, 6));
    // 0x102a8c: 0xa2670034  sb          $a3, 0x34($s3)
    ctx->pc = 0x102a8cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 52), (uint8_t)GPR_U32(ctx, 7));
    // 0x102a90: 0xa2740035  sb          $s4, 0x35($s3)
    ctx->pc = 0x102a90u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 53), (uint8_t)GPR_U32(ctx, 20));
    // 0x102a94: 0xa2720036  sb          $s2, 0x36($s3)
    ctx->pc = 0x102a94u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 54), (uint8_t)GPR_U32(ctx, 18));
    // 0x102a98: 0x8d430000  lw          $v1, 0x0($t2)
    ctx->pc = 0x102a98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x102a9c: 0xa2630037  sb          $v1, 0x37($s3)
    ctx->pc = 0x102a9cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 55), (uint8_t)GPR_U32(ctx, 3));
label_102aa0:
    // 0x102aa0: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x102aa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x102aa4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x102aa4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x102aa8: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x102aa8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x102aac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x102aacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x102ab0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x102ab0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x102ab4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x102ab4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x102ab8: 0x3e00008  jr          $ra
    ctx->pc = 0x102AB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x102ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x102AB8u;
            // 0x102abc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x102970u: goto label_102970;
            case 0x102984u: goto label_102984;
            case 0x102AA0u: goto label_102aa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x102AC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
