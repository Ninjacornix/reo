#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00144618
// Address: 0x144618 - 0x144748
void sub_00144618_0x144618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00144618_0x144618");
#endif

    switch (ctx->pc) {
        case 0x144650u: goto label_144650;
        case 0x14465cu: goto label_14465c;
        case 0x144680u: goto label_144680;
        case 0x144690u: goto label_144690;
        case 0x144698u: goto label_144698;
        case 0x1446a4u: goto label_1446a4;
        case 0x1446c4u: goto label_1446c4;
        default: break;
    }

    ctx->pc = 0x144618u;

    // 0x144618: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x144618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x14461c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x14461cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x144620: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x144620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x144624: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x144624u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144628: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x144628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x14462c: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x14462cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144630: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x144630u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x144634: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x144634u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144638: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x144638u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x14463c: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x14463cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x144640: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x144640u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144644: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x144644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x144648: 0xc0516d6  jal         func_145B58
    ctx->pc = 0x144648u;
    SET_GPR_U32(ctx, 31, 0x144650u);
    ctx->pc = 0x14464Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144648u;
            // 0x14464c: 0xae000134  sw          $zero, 0x134($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145B58u;
    if (runtime->hasFunction(0x145B58u)) {
        auto targetFn = runtime->lookupFunction(0x145B58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144650u; }
        if (ctx->pc != 0x144650u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145B58_0x145b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144650u; }
        if (ctx->pc != 0x144650u) { return; }
    }
    ctx->pc = 0x144650u;
label_144650:
    // 0x144650: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x144650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144654: 0xc0515ee  jal         func_1457B8
    ctx->pc = 0x144654u;
    SET_GPR_U32(ctx, 31, 0x14465Cu);
    ctx->pc = 0x144658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144654u;
            // 0x144658: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1457B8u;
    if (runtime->hasFunction(0x1457B8u)) {
        auto targetFn = runtime->lookupFunction(0x1457B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14465Cu; }
        if (ctx->pc != 0x14465Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001457B8_0x1457b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14465Cu; }
        if (ctx->pc != 0x14465Cu) { return; }
    }
    ctx->pc = 0x14465Cu;
label_14465c:
    // 0x14465c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x14465cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144660: 0x2642feff  addiu       $v0, $s2, -0x101
    ctx->pc = 0x144660u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967039));
    // 0x144664: 0x2c4200af  sltiu       $v0, $v0, 0xAF
    ctx->pc = 0x144664u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)175) ? 1 : 0);
    // 0x144668: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x144668u;
    {
        const bool branch_taken_0x144668 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x14466Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144668u;
            // 0x14466c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144668) {
            ctx->pc = 0x144688u;
            goto label_144688;
        }
    }
    ctx->pc = 0x144670u;
    // 0x144670: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x144670u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x144674: 0x24a5de40  addiu       $a1, $a1, -0x21C0
    ctx->pc = 0x144674u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958656));
    // 0x144678: 0xc05220e  jal         func_148838
    ctx->pc = 0x144678u;
    SET_GPR_U32(ctx, 31, 0x144680u);
    ctx->pc = 0x14467Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144678u;
            // 0x14467c: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148838u;
    if (runtime->hasFunction(0x148838u)) {
        auto targetFn = runtime->lookupFunction(0x148838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144680u; }
        if (ctx->pc != 0x144680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144680u; }
        if (ctx->pc != 0x144680u) { return; }
    }
    ctx->pc = 0x144680u;
label_144680:
    // 0x144680: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x144680u;
    {
        const bool branch_taken_0x144680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x144684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x144680u;
            // 0x144684: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x144680) {
            ctx->pc = 0x144720u;
            goto label_144720;
        }
    }
    ctx->pc = 0x144688u;
label_144688:
    // 0x144688: 0xc051636  jal         func_1458D8
    ctx->pc = 0x144688u;
    SET_GPR_U32(ctx, 31, 0x144690u);
    ctx->pc = 0x14468Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144688u;
            // 0x14468c: 0x24050020  addiu       $a1, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1458D8u;
    if (runtime->hasFunction(0x1458D8u)) {
        auto targetFn = runtime->lookupFunction(0x1458D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144690u; }
        if (ctx->pc != 0x144690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144690u; }
        if (ctx->pc != 0x144690u) { return; }
    }
    ctx->pc = 0x144690u;
label_144690:
    // 0x144690: 0xc0516f6  jal         func_145BD8
    ctx->pc = 0x144690u;
    SET_GPR_U32(ctx, 31, 0x144698u);
    ctx->pc = 0x144694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x144690u;
            // 0x144694: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x145BD8u;
    if (runtime->hasFunction(0x145BD8u)) {
        auto targetFn = runtime->lookupFunction(0x145BD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144698u; }
        if (ctx->pc != 0x144698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00145BD8_0x145bd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144698u; }
        if (ctx->pc != 0x144698u) { return; }
    }
    ctx->pc = 0x144698u;
label_144698:
    // 0x144698: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x144698u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14469c: 0xc0510fc  jal         func_1443F0
    ctx->pc = 0x14469Cu;
    SET_GPR_U32(ctx, 31, 0x1446A4u);
    ctx->pc = 0x1446A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14469Cu;
            // 0x1446a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1443F0u;
    if (runtime->hasFunction(0x1443F0u)) {
        auto targetFn = runtime->lookupFunction(0x1443F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1446A4u; }
        if (ctx->pc != 0x1446A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001443F0_0x1443f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1446A4u; }
        if (ctx->pc != 0x1446A4u) { return; }
    }
    ctx->pc = 0x1446A4u;
label_1446a4:
    // 0x1446a4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1446a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1446a8: 0xae860000  sw          $a2, 0x0($s4)
    ctx->pc = 0x1446a8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 6));
    // 0x1446ac: 0x8e020134  lw          $v0, 0x134($s0)
    ctx->pc = 0x1446acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 308)));
    // 0x1446b0: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1446B0u;
    {
        const bool branch_taken_0x1446b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1446B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1446B0u;
            // 0x1446b4: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1446b0) {
            ctx->pc = 0x1446CCu;
            goto label_1446cc;
        }
    }
    ctx->pc = 0x1446B8u;
    // 0x1446b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1446b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1446bc: 0xc05221c  jal         func_148870
    ctx->pc = 0x1446BCu;
    SET_GPR_U32(ctx, 31, 0x1446C4u);
    ctx->pc = 0x1446C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1446BCu;
            // 0x1446c0: 0x24a5de68  addiu       $a1, $a1, -0x2198 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958696));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1446C4u; }
        if (ctx->pc != 0x1446C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1446C4u; }
        if (ctx->pc != 0x1446C4u) { return; }
    }
    ctx->pc = 0x1446C4u;
label_1446c4:
    // 0x1446c4: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1446C4u;
    {
        const bool branch_taken_0x1446c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1446C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1446C4u;
            // 0x1446c8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1446c4) {
            ctx->pc = 0x144720u;
            goto label_144720;
        }
    }
    ctx->pc = 0x1446CCu;
label_1446cc:
    // 0x1446cc: 0x324200ff  andi        $v0, $s2, 0xFF
    ctx->pc = 0x1446ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 18) & (uint64_t)(uint16_t)255);
    // 0x1446d0: 0x1319c0  sll         $v1, $s3, 7
    ctx->pc = 0x1446d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 7));
    // 0x1446d4: 0x8e040144  lw          $a0, 0x144($s0)
    ctx->pc = 0x1446d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 324)));
    // 0x1446d8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1446d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1446dc: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1446dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1446e0: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1446e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1446e4: 0x641018  mult        $v0, $v1, $a0
    ctx->pc = 0x1446e4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1446e8: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x1446e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1446ec: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x1446ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1446f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1446f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1446f4: 0xaea30000  sw          $v1, 0x0($s5)
    ctx->pc = 0x1446f4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x1446f8: 0xae850000  sw          $a1, 0x0($s4)
    ctx->pc = 0x1446f8u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 5));
    // 0x1446fc: 0xae0501c8  sw          $a1, 0x1C8($s0)
    ctx->pc = 0x1446fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 456), GPR_U32(ctx, 5));
    // 0x144700: 0xae200008  sw          $zero, 0x8($s1)
    ctx->pc = 0x144700u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x144704: 0xae200014  sw          $zero, 0x14($s1)
    ctx->pc = 0x144704u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x144708: 0xae200010  sw          $zero, 0x10($s1)
    ctx->pc = 0x144708u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x14470c: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x14470cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x144710: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x144710u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x144714: 0xae20001c  sw          $zero, 0x1C($s1)
    ctx->pc = 0x144714u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 0));
    // 0x144718: 0xae200018  sw          $zero, 0x18($s1)
    ctx->pc = 0x144718u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 0));
    // 0x14471c: 0xae20000c  sw          $zero, 0xC($s1)
    ctx->pc = 0x14471cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
label_144720:
    // 0x144720: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x144720u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x144724: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x144724u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x144728: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x144728u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14472c: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x14472cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x144730: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x144730u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x144734: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x144734u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x144738: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x144738u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14473c: 0x3e00008  jr          $ra
    ctx->pc = 0x14473Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14473Cu;
            // 0x144740: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144650u: goto label_144650;
            case 0x14465Cu: goto label_14465c;
            case 0x144680u: goto label_144680;
            case 0x144688u: goto label_144688;
            case 0x144690u: goto label_144690;
            case 0x144698u: goto label_144698;
            case 0x1446A4u: goto label_1446a4;
            case 0x1446C4u: goto label_1446c4;
            case 0x1446CCu: goto label_1446cc;
            case 0x144720u: goto label_144720;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144744u;
    // 0x144744: 0x0  nop
    ctx->pc = 0x144744u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
