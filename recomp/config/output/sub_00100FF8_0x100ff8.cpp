#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00100FF8
// Address: 0x100ff8 - 0x1010a8
void sub_00100FF8_0x100ff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00100FF8_0x100ff8");
#endif

    ctx->pc = 0x100ff8u;

    // 0x100ff8: 0x34028001  ori         $v0, $zero, 0x8001
    ctx->pc = 0x100ff8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32769);
    // 0x100ffc: 0x10820026  beq         $a0, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x100FFCu;
    {
        const bool branch_taken_0x100ffc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x100FFCu;
            // 0x101000: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x100ffc) {
            ctx->pc = 0x101098u;
            goto label_101098;
        }
    }
    ctx->pc = 0x101004u;
    // 0x101004: 0x34028003  ori         $v0, $zero, 0x8003
    ctx->pc = 0x101004u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32771);
    // 0x101008: 0x10820021  beq         $a0, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x101008u;
    {
        const bool branch_taken_0x101008 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x10100Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101008u;
            // 0x10100c: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101008) {
            ctx->pc = 0x101090u;
            goto label_101090;
        }
    }
    ctx->pc = 0x101010u;
    // 0x101010: 0x34028002  ori         $v0, $zero, 0x8002
    ctx->pc = 0x101010u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32770);
    // 0x101014: 0x1082001c  beq         $a0, $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x101014u;
    {
        const bool branch_taken_0x101014 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101018u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101014u;
            // 0x101018: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101014) {
            ctx->pc = 0x101088u;
            goto label_101088;
        }
    }
    ctx->pc = 0x10101Cu;
    // 0x10101c: 0x34028004  ori         $v0, $zero, 0x8004
    ctx->pc = 0x10101cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32772);
    // 0x101020: 0x10820017  beq         $a0, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x101020u;
    {
        const bool branch_taken_0x101020 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101020u;
            // 0x101024: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101020) {
            ctx->pc = 0x101080u;
            goto label_101080;
        }
    }
    ctx->pc = 0x101028u;
    // 0x101028: 0x34028011  ori         $v0, $zero, 0x8011
    ctx->pc = 0x101028u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32785);
    // 0x10102c: 0x10820010  beq         $a0, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x10102Cu;
    {
        const bool branch_taken_0x10102c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101030u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10102Cu;
            // 0x101030: 0x34028013  ori         $v0, $zero, 0x8013 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32787);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10102c) {
            ctx->pc = 0x101070u;
            goto label_101070;
        }
    }
    ctx->pc = 0x101034u;
    // 0x101034: 0x1082000c  beq         $a0, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x101034u;
    {
        const bool branch_taken_0x101034 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101034u;
            // 0x101038: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101034) {
            ctx->pc = 0x101068u;
            goto label_101068;
        }
    }
    ctx->pc = 0x10103Cu;
    // 0x10103c: 0x34028012  ori         $v0, $zero, 0x8012
    ctx->pc = 0x10103cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32786);
    // 0x101040: 0x10820007  beq         $a0, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x101040u;
    {
        const bool branch_taken_0x101040 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x101044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101040u;
            // 0x101044: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101040) {
            ctx->pc = 0x101060u;
            goto label_101060;
        }
    }
    ctx->pc = 0x101048u;
    // 0x101048: 0x34028014  ori         $v0, $zero, 0x8014
    ctx->pc = 0x101048u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32788);
    // 0x10104c: 0x54820013  bnel        $a0, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x10104Cu;
    {
        const bool branch_taken_0x10104c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x10104c) {
            ctx->pc = 0x101050u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10104Cu;
            // 0x101050: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101054u;
    // 0x101054: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x101054u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x101058: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x101058u;
    {
        const bool branch_taken_0x101058 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10105Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101058u;
            // 0x10105c: 0x24429480  addiu       $v0, $v0, -0x6B80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294939776));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101058) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101060u;
label_101060:
    // 0x101060: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x101060u;
    {
        const bool branch_taken_0x101060 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101060u;
            // 0x101064: 0x24428f40  addiu       $v0, $v0, -0x70C0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938432));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101060) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101068u;
label_101068:
    // 0x101068: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x101068u;
    {
        const bool branch_taken_0x101068 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10106Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101068u;
            // 0x10106c: 0x24428b00  addiu       $v0, $v0, -0x7500 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937344));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101068) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101070u;
label_101070:
    // 0x101070: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101070u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101074: 0x8c42792c  lw          $v0, 0x792C($v0)
    ctx->pc = 0x101074u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
    // 0x101078: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x101078u;
    {
        const bool branch_taken_0x101078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10107Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101078u;
            // 0x10107c: 0xaca20000  sw          $v0, 0x0($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101078) {
            ctx->pc = 0x1010A0u;
            goto label_1010a0;
        }
    }
    ctx->pc = 0x101080u;
label_101080:
    // 0x101080: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x101080u;
    {
        const bool branch_taken_0x101080 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101080u;
            // 0x101084: 0x24428ad0  addiu       $v0, $v0, -0x7530 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937296));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101080) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101088u;
label_101088:
    // 0x101088: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x101088u;
    {
        const bool branch_taken_0x101088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10108Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101088u;
            // 0x10108c: 0x24427a00  addiu       $v0, $v0, 0x7A00 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101088) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101090u;
label_101090:
    // 0x101090: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x101090u;
    {
        const bool branch_taken_0x101090 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101090u;
            // 0x101094: 0x24427980  addiu       $v0, $v0, 0x7980 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 31104));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101090) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101098u;
label_101098:
    // 0x101098: 0x8c427928  lw          $v0, 0x7928($v0)
    ctx->pc = 0x101098u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
label_10109c:
    // 0x10109c: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x10109cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_1010a0:
    // 0x1010a0: 0x3e00008  jr          $ra
    ctx->pc = 0x1010A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1010A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1010A0u;
            // 0x1010a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101060u: goto label_101060;
            case 0x101068u: goto label_101068;
            case 0x101070u: goto label_101070;
            case 0x101080u: goto label_101080;
            case 0x101088u: goto label_101088;
            case 0x101090u: goto label_101090;
            case 0x101098u: goto label_101098;
            case 0x10109Cu: goto label_10109c;
            case 0x1010A0u: goto label_1010a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1010A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
