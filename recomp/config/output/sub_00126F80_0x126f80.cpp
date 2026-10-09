#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126F80
// Address: 0x126f80 - 0x1276d8
void sub_00126F80_0x126f80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126F80_0x126f80");
#endif

    switch (ctx->pc) {
        case 0x127058u: goto label_127058;
        case 0x1270a0u: goto label_1270a0;
        case 0x127158u: goto label_127158;
        case 0x127210u: goto label_127210;
        case 0x127298u: goto label_127298;
        case 0x1273f0u: goto label_1273f0;
        case 0x1274a8u: goto label_1274a8;
        case 0x127540u: goto label_127540;
        default: break;
    }

    ctx->pc = 0x126f80u;

    // 0x126f80: 0xc71821  addu        $v1, $a2, $a3
    ctx->pc = 0x126f80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x126f84: 0x1480000a  bnez        $a0, . + 4 + (0xA << 2)
    ctx->pc = 0x126F84u;
    {
        const bool branch_taken_0x126f84 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x126F88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126F84u;
            // 0x126f88: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126f84) {
            ctx->pc = 0x126FB0u;
            goto label_126fb0;
        }
    }
    ctx->pc = 0x126F8Cu;
    // 0x126f8c: 0xa31021  addu        $v0, $a1, $v1
    ctx->pc = 0x126f8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x126f90: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x126F90u;
    {
        const bool branch_taken_0x126f90 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x126f90) {
            ctx->pc = 0x126F94u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126F90u;
            // 0x126f94: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x126F98u;
            goto label_126f98;
        }
    }
    ctx->pc = 0x126F98u;
label_126f98:
    // 0x126f98: 0x24420021  addiu       $v0, $v0, 0x21
    ctx->pc = 0x126f98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 33));
    // 0x126f9c: 0x47001b  divu        $zero, $v0, $a3
    ctx->pc = 0x126f9cu;
    { uint32_t divisor = GPR_U32(ctx, 7); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x126fa0: 0x1012  mflo        $v0
    ctx->pc = 0x126fa0u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x126fa4: 0x471018  mult        $v0, $v0, $a3
    ctx->pc = 0x126fa4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x126fa8: 0x3e00008  jr          $ra
    ctx->pc = 0x126FA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126FA8u;
            // 0x126fac: 0x461023  subu        $v0, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126F98u: goto label_126f98;
            case 0x126FB0u: goto label_126fb0;
            case 0x126FBCu: goto label_126fbc;
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            case 0x127158u: goto label_127158;
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126FB0u;
label_126fb0:
    // 0x126fb0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x126fb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x126fb4: 0x50e00001  beql        $a3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x126FB4u;
    {
        const bool branch_taken_0x126fb4 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 0));
        if (branch_taken_0x126fb4) {
            ctx->pc = 0x126FB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x126FB4u;
            // 0x126fb8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x126FBCu;
            goto label_126fbc;
        }
    }
    ctx->pc = 0x126FBCu;
label_126fbc:
    // 0x126fbc: 0x24420039  addiu       $v0, $v0, 0x39
    ctx->pc = 0x126fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 57));
    // 0x126fc0: 0x47001b  divu        $zero, $v0, $a3
    ctx->pc = 0x126fc0u;
    { uint32_t divisor = GPR_U32(ctx, 7); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x126fc4: 0x1012  mflo        $v0
    ctx->pc = 0x126fc4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x126fc8: 0x471018  mult        $v0, $v0, $a3
    ctx->pc = 0x126fc8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x126fcc: 0x3e00008  jr          $ra
    ctx->pc = 0x126FCCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126FD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126FCCu;
            // 0x126fd0: 0x461023  subu        $v0, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126F98u: goto label_126f98;
            case 0x126FB0u: goto label_126fb0;
            case 0x126FBCu: goto label_126fbc;
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            case 0x127158u: goto label_127158;
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126FD4u;
    // 0x126fd4: 0x0  nop
    ctx->pc = 0x126fd4u;
    // NOP
    // 0x126fd8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x126fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x126fdc: 0x3e00008  jr          $ra
    ctx->pc = 0x126FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126FDCu;
            // 0x126fe0: 0xac44c7a8  sw          $a0, -0x3858($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294952872), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126F98u: goto label_126f98;
            case 0x126FB0u: goto label_126fb0;
            case 0x126FBCu: goto label_126fbc;
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            case 0x127158u: goto label_127158;
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126FE4u;
    // 0x126fe4: 0x0  nop
    ctx->pc = 0x126fe4u;
    // NOP
    // 0x126fe8: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x126fe8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x126fec: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x126fecu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x126ff0: 0x84303  sra         $t0, $t0, 12
    ctx->pc = 0x126ff0u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 12));
    // 0x126ff4: 0x94b03  sra         $t1, $t1, 12
    ctx->pc = 0x126ff4u;
    SET_GPR_S32(ctx, 9, SRA32(GPR_S32(ctx, 9), 12));
    // 0x126ff8: 0x44890800  mtc1        $t1, $f1
    ctx->pc = 0x126ff8u;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x126ffc: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x126ffcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x127000: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x127000u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127004: 0x44881000  mtc1        $t0, $f2
    ctx->pc = 0x127004u;
    { uint32_t bits = GPR_U32(ctx, 8); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x127008: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x127008u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x12700c: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x12700cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127010: 0x84e20000  lh          $v0, 0x0($a3)
    ctx->pc = 0x127010u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127014: 0x84e30002  lh          $v1, 0x2($a3)
    ctx->pc = 0x127014u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x127018: 0x3c013780  lui         $at, 0x3780
    ctx->pc = 0x127018u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14208 << 16));
    // 0x12701c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12701cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x127020: 0x21400  sll         $v0, $v0, 16
    ctx->pc = 0x127020u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
    // 0x127024: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x127024u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x127028: 0x46000a02  mul.s       $f8, $f1, $f0
    ctx->pc = 0x127028u;
    ctx->f[8] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x12702c: 0x44832800  mtc1        $v1, $f5
    ctx->pc = 0x12702cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[5], &bits, sizeof(bits)); }
    // 0x127030: 0x46802960  cvt.s.w     $f5, $f5
    ctx->pc = 0x127030u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[5], sizeof(tmp)); ctx->f[5] = FPU_CVT_S_W(tmp); }
    // 0x127034: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x127034u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x127038: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x127038u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x12703c: 0x18a0003b  blez        $a1, . + 4 + (0x3B << 2)
    ctx->pc = 0x12703Cu;
    {
        const bool branch_taken_0x12703c = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x127040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12703Cu;
            // 0x127040: 0x460011c2  mul.s       $f7, $f2, $f0 (Delay Slot)
        ctx->f[7] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12703c) {
            ctx->pc = 0x12712Cu;
            goto label_12712c;
        }
    }
    ctx->pc = 0x127044u;
    // 0x127044: 0x240eff00  addiu       $t6, $zero, -0x100
    ctx->pc = 0x127044u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127048: 0x3c0d0024  lui         $t5, 0x24
    ctx->pc = 0x127048u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)36 << 16));
    // 0x12704c: 0x3c0c0024  lui         $t4, 0x24
    ctx->pc = 0x12704cu;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)36 << 16));
    // 0x127050: 0x95030000  lhu         $v1, 0x0($t0)
    ctx->pc = 0x127050u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x127054: 0x0  nop
    ctx->pc = 0x127054u;
    // NOP
label_127058:
    // 0x127058: 0x91040001  lbu         $a0, 0x1($t0)
    ctx->pc = 0x127058u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 1)));
    // 0x12705c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12705cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127060: 0x6e1824  and         $v1, $v1, $t6
    ctx->pc = 0x127060u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 14));
    // 0x127064: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x127064u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127068: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127068u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x12706c: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x12706cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127070: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127070u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x127074: 0x14600036  bnez        $v1, . + 4 + (0x36 << 2)
    ctx->pc = 0x127074u;
    {
        const bool branch_taken_0x127074 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127074u;
            // 0x127078: 0x120102d  daddu       $v0, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127074) {
            ctx->pc = 0x127150u;
            goto label_127150;
        }
    }
    ctx->pc = 0x12707Cu;
    // 0x12707c: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x12707cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127080: 0x2404001e  addiu       $a0, $zero, 0x1E
    ctx->pc = 0x127080u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x127084: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x127084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x127088: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127088u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x12708c: 0x44823000  mtc1        $v0, $f6
    ctx->pc = 0x12708cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[6], &bits, sizeof(bits)); }
    // 0x127090: 0x468031a0  cvt.s.w     $f6, $f6
    ctx->pc = 0x127090u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[6], sizeof(tmp)); ctx->f[6] = FPU_CVT_S_W(tmp); }
    // 0x127094: 0x25aba528  addiu       $t3, $t5, -0x5AD8
    ctx->pc = 0x127094u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 13), 4294944040));
    // 0x127098: 0x258aa928  addiu       $t2, $t4, -0x56D8
    ctx->pc = 0x127098u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 12), 4294945064));
    // 0x12709c: 0x0  nop
    ctx->pc = 0x12709cu;
    // NOP
label_1270a0:
    // 0x1270a0: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x1270a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x1270a4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1270a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1270a8: 0x46054002  mul.s       $f0, $f8, $f5
    ctx->pc = 0x1270a8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[8], ctx->f[5]);
    // 0x1270ac: 0x46000946  mov.s       $f5, $f1
    ctx->pc = 0x1270acu;
    ctx->f[5] = FPU_MOV_S(ctx->f[1]);
    // 0x1270b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1270b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1270b4: 0x46013882  mul.s       $f2, $f7, $f1
    ctx->pc = 0x1270b4u;
    ctx->f[2] = FPU_MUL_S(ctx->f[7], ctx->f[1]);
    // 0x1270b8: 0x4b1821  addu        $v1, $v0, $t3
    ctx->pc = 0x1270b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1270bc: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1270bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1270c0: 0xc4630000  lwc1        $f3, 0x0($v1)
    ctx->pc = 0x1270c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1270c4: 0x46054102  mul.s       $f4, $f8, $f5
    ctx->pc = 0x1270c4u;
    ctx->f[4] = FPU_MUL_S(ctx->f[8], ctx->f[5]);
    // 0x1270c8: 0x2484fffe  addiu       $a0, $a0, -0x2
    ctx->pc = 0x1270c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967294));
    // 0x1270cc: 0x46001080  add.s       $f2, $f2, $f0
    ctx->pc = 0x1270ccu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[0]);
    // 0x1270d0: 0x46061842  mul.s       $f1, $f3, $f6
    ctx->pc = 0x1270d0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[3], ctx->f[6]);
    // 0x1270d4: 0xc4430000  lwc1        $f3, 0x0($v0)
    ctx->pc = 0x1270d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x1270d8: 0x460618c2  mul.s       $f3, $f3, $f6
    ctx->pc = 0x1270d8u;
    ctx->f[3] = FPU_MUL_S(ctx->f[3], ctx->f[6]);
    // 0x1270dc: 0x46011040  add.s       $f1, $f2, $f1
    ctx->pc = 0x1270dcu;
    ctx->f[1] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x1270e0: 0x46013802  mul.s       $f0, $f7, $f1
    ctx->pc = 0x1270e0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[7], ctx->f[1]);
    // 0x1270e4: 0x46000946  mov.s       $f5, $f1
    ctx->pc = 0x1270e4u;
    ctx->f[5] = FPU_MOV_S(ctx->f[1]);
    // 0x1270e8: 0x460008a4  .word       0x460008A4                   # cvt.w.s     $f2, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1270e8u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[2], &tmp, sizeof(tmp)); }
    // 0x1270ec: 0x44021000  mfc1        $v0, $f2
    ctx->pc = 0x1270ecu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[2], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1270f0: 0x46040000  add.s       $f0, $f0, $f4
    ctx->pc = 0x1270f0u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[4]);
    // 0x1270f4: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1270f4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1270f8: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x1270f8u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1270fc: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x1270fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127100: 0x46030040  add.s       $f1, $f0, $f3
    ctx->pc = 0x127100u;
    ctx->f[1] = FPU_ADD_S(ctx->f[0], ctx->f[3]);
    // 0x127104: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127104u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127108: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x127108u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x12710c: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x12710cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x127110: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x127110u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127114: 0x481ffe2  bgez        $a0, . + 4 + (-0x1E << 2)
    ctx->pc = 0x127114u;
    {
        const bool branch_taken_0x127114 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x127118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127114u;
            // 0x127118: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127114) {
            ctx->pc = 0x1270A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1270a0;
        }
    }
    ctx->pc = 0x12711Cu;
    // 0x12711c: 0x25290001  addiu       $t1, $t1, 0x1
    ctx->pc = 0x12711cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 1));
    // 0x127120: 0x125102a  slt         $v0, $t1, $a1
    ctx->pc = 0x127120u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x127124: 0x5440ffcc  bnel        $v0, $zero, . + 4 + (-0x34 << 2)
    ctx->pc = 0x127124u;
    {
        const bool branch_taken_0x127124 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x127124) {
            ctx->pc = 0x127128u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x127124u;
            // 0x127128: 0x95030000  lhu         $v1, 0x0($t0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 8), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x127058u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127058;
        }
    }
    ctx->pc = 0x12712Cu;
label_12712c:
    // 0x12712c: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x12712cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127130: 0x44040000  mfc1        $a0, $f0
    ctx->pc = 0x127130u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x127134: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x127134u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127138: 0x46002824  .word       0x46002824                   # cvt.w.s     $f0, $f5 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127138u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[5]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12713c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12713cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127140: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x127140u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127144: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x127144u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127148: 0xa4e40000  sh          $a0, 0x0($a3)
    ctx->pc = 0x127148u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x12714c: 0xa4e30002  sh          $v1, 0x2($a3)
    ctx->pc = 0x12714cu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 2), (uint16_t)GPR_U32(ctx, 3));
label_127150:
    // 0x127150: 0x3e00008  jr          $ra
    ctx->pc = 0x127150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126F98u: goto label_126f98;
            case 0x126FB0u: goto label_126fb0;
            case 0x126FBCu: goto label_126fbc;
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            case 0x127158u: goto label_127158;
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127158u;
label_127158:
    // 0x127158: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x127158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12715c: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x12715cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x127160: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x127160u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x127164: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x127164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x127168: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x127168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12716c: 0xa5303  sra         $t2, $t2, 12
    ctx->pc = 0x12716cu;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 12));
    // 0x127170: 0xb5b03  sra         $t3, $t3, 12
    ctx->pc = 0x127170u;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 12));
    // 0x127174: 0xa0782d  daddu       $t7, $a1, $zero
    ctx->pc = 0x127174u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127178: 0xe0682d  daddu       $t5, $a3, $zero
    ctx->pc = 0x127178u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12717c: 0x120702d  daddu       $t6, $t1, $zero
    ctx->pc = 0x12717cu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127180: 0x448a1000  mtc1        $t2, $f2
    ctx->pc = 0x127180u;
    { uint32_t bits = GPR_U32(ctx, 10); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x127184: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x127184u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x127188: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x127188u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12718c: 0x448b0800  mtc1        $t3, $f1
    ctx->pc = 0x12718cu;
    { uint32_t bits = GPR_U32(ctx, 11); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x127190: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x127190u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x127194: 0x85a30000  lh          $v1, 0x0($t5)
    ctx->pc = 0x127194u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x127198: 0x85a70002  lh          $a3, 0x2($t5)
    ctx->pc = 0x127198u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 13), 2)));
    // 0x12719c: 0xf17c2  srl         $v0, $t7, 31
    ctx->pc = 0x12719cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 15), 31));
    // 0x1271a0: 0x85c90000  lh          $t1, 0x0($t6)
    ctx->pc = 0x1271a0u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1271a4: 0x1e21021  addu        $v0, $t7, $v0
    ctx->pc = 0x1271a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 2)));
    // 0x1271a8: 0x85c50002  lh          $a1, 0x2($t6)
    ctx->pc = 0x1271a8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x1271ac: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1271acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1271b0: 0x3c013780  lui         $at, 0x3780
    ctx->pc = 0x1271b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14208 << 16));
    // 0x1271b4: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x1271b4u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1271b8: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x1271b8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x1271bc: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x1271bcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x1271c0: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x1271c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x1271c4: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1271c4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1271c8: 0x46000b82  mul.s       $f14, $f1, $f0
    ctx->pc = 0x1271c8u;
    ctx->f[14] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1271cc: 0x44834000  mtc1        $v1, $f8
    ctx->pc = 0x1271ccu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x1271d0: 0x46804220  cvt.s.w     $f8, $f8
    ctx->pc = 0x1271d0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[8], sizeof(tmp)); ctx->f[8] = FPU_CVT_S_W(tmp); }
    // 0x1271d4: 0x602d  daddu       $t4, $zero, $zero
    ctx->pc = 0x1271d4u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1271d8: 0x44875800  mtc1        $a3, $f11
    ctx->pc = 0x1271d8u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[11], &bits, sizeof(bits)); }
    // 0x1271dc: 0x46805ae0  cvt.s.w     $f11, $f11
    ctx->pc = 0x1271dcu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[11], sizeof(tmp)); ctx->f[11] = FPU_CVT_S_W(tmp); }
    // 0x1271e0: 0x44894800  mtc1        $t1, $f9
    ctx->pc = 0x1271e0u;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x1271e4: 0x46804a60  cvt.s.w     $f9, $f9
    ctx->pc = 0x1271e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[9], sizeof(tmp)); ctx->f[9] = FPU_CVT_S_W(tmp); }
    // 0x1271e8: 0x44855000  mtc1        $a1, $f10
    ctx->pc = 0x1271e8u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x1271ec: 0x468052a0  cvt.s.w     $f10, $f10
    ctx->pc = 0x1271ecu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[10], sizeof(tmp)); ctx->f[10] = FPU_CVT_S_W(tmp); }
    // 0x1271f0: 0x18400069  blez        $v0, . + 4 + (0x69 << 2)
    ctx->pc = 0x1271F0u;
    {
        const bool branch_taken_0x1271f0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1271F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1271F0u;
            // 0x1271f4: 0x46001342  mul.s       $f13, $f2, $f0 (Delay Slot)
        ctx->f[13] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1271f0) {
            ctx->pc = 0x127398u;
            goto label_127398;
        }
    }
    ctx->pc = 0x1271F8u;
    // 0x1271f8: 0x40c82d  daddu       $t9, $v0, $zero
    ctx->pc = 0x1271f8u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1271fc: 0x2418ff00  addiu       $t8, $zero, -0x100
    ctx->pc = 0x1271fcu;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127200: 0x3c110024  lui         $s1, 0x24
    ctx->pc = 0x127200u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)36 << 16));
    // 0x127204: 0x3c100024  lui         $s0, 0x24
    ctx->pc = 0x127204u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)36 << 16));
    // 0x127208: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x127208u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12720c: 0x0  nop
    ctx->pc = 0x12720cu;
    // NOP
label_127210:
    // 0x127210: 0x254a0012  addiu       $t2, $t2, 0x12
    ctx->pc = 0x127210u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 18));
    // 0x127214: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x127214u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x127218: 0x90a40001  lbu         $a0, 0x1($a1)
    ctx->pc = 0x127218u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x12721c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12721cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127220: 0x781824  and         $v1, $v1, $t8
    ctx->pc = 0x127220u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 24));
    // 0x127224: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x127224u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127228: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127228u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x12722c: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x12722cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127230: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127230u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x127234: 0x14600069  bnez        $v1, . + 4 + (0x69 << 2)
    ctx->pc = 0x127234u;
    {
        const bool branch_taken_0x127234 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127234u;
            // 0x127238: 0xc1040  sll         $v0, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127234) {
            ctx->pc = 0x1273DCu;
            goto label_1273dc;
        }
    }
    ctx->pc = 0x12723Cu;
    // 0x12723c: 0x95430000  lhu         $v1, 0x0($t2)
    ctx->pc = 0x12723cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x127240: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x127240u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127244: 0x91440001  lbu         $a0, 0x1($t2)
    ctx->pc = 0x127244u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x127248: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x127248u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x12724c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12724cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127250: 0x44827800  mtc1        $v0, $f15
    ctx->pc = 0x127250u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[15], &bits, sizeof(bits)); }
    // 0x127254: 0x46807be0  cvt.s.w     $f15, $f15
    ctx->pc = 0x127254u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[15], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x127258: 0x781824  and         $v1, $v1, $t8
    ctx->pc = 0x127258u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 24));
    // 0x12725c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x12725cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127260: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127260u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x127264: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x127264u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127268: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127268u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x12726c: 0x1460005b  bnez        $v1, . + 4 + (0x5B << 2)
    ctx->pc = 0x12726Cu;
    {
        const bool branch_taken_0x12726c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12726Cu;
            // 0x127270: 0xc1040  sll         $v0, $t4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12726c) {
            ctx->pc = 0x1273DCu;
            goto label_1273dc;
        }
    }
    ctx->pc = 0x127274u;
    // 0x127274: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x127274u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127278: 0x24a50002  addiu       $a1, $a1, 0x2
    ctx->pc = 0x127278u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
    // 0x12727c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12727cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x127280: 0x254a0002  addiu       $t2, $t2, 0x2
    ctx->pc = 0x127280u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 2));
    // 0x127284: 0x44826000  mtc1        $v0, $f12
    ctx->pc = 0x127284u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[12], &bits, sizeof(bits)); }
    // 0x127288: 0x46806320  cvt.s.w     $f12, $f12
    ctx->pc = 0x127288u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[12], sizeof(tmp)); ctx->f[12] = FPU_CVT_S_W(tmp); }
    // 0x12728c: 0x262ba528  addiu       $t3, $s1, -0x5AD8
    ctx->pc = 0x12728cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 17), 4294944040));
    // 0x127290: 0x2609a928  addiu       $t1, $s0, -0x56D8
    ctx->pc = 0x127290u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 16), 4294945064));
    // 0x127294: 0x2407001e  addiu       $a3, $zero, 0x1E
    ctx->pc = 0x127294u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
label_127298:
    // 0x127298: 0x90a40000  lbu         $a0, 0x0($a1)
    ctx->pc = 0x127298u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12729c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x12729cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1272a0: 0x460b7082  mul.s       $f2, $f14, $f11
    ctx->pc = 0x1272a0u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x1272a4: 0x460042c6  mov.s       $f11, $f8
    ctx->pc = 0x1272a4u;
    ctx->f[11] = FPU_MOV_S(ctx->f[8]);
    // 0x1272a8: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x1272a8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1272ac: 0x46086802  mul.s       $f0, $f13, $f8
    ctx->pc = 0x1272acu;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[8]);
    // 0x1272b0: 0x8b1021  addu        $v0, $a0, $t3
    ctx->pc = 0x1272b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1272b4: 0x892021  addu        $a0, $a0, $t1
    ctx->pc = 0x1272b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1272b8: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x1272b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1272bc: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1272bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1272c0: 0xc4440000  lwc1        $f4, 0x0($v0)
    ctx->pc = 0x1272c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1272c4: 0x460a70c2  mul.s       $f3, $f14, $f10
    ctx->pc = 0x1272c4u;
    ctx->f[3] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x1272c8: 0x46020000  add.s       $f0, $f0, $f2
    ctx->pc = 0x1272c8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1272cc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1272ccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1272d0: 0x460f2082  mul.s       $f2, $f4, $f15
    ctx->pc = 0x1272d0u;
    ctx->f[2] = FPU_MUL_S(ctx->f[4], ctx->f[15]);
    // 0x1272d4: 0xc4840000  lwc1        $f4, 0x0($a0)
    ctx->pc = 0x1272d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1272d8: 0x46096842  mul.s       $f1, $f13, $f9
    ctx->pc = 0x1272d8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[9]);
    // 0x1272dc: 0x6b1021  addu        $v0, $v1, $t3
    ctx->pc = 0x1272dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x1272e0: 0xc4470000  lwc1        $f7, 0x0($v0)
    ctx->pc = 0x1272e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1272e4: 0x46004a86  mov.s       $f10, $f9
    ctx->pc = 0x1272e4u;
    ctx->f[10] = FPU_MOV_S(ctx->f[9]);
    // 0x1272e8: 0x460b7182  mul.s       $f6, $f14, $f11
    ctx->pc = 0x1272e8u;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x1272ec: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x1272ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1272f0: 0x46020200  add.s       $f8, $f0, $f2
    ctx->pc = 0x1272f0u;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1272f4: 0x24e7fffe  addiu       $a3, $a3, -0x2
    ctx->pc = 0x1272f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967294));
    // 0x1272f8: 0x46030840  add.s       $f1, $f1, $f3
    ctx->pc = 0x1272f8u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x1272fc: 0x460c38c2  mul.s       $f3, $f7, $f12
    ctx->pc = 0x1272fcu;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[12]);
    // 0x127300: 0xc4670000  lwc1        $f7, 0x0($v1)
    ctx->pc = 0x127300u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x127304: 0x460a7142  mul.s       $f5, $f14, $f10
    ctx->pc = 0x127304u;
    ctx->f[5] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x127308: 0x46086802  mul.s       $f0, $f13, $f8
    ctx->pc = 0x127308u;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[8]);
    // 0x12730c: 0x460042c6  mov.s       $f11, $f8
    ctx->pc = 0x12730cu;
    ctx->f[11] = FPU_MOV_S(ctx->f[8]);
    // 0x127310: 0x460f2102  mul.s       $f4, $f4, $f15
    ctx->pc = 0x127310u;
    ctx->f[4] = FPU_MUL_S(ctx->f[4], ctx->f[15]);
    // 0x127314: 0x46030a40  add.s       $f9, $f1, $f3
    ctx->pc = 0x127314u;
    ctx->f[9] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x127318: 0x46004064  .word       0x46004064                   # cvt.w.s     $f1, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127318u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x12731c: 0x44030800  mfc1        $v1, $f1
    ctx->pc = 0x12731cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127320: 0x46060000  add.s       $f0, $f0, $f6
    ctx->pc = 0x127320u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[6]);
    // 0x127324: 0x460c3882  mul.s       $f2, $f7, $f12
    ctx->pc = 0x127324u;
    ctx->f[2] = FPU_MUL_S(ctx->f[7], ctx->f[12]);
    // 0x127328: 0x46096842  mul.s       $f1, $f13, $f9
    ctx->pc = 0x127328u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[9]);
    // 0x12732c: 0x46004a86  mov.s       $f10, $f9
    ctx->pc = 0x12732cu;
    ctx->f[10] = FPU_MOV_S(ctx->f[9]);
    // 0x127330: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x127330u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127334: 0x460048e4  .word       0x460048E4                   # cvt.w.s     $f3, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127334u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[3], &tmp, sizeof(tmp)); }
    // 0x127338: 0x44031800  mfc1        $v1, $f3
    ctx->pc = 0x127338u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[3], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x12733c: 0x46040200  add.s       $f8, $f0, $f4
    ctx->pc = 0x12733cu;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[4]);
    // 0x127340: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x127340u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127344: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127344u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127348: 0x46050840  add.s       $f1, $f1, $f5
    ctx->pc = 0x127348u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x12734c: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x12734cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127350: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x127350u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127354: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127354u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x127358: 0x46004024  .word       0x46004024                   # cvt.w.s     $f0, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127358u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12735c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12735cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127360: 0x46020a40  add.s       $f9, $f1, $f2
    ctx->pc = 0x127360u;
    ctx->f[9] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x127364: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x127364u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127368: 0x46004824  .word       0x46004824                   # cvt.w.s     $f0, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127368u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12736c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12736cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127370: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x127370u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127374: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127374u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127378: 0x31403  sra         $v0, $v1, 16
    ctx->pc = 0x127378u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x12737c: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x12737cu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127380: 0x4e1ffc5  bgez        $a3, . + 4 + (-0x3B << 2)
    ctx->pc = 0x127380u;
    {
        const bool branch_taken_0x127380 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x127384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127380u;
            // 0x127384: 0x25080002  addiu       $t0, $t0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127380) {
            ctx->pc = 0x127298u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127298;
        }
    }
    ctx->pc = 0x127388u;
    // 0x127388: 0x258c0001  addiu       $t4, $t4, 0x1
    ctx->pc = 0x127388u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x12738c: 0x199102a  slt         $v0, $t4, $t9
    ctx->pc = 0x12738cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)GPR_S64(ctx, 25)) ? 1 : 0);
    // 0x127390: 0x1440ff9f  bnez        $v0, . + 4 + (-0x61 << 2)
    ctx->pc = 0x127390u;
    {
        const bool branch_taken_0x127390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x127394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127390u;
            // 0x127394: 0x140282d  daddu       $a1, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127390) {
            ctx->pc = 0x127210u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127210;
        }
    }
    ctx->pc = 0x127398u;
label_127398:
    // 0x127398: 0x46004024  .word       0x46004024                   # cvt.w.s     $f0, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127398u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12739c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12739cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x1273a0: 0x1e0102d  daddu       $v0, $t7, $zero
    ctx->pc = 0x1273a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1273a4: 0x46005824  .word       0x46005824                   # cvt.w.s     $f0, $f11 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1273a4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[11]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1273a8: 0x44040000  mfc1        $a0, $f0
    ctx->pc = 0x1273a8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x1273ac: 0x46004824  .word       0x46004824                   # cvt.w.s     $f0, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1273acu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1273b0: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x1273b0u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x1273b4: 0x46005024  .word       0x46005024                   # cvt.w.s     $f0, $f10 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1273b4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[10]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x1273b8: 0x44060000  mfc1        $a2, $f0
    ctx->pc = 0x1273b8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x1273bc: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x1273bcu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x1273c0: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x1273c0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1273c4: 0xa5a30000  sh          $v1, 0x0($t5)
    ctx->pc = 0x1273c4u;
    WRITE16(ADD32(GPR_U32(ctx, 13), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1273c8: 0x52c03  sra         $a1, $a1, 16
    ctx->pc = 0x1273c8u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x1273cc: 0xa5a40002  sh          $a0, 0x2($t5)
    ctx->pc = 0x1273ccu;
    WRITE16(ADD32(GPR_U32(ctx, 13), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x1273d0: 0x63403  sra         $a2, $a2, 16
    ctx->pc = 0x1273d0u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x1273d4: 0xa5c50000  sh          $a1, 0x0($t6)
    ctx->pc = 0x1273d4u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1273d8: 0xa5c60002  sh          $a2, 0x2($t6)
    ctx->pc = 0x1273d8u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 6));
label_1273dc:
    // 0x1273dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1273dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1273e0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1273e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1273e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1273E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1273E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1273E4u;
            // 0x1273e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126F98u: goto label_126f98;
            case 0x126FB0u: goto label_126fb0;
            case 0x126FBCu: goto label_126fbc;
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            case 0x127158u: goto label_127158;
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1273ECu;
    // 0x1273ec: 0x0  nop
    ctx->pc = 0x1273ecu;
    // NOP
label_1273f0:
    // 0x1273f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1273f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1273f4: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x1273f4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x1273f8: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x1273f8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x1273fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1273fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x127400: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x127400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x127404: 0xa5303  sra         $t2, $t2, 12
    ctx->pc = 0x127404u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 12));
    // 0x127408: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x127408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12740c: 0xb5b03  sra         $t3, $t3, 12
    ctx->pc = 0x12740cu;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 12));
    // 0x127410: 0xa0c02d  daddu       $t8, $a1, $zero
    ctx->pc = 0x127410u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127414: 0xe0702d  daddu       $t6, $a3, $zero
    ctx->pc = 0x127414u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127418: 0x120782d  daddu       $t7, $t1, $zero
    ctx->pc = 0x127418u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12741c: 0x448a1000  mtc1        $t2, $f2
    ctx->pc = 0x12741cu;
    { uint32_t bits = GPR_U32(ctx, 10); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x127420: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x127420u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x127424: 0x448b0800  mtc1        $t3, $f1
    ctx->pc = 0x127424u;
    { uint32_t bits = GPR_U32(ctx, 11); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x127428: 0x46800860  cvt.s.w     $f1, $f1
    ctx->pc = 0x127428u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[1], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x12742c: 0x85c30000  lh          $v1, 0x0($t6)
    ctx->pc = 0x12742cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x127430: 0x85c70002  lh          $a3, 0x2($t6)
    ctx->pc = 0x127430u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x127434: 0x1817c2  srl         $v0, $t8, 31
    ctx->pc = 0x127434u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 24), 31));
    // 0x127438: 0x85e90000  lh          $t1, 0x0($t7)
    ctx->pc = 0x127438u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x12743c: 0x3021021  addu        $v0, $t8, $v0
    ctx->pc = 0x12743cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 2)));
    // 0x127440: 0x85e50002  lh          $a1, 0x2($t7)
    ctx->pc = 0x127440u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 15), 2)));
    // 0x127444: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x127444u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x127448: 0x3c013780  lui         $at, 0x3780
    ctx->pc = 0x127448u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)14208 << 16));
    // 0x12744c: 0x44810000  mtc1        $at, $f0
    ctx->pc = 0x12744cu;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x127450: 0x73c00  sll         $a3, $a3, 16
    ctx->pc = 0x127450u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
    // 0x127454: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x127454u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x127458: 0x52c00  sll         $a1, $a1, 16
    ctx->pc = 0x127458u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x12745c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x12745cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x127460: 0x46000b82  mul.s       $f14, $f1, $f0
    ctx->pc = 0x127460u;
    ctx->f[14] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x127464: 0x44834800  mtc1        $v1, $f9
    ctx->pc = 0x127464u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[9], &bits, sizeof(bits)); }
    // 0x127468: 0x46804a60  cvt.s.w     $f9, $f9
    ctx->pc = 0x127468u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[9], sizeof(tmp)); ctx->f[9] = FPU_CVT_S_W(tmp); }
    // 0x12746c: 0x80502d  daddu       $t2, $a0, $zero
    ctx->pc = 0x12746cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127470: 0x44875800  mtc1        $a3, $f11
    ctx->pc = 0x127470u;
    { uint32_t bits = GPR_U32(ctx, 7); std::memcpy(&ctx->f[11], &bits, sizeof(bits)); }
    // 0x127474: 0x46805ae0  cvt.s.w     $f11, $f11
    ctx->pc = 0x127474u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[11], sizeof(tmp)); ctx->f[11] = FPU_CVT_S_W(tmp); }
    // 0x127478: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x127478u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12747c: 0x44894000  mtc1        $t1, $f8
    ctx->pc = 0x12747cu;
    { uint32_t bits = GPR_U32(ctx, 9); std::memcpy(&ctx->f[8], &bits, sizeof(bits)); }
    // 0x127480: 0x46804220  cvt.s.w     $f8, $f8
    ctx->pc = 0x127480u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[8], sizeof(tmp)); ctx->f[8] = FPU_CVT_S_W(tmp); }
    // 0x127484: 0x44855000  mtc1        $a1, $f10
    ctx->pc = 0x127484u;
    { uint32_t bits = GPR_U32(ctx, 5); std::memcpy(&ctx->f[10], &bits, sizeof(bits)); }
    // 0x127488: 0x468052a0  cvt.s.w     $f10, $f10
    ctx->pc = 0x127488u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[10], sizeof(tmp)); ctx->f[10] = FPU_CVT_S_W(tmp); }
    // 0x12748c: 0x1840006a  blez        $v0, . + 4 + (0x6A << 2)
    ctx->pc = 0x12748Cu;
    {
        const bool branch_taken_0x12748c = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x127490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12748Cu;
            // 0x127490: 0x46001302  mul.s       $f12, $f2, $f0 (Delay Slot)
        ctx->f[12] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        ctx->in_delay_slot = false;
        if (branch_taken_0x12748c) {
            ctx->pc = 0x127638u;
            goto label_127638;
        }
    }
    ctx->pc = 0x127494u;
    // 0x127494: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x127494u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127498: 0x2419ff00  addiu       $t9, $zero, -0x100
    ctx->pc = 0x127498u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x12749c: 0x3c120024  lui         $s2, 0x24
    ctx->pc = 0x12749cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)36 << 16));
    // 0x1274a0: 0x3c110024  lui         $s1, 0x24
    ctx->pc = 0x1274a0u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)36 << 16));
    // 0x1274a4: 0x140382d  daddu       $a3, $t2, $zero
    ctx->pc = 0x1274a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_1274a8:
    // 0x1274a8: 0x254a0012  addiu       $t2, $t2, 0x12
    ctx->pc = 0x1274a8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 18));
    // 0x1274ac: 0x94e30000  lhu         $v1, 0x0($a3)
    ctx->pc = 0x1274acu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1274b0: 0x90e40001  lbu         $a0, 0x1($a3)
    ctx->pc = 0x1274b0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1274b4: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1274b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1274b8: 0x791824  and         $v1, $v1, $t9
    ctx->pc = 0x1274b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 25));
    // 0x1274bc: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1274bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1274c0: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1274c0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1274c4: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x1274c4u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1274c8: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x1274c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x1274cc: 0x1460006b  bnez        $v1, . + 4 + (0x6B << 2)
    ctx->pc = 0x1274CCu;
    {
        const bool branch_taken_0x1274cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1274D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1274CCu;
            // 0x1274d0: 0xd1040  sll         $v0, $t5, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 13), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1274cc) {
            ctx->pc = 0x12767Cu;
            goto label_12767c;
        }
    }
    ctx->pc = 0x1274D4u;
    // 0x1274d4: 0x95430000  lhu         $v1, 0x0($t2)
    ctx->pc = 0x1274d4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1274d8: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x1274d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x1274dc: 0x91440001  lbu         $a0, 0x1($t2)
    ctx->pc = 0x1274dcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x1274e0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1274e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1274e4: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1274e4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1274e8: 0x44827800  mtc1        $v0, $f15
    ctx->pc = 0x1274e8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[15], &bits, sizeof(bits)); }
    // 0x1274ec: 0x46807be0  cvt.s.w     $f15, $f15
    ctx->pc = 0x1274ecu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[15], sizeof(tmp)); ctx->f[15] = FPU_CVT_S_W(tmp); }
    // 0x1274f0: 0x791824  and         $v1, $v1, $t9
    ctx->pc = 0x1274f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 25));
    // 0x1274f4: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1274f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1274f8: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1274f8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1274fc: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x1274fcu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127500: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127500u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x127504: 0x1460005d  bnez        $v1, . + 4 + (0x5D << 2)
    ctx->pc = 0x127504u;
    {
        const bool branch_taken_0x127504 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127504u;
            // 0x127508: 0xd1040  sll         $v0, $t5, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 13), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127504) {
            ctx->pc = 0x12767Cu;
            goto label_12767c;
        }
    }
    ctx->pc = 0x12750Cu;
    // 0x12750c: 0x30821fff  andi        $v0, $a0, 0x1FFF
    ctx->pc = 0x12750cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)8191);
    // 0x127510: 0x3c013f33  lui         $at, 0x3F33
    ctx->pc = 0x127510u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)16179 << 16));
    // 0x127514: 0x34213333  ori         $at, $at, 0x3333
    ctx->pc = 0x127514u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)13107);
    // 0x127518: 0x44818000  mtc1        $at, $f16
    ctx->pc = 0x127518u;
    { uint32_t bits = GPR_U32(ctx, 1); std::memcpy(&ctx->f[16], &bits, sizeof(bits)); }
    // 0x12751c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x12751cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x127520: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x127520u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x127524: 0x44826800  mtc1        $v0, $f13
    ctx->pc = 0x127524u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[13], &bits, sizeof(bits)); }
    // 0x127528: 0x46806b60  cvt.s.w     $f13, $f13
    ctx->pc = 0x127528u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[13], sizeof(tmp)); ctx->f[13] = FPU_CVT_S_W(tmp); }
    // 0x12752c: 0x254a0002  addiu       $t2, $t2, 0x2
    ctx->pc = 0x12752cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 2));
    // 0x127530: 0x264ca528  addiu       $t4, $s2, -0x5AD8
    ctx->pc = 0x127530u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 18), 4294944040));
    // 0x127534: 0x262ba928  addiu       $t3, $s1, -0x56D8
    ctx->pc = 0x127534u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 17), 4294945064));
    // 0x127538: 0x2409001e  addiu       $t1, $zero, 0x1E
    ctx->pc = 0x127538u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x12753c: 0x0  nop
    ctx->pc = 0x12753cu;
    // NOP
label_127540:
    // 0x127540: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x127540u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127544: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x127544u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x127548: 0x91430000  lbu         $v1, 0x0($t2)
    ctx->pc = 0x127548u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x12754c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x12754cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x127550: 0x460b7042  mul.s       $f1, $f14, $f11
    ctx->pc = 0x127550u;
    ctx->f[1] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x127554: 0x46004ac6  mov.s       $f11, $f9
    ctx->pc = 0x127554u;
    ctx->f[11] = FPU_MOV_S(ctx->f[9]);
    // 0x127558: 0x460a70c2  mul.s       $f3, $f14, $f10
    ctx->pc = 0x127558u;
    ctx->f[3] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x12755c: 0x46004286  mov.s       $f10, $f8
    ctx->pc = 0x12755cu;
    ctx->f[10] = FPU_MOV_S(ctx->f[8]);
    // 0x127560: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x127560u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x127564: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x127564u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x127568: 0x46096082  mul.s       $f2, $f12, $f9
    ctx->pc = 0x127568u;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[9]);
    // 0x12756c: 0x4c2021  addu        $a0, $v0, $t4
    ctx->pc = 0x12756cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x127570: 0x46086002  mul.s       $f0, $f12, $f8
    ctx->pc = 0x127570u;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[8]);
    // 0x127574: 0x6c2821  addu        $a1, $v1, $t4
    ctx->pc = 0x127574u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x127578: 0xc4870000  lwc1        $f7, 0x0($a0)
    ctx->pc = 0x127578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x12757c: 0x460b7182  mul.s       $f6, $f14, $f11
    ctx->pc = 0x12757cu;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x127580: 0xc4a40000  lwc1        $f4, 0x0($a1)
    ctx->pc = 0x127580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x127584: 0x460a7142  mul.s       $f5, $f14, $f10
    ctx->pc = 0x127584u;
    ctx->f[5] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x127588: 0x46011080  add.s       $f2, $f2, $f1
    ctx->pc = 0x127588u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x12758c: 0x6b1821  addu        $v1, $v1, $t3
    ctx->pc = 0x12758cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x127590: 0x46030000  add.s       $f0, $f0, $f3
    ctx->pc = 0x127590u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[3]);
    // 0x127594: 0x4b1021  addu        $v0, $v0, $t3
    ctx->pc = 0x127594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x127598: 0x460f38c2  mul.s       $f3, $f7, $f15
    ctx->pc = 0x127598u;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[15]);
    // 0x12759c: 0xc4470000  lwc1        $f7, 0x0($v0)
    ctx->pc = 0x12759cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1275a0: 0x460d2042  mul.s       $f1, $f4, $f13
    ctx->pc = 0x1275a0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[4], ctx->f[13]);
    // 0x1275a4: 0xc4640000  lwc1        $f4, 0x0($v1)
    ctx->pc = 0x1275a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1275a8: 0x2529fffe  addiu       $t1, $t1, -0x2
    ctx->pc = 0x1275a8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294967294));
    // 0x1275ac: 0x460d2102  mul.s       $f4, $f4, $f13
    ctx->pc = 0x1275acu;
    ctx->f[4] = FPU_MUL_S(ctx->f[4], ctx->f[13]);
    // 0x1275b0: 0x46031240  add.s       $f9, $f2, $f3
    ctx->pc = 0x1275b0u;
    ctx->f[9] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x1275b4: 0x46010200  add.s       $f8, $f0, $f1
    ctx->pc = 0x1275b4u;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1275b8: 0x460f38c2  mul.s       $f3, $f7, $f15
    ctx->pc = 0x1275b8u;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[15]);
    // 0x1275bc: 0x46096082  mul.s       $f2, $f12, $f9
    ctx->pc = 0x1275bcu;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[9]);
    // 0x1275c0: 0x46004ac6  mov.s       $f11, $f9
    ctx->pc = 0x1275c0u;
    ctx->f[11] = FPU_MOV_S(ctx->f[9]);
    // 0x1275c4: 0x46086042  mul.s       $f1, $f12, $f8
    ctx->pc = 0x1275c4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[12], ctx->f[8]);
    // 0x1275c8: 0x46004286  mov.s       $f10, $f8
    ctx->pc = 0x1275c8u;
    ctx->f[10] = FPU_MOV_S(ctx->f[8]);
    // 0x1275cc: 0x46084800  add.s       $f0, $f9, $f8
    ctx->pc = 0x1275ccu;
    ctx->f[0] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x1275d0: 0x46061080  add.s       $f2, $f2, $f6
    ctx->pc = 0x1275d0u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[6]);
    // 0x1275d4: 0x46050840  add.s       $f1, $f1, $f5
    ctx->pc = 0x1275d4u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x1275d8: 0x46100002  mul.s       $f0, $f0, $f16
    ctx->pc = 0x1275d8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[16]);
    // 0x1275dc: 0x46031240  add.s       $f9, $f2, $f3
    ctx->pc = 0x1275dcu;
    ctx->f[9] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x1275e0: 0x46040a00  add.s       $f8, $f1, $f4
    ctx->pc = 0x1275e0u;
    ctx->f[8] = FPU_ADD_S(ctx->f[1], ctx->f[4]);
    // 0x1275e4: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1275e4u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1275e8: 0x44020800  mfc1        $v0, $f1
    ctx->pc = 0x1275e8u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x1275ec: 0x46084840  add.s       $f1, $f9, $f8
    ctx->pc = 0x1275ecu;
    ctx->f[1] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x1275f0: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x1275f0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1275f4: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x1275f4u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1275f8: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x1275f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x1275fc: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x1275fcu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127600: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127600u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127604: 0x46100842  mul.s       $f1, $f1, $f16
    ctx->pc = 0x127604u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[16]);
    // 0x127608: 0x46000824  .word       0x46000824                   # cvt.w.s     $f0, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127608u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12760c: 0x44020000  mfc1        $v0, $f0
    ctx->pc = 0x12760cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 2, bits); }
    // 0x127610: 0x21403  sra         $v0, $v0, 16
    ctx->pc = 0x127610u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x127614: 0xa5020000  sh          $v0, 0x0($t0)
    ctx->pc = 0x127614u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127618: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127618u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x12761c: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x12761cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127620: 0x521ffc7  bgez        $t1, . + 4 + (-0x39 << 2)
    ctx->pc = 0x127620u;
    {
        const bool branch_taken_0x127620 = (GPR_S64(ctx, 9) >= 0);
        ctx->pc = 0x127624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127620u;
            // 0x127624: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127620) {
            ctx->pc = 0x127540u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127540;
        }
    }
    ctx->pc = 0x127628u;
    // 0x127628: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x127628u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x12762c: 0x1b0102a  slt         $v0, $t5, $s0
    ctx->pc = 0x12762cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x127630: 0x1440ff9d  bnez        $v0, . + 4 + (-0x63 << 2)
    ctx->pc = 0x127630u;
    {
        const bool branch_taken_0x127630 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x127634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127630u;
            // 0x127634: 0x140382d  daddu       $a3, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127630) {
            ctx->pc = 0x1274A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1274a8;
        }
    }
    ctx->pc = 0x127638u;
label_127638:
    // 0x127638: 0x46004824  .word       0x46004824                   # cvt.w.s     $f0, $f9 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127638u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[9]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x12763c: 0x44030000  mfc1        $v1, $f0
    ctx->pc = 0x12763cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 3, bits); }
    // 0x127640: 0x300102d  daddu       $v0, $t8, $zero
    ctx->pc = 0x127640u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127644: 0x46005824  .word       0x46005824                   # cvt.w.s     $f0, $f11 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127644u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[11]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127648: 0x44040000  mfc1        $a0, $f0
    ctx->pc = 0x127648u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 4, bits); }
    // 0x12764c: 0x46004024  .word       0x46004024                   # cvt.w.s     $f0, $f8 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x12764cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[8]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127650: 0x44050000  mfc1        $a1, $f0
    ctx->pc = 0x127650u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 5, bits); }
    // 0x127654: 0x46005024  .word       0x46005024                   # cvt.w.s     $f0, $f10 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x127654u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[10]); std::memcpy(&ctx->f[0], &tmp, sizeof(tmp)); }
    // 0x127658: 0x44060000  mfc1        $a2, $f0
    ctx->pc = 0x127658u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[0], sizeof(bits)); SET_GPR_U32(ctx, 6, bits); }
    // 0x12765c: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x12765cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127660: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x127660u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127664: 0xa5c30000  sh          $v1, 0x0($t6)
    ctx->pc = 0x127664u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x127668: 0x52c03  sra         $a1, $a1, 16
    ctx->pc = 0x127668u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x12766c: 0xa5c40002  sh          $a0, 0x2($t6)
    ctx->pc = 0x12766cu;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x127670: 0x63403  sra         $a2, $a2, 16
    ctx->pc = 0x127670u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x127674: 0xa5e50000  sh          $a1, 0x0($t7)
    ctx->pc = 0x127674u;
    WRITE16(ADD32(GPR_U32(ctx, 15), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x127678: 0xa5e60002  sh          $a2, 0x2($t7)
    ctx->pc = 0x127678u;
    WRITE16(ADD32(GPR_U32(ctx, 15), 2), (uint16_t)GPR_U32(ctx, 6));
label_12767c:
    // 0x12767c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12767cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x127680: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x127680u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x127684: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x127684u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x127688: 0x3e00008  jr          $ra
    ctx->pc = 0x127688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12768Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127688u;
            // 0x12768c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x126F98u: goto label_126f98;
            case 0x126FB0u: goto label_126fb0;
            case 0x126FBCu: goto label_126fbc;
            case 0x127058u: goto label_127058;
            case 0x1270A0u: goto label_1270a0;
            case 0x12712Cu: goto label_12712c;
            case 0x127150u: goto label_127150;
            case 0x127158u: goto label_127158;
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127690u;
    // 0x127690: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x127690u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x127694: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x127694u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x127698: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x127698u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x12769c: 0x8c43c7a8  lw          $v1, -0x3858($v0)
    ctx->pc = 0x12769cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294952872)));
    // 0x1276a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1276a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1276a4: 0xb6403  sra         $t4, $t3, 16
    ctx->pc = 0x1276a4u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 11), 16));
    // 0x1276a8: 0xa1403  sra         $v0, $t2, 16
    ctx->pc = 0x1276a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 10), 16));
    // 0x1276ac: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1276acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1276b0: 0x40502d  daddu       $t2, $v0, $zero
    ctx->pc = 0x1276b0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276b4: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1276B4u;
    {
        const bool branch_taken_0x1276b4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1276B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1276B4u;
            // 0x1276b8: 0x180582d  daddu       $t3, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1276b4) {
            ctx->pc = 0x1276C8u;
            goto label_1276c8;
        }
    }
    ctx->pc = 0x1276BCu;
    // 0x1276bc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1276bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1276c0: 0x8049c56  j           func_127158
    ctx->pc = 0x1276C0u;
    ctx->pc = 0x1276C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1276C0u;
            // 0x1276c4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x127158u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_127158;
    ctx->pc = 0x1276C8u;
label_1276c8:
    // 0x1276c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1276c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1276cc: 0x40502d  daddu       $t2, $v0, $zero
    ctx->pc = 0x1276ccu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276d0: 0x8049cfc  j           func_1273F0
    ctx->pc = 0x1276D0u;
    ctx->pc = 0x1276D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1276D0u;
            // 0x1276d4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1273F0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1273f0;
    ctx->pc = 0x1276D8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
