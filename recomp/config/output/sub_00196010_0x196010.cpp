#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00196010
// Address: 0x196010 - 0x197470
void sub_00196010_0x196010(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00196010_0x196010");
#endif

    switch (ctx->pc) {
        case 0x196060u: goto label_196060;
        case 0x1960ccu: goto label_1960cc;
        case 0x196130u: goto label_196130;
        case 0x196158u: goto label_196158;
        case 0x196554u: goto label_196554;
        case 0x19655cu: goto label_19655c;
        case 0x196604u: goto label_196604;
        case 0x196650u: goto label_196650;
        case 0x1966a4u: goto label_1966a4;
        case 0x196838u: goto label_196838;
        case 0x1968a4u: goto label_1968a4;
        case 0x1968f8u: goto label_1968f8;
        case 0x196930u: goto label_196930;
        case 0x196968u: goto label_196968;
        case 0x196984u: goto label_196984;
        case 0x1969b0u: goto label_1969b0;
        case 0x1969c8u: goto label_1969c8;
        case 0x196af4u: goto label_196af4;
        case 0x196b24u: goto label_196b24;
        case 0x196ba8u: goto label_196ba8;
        case 0x196e3cu: goto label_196e3c;
        case 0x196ee0u: goto label_196ee0;
        case 0x1971b0u: goto label_1971b0;
        default: break;
    }

    ctx->pc = 0x196010u;

    // 0x196010: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x196010u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x196014: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x196014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x196018: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x196018u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19601c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19601cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x196020: 0x309000ff  andi        $s0, $a0, 0xFF
    ctx->pc = 0x196020u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x196024: 0x2a02001a  slti        $v0, $s0, 0x1A
    ctx->pc = 0x196024u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)26) ? 1 : 0);
    // 0x196028: 0x14400018  bnez        $v0, . + 4 + (0x18 << 2)
    ctx->pc = 0x196028u;
    {
        const bool branch_taken_0x196028 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x19602Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196028u;
            // 0x19602c: 0xafa50038  sw          $a1, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196028) {
            ctx->pc = 0x19608Cu;
            goto label_19608c;
        }
    }
    ctx->pc = 0x196030u;
    // 0x196030: 0x2a01003a  slti        $at, $s0, 0x3A
    ctx->pc = 0x196030u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)58) ? 1 : 0);
    // 0x196034: 0x10200016  beqz        $at, . + 4 + (0x16 << 2)
    ctx->pc = 0x196034u;
    {
        const bool branch_taken_0x196034 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x196038u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196034u;
            // 0x196038: 0x2a02003a  slti        $v0, $s0, 0x3A (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)58) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x196034) {
            ctx->pc = 0x196090u;
            goto label_196090;
        }
    }
    ctx->pc = 0x19603Cu;
    // 0x19603c: 0x8fa60038  lw          $a2, 0x38($sp)
    ctx->pc = 0x19603cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196040: 0x10c00010  beqz        $a2, . + 4 + (0x10 << 2)
    ctx->pc = 0x196040u;
    {
        const bool branch_taken_0x196040 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x196044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196040u;
            // 0x196044: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196040) {
            ctx->pc = 0x196084u;
            goto label_196084;
        }
    }
    ctx->pc = 0x196048u;
    // 0x196048: 0x2602ffe6  addiu       $v0, $s0, -0x1A
    ctx->pc = 0x196048u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967270));
    // 0x19604c: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x19604cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x196050: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x196050u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x196054: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x196054u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x196058: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x196058u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x19605c: 0x412821  addu        $a1, $v0, $at
    ctx->pc = 0x19605cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
label_196060:
    // 0x196060: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x196060u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x196064: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x196064u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x196068: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x196068u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19606c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x19606cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x196070: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x196070u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x196074: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x196074u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x196078: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x196078u;
    {
        const bool branch_taken_0x196078 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x19607Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196078u;
            // 0x19607c: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196078) {
            ctx->pc = 0x196060u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_196060;
        }
    }
    ctx->pc = 0x196080u;
    // 0x196080: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196080u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_196084:
    // 0x196084: 0x10000398  b           . + 4 + (0x398 << 2)
    ctx->pc = 0x196084u;
    {
        const bool branch_taken_0x196084 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196088u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196084u;
            // 0x196088: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196084) {
            ctx->pc = 0x196EE8u;
            goto label_196ee8;
        }
    }
    ctx->pc = 0x19608Cu;
label_19608c:
    // 0x19608c: 0x2a02003a  slti        $v0, $s0, 0x3A
    ctx->pc = 0x19608cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)58) ? 1 : 0);
label_196090:
    // 0x196090: 0x14400017  bnez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x196090u;
    {
        const bool branch_taken_0x196090 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x196094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196090u;
            // 0x196094: 0x2a02005a  slti        $v0, $s0, 0x5A (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)90) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x196090) {
            ctx->pc = 0x1960F0u;
            goto label_1960f0;
        }
    }
    ctx->pc = 0x196098u;
    // 0x196098: 0x2a01005a  slti        $at, $s0, 0x5A
    ctx->pc = 0x196098u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)90) ? 1 : 0);
    // 0x19609c: 0x10200014  beqz        $at, . + 4 + (0x14 << 2)
    ctx->pc = 0x19609Cu;
    {
        const bool branch_taken_0x19609c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1960A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19609Cu;
            // 0x1960a0: 0x2606ffc6  addiu       $a2, $s0, -0x3A (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967238));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19609c) {
            ctx->pc = 0x1960F0u;
            goto label_1960f0;
        }
    }
    ctx->pc = 0x1960A4u;
    // 0x1960a4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1960a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1960a8: 0x618c0  sll         $v1, $a2, 3
    ctx->pc = 0x1960a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x1960ac: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x1960acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1960b0: 0x662821  addu        $a1, $v1, $a2
    ctx->pc = 0x1960b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1960b4: 0x24424340  addiu       $v0, $v0, 0x4340
    ctx->pc = 0x1960b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17216));
    // 0x1960b8: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1960b8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1960bc: 0x24030013  addiu       $v1, $zero, 0x13
    ctx->pc = 0x1960bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x1960c0: 0xa62821  addu        $a1, $a1, $a2
    ctx->pc = 0x1960c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x1960c4: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x1960c4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1960c8: 0x452821  addu        $a1, $v0, $a1
    ctx->pc = 0x1960c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_1960cc:
    // 0x1960cc: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x1960ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1960d0: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1960d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1960d4: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x1960d4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1960d8: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x1960d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x1960dc: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x1960dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x1960e0: 0x1c60fffa  bgtz        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1960E0u;
    {
        const bool branch_taken_0x1960e0 = (GPR_S64(ctx, 3) > 0);
        if (branch_taken_0x1960e0) {
            ctx->pc = 0x1960CCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1960cc;
        }
    }
    ctx->pc = 0x1960E8u;
    // 0x1960e8: 0x1000037e  b           . + 4 + (0x37E << 2)
    ctx->pc = 0x1960E8u;
    {
        const bool branch_taken_0x1960e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1960ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1960E8u;
            // 0x1960ec: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1960e8) {
            ctx->pc = 0x196EE4u;
            goto label_196ee4;
        }
    }
    ctx->pc = 0x1960F0u;
label_1960f0:
    // 0x1960f0: 0x14400031  bnez        $v0, . + 4 + (0x31 << 2)
    ctx->pc = 0x1960F0u;
    {
        const bool branch_taken_0x1960f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1960F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1960F0u;
            // 0x1960f4: 0x2a01005d  slti        $at, $s0, 0x5D (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)93) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1960f0) {
            ctx->pc = 0x1961B8u;
            goto label_1961b8;
        }
    }
    ctx->pc = 0x1960F8u;
    // 0x1960f8: 0x10200030  beqz        $at, . + 4 + (0x30 << 2)
    ctx->pc = 0x1960F8u;
    {
        const bool branch_taken_0x1960f8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1960FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1960F8u;
            // 0x1960fc: 0x2402006d  addiu       $v0, $zero, 0x6D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1960f8) {
            ctx->pc = 0x1961BCu;
            goto label_1961bc;
        }
    }
    ctx->pc = 0x196100u;
    // 0x196100: 0x2611ffa6  addiu       $s1, $s0, -0x5A
    ctx->pc = 0x196100u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967206));
    // 0x196104: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x196104u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x196108: 0x111840  sll         $v1, $s1, 1
    ctx->pc = 0x196108u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
    // 0x19610c: 0x8fa60038  lw          $a2, 0x38($sp)
    ctx->pc = 0x19610cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196110: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x196110u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x196114: 0x24424200  addiu       $v0, $v0, 0x4200
    ctx->pc = 0x196114u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16896));
    // 0x196118: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x196118u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x19611c: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x19611cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x196120: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x196120u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x196124: 0x380c0  sll         $s0, $v1, 3
    ctx->pc = 0x196124u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x196128: 0x503821  addu        $a3, $v0, $s0
    ctx->pc = 0x196128u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x19612c: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x19612cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_196130:
    // 0x196130: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x196130u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x196134: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x196134u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x196138: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x196138u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19613c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x19613cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x196140: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x196140u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x196144: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x196144u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x196148: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x196148u;
    {
        const bool branch_taken_0x196148 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x19614Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196148u;
            // 0x19614c: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196148) {
            ctx->pc = 0x196130u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_196130;
        }
    }
    ctx->pc = 0x196150u;
    // 0x196150: 0xc064760  jal         func_191D80
    ctx->pc = 0x196150u;
    SET_GPR_U32(ctx, 31, 0x196158u);
    ctx->pc = 0x196154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196150u;
            // 0x196154: 0x24e40034  addiu       $a0, $a3, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 52));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191D80u;
    if (runtime->hasFunction(0x191D80u)) {
        auto targetFn = runtime->lookupFunction(0x191D80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196158u; }
        if (ctx->pc != 0x196158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191D80_0x191d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196158u; }
        if (ctx->pc != 0x196158u) { return; }
    }
    ctx->pc = 0x196158u;
label_196158:
    // 0x196158: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x196158u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x19615c: 0x112080  sll         $a0, $s1, 2
    ctx->pc = 0x19615cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x196160: 0x24424210  addiu       $v0, $v0, 0x4210
    ctx->pc = 0x196160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16912));
    // 0x196164: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x196164u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x196168: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x196168u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x19616c: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x19616cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x196170: 0x24424220  addiu       $v0, $v0, 0x4220
    ctx->pc = 0x196170u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16928));
    // 0x196174: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x196174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x196178: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x196178u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x19617c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x19617cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x196180: 0x24424250  addiu       $v0, $v0, 0x4250
    ctx->pc = 0x196180u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16976));
    // 0x196184: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x196184u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x196188: 0xc4600000  lwc1        $f0, 0x0($v1)
    ctx->pc = 0x196188u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19618c: 0x3c023f80  lui         $v0, 0x3F80
    ctx->pc = 0x19618cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16256 << 16));
    // 0x196190: 0x44820800  mtc1        $v0, $f1
    ctx->pc = 0x196190u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x196194: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196194u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x196198: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196198u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x19619c: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x19619cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x1961a0: 0x246341e8  addiu       $v1, $v1, 0x41E8
    ctx->pc = 0x1961a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 16872));
    // 0x1961a4: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1961a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1961a8: 0x0  nop
    ctx->pc = 0x1961a8u;
    // NOP
    // 0x1961ac: 0x0  nop
    ctx->pc = 0x1961acu;
    // NOP
    // 0x1961b0: 0x1000034c  b           . + 4 + (0x34C << 2)
    ctx->pc = 0x1961B0u;
    {
        const bool branch_taken_0x1961b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1961B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1961B0u;
            // 0x1961b4: 0xe4600000  swc1        $f0, 0x0($v1) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 3), 0), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1961b0) {
            ctx->pc = 0x196EE4u;
            goto label_196ee4;
        }
    }
    ctx->pc = 0x1961B8u;
label_1961b8:
    // 0x1961b8: 0x2402006d  addiu       $v0, $zero, 0x6D
    ctx->pc = 0x1961b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
label_1961bc:
    // 0x1961bc: 0x12020321  beq         $s0, $v0, . + 4 + (0x321 << 2)
    ctx->pc = 0x1961BCu;
    {
        const bool branch_taken_0x1961bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1961C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1961BCu;
            // 0x1961c0: 0x2402006c  addiu       $v0, $zero, 0x6C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1961bc) {
            ctx->pc = 0x196E44u;
            goto label_196e44;
        }
    }
    ctx->pc = 0x1961C4u;
    // 0x1961c4: 0x12020303  beq         $s0, $v0, . + 4 + (0x303 << 2)
    ctx->pc = 0x1961C4u;
    {
        const bool branch_taken_0x1961c4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1961c4) {
            ctx->pc = 0x196DD4u;
            goto label_196dd4;
        }
    }
    ctx->pc = 0x1961CCu;
    // 0x1961cc: 0x2402006b  addiu       $v0, $zero, 0x6B
    ctx->pc = 0x1961ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x1961d0: 0x120202f0  beq         $s0, $v0, . + 4 + (0x2F0 << 2)
    ctx->pc = 0x1961D0u;
    {
        const bool branch_taken_0x1961d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1961D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1961D0u;
            // 0x1961d4: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1961d0) {
            ctx->pc = 0x196D94u;
            goto label_196d94;
        }
    }
    ctx->pc = 0x1961D8u;
    // 0x1961d8: 0x2402006a  addiu       $v0, $zero, 0x6A
    ctx->pc = 0x1961d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 106));
    // 0x1961dc: 0x120202e9  beq         $s0, $v0, . + 4 + (0x2E9 << 2)
    ctx->pc = 0x1961DCu;
    {
        const bool branch_taken_0x1961dc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1961E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1961DCu;
            // 0x1961e0: 0x24020069  addiu       $v0, $zero, 0x69 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 105));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1961dc) {
            ctx->pc = 0x196D84u;
            goto label_196d84;
        }
    }
    ctx->pc = 0x1961E4u;
    // 0x1961e4: 0x120202e3  beq         $s0, $v0, . + 4 + (0x2E3 << 2)
    ctx->pc = 0x1961E4u;
    {
        const bool branch_taken_0x1961e4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x1961e4) {
            ctx->pc = 0x196D74u;
            goto label_196d74;
        }
    }
    ctx->pc = 0x1961ECu;
    // 0x1961ec: 0x24020068  addiu       $v0, $zero, 0x68
    ctx->pc = 0x1961ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x1961f0: 0x1202033c  beq         $s0, $v0, . + 4 + (0x33C << 2)
    ctx->pc = 0x1961F0u;
    {
        const bool branch_taken_0x1961f0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x1961F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1961F0u;
            // 0x1961f4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1961f0) {
            ctx->pc = 0x196EE4u;
            goto label_196ee4;
        }
    }
    ctx->pc = 0x1961F8u;
    // 0x1961f8: 0x24020067  addiu       $v0, $zero, 0x67
    ctx->pc = 0x1961f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 103));
    // 0x1961fc: 0x1202028c  beq         $s0, $v0, . + 4 + (0x28C << 2)
    ctx->pc = 0x1961FCu;
    {
        const bool branch_taken_0x1961fc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1961FCu;
            // 0x196200: 0x24020066  addiu       $v0, $zero, 0x66 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1961fc) {
            ctx->pc = 0x196C30u;
            goto label_196c30;
        }
    }
    ctx->pc = 0x196204u;
    // 0x196204: 0x1202027a  beq         $s0, $v0, . + 4 + (0x27A << 2)
    ctx->pc = 0x196204u;
    {
        const bool branch_taken_0x196204 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196204u;
            // 0x196208: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196204) {
            ctx->pc = 0x196BF0u;
            goto label_196bf0;
        }
    }
    ctx->pc = 0x19620Cu;
    // 0x19620c: 0x24020065  addiu       $v0, $zero, 0x65
    ctx->pc = 0x19620cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x196210: 0x12020333  beq         $s0, $v0, . + 4 + (0x333 << 2)
    ctx->pc = 0x196210u;
    {
        const bool branch_taken_0x196210 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196210u;
            // 0x196214: 0x24020064  addiu       $v0, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196210) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196218u;
    // 0x196218: 0x12020265  beq         $s0, $v0, . + 4 + (0x265 << 2)
    ctx->pc = 0x196218u;
    {
        const bool branch_taken_0x196218 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x19621Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196218u;
            // 0x19621c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196218) {
            ctx->pc = 0x196BB0u;
            goto label_196bb0;
        }
    }
    ctx->pc = 0x196220u;
    // 0x196220: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x196220u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x196224: 0x1202024e  beq         $s0, $v0, . + 4 + (0x24E << 2)
    ctx->pc = 0x196224u;
    {
        const bool branch_taken_0x196224 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196228u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196224u;
            // 0x196228: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196224) {
            ctx->pc = 0x196B60u;
            goto label_196b60;
        }
    }
    ctx->pc = 0x19622Cu;
    // 0x19622c: 0x24020062  addiu       $v0, $zero, 0x62
    ctx->pc = 0x19622cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x196230: 0x1202023e  beq         $s0, $v0, . + 4 + (0x23E << 2)
    ctx->pc = 0x196230u;
    {
        const bool branch_taken_0x196230 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196230u;
            // 0x196234: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196230) {
            ctx->pc = 0x196B2Cu;
            goto label_196b2c;
        }
    }
    ctx->pc = 0x196238u;
    // 0x196238: 0x24020060  addiu       $v0, $zero, 0x60
    ctx->pc = 0x196238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x19623c: 0x1202022f  beq         $s0, $v0, . + 4 + (0x22F << 2)
    ctx->pc = 0x19623Cu;
    {
        const bool branch_taken_0x19623c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19623Cu;
            // 0x196240: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19623c) {
            ctx->pc = 0x196AFCu;
            goto label_196afc;
        }
    }
    ctx->pc = 0x196244u;
    // 0x196244: 0x2402005f  addiu       $v0, $zero, 0x5F
    ctx->pc = 0x196244u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x196248: 0x120201f5  beq         $s0, $v0, . + 4 + (0x1F5 << 2)
    ctx->pc = 0x196248u;
    {
        const bool branch_taken_0x196248 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x19624Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196248u;
            // 0x19624c: 0x2402005d  addiu       $v0, $zero, 0x5D (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196248) {
            ctx->pc = 0x196A20u;
            goto label_196a20;
        }
    }
    ctx->pc = 0x196250u;
    // 0x196250: 0x120201e7  beq         $s0, $v0, . + 4 + (0x1E7 << 2)
    ctx->pc = 0x196250u;
    {
        const bool branch_taken_0x196250 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196254u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196250u;
            // 0x196254: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196250) {
            ctx->pc = 0x1969F0u;
            goto label_1969f0;
        }
    }
    ctx->pc = 0x196258u;
    // 0x196258: 0x24020019  addiu       $v0, $zero, 0x19
    ctx->pc = 0x196258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 25));
    // 0x19625c: 0x120201d6  beq         $s0, $v0, . + 4 + (0x1D6 << 2)
    ctx->pc = 0x19625Cu;
    {
        const bool branch_taken_0x19625c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19625Cu;
            // 0x196260: 0x24030018  addiu       $v1, $zero, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19625c) {
            ctx->pc = 0x1969B8u;
            goto label_1969b8;
        }
    }
    ctx->pc = 0x196264u;
    // 0x196264: 0x120301c9  beq         $s0, $v1, . + 4 + (0x1C9 << 2)
    ctx->pc = 0x196264u;
    {
        const bool branch_taken_0x196264 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x196268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196264u;
            // 0x196268: 0x24020017  addiu       $v0, $zero, 0x17 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196264) {
            ctx->pc = 0x19698Cu;
            goto label_19698c;
        }
    }
    ctx->pc = 0x19626Cu;
    // 0x19626c: 0x120201ac  beq         $s0, $v0, . + 4 + (0x1AC << 2)
    ctx->pc = 0x19626Cu;
    {
        const bool branch_taken_0x19626c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x19626c) {
            ctx->pc = 0x196920u;
            goto label_196920;
        }
    }
    ctx->pc = 0x196274u;
    // 0x196274: 0x24020016  addiu       $v0, $zero, 0x16
    ctx->pc = 0x196274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x196278: 0x1202019b  beq         $s0, $v0, . + 4 + (0x19B << 2)
    ctx->pc = 0x196278u;
    {
        const bool branch_taken_0x196278 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x19627Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196278u;
            // 0x19627c: 0x24020015  addiu       $v0, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196278) {
            ctx->pc = 0x1968E8u;
            goto label_1968e8;
        }
    }
    ctx->pc = 0x196280u;
    // 0x196280: 0x1202018a  beq         $s0, $v0, . + 4 + (0x18A << 2)
    ctx->pc = 0x196280u;
    {
        const bool branch_taken_0x196280 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196284u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196280u;
            // 0x196284: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196280) {
            ctx->pc = 0x1968ACu;
            goto label_1968ac;
        }
    }
    ctx->pc = 0x196288u;
    // 0x196288: 0x24020014  addiu       $v0, $zero, 0x14
    ctx->pc = 0x196288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x19628c: 0x12020183  beq         $s0, $v0, . + 4 + (0x183 << 2)
    ctx->pc = 0x19628Cu;
    {
        const bool branch_taken_0x19628c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19628Cu;
            // 0x196290: 0x24040013  addiu       $a0, $zero, 0x13 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19628c) {
            ctx->pc = 0x19689Cu;
            goto label_19689c;
        }
    }
    ctx->pc = 0x196294u;
    // 0x196294: 0x12040312  beq         $s0, $a0, . + 4 + (0x312 << 2)
    ctx->pc = 0x196294u;
    {
        const bool branch_taken_0x196294 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        if (branch_taken_0x196294) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19629Cu;
    // 0x19629c: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x19629cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x1962a0: 0x1204016f  beq         $s0, $a0, . + 4 + (0x16F << 2)
    ctx->pc = 0x1962A0u;
    {
        const bool branch_taken_0x1962a0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962A0u;
            // 0x1962a4: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962a0) {
            ctx->pc = 0x196860u;
            goto label_196860;
        }
    }
    ctx->pc = 0x1962A8u;
    // 0x1962a8: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x1962a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x1962ac: 0x12040168  beq         $s0, $a0, . + 4 + (0x168 << 2)
    ctx->pc = 0x1962ACu;
    {
        const bool branch_taken_0x1962ac = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962ACu;
            // 0x1962b0: 0x24090010  addiu       $t1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962ac) {
            ctx->pc = 0x196850u;
            goto label_196850;
        }
    }
    ctx->pc = 0x1962B4u;
    // 0x1962b4: 0x12090162  beq         $s0, $t1, . + 4 + (0x162 << 2)
    ctx->pc = 0x1962B4u;
    {
        const bool branch_taken_0x1962b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 9));
        ctx->pc = 0x1962B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962B4u;
            // 0x1962b8: 0x2404000f  addiu       $a0, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962b4) {
            ctx->pc = 0x196840u;
            goto label_196840;
        }
    }
    ctx->pc = 0x1962BCu;
    // 0x1962bc: 0x12040157  beq         $s0, $a0, . + 4 + (0x157 << 2)
    ctx->pc = 0x1962BCu;
    {
        const bool branch_taken_0x1962bc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962BCu;
            // 0x1962c0: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962bc) {
            ctx->pc = 0x19681Cu;
            goto label_19681c;
        }
    }
    ctx->pc = 0x1962C4u;
    // 0x1962c4: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x1962c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x1962c8: 0x120400f8  beq         $s0, $a0, . + 4 + (0xF8 << 2)
    ctx->pc = 0x1962C8u;
    {
        const bool branch_taken_0x1962c8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962C8u;
            // 0x1962cc: 0x24040061  addiu       $a0, $zero, 0x61 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962c8) {
            ctx->pc = 0x1966ACu;
            goto label_1966ac;
        }
    }
    ctx->pc = 0x1962D0u;
    // 0x1962d0: 0x120400e1  beq         $s0, $a0, . + 4 + (0xE1 << 2)
    ctx->pc = 0x1962D0u;
    {
        const bool branch_taken_0x1962d0 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962D0u;
            // 0x1962d4: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962d0) {
            ctx->pc = 0x196658u;
            goto label_196658;
        }
    }
    ctx->pc = 0x1962D8u;
    // 0x1962d8: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x1962d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x1962dc: 0x120400cb  beq         $s0, $a0, . + 4 + (0xCB << 2)
    ctx->pc = 0x1962DCu;
    {
        const bool branch_taken_0x1962dc = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962DCu;
            // 0x1962e0: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962dc) {
            ctx->pc = 0x19660Cu;
            goto label_19660c;
        }
    }
    ctx->pc = 0x1962E4u;
    // 0x1962e4: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1962e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1962e8: 0x120400b5  beq         $s0, $a0, . + 4 + (0xB5 << 2)
    ctx->pc = 0x1962E8u;
    {
        const bool branch_taken_0x1962e8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x1962ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962E8u;
            // 0x1962ec: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962e8) {
            ctx->pc = 0x1965C0u;
            goto label_1965c0;
        }
    }
    ctx->pc = 0x1962F0u;
    // 0x1962f0: 0x2408000c  addiu       $t0, $zero, 0xC
    ctx->pc = 0x1962f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1962f4: 0x120800a4  beq         $s0, $t0, . + 4 + (0xA4 << 2)
    ctx->pc = 0x1962F4u;
    {
        const bool branch_taken_0x1962f4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 8));
        ctx->pc = 0x1962F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1962F4u;
            // 0x1962f8: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1962f4) {
            ctx->pc = 0x196588u;
            goto label_196588;
        }
    }
    ctx->pc = 0x1962FCu;
    // 0x1962fc: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x1962fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x196300: 0x120402f7  beq         $s0, $a0, . + 4 + (0x2F7 << 2)
    ctx->pc = 0x196300u;
    {
        const bool branch_taken_0x196300 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x196304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196300u;
            // 0x196304: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196300) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196308u;
    // 0x196308: 0x120402f5  beq         $s0, $a0, . + 4 + (0x2F5 << 2)
    ctx->pc = 0x196308u;
    {
        const bool branch_taken_0x196308 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        if (branch_taken_0x196308) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196310u;
    // 0x196310: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x196310u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x196314: 0x120402f2  beq         $s0, $a0, . + 4 + (0x2F2 << 2)
    ctx->pc = 0x196314u;
    {
        const bool branch_taken_0x196314 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x196318u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196314u;
            // 0x196318: 0x24070008  addiu       $a3, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196314) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19631Cu;
    // 0x19631c: 0x120702f0  beq         $s0, $a3, . + 4 + (0x2F0 << 2)
    ctx->pc = 0x19631Cu;
    {
        const bool branch_taken_0x19631c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 7));
        ctx->pc = 0x196320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19631Cu;
            // 0x196320: 0x24040007  addiu       $a0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19631c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196324u;
    // 0x196324: 0x12040084  beq         $s0, $a0, . + 4 + (0x84 << 2)
    ctx->pc = 0x196324u;
    {
        const bool branch_taken_0x196324 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        if (branch_taken_0x196324) {
            ctx->pc = 0x196538u;
            goto label_196538;
        }
    }
    ctx->pc = 0x19632Cu;
    // 0x19632c: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x19632cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x196330: 0x12040081  beq         $s0, $a0, . + 4 + (0x81 << 2)
    ctx->pc = 0x196330u;
    {
        const bool branch_taken_0x196330 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x196334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196330u;
            // 0x196334: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196330) {
            ctx->pc = 0x196538u;
            goto label_196538;
        }
    }
    ctx->pc = 0x196338u;
    // 0x196338: 0x1204007f  beq         $s0, $a0, . + 4 + (0x7F << 2)
    ctx->pc = 0x196338u;
    {
        const bool branch_taken_0x196338 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x19633Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196338u;
            // 0x19633c: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196338) {
            ctx->pc = 0x196538u;
            goto label_196538;
        }
    }
    ctx->pc = 0x196340u;
    // 0x196340: 0x1206007d  beq         $s0, $a2, . + 4 + (0x7D << 2)
    ctx->pc = 0x196340u;
    {
        const bool branch_taken_0x196340 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 6));
        ctx->pc = 0x196344u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196340u;
            // 0x196344: 0x24040002  addiu       $a0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196340) {
            ctx->pc = 0x196538u;
            goto label_196538;
        }
    }
    ctx->pc = 0x196348u;
    // 0x196348: 0x12040060  beq         $s0, $a0, . + 4 + (0x60 << 2)
    ctx->pc = 0x196348u;
    {
        const bool branch_taken_0x196348 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 4));
        ctx->pc = 0x19634Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196348u;
            // 0x19634c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196348) {
            ctx->pc = 0x1964CCu;
            goto label_1964cc;
        }
    }
    ctx->pc = 0x196350u;
    // 0x196350: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x196354: 0x12020014  beq         $s0, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x196354u;
    {
        const bool branch_taken_0x196354 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        ctx->pc = 0x196358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196354u;
            // 0x196358: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196354) {
            ctx->pc = 0x1963A8u;
            goto label_1963a8;
        }
    }
    ctx->pc = 0x19635Cu;
    // 0x19635c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x19635cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x196360: 0x120202df  beq         $s0, $v0, . + 4 + (0x2DF << 2)
    ctx->pc = 0x196360u;
    {
        const bool branch_taken_0x196360 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 2));
        if (branch_taken_0x196360) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196368u;
    // 0x196368: 0x12000003  beqz        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x196368u;
    {
        const bool branch_taken_0x196368 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x19636Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196368u;
            // 0x19636c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196368) {
            ctx->pc = 0x196378u;
            goto label_196378;
        }
    }
    ctx->pc = 0x196370u;
    // 0x196370: 0x100002db  b           . + 4 + (0x2DB << 2)
    ctx->pc = 0x196370u;
    {
        const bool branch_taken_0x196370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196370) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196378u;
label_196378:
    // 0x196378: 0x2403ff9f  addiu       $v1, $zero, -0x61
    ctx->pc = 0x196378u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967199));
    // 0x19637c: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x19637cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196380: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196380u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196384: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x196384u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x196388: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196388u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19638c: 0xac23fe70  sw          $v1, -0x190($at)
    ctx->pc = 0x19638cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 3));
    // 0x196390: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196390u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196394: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x196394u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196398: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x196398u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19639c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19639cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1963a0: 0x100002cf  b           . + 4 + (0x2CF << 2)
    ctx->pc = 0x1963A0u;
    {
        const bool branch_taken_0x1963a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1963A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963A0u;
            // 0x1963a4: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963a0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1963A8u;
label_1963a8:
    // 0x1963a8: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x1963a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1963ac: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x1963acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1963b0: 0x2402f0ff  addiu       $v0, $zero, -0xF01
    ctx->pc = 0x1963b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294963455));
    // 0x1963b4: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x1963b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x1963b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1963b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1963bc: 0x106002c8  beqz        $v1, . + 4 + (0x2C8 << 2)
    ctx->pc = 0x1963BCu;
    {
        const bool branch_taken_0x1963bc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1963C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963BCu;
            // 0x1963c0: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963bc) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1963C4u;
    // 0x1963c4: 0x24020800  addiu       $v0, $zero, 0x800
    ctx->pc = 0x1963c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1963c8: 0x1062003b  beq         $v1, $v0, . + 4 + (0x3B << 2)
    ctx->pc = 0x1963C8u;
    {
        const bool branch_taken_0x1963c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1963CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963C8u;
            // 0x1963cc: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963c8) {
            ctx->pc = 0x1964B8u;
            goto label_1964b8;
        }
    }
    ctx->pc = 0x1963D0u;
    // 0x1963d0: 0x24020700  addiu       $v0, $zero, 0x700
    ctx->pc = 0x1963d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1792));
    // 0x1963d4: 0x10620033  beq         $v1, $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0x1963D4u;
    {
        const bool branch_taken_0x1963d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1963D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963D4u;
            // 0x1963d8: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963d4) {
            ctx->pc = 0x1964A4u;
            goto label_1964a4;
        }
    }
    ctx->pc = 0x1963DCu;
    // 0x1963dc: 0x24020600  addiu       $v0, $zero, 0x600
    ctx->pc = 0x1963dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x1963e0: 0x1062002b  beq         $v1, $v0, . + 4 + (0x2B << 2)
    ctx->pc = 0x1963E0u;
    {
        const bool branch_taken_0x1963e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1963E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963E0u;
            // 0x1963e4: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963e0) {
            ctx->pc = 0x196490u;
            goto label_196490;
        }
    }
    ctx->pc = 0x1963E8u;
    // 0x1963e8: 0x24020500  addiu       $v0, $zero, 0x500
    ctx->pc = 0x1963e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1280));
    // 0x1963ec: 0x10620023  beq         $v1, $v0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1963ECu;
    {
        const bool branch_taken_0x1963ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1963F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963ECu;
            // 0x1963f0: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963ec) {
            ctx->pc = 0x19647Cu;
            goto label_19647c;
        }
    }
    ctx->pc = 0x1963F4u;
    // 0x1963f4: 0x24020400  addiu       $v0, $zero, 0x400
    ctx->pc = 0x1963f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1963f8: 0x1062001b  beq         $v1, $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1963F8u;
    {
        const bool branch_taken_0x1963f8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1963FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1963F8u;
            // 0x1963fc: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1963f8) {
            ctx->pc = 0x196468u;
            goto label_196468;
        }
    }
    ctx->pc = 0x196400u;
    // 0x196400: 0x24020300  addiu       $v0, $zero, 0x300
    ctx->pc = 0x196400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 768));
    // 0x196404: 0x10620013  beq         $v1, $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x196404u;
    {
        const bool branch_taken_0x196404 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x196408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196404u;
            // 0x196408: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196404) {
            ctx->pc = 0x196454u;
            goto label_196454;
        }
    }
    ctx->pc = 0x19640Cu;
    // 0x19640c: 0x24020100  addiu       $v0, $zero, 0x100
    ctx->pc = 0x19640cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
    // 0x196410: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x196410u;
    {
        const bool branch_taken_0x196410 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x196414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196410u;
            // 0x196414: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196410) {
            ctx->pc = 0x196440u;
            goto label_196440;
        }
    }
    ctx->pc = 0x196418u;
    // 0x196418: 0x24020200  addiu       $v0, $zero, 0x200
    ctx->pc = 0x196418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 512));
    // 0x19641c: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19641Cu;
    {
        const bool branch_taken_0x19641c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x196420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19641Cu;
            // 0x196420: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19641c) {
            ctx->pc = 0x19642Cu;
            goto label_19642c;
        }
    }
    ctx->pc = 0x196424u;
    // 0x196424: 0x100002ae  b           . + 4 + (0x2AE << 2)
    ctx->pc = 0x196424u;
    {
        const bool branch_taken_0x196424 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196424) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19642Cu;
label_19642c:
    // 0x19642c: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x19642cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196430: 0x34420200  ori         $v0, $v0, 0x200
    ctx->pc = 0x196430u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)512);
    // 0x196434: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196434u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196438: 0x100002a9  b           . + 4 + (0x2A9 << 2)
    ctx->pc = 0x196438u;
    {
        const bool branch_taken_0x196438 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19643Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196438u;
            // 0x19643c: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196438) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196440u;
label_196440:
    // 0x196440: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196440u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196444: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x196444u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x196448: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196448u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19644c: 0x100002a4  b           . + 4 + (0x2A4 << 2)
    ctx->pc = 0x19644Cu;
    {
        const bool branch_taken_0x19644c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196450u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19644Cu;
            // 0x196450: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19644c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196454u;
label_196454:
    // 0x196454: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196458: 0x34420300  ori         $v0, $v0, 0x300
    ctx->pc = 0x196458u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)768);
    // 0x19645c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19645cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196460: 0x1000029f  b           . + 4 + (0x29F << 2)
    ctx->pc = 0x196460u;
    {
        const bool branch_taken_0x196460 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196460u;
            // 0x196464: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196460) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196468u;
label_196468:
    // 0x196468: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196468u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x19646c: 0x34420400  ori         $v0, $v0, 0x400
    ctx->pc = 0x19646cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1024);
    // 0x196470: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196470u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196474: 0x1000029a  b           . + 4 + (0x29A << 2)
    ctx->pc = 0x196474u;
    {
        const bool branch_taken_0x196474 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196474u;
            // 0x196478: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196474) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19647Cu;
label_19647c:
    // 0x19647c: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x19647cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196480: 0x34420500  ori         $v0, $v0, 0x500
    ctx->pc = 0x196480u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1280);
    // 0x196484: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196484u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196488: 0x10000295  b           . + 4 + (0x295 << 2)
    ctx->pc = 0x196488u;
    {
        const bool branch_taken_0x196488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19648Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196488u;
            // 0x19648c: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196488) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196490u;
label_196490:
    // 0x196490: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196490u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196494: 0x34420600  ori         $v0, $v0, 0x600
    ctx->pc = 0x196494u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1536);
    // 0x196498: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196498u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19649c: 0x10000290  b           . + 4 + (0x290 << 2)
    ctx->pc = 0x19649Cu;
    {
        const bool branch_taken_0x19649c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1964A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19649Cu;
            // 0x1964a0: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19649c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1964A4u;
label_1964a4:
    // 0x1964a4: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x1964a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1964a8: 0x34420700  ori         $v0, $v0, 0x700
    ctx->pc = 0x1964a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)1792);
    // 0x1964ac: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1964acu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1964b0: 0x1000028b  b           . + 4 + (0x28B << 2)
    ctx->pc = 0x1964B0u;
    {
        const bool branch_taken_0x1964b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1964B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1964B0u;
            // 0x1964b4: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1964b0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1964B8u;
label_1964b8:
    // 0x1964b8: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x1964b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1964bc: 0x34420800  ori         $v0, $v0, 0x800
    ctx->pc = 0x1964bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2048);
    // 0x1964c0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1964c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1964c4: 0x10000286  b           . + 4 + (0x286 << 2)
    ctx->pc = 0x1964C4u;
    {
        const bool branch_taken_0x1964c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1964C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1964C4u;
            // 0x1964c8: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1964c4) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1964CCu;
label_1964cc:
    // 0x1964cc: 0x8faa0038  lw          $t2, 0x38($sp)
    ctx->pc = 0x1964ccu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1964d0: 0x8c25fe70  lw          $a1, -0x190($at)
    ctx->pc = 0x1964d0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1964d4: 0x2404ffe3  addiu       $a0, $zero, -0x1D
    ctx->pc = 0x1964d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967267));
    // 0x1964d8: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x1964d8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1964dc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1964dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1964e0: 0x1140027f  beqz        $t2, . + 4 + (0x27F << 2)
    ctx->pc = 0x1964E0u;
    {
        const bool branch_taken_0x1964e0 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        ctx->pc = 0x1964E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1964E0u;
            // 0x1964e4: 0xac24fe70  sw          $a0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1964e0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1964E8u;
    // 0x1964e8: 0x1143000d  beq         $t2, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1964E8u;
    {
        const bool branch_taken_0x1964e8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 3));
        if (branch_taken_0x1964e8) {
            ctx->pc = 0x196520u;
            goto label_196520;
        }
    }
    ctx->pc = 0x1964F0u;
    // 0x1964f0: 0x1142000b  beq         $t2, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1964F0u;
    {
        const bool branch_taken_0x1964f0 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 2));
        if (branch_taken_0x1964f0) {
            ctx->pc = 0x196520u;
            goto label_196520;
        }
    }
    ctx->pc = 0x1964F8u;
    // 0x1964f8: 0x11490009  beq         $t2, $t1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1964F8u;
    {
        const bool branch_taken_0x1964f8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 9));
        if (branch_taken_0x1964f8) {
            ctx->pc = 0x196520u;
            goto label_196520;
        }
    }
    ctx->pc = 0x196500u;
    // 0x196500: 0x11480007  beq         $t2, $t0, . + 4 + (0x7 << 2)
    ctx->pc = 0x196500u;
    {
        const bool branch_taken_0x196500 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 8));
        if (branch_taken_0x196500) {
            ctx->pc = 0x196520u;
            goto label_196520;
        }
    }
    ctx->pc = 0x196508u;
    // 0x196508: 0x11470005  beq         $t2, $a3, . + 4 + (0x5 << 2)
    ctx->pc = 0x196508u;
    {
        const bool branch_taken_0x196508 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 7));
        if (branch_taken_0x196508) {
            ctx->pc = 0x196520u;
            goto label_196520;
        }
    }
    ctx->pc = 0x196510u;
    // 0x196510: 0x11460003  beq         $t2, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x196510u;
    {
        const bool branch_taken_0x196510 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 6));
        if (branch_taken_0x196510) {
            ctx->pc = 0x196520u;
            goto label_196520;
        }
    }
    ctx->pc = 0x196518u;
    // 0x196518: 0x10000271  b           . + 4 + (0x271 << 2)
    ctx->pc = 0x196518u;
    {
        const bool branch_taken_0x196518 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196518) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196520u;
label_196520:
    // 0x196520: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196520u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196524: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196524u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196528: 0x4a1025  or          $v0, $v0, $t2
    ctx->pc = 0x196528u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 10));
    // 0x19652c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19652cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196530: 0x1000026b  b           . + 4 + (0x26B << 2)
    ctx->pc = 0x196530u;
    {
        const bool branch_taken_0x196530 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196534u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196530u;
            // 0x196534: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196530) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196538u;
label_196538:
    // 0x196538: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x196538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x19653c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x19653cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x196540: 0x16020009  bne         $s0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x196540u;
    {
        const bool branch_taken_0x196540 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x196544u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196540u;
            // 0x196544: 0xafa3003c  sw          $v1, 0x3C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196540) {
            ctx->pc = 0x196568u;
            goto label_196568;
        }
    }
    ctx->pc = 0x196548u;
    // 0x196548: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x196548u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19654c: 0xc0675c8  jal         func_19D720
    ctx->pc = 0x19654Cu;
    SET_GPR_U32(ctx, 31, 0x196554u);
    ctx->pc = 0x196550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19654Cu;
            // 0x196550: 0x27a5003c  addiu       $a1, $sp, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D720u;
    if (runtime->hasFunction(0x19D720u)) {
        auto targetFn = runtime->lookupFunction(0x19D720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196554u; }
        if (ctx->pc != 0x196554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D720_0x19d720(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196554u; }
        if (ctx->pc != 0x196554u) { return; }
    }
    ctx->pc = 0x196554u;
label_196554:
    // 0x196554: 0xc066118  jal         func_198460
    ctx->pc = 0x196554u;
    SET_GPR_U32(ctx, 31, 0x19655Cu);
    ctx->pc = 0x196558u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196554u;
            // 0x196558: 0x8fa4003c  lw          $a0, 0x3C($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198460u;
    if (runtime->hasFunction(0x198460u)) {
        auto targetFn = runtime->lookupFunction(0x198460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19655Cu; }
        if (ctx->pc != 0x19655Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198460_0x198460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19655Cu; }
        if (ctx->pc != 0x19655Cu) { return; }
    }
    ctx->pc = 0x19655Cu;
label_19655c:
    // 0x19655c: 0x8fa2003c  lw          $v0, 0x3C($sp)
    ctx->pc = 0x19655cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x196560: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196560u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196564: 0xac22fee8  sw          $v0, -0x118($at)
    ctx->pc = 0x196564u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294967016), GPR_U32(ctx, 2));
label_196568:
    // 0x196568: 0x8fa4003c  lw          $a0, 0x3C($sp)
    ctx->pc = 0x196568u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 60)));
    // 0x19656c: 0x2602fffc  addiu       $v0, $s0, -0x4
    ctx->pc = 0x19656cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967292));
    // 0x196570: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x196570u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x196574: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x196574u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x196578: 0x24424e60  addiu       $v0, $v0, 0x4E60
    ctx->pc = 0x196578u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20064));
    // 0x19657c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x19657cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x196580: 0x10000257  b           . + 4 + (0x257 << 2)
    ctx->pc = 0x196580u;
    {
        const bool branch_taken_0x196580 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196580u;
            // 0x196584: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196580) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196588u;
label_196588:
    // 0x196588: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x196588u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x19658c: 0x8c25fe70  lw          $a1, -0x190($at)
    ctx->pc = 0x19658cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196590: 0x2404ff7f  addiu       $a0, $zero, -0x81
    ctx->pc = 0x196590u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967167));
    // 0x196594: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x196598: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x196598u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x19659c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19659cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965a0: 0x1462024f  bne         $v1, $v0, . + 4 + (0x24F << 2)
    ctx->pc = 0x1965A0u;
    {
        const bool branch_taken_0x1965a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1965A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1965A0u;
            // 0x1965a4: 0xac24fe70  sw          $a0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1965a0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1965A8u;
    // 0x1965a8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1965a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965ac: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x1965acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1965b0: 0x34420080  ori         $v0, $v0, 0x80
    ctx->pc = 0x1965b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)128);
    // 0x1965b4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1965b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965b8: 0x10000249  b           . + 4 + (0x249 << 2)
    ctx->pc = 0x1965B8u;
    {
        const bool branch_taken_0x1965b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1965BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1965B8u;
            // 0x1965bc: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1965b8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1965C0u;
label_1965c0:
    // 0x1965c0: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x1965c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1965c4: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x1965c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1965c8: 0x30620c00  andi        $v0, $v1, 0xC00
    ctx->pc = 0x1965c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3072);
    // 0x1965cc: 0x10440244  beq         $v0, $a0, . + 4 + (0x244 << 2)
    ctx->pc = 0x1965CCu;
    {
        const bool branch_taken_0x1965cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1965D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1965CCu;
            // 0x1965d0: 0x2402f3ff  addiu       $v0, $zero, -0xC01 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294964223));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1965cc) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1965D4u;
    // 0x1965d4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1965d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965d8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1965d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1965dc: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x1965dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x1965e0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1965e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965e4: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x1965e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1965e8: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1965e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1965ec: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1965ecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965f0: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x1965f0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x1965f4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1965f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1965f8: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x1965f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1965fc: 0xc065eec  jal         func_197BB0
    ctx->pc = 0x1965FCu;
    SET_GPR_U32(ctx, 31, 0x196604u);
    ctx->pc = 0x196600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1965FCu;
            // 0x196600: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197BB0u;
    if (runtime->hasFunction(0x197BB0u)) {
        auto targetFn = runtime->lookupFunction(0x197BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196604u; }
        if (ctx->pc != 0x196604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197BB0_0x197bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196604u; }
        if (ctx->pc != 0x196604u) { return; }
    }
    ctx->pc = 0x196604u;
label_196604:
    // 0x196604: 0x10000236  b           . + 4 + (0x236 << 2)
    ctx->pc = 0x196604u;
    {
        const bool branch_taken_0x196604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196604) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19660Cu;
label_19660c:
    // 0x19660c: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x19660cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196610: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x196610u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196614: 0x306200ff  andi        $v0, $v1, 0xFF
    ctx->pc = 0x196614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x196618: 0x10440231  beq         $v0, $a0, . + 4 + (0x231 << 2)
    ctx->pc = 0x196618u;
    {
        const bool branch_taken_0x196618 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x19661Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196618u;
            // 0x19661c: 0x2402ff00  addiu       $v0, $zero, -0x100 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196618) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196620u;
    // 0x196620: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196620u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196624: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196624u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196628: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196628u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x19662c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19662cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196630: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196630u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196634: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x196634u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x196638: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196638u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19663c: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x19663cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196640: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196640u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196644: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196644u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196648: 0xc065eec  jal         func_197BB0
    ctx->pc = 0x196648u;
    SET_GPR_U32(ctx, 31, 0x196650u);
    ctx->pc = 0x19664Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196648u;
            // 0x19664c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197BB0u;
    if (runtime->hasFunction(0x197BB0u)) {
        auto targetFn = runtime->lookupFunction(0x197BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196650u; }
        if (ctx->pc != 0x196650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197BB0_0x197bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196650u; }
        if (ctx->pc != 0x196650u) { return; }
    }
    ctx->pc = 0x196650u;
label_196650:
    // 0x196650: 0x10000223  b           . + 4 + (0x223 << 2)
    ctx->pc = 0x196650u;
    {
        const bool branch_taken_0x196650 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196650) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196658u;
label_196658:
    // 0x196658: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196658u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x19665c: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x19665cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196660: 0x3c020100  lui         $v0, 0x100
    ctx->pc = 0x196660u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)256 << 16));
    // 0x196664: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196664u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196668: 0x1044021d  beq         $v0, $a0, . + 4 + (0x21D << 2)
    ctx->pc = 0x196668u;
    {
        const bool branch_taken_0x196668 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x19666Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196668u;
            // 0x19666c: 0x3c02feff  lui         $v0, 0xFEFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65279 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196668) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196670u;
    // 0x196670: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196670u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196674: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x196674u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x196678: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x19667c: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x19667cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196680: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196680u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196684: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196684u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196688: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x196688u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x19668c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19668cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196690: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196690u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196694: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196694u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196698: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196698u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x19669c: 0xc065eec  jal         func_197BB0
    ctx->pc = 0x19669Cu;
    SET_GPR_U32(ctx, 31, 0x1966A4u);
    ctx->pc = 0x1966A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19669Cu;
            // 0x1966a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197BB0u;
    if (runtime->hasFunction(0x197BB0u)) {
        auto targetFn = runtime->lookupFunction(0x197BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1966A4u; }
        if (ctx->pc != 0x1966A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197BB0_0x197bb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1966A4u; }
        if (ctx->pc != 0x1966A4u) { return; }
    }
    ctx->pc = 0x1966A4u;
label_1966a4:
    // 0x1966a4: 0x1000020e  b           . + 4 + (0x20E << 2)
    ctx->pc = 0x1966A4u;
    {
        const bool branch_taken_0x1966a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1966a4) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1966ACu;
label_1966ac:
    // 0x1966ac: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x1966acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1966b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1966b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1966b4: 0xac22fe30  sw          $v0, -0x1D0($at)
    ctx->pc = 0x1966b4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966832), GPR_U32(ctx, 2));
    // 0x1966b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1966b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1966bc: 0x8c24fe30  lw          $a0, -0x1D0($at)
    ctx->pc = 0x1966bcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966832)));
    // 0x1966c0: 0x41402  srl         $v0, $a0, 16
    ctx->pc = 0x1966c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x1966c4: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1966c4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1966c8: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1966C8u;
    {
        const bool branch_taken_0x1966c8 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1966CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1966C8u;
            // 0x1966cc: 0x21842  srl         $v1, $v0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1966c8) {
            ctx->pc = 0x1966DCu;
            goto label_1966dc;
        }
    }
    ctx->pc = 0x1966D0u;
    // 0x1966d0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1966d0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1966d4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1966D4u;
    {
        const bool branch_taken_0x1966d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1966D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1966D4u;
            // 0x1966d8: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1966d4) {
            ctx->pc = 0x1966F4u;
            goto label_1966f4;
        }
    }
    ctx->pc = 0x1966DCu;
label_1966dc:
    // 0x1966dc: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x1966dcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1966e0: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1966e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1966e4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1966e4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1966e8: 0x0  nop
    ctx->pc = 0x1966e8u;
    // NOP
    // 0x1966ec: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x1966ecu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x1966f0: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x1966f0u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_1966f4:
    // 0x1966f4: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x1966f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x1966f8: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x1966f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1966fc: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1966fcu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196700: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x196700u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x196704: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196704u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x196708: 0x0  nop
    ctx->pc = 0x196708u;
    // NOP
    // 0x19670c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19670cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196710: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x196710u;
    {
        const bool branch_taken_0x196710 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x196714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196710u;
            // 0x196714: 0xe4204e50  swc1        $f0, 0x4E50($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20048), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196710) {
            ctx->pc = 0x196724u;
            goto label_196724;
        }
    }
    ctx->pc = 0x196718u;
    // 0x196718: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196718u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19671c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19671Cu;
    {
        const bool branch_taken_0x19671c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19671Cu;
            // 0x196720: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19671c) {
            ctx->pc = 0x196740u;
            goto label_196740;
        }
    }
    ctx->pc = 0x196724u;
label_196724:
    // 0x196724: 0x21842  srl         $v1, $v0, 1
    ctx->pc = 0x196724u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x196728: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x196728u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x19672c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x19672cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196730: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196730u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196734: 0x0  nop
    ctx->pc = 0x196734u;
    // NOP
    // 0x196738: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x196738u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x19673c: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x19673cu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_196740:
    // 0x196740: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x196740u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x196744: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x196744u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x196748: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196748u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x19674c: 0x0  nop
    ctx->pc = 0x19674cu;
    // NOP
    // 0x196750: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196750u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x196754: 0x0  nop
    ctx->pc = 0x196754u;
    // NOP
    // 0x196758: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196758u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19675c: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x19675Cu;
    {
        const bool branch_taken_0x19675c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x196760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19675Cu;
            // 0x196760: 0xe4204e54  swc1        $f0, 0x4E54($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20052), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19675c) {
            ctx->pc = 0x196770u;
            goto label_196770;
        }
    }
    ctx->pc = 0x196764u;
    // 0x196764: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196764u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196768: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x196768u;
    {
        const bool branch_taken_0x196768 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19676Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196768u;
            // 0x19676c: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196768) {
            ctx->pc = 0x19678Cu;
            goto label_19678c;
        }
    }
    ctx->pc = 0x196770u;
label_196770:
    // 0x196770: 0x21842  srl         $v1, $v0, 1
    ctx->pc = 0x196770u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x196774: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x196774u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x196778: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x196778u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x19677c: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x19677cu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196780: 0x0  nop
    ctx->pc = 0x196780u;
    // NOP
    // 0x196784: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x196784u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x196788: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x196788u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_19678c:
    // 0x19678c: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x19678cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x196790: 0x41602  srl         $v0, $a0, 24
    ctx->pc = 0x196790u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x196794: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196794u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196798: 0x304400ff  andi        $a0, $v0, 0xFF
    ctx->pc = 0x196798u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x19679c: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x19679cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1967a0: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x1967a0u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x1967a4: 0x0  nop
    ctx->pc = 0x1967a4u;
    // NOP
    // 0x1967a8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1967a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1967ac: 0x14820005  bne         $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1967ACu;
    {
        const bool branch_taken_0x1967ac = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1967B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1967ACu;
            // 0x1967b0: 0xe4204e58  swc1        $f0, 0x4E58($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20056), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1967ac) {
            ctx->pc = 0x1967C4u;
            goto label_1967c4;
        }
    }
    ctx->pc = 0x1967B4u;
    // 0x1967b4: 0x3c024300  lui         $v0, 0x4300
    ctx->pc = 0x1967b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17152 << 16));
    // 0x1967b8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x1967b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x1967bc: 0x100001c8  b           . + 4 + (0x1C8 << 2)
    ctx->pc = 0x1967BCu;
    {
        const bool branch_taken_0x1967bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1967C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1967BCu;
            // 0x1967c0: 0xac224e5c  sw          $v0, 0x4E5C($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20060), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1967bc) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1967C4u;
label_1967c4:
    // 0x1967c4: 0x10800013  beqz        $a0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1967C4u;
    {
        const bool branch_taken_0x1967c4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1967C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1967C4u;
            // 0x1967c8: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1967c4) {
            ctx->pc = 0x196814u;
            goto label_196814;
        }
    }
    ctx->pc = 0x1967CCu;
    // 0x1967cc: 0x42042  srl         $a0, $a0, 1
    ctx->pc = 0x1967ccu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
    // 0x1967d0: 0x14800002  bnez        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1967D0u;
    {
        const bool branch_taken_0x1967d0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1967d0) {
            ctx->pc = 0x1967DCu;
            goto label_1967dc;
        }
    }
    ctx->pc = 0x1967D8u;
    // 0x1967d8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1967d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1967dc:
    // 0x1967dc: 0x4800004  bltz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1967DCu;
    {
        const bool branch_taken_0x1967dc = (GPR_S64(ctx, 4) < 0);
        ctx->pc = 0x1967E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1967DCu;
            // 0x1967e0: 0x41842  srl         $v1, $a0, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1967dc) {
            ctx->pc = 0x1967F0u;
            goto label_1967f0;
        }
    }
    ctx->pc = 0x1967E4u;
    // 0x1967e4: 0x44840000  mtc1        $a0, $f0
    ctx->pc = 0x1967e4u;
    { uint32_t bits = GPR_U32(ctx, 4); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1967e8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1967E8u;
    {
        const bool branch_taken_0x1967e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1967ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1967E8u;
            // 0x1967ec: 0x46800020  cvt.s.w     $f0, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1967e8) {
            ctx->pc = 0x196808u;
            goto label_196808;
        }
    }
    ctx->pc = 0x1967F0u;
label_1967f0:
    // 0x1967f0: 0x30820001  andi        $v0, $a0, 0x1
    ctx->pc = 0x1967f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1967f4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1967f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1967f8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1967f8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1967fc: 0x0  nop
    ctx->pc = 0x1967fcu;
    // NOP
    // 0x196800: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x196800u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x196804: 0x46000000  add.s       $f0, $f0, $f0
    ctx->pc = 0x196804u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_196808:
    // 0x196808: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196808u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19680c: 0x100001b4  b           . + 4 + (0x1B4 << 2)
    ctx->pc = 0x19680Cu;
    {
        const bool branch_taken_0x19680c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19680Cu;
            // 0x196810: 0xe4204e5c  swc1        $f0, 0x4E5C($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20060), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19680c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196814u;
label_196814:
    // 0x196814: 0x100001b2  b           . + 4 + (0x1B2 << 2)
    ctx->pc = 0x196814u;
    {
        const bool branch_taken_0x196814 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196814u;
            // 0x196818: 0xac204e5c  sw          $zero, 0x4E5C($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20060), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196814) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19681Cu;
label_19681c:
    // 0x19681c: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x19681cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196820: 0x8c22fe38  lw          $v0, -0x1C8($at)
    ctx->pc = 0x196820u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966840)));
    // 0x196824: 0x104401ae  beq         $v0, $a0, . + 4 + (0x1AE << 2)
    ctx->pc = 0x196824u;
    {
        const bool branch_taken_0x196824 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x196824) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19682Cu;
    // 0x19682c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19682cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196830: 0xc0660b4  jal         func_1982D0
    ctx->pc = 0x196830u;
    SET_GPR_U32(ctx, 31, 0x196838u);
    ctx->pc = 0x196834u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196830u;
            // 0x196834: 0xac24fe38  sw          $a0, -0x1C8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966840), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1982D0u;
    if (runtime->hasFunction(0x1982D0u)) {
        auto targetFn = runtime->lookupFunction(0x1982D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196838u; }
        if (ctx->pc != 0x196838u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001982D0_0x1982d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196838u; }
        if (ctx->pc != 0x196838u) { return; }
    }
    ctx->pc = 0x196838u;
label_196838:
    // 0x196838: 0x100001a9  b           . + 4 + (0x1A9 << 2)
    ctx->pc = 0x196838u;
    {
        const bool branch_taken_0x196838 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196838) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196840u;
label_196840:
    // 0x196840: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x196840u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x196844: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196848: 0x100001a5  b           . + 4 + (0x1A5 << 2)
    ctx->pc = 0x196848u;
    {
        const bool branch_taken_0x196848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19684Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196848u;
            // 0x19684c: 0xe420fe48  swc1        $f0, -0x1B8($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294966856), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196848) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196850u;
label_196850:
    // 0x196850: 0xc7a00038  lwc1        $f0, 0x38($sp)
    ctx->pc = 0x196850u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 56)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x196854: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196854u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196858: 0x100001a1  b           . + 4 + (0x1A1 << 2)
    ctx->pc = 0x196858u;
    {
        const bool branch_taken_0x196858 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19685Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196858u;
            // 0x19685c: 0xe420fe40  swc1        $f0, -0x1C0($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 4294966848), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196858) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196860u;
label_196860:
    // 0x196860: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x196860u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x196864: 0x8c25fe70  lw          $a1, -0x190($at)
    ctx->pc = 0x196864u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196868: 0x34447fff  ori         $a0, $v0, 0x7FFF
    ctx->pc = 0x196868u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32767);
    // 0x19686c: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x19686cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196870: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x196870u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x196874: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x196874u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x196878: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196878u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19687c: 0x14620198  bne         $v1, $v0, . + 4 + (0x198 << 2)
    ctx->pc = 0x19687Cu;
    {
        const bool branch_taken_0x19687c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x196880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19687Cu;
            // 0x196880: 0xac24fe70  sw          $a0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19687c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196884u;
    // 0x196884: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196884u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196888: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196888u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x19688c: 0x34428000  ori         $v0, $v0, 0x8000
    ctx->pc = 0x19688cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32768);
    // 0x196890: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196890u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196894: 0x10000192  b           . + 4 + (0x192 << 2)
    ctx->pc = 0x196894u;
    {
        const bool branch_taken_0x196894 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196894u;
            // 0x196898: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196894) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19689Cu;
label_19689c:
    // 0x19689c: 0xc065d1c  jal         func_197470
    ctx->pc = 0x19689Cu;
    SET_GPR_U32(ctx, 31, 0x1968A4u);
    ctx->pc = 0x1968A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19689Cu;
            // 0x1968a0: 0x8fa40038  lw          $a0, 0x38($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197470u;
    if (runtime->hasFunction(0x197470u)) {
        auto targetFn = runtime->lookupFunction(0x197470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1968A4u; }
        if (ctx->pc != 0x1968A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197470_0x197470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1968A4u; }
        if (ctx->pc != 0x1968A4u) { return; }
    }
    ctx->pc = 0x1968A4u;
label_1968a4:
    // 0x1968a4: 0x1000018e  b           . + 4 + (0x18E << 2)
    ctx->pc = 0x1968A4u;
    {
        const bool branch_taken_0x1968a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1968a4) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1968ACu;
label_1968ac:
    // 0x1968ac: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x1968acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1968b0: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x1968b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1968b4: 0x2402fffc  addiu       $v0, $zero, -0x4
    ctx->pc = 0x1968b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x1968b8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1968b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1968bc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1968bcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1968c0: 0x10800187  beqz        $a0, . + 4 + (0x187 << 2)
    ctx->pc = 0x1968C0u;
    {
        const bool branch_taken_0x1968c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1968C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1968C0u;
            // 0x1968c4: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1968c0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1968C8u;
    // 0x1968c8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1968c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1968cc: 0x14820184  bne         $a0, $v0, . + 4 + (0x184 << 2)
    ctx->pc = 0x1968CCu;
    {
        const bool branch_taken_0x1968cc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        ctx->pc = 0x1968D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1968CCu;
            // 0x1968d0: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1968cc) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1968D4u;
    // 0x1968d4: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x1968d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1968d8: 0x34420002  ori         $v0, $v0, 0x2
    ctx->pc = 0x1968d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    // 0x1968dc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1968dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1968e0: 0x1000017f  b           . + 4 + (0x17F << 2)
    ctx->pc = 0x1968E0u;
    {
        const bool branch_taken_0x1968e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1968E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1968E0u;
            // 0x1968e4: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1968e0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1968E8u;
label_1968e8:
    // 0x1968e8: 0x8fa60038  lw          $a2, 0x38($sp)
    ctx->pc = 0x1968e8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1968ec: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x1968ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x1968f0: 0x34453f40  ori         $a1, $v0, 0x3F40
    ctx->pc = 0x1968f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16192);
    // 0x1968f4: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1968f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1968f8:
    // 0x1968f8: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1968f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1968fc: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1968fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x196900: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x196900u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x196904: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x196904u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x196908: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x196908u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x19690c: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x19690cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x196910: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x196910u;
    {
        const bool branch_taken_0x196910 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x196914u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196910u;
            // 0x196914: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196910) {
            ctx->pc = 0x1968F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1968f8;
        }
    }
    ctx->pc = 0x196918u;
    // 0x196918: 0x10000171  b           . + 4 + (0x171 << 2)
    ctx->pc = 0x196918u;
    {
        const bool branch_taken_0x196918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196918) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196920u;
label_196920:
    // 0x196920: 0x8fa60038  lw          $a2, 0x38($sp)
    ctx->pc = 0x196920u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196924: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x196924u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x196928: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x196928u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x19692c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x19692cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_196930:
    // 0x196930: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x196930u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x196934: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x196934u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x196938: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x196938u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19693c: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x19693cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x196940: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x196940u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x196944: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x196944u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x196948: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x196948u;
    {
        const bool branch_taken_0x196948 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x19694Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196948u;
            // 0x19694c: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196948) {
            ctx->pc = 0x196930u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_196930;
        }
    }
    ctx->pc = 0x196950u;
    // 0x196950: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x196950u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x196954: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x196954u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x196958: 0x24844d40  addiu       $a0, $a0, 0x4D40
    ctx->pc = 0x196958u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19776));
    // 0x19695c: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x19695cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x196960: 0xc0644a0  jal         func_191280
    ctx->pc = 0x196960u;
    SET_GPR_U32(ctx, 31, 0x196968u);
    ctx->pc = 0x196964u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196960u;
            // 0x196964: 0x34463f80  ori         $a2, $v0, 0x3F80 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16256);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196968u; }
        if (ctx->pc != 0x196968u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196968u; }
        if (ctx->pc != 0x196968u) { return; }
    }
    ctx->pc = 0x196968u;
label_196968:
    // 0x196968: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x196968u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x19696c: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x19696cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x196970: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x196970u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x196974: 0x24844d80  addiu       $a0, $a0, 0x4D80
    ctx->pc = 0x196974u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19840));
    // 0x196978: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x196978u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x19697c: 0xc0644a0  jal         func_191280
    ctx->pc = 0x19697Cu;
    SET_GPR_U32(ctx, 31, 0x196984u);
    ctx->pc = 0x196980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19697Cu;
            // 0x196980: 0x24c64dc0  addiu       $a2, $a2, 0x4DC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196984u; }
        if (ctx->pc != 0x196984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196984u; }
        if (ctx->pc != 0x196984u) { return; }
    }
    ctx->pc = 0x196984u;
label_196984:
    // 0x196984: 0x10000156  b           . + 4 + (0x156 << 2)
    ctx->pc = 0x196984u;
    {
        const bool branch_taken_0x196984 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196984) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x19698Cu;
label_19698c:
    // 0x19698c: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x19698cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196990: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x196990u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x196994: 0xc44c0010  lwc1        $f12, 0x10($v0)
    ctx->pc = 0x196994u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x196998: 0x8c460004  lw          $a2, 0x4($v0)
    ctx->pc = 0x196998u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x19699c: 0xc44d0014  lwc1        $f13, 0x14($v0)
    ctx->pc = 0x19699cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x1969a0: 0x8c470008  lw          $a3, 0x8($v0)
    ctx->pc = 0x1969a0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1969a4: 0x8c48000c  lw          $t0, 0xC($v0)
    ctx->pc = 0x1969a4u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x1969a8: 0xc063e20  jal         func_18F880
    ctx->pc = 0x1969A8u;
    SET_GPR_U32(ctx, 31, 0x1969B0u);
    ctx->pc = 0x1969ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1969A8u;
            // 0x1969ac: 0x24040022  addiu       $a0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F880u;
    if (runtime->hasFunction(0x18F880u)) {
        auto targetFn = runtime->lookupFunction(0x18F880u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1969B0u; }
        if (ctx->pc != 0x1969B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F880_0x18f880(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1969B0u; }
        if (ctx->pc != 0x1969B0u) { return; }
    }
    ctx->pc = 0x1969B0u;
label_1969b0:
    // 0x1969b0: 0x1000014b  b           . + 4 + (0x14B << 2)
    ctx->pc = 0x1969B0u;
    {
        const bool branch_taken_0x1969b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1969b0) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1969B8u;
label_1969b8:
    // 0x1969b8: 0x8fa60038  lw          $a2, 0x38($sp)
    ctx->pc = 0x1969b8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1969bc: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x1969bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x1969c0: 0x34453fc0  ori         $a1, $v0, 0x3FC0
    ctx->pc = 0x1969c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16320);
    // 0x1969c4: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1969c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
label_1969c8:
    // 0x1969c8: 0x8cc30000  lw          $v1, 0x0($a2)
    ctx->pc = 0x1969c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1969cc: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x1969ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x1969d0: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x1969d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x1969d4: 0xaca30000  sw          $v1, 0x0($a1)
    ctx->pc = 0x1969d4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x1969d8: 0x24c60008  addiu       $a2, $a2, 0x8
    ctx->pc = 0x1969d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 8));
    // 0x1969dc: 0xaca20004  sw          $v0, 0x4($a1)
    ctx->pc = 0x1969dcu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1969e0: 0x1c80fff9  bgtz        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1969E0u;
    {
        const bool branch_taken_0x1969e0 = (GPR_S64(ctx, 4) > 0);
        ctx->pc = 0x1969E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1969E0u;
            // 0x1969e4: 0x24a50008  addiu       $a1, $a1, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1969e0) {
            ctx->pc = 0x1969C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1969c8;
        }
    }
    ctx->pc = 0x1969E8u;
    // 0x1969e8: 0x1000013d  b           . + 4 + (0x13D << 2)
    ctx->pc = 0x1969E8u;
    {
        const bool branch_taken_0x1969e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1969e8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x1969F0u;
label_1969f0:
    // 0x1969f0: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x1969f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1969f4: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x1969f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1969f8: 0x31a3c  dsll32      $v1, $v1, 8
    ctx->pc = 0x1969f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 8));
    // 0x1969fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1969fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196a00: 0x31a3e  dsrl32      $v1, $v1, 8
    ctx->pc = 0x196a00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 8));
    // 0x196a04: 0xac23fe70  sw          $v1, -0x190($at)
    ctx->pc = 0x196a04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 3));
    // 0x196a08: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196a08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196a0c: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x196a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196a10: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x196a10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196a14: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196a14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196a18: 0x10000131  b           . + 4 + (0x131 << 2)
    ctx->pc = 0x196A18u;
    {
        const bool branch_taken_0x196a18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A18u;
            // 0x196a1c: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a18) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196A20u;
label_196a20:
    // 0x196a20: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196a20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196a24: 0x2c410008  sltiu       $at, $v0, 0x8
    ctx->pc = 0x196a24u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x196a28: 0x1020001e  beqz        $at, . + 4 + (0x1E << 2)
    ctx->pc = 0x196A28u;
    {
        const bool branch_taken_0x196a28 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x196a28) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A30u;
    // 0x196a30: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x196a30u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x196a34: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x196a34u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x196a38: 0x24631cc0  addiu       $v1, $v1, 0x1CC0
    ctx->pc = 0x196a38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7360));
    // 0x196a3c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x196a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x196a40: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x196a40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x196a44: 0x400008  jr          $v0
    ctx->pc = 0x196A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x196A4Cu: goto label_196a4c;
            case 0x196A58u: goto label_196a58;
            case 0x196A64u: goto label_196a64;
            case 0x196A70u: goto label_196a70;
            case 0x196A7Cu: goto label_196a7c;
            case 0x196A84u: goto label_196a84;
            case 0x196A90u: goto label_196a90;
            case 0x196A9Cu: goto label_196a9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x196A4Cu;
label_196a4c:
    // 0x196a4c: 0x3c020010  lui         $v0, 0x10
    ctx->pc = 0x196a4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16 << 16));
    // 0x196a50: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x196A50u;
    {
        const bool branch_taken_0x196a50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A50u;
            // 0x196a54: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a50) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A58u;
label_196a58:
    // 0x196a58: 0x3c020028  lui         $v0, 0x28
    ctx->pc = 0x196a58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)40 << 16));
    // 0x196a5c: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x196A5Cu;
    {
        const bool branch_taken_0x196a5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A5Cu;
            // 0x196a60: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a5c) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A64u;
label_196a64:
    // 0x196a64: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x196a64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x196a68: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x196A68u;
    {
        const bool branch_taken_0x196a68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A68u;
            // 0x196a6c: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a68) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A70u;
label_196a70:
    // 0x196a70: 0x3c020030  lui         $v0, 0x30
    ctx->pc = 0x196a70u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48 << 16));
    // 0x196a74: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x196A74u;
    {
        const bool branch_taken_0x196a74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A74u;
            // 0x196a78: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a74) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A7Cu;
label_196a7c:
    // 0x196a7c: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x196A7Cu;
    {
        const bool branch_taken_0x196a7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A7Cu;
            // 0x196a80: 0xafa00038  sw          $zero, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a7c) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A84u;
label_196a84:
    // 0x196a84: 0x3c020038  lui         $v0, 0x38
    ctx->pc = 0x196a84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)56 << 16));
    // 0x196a88: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x196A88u;
    {
        const bool branch_taken_0x196a88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A88u;
            // 0x196a8c: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a88) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A90u;
label_196a90:
    // 0x196a90: 0x3c020008  lui         $v0, 0x8
    ctx->pc = 0x196a90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8 << 16));
    // 0x196a94: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x196A94u;
    {
        const bool branch_taken_0x196a94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196A98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196A94u;
            // 0x196a98: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196a94) {
            ctx->pc = 0x196AA4u;
            goto label_196aa4;
        }
    }
    ctx->pc = 0x196A9Cu;
label_196a9c:
    // 0x196a9c: 0x3c020018  lui         $v0, 0x18
    ctx->pc = 0x196a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)24 << 16));
    // 0x196aa0: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x196aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
label_196aa4:
    // 0x196aa4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196aa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196aa8: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196aa8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196aac: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x196aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196ab0: 0x3c020038  lui         $v0, 0x38
    ctx->pc = 0x196ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)56 << 16));
    // 0x196ab4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196ab4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196ab8: 0x10440109  beq         $v0, $a0, . + 4 + (0x109 << 2)
    ctx->pc = 0x196AB8u;
    {
        const bool branch_taken_0x196ab8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x196ABCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196AB8u;
            // 0x196abc: 0x3c02ffc7  lui         $v0, 0xFFC7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65479 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196ab8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196AC0u;
    // 0x196ac0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196ac0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ac4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x196ac4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x196ac8: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196ac8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196acc: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196accu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196ad0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196ad0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ad4: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196ad8: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x196ad8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x196adc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196adcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ae0: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196ae4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196ae4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ae8: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196ae8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196aec: 0xc065e40  jal         func_197900
    ctx->pc = 0x196AECu;
    SET_GPR_U32(ctx, 31, 0x196AF4u);
    ctx->pc = 0x196AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196AECu;
            // 0x196af0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197900u;
    if (runtime->hasFunction(0x197900u)) {
        auto targetFn = runtime->lookupFunction(0x197900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196AF4u; }
        if (ctx->pc != 0x196AF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197900_0x197900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196AF4u; }
        if (ctx->pc != 0x196AF4u) { return; }
    }
    ctx->pc = 0x196AF4u;
label_196af4:
    // 0x196af4: 0x100000fa  b           . + 4 + (0xFA << 2)
    ctx->pc = 0x196AF4u;
    {
        const bool branch_taken_0x196af4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196af4) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196AFCu;
label_196afc:
    // 0x196afc: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x196afcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196b00: 0x8c22fe20  lw          $v0, -0x1E0($at)
    ctx->pc = 0x196b00u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966816)));
    // 0x196b04: 0x106200f6  beq         $v1, $v0, . + 4 + (0xF6 << 2)
    ctx->pc = 0x196B04u;
    {
        const bool branch_taken_0x196b04 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x196b04) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196B0Cu;
    // 0x196b0c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b10: 0xac23fe20  sw          $v1, -0x1E0($at)
    ctx->pc = 0x196b10u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966816), GPR_U32(ctx, 3));
    // 0x196b14: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b18: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196b18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196b1c: 0xc065e40  jal         func_197900
    ctx->pc = 0x196B1Cu;
    SET_GPR_U32(ctx, 31, 0x196B24u);
    ctx->pc = 0x196B20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196B1Cu;
            // 0x196b20: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197900u;
    if (runtime->hasFunction(0x197900u)) {
        auto targetFn = runtime->lookupFunction(0x197900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196B24u; }
        if (ctx->pc != 0x196B24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197900_0x197900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196B24u; }
        if (ctx->pc != 0x196B24u) { return; }
    }
    ctx->pc = 0x196B24u;
label_196b24:
    // 0x196b24: 0x100000ee  b           . + 4 + (0xEE << 2)
    ctx->pc = 0x196B24u;
    {
        const bool branch_taken_0x196b24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196b24) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196B2Cu;
label_196b2c:
    // 0x196b2c: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196b30: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x196b30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196b34: 0x2403bfff  addiu       $v1, $zero, -0x4001
    ctx->pc = 0x196b34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294950911));
    // 0x196b38: 0x831824  and         $v1, $a0, $v1
    ctx->pc = 0x196b38u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x196b3c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b3cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b40: 0x104000e7  beqz        $v0, . + 4 + (0xE7 << 2)
    ctx->pc = 0x196B40u;
    {
        const bool branch_taken_0x196b40 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x196B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196B40u;
            // 0x196b44: 0xac23fe70  sw          $v1, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196b40) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196B48u;
    // 0x196b48: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b4c: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x196b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196b50: 0x34424000  ori         $v0, $v0, 0x4000
    ctx->pc = 0x196b50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16384);
    // 0x196b54: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b58: 0x100000e1  b           . + 4 + (0xE1 << 2)
    ctx->pc = 0x196B58u;
    {
        const bool branch_taken_0x196b58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196B58u;
            // 0x196b5c: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196b58) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196B60u;
label_196b60:
    // 0x196b60: 0x3c02fffe  lui         $v0, 0xFFFE
    ctx->pc = 0x196b60u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65534 << 16));
    // 0x196b64: 0x8c25fe68  lw          $a1, -0x198($at)
    ctx->pc = 0x196b64u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196b68: 0x3444ffff  ori         $a0, $v0, 0xFFFF
    ctx->pc = 0x196b68u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x196b6c: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196b70: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x196b70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x196b74: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x196b74u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x196b78: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b7c: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x196B7Cu;
    {
        const bool branch_taken_0x196b7c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x196B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196B7Cu;
            // 0x196b80: 0xac24fe68  sw          $a0, -0x198($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196b7c) {
            ctx->pc = 0x196B98u;
            goto label_196b98;
        }
    }
    ctx->pc = 0x196B84u;
    // 0x196b84: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b88: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196b88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196b8c: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x196b8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x196b90: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b94: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196b94u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
label_196b98:
    // 0x196b98: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196b98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196b9c: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196b9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196ba0: 0xc0660e4  jal         func_198390
    ctx->pc = 0x196BA0u;
    SET_GPR_U32(ctx, 31, 0x196BA8u);
    ctx->pc = 0x196BA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196BA0u;
            // 0x196ba4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198390u;
    if (runtime->hasFunction(0x198390u)) {
        auto targetFn = runtime->lookupFunction(0x198390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196BA8u; }
        if (ctx->pc != 0x196BA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198390_0x198390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196BA8u; }
        if (ctx->pc != 0x196BA8u) { return; }
    }
    ctx->pc = 0x196BA8u;
label_196ba8:
    // 0x196ba8: 0x100000cd  b           . + 4 + (0xCD << 2)
    ctx->pc = 0x196BA8u;
    {
        const bool branch_taken_0x196ba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196ba8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196BB0u;
label_196bb0:
    // 0x196bb0: 0x3c02fff9  lui         $v0, 0xFFF9
    ctx->pc = 0x196bb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65529 << 16));
    // 0x196bb4: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x196bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196bb8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x196bb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x196bbc: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196bbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196bc0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196bc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196bc4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196bc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196bc8: 0x108000c5  beqz        $a0, . + 4 + (0xC5 << 2)
    ctx->pc = 0x196BC8u;
    {
        const bool branch_taken_0x196bc8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x196BCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196BC8u;
            // 0x196bcc: 0xac22fe68  sw          $v0, -0x198($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196bc8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196BD0u;
    // 0x196bd0: 0x3c030002  lui         $v1, 0x2
    ctx->pc = 0x196bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)2 << 16));
    // 0x196bd4: 0x148300c2  bne         $a0, $v1, . + 4 + (0xC2 << 2)
    ctx->pc = 0x196BD4u;
    {
        const bool branch_taken_0x196bd4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x196BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196BD4u;
            // 0x196bd8: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196bd4) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196BDCu;
    // 0x196bdc: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196be0: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x196be0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x196be4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196be4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196be8: 0x100000bd  b           . + 4 + (0xBD << 2)
    ctx->pc = 0x196BE8u;
    {
        const bool branch_taken_0x196be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196BE8u;
            // 0x196bec: 0xac22fe68  sw          $v0, -0x198($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196be8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196BF0u;
label_196bf0:
    // 0x196bf0: 0x3c02fffd  lui         $v0, 0xFFFD
    ctx->pc = 0x196bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65533 << 16));
    // 0x196bf4: 0x8c25fe70  lw          $a1, -0x190($at)
    ctx->pc = 0x196bf4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196bf8: 0x3444ffff  ori         $a0, $v0, 0xFFFF
    ctx->pc = 0x196bf8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x196bfc: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x196bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196c00: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196c00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x196c04: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x196c04u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x196c08: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196c08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196c0c: 0x146200b4  bne         $v1, $v0, . + 4 + (0xB4 << 2)
    ctx->pc = 0x196C0Cu;
    {
        const bool branch_taken_0x196c0c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x196C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196C0Cu;
            // 0x196c10: 0xac24fe70  sw          $a0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196c0c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196C14u;
    // 0x196c14: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196c14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196c18: 0x3c020002  lui         $v0, 0x2
    ctx->pc = 0x196c18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)2 << 16));
    // 0x196c1c: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x196c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x196c20: 0x621025  or          $v0, $v1, $v0
    ctx->pc = 0x196c20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196c24: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196c24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196c28: 0x100000ad  b           . + 4 + (0xAD << 2)
    ctx->pc = 0x196C28u;
    {
        const bool branch_taken_0x196c28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196C28u;
            // 0x196c2c: 0xac22fe70  sw          $v0, -0x190($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966896), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196c28) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196C30u;
label_196c30:
    // 0x196c30: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196c30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196c34: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196c34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196c38: 0x41402  srl         $v0, $a0, 16
    ctx->pc = 0x196c38u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x196c3c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x196c3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x196c40: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x196C40u;
    {
        const bool branch_taken_0x196c40 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x196C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196C40u;
            // 0x196c44: 0xac24fe28  sw          $a0, -0x1D8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966824), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196c40) {
            ctx->pc = 0x196C54u;
            goto label_196c54;
        }
    }
    ctx->pc = 0x196C48u;
    // 0x196c48: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196c48u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196c4c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x196C4Cu;
    {
        const bool branch_taken_0x196c4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196C4Cu;
            // 0x196c50: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196c4c) {
            ctx->pc = 0x196C70u;
            goto label_196c70;
        }
    }
    ctx->pc = 0x196C54u;
label_196c54:
    // 0x196c54: 0x21842  srl         $v1, $v0, 1
    ctx->pc = 0x196c54u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x196c58: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x196c58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x196c5c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x196c5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196c60: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196c60u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196c64: 0x0  nop
    ctx->pc = 0x196c64u;
    // NOP
    // 0x196c68: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x196c68u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x196c6c: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x196c6cu;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_196c70:
    // 0x196c70: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x196c70u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x196c74: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x196c74u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x196c78: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196c78u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196c7c: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x196c7cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x196c80: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196c80u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x196c84: 0x0  nop
    ctx->pc = 0x196c84u;
    // NOP
    // 0x196c88: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196c88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196c8c: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x196C8Cu;
    {
        const bool branch_taken_0x196c8c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x196C90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196C8Cu;
            // 0x196c90: 0xe4204e40  swc1        $f0, 0x4E40($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20032), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196c8c) {
            ctx->pc = 0x196CA0u;
            goto label_196ca0;
        }
    }
    ctx->pc = 0x196C94u;
    // 0x196c94: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196c94u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196c98: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x196C98u;
    {
        const bool branch_taken_0x196c98 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196C9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196C98u;
            // 0x196c9c: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196c98) {
            ctx->pc = 0x196CBCu;
            goto label_196cbc;
        }
    }
    ctx->pc = 0x196CA0u;
label_196ca0:
    // 0x196ca0: 0x21842  srl         $v1, $v0, 1
    ctx->pc = 0x196ca0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x196ca4: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x196ca4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x196ca8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x196ca8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196cac: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196cacu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196cb0: 0x0  nop
    ctx->pc = 0x196cb0u;
    // NOP
    // 0x196cb4: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x196cb4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x196cb8: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x196cb8u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_196cbc:
    // 0x196cbc: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x196cbcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x196cc0: 0x308200ff  andi        $v0, $a0, 0xFF
    ctx->pc = 0x196cc0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x196cc4: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196cc4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196cc8: 0x0  nop
    ctx->pc = 0x196cc8u;
    // NOP
    // 0x196ccc: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196cccu;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x196cd0: 0x0  nop
    ctx->pc = 0x196cd0u;
    // NOP
    // 0x196cd4: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196cd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196cd8: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x196CD8u;
    {
        const bool branch_taken_0x196cd8 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x196CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196CD8u;
            // 0x196cdc: 0xe4204e44  swc1        $f0, 0x4E44($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20036), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196cd8) {
            ctx->pc = 0x196CECu;
            goto label_196cec;
        }
    }
    ctx->pc = 0x196CE0u;
    // 0x196ce0: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196ce0u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196ce4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x196CE4u;
    {
        const bool branch_taken_0x196ce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196CE4u;
            // 0x196ce8: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196ce4) {
            ctx->pc = 0x196D08u;
            goto label_196d08;
        }
    }
    ctx->pc = 0x196CECu;
label_196cec:
    // 0x196cec: 0x21842  srl         $v1, $v0, 1
    ctx->pc = 0x196cecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x196cf0: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x196cf0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x196cf4: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x196cf4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196cf8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196cf8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196cfc: 0x0  nop
    ctx->pc = 0x196cfcu;
    // NOP
    // 0x196d00: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x196d00u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x196d04: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x196d04u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_196d08:
    // 0x196d08: 0x3c03437f  lui         $v1, 0x437F
    ctx->pc = 0x196d08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17279 << 16));
    // 0x196d0c: 0x41602  srl         $v0, $a0, 24
    ctx->pc = 0x196d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
    // 0x196d10: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196d10u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196d14: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x196d14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x196d18: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196d18u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x196d1c: 0x0  nop
    ctx->pc = 0x196d1cu;
    // NOP
    // 0x196d20: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196d20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196d24: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x196D24u;
    {
        const bool branch_taken_0x196d24 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x196D28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196D24u;
            // 0x196d28: 0xe4204e48  swc1        $f0, 0x4E48($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20040), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196d24) {
            ctx->pc = 0x196D38u;
            goto label_196d38;
        }
    }
    ctx->pc = 0x196D2Cu;
    // 0x196d2c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196d2cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196d30: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x196D30u;
    {
        const bool branch_taken_0x196d30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196D30u;
            // 0x196d34: 0x46800060  cvt.s.w     $f1, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196d30) {
            ctx->pc = 0x196D54u;
            goto label_196d54;
        }
    }
    ctx->pc = 0x196D38u;
label_196d38:
    // 0x196d38: 0x21842  srl         $v1, $v0, 1
    ctx->pc = 0x196d38u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x196d3c: 0x30420001  andi        $v0, $v0, 0x1
    ctx->pc = 0x196d3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x196d40: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x196d40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x196d44: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x196d44u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196d48: 0x0  nop
    ctx->pc = 0x196d48u;
    // NOP
    // 0x196d4c: 0x46800060  cvt.s.w     $f1, $f0
    ctx->pc = 0x196d4cu;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[1] = FPU_CVT_S_W(tmp); }
    // 0x196d50: 0x46010840  add.s       $f1, $f1, $f1
    ctx->pc = 0x196d50u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[1]);
label_196d54:
    // 0x196d54: 0x3c02437f  lui         $v0, 0x437F
    ctx->pc = 0x196d54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)17279 << 16));
    // 0x196d58: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x196d58u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x196d5c: 0x0  nop
    ctx->pc = 0x196d5cu;
    // NOP
    // 0x196d60: 0x46000803  div.s       $f0, $f1, $f0
    ctx->pc = 0x196d60u;
    if (ctx->f[0] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[1]) ^ std::bit_cast<uint32_t>(ctx->f[0])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[0] = std::bit_cast<float>(__maxf); } else ctx->f[0] = ctx->f[1] / ctx->f[0];
    // 0x196d64: 0x0  nop
    ctx->pc = 0x196d64u;
    // NOP
    // 0x196d68: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196d68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196d6c: 0x1000005c  b           . + 4 + (0x5C << 2)
    ctx->pc = 0x196D6Cu;
    {
        const bool branch_taken_0x196d6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196D70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196D6Cu;
            // 0x196d70: 0xe4204e4c  swc1        $f0, 0x4E4C($at) (Delay Slot)
        { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 1), 20044), bits); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x196d6c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196D74u;
label_196d74:
    // 0x196d74: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196d74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196d78: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196d78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196d7c: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x196D7Cu;
    {
        const bool branch_taken_0x196d7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196D7Cu;
            // 0x196d80: 0xac224e70  sw          $v0, 0x4E70($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20080), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196d7c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196D84u;
label_196d84:
    // 0x196d84: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196d84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196d88: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x196d88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x196d8c: 0x10000054  b           . + 4 + (0x54 << 2)
    ctx->pc = 0x196D8Cu;
    {
        const bool branch_taken_0x196d8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196D90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196D8Cu;
            // 0x196d90: 0xac224e68  sw          $v0, 0x4E68($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20072), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196d8c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196D94u;
label_196d94:
    // 0x196d94: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196d94u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196d98: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x196d98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196d9c: 0x3c0200c0  lui         $v0, 0xC0
    ctx->pc = 0x196d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)192 << 16));
    // 0x196da0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196da0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196da4: 0x1044004e  beq         $v0, $a0, . + 4 + (0x4E << 2)
    ctx->pc = 0x196DA4u;
    {
        const bool branch_taken_0x196da4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x196DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196DA4u;
            // 0x196da8: 0x3c02ff3f  lui         $v0, 0xFF3F (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65343 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196da4) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196DACu;
    // 0x196dac: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196dacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196db0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x196db0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x196db4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196db4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196db8: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196db8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196dbc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196dbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196dc0: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196dc4: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x196dc4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x196dc8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196dc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196dcc: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x196DCCu;
    {
        const bool branch_taken_0x196dcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196DD0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196DCCu;
            // 0x196dd0: 0xac22fe68  sw          $v0, -0x198($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196dcc) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196DD4u;
label_196dd4:
    // 0x196dd4: 0x8fa30038  lw          $v1, 0x38($sp)
    ctx->pc = 0x196dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196dd8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x196ddc: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x196DDCu;
    {
        const bool branch_taken_0x196ddc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x196DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196DDCu;
            // 0x196de0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196ddc) {
            ctx->pc = 0x196DE8u;
            goto label_196de8;
        }
    }
    ctx->pc = 0x196DE4u;
    // 0x196de4: 0x34028000  ori         $v0, $zero, 0x8000
    ctx->pc = 0x196de4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
label_196de8:
    // 0x196de8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196de8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196dec: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x196decu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
    // 0x196df0: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x196df0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196df4: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196df4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196df8: 0x30628000  andi        $v0, $v1, 0x8000
    ctx->pc = 0x196df8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32768);
    // 0x196dfc: 0x10440038  beq         $v0, $a0, . + 4 + (0x38 << 2)
    ctx->pc = 0x196DFCu;
    {
        const bool branch_taken_0x196dfc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        if (branch_taken_0x196dfc) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196E04u;
    // 0x196e04: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x196e04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x196e08: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196e08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196e0c: 0x34427fff  ori         $v0, $v0, 0x7FFF
    ctx->pc = 0x196e0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)32767);
    // 0x196e10: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196e10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196e14: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196e14u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196e18: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196e18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196e1c: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196e20: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x196e20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x196e24: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196e24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196e28: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196e28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196e2c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196e2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196e30: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196e30u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196e34: 0xc065de0  jal         func_197780
    ctx->pc = 0x196E34u;
    SET_GPR_U32(ctx, 31, 0x196E3Cu);
    ctx->pc = 0x196E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196E34u;
            // 0x196e38: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197780u;
    if (runtime->hasFunction(0x197780u)) {
        auto targetFn = runtime->lookupFunction(0x197780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196E3Cu; }
        if (ctx->pc != 0x196E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197780_0x197780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196E3Cu; }
        if (ctx->pc != 0x196E3Cu) { return; }
    }
    ctx->pc = 0x196E3Cu;
label_196e3c:
    // 0x196e3c: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x196E3Cu;
    {
        const bool branch_taken_0x196e3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x196e3c) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196E44u;
label_196e44:
    // 0x196e44: 0x8fa20038  lw          $v0, 0x38($sp)
    ctx->pc = 0x196e44u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196e48: 0x2c410008  sltiu       $at, $v0, 0x8
    ctx->pc = 0x196e48u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)8) ? 1 : 0);
    // 0x196e4c: 0x10200012  beqz        $at, . + 4 + (0x12 << 2)
    ctx->pc = 0x196E4Cu;
    {
        const bool branch_taken_0x196e4c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x196e4c) {
            ctx->pc = 0x196E98u;
            goto label_196e98;
        }
    }
    ctx->pc = 0x196E54u;
    // 0x196e54: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x196e54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x196e58: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x196e58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x196e5c: 0x24631ca0  addiu       $v1, $v1, 0x1CA0
    ctx->pc = 0x196e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 7328));
    // 0x196e60: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x196e60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x196e64: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x196e64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x196e68: 0x400008  jr          $v0
    ctx->pc = 0x196E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x196E70u: goto label_196e70;
            case 0x196E78u: goto label_196e78;
            case 0x196E84u: goto label_196e84;
            case 0x196E90u: goto label_196e90;
            case 0x196E98u: goto label_196e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x196E70u;
label_196e70:
    // 0x196e70: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x196E70u;
    {
        const bool branch_taken_0x196e70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196E74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196E70u;
            // 0x196e74: 0xafa00038  sw          $zero, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196e70) {
            ctx->pc = 0x196E98u;
            goto label_196e98;
        }
    }
    ctx->pc = 0x196E78u;
label_196e78:
    // 0x196e78: 0x24027000  addiu       $v0, $zero, 0x7000
    ctx->pc = 0x196e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
    // 0x196e7c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x196E7Cu;
    {
        const bool branch_taken_0x196e7c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196E7Cu;
            // 0x196e80: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196e7c) {
            ctx->pc = 0x196E98u;
            goto label_196e98;
        }
    }
    ctx->pc = 0x196E84u;
label_196e84:
    // 0x196e84: 0x24021000  addiu       $v0, $zero, 0x1000
    ctx->pc = 0x196e84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x196e88: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x196E88u;
    {
        const bool branch_taken_0x196e88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x196E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196E88u;
            // 0x196e8c: 0xafa20038  sw          $v0, 0x38($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196e88) {
            ctx->pc = 0x196E98u;
            goto label_196e98;
        }
    }
    ctx->pc = 0x196E90u;
label_196e90:
    // 0x196e90: 0x24023000  addiu       $v0, $zero, 0x3000
    ctx->pc = 0x196e90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12288));
    // 0x196e94: 0xafa20038  sw          $v0, 0x38($sp)
    ctx->pc = 0x196e94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 2));
label_196e98:
    // 0x196e98: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196e98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196e9c: 0x8fa40038  lw          $a0, 0x38($sp)
    ctx->pc = 0x196e9cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x196ea0: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x196ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196ea4: 0x30627000  andi        $v0, $v1, 0x7000
    ctx->pc = 0x196ea4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)28672);
    // 0x196ea8: 0x1044000d  beq         $v0, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x196EA8u;
    {
        const bool branch_taken_0x196ea8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x196EACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196EA8u;
            // 0x196eac: 0x24028fff  addiu       $v0, $zero, -0x7001 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294938623));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196ea8) {
            ctx->pc = 0x196EE0u;
            goto label_196ee0;
        }
    }
    ctx->pc = 0x196EB0u;
    // 0x196eb0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196eb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196eb4: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x196eb4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x196eb8: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196eb8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196ebc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196ebcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ec0: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x196ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196ec4: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x196ec4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x196ec8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196ec8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ecc: 0xac22fe68  sw          $v0, -0x198($at)
    ctx->pc = 0x196eccu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966888), GPR_U32(ctx, 2));
    // 0x196ed0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x196ed0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x196ed4: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x196ed4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x196ed8: 0xc065e40  jal         func_197900
    ctx->pc = 0x196ED8u;
    SET_GPR_U32(ctx, 31, 0x196EE0u);
    ctx->pc = 0x196EDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x196ED8u;
            // 0x196edc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x197900u;
    if (runtime->hasFunction(0x197900u)) {
        auto targetFn = runtime->lookupFunction(0x197900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196EE0u; }
        if (ctx->pc != 0x196EE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00197900_0x197900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x196EE0u; }
        if (ctx->pc != 0x196EE0u) { return; }
    }
    ctx->pc = 0x196EE0u;
label_196ee0:
    // 0x196ee0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x196ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_196ee4:
    // 0x196ee4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x196ee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_196ee8:
    // 0x196ee8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x196ee8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x196eec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x196eecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x196ef0: 0x3e00008  jr          $ra
    ctx->pc = 0x196EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x196EF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196EF0u;
            // 0x196ef4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x196060u: goto label_196060;
            case 0x196084u: goto label_196084;
            case 0x19608Cu: goto label_19608c;
            case 0x196090u: goto label_196090;
            case 0x1960CCu: goto label_1960cc;
            case 0x1960F0u: goto label_1960f0;
            case 0x196130u: goto label_196130;
            case 0x196158u: goto label_196158;
            case 0x1961B8u: goto label_1961b8;
            case 0x1961BCu: goto label_1961bc;
            case 0x196378u: goto label_196378;
            case 0x1963A8u: goto label_1963a8;
            case 0x19642Cu: goto label_19642c;
            case 0x196440u: goto label_196440;
            case 0x196454u: goto label_196454;
            case 0x196468u: goto label_196468;
            case 0x19647Cu: goto label_19647c;
            case 0x196490u: goto label_196490;
            case 0x1964A4u: goto label_1964a4;
            case 0x1964B8u: goto label_1964b8;
            case 0x1964CCu: goto label_1964cc;
            case 0x196520u: goto label_196520;
            case 0x196538u: goto label_196538;
            case 0x196554u: goto label_196554;
            case 0x19655Cu: goto label_19655c;
            case 0x196568u: goto label_196568;
            case 0x196588u: goto label_196588;
            case 0x1965C0u: goto label_1965c0;
            case 0x196604u: goto label_196604;
            case 0x19660Cu: goto label_19660c;
            case 0x196650u: goto label_196650;
            case 0x196658u: goto label_196658;
            case 0x1966A4u: goto label_1966a4;
            case 0x1966ACu: goto label_1966ac;
            case 0x1966DCu: goto label_1966dc;
            case 0x1966F4u: goto label_1966f4;
            case 0x196724u: goto label_196724;
            case 0x196740u: goto label_196740;
            case 0x196770u: goto label_196770;
            case 0x19678Cu: goto label_19678c;
            case 0x1967C4u: goto label_1967c4;
            case 0x1967DCu: goto label_1967dc;
            case 0x1967F0u: goto label_1967f0;
            case 0x196808u: goto label_196808;
            case 0x196814u: goto label_196814;
            case 0x19681Cu: goto label_19681c;
            case 0x196838u: goto label_196838;
            case 0x196840u: goto label_196840;
            case 0x196850u: goto label_196850;
            case 0x196860u: goto label_196860;
            case 0x19689Cu: goto label_19689c;
            case 0x1968A4u: goto label_1968a4;
            case 0x1968ACu: goto label_1968ac;
            case 0x1968E8u: goto label_1968e8;
            case 0x1968F8u: goto label_1968f8;
            case 0x196920u: goto label_196920;
            case 0x196930u: goto label_196930;
            case 0x196968u: goto label_196968;
            case 0x196984u: goto label_196984;
            case 0x19698Cu: goto label_19698c;
            case 0x1969B0u: goto label_1969b0;
            case 0x1969B8u: goto label_1969b8;
            case 0x1969C8u: goto label_1969c8;
            case 0x1969F0u: goto label_1969f0;
            case 0x196A20u: goto label_196a20;
            case 0x196A4Cu: goto label_196a4c;
            case 0x196A58u: goto label_196a58;
            case 0x196A64u: goto label_196a64;
            case 0x196A70u: goto label_196a70;
            case 0x196A7Cu: goto label_196a7c;
            case 0x196A84u: goto label_196a84;
            case 0x196A90u: goto label_196a90;
            case 0x196A9Cu: goto label_196a9c;
            case 0x196AA4u: goto label_196aa4;
            case 0x196AF4u: goto label_196af4;
            case 0x196AFCu: goto label_196afc;
            case 0x196B24u: goto label_196b24;
            case 0x196B2Cu: goto label_196b2c;
            case 0x196B60u: goto label_196b60;
            case 0x196B98u: goto label_196b98;
            case 0x196BA8u: goto label_196ba8;
            case 0x196BB0u: goto label_196bb0;
            case 0x196BF0u: goto label_196bf0;
            case 0x196C30u: goto label_196c30;
            case 0x196C54u: goto label_196c54;
            case 0x196C70u: goto label_196c70;
            case 0x196CA0u: goto label_196ca0;
            case 0x196CBCu: goto label_196cbc;
            case 0x196CECu: goto label_196cec;
            case 0x196D08u: goto label_196d08;
            case 0x196D38u: goto label_196d38;
            case 0x196D54u: goto label_196d54;
            case 0x196D74u: goto label_196d74;
            case 0x196D84u: goto label_196d84;
            case 0x196D94u: goto label_196d94;
            case 0x196DD4u: goto label_196dd4;
            case 0x196DE8u: goto label_196de8;
            case 0x196E3Cu: goto label_196e3c;
            case 0x196E44u: goto label_196e44;
            case 0x196E70u: goto label_196e70;
            case 0x196E78u: goto label_196e78;
            case 0x196E84u: goto label_196e84;
            case 0x196E90u: goto label_196e90;
            case 0x196E98u: goto label_196e98;
            case 0x196EE0u: goto label_196ee0;
            case 0x196EE4u: goto label_196ee4;
            case 0x196EE8u: goto label_196ee8;
            case 0x1970FCu: goto label_1970fc;
            case 0x19710Cu: goto label_19710c;
            case 0x19711Cu: goto label_19711c;
            case 0x197138u: goto label_197138;
            case 0x197158u: goto label_197158;
            case 0x197168u: goto label_197168;
            case 0x197174u: goto label_197174;
            case 0x197180u: goto label_197180;
            case 0x1971A8u: goto label_1971a8;
            case 0x1971B0u: goto label_1971b0;
            case 0x1971B8u: goto label_1971b8;
            case 0x1971D8u: goto label_1971d8;
            case 0x1971E8u: goto label_1971e8;
            case 0x1971ECu: goto label_1971ec;
            case 0x197210u: goto label_197210;
            case 0x197224u: goto label_197224;
            case 0x197230u: goto label_197230;
            case 0x1972A0u: goto label_1972a0;
            case 0x1972A8u: goto label_1972a8;
            case 0x1972B0u: goto label_1972b0;
            case 0x1972B8u: goto label_1972b8;
            case 0x1972C0u: goto label_1972c0;
            case 0x1972C8u: goto label_1972c8;
            case 0x1972D0u: goto label_1972d0;
            case 0x1972D8u: goto label_1972d8;
            case 0x1972E4u: goto label_1972e4;
            case 0x197304u: goto label_197304;
            case 0x197324u: goto label_197324;
            case 0x197338u: goto label_197338;
            case 0x19734Cu: goto label_19734c;
            case 0x19736Cu: goto label_19736c;
            case 0x197378u: goto label_197378;
            case 0x197384u: goto label_197384;
            case 0x197398u: goto label_197398;
            case 0x1973B8u: goto label_1973b8;
            case 0x197428u: goto label_197428;
            case 0x197430u: goto label_197430;
            case 0x197438u: goto label_197438;
            case 0x197440u: goto label_197440;
            case 0x197448u: goto label_197448;
            case 0x197450u: goto label_197450;
            case 0x197458u: goto label_197458;
            case 0x19745Cu: goto label_19745c;
            case 0x197460u: goto label_197460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x196EF8u;
    // 0x196ef8: 0x0  nop
    ctx->pc = 0x196ef8u;
    // NOP
    // 0x196efc: 0x0  nop
    ctx->pc = 0x196efcu;
    // NOP
    // 0x196f00: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x196f00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x196f04: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x196f04u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x196f08: 0x2404006d  addiu       $a0, $zero, 0x6D
    ctx->pc = 0x196f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 109));
    // 0x196f0c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x196f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x196f10: 0x10640129  beq         $v1, $a0, . + 4 + (0x129 << 2)
    ctx->pc = 0x196F10u;
    {
        const bool branch_taken_0x196f10 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x196F14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196F10u;
            // 0x196f14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196f10) {
            ctx->pc = 0x1973B8u;
            goto label_1973b8;
        }
    }
    ctx->pc = 0x196F18u;
    // 0x196f18: 0x2404006c  addiu       $a0, $zero, 0x6C
    ctx->pc = 0x196f18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 108));
    // 0x196f1c: 0x1064011e  beq         $v1, $a0, . + 4 + (0x11E << 2)
    ctx->pc = 0x196F1Cu;
    {
        const bool branch_taken_0x196f1c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f1c) {
            ctx->pc = 0x197398u;
            goto label_197398;
        }
    }
    ctx->pc = 0x196F24u;
    // 0x196f24: 0x2404006b  addiu       $a0, $zero, 0x6B
    ctx->pc = 0x196f24u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
    // 0x196f28: 0x10640116  beq         $v1, $a0, . + 4 + (0x116 << 2)
    ctx->pc = 0x196F28u;
    {
        const bool branch_taken_0x196f28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f28) {
            ctx->pc = 0x197384u;
            goto label_197384;
        }
    }
    ctx->pc = 0x196F30u;
    // 0x196f30: 0x2404006a  addiu       $a0, $zero, 0x6A
    ctx->pc = 0x196f30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 106));
    // 0x196f34: 0x10640110  beq         $v1, $a0, . + 4 + (0x110 << 2)
    ctx->pc = 0x196F34u;
    {
        const bool branch_taken_0x196f34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f34) {
            ctx->pc = 0x197378u;
            goto label_197378;
        }
    }
    ctx->pc = 0x196F3Cu;
    // 0x196f3c: 0x24040069  addiu       $a0, $zero, 0x69
    ctx->pc = 0x196f3cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 105));
    // 0x196f40: 0x1064010a  beq         $v1, $a0, . + 4 + (0x10A << 2)
    ctx->pc = 0x196F40u;
    {
        const bool branch_taken_0x196f40 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f40) {
            ctx->pc = 0x19736Cu;
            goto label_19736c;
        }
    }
    ctx->pc = 0x196F48u;
    // 0x196f48: 0x24040068  addiu       $a0, $zero, 0x68
    ctx->pc = 0x196f48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 104));
    // 0x196f4c: 0x10640143  beq         $v1, $a0, . + 4 + (0x143 << 2)
    ctx->pc = 0x196F4Cu;
    {
        const bool branch_taken_0x196f4c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f4c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x196F54u;
    // 0x196f54: 0x24040066  addiu       $a0, $zero, 0x66
    ctx->pc = 0x196f54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 102));
    // 0x196f58: 0x106400fc  beq         $v1, $a0, . + 4 + (0xFC << 2)
    ctx->pc = 0x196F58u;
    {
        const bool branch_taken_0x196f58 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f58) {
            ctx->pc = 0x19734Cu;
            goto label_19734c;
        }
    }
    ctx->pc = 0x196F60u;
    // 0x196f60: 0x24040065  addiu       $a0, $zero, 0x65
    ctx->pc = 0x196f60u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 101));
    // 0x196f64: 0x1064013d  beq         $v1, $a0, . + 4 + (0x13D << 2)
    ctx->pc = 0x196F64u;
    {
        const bool branch_taken_0x196f64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f64) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x196F6Cu;
    // 0x196f6c: 0x24040064  addiu       $a0, $zero, 0x64
    ctx->pc = 0x196f6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x196f70: 0x106400f1  beq         $v1, $a0, . + 4 + (0xF1 << 2)
    ctx->pc = 0x196F70u;
    {
        const bool branch_taken_0x196f70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f70) {
            ctx->pc = 0x197338u;
            goto label_197338;
        }
    }
    ctx->pc = 0x196F78u;
    // 0x196f78: 0x24040063  addiu       $a0, $zero, 0x63
    ctx->pc = 0x196f78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x196f7c: 0x106400e9  beq         $v1, $a0, . + 4 + (0xE9 << 2)
    ctx->pc = 0x196F7Cu;
    {
        const bool branch_taken_0x196f7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f7c) {
            ctx->pc = 0x197324u;
            goto label_197324;
        }
    }
    ctx->pc = 0x196F84u;
    // 0x196f84: 0x24040062  addiu       $a0, $zero, 0x62
    ctx->pc = 0x196f84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 98));
    // 0x196f88: 0x106400de  beq         $v1, $a0, . + 4 + (0xDE << 2)
    ctx->pc = 0x196F88u;
    {
        const bool branch_taken_0x196f88 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f88) {
            ctx->pc = 0x197304u;
            goto label_197304;
        }
    }
    ctx->pc = 0x196F90u;
    // 0x196f90: 0x24040061  addiu       $a0, $zero, 0x61
    ctx->pc = 0x196f90u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 97));
    // 0x196f94: 0x106400d3  beq         $v1, $a0, . + 4 + (0xD3 << 2)
    ctx->pc = 0x196F94u;
    {
        const bool branch_taken_0x196f94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196f94) {
            ctx->pc = 0x1972E4u;
            goto label_1972e4;
        }
    }
    ctx->pc = 0x196F9Cu;
    // 0x196f9c: 0x24040060  addiu       $a0, $zero, 0x60
    ctx->pc = 0x196f9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 96));
    // 0x196fa0: 0x106400cd  beq         $v1, $a0, . + 4 + (0xCD << 2)
    ctx->pc = 0x196FA0u;
    {
        const bool branch_taken_0x196fa0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fa0) {
            ctx->pc = 0x1972D8u;
            goto label_1972d8;
        }
    }
    ctx->pc = 0x196FA8u;
    // 0x196fa8: 0x2404005f  addiu       $a0, $zero, 0x5F
    ctx->pc = 0x196fa8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 95));
    // 0x196fac: 0x106400a0  beq         $v1, $a0, . + 4 + (0xA0 << 2)
    ctx->pc = 0x196FACu;
    {
        const bool branch_taken_0x196fac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fac) {
            ctx->pc = 0x197230u;
            goto label_197230;
        }
    }
    ctx->pc = 0x196FB4u;
    // 0x196fb4: 0x2404005e  addiu       $a0, $zero, 0x5E
    ctx->pc = 0x196fb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 94));
    // 0x196fb8: 0x1064009a  beq         $v1, $a0, . + 4 + (0x9A << 2)
    ctx->pc = 0x196FB8u;
    {
        const bool branch_taken_0x196fb8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fb8) {
            ctx->pc = 0x197224u;
            goto label_197224;
        }
    }
    ctx->pc = 0x196FC0u;
    // 0x196fc0: 0x2404005d  addiu       $a0, $zero, 0x5D
    ctx->pc = 0x196fc0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 93));
    // 0x196fc4: 0x10640092  beq         $v1, $a0, . + 4 + (0x92 << 2)
    ctx->pc = 0x196FC4u;
    {
        const bool branch_taken_0x196fc4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fc4) {
            ctx->pc = 0x197210u;
            goto label_197210;
        }
    }
    ctx->pc = 0x196FCCu;
    // 0x196fcc: 0x2404005c  addiu       $a0, $zero, 0x5C
    ctx->pc = 0x196fccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 92));
    // 0x196fd0: 0x10640086  beq         $v1, $a0, . + 4 + (0x86 << 2)
    ctx->pc = 0x196FD0u;
    {
        const bool branch_taken_0x196fd0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x196FD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x196FD0u;
            // 0x196fd4: 0x2464ffa6  addiu       $a0, $v1, -0x5A (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967206));
        ctx->in_delay_slot = false;
        if (branch_taken_0x196fd0) {
            ctx->pc = 0x1971ECu;
            goto label_1971ec;
        }
    }
    ctx->pc = 0x196FD8u;
    // 0x196fd8: 0x2404005b  addiu       $a0, $zero, 0x5B
    ctx->pc = 0x196fd8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 91));
    // 0x196fdc: 0x10640082  beq         $v1, $a0, . + 4 + (0x82 << 2)
    ctx->pc = 0x196FDCu;
    {
        const bool branch_taken_0x196fdc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fdc) {
            ctx->pc = 0x1971E8u;
            goto label_1971e8;
        }
    }
    ctx->pc = 0x196FE4u;
    // 0x196fe4: 0x2404005a  addiu       $a0, $zero, 0x5A
    ctx->pc = 0x196fe4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x196fe8: 0x1064007f  beq         $v1, $a0, . + 4 + (0x7F << 2)
    ctx->pc = 0x196FE8u;
    {
        const bool branch_taken_0x196fe8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196fe8) {
            ctx->pc = 0x1971E8u;
            goto label_1971e8;
        }
    }
    ctx->pc = 0x196FF0u;
    // 0x196ff0: 0x24040015  addiu       $a0, $zero, 0x15
    ctx->pc = 0x196ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
    // 0x196ff4: 0x10640070  beq         $v1, $a0, . + 4 + (0x70 << 2)
    ctx->pc = 0x196FF4u;
    {
        const bool branch_taken_0x196ff4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x196ff4) {
            ctx->pc = 0x1971B8u;
            goto label_1971b8;
        }
    }
    ctx->pc = 0x196FFCu;
    // 0x196ffc: 0x24040014  addiu       $a0, $zero, 0x14
    ctx->pc = 0x196ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x197000: 0x10640069  beq         $v1, $a0, . + 4 + (0x69 << 2)
    ctx->pc = 0x197000u;
    {
        const bool branch_taken_0x197000 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197000) {
            ctx->pc = 0x1971A8u;
            goto label_1971a8;
        }
    }
    ctx->pc = 0x197008u;
    // 0x197008: 0x24040013  addiu       $a0, $zero, 0x13
    ctx->pc = 0x197008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x19700c: 0x10640113  beq         $v1, $a0, . + 4 + (0x113 << 2)
    ctx->pc = 0x19700Cu;
    {
        const bool branch_taken_0x19700c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19700c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197014u;
    // 0x197014: 0x24040012  addiu       $a0, $zero, 0x12
    ctx->pc = 0x197014u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x197018: 0x10640059  beq         $v1, $a0, . + 4 + (0x59 << 2)
    ctx->pc = 0x197018u;
    {
        const bool branch_taken_0x197018 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197018) {
            ctx->pc = 0x197180u;
            goto label_197180;
        }
    }
    ctx->pc = 0x197020u;
    // 0x197020: 0x24040011  addiu       $a0, $zero, 0x11
    ctx->pc = 0x197020u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17));
    // 0x197024: 0x1064010d  beq         $v1, $a0, . + 4 + (0x10D << 2)
    ctx->pc = 0x197024u;
    {
        const bool branch_taken_0x197024 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197024) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19702Cu;
    // 0x19702c: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x19702cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x197030: 0x1064010a  beq         $v1, $a0, . + 4 + (0x10A << 2)
    ctx->pc = 0x197030u;
    {
        const bool branch_taken_0x197030 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197030) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197038u;
    // 0x197038: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x197038u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x19703c: 0x1064004d  beq         $v1, $a0, . + 4 + (0x4D << 2)
    ctx->pc = 0x19703Cu;
    {
        const bool branch_taken_0x19703c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19703c) {
            ctx->pc = 0x197174u;
            goto label_197174;
        }
    }
    ctx->pc = 0x197044u;
    // 0x197044: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x197044u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x197048: 0x10640047  beq         $v1, $a0, . + 4 + (0x47 << 2)
    ctx->pc = 0x197048u;
    {
        const bool branch_taken_0x197048 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197048) {
            ctx->pc = 0x197168u;
            goto label_197168;
        }
    }
    ctx->pc = 0x197050u;
    // 0x197050: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x197050u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x197054: 0x10640040  beq         $v1, $a0, . + 4 + (0x40 << 2)
    ctx->pc = 0x197054u;
    {
        const bool branch_taken_0x197054 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197054) {
            ctx->pc = 0x197158u;
            goto label_197158;
        }
    }
    ctx->pc = 0x19705Cu;
    // 0x19705c: 0x2404000c  addiu       $a0, $zero, 0xC
    ctx->pc = 0x19705cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x197060: 0x10640035  beq         $v1, $a0, . + 4 + (0x35 << 2)
    ctx->pc = 0x197060u;
    {
        const bool branch_taken_0x197060 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197060) {
            ctx->pc = 0x197138u;
            goto label_197138;
        }
    }
    ctx->pc = 0x197068u;
    // 0x197068: 0x2404000b  addiu       $a0, $zero, 0xB
    ctx->pc = 0x197068u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x19706c: 0x106400fb  beq         $v1, $a0, . + 4 + (0xFB << 2)
    ctx->pc = 0x19706Cu;
    {
        const bool branch_taken_0x19706c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19706c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197074u;
    // 0x197074: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x197074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x197078: 0x106400f8  beq         $v1, $a0, . + 4 + (0xF8 << 2)
    ctx->pc = 0x197078u;
    {
        const bool branch_taken_0x197078 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197078) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197080u;
    // 0x197080: 0x24040009  addiu       $a0, $zero, 0x9
    ctx->pc = 0x197080u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x197084: 0x106400f5  beq         $v1, $a0, . + 4 + (0xF5 << 2)
    ctx->pc = 0x197084u;
    {
        const bool branch_taken_0x197084 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197084) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19708Cu;
    // 0x19708c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x19708cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x197090: 0x106400f2  beq         $v1, $a0, . + 4 + (0xF2 << 2)
    ctx->pc = 0x197090u;
    {
        const bool branch_taken_0x197090 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x197090) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197098u;
    // 0x197098: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x197098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x19709c: 0x1064001f  beq         $v1, $a0, . + 4 + (0x1F << 2)
    ctx->pc = 0x19709Cu;
    {
        const bool branch_taken_0x19709c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x19709c) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970A4u;
    // 0x1970a4: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x1970a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1970a8: 0x1064001c  beq         $v1, $a0, . + 4 + (0x1C << 2)
    ctx->pc = 0x1970A8u;
    {
        const bool branch_taken_0x1970a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970a8) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970B0u;
    // 0x1970b0: 0x24040005  addiu       $a0, $zero, 0x5
    ctx->pc = 0x1970b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1970b4: 0x10640019  beq         $v1, $a0, . + 4 + (0x19 << 2)
    ctx->pc = 0x1970B4u;
    {
        const bool branch_taken_0x1970b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970b4) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970BCu;
    // 0x1970bc: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1970bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1970c0: 0x10640016  beq         $v1, $a0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1970C0u;
    {
        const bool branch_taken_0x1970c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970c0) {
            ctx->pc = 0x19711Cu;
            goto label_19711c;
        }
    }
    ctx->pc = 0x1970C8u;
    // 0x1970c8: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1970c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1970cc: 0x1064000f  beq         $v1, $a0, . + 4 + (0xF << 2)
    ctx->pc = 0x1970CCu;
    {
        const bool branch_taken_0x1970cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970cc) {
            ctx->pc = 0x19710Cu;
            goto label_19710c;
        }
    }
    ctx->pc = 0x1970D4u;
    // 0x1970d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1970d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1970d8: 0x10640008  beq         $v1, $a0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1970D8u;
    {
        const bool branch_taken_0x1970d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970d8) {
            ctx->pc = 0x1970FCu;
            goto label_1970fc;
        }
    }
    ctx->pc = 0x1970E0u;
    // 0x1970e0: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x1970e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1970e4: 0x106400dd  beq         $v1, $a0, . + 4 + (0xDD << 2)
    ctx->pc = 0x1970E4u;
    {
        const bool branch_taken_0x1970e4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1970e4) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1970ECu;
    // 0x1970ec: 0x106000db  beqz        $v1, . + 4 + (0xDB << 2)
    ctx->pc = 0x1970ECu;
    {
        const bool branch_taken_0x1970ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1970ec) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1970F4u;
    // 0x1970f4: 0x100000da  b           . + 4 + (0xDA << 2)
    ctx->pc = 0x1970F4u;
    {
        const bool branch_taken_0x1970f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1970F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1970F4u;
            // 0x1970f8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1970f4) {
            ctx->pc = 0x197460u;
            goto label_197460;
        }
    }
    ctx->pc = 0x1970FCu;
label_1970fc:
    // 0x1970fc: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1970fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197100: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x197100u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197104: 0x100000d5  b           . + 4 + (0xD5 << 2)
    ctx->pc = 0x197104u;
    {
        const bool branch_taken_0x197104 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197104u;
            // 0x197108: 0x30420f00  andi        $v0, $v0, 0xF00 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3840);
        ctx->in_delay_slot = false;
        if (branch_taken_0x197104) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19710Cu;
label_19710c:
    // 0x19710c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19710cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197110: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x197110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197114: 0x100000d1  b           . + 4 + (0xD1 << 2)
    ctx->pc = 0x197114u;
    {
        const bool branch_taken_0x197114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197114u;
            // 0x197118: 0x3042001c  andi        $v0, $v0, 0x1C (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)28);
        ctx->in_delay_slot = false;
        if (branch_taken_0x197114) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19711Cu;
label_19711c:
    // 0x19711c: 0x2463fffc  addiu       $v1, $v1, -0x4
    ctx->pc = 0x19711cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967292));
    // 0x197120: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x197120u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x197124: 0x24424e60  addiu       $v0, $v0, 0x4E60
    ctx->pc = 0x197124u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 20064));
    // 0x197128: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x197128u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x19712c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x19712cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x197130: 0x100000ca  b           . + 4 + (0xCA << 2)
    ctx->pc = 0x197130u;
    {
        const bool branch_taken_0x197130 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197130u;
            // 0x197134: 0x8c420000  lw          $v0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197130) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197138u;
label_197138:
    // 0x197138: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197138u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19713c: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x19713cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x197140: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x197140u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197144: 0x30840080  andi        $a0, $a0, 0x80
    ctx->pc = 0x197144u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)128);
    // 0x197148: 0x148300c4  bne         $a0, $v1, . + 4 + (0xC4 << 2)
    ctx->pc = 0x197148u;
    {
        const bool branch_taken_0x197148 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x197148) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197150u;
    // 0x197150: 0x100000c2  b           . + 4 + (0xC2 << 2)
    ctx->pc = 0x197150u;
    {
        const bool branch_taken_0x197150 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197150u;
            // 0x197154: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197150) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197158u;
label_197158:
    // 0x197158: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197158u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19715c: 0x8c22fe68  lw          $v0, -0x198($at)
    ctx->pc = 0x19715cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197160: 0x100000be  b           . + 4 + (0xBE << 2)
    ctx->pc = 0x197160u;
    {
        const bool branch_taken_0x197160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197160u;
            // 0x197164: 0x30420c00  andi        $v0, $v0, 0xC00 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3072);
        ctx->in_delay_slot = false;
        if (branch_taken_0x197160) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197168u;
label_197168:
    // 0x197168: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197168u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19716c: 0x100000bb  b           . + 4 + (0xBB << 2)
    ctx->pc = 0x19716Cu;
    {
        const bool branch_taken_0x19716c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19716Cu;
            // 0x197170: 0x8c22fe30  lw          $v0, -0x1D0($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966832)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19716c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197174u;
label_197174:
    // 0x197174: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197174u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197178: 0x100000b8  b           . + 4 + (0xB8 << 2)
    ctx->pc = 0x197178u;
    {
        const bool branch_taken_0x197178 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19717Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197178u;
            // 0x19717c: 0x8c22fe38  lw          $v0, -0x1C8($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966840)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197178) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197180u;
label_197180:
    // 0x197180: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197180u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197184: 0x3c030001  lui         $v1, 0x1
    ctx->pc = 0x197184u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)1 << 16));
    // 0x197188: 0x8c25fe70  lw          $a1, -0x190($at)
    ctx->pc = 0x197188u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x19718c: 0x34648000  ori         $a0, $v1, 0x8000
    ctx->pc = 0x19718cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)32768);
    // 0x197190: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x197190u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x197194: 0xa42024  and         $a0, $a1, $a0
    ctx->pc = 0x197194u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x197198: 0x148300b0  bne         $a0, $v1, . + 4 + (0xB0 << 2)
    ctx->pc = 0x197198u;
    {
        const bool branch_taken_0x197198 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x197198) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971A0u;
    // 0x1971a0: 0x100000ae  b           . + 4 + (0xAE << 2)
    ctx->pc = 0x1971A0u;
    {
        const bool branch_taken_0x1971a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1971A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971A0u;
            // 0x1971a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971a0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971A8u;
label_1971a8:
    // 0x1971a8: 0xc065d20  jal         func_197480
    ctx->pc = 0x1971A8u;
    SET_GPR_U32(ctx, 31, 0x1971B0u);
    ctx->pc = 0x197480u;
    {
        auto targetFn = runtime->lookupFunction(0x197480u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1971B0u; }
        if (ctx->pc != 0x1971B0u) { return; }
    }
    ctx->pc = 0x1971B0u;
label_1971b0:
    // 0x1971b0: 0x100000aa  b           . + 4 + (0xAA << 2)
    ctx->pc = 0x1971B0u;
    {
        const bool branch_taken_0x1971b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1971b0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971B8u;
label_1971b8:
    // 0x1971b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1971b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1971bc: 0x8c22fe70  lw          $v0, -0x190($at)
    ctx->pc = 0x1971bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x1971c0: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x1971c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
    // 0x1971c4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1971C4u;
    {
        const bool branch_taken_0x1971c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1971C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971C4u;
            // 0x1971c8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971c4) {
            ctx->pc = 0x1971D8u;
            goto label_1971d8;
        }
    }
    ctx->pc = 0x1971CCu;
    // 0x1971cc: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1971CCu;
    {
        const bool branch_taken_0x1971cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1971D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971CCu;
            // 0x1971d0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971cc) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971D4u;
    // 0x1971d4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1971d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1971d8:
    // 0x1971d8: 0x144300a0  bne         $v0, $v1, . + 4 + (0xA0 << 2)
    ctx->pc = 0x1971D8u;
    {
        const bool branch_taken_0x1971d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1971d8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971E0u;
    // 0x1971e0: 0x1000009e  b           . + 4 + (0x9E << 2)
    ctx->pc = 0x1971E0u;
    {
        const bool branch_taken_0x1971e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1971E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1971E0u;
            // 0x1971e4: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1971e0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1971E8u;
label_1971e8:
    // 0x1971e8: 0x2464ffa6  addiu       $a0, $v1, -0x5A
    ctx->pc = 0x1971e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967206));
label_1971ec:
    // 0x1971ec: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x1971ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1971f0: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1971f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1971f4: 0x24424200  addiu       $v0, $v0, 0x4200
    ctx->pc = 0x1971f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16896));
    // 0x1971f8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1971f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1971fc: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1971fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x197200: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x197200u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x197204: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x197204u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x197208: 0x10000094  b           . + 4 + (0x94 << 2)
    ctx->pc = 0x197208u;
    {
        const bool branch_taken_0x197208 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19720Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197208u;
            // 0x19720c: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197208) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197210u;
label_197210:
    // 0x197210: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197210u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197214: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x197214u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x197218: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x197218u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x19721c: 0x1000008f  b           . + 4 + (0x8F << 2)
    ctx->pc = 0x19721Cu;
    {
        const bool branch_taken_0x19721c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19721Cu;
            // 0x197220: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19721c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197224u;
label_197224:
    // 0x197224: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197224u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197228: 0x1000008c  b           . + 4 + (0x8C << 2)
    ctx->pc = 0x197228u;
    {
        const bool branch_taken_0x197228 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19722Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197228u;
            // 0x19722c: 0x9022fe68  lbu         $v0, -0x198($at) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294966888)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197228) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197230u;
label_197230:
    // 0x197230: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197230u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197234: 0x3c030038  lui         $v1, 0x38
    ctx->pc = 0x197234u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)56 << 16));
    // 0x197238: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x197238u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x19723c: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x19723cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x197240: 0x10830023  beq         $a0, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x197240u;
    {
        const bool branch_taken_0x197240 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197240) {
            ctx->pc = 0x1972D0u;
            goto label_1972d0;
        }
    }
    ctx->pc = 0x197248u;
    // 0x197248: 0x3c030030  lui         $v1, 0x30
    ctx->pc = 0x197248u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)48 << 16));
    // 0x19724c: 0x1083001e  beq         $a0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x19724Cu;
    {
        const bool branch_taken_0x19724c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x19724c) {
            ctx->pc = 0x1972C8u;
            goto label_1972c8;
        }
    }
    ctx->pc = 0x197254u;
    // 0x197254: 0x3c030028  lui         $v1, 0x28
    ctx->pc = 0x197254u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)40 << 16));
    // 0x197258: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x197258u;
    {
        const bool branch_taken_0x197258 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197258) {
            ctx->pc = 0x1972C0u;
            goto label_1972c0;
        }
    }
    ctx->pc = 0x197260u;
    // 0x197260: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x197260u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x197264: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x197264u;
    {
        const bool branch_taken_0x197264 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197264) {
            ctx->pc = 0x1972B8u;
            goto label_1972b8;
        }
    }
    ctx->pc = 0x19726Cu;
    // 0x19726c: 0x3c030018  lui         $v1, 0x18
    ctx->pc = 0x19726cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)24 << 16));
    // 0x197270: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x197270u;
    {
        const bool branch_taken_0x197270 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197270) {
            ctx->pc = 0x1972B0u;
            goto label_1972b0;
        }
    }
    ctx->pc = 0x197278u;
    // 0x197278: 0x3c030010  lui         $v1, 0x10
    ctx->pc = 0x197278u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)16 << 16));
    // 0x19727c: 0x1083000a  beq         $a0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x19727Cu;
    {
        const bool branch_taken_0x19727c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x19727c) {
            ctx->pc = 0x1972A8u;
            goto label_1972a8;
        }
    }
    ctx->pc = 0x197284u;
    // 0x197284: 0x3c030008  lui         $v1, 0x8
    ctx->pc = 0x197284u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)8 << 16));
    // 0x197288: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x197288u;
    {
        const bool branch_taken_0x197288 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197288) {
            ctx->pc = 0x1972A0u;
            goto label_1972a0;
        }
    }
    ctx->pc = 0x197290u;
    // 0x197290: 0x10800072  beqz        $a0, . + 4 + (0x72 << 2)
    ctx->pc = 0x197290u;
    {
        const bool branch_taken_0x197290 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x197290) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197298u;
    // 0x197298: 0x10000070  b           . + 4 + (0x70 << 2)
    ctx->pc = 0x197298u;
    {
        const bool branch_taken_0x197298 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197298) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972A0u;
label_1972a0:
    // 0x1972a0: 0x1000006e  b           . + 4 + (0x6E << 2)
    ctx->pc = 0x1972A0u;
    {
        const bool branch_taken_0x1972a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972A0u;
            // 0x1972a4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972a0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972A8u;
label_1972a8:
    // 0x1972a8: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1972A8u;
    {
        const bool branch_taken_0x1972a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972A8u;
            // 0x1972ac: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972a8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972B0u;
label_1972b0:
    // 0x1972b0: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x1972B0u;
    {
        const bool branch_taken_0x1972b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972B0u;
            // 0x1972b4: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972b0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972B8u;
label_1972b8:
    // 0x1972b8: 0x10000068  b           . + 4 + (0x68 << 2)
    ctx->pc = 0x1972B8u;
    {
        const bool branch_taken_0x1972b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972B8u;
            // 0x1972bc: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972b8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972C0u;
label_1972c0:
    // 0x1972c0: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1972C0u;
    {
        const bool branch_taken_0x1972c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972C0u;
            // 0x1972c4: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972c0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972C8u;
label_1972c8:
    // 0x1972c8: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1972C8u;
    {
        const bool branch_taken_0x1972c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972C8u;
            // 0x1972cc: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972c8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972D0u;
label_1972d0:
    // 0x1972d0: 0x10000062  b           . + 4 + (0x62 << 2)
    ctx->pc = 0x1972D0u;
    {
        const bool branch_taken_0x1972d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972D0u;
            // 0x1972d4: 0x24020007  addiu       $v0, $zero, 0x7 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972d0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972D8u;
label_1972d8:
    // 0x1972d8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1972d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1972dc: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x1972DCu;
    {
        const bool branch_taken_0x1972dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1972E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972DCu;
            // 0x1972e0: 0x8c22fe20  lw          $v0, -0x1E0($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966816)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972dc) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972E4u;
label_1972e4:
    // 0x1972e4: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1972e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1972e8: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1972e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1972ec: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x1972ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1972f0: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x1972f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x1972f4: 0x14640059  bne         $v1, $a0, . + 4 + (0x59 << 2)
    ctx->pc = 0x1972F4u;
    {
        const bool branch_taken_0x1972f4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1972f4) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1972FCu;
    // 0x1972fc: 0x10000057  b           . + 4 + (0x57 << 2)
    ctx->pc = 0x1972FCu;
    {
        const bool branch_taken_0x1972fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1972FCu;
            // 0x197300: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1972fc) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197304u;
label_197304:
    // 0x197304: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197304u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197308: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x197308u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x19730c: 0x8c24fe70  lw          $a0, -0x190($at)
    ctx->pc = 0x19730cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197310: 0x30844000  andi        $a0, $a0, 0x4000
    ctx->pc = 0x197310u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)16384);
    // 0x197314: 0x14830051  bne         $a0, $v1, . + 4 + (0x51 << 2)
    ctx->pc = 0x197314u;
    {
        const bool branch_taken_0x197314 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x197314) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19731Cu;
    // 0x19731c: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x19731Cu;
    {
        const bool branch_taken_0x19731c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19731Cu;
            // 0x197320: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19731c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197324u;
label_197324:
    // 0x197324: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197324u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197328: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x197328u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x19732c: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x19732cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197330: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x197330u;
    {
        const bool branch_taken_0x197330 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197334u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197330u;
            // 0x197334: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197330) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197338u;
label_197338:
    // 0x197338: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197338u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19733c: 0x3c020006  lui         $v0, 0x6
    ctx->pc = 0x19733cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)6 << 16));
    // 0x197340: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x197340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197344: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x197344u;
    {
        const bool branch_taken_0x197344 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197344u;
            // 0x197348: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197344) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19734Cu;
label_19734c:
    // 0x19734c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19734cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197350: 0x3c040002  lui         $a0, 0x2
    ctx->pc = 0x197350u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)2 << 16));
    // 0x197354: 0x8c23fe70  lw          $v1, -0x190($at)
    ctx->pc = 0x197354u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
    // 0x197358: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x197358u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x19735c: 0x1464003f  bne         $v1, $a0, . + 4 + (0x3F << 2)
    ctx->pc = 0x19735Cu;
    {
        const bool branch_taken_0x19735c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x19735c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197364u;
    // 0x197364: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x197364u;
    {
        const bool branch_taken_0x197364 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197364u;
            // 0x197368: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197364) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x19736Cu;
label_19736c:
    // 0x19736c: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19736cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x197370: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x197370u;
    {
        const bool branch_taken_0x197370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197370u;
            // 0x197374: 0x8c224e70  lw          $v0, 0x4E70($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20080)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197370) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197378u;
label_197378:
    // 0x197378: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x197378u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19737c: 0x10000037  b           . + 4 + (0x37 << 2)
    ctx->pc = 0x19737Cu;
    {
        const bool branch_taken_0x19737c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19737Cu;
            // 0x197380: 0x8c224e68  lw          $v0, 0x4E68($at) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 20072)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19737c) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197384u;
label_197384:
    // 0x197384: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197384u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x197388: 0x3c0200c0  lui         $v0, 0xC0
    ctx->pc = 0x197388u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)192 << 16));
    // 0x19738c: 0x8c23fe68  lw          $v1, -0x198($at)
    ctx->pc = 0x19738cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x197390: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x197390u;
    {
        const bool branch_taken_0x197390 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197390u;
            // 0x197394: 0x621024  and         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197390) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197398u;
label_197398:
    // 0x197398: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x197398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19739c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x19739cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1973a0: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x1973a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1973a4: 0x30848000  andi        $a0, $a0, 0x8000
    ctx->pc = 0x1973a4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x1973a8: 0x1483002c  bne         $a0, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1973A8u;
    {
        const bool branch_taken_0x1973a8 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        if (branch_taken_0x1973a8) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1973B0u;
    // 0x1973b0: 0x1000002a  b           . + 4 + (0x2A << 2)
    ctx->pc = 0x1973B0u;
    {
        const bool branch_taken_0x1973b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1973B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1973B0u;
            // 0x1973b4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1973b0) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x1973B8u;
label_1973b8:
    // 0x1973b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1973b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1973bc: 0x24037000  addiu       $v1, $zero, 0x7000
    ctx->pc = 0x1973bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 28672));
    // 0x1973c0: 0x8c24fe68  lw          $a0, -0x198($at)
    ctx->pc = 0x1973c0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294966888)));
    // 0x1973c4: 0x30847000  andi        $a0, $a0, 0x7000
    ctx->pc = 0x1973c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)28672);
    // 0x1973c8: 0x10830023  beq         $a0, $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x1973C8u;
    {
        const bool branch_taken_0x1973c8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973c8) {
            ctx->pc = 0x197458u;
            goto label_197458;
        }
    }
    ctx->pc = 0x1973D0u;
    // 0x1973d0: 0x24036000  addiu       $v1, $zero, 0x6000
    ctx->pc = 0x1973d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24576));
    // 0x1973d4: 0x1083001e  beq         $a0, $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1973D4u;
    {
        const bool branch_taken_0x1973d4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973d4) {
            ctx->pc = 0x197450u;
            goto label_197450;
        }
    }
    ctx->pc = 0x1973DCu;
    // 0x1973dc: 0x24035000  addiu       $v1, $zero, 0x5000
    ctx->pc = 0x1973dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20480));
    // 0x1973e0: 0x10830019  beq         $a0, $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1973E0u;
    {
        const bool branch_taken_0x1973e0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973e0) {
            ctx->pc = 0x197448u;
            goto label_197448;
        }
    }
    ctx->pc = 0x1973E8u;
    // 0x1973e8: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x1973e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x1973ec: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1973ECu;
    {
        const bool branch_taken_0x1973ec = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973ec) {
            ctx->pc = 0x197440u;
            goto label_197440;
        }
    }
    ctx->pc = 0x1973F4u;
    // 0x1973f4: 0x24033000  addiu       $v1, $zero, 0x3000
    ctx->pc = 0x1973f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12288));
    // 0x1973f8: 0x1083000f  beq         $a0, $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1973F8u;
    {
        const bool branch_taken_0x1973f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1973f8) {
            ctx->pc = 0x197438u;
            goto label_197438;
        }
    }
    ctx->pc = 0x197400u;
    // 0x197400: 0x24032000  addiu       $v1, $zero, 0x2000
    ctx->pc = 0x197400u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x197404: 0x1083000a  beq         $a0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x197404u;
    {
        const bool branch_taken_0x197404 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197404) {
            ctx->pc = 0x197430u;
            goto label_197430;
        }
    }
    ctx->pc = 0x19740Cu;
    // 0x19740c: 0x24031000  addiu       $v1, $zero, 0x1000
    ctx->pc = 0x19740cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4096));
    // 0x197410: 0x10830005  beq         $a0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x197410u;
    {
        const bool branch_taken_0x197410 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x197410) {
            ctx->pc = 0x197428u;
            goto label_197428;
        }
    }
    ctx->pc = 0x197418u;
    // 0x197418: 0x10800010  beqz        $a0, . + 4 + (0x10 << 2)
    ctx->pc = 0x197418u;
    {
        const bool branch_taken_0x197418 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x197418) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197420u;
    // 0x197420: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x197420u;
    {
        const bool branch_taken_0x197420 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x197420) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197428u;
label_197428:
    // 0x197428: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x197428u;
    {
        const bool branch_taken_0x197428 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19742Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197428u;
            // 0x19742c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197428) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197430u;
label_197430:
    // 0x197430: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x197430u;
    {
        const bool branch_taken_0x197430 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197430u;
            // 0x197434: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197430) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197438u;
label_197438:
    // 0x197438: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x197438u;
    {
        const bool branch_taken_0x197438 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19743Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197438u;
            // 0x19743c: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197438) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197440u;
label_197440:
    // 0x197440: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x197440u;
    {
        const bool branch_taken_0x197440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197440u;
            // 0x197444: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197440) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197448u;
label_197448:
    // 0x197448: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x197448u;
    {
        const bool branch_taken_0x197448 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19744Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197448u;
            // 0x19744c: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197448) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197450u;
label_197450:
    // 0x197450: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x197450u;
    {
        const bool branch_taken_0x197450 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197454u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197450u;
            // 0x197454: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197450) {
            ctx->pc = 0x19745Cu;
            goto label_19745c;
        }
    }
    ctx->pc = 0x197458u;
label_197458:
    // 0x197458: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x197458u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
label_19745c:
    // 0x19745c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19745cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_197460:
    // 0x197460: 0x3e00008  jr          $ra
    ctx->pc = 0x197460u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197460u;
            // 0x197464: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x196060u: goto label_196060;
            case 0x196084u: goto label_196084;
            case 0x19608Cu: goto label_19608c;
            case 0x196090u: goto label_196090;
            case 0x1960CCu: goto label_1960cc;
            case 0x1960F0u: goto label_1960f0;
            case 0x196130u: goto label_196130;
            case 0x196158u: goto label_196158;
            case 0x1961B8u: goto label_1961b8;
            case 0x1961BCu: goto label_1961bc;
            case 0x196378u: goto label_196378;
            case 0x1963A8u: goto label_1963a8;
            case 0x19642Cu: goto label_19642c;
            case 0x196440u: goto label_196440;
            case 0x196454u: goto label_196454;
            case 0x196468u: goto label_196468;
            case 0x19647Cu: goto label_19647c;
            case 0x196490u: goto label_196490;
            case 0x1964A4u: goto label_1964a4;
            case 0x1964B8u: goto label_1964b8;
            case 0x1964CCu: goto label_1964cc;
            case 0x196520u: goto label_196520;
            case 0x196538u: goto label_196538;
            case 0x196554u: goto label_196554;
            case 0x19655Cu: goto label_19655c;
            case 0x196568u: goto label_196568;
            case 0x196588u: goto label_196588;
            case 0x1965C0u: goto label_1965c0;
            case 0x196604u: goto label_196604;
            case 0x19660Cu: goto label_19660c;
            case 0x196650u: goto label_196650;
            case 0x196658u: goto label_196658;
            case 0x1966A4u: goto label_1966a4;
            case 0x1966ACu: goto label_1966ac;
            case 0x1966DCu: goto label_1966dc;
            case 0x1966F4u: goto label_1966f4;
            case 0x196724u: goto label_196724;
            case 0x196740u: goto label_196740;
            case 0x196770u: goto label_196770;
            case 0x19678Cu: goto label_19678c;
            case 0x1967C4u: goto label_1967c4;
            case 0x1967DCu: goto label_1967dc;
            case 0x1967F0u: goto label_1967f0;
            case 0x196808u: goto label_196808;
            case 0x196814u: goto label_196814;
            case 0x19681Cu: goto label_19681c;
            case 0x196838u: goto label_196838;
            case 0x196840u: goto label_196840;
            case 0x196850u: goto label_196850;
            case 0x196860u: goto label_196860;
            case 0x19689Cu: goto label_19689c;
            case 0x1968A4u: goto label_1968a4;
            case 0x1968ACu: goto label_1968ac;
            case 0x1968E8u: goto label_1968e8;
            case 0x1968F8u: goto label_1968f8;
            case 0x196920u: goto label_196920;
            case 0x196930u: goto label_196930;
            case 0x196968u: goto label_196968;
            case 0x196984u: goto label_196984;
            case 0x19698Cu: goto label_19698c;
            case 0x1969B0u: goto label_1969b0;
            case 0x1969B8u: goto label_1969b8;
            case 0x1969C8u: goto label_1969c8;
            case 0x1969F0u: goto label_1969f0;
            case 0x196A20u: goto label_196a20;
            case 0x196A4Cu: goto label_196a4c;
            case 0x196A58u: goto label_196a58;
            case 0x196A64u: goto label_196a64;
            case 0x196A70u: goto label_196a70;
            case 0x196A7Cu: goto label_196a7c;
            case 0x196A84u: goto label_196a84;
            case 0x196A90u: goto label_196a90;
            case 0x196A9Cu: goto label_196a9c;
            case 0x196AA4u: goto label_196aa4;
            case 0x196AF4u: goto label_196af4;
            case 0x196AFCu: goto label_196afc;
            case 0x196B24u: goto label_196b24;
            case 0x196B2Cu: goto label_196b2c;
            case 0x196B60u: goto label_196b60;
            case 0x196B98u: goto label_196b98;
            case 0x196BA8u: goto label_196ba8;
            case 0x196BB0u: goto label_196bb0;
            case 0x196BF0u: goto label_196bf0;
            case 0x196C30u: goto label_196c30;
            case 0x196C54u: goto label_196c54;
            case 0x196C70u: goto label_196c70;
            case 0x196CA0u: goto label_196ca0;
            case 0x196CBCu: goto label_196cbc;
            case 0x196CECu: goto label_196cec;
            case 0x196D08u: goto label_196d08;
            case 0x196D38u: goto label_196d38;
            case 0x196D54u: goto label_196d54;
            case 0x196D74u: goto label_196d74;
            case 0x196D84u: goto label_196d84;
            case 0x196D94u: goto label_196d94;
            case 0x196DD4u: goto label_196dd4;
            case 0x196DE8u: goto label_196de8;
            case 0x196E3Cu: goto label_196e3c;
            case 0x196E44u: goto label_196e44;
            case 0x196E70u: goto label_196e70;
            case 0x196E78u: goto label_196e78;
            case 0x196E84u: goto label_196e84;
            case 0x196E90u: goto label_196e90;
            case 0x196E98u: goto label_196e98;
            case 0x196EE0u: goto label_196ee0;
            case 0x196EE4u: goto label_196ee4;
            case 0x196EE8u: goto label_196ee8;
            case 0x1970FCu: goto label_1970fc;
            case 0x19710Cu: goto label_19710c;
            case 0x19711Cu: goto label_19711c;
            case 0x197138u: goto label_197138;
            case 0x197158u: goto label_197158;
            case 0x197168u: goto label_197168;
            case 0x197174u: goto label_197174;
            case 0x197180u: goto label_197180;
            case 0x1971A8u: goto label_1971a8;
            case 0x1971B0u: goto label_1971b0;
            case 0x1971B8u: goto label_1971b8;
            case 0x1971D8u: goto label_1971d8;
            case 0x1971E8u: goto label_1971e8;
            case 0x1971ECu: goto label_1971ec;
            case 0x197210u: goto label_197210;
            case 0x197224u: goto label_197224;
            case 0x197230u: goto label_197230;
            case 0x1972A0u: goto label_1972a0;
            case 0x1972A8u: goto label_1972a8;
            case 0x1972B0u: goto label_1972b0;
            case 0x1972B8u: goto label_1972b8;
            case 0x1972C0u: goto label_1972c0;
            case 0x1972C8u: goto label_1972c8;
            case 0x1972D0u: goto label_1972d0;
            case 0x1972D8u: goto label_1972d8;
            case 0x1972E4u: goto label_1972e4;
            case 0x197304u: goto label_197304;
            case 0x197324u: goto label_197324;
            case 0x197338u: goto label_197338;
            case 0x19734Cu: goto label_19734c;
            case 0x19736Cu: goto label_19736c;
            case 0x197378u: goto label_197378;
            case 0x197384u: goto label_197384;
            case 0x197398u: goto label_197398;
            case 0x1973B8u: goto label_1973b8;
            case 0x197428u: goto label_197428;
            case 0x197430u: goto label_197430;
            case 0x197438u: goto label_197438;
            case 0x197440u: goto label_197440;
            case 0x197448u: goto label_197448;
            case 0x197450u: goto label_197450;
            case 0x197458u: goto label_197458;
            case 0x19745Cu: goto label_19745c;
            case 0x197460u: goto label_197460;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197468u;
    // 0x197468: 0x0  nop
    ctx->pc = 0x197468u;
    // NOP
    // 0x19746c: 0x0  nop
    ctx->pc = 0x19746cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
