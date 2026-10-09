#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001118F8
// Address: 0x1118f8 - 0x1119d0
void sub_001118F8_0x1118f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001118F8_0x1118f8");
#endif

    ctx->pc = 0x1118f8u;

    // 0x1118f8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1118f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1118fc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1118fcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111900: 0xdc850010  ld          $a1, 0x10($a0)
    ctx->pc = 0x111900u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x111904: 0x2c620002  sltiu       $v0, $v1, 0x2
    ctx->pc = 0x111904u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x111908: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x111908u;
    {
        const bool branch_taken_0x111908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11190Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111908u;
            // 0x11190c: 0x8c880004  lw          $t0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111908) {
            ctx->pc = 0x111928u;
            goto label_111928;
        }
    }
    ctx->pc = 0x111910u;
    // 0x111910: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x111910u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x111914: 0x2113c  dsll32      $v0, $v0, 4
    ctx->pc = 0x111914u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 4));
    // 0x111918: 0x240707ff  addiu       $a3, $zero, 0x7FF
    ctx->pc = 0x111918u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2047));
    // 0x11191c: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x11191Cu;
    {
        const bool branch_taken_0x11191c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x111920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11191Cu;
            // 0x111920: 0xa22825  or          $a1, $a1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11191c) {
            ctx->pc = 0x111974u;
            goto label_111974;
        }
    }
    ctx->pc = 0x111924u;
    // 0x111924: 0x0  nop
    ctx->pc = 0x111924u;
    // NOP
label_111928:
    // 0x111928: 0x38620004  xori        $v0, $v1, 0x4
    ctx->pc = 0x111928u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)4);
    // 0x11192c: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x11192Cu;
    {
        const bool branch_taken_0x11192c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x11192c) {
            ctx->pc = 0x111930u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11192Cu;
            // 0x111930: 0x240707ff  addiu       $a3, $zero, 0x7FF (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2047));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111968u;
            goto label_111968;
        }
    }
    ctx->pc = 0x111934u;
    // 0x111934: 0x38620002  xori        $v0, $v1, 0x2
    ctx->pc = 0x111934u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
    // 0x111938: 0x5040000e  beql        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x111938u;
    {
        const bool branch_taken_0x111938 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x111938) {
            ctx->pc = 0x11193Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111938u;
            // 0x11193c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111974u;
            goto label_111974;
        }
    }
    ctx->pc = 0x111940u;
    // 0x111940: 0x10a0000c  beqz        $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x111940u;
    {
        const bool branch_taken_0x111940 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x111940) {
            ctx->pc = 0x111974u;
            goto label_111974;
        }
    }
    ctx->pc = 0x111948u;
    // 0x111948: 0x8c840008  lw          $a0, 0x8($a0)
    ctx->pc = 0x111948u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x11194c: 0x2882fc02  slti        $v0, $a0, -0x3FE
    ctx->pc = 0x11194cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294966274) ? 1 : 0);
    // 0x111950: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x111950u;
    {
        const bool branch_taken_0x111950 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111950) {
            ctx->pc = 0x111954u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111950u;
            // 0x111954: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111974u;
            goto label_111974;
        }
    }
    ctx->pc = 0x111958u;
    // 0x111958: 0x28820400  slti        $v0, $a0, 0x400
    ctx->pc = 0x111958u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)1024) ? 1 : 0);
    // 0x11195c: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x11195Cu;
    {
        const bool branch_taken_0x11195c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x11195c) {
            ctx->pc = 0x111960u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11195Cu;
            // 0x111960: 0x248703ff  addiu       $a3, $a0, 0x3FF (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 1023));
        ctx->in_delay_slot = false;
            ctx->pc = 0x111970u;
            goto label_111970;
        }
    }
    ctx->pc = 0x111964u;
    // 0x111964: 0x240707ff  addiu       $a3, $zero, 0x7FF
    ctx->pc = 0x111964u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2047));
label_111968:
    // 0x111968: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x111968u;
    {
        const bool branch_taken_0x111968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x11196Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111968u;
            // 0x11196c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111968) {
            ctx->pc = 0x111974u;
            goto label_111974;
        }
    }
    ctx->pc = 0x111970u;
label_111970:
    // 0x111970: 0x52a3a  dsrl        $a1, $a1, 8
    ctx->pc = 0x111970u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> 8);
label_111974:
    // 0x111974: 0x3403fff0  ori         $v1, $zero, 0xFFF0
    ctx->pc = 0x111974u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65520);
    // 0x111978: 0x31c3c  dsll32      $v1, $v1, 16
    ctx->pc = 0x111978u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 16));
    // 0x11197c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x11197cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x111980: 0x2133a  dsrl        $v0, $v0, 12
    ctx->pc = 0x111980u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 12);
    // 0x111984: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x111984u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x111988: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x111988u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x11198c: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x11198cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x111990: 0x3c02800f  lui         $v0, 0x800F
    ctx->pc = 0x111990u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32783 << 16));
    // 0x111994: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x111994u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x111998: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x111998u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x11199c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11199cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1119a0: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x1119a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1119a4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1119a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1119a8: 0x30e307ff  andi        $v1, $a3, 0x7FF
    ctx->pc = 0x1119a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)2047);
    // 0x1119ac: 0xc23024  and         $a2, $a2, $v0
    ctx->pc = 0x1119acu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x1119b0: 0x31d3c  dsll32      $v1, $v1, 20
    ctx->pc = 0x1119b0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 20));
    // 0x1119b4: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x1119b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1119b8: 0x4207a  dsrl        $a0, $a0, 1
    ctx->pc = 0x1119b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> 1);
    // 0x1119bc: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x1119bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x1119c0: 0x817fc  dsll32      $v0, $t0, 31
    ctx->pc = 0x1119c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) << (32 + 31));
    // 0x1119c4: 0xc43024  and         $a2, $a2, $a0
    ctx->pc = 0x1119c4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 4));
    // 0x1119c8: 0x3e00008  jr          $ra
    ctx->pc = 0x1119C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1119CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1119C8u;
            // 0x1119cc: 0xc21025  or          $v0, $a2, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x111928u: goto label_111928;
            case 0x111968u: goto label_111968;
            case 0x111970u: goto label_111970;
            case 0x111974u: goto label_111974;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1119D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
