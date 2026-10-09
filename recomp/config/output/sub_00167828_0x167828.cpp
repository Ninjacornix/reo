#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167828
// Address: 0x167828 - 0x16791c
void sub_00167828_0x167828(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167828_0x167828");
#endif

    switch (ctx->pc) {
        case 0x167888u: goto label_167888;
        case 0x167898u: goto label_167898;
        case 0x1678e8u: goto label_1678e8;
        case 0x1678fcu: goto label_1678fc;
        default: break;
    }

    ctx->pc = 0x167828u;

    // 0x167828: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x167828u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x16782c: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x16782cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x167830: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x167830u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167834: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167834u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167838: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167838u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x16783c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x16783cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167840: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x167840u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x167844: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167844u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167848: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x167848u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x16784c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x16784cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167850: 0x26461140  addiu       $a2, $s2, 0x1140
    ctx->pc = 0x167850u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 18), 4416));
    // 0x167854: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x167858: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16785c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16785cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167860: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x167860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x167864: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x167864u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167868: 0x12200025  beqz        $s1, . + 4 + (0x25 << 2)
    ctx->pc = 0x167868u;
    {
        const bool branch_taken_0x167868 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x16786Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167868u;
            // 0x16786c: 0xc33021  addu        $a2, $a2, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167868) {
            ctx->pc = 0x167900u;
            goto label_167900;
        }
    }
    ctx->pc = 0x167870u;
    // 0x167870: 0x8cc20004  lw          $v0, 0x4($a2)
    ctx->pc = 0x167870u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x167874: 0x54400006  bnel        $v0, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x167874u;
    {
        const bool branch_taken_0x167874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x167874) {
            ctx->pc = 0x167878u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x167874u;
            // 0x167878: 0x24d00010  addiu       $s0, $a2, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x167890u;
            goto label_167890;
        }
    }
    ctx->pc = 0x16787Cu;
    // 0x16787c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16787cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x167880: 0xc05a704  jal         func_169C10
    ctx->pc = 0x167880u;
    SET_GPR_U32(ctx, 31, 0x167888u);
    ctx->pc = 0x167884u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167880u;
            // 0x167884: 0x34a50401  ori         $a1, $a1, 0x401 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1025);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167888u; }
        if (ctx->pc != 0x167888u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167888u; }
        if (ctx->pc != 0x167888u) { return; }
    }
    ctx->pc = 0x167888u;
label_167888:
    // 0x167888: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x167888u;
    {
        const bool branch_taken_0x167888 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16788Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167888u;
            // 0x16788c: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167888) {
            ctx->pc = 0x167904u;
            goto label_167904;
        }
    }
    ctx->pc = 0x167890u;
label_167890:
    // 0x167890: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167890u;
    SET_GPR_U32(ctx, 31, 0x167898u);
    ctx->pc = 0x167894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167890u;
            // 0x167894: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167898u; }
        if (ctx->pc != 0x167898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167898u; }
        if (ctx->pc != 0x167898u) { return; }
    }
    ctx->pc = 0x167898u;
label_167898:
    // 0x167898: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x167898u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16789c: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x16789cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1678a0: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1678a0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1678a4: 0x8e06001c  lw          $a2, 0x1C($s0)
    ctx->pc = 0x1678a4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1678a8: 0x34a50406  ori         $a1, $a1, 0x406
    ctx->pc = 0x1678a8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)1030);
    // 0x1678ac: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1678acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1678b0: 0x46182a  slt         $v1, $v0, $a2
    ctx->pc = 0x1678b0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1678b4: 0x463823  subu        $a3, $v0, $a2
    ctx->pc = 0x1678b4u;
    SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1678b8: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1678B8u;
    {
        const bool branch_taken_0x1678b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1678BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1678B8u;
            // 0x1678bc: 0xae020020  sw          $v0, 0x20($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1678b8) {
            ctx->pc = 0x1678C4u;
            goto label_1678c4;
        }
    }
    ctx->pc = 0x1678C0u;
    // 0x1678c0: 0xae070020  sw          $a3, 0x20($s0)
    ctx->pc = 0x1678c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 7));
label_1678c4:
    // 0x1678c4: 0x8e020028  lw          $v0, 0x28($s0)
    ctx->pc = 0x1678c4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1678c8: 0x8e03002c  lw          $v1, 0x2C($s0)
    ctx->pc = 0x1678c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
    // 0x1678cc: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x1678ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x1678d0: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x1678d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1678d4: 0x62182a  slt         $v1, $v1, $v0
    ctx->pc = 0x1678d4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1678d8: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1678D8u;
    {
        const bool branch_taken_0x1678d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1678DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1678D8u;
            // 0x1678dc: 0xae020028  sw          $v0, 0x28($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1678d8) {
            ctx->pc = 0x1678ECu;
            goto label_1678ec;
        }
    }
    ctx->pc = 0x1678E0u;
    // 0x1678e0: 0xc05a704  jal         func_169C10
    ctx->pc = 0x1678E0u;
    SET_GPR_U32(ctx, 31, 0x1678E8u);
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678E8u; }
        if (ctx->pc != 0x1678E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678E8u; }
        if (ctx->pc != 0x1678E8u) { return; }
    }
    ctx->pc = 0x1678E8u;
label_1678e8:
    // 0x1678e8: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x1678e8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1678ec:
    // 0x1678ec: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1678ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1678f0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1678f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1678f4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x1678F4u;
    SET_GPR_U32(ctx, 31, 0x1678FCu);
    ctx->pc = 0x1678F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1678F4u;
            // 0x1678f8: 0xae420044  sw          $v0, 0x44($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 68), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678FCu; }
        if (ctx->pc != 0x1678FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1678FCu; }
        if (ctx->pc != 0x1678FCu) { return; }
    }
    ctx->pc = 0x1678FCu;
label_1678fc:
    // 0x1678fc: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x1678fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_167900:
    // 0x167900: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167900u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_167904:
    // 0x167904: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167904u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167908: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167908u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16790c: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16790cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167910: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x167910u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167914: 0x3e00008  jr          $ra
    ctx->pc = 0x167914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167918u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167914u;
            // 0x167918: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167888u: goto label_167888;
            case 0x167890u: goto label_167890;
            case 0x167898u: goto label_167898;
            case 0x1678C4u: goto label_1678c4;
            case 0x1678E8u: goto label_1678e8;
            case 0x1678ECu: goto label_1678ec;
            case 0x1678FCu: goto label_1678fc;
            case 0x167900u: goto label_167900;
            case 0x167904u: goto label_167904;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16791Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
