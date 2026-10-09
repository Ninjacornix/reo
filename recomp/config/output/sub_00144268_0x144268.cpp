#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00144268
// Address: 0x144268 - 0x1443f0
void sub_00144268_0x144268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00144268_0x144268");
#endif

    switch (ctx->pc) {
        case 0x1442fcu: goto label_1442fc;
        case 0x144300u: goto label_144300;
        default: break;
    }

    ctx->pc = 0x144268u;

    // 0x144268: 0x8c83018c  lw          $v1, 0x18C($a0)
    ctx->pc = 0x144268u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 396)));
    // 0x14426c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x14426cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x144270: 0x14620045  bne         $v1, $v0, . + 4 + (0x45 << 2)
    ctx->pc = 0x144270u;
    {
        const bool branch_taken_0x144270 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x144270) {
            ctx->pc = 0x144388u;
            goto label_144388;
        }
    }
    ctx->pc = 0x144278u;
    // 0x144278: 0x8c820190  lw          $v0, 0x190($a0)
    ctx->pc = 0x144278u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 400)));
    // 0x14427c: 0x50400024  beql        $v0, $zero, . + 4 + (0x24 << 2)
    ctx->pc = 0x14427Cu;
    {
        const bool branch_taken_0x14427c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x14427c) {
            ctx->pc = 0x144280u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x14427Cu;
            // 0x144280: 0x71040  sll         $v0, $a3, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x144310u;
            goto label_144310;
        }
    }
    ctx->pc = 0x144284u;
    // 0x144284: 0x18e00004  blez        $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x144284u;
    {
        const bool branch_taken_0x144284 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x144288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144284u;
            // 0x144288: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144284) {
            ctx->pc = 0x144298u;
            goto label_144298;
        }
    }
    ctx->pc = 0x14428Cu;
    // 0x14428c: 0x24e20001  addiu       $v0, $a3, 0x1
    ctx->pc = 0x14428cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x144290: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x144290u;
    {
        const bool branch_taken_0x144290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144290u;
            // 0x144294: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144290) {
            ctx->pc = 0x14429Cu;
            goto label_14429c;
        }
    }
    ctx->pc = 0x144298u;
label_144298:
    // 0x144298: 0x71043  sra         $v0, $a3, 1
    ctx->pc = 0x144298u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), 1));
label_14429c:
    // 0x14429c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14429cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1442a0: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1442a0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1442a4: 0x19000004  blez        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1442A4u;
    {
        const bool branch_taken_0x1442a4 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x1442A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1442A4u;
            // 0x1442a8: 0x8cc30004  lw          $v1, 0x4($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1442a4) {
            ctx->pc = 0x1442B8u;
            goto label_1442b8;
        }
    }
    ctx->pc = 0x1442ACu;
    // 0x1442ac: 0x25020001  addiu       $v0, $t0, 0x1
    ctx->pc = 0x1442acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1442b0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1442B0u;
    {
        const bool branch_taken_0x1442b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1442B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1442B0u;
            // 0x1442b4: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1442b0) {
            ctx->pc = 0x1442BCu;
            goto label_1442bc;
        }
    }
    ctx->pc = 0x1442B8u;
label_1442b8:
    // 0x1442b8: 0x81043  sra         $v0, $t0, 1
    ctx->pc = 0x1442b8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 8), 1));
label_1442bc:
    // 0x1442bc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1442bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1442c0: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1442c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1442c4: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1442c4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1442c8: 0x71040  sll         $v0, $a3, 1
    ctx->pc = 0x1442c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x1442cc: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x1442ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1442d0: 0x18e00002  blez        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1442D0u;
    {
        const bool branch_taken_0x1442d0 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x1442D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1442D0u;
            // 0x1442d4: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1442d0) {
            ctx->pc = 0x1442DCu;
            goto label_1442dc;
        }
    }
    ctx->pc = 0x1442D8u;
    // 0x1442d8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1442d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1442dc:
    // 0x1442dc: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1442dcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1442e0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1442e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1442e4: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x1442e4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x1442e8: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x1442e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1442ec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1442ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1442f0: 0x19000002  blez        $t0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1442F0u;
    {
        const bool branch_taken_0x1442f0 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x1442F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1442F0u;
            // 0x1442f4: 0x8cc60004  lw          $a2, 0x4($a2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1442f0) {
            ctx->pc = 0x1442FCu;
            goto label_1442fc;
        }
    }
    ctx->pc = 0x1442F8u;
    // 0x1442f8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1442f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1442fc:
    // 0x1442fc: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1442fcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_144300:
    // 0x144300: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x144300u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x144304: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x144304u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x144308: 0x3e00008  jr          $ra
    ctx->pc = 0x144308u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14430Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144308u;
            // 0x14430c: 0xaca2000c  sw          $v0, 0xC($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144298u: goto label_144298;
            case 0x14429Cu: goto label_14429c;
            case 0x1442B8u: goto label_1442b8;
            case 0x1442BCu: goto label_1442bc;
            case 0x1442DCu: goto label_1442dc;
            case 0x1442FCu: goto label_1442fc;
            case 0x144300u: goto label_144300;
            case 0x144310u: goto label_144310;
            case 0x144320u: goto label_144320;
            case 0x144340u: goto label_144340;
            case 0x144364u: goto label_144364;
            case 0x144368u: goto label_144368;
            case 0x144380u: goto label_144380;
            case 0x144388u: goto label_144388;
            case 0x14439Cu: goto label_14439c;
            case 0x1443A0u: goto label_1443a0;
            case 0x1443BCu: goto label_1443bc;
            case 0x1443C0u: goto label_1443c0;
            case 0x1443E4u: goto label_1443e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144310u;
label_144310:
    // 0x144310: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x144310u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x144314: 0x18e00002  blez        $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x144314u;
    {
        const bool branch_taken_0x144314 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x144318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144314u;
            // 0x144318: 0x471021  addu        $v0, $v0, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144314) {
            ctx->pc = 0x144320u;
            goto label_144320;
        }
    }
    ctx->pc = 0x14431Cu;
    // 0x14431c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x14431cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_144320:
    // 0x144320: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x144320u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x144324: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x144324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x144328: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x144328u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x14432c: 0x81040  sll         $v0, $t0, 1
    ctx->pc = 0x14432cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x144330: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x144330u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x144334: 0x19000002  blez        $t0, . + 4 + (0x2 << 2)
    ctx->pc = 0x144334u;
    {
        const bool branch_taken_0x144334 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x144338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144334u;
            // 0x144338: 0x8cc30004  lw          $v1, 0x4($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144334) {
            ctx->pc = 0x144340u;
            goto label_144340;
        }
    }
    ctx->pc = 0x14433Cu;
    // 0x14433c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x14433cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_144340:
    // 0x144340: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x144340u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x144344: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x144344u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x144348: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x144348u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x14434c: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x14434cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x144350: 0x18e00004  blez        $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x144350u;
    {
        const bool branch_taken_0x144350 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x144354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144350u;
            // 0x144354: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144350) {
            ctx->pc = 0x144364u;
            goto label_144364;
        }
    }
    ctx->pc = 0x144358u;
    // 0x144358: 0x24e20001  addiu       $v0, $a3, 0x1
    ctx->pc = 0x144358u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x14435c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x14435Cu;
    {
        const bool branch_taken_0x14435c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14435Cu;
            // 0x144360: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14435c) {
            ctx->pc = 0x144368u;
            goto label_144368;
        }
    }
    ctx->pc = 0x144364u;
label_144364:
    // 0x144364: 0x71043  sra         $v0, $a3, 1
    ctx->pc = 0x144364u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), 1));
label_144368:
    // 0x144368: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x144368u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x14436c: 0xaca20008  sw          $v0, 0x8($a1)
    ctx->pc = 0x14436cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 2));
    // 0x144370: 0x19000003  blez        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x144370u;
    {
        const bool branch_taken_0x144370 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x144374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144370u;
            // 0x144374: 0x8cc60004  lw          $a2, 0x4($a2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144370) {
            ctx->pc = 0x144380u;
            goto label_144380;
        }
    }
    ctx->pc = 0x144378u;
    // 0x144378: 0x1000ffe0  b           . + 4 + (-0x20 << 2)
    ctx->pc = 0x144378u;
    {
        const bool branch_taken_0x144378 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14437Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144378u;
            // 0x14437c: 0x25020001  addiu       $v0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144378) {
            ctx->pc = 0x1442FCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1442fc;
        }
    }
    ctx->pc = 0x144380u;
label_144380:
    // 0x144380: 0x1000ffdf  b           . + 4 + (-0x21 << 2)
    ctx->pc = 0x144380u;
    {
        const bool branch_taken_0x144380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144380u;
            // 0x144384: 0x81043  sra         $v0, $t0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144380) {
            ctx->pc = 0x144300u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_144300;
        }
    }
    ctx->pc = 0x144388u;
label_144388:
    // 0x144388: 0x18e00004  blez        $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x144388u;
    {
        const bool branch_taken_0x144388 = (GPR_S64(ctx, 7) <= 0);
        ctx->pc = 0x14438Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144388u;
            // 0x14438c: 0x8cc30000  lw          $v1, 0x0($a2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144388) {
            ctx->pc = 0x14439Cu;
            goto label_14439c;
        }
    }
    ctx->pc = 0x144390u;
    // 0x144390: 0x24e20001  addiu       $v0, $a3, 0x1
    ctx->pc = 0x144390u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x144394: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x144394u;
    {
        const bool branch_taken_0x144394 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144398u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144394u;
            // 0x144398: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144394) {
            ctx->pc = 0x1443A0u;
            goto label_1443a0;
        }
    }
    ctx->pc = 0x14439Cu;
label_14439c:
    // 0x14439c: 0x71043  sra         $v0, $a3, 1
    ctx->pc = 0x14439cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 7), 1));
label_1443a0:
    // 0x1443a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1443a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1443a4: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1443a4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1443a8: 0x19000004  blez        $t0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1443A8u;
    {
        const bool branch_taken_0x1443a8 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x1443ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1443A8u;
            // 0x1443ac: 0x8cc60004  lw          $a2, 0x4($a2) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1443a8) {
            ctx->pc = 0x1443BCu;
            goto label_1443bc;
        }
    }
    ctx->pc = 0x1443B0u;
    // 0x1443b0: 0x25020001  addiu       $v0, $t0, 0x1
    ctx->pc = 0x1443b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1443b4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1443B4u;
    {
        const bool branch_taken_0x1443b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1443B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1443B4u;
            // 0x1443b8: 0x21043  sra         $v0, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1443b4) {
            ctx->pc = 0x1443C0u;
            goto label_1443c0;
        }
    }
    ctx->pc = 0x1443BCu;
label_1443bc:
    // 0x1443bc: 0x81043  sra         $v0, $t0, 1
    ctx->pc = 0x1443bcu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 8), 1));
label_1443c0:
    // 0x1443c0: 0x463021  addu        $a2, $v0, $a2
    ctx->pc = 0x1443c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1443c4: 0xaca60004  sw          $a2, 0x4($a1)
    ctx->pc = 0x1443c4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 6));
    // 0x1443c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1443c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1443cc: 0x8c82018c  lw          $v0, 0x18C($a0)
    ctx->pc = 0x1443ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 396)));
    // 0x1443d0: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1443D0u;
    {
        const bool branch_taken_0x1443d0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1443D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1443D0u;
            // 0x1443d4: 0x24c20001  addiu       $v0, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1443d0) {
            ctx->pc = 0x1443E4u;
            goto label_1443e4;
        }
    }
    ctx->pc = 0x1443D8u;
    // 0x1443d8: 0x24c2ffff  addiu       $v0, $a2, -0x1
    ctx->pc = 0x1443d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1443dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1443DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1443E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1443DCu;
            // 0x1443e0: 0xaca20004  sw          $v0, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144298u: goto label_144298;
            case 0x14429Cu: goto label_14429c;
            case 0x1442B8u: goto label_1442b8;
            case 0x1442BCu: goto label_1442bc;
            case 0x1442DCu: goto label_1442dc;
            case 0x1442FCu: goto label_1442fc;
            case 0x144300u: goto label_144300;
            case 0x144310u: goto label_144310;
            case 0x144320u: goto label_144320;
            case 0x144340u: goto label_144340;
            case 0x144364u: goto label_144364;
            case 0x144368u: goto label_144368;
            case 0x144380u: goto label_144380;
            case 0x144388u: goto label_144388;
            case 0x14439Cu: goto label_14439c;
            case 0x1443A0u: goto label_1443a0;
            case 0x1443BCu: goto label_1443bc;
            case 0x1443C0u: goto label_1443c0;
            case 0x1443E4u: goto label_1443e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1443E4u;
label_1443e4:
    // 0x1443e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1443E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1443E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1443E4u;
            // 0x1443e8: 0xaca20004  sw          $v0, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144298u: goto label_144298;
            case 0x14429Cu: goto label_14429c;
            case 0x1442B8u: goto label_1442b8;
            case 0x1442BCu: goto label_1442bc;
            case 0x1442DCu: goto label_1442dc;
            case 0x1442FCu: goto label_1442fc;
            case 0x144300u: goto label_144300;
            case 0x144310u: goto label_144310;
            case 0x144320u: goto label_144320;
            case 0x144340u: goto label_144340;
            case 0x144364u: goto label_144364;
            case 0x144368u: goto label_144368;
            case 0x144380u: goto label_144380;
            case 0x144388u: goto label_144388;
            case 0x14439Cu: goto label_14439c;
            case 0x1443A0u: goto label_1443a0;
            case 0x1443BCu: goto label_1443bc;
            case 0x1443C0u: goto label_1443c0;
            case 0x1443E4u: goto label_1443e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1443ECu;
    // 0x1443ec: 0x0  nop
    ctx->pc = 0x1443ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
