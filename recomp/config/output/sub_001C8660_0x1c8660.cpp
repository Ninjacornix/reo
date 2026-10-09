#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8660
// Address: 0x1c8660 - 0x1c87f0
void sub_001C8660_0x1c8660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8660_0x1c8660");
#endif

    switch (ctx->pc) {
        case 0x1c86bcu: goto label_1c86bc;
        case 0x1c8704u: goto label_1c8704;
        case 0x1c8730u: goto label_1c8730;
        case 0x1c87a8u: goto label_1c87a8;
        case 0x1c87c0u: goto label_1c87c0;
        case 0x1c87ccu: goto label_1c87cc;
        default: break;
    }

    ctx->pc = 0x1c8660u;

    // 0x1c8660: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1c8660u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1c8664: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1c8664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c8668: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1c8668u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1c866c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c866cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c8670: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c8670u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c8674: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1c8674u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8678: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c8678u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c867c: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1c867cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8680: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c8680u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c8684: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1c8684u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c8688: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c8688u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c868c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x1c868cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c8690: 0x10620007  beq         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C8690u;
    {
        const bool branch_taken_0x1c8690 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C8694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8690u;
            // 0x1c8694: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8690) {
            ctx->pc = 0x1C86B0u;
            goto label_1c86b0;
        }
    }
    ctx->pc = 0x1C8698u;
    // 0x1c8698: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c8698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c869c: 0x14620002  bne         $v1, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C869Cu;
    {
        const bool branch_taken_0x1c869c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1C86A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C869Cu;
            // 0x1c86a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c869c) {
            ctx->pc = 0x1C86A8u;
            goto label_1c86a8;
        }
    }
    ctx->pc = 0x1C86A4u;
    // 0x1c86a4: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1c86a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_1c86a8:
    // 0x1c86a8: 0x1000004a  b           . + 4 + (0x4A << 2)
    ctx->pc = 0x1C86A8u;
    {
        const bool branch_taken_0x1c86a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C86ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C86A8u;
            // 0x1c86ac: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c86a8) {
            ctx->pc = 0x1C87D4u;
            goto label_1c87d4;
        }
    }
    ctx->pc = 0x1C86B0u;
label_1c86b0:
    // 0x1c86b0: 0x27a4006c  addiu       $a0, $sp, 0x6C
    ctx->pc = 0x1c86b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 108));
    // 0x1c86b4: 0xc071c94  jal         func_1C7250
    ctx->pc = 0x1C86B4u;
    SET_GPR_U32(ctx, 31, 0x1C86BCu);
    ctx->pc = 0x1C86B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C86B4u;
            // 0x1c86b8: 0x27a50068  addiu       $a1, $sp, 0x68 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C7250u;
    if (runtime->hasFunction(0x1C7250u)) {
        auto targetFn = runtime->lookupFunction(0x1C7250u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C86BCu; }
        if (ctx->pc != 0x1C86BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C7250_0x1c7250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C86BCu; }
        if (ctx->pc != 0x1C86BCu) { return; }
    }
    ctx->pc = 0x1C86BCu;
label_1c86bc:
    // 0x1c86bc: 0x10400043  beqz        $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1C86BCu;
    {
        const bool branch_taken_0x1c86bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C86C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C86BCu;
            // 0x1c86c0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c86bc) {
            ctx->pc = 0x1C87CCu;
            goto label_1c87cc;
        }
    }
    ctx->pc = 0x1C86C4u;
    // 0x1c86c4: 0x8fa30068  lw          $v1, 0x68($sp)
    ctx->pc = 0x1c86c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1c86c8: 0x2402000f  addiu       $v0, $zero, 0xF
    ctx->pc = 0x1c86c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1c86cc: 0x1462002f  bne         $v1, $v0, . + 4 + (0x2F << 2)
    ctx->pc = 0x1C86CCu;
    {
        const bool branch_taken_0x1c86cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c86cc) {
            ctx->pc = 0x1C878Cu;
            goto label_1c878c;
        }
    }
    ctx->pc = 0x1C86D4u;
    // 0x1c86d4: 0x8fa4006c  lw          $a0, 0x6C($sp)
    ctx->pc = 0x1c86d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1c86d8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c86d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c86dc: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x1c86dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c86e0: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C86E0u;
    {
        const bool branch_taken_0x1c86e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c86e0) {
            ctx->pc = 0x1C86F0u;
            goto label_1c86f0;
        }
    }
    ctx->pc = 0x1C86E8u;
    // 0x1c86e8: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1C86E8u;
    {
        const bool branch_taken_0x1c86e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c86e8) {
            ctx->pc = 0x1C87C4u;
            goto label_1c87c4;
        }
    }
    ctx->pc = 0x1C86F0u;
label_1c86f0:
    // 0x1c86f0: 0x90820001  lbu         $v0, 0x1($a0)
    ctx->pc = 0x1c86f0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x1c86f4: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1c86f4u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c86f8: 0x8e840048  lw          $a0, 0x48($s4)
    ctx->pc = 0x1c86f8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
    // 0x1c86fc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C86FCu;
    {
        const bool branch_taken_0x1c86fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C86FCu;
            // 0x1c8700: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c86fc) {
            ctx->pc = 0x1C871Cu;
            goto label_1c871c;
        }
    }
    ctx->pc = 0x1C8704u;
label_1c8704:
    // 0x1c8704: 0x92620000  lbu         $v0, 0x0($s3)
    ctx->pc = 0x1c8704u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1c8708: 0x2831821  addu        $v1, $s4, $v1
    ctx->pc = 0x1c8708u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1c870c: 0x8c63004c  lw          $v1, 0x4C($v1)
    ctx->pc = 0x1c870cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 76)));
    // 0x1c8710: 0x10620005  beq         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1C8710u;
    {
        const bool branch_taken_0x1c8710 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c8710) {
            ctx->pc = 0x1C8728u;
            goto label_1c8728;
        }
    }
    ctx->pc = 0x1C8718u;
    // 0x1c8718: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1c8718u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1c871c:
    // 0x1c871c: 0xa4102a  slt         $v0, $a1, $a0
    ctx->pc = 0x1c871cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1c8720: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1C8720u;
    {
        const bool branch_taken_0x1c8720 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C8724u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8720u;
            // 0x1c8724: 0x51880  sll         $v1, $a1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8720) {
            ctx->pc = 0x1C8704u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c8704;
        }
    }
    ctx->pc = 0x1C8728u;
label_1c8728:
    // 0x1c8728: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C8728u;
    {
        const bool branch_taken_0x1c8728 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C872Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8728u;
            // 0x1c872c: 0x24a40001  addiu       $a0, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8728) {
            ctx->pc = 0x1C8750u;
            goto label_1c8750;
        }
    }
    ctx->pc = 0x1C8730u;
label_1c8730:
    // 0x1c8730: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1c8730u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1c8734: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x1c8734u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1c8738: 0x2831821  addu        $v1, $s4, $v1
    ctx->pc = 0x1c8738u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1c873c: 0x2821021  addu        $v0, $s4, $v0
    ctx->pc = 0x1c873cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
    // 0x1c8740: 0x8c63004c  lw          $v1, 0x4C($v1)
    ctx->pc = 0x1c8740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 76)));
    // 0x1c8744: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1c8744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1c8748: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1c8748u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1c874c: 0xac43004c  sw          $v1, 0x4C($v0)
    ctx->pc = 0x1c874cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 3));
label_1c8750:
    // 0x1c8750: 0x8e830048  lw          $v1, 0x48($s4)
    ctx->pc = 0x1c8750u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
    // 0x1c8754: 0x83102a  slt         $v0, $a0, $v1
    ctx->pc = 0x1c8754u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c8758: 0x1440fff5  bnez        $v0, . + 4 + (-0xB << 2)
    ctx->pc = 0x1C8758u;
    {
        const bool branch_taken_0x1c8758 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C875Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8758u;
            // 0x1c875c: 0x2462ffff  addiu       $v0, $v1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8758) {
            ctx->pc = 0x1C8730u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c8730;
        }
    }
    ctx->pc = 0x1C8760u;
    // 0x1c8760: 0xae820048  sw          $v0, 0x48($s4)
    ctx->pc = 0x1c8760u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 72), GPR_U32(ctx, 2));
    // 0x1c8764: 0x8e83004c  lw          $v1, 0x4C($s4)
    ctx->pc = 0x1c8764u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 76)));
    // 0x1c8768: 0x8e820040  lw          $v0, 0x40($s4)
    ctx->pc = 0x1c8768u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 64)));
    // 0x1c876c: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C876Cu;
    {
        const bool branch_taken_0x1c876c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1c876c) {
            ctx->pc = 0x1C877Cu;
            goto label_1c877c;
        }
    }
    ctx->pc = 0x1C8774u;
    // 0x1c8774: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C8774u;
    {
        const bool branch_taken_0x1c8774 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8774u;
            // 0x1c8778: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8774) {
            ctx->pc = 0x1C8780u;
            goto label_1c8780;
        }
    }
    ctx->pc = 0x1C877Cu;
label_1c877c:
    // 0x1c877c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c877cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c8780:
    // 0x1c8780: 0xa2820044  sb          $v0, 0x44($s4)
    ctx->pc = 0x1c8780u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 68), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c8784: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C8784u;
    {
        const bool branch_taken_0x1c8784 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8788u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8784u;
            // 0x1c8788: 0x24110004  addiu       $s1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8784) {
            ctx->pc = 0x1C87C4u;
            goto label_1c87c4;
        }
    }
    ctx->pc = 0x1C878Cu;
label_1c878c:
    // 0x1c878c: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x1c878cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1c8790: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x1c8790u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1c8794: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x1c8794u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c8798: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C8798u;
    {
        const bool branch_taken_0x1c8798 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C879Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8798u;
            // 0x1c879c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8798) {
            ctx->pc = 0x1C87A8u;
            goto label_1c87a8;
        }
    }
    ctx->pc = 0x1C87A0u;
    // 0x1c87a0: 0xc072250  jal         func_1C8940
    ctx->pc = 0x1C87A0u;
    SET_GPR_U32(ctx, 31, 0x1C87A8u);
    ctx->pc = 0x1C8940u;
    if (runtime->hasFunction(0x1C8940u)) {
        auto targetFn = runtime->lookupFunction(0x1C8940u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C87A8u; }
        if (ctx->pc != 0x1C87A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8940_0x1c8940(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C87A8u; }
        if (ctx->pc != 0x1C87A8u) { return; }
    }
    ctx->pc = 0x1C87A8u;
label_1c87a8:
    // 0x1c87a8: 0x8fa20068  lw          $v0, 0x68($sp)
    ctx->pc = 0x1c87a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x1c87ac: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1c87acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c87b0: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1c87b0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c87b4: 0x8fa5006c  lw          $a1, 0x6C($sp)
    ctx->pc = 0x1c87b4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 108)));
    // 0x1c87b8: 0xc072258  jal         func_1C8960
    ctx->pc = 0x1C87B8u;
    SET_GPR_U32(ctx, 31, 0x1C87C0u);
    ctx->pc = 0x1C87BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C87B8u;
            // 0x1c87bc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8960u;
    if (runtime->hasFunction(0x1C8960u)) {
        auto targetFn = runtime->lookupFunction(0x1C8960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C87C0u; }
        if (ctx->pc != 0x1C87C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8960_0x1c8960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C87C0u; }
        if (ctx->pc != 0x1C87C0u) { return; }
    }
    ctx->pc = 0x1C87C0u;
label_1c87c0:
    // 0x1c87c0: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1c87c0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1c87c4:
    // 0x1c87c4: 0xc071cb8  jal         func_1C72E0
    ctx->pc = 0x1C87C4u;
    SET_GPR_U32(ctx, 31, 0x1C87CCu);
    ctx->pc = 0x1C72E0u;
    if (runtime->hasFunction(0x1C72E0u)) {
        auto targetFn = runtime->lookupFunction(0x1C72E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C87CCu; }
        if (ctx->pc != 0x1C87CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C72E0_0x1c72e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C87CCu; }
        if (ctx->pc != 0x1C87CCu) { return; }
    }
    ctx->pc = 0x1C87CCu;
label_1c87cc:
    // 0x1c87cc: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1c87ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c87d0: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1c87d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_1c87d4:
    // 0x1c87d4: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1c87d4u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c87d8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c87d8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c87dc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c87dcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c87e0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c87e0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c87e4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c87e4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c87e8: 0x3e00008  jr          $ra
    ctx->pc = 0x1C87E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C87ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C87E8u;
            // 0x1c87ec: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C86A8u: goto label_1c86a8;
            case 0x1C86B0u: goto label_1c86b0;
            case 0x1C86BCu: goto label_1c86bc;
            case 0x1C86F0u: goto label_1c86f0;
            case 0x1C8704u: goto label_1c8704;
            case 0x1C871Cu: goto label_1c871c;
            case 0x1C8728u: goto label_1c8728;
            case 0x1C8730u: goto label_1c8730;
            case 0x1C8750u: goto label_1c8750;
            case 0x1C877Cu: goto label_1c877c;
            case 0x1C8780u: goto label_1c8780;
            case 0x1C878Cu: goto label_1c878c;
            case 0x1C87A8u: goto label_1c87a8;
            case 0x1C87C0u: goto label_1c87c0;
            case 0x1C87C4u: goto label_1c87c4;
            case 0x1C87CCu: goto label_1c87cc;
            case 0x1C87D4u: goto label_1c87d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C87F0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
