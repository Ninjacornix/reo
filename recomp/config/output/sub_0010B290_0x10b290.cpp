#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010B290
// Address: 0x10b290 - 0x10b440
void sub_0010B290_0x10b290(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010B290_0x10b290");
#endif

    switch (ctx->pc) {
        case 0x10b310u: goto label_10b310;
        case 0x10b388u: goto label_10b388;
        case 0x10b3b8u: goto label_10b3b8;
        case 0x10b408u: goto label_10b408;
        default: break;
    }

    ctx->pc = 0x10b290u;

    // 0x10b290: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x10b290u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b294: 0x31020007  andi        $v0, $t0, 0x7
    ctx->pc = 0x10b294u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)7);
    // 0x10b298: 0x54400044  bnel        $v0, $zero, . + 4 + (0x44 << 2)
    ctx->pc = 0x10B298u;
    {
        const bool branch_taken_0x10b298 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b298) {
            ctx->pc = 0x10B29Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B298u;
            // 0x10b29c: 0x80820000  lb          $v0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B3ACu;
            goto label_10b3ac;
        }
    }
    ctx->pc = 0x10B2A0u;
    // 0x10b2a0: 0x3103000f  andi        $v1, $t0, 0xF
    ctx->pc = 0x10b2a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)15);
    // 0x10b2a4: 0x54600025  bnel        $v1, $zero, . + 4 + (0x25 << 2)
    ctx->pc = 0x10B2A4u;
    {
        const bool branch_taken_0x10b2a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b2a4) {
            ctx->pc = 0x10B2A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B2A4u;
            // 0x10b2a8: 0xdd020000  ld          $v0, 0x0($t0) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 8), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B33Cu;
            goto label_10b33c;
        }
    }
    ctx->pc = 0x10B2ACu;
    // 0x10b2ac: 0x3c070101  lui         $a3, 0x101
    ctx->pc = 0x10b2acu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)257 << 16));
    // 0x10b2b0: 0x34e70101  ori         $a3, $a3, 0x101
    ctx->pc = 0x10b2b0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)257);
    // 0x10b2b4: 0x73c38  dsll        $a3, $a3, 16
    ctx->pc = 0x10b2b4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << 16);
    // 0x10b2b8: 0x34e70101  ori         $a3, $a3, 0x101
    ctx->pc = 0x10b2b8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)257);
    // 0x10b2bc: 0x73c38  dsll        $a3, $a3, 16
    ctx->pc = 0x10b2bcu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) << 16);
    // 0x10b2c0: 0x34e70101  ori         $a3, $a3, 0x101
    ctx->pc = 0x10b2c0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) | (uint64_t)(uint16_t)257);
    // 0x10b2c4: 0x79020000  lq          $v0, 0x0($t0)
    ctx->pc = 0x10b2c4u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x10b2c8: 0x70e74b89  pcpyld      $t1, $a3, $a3
    ctx->pc = 0x10b2c8u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 7)));
    // 0x10b2cc: 0x3c048080  lui         $a0, 0x8080
    ctx->pc = 0x10b2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32896 << 16));
    // 0x10b2d0: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b2d0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b2d4: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10b2d4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10b2d8: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b2d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b2dc: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10b2dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10b2e0: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b2e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b2e4: 0x70491a48  psubb       $v1, $v0, $t1
    ctx->pc = 0x10b2e4u;
    SET_GPR_VEC(ctx, 3, PS2_PSUBB(GPR_VEC(ctx, 2), GPR_VEC(ctx, 9)));
    // 0x10b2e8: 0x700214e9  pnor        $v0, $zero, $v0
    ctx->pc = 0x10b2e8u;
    SET_GPR_VEC(ctx, 2, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x10b2ec: 0x70845389  pcpyld      $t2, $a0, $a0
    ctx->pc = 0x10b2ecu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 4), GPR_VEC(ctx, 4)));
    // 0x10b2f0: 0x70621c89  pand        $v1, $v1, $v0
    ctx->pc = 0x10b2f0u;
    SET_GPR_VEC(ctx, 3, PS2_PAND(GPR_VEC(ctx, 3), GPR_VEC(ctx, 2)));
    // 0x10b2f4: 0x706a1c89  pand        $v1, $v1, $t2
    ctx->pc = 0x10b2f4u;
    SET_GPR_VEC(ctx, 3, PS2_PAND(GPR_VEC(ctx, 3), GPR_VEC(ctx, 10)));
    // 0x10b2f8: 0x706413a9  pcpyud      $v0, $v1, $a0
    ctx->pc = 0x10b2f8u;
    SET_GPR_VEC(ctx, 2, _mm_unpackhi_epi64(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x10b2fc: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x10b2fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x10b300: 0x14600028  bnez        $v1, . + 4 + (0x28 << 2)
    ctx->pc = 0x10B300u;
    {
        const bool branch_taken_0x10b300 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B300u;
            // 0x10b304: 0x100382d  daddu       $a3, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b300) {
            ctx->pc = 0x10B3A4u;
            goto label_10b3a4;
        }
    }
    ctx->pc = 0x10B308u;
    // 0x10b308: 0x24e70010  addiu       $a3, $a3, 0x10
    ctx->pc = 0x10b308u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x10b30c: 0x0  nop
    ctx->pc = 0x10b30cu;
    // NOP
label_10b310:
    // 0x10b310: 0x78e20000  lq          $v0, 0x0($a3)
    ctx->pc = 0x10b310u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10b314: 0x70021ce9  pnor        $v1, $zero, $v0
    ctx->pc = 0x10b314u;
    SET_GPR_VEC(ctx, 3, PS2_PNOR(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
    // 0x10b318: 0x70491248  psubb       $v0, $v0, $t1
    ctx->pc = 0x10b318u;
    SET_GPR_VEC(ctx, 2, PS2_PSUBB(GPR_VEC(ctx, 2), GPR_VEC(ctx, 9)));
    // 0x10b31c: 0x70431489  pand        $v0, $v0, $v1
    ctx->pc = 0x10b31cu;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 3)));
    // 0x10b320: 0x704a1489  pand        $v0, $v0, $t2
    ctx->pc = 0x10b320u;
    SET_GPR_VEC(ctx, 2, PS2_PAND(GPR_VEC(ctx, 2), GPR_VEC(ctx, 10)));
    // 0x10b324: 0x70441ba9  pcpyud      $v1, $v0, $a0
    ctx->pc = 0x10b324u;
    SET_GPR_VEC(ctx, 3, _mm_unpackhi_epi64(GPR_VEC(ctx, 2), GPR_VEC(ctx, 4)));
    // 0x10b328: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x10b328u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x10b32c: 0x1040fff8  beqz        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10B32Cu;
    {
        const bool branch_taken_0x10b32c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B330u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B32Cu;
            // 0x10b330: 0x24e70010  addiu       $a3, $a3, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b32c) {
            ctx->pc = 0x10B310u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b310;
        }
    }
    ctx->pc = 0x10B334u;
    // 0x10b334: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x10B334u;
    {
        const bool branch_taken_0x10b334 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B334u;
            // 0x10b338: 0x24e7fff0  addiu       $a3, $a3, -0x10 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b334) {
            ctx->pc = 0x10B3A4u;
            goto label_10b3a4;
        }
    }
    ctx->pc = 0x10B33Cu;
label_10b33c:
    // 0x10b33c: 0x3c090101  lui         $t1, 0x101
    ctx->pc = 0x10b33cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)257 << 16));
    // 0x10b340: 0x35290101  ori         $t1, $t1, 0x101
    ctx->pc = 0x10b340u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)257);
    // 0x10b344: 0x94c38  dsll        $t1, $t1, 16
    ctx->pc = 0x10b344u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 16);
    // 0x10b348: 0x35290101  ori         $t1, $t1, 0x101
    ctx->pc = 0x10b348u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)257);
    // 0x10b34c: 0x94c38  dsll        $t1, $t1, 16
    ctx->pc = 0x10b34cu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) << 16);
    // 0x10b350: 0x35290101  ori         $t1, $t1, 0x101
    ctx->pc = 0x10b350u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)257);
    // 0x10b354: 0x3c048080  lui         $a0, 0x8080
    ctx->pc = 0x10b354u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32896 << 16));
    // 0x10b358: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b358u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b35c: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10b35cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10b360: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b360u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b364: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x10b364u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x10b368: 0x34848080  ori         $a0, $a0, 0x8080
    ctx->pc = 0x10b368u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)32896);
    // 0x10b36c: 0x49182f  dsubu       $v1, $v0, $t1
    ctx->pc = 0x10b36cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) - GPR_U64(ctx, 9));
    // 0x10b370: 0x21027  nor         $v0, $zero, $v0
    ctx->pc = 0x10b370u;
    SET_GPR_U64(ctx, 2, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x10b374: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x10b374u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x10b378: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x10b378u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x10b37c: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10B37Cu;
    {
        const bool branch_taken_0x10b37c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B37Cu;
            // 0x10b380: 0x100382d  daddu       $a3, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b37c) {
            ctx->pc = 0x10B3A4u;
            goto label_10b3a4;
        }
    }
    ctx->pc = 0x10B384u;
    // 0x10b384: 0x24e70008  addiu       $a3, $a3, 0x8
    ctx->pc = 0x10b384u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
label_10b388:
    // 0x10b388: 0xdce20000  ld          $v0, 0x0($a3)
    ctx->pc = 0x10b388u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10b38c: 0x21827  nor         $v1, $zero, $v0
    ctx->pc = 0x10b38cu;
    SET_GPR_U64(ctx, 3, ~(GPR_U64(ctx, 0) | GPR_U64(ctx, 2)));
    // 0x10b390: 0x49102f  dsubu       $v0, $v0, $t1
    ctx->pc = 0x10b390u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 9));
    // 0x10b394: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x10b394u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x10b398: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x10b398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x10b39c: 0x5040fffa  beql        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10B39Cu;
    {
        const bool branch_taken_0x10b39c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10b39c) {
            ctx->pc = 0x10B3A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B39Cu;
            // 0x10b3a0: 0x24e70008  addiu       $a3, $a3, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 8));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b388;
        }
    }
    ctx->pc = 0x10B3A4u;
label_10b3a4:
    // 0x10b3a4: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x10b3a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b3a8: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10b3a8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
label_10b3ac:
    // 0x10b3ac: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10B3ACu;
    {
        const bool branch_taken_0x10b3ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B3ACu;
            // 0x10b3b0: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b3ac) {
            ctx->pc = 0x10B3D4u;
            goto label_10b3d4;
        }
    }
    ctx->pc = 0x10B3B4u;
    // 0x10b3b4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10b3b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_10b3b8:
    // 0x10b3b8: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x10b3b8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b3bc: 0x0  nop
    ctx->pc = 0x10b3bcu;
    // NOP
    // 0x10b3c0: 0x0  nop
    ctx->pc = 0x10b3c0u;
    // NOP
    // 0x10b3c4: 0x0  nop
    ctx->pc = 0x10b3c4u;
    // NOP
    // 0x10b3c8: 0x0  nop
    ctx->pc = 0x10b3c8u;
    // NOP
    // 0x10b3cc: 0x5440fffa  bnel        $v0, $zero, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10B3CCu;
    {
        const bool branch_taken_0x10b3cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10b3cc) {
            ctx->pc = 0x10B3D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B3CCu;
            // 0x10b3d0: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B3B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b3b8;
        }
    }
    ctx->pc = 0x10B3D4u;
label_10b3d4:
    // 0x10b3d4: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x10b3d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x10b3d8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x10b3d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10b3dc: 0x10c20015  beq         $a2, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x10B3DCu;
    {
        const bool branch_taken_0x10b3dc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 2));
        if (branch_taken_0x10b3dc) {
            ctx->pc = 0x10B434u;
            goto label_10b434;
        }
    }
    ctx->pc = 0x10B3E4u;
    // 0x10b3e4: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x10b3e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10b3e8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10b3e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10b3ec: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x10b3ecu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10b3f0: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x10b3f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x10b3f4: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x10B3F4u;
    {
        const bool branch_taken_0x10b3f4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B3F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B3F4u;
            // 0x10b3f8: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b3f4) {
            ctx->pc = 0x10B434u;
            goto label_10b434;
        }
    }
    ctx->pc = 0x10B3FCu;
    // 0x10b3fc: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x10b3fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x10b400: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x10b400u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x10b404: 0x0  nop
    ctx->pc = 0x10b404u;
    // NOP
label_10b408:
    // 0x10b408: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10B408u;
    {
        const bool branch_taken_0x10b408 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x10b408) {
            ctx->pc = 0x10B40Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10B408u;
            // 0x10b40c: 0xa0800000  sb          $zero, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10B410u;
            goto label_10b410;
        }
    }
    ctx->pc = 0x10B410u;
label_10b410:
    // 0x10b410: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x10b410u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x10b414: 0x10c30007  beq         $a2, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x10B414u;
    {
        const bool branch_taken_0x10b414 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        if (branch_taken_0x10b414) {
            ctx->pc = 0x10B434u;
            goto label_10b434;
        }
    }
    ctx->pc = 0x10B41Cu;
    // 0x10b41c: 0x90a20000  lbu         $v0, 0x0($a1)
    ctx->pc = 0x10b41cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10b420: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x10b420u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10b424: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x10b424u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10b428: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x10b428u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x10b42c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x10B42Cu;
    {
        const bool branch_taken_0x10b42c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B42Cu;
            // 0x10b430: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b42c) {
            ctx->pc = 0x10B408u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b408;
        }
    }
    ctx->pc = 0x10B434u;
label_10b434:
    // 0x10b434: 0x3e00008  jr          $ra
    ctx->pc = 0x10B434u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B438u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B434u;
            // 0x10b438: 0x100102d  daddu       $v0, $t0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B310u: goto label_10b310;
            case 0x10B33Cu: goto label_10b33c;
            case 0x10B388u: goto label_10b388;
            case 0x10B3A4u: goto label_10b3a4;
            case 0x10B3ACu: goto label_10b3ac;
            case 0x10B3B8u: goto label_10b3b8;
            case 0x10B3D4u: goto label_10b3d4;
            case 0x10B408u: goto label_10b408;
            case 0x10B410u: goto label_10b410;
            case 0x10B434u: goto label_10b434;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B43Cu;
    // 0x10b43c: 0x0  nop
    ctx->pc = 0x10b43cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
