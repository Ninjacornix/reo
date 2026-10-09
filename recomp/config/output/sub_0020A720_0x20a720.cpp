#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A720
// Address: 0x20a720 - 0x20a7c4
void sub_0020A720_0x20a720(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A720_0x20a720");
#endif

    switch (ctx->pc) {
        case 0x20a768u: goto label_20a768;
        default: break;
    }

    ctx->pc = 0x20a720u;

    // 0x20a720: 0xa63821  addu        $a3, $a1, $a2
    ctx->pc = 0x20a720u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x20a724: 0x2ce20081  sltiu       $v0, $a3, 0x81
    ctx->pc = 0x20a724u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)129) ? 1 : 0);
    // 0x20a728: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x20A728u;
    {
        const bool branch_taken_0x20a728 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20A72Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A728u;
            // 0x20a72c: 0x80502d  daddu       $t2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a728) {
            ctx->pc = 0x20A74Cu;
            goto label_20a74c;
        }
    }
    ctx->pc = 0x20A730u;
    // 0x20a730: 0x2cc20080  sltiu       $v0, $a2, 0x80
    ctx->pc = 0x20a730u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x20a734: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x20A734u;
    {
        const bool branch_taken_0x20a734 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A734u;
            // 0x20a738: 0x24020080  addiu       $v0, $zero, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a734) {
            ctx->pc = 0x20A744u;
            goto label_20a744;
        }
    }
    ctx->pc = 0x20A73Cu;
    // 0x20a73c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x20A73Cu;
    {
        const bool branch_taken_0x20a73c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A73Cu;
            // 0x20a740: 0x462823  subu        $a1, $v0, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a73c) {
            ctx->pc = 0x20A74Cu;
            goto label_20a74c;
        }
    }
    ctx->pc = 0x20A744u;
label_20a744:
    // 0x20a744: 0x24060080  addiu       $a2, $zero, 0x80
    ctx->pc = 0x20a744u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x20a748: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x20a748u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_20a74c:
    // 0x20a74c: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x20a74cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x20a750: 0xc5102b  sltu        $v0, $a2, $a1
    ctx->pc = 0x20a750u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x20a754: 0x1040000f  beqz        $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x20A754u;
    {
        const bool branch_taken_0x20a754 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A754u;
            // 0x20a758: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a754) {
            ctx->pc = 0x20A794u;
            goto label_20a794;
        }
    }
    ctx->pc = 0x20A75Cu;
    // 0x20a75c: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x20a75cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a760: 0x3c098007  lui         $t1, 0x8007
    ctx->pc = 0x20a760u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32775 << 16));
    // 0x20a764: 0x3c058007  lui         $a1, 0x8007
    ctx->pc = 0x20a764u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32775 << 16));
label_20a768:
    // 0x20a768: 0x24a247b0  addiu       $v0, $a1, 0x47B0
    ctx->pc = 0x20a768u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 18352));
    // 0x20a76c: 0x1482021  addu        $a0, $t2, $t0
    ctx->pc = 0x20a76cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 8)));
    // 0x20a770: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x20a770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x20a774: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x20a774u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x20a778: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x20a778u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x20a77c: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x20a77cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x20a780: 0xc7102b  sltu        $v0, $a2, $a3
    ctx->pc = 0x20a780u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x20a784: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x20A784u;
    {
        const bool branch_taken_0x20a784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x20A788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A784u;
            // 0x20a788: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a784) {
            ctx->pc = 0x20A768u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20a768;
        }
    }
    ctx->pc = 0x20A78Cu;
    // 0x20a78c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x20A78Cu;
    {
        const bool branch_taken_0x20a78c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A78Cu;
            // 0x20a790: 0xdd234700  ld          $v1, 0x4700($t1) (Delay Slot)
        SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 9), 18176)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a78c) {
            ctx->pc = 0x20A79Cu;
            goto label_20a79c;
        }
    }
    ctx->pc = 0x20A794u;
label_20a794:
    // 0x20a794: 0x3c098007  lui         $t1, 0x8007
    ctx->pc = 0x20a794u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)32775 << 16));
    // 0x20a798: 0xdd234700  ld          $v1, 0x4700($t1)
    ctx->pc = 0x20a798u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 9), 18176)));
label_20a79c:
    // 0x20a79c: 0x316b8  dsll        $v0, $v1, 26
    ctx->pc = 0x20a79cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << 26);
    // 0x20a7a0: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x20a7a0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x20a7a4: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x20a7a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x20a7a8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x20A7A8u;
    {
        const bool branch_taken_0x20a7a8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x20a7a8) {
            ctx->pc = 0x20A7B8u;
            goto label_20a7b8;
        }
    }
    ctx->pc = 0x20A7B0u;
    // 0x20a7b0: 0x3e00008  jr          $ra
    ctx->pc = 0x20A7B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20A7B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A7B0u;
            // 0x20a7b4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A744u: goto label_20a744;
            case 0x20A74Cu: goto label_20a74c;
            case 0x20A768u: goto label_20a768;
            case 0x20A794u: goto label_20a794;
            case 0x20A79Cu: goto label_20a79c;
            case 0x20A7B8u: goto label_20a7b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20A7B8u;
label_20a7b8:
    // 0x20a7b8: 0x3133e  dsrl32      $v0, $v1, 12
    ctx->pc = 0x20a7b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) >> (32 + 12));
    // 0x20a7bc: 0x3e00008  jr          $ra
    ctx->pc = 0x20A7BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x20A7C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A7BCu;
            // 0x20a7c0: 0x3042000f  andi        $v0, $v0, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A744u: goto label_20a744;
            case 0x20A74Cu: goto label_20a74c;
            case 0x20A768u: goto label_20a768;
            case 0x20A794u: goto label_20a794;
            case 0x20A79Cu: goto label_20a79c;
            case 0x20A7B8u: goto label_20a7b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20A7C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
