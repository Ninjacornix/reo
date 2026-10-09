#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108F40
// Address: 0x108f40 - 0x109948
void sub_00108F40_0x108f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108F40_0x108f40");
#endif

    switch (ctx->pc) {
        case 0x108f7cu: goto label_108f7c;
        case 0x108fe8u: goto label_108fe8;
        case 0x109018u: goto label_109018;
        case 0x109048u: goto label_109048;
        case 0x10906cu: goto label_10906c;
        case 0x109088u: goto label_109088;
        case 0x109118u: goto label_109118;
        case 0x109128u: goto label_109128;
        case 0x109138u: goto label_109138;
        case 0x109150u: goto label_109150;
        case 0x109164u: goto label_109164;
        case 0x109194u: goto label_109194;
        case 0x1091a4u: goto label_1091a4;
        case 0x1091b4u: goto label_1091b4;
        case 0x1091d0u: goto label_1091d0;
        case 0x1091e4u: goto label_1091e4;
        case 0x109218u: goto label_109218;
        case 0x109228u: goto label_109228;
        case 0x109238u: goto label_109238;
        case 0x109250u: goto label_109250;
        case 0x109264u: goto label_109264;
        case 0x10928cu: goto label_10928c;
        case 0x10929cu: goto label_10929c;
        case 0x1092acu: goto label_1092ac;
        case 0x1092c8u: goto label_1092c8;
        case 0x1092dcu: goto label_1092dc;
        case 0x109350u: goto label_109350;
        case 0x109388u: goto label_109388;
        case 0x1093e0u: goto label_1093e0;
        case 0x109420u: goto label_109420;
        case 0x109458u: goto label_109458;
        case 0x109480u: goto label_109480;
        case 0x1094a4u: goto label_1094a4;
        case 0x1094d0u: goto label_1094d0;
        case 0x109510u: goto label_109510;
        case 0x109548u: goto label_109548;
        case 0x10959cu: goto label_10959c;
        case 0x1095e8u: goto label_1095e8;
        case 0x109620u: goto label_109620;
        case 0x1096a0u: goto label_1096a0;
        case 0x1096d0u: goto label_1096d0;
        case 0x109700u: goto label_109700;
        case 0x109724u: goto label_109724;
        case 0x109740u: goto label_109740;
        case 0x1097b0u: goto label_1097b0;
        case 0x1097e8u: goto label_1097e8;
        case 0x109848u: goto label_109848;
        case 0x109880u: goto label_109880;
        case 0x1098d4u: goto label_1098d4;
        default: break;
    }

    ctx->pc = 0x108f40u;

label_108f40:
    // 0x108f40: 0x27bdff40  addiu       $sp, $sp, -0xC0
    ctx->pc = 0x108f40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x108f44: 0xffb00070  sd          $s0, 0x70($sp)
    ctx->pc = 0x108f44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 16));
    // 0x108f48: 0xffb10078  sd          $s1, 0x78($sp)
    ctx->pc = 0x108f48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 17));
    // 0x108f4c: 0xffb20080  sd          $s2, 0x80($sp)
    ctx->pc = 0x108f4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 18));
    // 0x108f50: 0xffb30088  sd          $s3, 0x88($sp)
    ctx->pc = 0x108f50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 136), GPR_U64(ctx, 19));
    // 0x108f54: 0xffb50098  sd          $s5, 0x98($sp)
    ctx->pc = 0x108f54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 152), GPR_U64(ctx, 21));
    // 0x108f58: 0xffb700a8  sd          $s7, 0xA8($sp)
    ctx->pc = 0x108f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 23));
    // 0x108f5c: 0xffbf00b8  sd          $ra, 0xB8($sp)
    ctx->pc = 0x108f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 31));
    // 0x108f60: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x108f60u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x108f64: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x108f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x108f68: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x108f68u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108f6c: 0xffb600a0  sd          $s6, 0xA0($sp)
    ctx->pc = 0x108f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 22));
    // 0x108f70: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x108f70u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108f74: 0xffbe00b0  sd          $fp, 0xB0($sp)
    ctx->pc = 0x108f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 30));
    // 0x108f78: 0xe0f02d  daddu       $fp, $a3, $zero
    ctx->pc = 0x108f78u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_108f7c:
    // 0x108f7c: 0x32c20007  andi        $v0, $s6, 0x7
    ctx->pc = 0x108f7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)7);
    // 0x108f80: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x108F80u;
    {
        const bool branch_taken_0x108f80 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x108F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108F80u;
            // 0x108f84: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108f80) {
            ctx->pc = 0x108F9Cu;
            goto label_108f9c;
        }
    }
    ctx->pc = 0x108F88u;
    // 0x108f88: 0x32820007  andi        $v0, $s4, 0x7
    ctx->pc = 0x108f88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)7);
    // 0x108f8c: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x108F8Cu;
    {
        const bool branch_taken_0x108f8c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x108f8c) {
            ctx->pc = 0x108F90u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108F8Cu;
            // 0x108f90: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108F9Cu;
            goto label_108f9c;
        }
    }
    ctx->pc = 0x108F94u;
    // 0x108f94: 0x3a820008  xori        $v0, $s4, 0x8
    ctx->pc = 0x108f94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) ^ (uint64_t)(uint16_t)8);
    // 0x108f98: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x108f98u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_108f9c:
    // 0x108f9c: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x108f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x108fa0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x108fa0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x108fa4: 0x2c620007  sltiu       $v0, $v1, 0x7
    ctx->pc = 0x108fa4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)7) ? 1 : 0);
    // 0x108fa8: 0x10400041  beqz        $v0, . + 4 + (0x41 << 2)
    ctx->pc = 0x108FA8u;
    {
        const bool branch_taken_0x108fa8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x108FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108FA8u;
            // 0x108fac: 0xafa00008  sw          $zero, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108fa8) {
            ctx->pc = 0x1090B0u;
            goto label_1090b0;
        }
    }
    ctx->pc = 0x108FB0u;
    // 0x108fb0: 0x741018  mult        $v0, $v1, $s4
    ctx->pc = 0x108fb0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x108fb4: 0x2d49821  addu        $s3, $s6, $s4
    ctx->pc = 0x108fb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 20)));
    // 0x108fb8: 0x561821  addu        $v1, $v0, $s6
    ctx->pc = 0x108fb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x108fbc: 0x263102b  sltu        $v0, $s3, $v1
    ctx->pc = 0x108fbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x108fc0: 0x5040024f  beql        $v0, $zero, . + 4 + (0x24F << 2)
    ctx->pc = 0x108FC0u;
    {
        const bool branch_taken_0x108fc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x108fc0) {
            ctx->pc = 0x108FC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x108FC0u;
            // 0x108fc4: 0xdfb00070  ld          $s0, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109900u;
            goto label_109900;
        }
    }
    ctx->pc = 0x108FC8u;
    // 0x108fc8: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x108fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x108fcc: 0x1410c2  srl         $v0, $s4, 3
    ctx->pc = 0x108fccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 20), 3));
    // 0x108fd0: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x108fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x108fd4: 0x2b83c  dsll32      $s7, $v0, 0
    ctx->pc = 0x108fd4u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 2) << (32 + 0));
    // 0x108fd8: 0x14903c  dsll32      $s2, $s4, 0
    ctx->pc = 0x108fd8u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 20) << (32 + 0));
    // 0x108fdc: 0x28750002  slti        $s5, $v1, 0x2
    ctx->pc = 0x108fdcu;
    SET_GPR_U64(ctx, 21, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x108fe0: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x108FE0u;
    {
        const bool branch_taken_0x108fe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x108FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108FE0u;
            // 0x108fe4: 0x260802d  daddu       $s0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108fe0) {
            ctx->pc = 0x10906Cu;
            goto label_10906c;
        }
    }
    ctx->pc = 0x108FE8u;
label_108fe8:
    // 0x108fe8: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x108FE8u;
    {
        const bool branch_taken_0x108fe8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x108fe8) {
            ctx->pc = 0x109008u;
            goto label_109008;
        }
    }
    ctx->pc = 0x108FF0u;
    // 0x108ff0: 0xde030000  ld          $v1, 0x0($s0)
    ctx->pc = 0x108ff0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x108ff4: 0xde220000  ld          $v0, 0x0($s1)
    ctx->pc = 0x108ff4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x108ff8: 0xfe020000  sd          $v0, 0x0($s0)
    ctx->pc = 0x108ff8u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 0), GPR_U64(ctx, 2));
    // 0x108ffc: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x108FFCu;
    {
        const bool branch_taken_0x108ffc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108FFCu;
            // 0x109000: 0xfe230000  sd          $v1, 0x0($s1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108ffc) {
            ctx->pc = 0x109068u;
            goto label_109068;
        }
    }
    ctx->pc = 0x109004u;
    // 0x109004: 0x0  nop
    ctx->pc = 0x109004u;
    // NOP
label_109008:
    // 0x109008: 0x12a0000d  beqz        $s5, . + 4 + (0xD << 2)
    ctx->pc = 0x109008u;
    {
        const bool branch_taken_0x109008 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x10900Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109008u;
            // 0x10900c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109008) {
            ctx->pc = 0x109040u;
            goto label_109040;
        }
    }
    ctx->pc = 0x109010u;
    // 0x109010: 0x17283e  dsrl32      $a1, $s7, 0
    ctx->pc = 0x109010u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 23) >> (32 + 0));
    // 0x109014: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x109014u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_109018:
    // 0x109018: 0xdc830000  ld          $v1, 0x0($a0)
    ctx->pc = 0x109018u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10901c: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x10901cu;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x109020: 0xdcc20000  ld          $v0, 0x0($a2)
    ctx->pc = 0x109020u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x109024: 0xfc820000  sd          $v0, 0x0($a0)
    ctx->pc = 0x109024u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x109028: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x109028u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x10902c: 0xfcc30000  sd          $v1, 0x0($a2)
    ctx->pc = 0x10902cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 3));
    // 0x109030: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109030u;
    {
        const bool branch_taken_0x109030 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x109034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109030u;
            // 0x109034: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109030) {
            ctx->pc = 0x109018u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109018;
        }
    }
    ctx->pc = 0x109038u;
    // 0x109038: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x109038u;
    {
        const bool branch_taken_0x109038 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10903Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109038u;
            // 0x10903c: 0x220802d  daddu       $s0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109038) {
            ctx->pc = 0x10906Cu;
            goto label_10906c;
        }
    }
    ctx->pc = 0x109040u;
label_109040:
    // 0x109040: 0x12283e  dsrl32      $a1, $s2, 0
    ctx->pc = 0x109040u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) >> (32 + 0));
    // 0x109044: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x109044u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_109048:
    // 0x109048: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x109048u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10904c: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x10904cu;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x109050: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x109050u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x109054: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x109054u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109058: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x109058u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10905c: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x10905cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109060: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109060u;
    {
        const bool branch_taken_0x109060 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x109064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109060u;
            // 0x109064: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109060) {
            ctx->pc = 0x109048u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109048;
        }
    }
    ctx->pc = 0x109068u;
label_109068:
    // 0x109068: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x109068u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_10906c:
    // 0x10906c: 0x2d0102b  sltu        $v0, $s6, $s0
    ctx->pc = 0x10906cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 22) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x109070: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x109070u;
    {
        const bool branch_taken_0x109070 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109070u;
            // 0x109074: 0x8fa3000c  lw          $v1, 0xC($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109070) {
            ctx->pc = 0x109094u;
            goto label_109094;
        }
    }
    ctx->pc = 0x109078u;
    // 0x109078: 0x2148823  subu        $s1, $s0, $s4
    ctx->pc = 0x109078u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 20)));
    // 0x10907c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10907cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109080: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109080u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109088u);
        ctx->pc = 0x109084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109080u;
            // 0x109084: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109088u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109088u; }
            if (ctx->pc != 0x109088u) { return; }
        }
        }
    }
    ctx->pc = 0x109088u;
label_109088:
    // 0x109088: 0x5c40ffd7  bgtzl       $v0, . + 4 + (-0x29 << 2)
    ctx->pc = 0x109088u;
    {
        const bool branch_taken_0x109088 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x109088) {
            ctx->pc = 0x10908Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109088u;
            // 0x10908c: 0x8fa40004  lw          $a0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x108FE8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108fe8;
        }
    }
    ctx->pc = 0x109090u;
    // 0x109090: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x109090u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
label_109094:
    // 0x109094: 0x2749821  addu        $s3, $s3, $s4
    ctx->pc = 0x109094u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x109098: 0x263102b  sltu        $v0, $s3, $v1
    ctx->pc = 0x109098u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x10909c: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x10909Cu;
    {
        const bool branch_taken_0x10909c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10909c) {
            ctx->pc = 0x1090A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10909Cu;
            // 0x1090a0: 0x260802d  daddu       $s0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10906Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10906c;
        }
    }
    ctx->pc = 0x1090A4u;
    // 0x1090a4: 0x10000216  b           . + 4 + (0x216 << 2)
    ctx->pc = 0x1090A4u;
    {
        const bool branch_taken_0x1090a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1090A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1090A4u;
            // 0x1090a8: 0xdfb00070  ld          $s0, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1090a4) {
            ctx->pc = 0x109900u;
            goto label_109900;
        }
    }
    ctx->pc = 0x1090ACu;
    // 0x1090ac: 0x0  nop
    ctx->pc = 0x1090acu;
    // NOP
label_1090b0:
    // 0x1090b0: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1090b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1090b4: 0x41042  srl         $v0, $a0, 1
    ctx->pc = 0x1090b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
    // 0x1090b8: 0x2c830008  sltiu       $v1, $a0, 0x8
    ctx->pc = 0x1090b8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x1090bc: 0x542018  mult        $a0, $v0, $s4
    ctx->pc = 0x1090bcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1090c0: 0x1460008f  bnez        $v1, . + 4 + (0x8F << 2)
    ctx->pc = 0x1090C0u;
    {
        const bool branch_taken_0x1090c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1090C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1090C0u;
            // 0x1090c4: 0x969821  addu        $s3, $a0, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1090c0) {
            ctx->pc = 0x109300u;
            goto label_109300;
        }
    }
    ctx->pc = 0x1090C8u;
    // 0x1090c8: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1090c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1090cc: 0x2c0802d  daddu       $s0, $s6, $zero
    ctx->pc = 0x1090ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1090d0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1090d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1090d4: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1090d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1090d8: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x1090d8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x1090dc: 0x2c620029  sltiu       $v0, $v1, 0x29
    ctx->pc = 0x1090dcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)41) ? 1 : 0);
    // 0x1090e0: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x1090e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1090e4: 0x741818  mult        $v1, $v1, $s4
    ctx->pc = 0x1090e4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1090e8: 0x14400065  bnez        $v0, . + 4 + (0x65 << 2)
    ctx->pc = 0x1090E8u;
    {
        const bool branch_taken_0x1090e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1090ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1090E8u;
            // 0x1090ec: 0x76a821  addu        $s5, $v1, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1090e8) {
            ctx->pc = 0x109280u;
            goto label_109280;
        }
    }
    ctx->pc = 0x1090F0u;
    // 0x1090f0: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x1090f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1090f4: 0x410c2  srl         $v0, $a0, 3
    ctx->pc = 0x1090f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 3));
    // 0x1090f8: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1090f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1090fc: 0x54b818  mult        $s7, $v0, $s4
    ctx->pc = 0x1090fcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 23, (int32_t)result); }
    // 0x109100: 0x171040  sll         $v0, $s7, 1
    ctx->pc = 0x109100u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 23), 1));
    // 0x109104: 0x2d78021  addu        $s0, $s6, $s7
    ctx->pc = 0x109104u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 23)));
    // 0x109108: 0xafa20010  sw          $v0, 0x10($sp)
    ctx->pc = 0x109108u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x10910c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x10910cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109110: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109110u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109118u);
        ctx->pc = 0x109114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109110u;
            // 0x109114: 0x568821  addu        $s1, $v0, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109118u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109118u; }
            if (ctx->pc != 0x109118u) { return; }
        }
        }
    }
    ctx->pc = 0x109118u;
label_109118:
    // 0x109118: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x109118u;
    {
        const bool branch_taken_0x109118 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10911Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109118u;
            // 0x10911c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109118) {
            ctx->pc = 0x109148u;
            goto label_109148;
        }
    }
    ctx->pc = 0x109120u;
    // 0x109120: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109120u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109128u);
        ctx->pc = 0x109124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109120u;
            // 0x109124: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109128u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109128u; }
            if (ctx->pc != 0x109128u) { return; }
        }
        }
    }
    ctx->pc = 0x109128u;
label_109128:
    // 0x109128: 0x4400013  bltz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x109128u;
    {
        const bool branch_taken_0x109128 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10912Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109128u;
            // 0x10912c: 0x2c0202d  daddu       $a0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109128) {
            ctx->pc = 0x109178u;
            goto label_109178;
        }
    }
    ctx->pc = 0x109130u;
    // 0x109130: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109138u);
        ctx->pc = 0x109134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109130u;
            // 0x109134: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109138u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109138u; }
            if (ctx->pc != 0x109138u) { return; }
        }
        }
    }
    ctx->pc = 0x109138u;
label_109138:
    // 0x109138: 0x220182d  daddu       $v1, $s1, $zero
    ctx->pc = 0x109138u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10913c: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x10913cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x109140: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109140u;
    {
        const bool branch_taken_0x109140 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109144u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109140u;
            // 0x109144: 0x2c2180a  movz        $v1, $s6, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 22));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109140) {
            ctx->pc = 0x10917Cu;
            goto label_10917c;
        }
    }
    ctx->pc = 0x109148u;
label_109148:
    // 0x109148: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109148u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109150u);
        ctx->pc = 0x10914Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109148u;
            // 0x10914c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109150u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109150u; }
            if (ctx->pc != 0x109150u) { return; }
        }
        }
    }
    ctx->pc = 0x109150u;
label_109150:
    // 0x109150: 0x1c40000a  bgtz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x109150u;
    {
        const bool branch_taken_0x109150 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x109154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109150u;
            // 0x109154: 0x200182d  daddu       $v1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109150) {
            ctx->pc = 0x10917Cu;
            goto label_10917c;
        }
    }
    ctx->pc = 0x109158u;
    // 0x109158: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x109158u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10915c: 0x3c0f809  jalr        $fp
    ctx->pc = 0x10915Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109164u);
        ctx->pc = 0x109160u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10915Cu;
            // 0x109160: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109164u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109164u; }
            if (ctx->pc != 0x109164u) { return; }
        }
        }
    }
    ctx->pc = 0x109164u;
label_109164:
    // 0x109164: 0x2c0182d  daddu       $v1, $s6, $zero
    ctx->pc = 0x109164u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109168: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x109168u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x10916c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10916Cu;
    {
        const bool branch_taken_0x10916c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10916Cu;
            // 0x109170: 0x222180a  movz        $v1, $s1, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10916c) {
            ctx->pc = 0x10917Cu;
            goto label_10917c;
        }
    }
    ctx->pc = 0x109174u;
    // 0x109174: 0x0  nop
    ctx->pc = 0x109174u;
    // NOP
label_109178:
    // 0x109178: 0x200182d  daddu       $v1, $s0, $zero
    ctx->pc = 0x109178u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_10917c:
    // 0x10917c: 0x2779023  subu        $s2, $s3, $s7
    ctx->pc = 0x10917cu;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 23)));
    // 0x109180: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x109180u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109184: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x109184u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109188: 0x60802d  daddu       $s0, $v1, $zero
    ctx->pc = 0x109188u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10918c: 0x3c0f809  jalr        $fp
    ctx->pc = 0x10918Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109194u);
        ctx->pc = 0x109190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10918Cu;
            // 0x109190: 0x2778821  addu        $s1, $s3, $s7 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 23)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109194u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109194u; }
            if (ctx->pc != 0x109194u) { return; }
        }
        }
    }
    ctx->pc = 0x109194u;
label_109194:
    // 0x109194: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x109194u;
    {
        const bool branch_taken_0x109194 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x109198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109194u;
            // 0x109198: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109194) {
            ctx->pc = 0x1091C8u;
            goto label_1091c8;
        }
    }
    ctx->pc = 0x10919Cu;
    // 0x10919c: 0x3c0f809  jalr        $fp
    ctx->pc = 0x10919Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1091A4u);
        ctx->pc = 0x1091A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10919Cu;
            // 0x1091a0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1091A4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1091A4u; }
            if (ctx->pc != 0x1091A4u) { return; }
        }
        }
    }
    ctx->pc = 0x1091A4u;
label_1091a4:
    // 0x1091a4: 0x4400014  bltz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1091A4u;
    {
        const bool branch_taken_0x1091a4 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1091A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1091A4u;
            // 0x1091a8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1091a4) {
            ctx->pc = 0x1091F8u;
            goto label_1091f8;
        }
    }
    ctx->pc = 0x1091ACu;
    // 0x1091ac: 0x3c0f809  jalr        $fp
    ctx->pc = 0x1091ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1091B4u);
        ctx->pc = 0x1091B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1091ACu;
            // 0x1091b0: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1091B4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1091B4u; }
            if (ctx->pc != 0x1091B4u) { return; }
        }
        }
    }
    ctx->pc = 0x1091B4u;
label_1091b4:
    // 0x1091b4: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x1091b4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1091b8: 0x242880a  movz        $s1, $s2, $v0
    ctx->pc = 0x1091b8u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 18));
    // 0x1091bc: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1091BCu;
    {
        const bool branch_taken_0x1091bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1091C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1091BCu;
            // 0x1091c0: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1091bc) {
            ctx->pc = 0x1091FCu;
            goto label_1091fc;
        }
    }
    ctx->pc = 0x1091C4u;
    // 0x1091c4: 0x0  nop
    ctx->pc = 0x1091c4u;
    // NOP
label_1091c8:
    // 0x1091c8: 0x3c0f809  jalr        $fp
    ctx->pc = 0x1091C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1091D0u);
        ctx->pc = 0x1091CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1091C8u;
            // 0x1091cc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1091D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1091D0u; }
            if (ctx->pc != 0x1091D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1091D0u;
label_1091d0:
    // 0x1091d0: 0x5c40000a  bgtzl       $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1091D0u;
    {
        const bool branch_taken_0x1091d0 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x1091d0) {
            ctx->pc = 0x1091D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1091D0u;
            // 0x1091d4: 0x260102d  daddu       $v0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1091FCu;
            goto label_1091fc;
        }
    }
    ctx->pc = 0x1091D8u;
    // 0x1091d8: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1091d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1091dc: 0x3c0f809  jalr        $fp
    ctx->pc = 0x1091DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1091E4u);
        ctx->pc = 0x1091E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1091DCu;
            // 0x1091e0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1091E4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1091E4u; }
            if (ctx->pc != 0x1091E4u) { return; }
        }
        }
    }
    ctx->pc = 0x1091E4u;
label_1091e4:
    // 0x1091e4: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x1091e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1091e8: 0x222900a  movz        $s2, $s1, $v0
    ctx->pc = 0x1091e8u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 18, GPR_VEC(ctx, 17));
    // 0x1091ec: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1091ECu;
    {
        const bool branch_taken_0x1091ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1091F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1091ECu;
            // 0x1091f0: 0x240102d  daddu       $v0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1091ec) {
            ctx->pc = 0x1091FCu;
            goto label_1091fc;
        }
    }
    ctx->pc = 0x1091F4u;
    // 0x1091f4: 0x0  nop
    ctx->pc = 0x1091f4u;
    // NOP
label_1091f8:
    // 0x1091f8: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x1091f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1091fc:
    // 0x1091fc: 0x8fa30010  lw          $v1, 0x10($sp)
    ctx->pc = 0x1091fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x109200: 0x2b78823  subu        $s1, $s5, $s7
    ctx->pc = 0x109200u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 23)));
    // 0x109204: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x109204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109208: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x109208u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10920c: 0x2a39023  subu        $s2, $s5, $v1
    ctx->pc = 0x10920cu;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 3)));
    // 0x109210: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109210u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109218u);
        ctx->pc = 0x109214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109210u;
            // 0x109214: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109218u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109218u; }
            if (ctx->pc != 0x109218u) { return; }
        }
        }
    }
    ctx->pc = 0x109218u;
label_109218:
    // 0x109218: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x109218u;
    {
        const bool branch_taken_0x109218 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x10921Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109218u;
            // 0x10921c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109218) {
            ctx->pc = 0x109248u;
            goto label_109248;
        }
    }
    ctx->pc = 0x109220u;
    // 0x109220: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109228u);
        ctx->pc = 0x109224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109220u;
            // 0x109224: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109228u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109228u; }
            if (ctx->pc != 0x109228u) { return; }
        }
        }
    }
    ctx->pc = 0x109228u;
label_109228:
    // 0x109228: 0x4400013  bltz        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x109228u;
    {
        const bool branch_taken_0x109228 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x10922Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109228u;
            // 0x10922c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109228) {
            ctx->pc = 0x109278u;
            goto label_109278;
        }
    }
    ctx->pc = 0x109230u;
    // 0x109230: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109230u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109238u);
        ctx->pc = 0x109234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109230u;
            // 0x109234: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109238u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109238u; }
            if (ctx->pc != 0x109238u) { return; }
        }
        }
    }
    ctx->pc = 0x109238u;
label_109238:
    // 0x109238: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x109238u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10923c: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x10923cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x109240: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109240u;
    {
        const bool branch_taken_0x109240 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109244u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109240u;
            // 0x109244: 0x242200a  movz        $a0, $s2, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109240) {
            ctx->pc = 0x10927Cu;
            goto label_10927c;
        }
    }
    ctx->pc = 0x109248u;
label_109248:
    // 0x109248: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109250u);
        ctx->pc = 0x10924Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109248u;
            // 0x10924c: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109250u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109250u; }
            if (ctx->pc != 0x109250u) { return; }
        }
        }
    }
    ctx->pc = 0x109250u;
label_109250:
    // 0x109250: 0x1c40000a  bgtz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x109250u;
    {
        const bool branch_taken_0x109250 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x109254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109250u;
            // 0x109254: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109250) {
            ctx->pc = 0x10927Cu;
            goto label_10927c;
        }
    }
    ctx->pc = 0x109258u;
    // 0x109258: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x109258u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10925c: 0x3c0f809  jalr        $fp
    ctx->pc = 0x10925Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109264u);
        ctx->pc = 0x109260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10925Cu;
            // 0x109260: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109264u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109264u; }
            if (ctx->pc != 0x109264u) { return; }
        }
        }
    }
    ctx->pc = 0x109264u;
label_109264:
    // 0x109264: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x109264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109268: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x109268u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x10926c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10926Cu;
    {
        const bool branch_taken_0x10926c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10926Cu;
            // 0x109270: 0x2a2200a  movz        $a0, $s5, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10926c) {
            ctx->pc = 0x10927Cu;
            goto label_10927c;
        }
    }
    ctx->pc = 0x109274u;
    // 0x109274: 0x0  nop
    ctx->pc = 0x109274u;
    // NOP
label_109278:
    // 0x109278: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x109278u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_10927c:
    // 0x10927c: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x10927cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_109280:
    // 0x109280: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x109280u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109284: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109284u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x10928Cu);
        ctx->pc = 0x109288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109284u;
            // 0x109288: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10928Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10928Cu; }
            if (ctx->pc != 0x10928Cu) { return; }
        }
        }
    }
    ctx->pc = 0x10928Cu;
label_10928c:
    // 0x10928c: 0x441000c  bgez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x10928Cu;
    {
        const bool branch_taken_0x10928c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x109290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10928Cu;
            // 0x109290: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10928c) {
            ctx->pc = 0x1092C0u;
            goto label_1092c0;
        }
    }
    ctx->pc = 0x109294u;
    // 0x109294: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109294u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x10929Cu);
        ctx->pc = 0x109298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109294u;
            // 0x109298: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10929Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10929Cu; }
            if (ctx->pc != 0x10929Cu) { return; }
        }
        }
    }
    ctx->pc = 0x10929Cu;
label_10929c:
    // 0x10929c: 0x4400014  bltz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x10929Cu;
    {
        const bool branch_taken_0x10929c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1092A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10929Cu;
            // 0x1092a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10929c) {
            ctx->pc = 0x1092F0u;
            goto label_1092f0;
        }
    }
    ctx->pc = 0x1092A4u;
    // 0x1092a4: 0x3c0f809  jalr        $fp
    ctx->pc = 0x1092A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1092ACu);
        ctx->pc = 0x1092A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092A4u;
            // 0x1092a8: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1092ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1092ACu; }
            if (ctx->pc != 0x1092ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1092ACu;
label_1092ac:
    // 0x1092ac: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1092acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1092b0: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x1092b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1092b4: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1092B4u;
    {
        const bool branch_taken_0x1092b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1092B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092B4u;
            // 0x1092b8: 0x202200a  movz        $a0, $s0, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1092b4) {
            ctx->pc = 0x1092F4u;
            goto label_1092f4;
        }
    }
    ctx->pc = 0x1092BCu;
    // 0x1092bc: 0x0  nop
    ctx->pc = 0x1092bcu;
    // NOP
label_1092c0:
    // 0x1092c0: 0x3c0f809  jalr        $fp
    ctx->pc = 0x1092C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1092C8u);
        ctx->pc = 0x1092C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092C0u;
            // 0x1092c4: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1092C8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1092C8u; }
            if (ctx->pc != 0x1092C8u) { return; }
        }
        }
    }
    ctx->pc = 0x1092C8u;
label_1092c8:
    // 0x1092c8: 0x1c40000a  bgtz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1092C8u;
    {
        const bool branch_taken_0x1092c8 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1092CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092C8u;
            // 0x1092cc: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1092c8) {
            ctx->pc = 0x1092F4u;
            goto label_1092f4;
        }
    }
    ctx->pc = 0x1092D0u;
    // 0x1092d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1092d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1092d4: 0x3c0f809  jalr        $fp
    ctx->pc = 0x1092D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1092DCu);
        ctx->pc = 0x1092D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092D4u;
            // 0x1092d8: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1092DCu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1092DCu; }
            if (ctx->pc != 0x1092DCu) { return; }
        }
        }
    }
    ctx->pc = 0x1092DCu;
label_1092dc:
    // 0x1092dc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1092dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1092e0: 0x28420000  slti        $v0, $v0, 0x0
    ctx->pc = 0x1092e0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1092e4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1092E4u;
    {
        const bool branch_taken_0x1092e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1092E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092E4u;
            // 0x1092e8: 0x2a2200a  movz        $a0, $s5, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1092e4) {
            ctx->pc = 0x1092F4u;
            goto label_1092f4;
        }
    }
    ctx->pc = 0x1092ECu;
    // 0x1092ec: 0x0  nop
    ctx->pc = 0x1092ecu;
    // NOP
label_1092f0:
    // 0x1092f0: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1092f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_1092f4:
    // 0x1092f4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1092F4u;
    {
        const bool branch_taken_0x1092f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1092F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1092F4u;
            // 0x1092f8: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1092f4) {
            ctx->pc = 0x10930Cu;
            goto label_10930c;
        }
    }
    ctx->pc = 0x1092FCu;
    // 0x1092fc: 0x0  nop
    ctx->pc = 0x1092fcu;
    // NOP
label_109300:
    // 0x109300: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x109300u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x109304: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x109304u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x109308: 0xafa40018  sw          $a0, 0x18($sp)
    ctx->pc = 0x109308u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 4));
label_10930c:
    // 0x10930c: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x10930cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x109310: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x109310u;
    {
        const bool branch_taken_0x109310 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x109314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109310u;
            // 0x109314: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109310) {
            ctx->pc = 0x109330u;
            goto label_109330;
        }
    }
    ctx->pc = 0x109318u;
    // 0x109318: 0xdec30000  ld          $v1, 0x0($s6)
    ctx->pc = 0x109318u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x10931c: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x10931cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x109320: 0xfec20000  sd          $v0, 0x0($s6)
    ctx->pc = 0x109320u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 2));
    // 0x109324: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x109324u;
    {
        const bool branch_taken_0x109324 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109324u;
            // 0x109328: 0xfe630000  sd          $v1, 0x0($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109324) {
            ctx->pc = 0x1093A8u;
            goto label_1093a8;
        }
    }
    ctx->pc = 0x10932Cu;
    // 0x10932c: 0x0  nop
    ctx->pc = 0x10932cu;
    // NOP
label_109330:
    // 0x109330: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x109330u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x109334: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x109334u;
    {
        const bool branch_taken_0x109334 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109334u;
            // 0x109338: 0x14103c  dsll32      $v0, $s4, 0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109334) {
            ctx->pc = 0x109378u;
            goto label_109378;
        }
    }
    ctx->pc = 0x10933Cu;
    // 0x10933c: 0x1410c2  srl         $v0, $s4, 3
    ctx->pc = 0x10933cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 20), 3));
    // 0x109340: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x109340u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109344: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x109344u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x109348: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x109348u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10934c: 0x2383e  dsrl32      $a3, $v0, 0
    ctx->pc = 0x10934cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) >> (32 + 0));
label_109350:
    // 0x109350: 0xdcc30000  ld          $v1, 0x0($a2)
    ctx->pc = 0x109350u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x109354: 0x64e7ffff  daddiu      $a3, $a3, -0x1
    ctx->pc = 0x109354u;
    SET_GPR_S64(ctx, 7, (int64_t)GPR_S64(ctx, 7) + (int64_t)(int32_t)4294967295);
    // 0x109358: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x109358u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10935c: 0xfcc20000  sd          $v0, 0x0($a2)
    ctx->pc = 0x10935cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 2));
    // 0x109360: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x109360u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x109364: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x109364u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x109368: 0x1ce0fff9  bgtz        $a3, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109368u;
    {
        const bool branch_taken_0x109368 = (GPR_S64(ctx, 7) > 0);
        ctx->pc = 0x10936Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109368u;
            // 0x10936c: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109368) {
            ctx->pc = 0x109350u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109350;
        }
    }
    ctx->pc = 0x109370u;
    // 0x109370: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109370u;
    {
        const bool branch_taken_0x109370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109370u;
            // 0x109374: 0x8fa20018  lw          $v0, 0x18($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109370) {
            ctx->pc = 0x1093ACu;
            goto label_1093ac;
        }
    }
    ctx->pc = 0x109378u;
label_109378:
    // 0x109378: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x109378u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10937c: 0x2283e  dsrl32      $a1, $v0, 0
    ctx->pc = 0x10937cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x109380: 0x2c0302d  daddu       $a2, $s6, $zero
    ctx->pc = 0x109380u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109384: 0x0  nop
    ctx->pc = 0x109384u;
    // NOP
label_109388:
    // 0x109388: 0x80c30000  lb          $v1, 0x0($a2)
    ctx->pc = 0x109388u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10938c: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x10938cu;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x109390: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x109390u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x109394: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x109394u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109398: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x109398u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x10939c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x10939cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1093a0: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1093A0u;
    {
        const bool branch_taken_0x1093a0 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1093A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1093A0u;
            // 0x1093a4: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1093a0) {
            ctx->pc = 0x109388u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109388;
        }
    }
    ctx->pc = 0x1093A8u;
label_1093a8:
    // 0x1093a8: 0x8fa20018  lw          $v0, 0x18($sp)
    ctx->pc = 0x1093a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
label_1093ac:
    // 0x1093ac: 0x2d48821  addu        $s1, $s6, $s4
    ctx->pc = 0x1093acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 20)));
    // 0x1093b0: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1093b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1093b4: 0x220a82d  daddu       $s5, $s1, $zero
    ctx->pc = 0x1093b4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1093b8: 0x541018  mult        $v0, $v0, $s4
    ctx->pc = 0x1093b8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1093bc: 0x14483c  dsll32      $t1, $s4, 0
    ctx->pc = 0x1093bcu;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 20) << (32 + 0));
    // 0x1093c0: 0x286a0002  slti        $t2, $v1, 0x2
    ctx->pc = 0x1093c0u;
    SET_GPR_U64(ctx, 10, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x1093c4: 0xafb1001c  sw          $s1, 0x1C($sp)
    ctx->pc = 0x1093c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 28), GPR_U32(ctx, 17));
    // 0x1093c8: 0x569821  addu        $s3, $v0, $s6
    ctx->pc = 0x1093c8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x1093cc: 0x1410c2  srl         $v0, $s4, 3
    ctx->pc = 0x1093ccu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 20), 3));
    // 0x1093d0: 0x2583c  dsll32      $t3, $v0, 0
    ctx->pc = 0x1093d0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1093d4: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1093D4u;
    {
        const bool branch_taken_0x1093d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1093D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1093D4u;
            // 0x1093d8: 0x260902d  daddu       $s2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1093d4) {
            ctx->pc = 0x109480u;
            goto label_109480;
        }
    }
    ctx->pc = 0x1093DCu;
    // 0x1093dc: 0x0  nop
    ctx->pc = 0x1093dcu;
    // NOP
label_1093e0:
    // 0x1093e0: 0x54a00027  bnel        $a1, $zero, . + 4 + (0x27 << 2)
    ctx->pc = 0x1093E0u;
    {
        const bool branch_taken_0x1093e0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1093e0) {
            ctx->pc = 0x1093E4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1093E0u;
            // 0x1093e4: 0x2348821  addu        $s1, $s1, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109480u;
            goto label_109480;
        }
    }
    ctx->pc = 0x1093E8u;
    // 0x1093e8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1093e8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1093ec: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1093ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1093f0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1093F0u;
    {
        const bool branch_taken_0x1093f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1093F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1093F0u;
            // 0x1093f4: 0xafa40008  sw          $a0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1093f0) {
            ctx->pc = 0x109410u;
            goto label_109410;
        }
    }
    ctx->pc = 0x1093F8u;
    // 0x1093f8: 0xdea30000  ld          $v1, 0x0($s5)
    ctx->pc = 0x1093f8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1093fc: 0xde220000  ld          $v0, 0x0($s1)
    ctx->pc = 0x1093fcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x109400: 0xfea20000  sd          $v0, 0x0($s5)
    ctx->pc = 0x109400u;
    WRITE64(ADD32(GPR_U32(ctx, 21), 0), GPR_U64(ctx, 2));
    // 0x109404: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x109404u;
    {
        const bool branch_taken_0x109404 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109404u;
            // 0x109408: 0xfe230000  sd          $v1, 0x0($s1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109404) {
            ctx->pc = 0x109478u;
            goto label_109478;
        }
    }
    ctx->pc = 0x10940Cu;
    // 0x10940c: 0x0  nop
    ctx->pc = 0x10940cu;
    // NOP
label_109410:
    // 0x109410: 0x1140000d  beqz        $t2, . + 4 + (0xD << 2)
    ctx->pc = 0x109410u;
    {
        const bool branch_taken_0x109410 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x109414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109410u;
            // 0x109414: 0xb303e  dsrl32      $a2, $t3, 0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 11) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109410) {
            ctx->pc = 0x109448u;
            goto label_109448;
        }
    }
    ctx->pc = 0x109418u;
    // 0x109418: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x109418u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10941c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x10941cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_109420:
    // 0x109420: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x109420u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x109424: 0x64c6ffff  daddiu      $a2, $a2, -0x1
    ctx->pc = 0x109424u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967295);
    // 0x109428: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x109428u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10942c: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x10942cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x109430: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x109430u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x109434: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x109434u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x109438: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109438u;
    {
        const bool branch_taken_0x109438 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x10943Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109438u;
            // 0x10943c: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109438) {
            ctx->pc = 0x109420u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109420;
        }
    }
    ctx->pc = 0x109440u;
    // 0x109440: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109440u;
    {
        const bool branch_taken_0x109440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109440u;
            // 0x109444: 0x2b4a821  addu        $s5, $s5, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109440) {
            ctx->pc = 0x10947Cu;
            goto label_10947c;
        }
    }
    ctx->pc = 0x109448u;
label_109448:
    // 0x109448: 0x9303e  dsrl32      $a2, $t1, 0
    ctx->pc = 0x109448u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 9) >> (32 + 0));
    // 0x10944c: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x10944cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109450: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x109450u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109454: 0x0  nop
    ctx->pc = 0x109454u;
    // NOP
label_109458:
    // 0x109458: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x109458u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10945c: 0x64c6ffff  daddiu      $a2, $a2, -0x1
    ctx->pc = 0x10945cu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967295);
    // 0x109460: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x109460u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x109464: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x109464u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109468: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x109468u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10946c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x10946cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109470: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109470u;
    {
        const bool branch_taken_0x109470 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x109474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109470u;
            // 0x109474: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109470) {
            ctx->pc = 0x109458u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109458;
        }
    }
    ctx->pc = 0x109478u;
label_109478:
    // 0x109478: 0x2b4a821  addu        $s5, $s5, $s4
    ctx->pc = 0x109478u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), GPR_U32(ctx, 20)));
label_10947c:
    // 0x10947c: 0x2348821  addu        $s1, $s1, $s4
    ctx->pc = 0x10947cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
label_109480:
    // 0x109480: 0x251802b  sltu        $s0, $s2, $s1
    ctx->pc = 0x109480u;
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
    // 0x109484: 0x1600000d  bnez        $s0, . + 4 + (0xD << 2)
    ctx->pc = 0x109484u;
    {
        const bool branch_taken_0x109484 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x109488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109484u;
            // 0x109488: 0x8fa30004  lw          $v1, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109484) {
            ctx->pc = 0x1094BCu;
            goto label_1094bc;
        }
    }
    ctx->pc = 0x10948Cu;
    // 0x10948c: 0x7fa90040  sq          $t1, 0x40($sp)
    ctx->pc = 0x10948cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 9));
    // 0x109490: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x109490u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109494: 0x7faa0050  sq          $t2, 0x50($sp)
    ctx->pc = 0x109494u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 10));
    // 0x109498: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x109498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10949c: 0x3c0f809  jalr        $fp
    ctx->pc = 0x10949Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x1094A4u);
        ctx->pc = 0x1094A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10949Cu;
            // 0x1094a0: 0x7fab0060  sq          $t3, 0x60($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 11));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1094A4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1094A4u; }
            if (ctx->pc != 0x1094A4u) { return; }
        }
        }
    }
    ctx->pc = 0x1094A4u;
label_1094a4:
    // 0x1094a4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1094a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1094a8: 0x7ba90040  lq          $t1, 0x40($sp)
    ctx->pc = 0x1094a8u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1094ac: 0x7baa0050  lq          $t2, 0x50($sp)
    ctx->pc = 0x1094acu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1094b0: 0x18a0ffcb  blez        $a1, . + 4 + (-0x35 << 2)
    ctx->pc = 0x1094B0u;
    {
        const bool branch_taken_0x1094b0 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x1094B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1094B0u;
            // 0x1094b4: 0x7bab0060  lq          $t3, 0x60($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1094b0) {
            ctx->pc = 0x1093E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1093e0;
        }
    }
    ctx->pc = 0x1094B8u;
    // 0x1094b8: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1094b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
label_1094bc:
    // 0x1094bc: 0x1410c2  srl         $v0, $s4, 3
    ctx->pc = 0x1094bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 20), 3));
    // 0x1094c0: 0x2383c  dsll32      $a3, $v0, 0
    ctx->pc = 0x1094c0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1094c4: 0x14b83c  dsll32      $s7, $s4, 0
    ctx->pc = 0x1094c4u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 20) << (32 + 0));
    // 0x1094c8: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1094C8u;
    {
        const bool branch_taken_0x1094c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1094CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1094C8u;
            // 0x1094cc: 0x28680002  slti        $t0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 8, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1094c8) {
            ctx->pc = 0x109574u;
            goto label_109574;
        }
    }
    ctx->pc = 0x1094D0u;
label_1094d0:
    // 0x1094d0: 0x54a00027  bnel        $a1, $zero, . + 4 + (0x27 << 2)
    ctx->pc = 0x1094D0u;
    {
        const bool branch_taken_0x1094d0 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1094d0) {
            ctx->pc = 0x1094D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1094D0u;
            // 0x1094d4: 0x2549023  subu        $s2, $s2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109570u;
            goto label_109570;
        }
    }
    ctx->pc = 0x1094D8u;
    // 0x1094d8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1094d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1094dc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1094dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1094e0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1094E0u;
    {
        const bool branch_taken_0x1094e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1094E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1094E0u;
            // 0x1094e4: 0xafa40008  sw          $a0, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1094e0) {
            ctx->pc = 0x109500u;
            goto label_109500;
        }
    }
    ctx->pc = 0x1094E8u;
    // 0x1094e8: 0xde430000  ld          $v1, 0x0($s2)
    ctx->pc = 0x1094e8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1094ec: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x1094ecu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1094f0: 0xfe420000  sd          $v0, 0x0($s2)
    ctx->pc = 0x1094f0u;
    WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 2));
    // 0x1094f4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1094F4u;
    {
        const bool branch_taken_0x1094f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1094F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1094F4u;
            // 0x1094f8: 0xfe630000  sd          $v1, 0x0($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1094f4) {
            ctx->pc = 0x109568u;
            goto label_109568;
        }
    }
    ctx->pc = 0x1094FCu;
    // 0x1094fc: 0x0  nop
    ctx->pc = 0x1094fcu;
    // NOP
label_109500:
    // 0x109500: 0x1100000d  beqz        $t0, . + 4 + (0xD << 2)
    ctx->pc = 0x109500u;
    {
        const bool branch_taken_0x109500 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x109504u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109500u;
            // 0x109504: 0x7303e  dsrl32      $a2, $a3, 0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 7) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109500) {
            ctx->pc = 0x109538u;
            goto label_109538;
        }
    }
    ctx->pc = 0x109508u;
    // 0x109508: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x109508u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10950c: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x10950cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_109510:
    // 0x109510: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x109510u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x109514: 0x64c6ffff  daddiu      $a2, $a2, -0x1
    ctx->pc = 0x109514u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967295);
    // 0x109518: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x109518u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10951c: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x10951cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x109520: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x109520u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x109524: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x109524u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x109528: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109528u;
    {
        const bool branch_taken_0x109528 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x10952Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109528u;
            // 0x10952c: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109528) {
            ctx->pc = 0x109510u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109510;
        }
    }
    ctx->pc = 0x109530u;
    // 0x109530: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109530u;
    {
        const bool branch_taken_0x109530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109530u;
            // 0x109534: 0x2749823  subu        $s3, $s3, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109530) {
            ctx->pc = 0x10956Cu;
            goto label_10956c;
        }
    }
    ctx->pc = 0x109538u;
label_109538:
    // 0x109538: 0x17303e  dsrl32      $a2, $s7, 0
    ctx->pc = 0x109538u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 23) >> (32 + 0));
    // 0x10953c: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x10953cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109540: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x109540u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109544: 0x0  nop
    ctx->pc = 0x109544u;
    // NOP
label_109548:
    // 0x109548: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x109548u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x10954c: 0x64c6ffff  daddiu      $a2, $a2, -0x1
    ctx->pc = 0x10954cu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967295);
    // 0x109550: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x109550u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x109554: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x109554u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109558: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x109558u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x10955c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x10955cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109560: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109560u;
    {
        const bool branch_taken_0x109560 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x109564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109560u;
            // 0x109564: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109560) {
            ctx->pc = 0x109548u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109548;
        }
    }
    ctx->pc = 0x109568u;
label_109568:
    // 0x109568: 0x2749823  subu        $s3, $s3, $s4
    ctx->pc = 0x109568u;
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
label_10956c:
    // 0x10956c: 0x2549023  subu        $s2, $s2, $s4
    ctx->pc = 0x10956cu;
    SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
label_109570:
    // 0x109570: 0x251802b  sltu        $s0, $s2, $s1
    ctx->pc = 0x109570u;
    SET_GPR_U64(ctx, 16, ((uint64_t)GPR_U64(ctx, 18) < (uint64_t)GPR_U64(ctx, 17)) ? 1 : 0);
label_109574:
    // 0x109574: 0x16000038  bnez        $s0, . + 4 + (0x38 << 2)
    ctx->pc = 0x109574u;
    {
        const bool branch_taken_0x109574 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x109578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109574u;
            // 0x109578: 0x8fa20008  lw          $v0, 0x8($sp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109574) {
            ctx->pc = 0x109658u;
            goto label_109658;
        }
    }
    ctx->pc = 0x10957Cu;
    // 0x10957c: 0x7fa70020  sq          $a3, 0x20($sp)
    ctx->pc = 0x10957cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 7));
    // 0x109580: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x109580u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109584: 0x7fa80030  sq          $t0, 0x30($sp)
    ctx->pc = 0x109584u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 8));
    // 0x109588: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x109588u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10958c: 0x7fa90040  sq          $t1, 0x40($sp)
    ctx->pc = 0x10958cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 9));
    // 0x109590: 0x7faa0050  sq          $t2, 0x50($sp)
    ctx->pc = 0x109590u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 10));
    // 0x109594: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109594u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x10959Cu);
        ctx->pc = 0x109598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109594u;
            // 0x109598: 0x7fab0060  sq          $t3, 0x60($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 11));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x10959Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x10959Cu; }
            if (ctx->pc != 0x10959Cu) { return; }
        }
        }
    }
    ctx->pc = 0x10959Cu;
label_10959c:
    // 0x10959c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x10959cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1095a0: 0x7ba70020  lq          $a3, 0x20($sp)
    ctx->pc = 0x1095a0u;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1095a4: 0x7ba80030  lq          $t0, 0x30($sp)
    ctx->pc = 0x1095a4u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1095a8: 0x7ba90040  lq          $t1, 0x40($sp)
    ctx->pc = 0x1095a8u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1095ac: 0x7baa0050  lq          $t2, 0x50($sp)
    ctx->pc = 0x1095acu;
    SET_GPR_VEC(ctx, 10, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1095b0: 0x4a1ffc7  bgez        $a1, . + 4 + (-0x39 << 2)
    ctx->pc = 0x1095B0u;
    {
        const bool branch_taken_0x1095b0 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x1095B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1095B0u;
            // 0x1095b4: 0x7bab0060  lq          $t3, 0x60($sp) (Delay Slot)
        SET_GPR_VEC(ctx, 11, READ128(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1095b0) {
            ctx->pc = 0x1094D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1094d0;
        }
    }
    ctx->pc = 0x1095B8u;
    // 0x1095b8: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x1095b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1095bc: 0x14600006  bnez        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1095BCu;
    {
        const bool branch_taken_0x1095bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1095bc) {
            ctx->pc = 0x1095D8u;
            goto label_1095d8;
        }
    }
    ctx->pc = 0x1095C4u;
    // 0x1095c4: 0xde230000  ld          $v1, 0x0($s1)
    ctx->pc = 0x1095c4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1095c8: 0xde420000  ld          $v0, 0x0($s2)
    ctx->pc = 0x1095c8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1095cc: 0xfe220000  sd          $v0, 0x0($s1)
    ctx->pc = 0x1095ccu;
    WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 2));
    // 0x1095d0: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1095D0u;
    {
        const bool branch_taken_0x1095d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1095D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1095D0u;
            // 0x1095d4: 0xfe430000  sd          $v1, 0x0($s2) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 18), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1095d0) {
            ctx->pc = 0x109640u;
            goto label_109640;
        }
    }
    ctx->pc = 0x1095D8u;
label_1095d8:
    // 0x1095d8: 0x1140000d  beqz        $t2, . + 4 + (0xD << 2)
    ctx->pc = 0x1095D8u;
    {
        const bool branch_taken_0x1095d8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1095DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1095D8u;
            // 0x1095dc: 0xb303e  dsrl32      $a2, $t3, 0 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 11) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1095d8) {
            ctx->pc = 0x109610u;
            goto label_109610;
        }
    }
    ctx->pc = 0x1095E0u;
    // 0x1095e0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1095e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1095e4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1095e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1095e8:
    // 0x1095e8: 0xdca30000  ld          $v1, 0x0($a1)
    ctx->pc = 0x1095e8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1095ec: 0x64c6ffff  daddiu      $a2, $a2, -0x1
    ctx->pc = 0x1095ecu;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967295);
    // 0x1095f0: 0xdc820000  ld          $v0, 0x0($a0)
    ctx->pc = 0x1095f0u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1095f4: 0xfca20000  sd          $v0, 0x0($a1)
    ctx->pc = 0x1095f4u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x1095f8: 0x24a50008  addiu       $a1, $a1, 0x8
    ctx->pc = 0x1095f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
    // 0x1095fc: 0xfc830000  sd          $v1, 0x0($a0)
    ctx->pc = 0x1095fcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x109600: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109600u;
    {
        const bool branch_taken_0x109600 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x109604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109600u;
            // 0x109604: 0x24840008  addiu       $a0, $a0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109600) {
            ctx->pc = 0x1095E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1095e8;
        }
    }
    ctx->pc = 0x109608u;
    // 0x109608: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109608u;
    {
        const bool branch_taken_0x109608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10960Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109608u;
            // 0x10960c: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109608) {
            ctx->pc = 0x109644u;
            goto label_109644;
        }
    }
    ctx->pc = 0x109610u;
label_109610:
    // 0x109610: 0x9303e  dsrl32      $a2, $t1, 0
    ctx->pc = 0x109610u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 9) >> (32 + 0));
    // 0x109614: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x109614u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109618: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x109618u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10961c: 0x0  nop
    ctx->pc = 0x10961cu;
    // NOP
label_109620:
    // 0x109620: 0x80a30000  lb          $v1, 0x0($a1)
    ctx->pc = 0x109620u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x109624: 0x64c6ffff  daddiu      $a2, $a2, -0x1
    ctx->pc = 0x109624u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 6) + (int64_t)(int32_t)4294967295);
    // 0x109628: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x109628u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10962c: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x10962cu;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109630: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x109630u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x109634: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x109634u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109638: 0x1cc0fff9  bgtz        $a2, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109638u;
    {
        const bool branch_taken_0x109638 = (GPR_S64(ctx, 6) > 0);
        ctx->pc = 0x10963Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109638u;
            // 0x10963c: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109638) {
            ctx->pc = 0x109620u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109620;
        }
    }
    ctx->pc = 0x109640u;
label_109640:
    // 0x109640: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x109640u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_109644:
    // 0x109644: 0x2348821  addu        $s1, $s1, $s4
    ctx->pc = 0x109644u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 20)));
    // 0x109648: 0xafa40008  sw          $a0, 0x8($sp)
    ctx->pc = 0x109648u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
    // 0x10964c: 0x1000ff8c  b           . + 4 + (-0x74 << 2)
    ctx->pc = 0x10964Cu;
    {
        const bool branch_taken_0x10964c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10964Cu;
            // 0x109650: 0x2549023  subu        $s2, $s2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10964c) {
            ctx->pc = 0x109480u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109480;
        }
    }
    ctx->pc = 0x109654u;
    // 0x109654: 0x0  nop
    ctx->pc = 0x109654u;
    // NOP
label_109658:
    // 0x109658: 0x14400043  bnez        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x109658u;
    {
        const bool branch_taken_0x109658 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10965Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109658u;
            // 0x10965c: 0x2352823  subu        $a1, $s1, $s5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 21)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109658) {
            ctx->pc = 0x109768u;
            goto label_109768;
        }
    }
    ctx->pc = 0x109660u;
    // 0x109660: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x109660u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x109664: 0x8fb3001c  lw          $s3, 0x1C($sp)
    ctx->pc = 0x109664u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 28)));
    // 0x109668: 0x541018  mult        $v0, $v0, $s4
    ctx->pc = 0x109668u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x10966c: 0x561821  addu        $v1, $v0, $s6
    ctx->pc = 0x10966cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x109670: 0x263102b  sltu        $v0, $s3, $v1
    ctx->pc = 0x109670u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x109674: 0x504000a2  beql        $v0, $zero, . + 4 + (0xA2 << 2)
    ctx->pc = 0x109674u;
    {
        const bool branch_taken_0x109674 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x109674) {
            ctx->pc = 0x109678u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109674u;
            // 0x109678: 0xdfb00070  ld          $s0, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109900u;
            goto label_109900;
        }
    }
    ctx->pc = 0x10967Cu;
    // 0x10967c: 0xafa30014  sw          $v1, 0x14($sp)
    ctx->pc = 0x10967cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 3));
    // 0x109680: 0x1410c2  srl         $v0, $s4, 3
    ctx->pc = 0x109680u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 20), 3));
    // 0x109684: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x109684u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x109688: 0x2b83c  dsll32      $s7, $v0, 0
    ctx->pc = 0x109688u;
    SET_GPR_U64(ctx, 23, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10968c: 0x14903c  dsll32      $s2, $s4, 0
    ctx->pc = 0x10968cu;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 20) << (32 + 0));
    // 0x109690: 0x28750002  slti        $s5, $v1, 0x2
    ctx->pc = 0x109690u;
    SET_GPR_U64(ctx, 21, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x109694: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x109694u;
    {
        const bool branch_taken_0x109694 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109694u;
            // 0x109698: 0x260802d  daddu       $s0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109694) {
            ctx->pc = 0x109724u;
            goto label_109724;
        }
    }
    ctx->pc = 0x10969Cu;
    // 0x10969c: 0x0  nop
    ctx->pc = 0x10969cu;
    // NOP
label_1096a0:
    // 0x1096a0: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1096A0u;
    {
        const bool branch_taken_0x1096a0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1096a0) {
            ctx->pc = 0x1096C0u;
            goto label_1096c0;
        }
    }
    ctx->pc = 0x1096A8u;
    // 0x1096a8: 0xde030000  ld          $v1, 0x0($s0)
    ctx->pc = 0x1096a8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1096ac: 0xde220000  ld          $v0, 0x0($s1)
    ctx->pc = 0x1096acu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1096b0: 0xfe020000  sd          $v0, 0x0($s0)
    ctx->pc = 0x1096b0u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 0), GPR_U64(ctx, 2));
    // 0x1096b4: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1096B4u;
    {
        const bool branch_taken_0x1096b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1096B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1096B4u;
            // 0x1096b8: 0xfe230000  sd          $v1, 0x0($s1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 17), 0), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1096b4) {
            ctx->pc = 0x109720u;
            goto label_109720;
        }
    }
    ctx->pc = 0x1096BCu;
    // 0x1096bc: 0x0  nop
    ctx->pc = 0x1096bcu;
    // NOP
label_1096c0:
    // 0x1096c0: 0x12a0000d  beqz        $s5, . + 4 + (0xD << 2)
    ctx->pc = 0x1096C0u;
    {
        const bool branch_taken_0x1096c0 = (GPR_U64(ctx, 21) == GPR_U64(ctx, 0));
        ctx->pc = 0x1096C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1096C0u;
            // 0x1096c4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1096c0) {
            ctx->pc = 0x1096F8u;
            goto label_1096f8;
        }
    }
    ctx->pc = 0x1096C8u;
    // 0x1096c8: 0x17283e  dsrl32      $a1, $s7, 0
    ctx->pc = 0x1096c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 23) >> (32 + 0));
    // 0x1096cc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1096ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1096d0:
    // 0x1096d0: 0xdc830000  ld          $v1, 0x0($a0)
    ctx->pc = 0x1096d0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1096d4: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x1096d4u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x1096d8: 0xdcc20000  ld          $v0, 0x0($a2)
    ctx->pc = 0x1096d8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1096dc: 0xfc820000  sd          $v0, 0x0($a0)
    ctx->pc = 0x1096dcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x1096e0: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x1096e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1096e4: 0xfcc30000  sd          $v1, 0x0($a2)
    ctx->pc = 0x1096e4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 3));
    // 0x1096e8: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1096E8u;
    {
        const bool branch_taken_0x1096e8 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1096ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1096E8u;
            // 0x1096ec: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1096e8) {
            ctx->pc = 0x1096D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1096d0;
        }
    }
    ctx->pc = 0x1096F0u;
    // 0x1096f0: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1096F0u;
    {
        const bool branch_taken_0x1096f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1096F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1096F0u;
            // 0x1096f4: 0x220802d  daddu       $s0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1096f0) {
            ctx->pc = 0x109724u;
            goto label_109724;
        }
    }
    ctx->pc = 0x1096F8u;
label_1096f8:
    // 0x1096f8: 0x12283e  dsrl32      $a1, $s2, 0
    ctx->pc = 0x1096f8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) >> (32 + 0));
    // 0x1096fc: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x1096fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_109700:
    // 0x109700: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x109700u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x109704: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x109704u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x109708: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x109708u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10970c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x10970cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109710: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x109710u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x109714: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x109714u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109718: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109718u;
    {
        const bool branch_taken_0x109718 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x10971Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109718u;
            // 0x10971c: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109718) {
            ctx->pc = 0x109700u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109700;
        }
    }
    ctx->pc = 0x109720u;
label_109720:
    // 0x109720: 0x220802d  daddu       $s0, $s1, $zero
    ctx->pc = 0x109720u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_109724:
    // 0x109724: 0x2d0102b  sltu        $v0, $s6, $s0
    ctx->pc = 0x109724u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 22) < (uint64_t)GPR_U64(ctx, 16)) ? 1 : 0);
    // 0x109728: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x109728u;
    {
        const bool branch_taken_0x109728 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10972Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109728u;
            // 0x10972c: 0x8fa30014  lw          $v1, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109728) {
            ctx->pc = 0x10974Cu;
            goto label_10974c;
        }
    }
    ctx->pc = 0x109730u;
    // 0x109730: 0x2148823  subu        $s1, $s0, $s4
    ctx->pc = 0x109730u;
    SET_GPR_S32(ctx, 17, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 20)));
    // 0x109734: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x109734u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109738: 0x3c0f809  jalr        $fp
    ctx->pc = 0x109738u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 30);
        SET_GPR_U32(ctx, 31, 0x109740u);
        ctx->pc = 0x10973Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109738u;
            // 0x10973c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x109740u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x109740u; }
            if (ctx->pc != 0x109740u) { return; }
        }
        }
    }
    ctx->pc = 0x109740u;
label_109740:
    // 0x109740: 0x5c40ffd7  bgtzl       $v0, . + 4 + (-0x29 << 2)
    ctx->pc = 0x109740u;
    {
        const bool branch_taken_0x109740 = (GPR_S64(ctx, 2) > 0);
        if (branch_taken_0x109740) {
            ctx->pc = 0x109744u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109740u;
            // 0x109744: 0x8fa40004  lw          $a0, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1096A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1096a0;
        }
    }
    ctx->pc = 0x109748u;
    // 0x109748: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x109748u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
label_10974c:
    // 0x10974c: 0x2749821  addu        $s3, $s3, $s4
    ctx->pc = 0x10974cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 20)));
    // 0x109750: 0x263102b  sltu        $v0, $s3, $v1
    ctx->pc = 0x109750u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 19) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x109754: 0x5440fff3  bnel        $v0, $zero, . + 4 + (-0xD << 2)
    ctx->pc = 0x109754u;
    {
        const bool branch_taken_0x109754 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x109754) {
            ctx->pc = 0x109758u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x109754u;
            // 0x109758: 0x260802d  daddu       $s0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x109724u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109724;
        }
    }
    ctx->pc = 0x10975Cu;
    // 0x10975c: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x10975Cu;
    {
        const bool branch_taken_0x10975c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x109760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10975Cu;
            // 0x109760: 0xdfb00070  ld          $s0, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10975c) {
            ctx->pc = 0x109900u;
            goto label_109900;
        }
    }
    ctx->pc = 0x109764u;
    // 0x109764: 0x0  nop
    ctx->pc = 0x109764u;
    // NOP
label_109768:
    // 0x109768: 0x2b61023  subu        $v0, $s5, $s6
    ctx->pc = 0x109768u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 22)));
    // 0x10976c: 0x45182a  slt         $v1, $v0, $a1
    ctx->pc = 0x10976cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x109770: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x109770u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109774: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x109774u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
    // 0x109778: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x109778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10977c: 0x541018  mult        $v0, $v0, $s4
    ctx->pc = 0x10977cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x109780: 0x18a00021  blez        $a1, . + 4 + (0x21 << 2)
    ctx->pc = 0x109780u;
    {
        const bool branch_taken_0x109780 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x109784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109780u;
            // 0x109784: 0x56a821  addu        $s5, $v0, $s6 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109780) {
            ctx->pc = 0x109808u;
            goto label_109808;
        }
    }
    ctx->pc = 0x109788u;
    // 0x109788: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x109788u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x10978c: 0x28620002  slti        $v0, $v1, 0x2
    ctx->pc = 0x10978cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x109790: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x109790u;
    {
        const bool branch_taken_0x109790 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109790u;
            // 0x109794: 0x2251823  subu        $v1, $s1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 17), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109790) {
            ctx->pc = 0x1097D8u;
            goto label_1097d8;
        }
    }
    ctx->pc = 0x109798u;
    // 0x109798: 0x510c2  srl         $v0, $a1, 3
    ctx->pc = 0x109798u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 3));
    // 0x10979c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x10979cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1097a0: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1097a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1097a4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1097a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1097a8: 0x2283e  dsrl32      $a1, $v0, 0
    ctx->pc = 0x1097a8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1097ac: 0x0  nop
    ctx->pc = 0x1097acu;
    // NOP
label_1097b0:
    // 0x1097b0: 0xdc830000  ld          $v1, 0x0($a0)
    ctx->pc = 0x1097b0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1097b4: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x1097b4u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x1097b8: 0xdcc20000  ld          $v0, 0x0($a2)
    ctx->pc = 0x1097b8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1097bc: 0xfc820000  sd          $v0, 0x0($a0)
    ctx->pc = 0x1097bcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x1097c0: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x1097c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1097c4: 0xfcc30000  sd          $v1, 0x0($a2)
    ctx->pc = 0x1097c4u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 3));
    // 0x1097c8: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1097C8u;
    {
        const bool branch_taken_0x1097c8 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x1097CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1097C8u;
            // 0x1097cc: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1097c8) {
            ctx->pc = 0x1097B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1097b0;
        }
    }
    ctx->pc = 0x1097D0u;
    // 0x1097d0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1097D0u;
    {
        const bool branch_taken_0x1097d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1097D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1097D0u;
            // 0x1097d4: 0x2b31823  subu        $v1, $s5, $s3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 19)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1097d0) {
            ctx->pc = 0x10980Cu;
            goto label_10980c;
        }
    }
    ctx->pc = 0x1097D8u;
label_1097d8:
    // 0x1097d8: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x1097d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1097dc: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x1097dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1097e0: 0x2283e  dsrl32      $a1, $v0, 0
    ctx->pc = 0x1097e0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1097e4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1097e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_1097e8:
    // 0x1097e8: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1097e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1097ec: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x1097ecu;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x1097f0: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x1097f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1097f4: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1097f4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1097f8: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1097f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1097fc: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x1097fcu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109800: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109800u;
    {
        const bool branch_taken_0x109800 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x109804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109800u;
            // 0x109804: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109800) {
            ctx->pc = 0x1097E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1097e8;
        }
    }
    ctx->pc = 0x109808u;
label_109808:
    // 0x109808: 0x2b31823  subu        $v1, $s5, $s3
    ctx->pc = 0x109808u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 19)));
label_10980c:
    // 0x10980c: 0x2728023  subu        $s0, $s3, $s2
    ctx->pc = 0x10980cu;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x109810: 0x742823  subu        $a1, $v1, $s4
    ctx->pc = 0x109810u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x109814: 0x205102b  sltu        $v0, $s0, $a1
    ctx->pc = 0x109814u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 16) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x109818: 0x202280b  movn        $a1, $s0, $v0
    ctx->pc = 0x109818u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 16));
    // 0x10981c: 0x58a00021  blezl       $a1, . + 4 + (0x21 << 2)
    ctx->pc = 0x10981Cu;
    {
        const bool branch_taken_0x10981c = (GPR_S64(ctx, 5) <= 0);
        if (branch_taken_0x10981c) {
            ctx->pc = 0x109820u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10981Cu;
            // 0x109820: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1098A4u;
            goto label_1098a4;
        }
    }
    ctx->pc = 0x109824u;
    // 0x109824: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x109824u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x109828: 0x28820002  slti        $v0, $a0, 0x2
    ctx->pc = 0x109828u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x10982c: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x10982Cu;
    {
        const bool branch_taken_0x10982c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x109830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10982Cu;
            // 0x109830: 0x2a51823  subu        $v1, $s5, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10982c) {
            ctx->pc = 0x109870u;
            goto label_109870;
        }
    }
    ctx->pc = 0x109834u;
    // 0x109834: 0x510c2  srl         $v0, $a1, 3
    ctx->pc = 0x109834u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 3));
    // 0x109838: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x109838u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10983c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x10983cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x109840: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x109840u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109844: 0x2283e  dsrl32      $a1, $v0, 0
    ctx->pc = 0x109844u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 0));
label_109848:
    // 0x109848: 0xdc830000  ld          $v1, 0x0($a0)
    ctx->pc = 0x109848u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10984c: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x10984cu;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x109850: 0xdcc20000  ld          $v0, 0x0($a2)
    ctx->pc = 0x109850u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x109854: 0xfc820000  sd          $v0, 0x0($a0)
    ctx->pc = 0x109854u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x109858: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x109858u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x10985c: 0xfcc30000  sd          $v1, 0x0($a2)
    ctx->pc = 0x10985cu;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 3));
    // 0x109860: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109860u;
    {
        const bool branch_taken_0x109860 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x109864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109860u;
            // 0x109864: 0x24c60008  addiu       $a2, $a2, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109860) {
            ctx->pc = 0x109848u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109848;
        }
    }
    ctx->pc = 0x109868u;
    // 0x109868: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x109868u;
    {
        const bool branch_taken_0x109868 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10986Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109868u;
            // 0x10986c: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109868) {
            ctx->pc = 0x1098A4u;
            goto label_1098a4;
        }
    }
    ctx->pc = 0x109870u;
label_109870:
    // 0x109870: 0x5103c  dsll32      $v0, $a1, 0
    ctx->pc = 0x109870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 0));
    // 0x109874: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x109874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x109878: 0x2283e  dsrl32      $a1, $v0, 0
    ctx->pc = 0x109878u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x10987c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x10987cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
label_109880:
    // 0x109880: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x109880u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x109884: 0x64a5ffff  daddiu      $a1, $a1, -0x1
    ctx->pc = 0x109884u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967295);
    // 0x109888: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x109888u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10988c: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x10988cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x109890: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x109890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x109894: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x109894u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x109898: 0x1ca0fff9  bgtz        $a1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x109898u;
    {
        const bool branch_taken_0x109898 = (GPR_S64(ctx, 5) > 0);
        ctx->pc = 0x10989Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109898u;
            // 0x10989c: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x109898) {
            ctx->pc = 0x109880u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_109880;
        }
    }
    ctx->pc = 0x1098A0u;
    // 0x1098a0: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x1098a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_1098a4:
    // 0x1098a4: 0x285102b  sltu        $v0, $s4, $a1
    ctx->pc = 0x1098a4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x1098a8: 0x5040000b  beql        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x1098A8u;
    {
        const bool branch_taken_0x1098a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1098a8) {
            ctx->pc = 0x1098ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1098A8u;
            // 0x1098ac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1098D8u;
            goto label_1098d8;
        }
    }
    ctx->pc = 0x1098B0u;
    // 0x1098b0: 0xb4001b  divu        $zero, $a1, $s4
    ctx->pc = 0x1098b0u;
    { uint32_t divisor = GPR_U32(ctx, 20); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
    // 0x1098b4: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x1098b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1098b8: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x1098b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1098bc: 0x3c0382d  daddu       $a3, $fp, $zero
    ctx->pc = 0x1098bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1098c0: 0x52800001  beql        $s4, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1098C0u;
    {
        const bool branch_taken_0x1098c0 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        if (branch_taken_0x1098c0) {
            ctx->pc = 0x1098C4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1098C0u;
            // 0x1098c4: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1098C8u;
            goto label_1098c8;
        }
    }
    ctx->pc = 0x1098C8u;
label_1098c8:
    // 0x1098c8: 0x2812  mflo        $a1
    ctx->pc = 0x1098c8u;
    SET_GPR_U64(ctx, 5, ctx->lo);
    // 0x1098cc: 0xc0423d0  jal         func_108F40
    ctx->pc = 0x1098CCu;
    SET_GPR_U32(ctx, 31, 0x1098D4u);
    ctx->pc = 0x108F40u;
    goto label_108f40;
    ctx->pc = 0x1098D4u;
label_1098d4:
    // 0x1098d4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1098d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1098d8:
    // 0x1098d8: 0x285102b  sltu        $v0, $s4, $a1
    ctx->pc = 0x1098d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x1098dc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1098DCu;
    {
        const bool branch_taken_0x1098dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1098E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1098DCu;
            // 0x1098e0: 0xdfb00070  ld          $s0, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1098dc) {
            ctx->pc = 0x109900u;
            goto label_109900;
        }
    }
    ctx->pc = 0x1098E4u;
    // 0x1098e4: 0xb4001b  divu        $zero, $a1, $s4
    ctx->pc = 0x1098e4u;
    { uint32_t divisor = GPR_U32(ctx, 20); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 5) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,5); } }
    // 0x1098e8: 0x52800001  beql        $s4, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1098E8u;
    {
        const bool branch_taken_0x1098e8 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 0));
        if (branch_taken_0x1098e8) {
            ctx->pc = 0x1098ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1098E8u;
            // 0x1098ec: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1098F0u;
            goto label_1098f0;
        }
    }
    ctx->pc = 0x1098F0u;
label_1098f0:
    // 0x1098f0: 0x2a5b023  subu        $s6, $s5, $a1
    ctx->pc = 0x1098f0u;
    SET_GPR_S32(ctx, 22, (int32_t)SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 5)));
    // 0x1098f4: 0x1012  mflo        $v0
    ctx->pc = 0x1098f4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1098f8: 0x1000fda0  b           . + 4 + (-0x260 << 2)
    ctx->pc = 0x1098F8u;
    {
        const bool branch_taken_0x1098f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1098FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1098F8u;
            // 0x1098fc: 0xafa20000  sw          $v0, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1098f8) {
            ctx->pc = 0x108F7Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108f7c;
        }
    }
    ctx->pc = 0x109900u;
label_109900:
    // 0x109900: 0xdfb10078  ld          $s1, 0x78($sp)
    ctx->pc = 0x109900u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x109904: 0xdfb20080  ld          $s2, 0x80($sp)
    ctx->pc = 0x109904u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x109908: 0xdfb30088  ld          $s3, 0x88($sp)
    ctx->pc = 0x109908u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 136)));
    // 0x10990c: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x10990cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x109910: 0xdfb50098  ld          $s5, 0x98($sp)
    ctx->pc = 0x109910u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 152)));
    // 0x109914: 0xdfb600a0  ld          $s6, 0xA0($sp)
    ctx->pc = 0x109914u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x109918: 0xdfb700a8  ld          $s7, 0xA8($sp)
    ctx->pc = 0x109918u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x10991c: 0xdfbe00b0  ld          $fp, 0xB0($sp)
    ctx->pc = 0x10991cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x109920: 0xdfbf00b8  ld          $ra, 0xB8($sp)
    ctx->pc = 0x109920u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x109924: 0x3e00008  jr          $ra
    ctx->pc = 0x109924u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x109928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109924u;
            // 0x109928: 0x27bd00c0  addiu       $sp, $sp, 0xC0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 192));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10992Cu;
    // 0x10992c: 0x0  nop
    ctx->pc = 0x10992cu;
    // NOP
    // 0x109930: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x109930u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x109934: 0x4203c  dsll32      $a0, $a0, 0
    ctx->pc = 0x109934u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x109938: 0x8c4397f0  lw          $v1, -0x6810($v0)
    ctx->pc = 0x109938u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10993c: 0x4203e  dsrl32      $a0, $a0, 0
    ctx->pc = 0x10993cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 0));
    // 0x109940: 0x3e00008  jr          $ra
    ctx->pc = 0x109940u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x109944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x109940u;
            // 0x109944: 0xfc6400a8  sd          $a0, 0xA8($v1) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 3), 168), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x108F40u: goto label_108f40;
            case 0x108F7Cu: goto label_108f7c;
            case 0x108F9Cu: goto label_108f9c;
            case 0x108FE8u: goto label_108fe8;
            case 0x109008u: goto label_109008;
            case 0x109018u: goto label_109018;
            case 0x109040u: goto label_109040;
            case 0x109048u: goto label_109048;
            case 0x109068u: goto label_109068;
            case 0x10906Cu: goto label_10906c;
            case 0x109088u: goto label_109088;
            case 0x109094u: goto label_109094;
            case 0x1090B0u: goto label_1090b0;
            case 0x109118u: goto label_109118;
            case 0x109128u: goto label_109128;
            case 0x109138u: goto label_109138;
            case 0x109148u: goto label_109148;
            case 0x109150u: goto label_109150;
            case 0x109164u: goto label_109164;
            case 0x109178u: goto label_109178;
            case 0x10917Cu: goto label_10917c;
            case 0x109194u: goto label_109194;
            case 0x1091A4u: goto label_1091a4;
            case 0x1091B4u: goto label_1091b4;
            case 0x1091C8u: goto label_1091c8;
            case 0x1091D0u: goto label_1091d0;
            case 0x1091E4u: goto label_1091e4;
            case 0x1091F8u: goto label_1091f8;
            case 0x1091FCu: goto label_1091fc;
            case 0x109218u: goto label_109218;
            case 0x109228u: goto label_109228;
            case 0x109238u: goto label_109238;
            case 0x109248u: goto label_109248;
            case 0x109250u: goto label_109250;
            case 0x109264u: goto label_109264;
            case 0x109278u: goto label_109278;
            case 0x10927Cu: goto label_10927c;
            case 0x109280u: goto label_109280;
            case 0x10928Cu: goto label_10928c;
            case 0x10929Cu: goto label_10929c;
            case 0x1092ACu: goto label_1092ac;
            case 0x1092C0u: goto label_1092c0;
            case 0x1092C8u: goto label_1092c8;
            case 0x1092DCu: goto label_1092dc;
            case 0x1092F0u: goto label_1092f0;
            case 0x1092F4u: goto label_1092f4;
            case 0x109300u: goto label_109300;
            case 0x10930Cu: goto label_10930c;
            case 0x109330u: goto label_109330;
            case 0x109350u: goto label_109350;
            case 0x109378u: goto label_109378;
            case 0x109388u: goto label_109388;
            case 0x1093A8u: goto label_1093a8;
            case 0x1093ACu: goto label_1093ac;
            case 0x1093E0u: goto label_1093e0;
            case 0x109410u: goto label_109410;
            case 0x109420u: goto label_109420;
            case 0x109448u: goto label_109448;
            case 0x109458u: goto label_109458;
            case 0x109478u: goto label_109478;
            case 0x10947Cu: goto label_10947c;
            case 0x109480u: goto label_109480;
            case 0x1094A4u: goto label_1094a4;
            case 0x1094BCu: goto label_1094bc;
            case 0x1094D0u: goto label_1094d0;
            case 0x109500u: goto label_109500;
            case 0x109510u: goto label_109510;
            case 0x109538u: goto label_109538;
            case 0x109548u: goto label_109548;
            case 0x109568u: goto label_109568;
            case 0x10956Cu: goto label_10956c;
            case 0x109570u: goto label_109570;
            case 0x109574u: goto label_109574;
            case 0x10959Cu: goto label_10959c;
            case 0x1095D8u: goto label_1095d8;
            case 0x1095E8u: goto label_1095e8;
            case 0x109610u: goto label_109610;
            case 0x109620u: goto label_109620;
            case 0x109640u: goto label_109640;
            case 0x109644u: goto label_109644;
            case 0x109658u: goto label_109658;
            case 0x1096A0u: goto label_1096a0;
            case 0x1096C0u: goto label_1096c0;
            case 0x1096D0u: goto label_1096d0;
            case 0x1096F8u: goto label_1096f8;
            case 0x109700u: goto label_109700;
            case 0x109720u: goto label_109720;
            case 0x109724u: goto label_109724;
            case 0x109740u: goto label_109740;
            case 0x10974Cu: goto label_10974c;
            case 0x109768u: goto label_109768;
            case 0x1097B0u: goto label_1097b0;
            case 0x1097D8u: goto label_1097d8;
            case 0x1097E8u: goto label_1097e8;
            case 0x109808u: goto label_109808;
            case 0x10980Cu: goto label_10980c;
            case 0x109848u: goto label_109848;
            case 0x109870u: goto label_109870;
            case 0x109880u: goto label_109880;
            case 0x1098A4u: goto label_1098a4;
            case 0x1098C8u: goto label_1098c8;
            case 0x1098D4u: goto label_1098d4;
            case 0x1098D8u: goto label_1098d8;
            case 0x1098F0u: goto label_1098f0;
            case 0x109900u: goto label_109900;
            default: break;
        }
        return;
    }
    ctx->pc = 0x109948u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
