#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146650
// Address: 0x146650 - 0x146908
void sub_00146650_0x146650(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146650_0x146650");
#endif

    ctx->pc = 0x146650u;

    // 0x146650: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x146650u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146654: 0x240b0004  addiu       $t3, $zero, 0x4
    ctx->pc = 0x146654u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x146658: 0x8ce9018c  lw          $t1, 0x18C($a3)
    ctx->pc = 0x146658u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 396)));
    // 0x14665c: 0x240c0002  addiu       $t4, $zero, 0x2
    ctx->pc = 0x14665cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146660: 0x8cea0168  lw          $t2, 0x168($a3)
    ctx->pc = 0x146660u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 360)));
    // 0x146664: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x146664u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146668: 0x39220003  xori        $v0, $t1, 0x3
    ctx->pc = 0x146668u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) ^ (uint64_t)(uint16_t)3);
    // 0x14666c: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x14666cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146670: 0x240e0003  addiu       $t6, $zero, 0x3
    ctx->pc = 0x146670u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x146674: 0x154e0044  bne         $t2, $t6, . + 4 + (0x44 << 2)
    ctx->pc = 0x146674u;
    {
        const bool branch_taken_0x146674 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 14));
        ctx->pc = 0x146678u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146674u;
            // 0x146678: 0x182580a  movz        $t3, $t4, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 11, GPR_VEC(ctx, 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146674) {
            ctx->pc = 0x146788u;
            goto label_146788;
        }
    }
    ctx->pc = 0x14667Cu;
    // 0x14667c: 0x8ce200b8  lw          $v0, 0xB8($a3)
    ctx->pc = 0x14667cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 184)));
    // 0x146680: 0x8ce300bc  lw          $v1, 0xBC($a3)
    ctx->pc = 0x146680u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 188)));
    // 0x146684: 0x8ce501dc  lw          $a1, 0x1DC($a3)
    ctx->pc = 0x146684u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 476)));
    // 0x146688: 0x8ce601ec  lw          $a2, 0x1EC($a3)
    ctx->pc = 0x146688u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 492)));
    // 0x14668c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14668cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x146690: 0x8ce401fc  lw          $a0, 0x1FC($a3)
    ctx->pc = 0x146690u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 508)));
    // 0x146694: 0x4b102a  slt         $v0, $v0, $t3
    ctx->pc = 0x146694u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 11)) ? 1 : 0);
    // 0x146698: 0xace501d8  sw          $a1, 0x1D8($a3)
    ctx->pc = 0x146698u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 472), GPR_U32(ctx, 5));
    // 0x14669c: 0xace601e8  sw          $a2, 0x1E8($a3)
    ctx->pc = 0x14669cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 488), GPR_U32(ctx, 6));
    // 0x1466a0: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1466A0u;
    {
        const bool branch_taken_0x1466a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1466A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1466A0u;
            // 0x1466a4: 0xace401f8  sw          $a0, 0x1F8($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 504), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1466a0) {
            ctx->pc = 0x1466B4u;
            goto label_1466b4;
        }
    }
    ctx->pc = 0x1466A8u;
    // 0x1466a8: 0xace00100  sw          $zero, 0x100($a3)
    ctx->pc = 0x1466a8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 256), GPR_U32(ctx, 0));
    // 0x1466ac: 0xace001c0  sw          $zero, 0x1C0($a3)
    ctx->pc = 0x1466acu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 448), GPR_U32(ctx, 0));
    // 0x1466b0: 0xace001bc  sw          $zero, 0x1BC($a3)
    ctx->pc = 0x1466b0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 444), GPR_U32(ctx, 0));
label_1466b4:
    // 0x1466b4: 0x8ce20100  lw          $v0, 0x100($a3)
    ctx->pc = 0x1466b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 256)));
    // 0x1466b8: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1466B8u;
    {
        const bool branch_taken_0x1466b8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1466b8) {
            ctx->pc = 0x1466BCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1466B8u;
            // 0x1466bc: 0x8ce201bc  lw          $v0, 0x1BC($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 444)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1466D0u;
            goto label_1466d0;
        }
    }
    ctx->pc = 0x1466C0u;
    // 0x1466c0: 0x8ce201c0  lw          $v0, 0x1C0($a3)
    ctx->pc = 0x1466c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 448)));
    // 0x1466c4: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x1466C4u;
    {
        const bool branch_taken_0x1466c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1466c4) {
            ctx->pc = 0x1466C8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1466C4u;
            // 0x1466c8: 0xace00100  sw          $zero, 0x100($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 256), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1466F8u;
            goto label_1466f8;
        }
    }
    ctx->pc = 0x1466CCu;
    // 0x1466cc: 0x8ce201bc  lw          $v0, 0x1BC($a3)
    ctx->pc = 0x1466ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 444)));
label_1466d0:
    // 0x1466d0: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x1466D0u;
    {
        const bool branch_taken_0x1466d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1466d0) {
            ctx->pc = 0x1466D4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1466D0u;
            // 0x1466d4: 0xace00100  sw          $zero, 0x100($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 256), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1466F8u;
            goto label_1466f8;
        }
    }
    ctx->pc = 0x1466D8u;
    // 0x1466d8: 0x8ce201d0  lw          $v0, 0x1D0($a3)
    ctx->pc = 0x1466d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 464)));
    // 0x1466dc: 0x8ce401e0  lw          $a0, 0x1E0($a3)
    ctx->pc = 0x1466dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 480)));
    // 0x1466e0: 0xac400028  sw          $zero, 0x28($v0)
    ctx->pc = 0x1466e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 40), GPR_U32(ctx, 0));
    // 0x1466e4: 0x8ce301f0  lw          $v1, 0x1F0($a3)
    ctx->pc = 0x1466e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 496)));
    // 0x1466e8: 0xac800028  sw          $zero, 0x28($a0)
    ctx->pc = 0x1466e8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
    // 0x1466ec: 0xac600028  sw          $zero, 0x28($v1)
    ctx->pc = 0x1466ecu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 40), GPR_U32(ctx, 0));
    // 0x1466f0: 0x8ce9018c  lw          $t1, 0x18C($a3)
    ctx->pc = 0x1466f0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 396)));
    // 0x1466f4: 0xace00100  sw          $zero, 0x100($a3)
    ctx->pc = 0x1466f4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 256), GPR_U32(ctx, 0));
label_1466f8:
    // 0x1466f8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1466f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1466fc: 0x1522000b  bne         $t1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1466FCu;
    {
        const bool branch_taken_0x1466fc = (GPR_U64(ctx, 9) != GPR_U64(ctx, 2));
        ctx->pc = 0x146700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1466FCu;
            // 0x146700: 0xace001c0  sw          $zero, 0x1C0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 448), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1466fc) {
            ctx->pc = 0x14672Cu;
            goto label_14672c;
        }
    }
    ctx->pc = 0x146704u;
    // 0x146704: 0x8ce301d0  lw          $v1, 0x1D0($a3)
    ctx->pc = 0x146704u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 464)));
    // 0x146708: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x146708u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14670c: 0x8c620028  lw          $v0, 0x28($v1)
    ctx->pc = 0x14670cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x146710: 0x50440018  beql        $v0, $a0, . + 4 + (0x18 << 2)
    ctx->pc = 0x146710u;
    {
        const bool branch_taken_0x146710 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x146710) {
            ctx->pc = 0x146714u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146710u;
            // 0x146714: 0x8ce301d4  lw          $v1, 0x1D4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 468)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146774u;
            goto label_146774;
        }
    }
    ctx->pc = 0x146718u;
    // 0x146718: 0x8ce201bc  lw          $v0, 0x1BC($a3)
    ctx->pc = 0x146718u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 444)));
    // 0x14671c: 0x10400048  beqz        $v0, . + 4 + (0x48 << 2)
    ctx->pc = 0x14671Cu;
    {
        const bool branch_taken_0x14671c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14671Cu;
            // 0x146720: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14671c) {
            ctx->pc = 0x146840u;
            goto label_146840;
        }
    }
    ctx->pc = 0x146724u;
    // 0x146724: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x146724u;
    {
        const bool branch_taken_0x146724 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146724u;
            // 0x146728: 0x8ce301d4  lw          $v1, 0x1D4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 468)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146724) {
            ctx->pc = 0x146774u;
            goto label_146774;
        }
    }
    ctx->pc = 0x14672Cu;
label_14672c:
    // 0x14672c: 0x8ce201e0  lw          $v0, 0x1E0($a3)
    ctx->pc = 0x14672cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 480)));
    // 0x146730: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x146730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146734: 0x8c440028  lw          $a0, 0x28($v0)
    ctx->pc = 0x146734u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x146738: 0x54830006  bnel        $a0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x146738u;
    {
        const bool branch_taken_0x146738 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x146738) {
            ctx->pc = 0x14673Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146738u;
            // 0x14673c: 0x8ce201bc  lw          $v0, 0x1BC($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 444)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146754u;
            goto label_146754;
        }
    }
    ctx->pc = 0x146740u;
    // 0x146740: 0x8ce201f0  lw          $v0, 0x1F0($a3)
    ctx->pc = 0x146740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 496)));
    // 0x146744: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x146744u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x146748: 0x50640005  beql        $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x146748u;
    {
        const bool branch_taken_0x146748 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x146748) {
            ctx->pc = 0x14674Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146748u;
            // 0x14674c: 0x8ce201e4  lw          $v0, 0x1E4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 484)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146760u;
            goto label_146760;
        }
    }
    ctx->pc = 0x146750u;
    // 0x146750: 0x8ce201bc  lw          $v0, 0x1BC($a3)
    ctx->pc = 0x146750u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 444)));
label_146754:
    // 0x146754: 0x1040003a  beqz        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x146754u;
    {
        const bool branch_taken_0x146754 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146758u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146754u;
            // 0x146758: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146754) {
            ctx->pc = 0x146840u;
            goto label_146840;
        }
    }
    ctx->pc = 0x14675Cu;
    // 0x14675c: 0x8ce201e4  lw          $v0, 0x1E4($a3)
    ctx->pc = 0x14675cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 484)));
label_146760:
    // 0x146760: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x146760u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146764: 0x8c440028  lw          $a0, 0x28($v0)
    ctx->pc = 0x146764u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x146768: 0x14830035  bne         $a0, $v1, . + 4 + (0x35 << 2)
    ctx->pc = 0x146768u;
    {
        const bool branch_taken_0x146768 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x14676Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146768u;
            // 0x14676c: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146768) {
            ctx->pc = 0x146840u;
            goto label_146840;
        }
    }
    ctx->pc = 0x146770u;
    // 0x146770: 0x8ce301f4  lw          $v1, 0x1F4($a3)
    ctx->pc = 0x146770u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 500)));
label_146774:
    // 0x146774: 0x80682d  daddu       $t5, $a0, $zero
    ctx->pc = 0x146774u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146778: 0x8c620028  lw          $v0, 0x28($v1)
    ctx->pc = 0x146778u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x14677c: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x14677cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x146780: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x146780u;
    {
        const bool branch_taken_0x146780 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146784u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146780u;
            // 0x146784: 0x2680b  movn        $t5, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 13, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146780) {
            ctx->pc = 0x14683Cu;
            goto label_14683c;
        }
    }
    ctx->pc = 0x146788u;
label_146788:
    // 0x146788: 0x54a0000e  bnel        $a1, $zero, . + 4 + (0xE << 2)
    ctx->pc = 0x146788u;
    {
        const bool branch_taken_0x146788 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x146788) {
            ctx->pc = 0x14678Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146788u;
            // 0x14678c: 0x8ce201d4  lw          $v0, 0x1D4($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 468)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1467C4u;
            goto label_1467c4;
        }
    }
    ctx->pc = 0x146790u;
    // 0x146790: 0x8ce601d0  lw          $a2, 0x1D0($a3)
    ctx->pc = 0x146790u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 464)));
    // 0x146794: 0x8ce401d4  lw          $a0, 0x1D4($a3)
    ctx->pc = 0x146794u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 468)));
    // 0x146798: 0xace601d4  sw          $a2, 0x1D4($a3)
    ctx->pc = 0x146798u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 468), GPR_U32(ctx, 6));
    // 0x14679c: 0x8ce601e0  lw          $a2, 0x1E0($a3)
    ctx->pc = 0x14679cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 480)));
    // 0x1467a0: 0x8ce301e4  lw          $v1, 0x1E4($a3)
    ctx->pc = 0x1467a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 484)));
    // 0x1467a4: 0xace601e4  sw          $a2, 0x1E4($a3)
    ctx->pc = 0x1467a4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 484), GPR_U32(ctx, 6));
    // 0x1467a8: 0x8ce601f0  lw          $a2, 0x1F0($a3)
    ctx->pc = 0x1467a8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 496)));
    // 0x1467ac: 0x8ce201f4  lw          $v0, 0x1F4($a3)
    ctx->pc = 0x1467acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 500)));
    // 0x1467b0: 0xace401d0  sw          $a0, 0x1D0($a3)
    ctx->pc = 0x1467b0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 464), GPR_U32(ctx, 4));
    // 0x1467b4: 0xace301e0  sw          $v1, 0x1E0($a3)
    ctx->pc = 0x1467b4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 480), GPR_U32(ctx, 3));
    // 0x1467b8: 0xace201f0  sw          $v0, 0x1F0($a3)
    ctx->pc = 0x1467b8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 496), GPR_U32(ctx, 2));
    // 0x1467bc: 0xace601f4  sw          $a2, 0x1F4($a3)
    ctx->pc = 0x1467bcu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 500), GPR_U32(ctx, 6));
    // 0x1467c0: 0x8ce201d4  lw          $v0, 0x1D4($a3)
    ctx->pc = 0x1467c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 468)));
label_1467c4:
    // 0x1467c4: 0x8ce401e4  lw          $a0, 0x1E4($a3)
    ctx->pc = 0x1467c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 484)));
    // 0x1467c8: 0x8ce301f4  lw          $v1, 0x1F4($a3)
    ctx->pc = 0x1467c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 500)));
    // 0x1467cc: 0xace201d8  sw          $v0, 0x1D8($a3)
    ctx->pc = 0x1467ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 472), GPR_U32(ctx, 2));
    // 0x1467d0: 0xace401e8  sw          $a0, 0x1E8($a3)
    ctx->pc = 0x1467d0u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 488), GPR_U32(ctx, 4));
    // 0x1467d4: 0x152e0006  bne         $t1, $t6, . + 4 + (0x6 << 2)
    ctx->pc = 0x1467D4u;
    {
        const bool branch_taken_0x1467d4 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 14));
        ctx->pc = 0x1467D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1467D4u;
            // 0x1467d8: 0xace301f8  sw          $v1, 0x1F8($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 504), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1467d4) {
            ctx->pc = 0x1467F0u;
            goto label_1467f0;
        }
    }
    ctx->pc = 0x1467DCu;
    // 0x1467dc: 0x554c0017  bnel        $t2, $t4, . + 4 + (0x17 << 2)
    ctx->pc = 0x1467DCu;
    {
        const bool branch_taken_0x1467dc = (GPR_U64(ctx, 10) != GPR_U64(ctx, 12));
        if (branch_taken_0x1467dc) {
            ctx->pc = 0x1467E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1467DCu;
            // 0x1467e0: 0x240d0001  addiu       $t5, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14683Cu;
            goto label_14683c;
        }
    }
    ctx->pc = 0x1467E4u;
    // 0x1467e4: 0x8ce201d0  lw          $v0, 0x1D0($a3)
    ctx->pc = 0x1467e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 464)));
    // 0x1467e8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1467E8u;
    {
        const bool branch_taken_0x1467e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1467ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1467E8u;
            // 0x1467ec: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1467e8) {
            ctx->pc = 0x14682Cu;
            goto label_14682c;
        }
    }
    ctx->pc = 0x1467F0u;
label_1467f0:
    // 0x1467f0: 0x39220001  xori        $v0, $t1, 0x1
    ctx->pc = 0x1467f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) ^ (uint64_t)(uint16_t)1);
    // 0x1467f4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1467f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1467f8: 0x82180b  movn        $v1, $a0, $v0
    ctx->pc = 0x1467f8u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x1467fc: 0x154c000e  bne         $t2, $t4, . + 4 + (0xE << 2)
    ctx->pc = 0x1467FCu;
    {
        const bool branch_taken_0x1467fc = (GPR_U64(ctx, 10) != GPR_U64(ctx, 12));
        ctx->pc = 0x146800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1467FCu;
            // 0x146800: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1467fc) {
            ctx->pc = 0x146838u;
            goto label_146838;
        }
    }
    ctx->pc = 0x146804u;
    // 0x146804: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x146804u;
    {
        const bool branch_taken_0x146804 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x146804) {
            ctx->pc = 0x146808u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146804u;
            // 0x146808: 0x8ce201e0  lw          $v0, 0x1E0($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 480)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14681Cu;
            goto label_14681c;
        }
    }
    ctx->pc = 0x14680Cu;
    // 0x14680c: 0x8c420028  lw          $v0, 0x28($v0)
    ctx->pc = 0x14680cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x146810: 0x5046000a  beql        $v0, $a2, . + 4 + (0xA << 2)
    ctx->pc = 0x146810u;
    {
        const bool branch_taken_0x146810 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 6));
        if (branch_taken_0x146810) {
            ctx->pc = 0x146814u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146810u;
            // 0x146814: 0x240d0001  addiu       $t5, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14683Cu;
            goto label_14683c;
        }
    }
    ctx->pc = 0x146818u;
    // 0x146818: 0x8ce201e0  lw          $v0, 0x1E0($a3)
    ctx->pc = 0x146818u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 480)));
label_14681c:
    // 0x14681c: 0x8c440028  lw          $a0, 0x28($v0)
    ctx->pc = 0x14681cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x146820: 0x14860007  bne         $a0, $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x146820u;
    {
        const bool branch_taken_0x146820 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x146824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146820u;
            // 0x146824: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146820) {
            ctx->pc = 0x146840u;
            goto label_146840;
        }
    }
    ctx->pc = 0x146828u;
    // 0x146828: 0x8ce201f0  lw          $v0, 0x1F0($a3)
    ctx->pc = 0x146828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 496)));
label_14682c:
    // 0x14682c: 0x8c430028  lw          $v1, 0x28($v0)
    ctx->pc = 0x14682cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 40)));
    // 0x146830: 0x14640003  bne         $v1, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x146830u;
    {
        const bool branch_taken_0x146830 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x146834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146830u;
            // 0x146834: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146830) {
            ctx->pc = 0x146840u;
            goto label_146840;
        }
    }
    ctx->pc = 0x146838u;
label_146838:
    // 0x146838: 0x240d0001  addiu       $t5, $zero, 0x1
    ctx->pc = 0x146838u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_14683c:
    // 0x14683c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x14683cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_146840:
    // 0x146840: 0x1122000c  beq         $t1, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x146840u;
    {
        const bool branch_taken_0x146840 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 2));
        ctx->pc = 0x146844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146840u;
            // 0x146844: 0x29220003  slti        $v0, $t1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 9) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x146840) {
            ctx->pc = 0x146874u;
            goto label_146874;
        }
    }
    ctx->pc = 0x146848u;
    // 0x146848: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x146848u;
    {
        const bool branch_taken_0x146848 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x14684Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146848u;
            // 0x14684c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146848) {
            ctx->pc = 0x146860u;
            goto label_146860;
        }
    }
    ctx->pc = 0x146850u;
    // 0x146850: 0x51220009  beql        $t1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x146850u;
    {
        const bool branch_taken_0x146850 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 2));
        if (branch_taken_0x146850) {
            ctx->pc = 0x146854u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146850u;
            // 0x146854: 0x8ce801e8  lw          $t0, 0x1E8($a3) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 488)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146878u;
            goto label_146878;
        }
    }
    ctx->pc = 0x146858u;
    // 0x146858: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x146858u;
    {
        const bool branch_taken_0x146858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14685Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146858u;
            // 0x14685c: 0xad000028  sw          $zero, 0x28($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146858) {
            ctx->pc = 0x14687Cu;
            goto label_14687c;
        }
    }
    ctx->pc = 0x146860u;
label_146860:
    // 0x146860: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x146860u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x146864: 0x51220004  beql        $t1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x146864u;
    {
        const bool branch_taken_0x146864 = (GPR_U64(ctx, 9) == GPR_U64(ctx, 2));
        if (branch_taken_0x146864) {
            ctx->pc = 0x146868u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x146864u;
            // 0x146868: 0x8ce801d8  lw          $t0, 0x1D8($a3) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 472)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x146878u;
            goto label_146878;
        }
    }
    ctx->pc = 0x14686Cu;
    // 0x14686c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x14686Cu;
    {
        const bool branch_taken_0x14686c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14686Cu;
            // 0x146870: 0xad000028  sw          $zero, 0x28($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14686c) {
            ctx->pc = 0x14687Cu;
            goto label_14687c;
        }
    }
    ctx->pc = 0x146874u;
label_146874:
    // 0x146874: 0x8ce801f8  lw          $t0, 0x1F8($a3)
    ctx->pc = 0x146874u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 504)));
label_146878:
    // 0x146878: 0xad000028  sw          $zero, 0x28($t0)
    ctx->pc = 0x146878u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 40), GPR_U32(ctx, 0));
label_14687c:
    // 0x14687c: 0x1a0102d  daddu       $v0, $t5, $zero
    ctx->pc = 0x14687cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146880: 0xdce30840  ld          $v1, 0x840($a3)
    ctx->pc = 0x146880u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 7), 2112)));
    // 0x146884: 0x8ce40168  lw          $a0, 0x168($a3)
    ctx->pc = 0x146884u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 360)));
    // 0x146888: 0xfd030018  sd          $v1, 0x18($t0)
    ctx->pc = 0x146888u;
    WRITE64(ADD32(GPR_U32(ctx, 8), 24), GPR_U64(ctx, 3));
    // 0x14688c: 0xad04002c  sw          $a0, 0x2C($t0)
    ctx->pc = 0x14688cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 44), GPR_U32(ctx, 4));
    // 0x146890: 0xdce30848  ld          $v1, 0x848($a3)
    ctx->pc = 0x146890u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 7), 2120)));
    // 0x146894: 0x8ce4018c  lw          $a0, 0x18C($a3)
    ctx->pc = 0x146894u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 396)));
    // 0x146898: 0xfd030020  sd          $v1, 0x20($t0)
    ctx->pc = 0x146898u;
    WRITE64(ADD32(GPR_U32(ctx, 8), 32), GPR_U64(ctx, 3));
    // 0x14689c: 0xad040030  sw          $a0, 0x30($t0)
    ctx->pc = 0x14689cu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 48), GPR_U32(ctx, 4));
    // 0x1468a0: 0x8ce30154  lw          $v1, 0x154($a3)
    ctx->pc = 0x1468a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 340)));
    // 0x1468a4: 0xad030034  sw          $v1, 0x34($t0)
    ctx->pc = 0x1468a4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 52), GPR_U32(ctx, 3));
    // 0x1468a8: 0x8ce401a0  lw          $a0, 0x1A0($a3)
    ctx->pc = 0x1468a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 416)));
    // 0x1468ac: 0xad040038  sw          $a0, 0x38($t0)
    ctx->pc = 0x1468acu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 56), GPR_U32(ctx, 4));
    // 0x1468b0: 0x8ce30190  lw          $v1, 0x190($a3)
    ctx->pc = 0x1468b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 400)));
    // 0x1468b4: 0xad03003c  sw          $v1, 0x3C($t0)
    ctx->pc = 0x1468b4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 60), GPR_U32(ctx, 3));
    // 0x1468b8: 0x8ce4019c  lw          $a0, 0x19C($a3)
    ctx->pc = 0x1468b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 412)));
    // 0x1468bc: 0xad040040  sw          $a0, 0x40($t0)
    ctx->pc = 0x1468bcu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 64), GPR_U32(ctx, 4));
    // 0x1468c0: 0x8ce301a4  lw          $v1, 0x1A4($a3)
    ctx->pc = 0x1468c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 420)));
    // 0x1468c4: 0xad030044  sw          $v1, 0x44($t0)
    ctx->pc = 0x1468c4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 68), GPR_U32(ctx, 3));
    // 0x1468c8: 0x8ce401a8  lw          $a0, 0x1A8($a3)
    ctx->pc = 0x1468c8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 424)));
    // 0x1468cc: 0xad040048  sw          $a0, 0x48($t0)
    ctx->pc = 0x1468ccu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 72), GPR_U32(ctx, 4));
    // 0x1468d0: 0x8ce301ac  lw          $v1, 0x1AC($a3)
    ctx->pc = 0x1468d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 428)));
    // 0x1468d4: 0xad03004c  sw          $v1, 0x4C($t0)
    ctx->pc = 0x1468d4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 76), GPR_U32(ctx, 3));
    // 0x1468d8: 0x8ce401b0  lw          $a0, 0x1B0($a3)
    ctx->pc = 0x1468d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 432)));
    // 0x1468dc: 0xad040050  sw          $a0, 0x50($t0)
    ctx->pc = 0x1468dcu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 80), GPR_U32(ctx, 4));
    // 0x1468e0: 0x8ce301b4  lw          $v1, 0x1B4($a3)
    ctx->pc = 0x1468e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 436)));
    // 0x1468e4: 0xad030054  sw          $v1, 0x54($t0)
    ctx->pc = 0x1468e4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 84), GPR_U32(ctx, 3));
    // 0x1468e8: 0x8ce401b8  lw          $a0, 0x1B8($a3)
    ctx->pc = 0x1468e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 440)));
    // 0x1468ec: 0xad040058  sw          $a0, 0x58($t0)
    ctx->pc = 0x1468ecu;
    WRITE32(ADD32(GPR_U32(ctx, 8), 88), GPR_U32(ctx, 4));
    // 0x1468f0: 0x8ce30160  lw          $v1, 0x160($a3)
    ctx->pc = 0x1468f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 352)));
    // 0x1468f4: 0xad03005c  sw          $v1, 0x5C($t0)
    ctx->pc = 0x1468f4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 92), GPR_U32(ctx, 3));
    // 0x1468f8: 0x8ce40164  lw          $a0, 0x164($a3)
    ctx->pc = 0x1468f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 356)));
    // 0x1468fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1468FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1468FCu;
            // 0x146900: 0xad040060  sw          $a0, 0x60($t0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 8), 96), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1466B4u: goto label_1466b4;
            case 0x1466D0u: goto label_1466d0;
            case 0x1466F8u: goto label_1466f8;
            case 0x14672Cu: goto label_14672c;
            case 0x146754u: goto label_146754;
            case 0x146760u: goto label_146760;
            case 0x146774u: goto label_146774;
            case 0x146788u: goto label_146788;
            case 0x1467C4u: goto label_1467c4;
            case 0x1467F0u: goto label_1467f0;
            case 0x14681Cu: goto label_14681c;
            case 0x14682Cu: goto label_14682c;
            case 0x146838u: goto label_146838;
            case 0x14683Cu: goto label_14683c;
            case 0x146840u: goto label_146840;
            case 0x146860u: goto label_146860;
            case 0x146874u: goto label_146874;
            case 0x146878u: goto label_146878;
            case 0x14687Cu: goto label_14687c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146904u;
    // 0x146904: 0x0  nop
    ctx->pc = 0x146904u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
