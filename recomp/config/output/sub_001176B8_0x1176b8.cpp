#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001176B8
// Address: 0x1176b8 - 0x117818
void sub_001176B8_0x1176b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001176B8_0x1176b8");
#endif

    switch (ctx->pc) {
        case 0x1176c8u: goto label_1176c8;
        case 0x1176d8u: goto label_1176d8;
        case 0x117730u: goto label_117730;
        case 0x11776cu: goto label_11776c;
        case 0x117798u: goto label_117798;
        case 0x1177d4u: goto label_1177d4;
        default: break;
    }

    ctx->pc = 0x1176b8u;

label_1176b8:
    // 0x1176b8: 0x8ca50028  lw          $a1, 0x28($a1)
    ctx->pc = 0x1176b8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 40)));
    // 0x1176bc: 0x10a0000f  beqz        $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x1176BCu;
    {
        const bool branch_taken_0x1176bc = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1176bc) {
            ctx->pc = 0x1176FCu;
            goto label_1176fc;
        }
    }
    ctx->pc = 0x1176C4u;
    // 0x1176c4: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x1176c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
label_1176c8:
    // 0x1176c8: 0x5060000a  beql        $v1, $zero, . + 4 + (0xA << 2)
    ctx->pc = 0x1176C8u;
    {
        const bool branch_taken_0x1176c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1176c8) {
            ctx->pc = 0x1176CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1176C8u;
            // 0x1176cc: 0x8ca50014  lw          $a1, 0x14($a1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1176F4u;
            goto label_1176f4;
        }
    }
    ctx->pc = 0x1176D0u;
    // 0x1176d0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1176d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1176d4: 0x0  nop
    ctx->pc = 0x1176d4u;
    // NOP
label_1176d8:
    // 0x1176d8: 0x54440003  bnel        $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1176D8u;
    {
        const bool branch_taken_0x1176d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x1176d8) {
            ctx->pc = 0x1176DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1176D8u;
            // 0x1176dc: 0x8c630038  lw          $v1, 0x38($v1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 56)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1176E8u;
            goto label_1176e8;
        }
    }
    ctx->pc = 0x1176E0u;
    // 0x1176e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1176E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1176E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1176E0u;
            // 0x1176e4: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1176B8u: goto label_1176b8;
            case 0x1176C8u: goto label_1176c8;
            case 0x1176D8u: goto label_1176d8;
            case 0x1176E8u: goto label_1176e8;
            case 0x1176F4u: goto label_1176f4;
            case 0x1176FCu: goto label_1176fc;
            case 0x117730u: goto label_117730;
            case 0x11776Cu: goto label_11776c;
            case 0x117798u: goto label_117798;
            case 0x1177ACu: goto label_1177ac;
            case 0x1177B4u: goto label_1177b4;
            case 0x1177D4u: goto label_1177d4;
            case 0x117800u: goto label_117800;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1176E8u;
label_1176e8:
    // 0x1176e8: 0x5460fffb  bnel        $v1, $zero, . + 4 + (-0x5 << 2)
    ctx->pc = 0x1176E8u;
    {
        const bool branch_taken_0x1176e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1176e8) {
            ctx->pc = 0x1176ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1176E8u;
            // 0x1176ec: 0x8c620000  lw          $v0, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1176D8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1176d8;
        }
    }
    ctx->pc = 0x1176F0u;
    // 0x1176f0: 0x8ca50014  lw          $a1, 0x14($a1)
    ctx->pc = 0x1176f0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
label_1176f4:
    // 0x1176f4: 0x54a0fff4  bnel        $a1, $zero, . + 4 + (-0xC << 2)
    ctx->pc = 0x1176F4u;
    {
        const bool branch_taken_0x1176f4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x1176f4) {
            ctx->pc = 0x1176F8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1176F4u;
            // 0x1176f8: 0x8ca30008  lw          $v1, 0x8($a1) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1176C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1176c8;
        }
    }
    ctx->pc = 0x1176FCu;
label_1176fc:
    // 0x1176fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1176FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1176FCu;
            // 0x117700: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1176B8u: goto label_1176b8;
            case 0x1176C8u: goto label_1176c8;
            case 0x1176D8u: goto label_1176d8;
            case 0x1176E8u: goto label_1176e8;
            case 0x1176F4u: goto label_1176f4;
            case 0x1176FCu: goto label_1176fc;
            case 0x117730u: goto label_117730;
            case 0x11776Cu: goto label_11776c;
            case 0x117798u: goto label_117798;
            case 0x1177ACu: goto label_1177ac;
            case 0x1177B4u: goto label_1177b4;
            case 0x1177D4u: goto label_1177d4;
            case 0x117800u: goto label_117800;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117704u;
    // 0x117704: 0x0  nop
    ctx->pc = 0x117704u;
    // NOP
    // 0x117708: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x117708u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11770c: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x11770cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117710: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x117710u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x117714: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x117714u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x117718: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x117718u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x11771c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x11771cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x117720: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x117720u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117724: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x117724u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117728: 0xc045b92  jal         func_116E48
    ctx->pc = 0x117728u;
    SET_GPR_U32(ctx, 31, 0x117730u);
    ctx->pc = 0x11772Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117728u;
            // 0x11772c: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117730u; }
        if (ctx->pc != 0x117730u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x117730u; }
        if (ctx->pc != 0x117730u) { return; }
    }
    ctx->pc = 0x117730u;
label_117730:
    // 0x117730: 0x24030800  addiu       $v1, $zero, 0x800
    ctx->pc = 0x117730u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x117734: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x117734u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x117738: 0x2180b  movn        $v1, $zero, $v0
    ctx->pc = 0x117738u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x11773c: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x11773cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117740: 0x3e00008  jr          $ra
    ctx->pc = 0x117740u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117744u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117740u;
            // 0x117744: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1176B8u: goto label_1176b8;
            case 0x1176C8u: goto label_1176c8;
            case 0x1176D8u: goto label_1176d8;
            case 0x1176E8u: goto label_1176e8;
            case 0x1176F4u: goto label_1176f4;
            case 0x1176FCu: goto label_1176fc;
            case 0x117730u: goto label_117730;
            case 0x11776Cu: goto label_11776c;
            case 0x117798u: goto label_117798;
            case 0x1177ACu: goto label_1177ac;
            case 0x1177B4u: goto label_1177b4;
            case 0x1177D4u: goto label_1177d4;
            case 0x117800u: goto label_117800;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117748u;
    // 0x117748: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x117748u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11774c: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11774cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x117750: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x117750u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x117754: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x117754u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117758: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x117758u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11775c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11775cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x117760: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x117760u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x117764: 0xc045cc4  jal         func_117310
    ctx->pc = 0x117764u;
    SET_GPR_U32(ctx, 31, 0x11776Cu);
    ctx->pc = 0x117768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117764u;
            // 0x117768: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x117310u;
    if (runtime->hasFunction(0x117310u)) {
        auto targetFn = runtime->lookupFunction(0x117310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11776Cu; }
        if (ctx->pc != 0x11776Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00117310_0x117310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11776Cu; }
        if (ctx->pc != 0x11776Cu) { return; }
    }
    ctx->pc = 0x11776Cu;
label_11776c:
    // 0x11776c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x11776cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x117770: 0x8e04001c  lw          $a0, 0x1C($s0)
    ctx->pc = 0x117770u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x117774: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x117774u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x117778: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x117778u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x11777c: 0x34420009  ori         $v0, $v0, 0x9
    ctx->pc = 0x11777cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)9);
    // 0x117780: 0xae44001c  sw          $a0, 0x1C($s2)
    ctx->pc = 0x117780u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 28), GPR_U32(ctx, 4));
    // 0x117784: 0xae430014  sw          $v1, 0x14($s2)
    ctx->pc = 0x117784u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 3));
    // 0x117788: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x117788u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11778c: 0xae420020  sw          $v0, 0x20($s2)
    ctx->pc = 0x11778cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 32), GPR_U32(ctx, 2));
    // 0x117790: 0xc045dae  jal         func_1176B8
    ctx->pc = 0x117790u;
    SET_GPR_U32(ctx, 31, 0x117798u);
    ctx->pc = 0x117794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x117790u;
            // 0x117794: 0x8e040020  lw          $a0, 0x20($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1176B8u;
    goto label_1176b8;
    ctx->pc = 0x117798u;
label_117798:
    // 0x117798: 0x54400004  bnel        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x117798u;
    {
        const bool branch_taken_0x117798 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x117798) {
            ctx->pc = 0x11779Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x117798u;
            // 0x11779c: 0xae420024  sw          $v0, 0x24($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1177ACu;
            goto label_1177ac;
        }
    }
    ctx->pc = 0x1177A0u;
    // 0x1177a0: 0xae400024  sw          $zero, 0x24($s2)
    ctx->pc = 0x1177a0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 0));
    // 0x1177a4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1177A4u;
    {
        const bool branch_taken_0x1177a4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1177A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1177A4u;
            // 0x1177a8: 0xae400028  sw          $zero, 0x28($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 40), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1177a4) {
            ctx->pc = 0x1177B4u;
            goto label_1177b4;
        }
    }
    ctx->pc = 0x1177ACu;
label_1177ac:
    // 0x1177ac: 0x8c420008  lw          $v0, 0x8($v0)
    ctx->pc = 0x1177acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1177b0: 0xae420028  sw          $v0, 0x28($s2)
    ctx->pc = 0x1177b0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 40), GPR_U32(ctx, 2));
label_1177b4:
    // 0x1177b4: 0x3c048000  lui         $a0, 0x8000
    ctx->pc = 0x1177b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)32768 << 16));
    // 0x1177b8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1177b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1177bc: 0x34840008  ori         $a0, $a0, 0x8
    ctx->pc = 0x1177bcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)8);
    // 0x1177c0: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x1177c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1177c4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1177c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1177c8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1177c8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1177cc: 0xc045b92  jal         func_116E48
    ctx->pc = 0x1177CCu;
    SET_GPR_U32(ctx, 31, 0x1177D4u);
    ctx->pc = 0x1177D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1177CCu;
            // 0x1177d0: 0x482d  daddu       $t1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116E48u;
    if (runtime->hasFunction(0x116E48u)) {
        auto targetFn = runtime->lookupFunction(0x116E48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1177D4u; }
        if (ctx->pc != 0x1177D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116E48_0x116e48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1177D4u; }
        if (ctx->pc != 0x1177D4u) { return; }
    }
    ctx->pc = 0x1177D4u;
label_1177d4:
    // 0x1177d4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1177D4u;
    {
        const bool branch_taken_0x1177d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1177D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1177D4u;
            // 0x1177d8: 0xdfbf0030  ld          $ra, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1177d4) {
            ctx->pc = 0x117800u;
            goto label_117800;
        }
    }
    ctx->pc = 0x1177DCu;
    // 0x1177dc: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x1177dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1177e0: 0x3c050011  lui         $a1, 0x11
    ctx->pc = 0x1177e0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)17 << 16));
    // 0x1177e4: 0x24a57708  addiu       $a1, $a1, 0x7708
    ctx->pc = 0x1177e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 30472));
    // 0x1177e8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1177e8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1177ec: 0x24040800  addiu       $a0, $zero, 0x800
    ctx->pc = 0x1177ecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2048));
    // 0x1177f0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x1177f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1177f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1177f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1177f8: 0x8047d02  j           func_11F408
    ctx->pc = 0x1177F8u;
    ctx->pc = 0x1177FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1177F8u;
            // 0x1177fc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11F408u;
    if (runtime->hasFunction(0x11F408u)) {
        auto targetFn = runtime->lookupFunction(0x11F408u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011F408_0x11f408(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x117800u;
label_117800:
    // 0x117800: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x117800u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x117804: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x117804u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x117808: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x117808u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11780c: 0x3e00008  jr          $ra
    ctx->pc = 0x11780Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x117810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11780Cu;
            // 0x117810: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1176B8u: goto label_1176b8;
            case 0x1176C8u: goto label_1176c8;
            case 0x1176D8u: goto label_1176d8;
            case 0x1176E8u: goto label_1176e8;
            case 0x1176F4u: goto label_1176f4;
            case 0x1176FCu: goto label_1176fc;
            case 0x117730u: goto label_117730;
            case 0x11776Cu: goto label_11776c;
            case 0x117798u: goto label_117798;
            case 0x1177ACu: goto label_1177ac;
            case 0x1177B4u: goto label_1177b4;
            case 0x1177D4u: goto label_1177d4;
            case 0x117800u: goto label_117800;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117814u;
    // 0x117814: 0x0  nop
    ctx->pc = 0x117814u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
