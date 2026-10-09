#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00107938
// Address: 0x107938 - 0x107a18
void sub_00107938_0x107938(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00107938_0x107938");
#endif

    switch (ctx->pc) {
        case 0x107998u: goto label_107998;
        case 0x1079f4u: goto label_1079f4;
        default: break;
    }

    ctx->pc = 0x107938u;

    // 0x107938: 0x2cc20010  sltiu       $v0, $a2, 0x10
    ctx->pc = 0x107938u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x10793c: 0x14400026  bnez        $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x10793Cu;
    {
        const bool branch_taken_0x10793c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x107940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10793Cu;
            // 0x107940: 0x30a500ff  andi        $a1, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10793c) {
            ctx->pc = 0x1079D8u;
            goto label_1079d8;
        }
    }
    ctx->pc = 0x107944u;
    // 0x107944: 0x3082000f  andi        $v0, $a0, 0xF
    ctx->pc = 0x107944u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)15);
    // 0x107948: 0x14400023  bnez        $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x107948u;
    {
        const bool branch_taken_0x107948 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10794Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107948u;
            // 0x10794c: 0x80382d  daddu       $a3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107948) {
            ctx->pc = 0x1079D8u;
            goto label_1079d8;
        }
    }
    ctx->pc = 0x107950u;
    // 0x107950: 0x51a38  dsll        $v1, $a1, 8
    ctx->pc = 0x107950u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << 8);
    // 0x107954: 0x3c020101  lui         $v0, 0x101
    ctx->pc = 0x107954u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)257 << 16));
    // 0x107958: 0x34420101  ori         $v0, $v0, 0x101
    ctx->pc = 0x107958u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)257);
    // 0x10795c: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x10795cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x107960: 0x34420101  ori         $v0, $v0, 0x101
    ctx->pc = 0x107960u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)257);
    // 0x107964: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x107964u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x107968: 0x34420101  ori         $v0, $v0, 0x101
    ctx->pc = 0x107968u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)257);
    // 0x10796c: 0x65502d  daddu       $t2, $v1, $a1
    ctx->pc = 0x10796cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 5));
    // 0x107970: 0x3c038080  lui         $v1, 0x8080
    ctx->pc = 0x107970u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32896 << 16));
    // 0x107974: 0x34638080  ori         $v1, $v1, 0x8080
    ctx->pc = 0x107974u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32896);
    // 0x107978: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x107978u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x10797c: 0x34638080  ori         $v1, $v1, 0x8080
    ctx->pc = 0x10797cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32896);
    // 0x107980: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x107980u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x107984: 0x34638080  ori         $v1, $v1, 0x8080
    ctx->pc = 0x107984u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32896);
    // 0x107988: 0x700a46e9  pcpyh       $t0, $t2
    ctx->pc = 0x107988u;
    { __m128i src = GPR_VEC(ctx, 0); uint16_t l = _mm_extract_epi16(src, 0); uint16_t h = _mm_extract_epi16(src, 4); 
   SET_GPR_VEC(ctx, 8, _mm_set_epi16(h,h,h,h, l,l,l,l)); }
    // 0x10798c: 0x71084b89  pcpyld      $t1, $t0, $t0
    ctx->pc = 0x10798cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 8), GPR_VEC(ctx, 8)));
    // 0x107990: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x107990u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x107994: 0x70634389  pcpyld      $t0, $v1, $v1
    ctx->pc = 0x107994u;
    SET_GPR_VEC(ctx, 8, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 3)));
label_107998:
    // 0x107998: 0x78e20000  lq          $v0, 0x0($a3)
    ctx->pc = 0x107998u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10799c: 0x704914c9  pxor        $v0, $v0, $t1
    ctx->pc = 0x10799cu;
    SET_GPR_VEC(ctx, 2, PS2_PXOR(GPR_VEC(ctx, 2), GPR_VEC(ctx, 9)));
    // 0x1079a0: 0x70845389  pcpyld      $t2, $a0, $a0
    ctx->pc = 0x1079a0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 4), GPR_VEC(ctx, 4)));
    // 0x1079a4: 0x70021ce9  pnor        $v1, $zero, $v0
    ctx->pc = 0x1079a4u;
    SET_GPR_VEC(ctx, 3, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x1079a8: 0x704a1248  psubb       $v0, $v0, $t2
    ctx->pc = 0x1079a8u;
    SET_GPR_VEC(ctx, 2, PS2_PSUBB(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x1079ac: 0x70431489  pand        $v0, $v0, $v1
    ctx->pc = 0x1079acu;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x1079b0: 0x70481489  pand        $v0, $v0, $t0
    ctx->pc = 0x1079b0u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 8)));
    // 0x1079b4: 0x70491ba9  pcpyud      $v1, $v0, $t1
    ctx->pc = 0x1079b4u;
    SET_GPR_VEC(ctx, 3, _mm_unpackhi_epi64(GPR_VEC(ctx, 2), GPR_VEC(ctx, 9)));
    // 0x1079b8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1079b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1079bc: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x1079BCu;
    {
        const bool branch_taken_0x1079bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1079bc) {
            ctx->pc = 0x1079C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1079BCu;
            // 0x1079c0: 0xe0202d  daddu       $a0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1079D8u;
            goto label_1079d8;
        }
    }
    ctx->pc = 0x1079C4u;
    // 0x1079c4: 0x24c6fff0  addiu       $a2, $a2, -0x10
    ctx->pc = 0x1079c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967280));
    // 0x1079c8: 0x2cc20010  sltiu       $v0, $a2, 0x10
    ctx->pc = 0x1079c8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)16) ? 1 : 0);
    // 0x1079cc: 0x1040fff2  beqz        $v0, . + 4 + (-0xE << 2)
    ctx->pc = 0x1079CCu;
    {
        const bool branch_taken_0x1079cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1079D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1079CCu;
            // 0x1079d0: 0x24e70010  addiu       $a3, $a3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1079cc) {
            ctx->pc = 0x107998u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_107998;
        }
    }
    ctx->pc = 0x1079D4u;
    // 0x1079d4: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1079d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_1079d8:
    // 0x1079d8: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1079d8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1079dc: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1079dcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1079e0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1079e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1079e4: 0x10c20008  beq         $a2, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1079E4u;
    {
        const bool branch_taken_0x1079e4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        if (branch_taken_0x1079e4) {
            ctx->pc = 0x107A08u;
            goto label_107a08;
        }
    }
    ctx->pc = 0x1079ECu;
    // 0x1079ec: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x1079ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x1079f0: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x1079f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
label_1079f4:
    // 0x1079f4: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1079f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1079f8: 0x10450005  beq         $v0, $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1079F8u;
    {
        const bool branch_taken_0x1079f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x1079FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1079F8u;
            // 0x1079fc: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1079f8) {
            ctx->pc = 0x107A10u;
            goto label_107a10;
        }
    }
    ctx->pc = 0x107A00u;
    // 0x107a00: 0x14c3fffc  bne         $a2, $v1, . + 4 + (-0x4 << 2)
    ctx->pc = 0x107A00u;
    {
        const bool branch_taken_0x107a00 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 3));
        ctx->pc = 0x107A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A00u;
            // 0x107a04: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x107a00) {
            ctx->pc = 0x1079F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1079f4;
        }
    }
    ctx->pc = 0x107A08u;
label_107a08:
    // 0x107a08: 0x3e00008  jr          $ra
    ctx->pc = 0x107A08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A08u;
            // 0x107a0c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107998u: goto label_107998;
            case 0x1079D8u: goto label_1079d8;
            case 0x1079F4u: goto label_1079f4;
            case 0x107A08u: goto label_107a08;
            case 0x107A10u: goto label_107a10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107A10u;
label_107a10:
    // 0x107a10: 0x3e00008  jr          $ra
    ctx->pc = 0x107A10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x107A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x107A10u;
            // 0x107a14: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x107998u: goto label_107998;
            case 0x1079D8u: goto label_1079d8;
            case 0x1079F4u: goto label_1079f4;
            case 0x107A08u: goto label_107a08;
            case 0x107A10u: goto label_107a10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x107A18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
