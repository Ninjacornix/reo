#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159520
// Address: 0x159520 - 0x159710
void sub_00159520_0x159520(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159520_0x159520");
#endif

    switch (ctx->pc) {
        case 0x159554u: goto label_159554;
        case 0x159568u: goto label_159568;
        case 0x159594u: goto label_159594;
        case 0x1595acu: goto label_1595ac;
        case 0x1595c8u: goto label_1595c8;
        case 0x1595e0u: goto label_1595e0;
        case 0x1595e8u: goto label_1595e8;
        case 0x1595f0u: goto label_1595f0;
        case 0x159610u: goto label_159610;
        case 0x159660u: goto label_159660;
        case 0x159670u: goto label_159670;
        case 0x159680u: goto label_159680;
        case 0x159694u: goto label_159694;
        case 0x1596acu: goto label_1596ac;
        case 0x1596bcu: goto label_1596bc;
        case 0x1596ccu: goto label_1596cc;
        default: break;
    }

    ctx->pc = 0x159520u;

    // 0x159520: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x159520u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x159524: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x159524u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x159528: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x159528u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15952c: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x15952cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x159530: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x159530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x159534: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x159534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x159538: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x159538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x15953c: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x15953cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x159540: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x159540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x159544: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x159544u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x159548: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x159548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x15954c: 0xc056dec  jal         func_15B7B0
    ctx->pc = 0x15954Cu;
    SET_GPR_U32(ctx, 31, 0x159554u);
    ctx->pc = 0x159550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15954Cu;
            // 0x159550: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B7B0u;
    if (runtime->hasFunction(0x15B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x15B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159554u; }
        if (ctx->pc != 0x159554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B7B0_0x15b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159554u; }
        if (ctx->pc != 0x159554u) { return; }
    }
    ctx->pc = 0x159554u;
label_159554:
    // 0x159554: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x159554u;
    {
        const bool branch_taken_0x159554 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x159558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159554u;
            // 0x159558: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159554) {
            ctx->pc = 0x159570u;
            goto label_159570;
        }
    }
    ctx->pc = 0x15955Cu;
    // 0x15955c: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x15955cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x159560: 0xc0563ce  jal         func_158F38
    ctx->pc = 0x159560u;
    SET_GPR_U32(ctx, 31, 0x159568u);
    ctx->pc = 0x159564u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159560u;
            // 0x159564: 0x34a5020c  ori         $a1, $a1, 0x20C (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)524);
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159568u; }
        if (ctx->pc != 0x159568u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158F38_0x158f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159568u; }
        if (ctx->pc != 0x159568u) { return; }
    }
    ctx->pc = 0x159568u;
label_159568:
    // 0x159568: 0x1000005f  b           . + 4 + (0x5F << 2)
    ctx->pc = 0x159568u;
    {
        const bool branch_taken_0x159568 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15956Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159568u;
            // 0x15956c: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159568) {
            ctx->pc = 0x1596E8u;
            goto label_1596e8;
        }
    }
    ctx->pc = 0x159570u;
label_159570:
    // 0x159570: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x159570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x159574: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x159574u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x159578: 0xae2003c0  sw          $zero, 0x3C0($s1)
    ctx->pc = 0x159578u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 960), GPR_U32(ctx, 0));
    // 0x15957c: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x15957cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159580: 0x8c480018  lw          $t0, 0x18($v0)
    ctx->pc = 0x159580u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x159584: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x159584u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159588: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x159588u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15958c: 0x100f809  jalr        $t0
    ctx->pc = 0x15958Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 8);
        SET_GPR_U32(ctx, 31, 0x159594u);
        ctx->pc = 0x159590u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15958Cu;
            // 0x159590: 0x34c6ffff  ori         $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159594u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159554u: goto label_159554;
            case 0x159568u: goto label_159568;
            case 0x159570u: goto label_159570;
            case 0x159594u: goto label_159594;
            case 0x1595ACu: goto label_1595ac;
            case 0x1595C8u: goto label_1595c8;
            case 0x1595E0u: goto label_1595e0;
            case 0x1595E8u: goto label_1595e8;
            case 0x1595F0u: goto label_1595f0;
            case 0x1595F8u: goto label_1595f8;
            case 0x159610u: goto label_159610;
            case 0x159640u: goto label_159640;
            case 0x159660u: goto label_159660;
            case 0x159668u: goto label_159668;
            case 0x159670u: goto label_159670;
            case 0x159678u: goto label_159678;
            case 0x159680u: goto label_159680;
            case 0x159688u: goto label_159688;
            case 0x159694u: goto label_159694;
            case 0x1596A0u: goto label_1596a0;
            case 0x1596ACu: goto label_1596ac;
            case 0x1596B0u: goto label_1596b0;
            case 0x1596B4u: goto label_1596b4;
            case 0x1596BCu: goto label_1596bc;
            case 0x1596CCu: goto label_1596cc;
            case 0x1596E0u: goto label_1596e0;
            case 0x1596E8u: goto label_1596e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159594u; }
            if (ctx->pc != 0x159594u) { return; }
        }
        }
    }
    ctx->pc = 0x159594u;
label_159594:
    // 0x159594: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x159594u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x159598: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x159598u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15959c: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x15959cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1595a0: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1595a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1595a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1595A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1595ACu);
        ctx->pc = 0x1595A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1595A4u;
            // 0x1595a8: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1595ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159554u: goto label_159554;
            case 0x159568u: goto label_159568;
            case 0x159570u: goto label_159570;
            case 0x159594u: goto label_159594;
            case 0x1595ACu: goto label_1595ac;
            case 0x1595C8u: goto label_1595c8;
            case 0x1595E0u: goto label_1595e0;
            case 0x1595E8u: goto label_1595e8;
            case 0x1595F0u: goto label_1595f0;
            case 0x1595F8u: goto label_1595f8;
            case 0x159610u: goto label_159610;
            case 0x159640u: goto label_159640;
            case 0x159660u: goto label_159660;
            case 0x159668u: goto label_159668;
            case 0x159670u: goto label_159670;
            case 0x159678u: goto label_159678;
            case 0x159680u: goto label_159680;
            case 0x159688u: goto label_159688;
            case 0x159694u: goto label_159694;
            case 0x1596A0u: goto label_1596a0;
            case 0x1596ACu: goto label_1596ac;
            case 0x1596B0u: goto label_1596b0;
            case 0x1596B4u: goto label_1596b4;
            case 0x1596BCu: goto label_1596bc;
            case 0x1596CCu: goto label_1596cc;
            case 0x1596E0u: goto label_1596e0;
            case 0x1596E8u: goto label_1596e8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1595ACu; }
            if (ctx->pc != 0x1595ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1595ACu;
label_1595ac:
    // 0x1595ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1595acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1595b0: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1595b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1595b4: 0x27a50010  addiu       $a1, $sp, 0x10
    ctx->pc = 0x1595b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1595b8: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x1595b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x1595bc: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x1595bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x1595c0: 0xc056608  jal         func_159820
    ctx->pc = 0x1595C0u;
    SET_GPR_U32(ctx, 31, 0x1595C8u);
    ctx->pc = 0x1595C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1595C0u;
            // 0x1595c4: 0xafa20014  sw          $v0, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159820u;
    if (runtime->hasFunction(0x159820u)) {
        auto targetFn = runtime->lookupFunction(0x159820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1595C8u; }
        if (ctx->pc != 0x1595C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159820_0x159820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1595C8u; }
        if (ctx->pc != 0x1595C8u) { return; }
    }
    ctx->pc = 0x1595C8u;
label_1595c8:
    // 0x1595c8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1595c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1595cc: 0x1443000a  bne         $v0, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1595CCu;
    {
        const bool branch_taken_0x1595cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1595D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1595CCu;
            // 0x1595d0: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1595cc) {
            ctx->pc = 0x1595F8u;
            goto label_1595f8;
        }
    }
    ctx->pc = 0x1595D4u;
    // 0x1595d4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1595d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1595d8: 0xc056e14  jal         func_15B850
    ctx->pc = 0x1595D8u;
    SET_GPR_U32(ctx, 31, 0x1595E0u);
    ctx->pc = 0x1595DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1595D8u;
            // 0x1595dc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15B850u;
    if (runtime->hasFunction(0x15B850u)) {
        auto targetFn = runtime->lookupFunction(0x15B850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1595E0u; }
        if (ctx->pc != 0x1595E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B850_0x15b850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1595E0u; }
        if (ctx->pc != 0x1595E0u) { return; }
    }
    ctx->pc = 0x1595E0u;
label_1595e0:
    // 0x1595e0: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1595E0u;
    {
        const bool branch_taken_0x1595e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1595E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1595E0u;
            // 0x1595e4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1595e0) {
            ctx->pc = 0x1596E8u;
            goto label_1596e8;
        }
    }
    ctx->pc = 0x1595E8u;
label_1595e8:
    // 0x1595e8: 0xc0563ce  jal         func_158F38
    ctx->pc = 0x1595E8u;
    SET_GPR_U32(ctx, 31, 0x1595F0u);
    ctx->pc = 0x1595ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1595E8u;
            // 0x1595ec: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158F38u;
    if (runtime->hasFunction(0x158F38u)) {
        auto targetFn = runtime->lookupFunction(0x158F38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1595F0u; }
        if (ctx->pc != 0x1595F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158F38_0x158f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1595F0u; }
        if (ctx->pc != 0x1595F0u) { return; }
    }
    ctx->pc = 0x1595F0u;
label_1595f0:
    // 0x1595f0: 0x1000003d  b           . + 4 + (0x3D << 2)
    ctx->pc = 0x1595F0u;
    {
        const bool branch_taken_0x1595f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1595F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1595F0u;
            // 0x1595f4: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1595f0) {
            ctx->pc = 0x1596E8u;
            goto label_1596e8;
        }
    }
    ctx->pc = 0x1595F8u;
label_1595f8:
    // 0x1595f8: 0x24130010  addiu       $s3, $zero, 0x10
    ctx->pc = 0x1595f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1595fc: 0x24150004  addiu       $s5, $zero, 0x4
    ctx->pc = 0x1595fcu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x159600: 0x24170008  addiu       $s7, $zero, 0x8
    ctx->pc = 0x159600u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x159604: 0x24140020  addiu       $s4, $zero, 0x20
    ctx->pc = 0x159604u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x159608: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x159608u;
    {
        const bool branch_taken_0x159608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15960Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159608u;
            // 0x15960c: 0x24160040  addiu       $s6, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159608) {
            ctx->pc = 0x1596ACu;
            goto label_1596ac;
        }
    }
    ctx->pc = 0x159610u;
label_159610:
    // 0x159610: 0x1073001d  beq         $v1, $s3, . + 4 + (0x1D << 2)
    ctx->pc = 0x159610u;
    {
        const bool branch_taken_0x159610 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 19));
        ctx->pc = 0x159614u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159610u;
            // 0x159614: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159610) {
            ctx->pc = 0x159688u;
            goto label_159688;
        }
    }
    ctx->pc = 0x159618u;
    // 0x159618: 0x2c620011  sltiu       $v0, $v1, 0x11
    ctx->pc = 0x159618u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)17) ? 1 : 0);
    // 0x15961c: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x15961Cu;
    {
        const bool branch_taken_0x15961c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15961c) {
            ctx->pc = 0x159640u;
            goto label_159640;
        }
    }
    ctx->pc = 0x159624u;
    // 0x159624: 0x10750014  beq         $v1, $s5, . + 4 + (0x14 << 2)
    ctx->pc = 0x159624u;
    {
        const bool branch_taken_0x159624 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 21));
        ctx->pc = 0x159628u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159624u;
            // 0x159628: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159624) {
            ctx->pc = 0x159678u;
            goto label_159678;
        }
    }
    ctx->pc = 0x15962Cu;
    // 0x15962c: 0x1077000e  beq         $v1, $s7, . + 4 + (0xE << 2)
    ctx->pc = 0x15962Cu;
    {
        const bool branch_taken_0x15962c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 23));
        if (branch_taken_0x15962c) {
            ctx->pc = 0x159668u;
            goto label_159668;
        }
    }
    ctx->pc = 0x159634u;
    // 0x159634: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x159634u;
    {
        const bool branch_taken_0x159634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159634u;
            // 0x159638: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159634) {
            ctx->pc = 0x1596B4u;
            goto label_1596b4;
        }
    }
    ctx->pc = 0x15963Cu;
    // 0x15963c: 0x0  nop
    ctx->pc = 0x15963cu;
    // NOP
label_159640:
    // 0x159640: 0x10740017  beq         $v1, $s4, . + 4 + (0x17 << 2)
    ctx->pc = 0x159640u;
    {
        const bool branch_taken_0x159640 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 20));
        ctx->pc = 0x159644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159640u;
            // 0x159644: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159640) {
            ctx->pc = 0x1596A0u;
            goto label_1596a0;
        }
    }
    ctx->pc = 0x159648u;
    // 0x159648: 0x1476001a  bne         $v1, $s6, . + 4 + (0x1A << 2)
    ctx->pc = 0x159648u;
    {
        const bool branch_taken_0x159648 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 22));
        ctx->pc = 0x15964Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159648u;
            // 0x15964c: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159648) {
            ctx->pc = 0x1596B4u;
            goto label_1596b4;
        }
    }
    ctx->pc = 0x159650u;
    // 0x159650: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x159650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159654: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x159654u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159658: 0xc056632  jal         func_1598C8
    ctx->pc = 0x159658u;
    SET_GPR_U32(ctx, 31, 0x159660u);
    ctx->pc = 0x15965Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159658u;
            // 0x15965c: 0x24120040  addiu       $s2, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1598C8u;
    if (runtime->hasFunction(0x1598C8u)) {
        auto targetFn = runtime->lookupFunction(0x1598C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159660u; }
        if (ctx->pc != 0x159660u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001598C8_0x1598c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159660u; }
        if (ctx->pc != 0x159660u) { return; }
    }
    ctx->pc = 0x159660u;
label_159660:
    // 0x159660: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x159660u;
    {
        const bool branch_taken_0x159660 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159660u;
            // 0x159664: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159660) {
            ctx->pc = 0x1596B0u;
            goto label_1596b0;
        }
    }
    ctx->pc = 0x159668u;
label_159668:
    // 0x159668: 0xc0567ec  jal         func_159FB0
    ctx->pc = 0x159668u;
    SET_GPR_U32(ctx, 31, 0x159670u);
    ctx->pc = 0x15966Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159668u;
            // 0x15966c: 0x24120008  addiu       $s2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159FB0u;
    if (runtime->hasFunction(0x159FB0u)) {
        auto targetFn = runtime->lookupFunction(0x159FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159670u; }
        if (ctx->pc != 0x159670u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159FB0_0x159fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159670u; }
        if (ctx->pc != 0x159670u) { return; }
    }
    ctx->pc = 0x159670u;
label_159670:
    // 0x159670: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x159670u;
    {
        const bool branch_taken_0x159670 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159670u;
            // 0x159674: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159670) {
            ctx->pc = 0x1596B0u;
            goto label_1596b0;
        }
    }
    ctx->pc = 0x159678u;
label_159678:
    // 0x159678: 0xc05689c  jal         func_15A270
    ctx->pc = 0x159678u;
    SET_GPR_U32(ctx, 31, 0x159680u);
    ctx->pc = 0x15967Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159678u;
            // 0x15967c: 0x24120004  addiu       $s2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15A270u;
    if (runtime->hasFunction(0x15A270u)) {
        auto targetFn = runtime->lookupFunction(0x15A270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159680u; }
        if (ctx->pc != 0x159680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015A270_0x15a270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159680u; }
        if (ctx->pc != 0x159680u) { return; }
    }
    ctx->pc = 0x159680u;
label_159680:
    // 0x159680: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x159680u;
    {
        const bool branch_taken_0x159680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159680u;
            // 0x159684: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159680) {
            ctx->pc = 0x1596B0u;
            goto label_1596b0;
        }
    }
    ctx->pc = 0x159688u;
label_159688:
    // 0x159688: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x159688u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15968c: 0xc056a18  jal         func_15A860
    ctx->pc = 0x15968Cu;
    SET_GPR_U32(ctx, 31, 0x159694u);
    ctx->pc = 0x159690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15968Cu;
            // 0x159690: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15A860u;
    if (runtime->hasFunction(0x15A860u)) {
        auto targetFn = runtime->lookupFunction(0x15A860u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159694u; }
        if (ctx->pc != 0x159694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015A860_0x15a860(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x159694u; }
        if (ctx->pc != 0x159694u) { return; }
    }
    ctx->pc = 0x159694u;
label_159694:
    // 0x159694: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x159694u;
    {
        const bool branch_taken_0x159694 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x159698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159694u;
            // 0x159698: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x159694) {
            ctx->pc = 0x1596B0u;
            goto label_1596b0;
        }
    }
    ctx->pc = 0x15969Cu;
    // 0x15969c: 0x0  nop
    ctx->pc = 0x15969cu;
    // NOP
label_1596a0:
    // 0x1596a0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1596a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1596a4: 0xc056a54  jal         func_15A950
    ctx->pc = 0x1596A4u;
    SET_GPR_U32(ctx, 31, 0x1596ACu);
    ctx->pc = 0x1596A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1596A4u;
            // 0x1596a8: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15A950u;
    if (runtime->hasFunction(0x15A950u)) {
        auto targetFn = runtime->lookupFunction(0x15A950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1596ACu; }
        if (ctx->pc != 0x1596ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015A950_0x15a950(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1596ACu; }
        if (ctx->pc != 0x1596ACu) { return; }
    }
    ctx->pc = 0x1596ACu;
label_1596ac:
    // 0x1596ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1596acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1596b0:
    // 0x1596b0: 0x2405ffff  addiu       $a1, $zero, -0x1
    ctx->pc = 0x1596b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1596b4:
    // 0x1596b4: 0xc056bd0  jal         func_15AF40
    ctx->pc = 0x1596B4u;
    SET_GPR_U32(ctx, 31, 0x1596BCu);
    ctx->pc = 0x1596B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1596B4u;
            // 0x1596b8: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15AF40u;
    if (runtime->hasFunction(0x15AF40u)) {
        auto targetFn = runtime->lookupFunction(0x15AF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1596BCu; }
        if (ctx->pc != 0x1596BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015AF40_0x15af40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1596BCu; }
        if (ctx->pc != 0x1596BCu) { return; }
    }
    ctx->pc = 0x1596BCu;
label_1596bc:
    // 0x1596bc: 0x5440ffca  bnel        $v0, $zero, . + 4 + (-0x36 << 2)
    ctx->pc = 0x1596BCu;
    {
        const bool branch_taken_0x1596bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1596bc) {
            ctx->pc = 0x1596C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1596BCu;
            // 0x1596c0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1595E8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1595e8;
        }
    }
    ctx->pc = 0x1596C4u;
    // 0x1596c4: 0xc0565c4  jal         func_159710
    ctx->pc = 0x1596C4u;
    SET_GPR_U32(ctx, 31, 0x1596CCu);
    ctx->pc = 0x1596C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1596C4u;
            // 0x1596c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159710u;
    if (runtime->hasFunction(0x159710u)) {
        auto targetFn = runtime->lookupFunction(0x159710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1596CCu; }
        if (ctx->pc != 0x1596CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159710_0x159710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1596CCu; }
        if (ctx->pc != 0x1596CCu) { return; }
    }
    ctx->pc = 0x1596CCu;
label_1596cc:
    // 0x1596cc: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1596ccu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1596d0: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1596D0u;
    {
        const bool branch_taken_0x1596d0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1596D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1596D0u;
            // 0x1596d4: 0x30620003  andi        $v0, $v1, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1596d0) {
            ctx->pc = 0x1596E0u;
            goto label_1596e0;
        }
    }
    ctx->pc = 0x1596D8u;
    // 0x1596d8: 0x1040ffcd  beqz        $v0, . + 4 + (-0x33 << 2)
    ctx->pc = 0x1596D8u;
    {
        const bool branch_taken_0x1596d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1596d8) {
            ctx->pc = 0x159610u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_159610;
        }
    }
    ctx->pc = 0x1596E0u;
label_1596e0:
    // 0x1596e0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1596e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1596e4: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1596e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1596e8:
    // 0x1596e8: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1596e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1596ec: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1596ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1596f0: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x1596f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1596f4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1596f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1596f8: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x1596f8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1596fc: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x1596fcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x159700: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x159700u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x159704: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x159704u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x159708: 0x3e00008  jr          $ra
    ctx->pc = 0x159708u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15970Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159708u;
            // 0x15970c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x159554u: goto label_159554;
            case 0x159568u: goto label_159568;
            case 0x159570u: goto label_159570;
            case 0x159594u: goto label_159594;
            case 0x1595ACu: goto label_1595ac;
            case 0x1595C8u: goto label_1595c8;
            case 0x1595E0u: goto label_1595e0;
            case 0x1595E8u: goto label_1595e8;
            case 0x1595F0u: goto label_1595f0;
            case 0x1595F8u: goto label_1595f8;
            case 0x159610u: goto label_159610;
            case 0x159640u: goto label_159640;
            case 0x159660u: goto label_159660;
            case 0x159668u: goto label_159668;
            case 0x159670u: goto label_159670;
            case 0x159678u: goto label_159678;
            case 0x159680u: goto label_159680;
            case 0x159688u: goto label_159688;
            case 0x159694u: goto label_159694;
            case 0x1596A0u: goto label_1596a0;
            case 0x1596ACu: goto label_1596ac;
            case 0x1596B0u: goto label_1596b0;
            case 0x1596B4u: goto label_1596b4;
            case 0x1596BCu: goto label_1596bc;
            case 0x1596CCu: goto label_1596cc;
            case 0x1596E0u: goto label_1596e0;
            case 0x1596E8u: goto label_1596e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x159710u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
