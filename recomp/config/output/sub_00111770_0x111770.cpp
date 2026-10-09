#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00111770
// Address: 0x111770 - 0x111828
void sub_00111770_0x111770(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00111770_0x111770");
#endif

    ctx->pc = 0x111770u;

    // 0x111770: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x111770u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x111774: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x111774u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x111778: 0x8c85000c  lw          $a1, 0xC($a0)
    ctx->pc = 0x111778u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x11177c: 0x38420002  xori        $v0, $v0, 0x2
    ctx->pc = 0x11177cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)2);
    // 0x111780: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x111780u;
    {
        const bool branch_taken_0x111780 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x111784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111780u;
            // 0x111784: 0x8c880004  lw          $t0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111780) {
            ctx->pc = 0x1117C4u;
            goto label_1117c4;
        }
    }
    ctx->pc = 0x111788u;
    // 0x111788: 0x10a00013  beqz        $a1, . + 4 + (0x13 << 2)
    ctx->pc = 0x111788u;
    {
        const bool branch_taken_0x111788 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x11178Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x111788u;
            // 0x11178c: 0x3c02007f  lui         $v0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x111788) {
            ctx->pc = 0x1117D8u;
            goto label_1117d8;
        }
    }
    ctx->pc = 0x111790u;
    // 0x111790: 0x8c840008  lw          $a0, 0x8($a0)
    ctx->pc = 0x111790u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x111794: 0x2882ff82  slti        $v0, $a0, -0x7E
    ctx->pc = 0x111794u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294967170) ? 1 : 0);
    // 0x111798: 0x5440000e  bnel        $v0, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x111798u;
    {
        const bool branch_taken_0x111798 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x111798) {
            ctx->pc = 0x11179Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x111798u;
            // 0x11179c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1117D4u;
            goto label_1117d4;
        }
    }
    ctx->pc = 0x1117A0u;
    // 0x1117a0: 0x28820081  slti        $v0, $a0, 0x81
    ctx->pc = 0x1117a0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)129) ? 1 : 0);
    // 0x1117a4: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x1117A4u;
    {
        const bool branch_taken_0x1117a4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1117a4) {
            ctx->pc = 0x1117A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1117A4u;
            // 0x1117a8: 0x240700ff  addiu       $a3, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1117C4u;
            goto label_1117c4;
        }
    }
    ctx->pc = 0x1117ACu;
    // 0x1117ac: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1117acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1117b0: 0x14820007  bne         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1117B0u;
    {
        const bool branch_taken_0x1117b0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1117B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1117B0u;
            // 0x1117b4: 0x2487007f  addiu       $a3, $a0, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), 127));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1117b0) {
            ctx->pc = 0x1117D0u;
            goto label_1117d0;
        }
    }
    ctx->pc = 0x1117B8u;
    // 0x1117b8: 0x4a30006  bgezl       $a1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1117B8u;
    {
        const bool branch_taken_0x1117b8 = (GPR_S64(ctx, 5) >= 0);
        if (branch_taken_0x1117b8) {
            ctx->pc = 0x1117BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1117B8u;
            // 0x1117bc: 0x529c2  srl         $a1, $a1, 7 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 7));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1117D4u;
            goto label_1117d4;
        }
    }
    ctx->pc = 0x1117C0u;
    // 0x1117c0: 0x240700ff  addiu       $a3, $zero, 0xFF
    ctx->pc = 0x1117c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
label_1117c4:
    // 0x1117c4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1117C4u;
    {
        const bool branch_taken_0x1117c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1117C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1117C4u;
            // 0x1117c8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1117c4) {
            ctx->pc = 0x1117D4u;
            goto label_1117d4;
        }
    }
    ctx->pc = 0x1117CCu;
    // 0x1117cc: 0x0  nop
    ctx->pc = 0x1117ccu;
    // NOP
label_1117d0:
    // 0x1117d0: 0x529c2  srl         $a1, $a1, 7
    ctx->pc = 0x1117d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 7));
label_1117d4:
    // 0x1117d4: 0x3c02007f  lui         $v0, 0x7F
    ctx->pc = 0x1117d4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)127 << 16));
label_1117d8:
    // 0x1117d8: 0x3c03ff80  lui         $v1, 0xFF80
    ctx->pc = 0x1117d8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65408 << 16));
    // 0x1117dc: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1117dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1117e0: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x1117e0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x1117e4: 0xa21024  and         $v0, $a1, $v0
    ctx->pc = 0x1117e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & GPR_U64(ctx, 2));
    // 0x1117e8: 0x3c03807f  lui         $v1, 0x807F
    ctx->pc = 0x1117e8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32895 << 16));
    // 0x1117ec: 0xc23025  or          $a2, $a2, $v0
    ctx->pc = 0x1117ecu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 2));
    // 0x1117f0: 0x3c027fff  lui         $v0, 0x7FFF
    ctx->pc = 0x1117f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32767 << 16));
    // 0x1117f4: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x1117f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x1117f8: 0x30e400ff  andi        $a0, $a3, 0xFF
    ctx->pc = 0x1117f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)255);
    // 0x1117fc: 0xc33024  and         $a2, $a2, $v1
    ctx->pc = 0x1117fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 3));
    // 0x111800: 0x81fc0  sll         $v1, $t0, 31
    ctx->pc = 0x111800u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 8), 31));
    // 0x111804: 0x425c0  sll         $a0, $a0, 23
    ctx->pc = 0x111804u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 23));
    // 0x111808: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x111808u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x11180c: 0xc43025  or          $a2, $a2, $a0
    ctx->pc = 0x11180cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 4));
    // 0x111810: 0xc23024  and         $a2, $a2, $v0
    ctx->pc = 0x111810u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & GPR_U64(ctx, 2));
    // 0x111814: 0xc33025  or          $a2, $a2, $v1
    ctx->pc = 0x111814u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 3));
    // 0x111818: 0x44860000  mtc1        $a2, $f0
    ctx->pc = 0x111818u;
    { uint32_t bits = GPR_U32(ctx, 6); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x11181c: 0x3e00008  jr          $ra
    ctx->pc = 0x11181Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1117C4u: goto label_1117c4;
            case 0x1117D0u: goto label_1117d0;
            case 0x1117D4u: goto label_1117d4;
            case 0x1117D8u: goto label_1117d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x111824u;
    // 0x111824: 0x0  nop
    ctx->pc = 0x111824u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
