#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168718
// Address: 0x168718 - 0x168820
void sub_00168718_0x168718(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168718_0x168718");
#endif

    switch (ctx->pc) {
        case 0x168758u: goto label_168758;
        case 0x168760u: goto label_168760;
        case 0x16876cu: goto label_16876c;
        case 0x168790u: goto label_168790;
        case 0x1687c0u: goto label_1687c0;
        case 0x1687e0u: goto label_1687e0;
        default: break;
    }

    ctx->pc = 0x168718u;

    // 0x168718: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x168718u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16871c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x16871cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x168720: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x168720u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168724: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x168724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x168728: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x168728u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16872c: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x16872cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x168730: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x168730u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168734: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x168734u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x168738: 0x293b021  addu        $s6, $s4, $s3
    ctx->pc = 0x168738u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 19)));
    // 0x16873c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16873cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x168740: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x168740u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x168744: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x168744u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x168748: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x168748u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x16874c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16874cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x168750: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x168750u;
    {
        const bool branch_taken_0x168750 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x168754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168750u;
            // 0x168754: 0x8eb70010  lw          $s7, 0x10($s5) (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168750) {
            ctx->pc = 0x168778u;
            goto label_168778;
        }
    }
    ctx->pc = 0x168758u;
label_168758:
    // 0x168758: 0xc05a2ea  jal         func_168BA8
    ctx->pc = 0x168758u;
    SET_GPR_U32(ctx, 31, 0x168760u);
    ctx->pc = 0x168BA8u;
    if (runtime->hasFunction(0x168BA8u)) {
        auto targetFn = runtime->lookupFunction(0x168BA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168760u; }
        if (ctx->pc != 0x168760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168BA8_0x168ba8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168760u; }
        if (ctx->pc != 0x168760u) { return; }
    }
    ctx->pc = 0x168760u;
label_168760:
    // 0x168760: 0x14400024  bnez        $v0, . + 4 + (0x24 << 2)
    ctx->pc = 0x168760u;
    {
        const bool branch_taken_0x168760 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168764u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168760u;
            // 0x168764: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168760) {
            ctx->pc = 0x1687F4u;
            goto label_1687f4;
        }
    }
    ctx->pc = 0x168768u;
    // 0x168768: 0x2541023  subu        $v0, $s2, $s4
    ctx->pc = 0x168768u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
label_16876c:
    // 0x16876c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x16876cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x168770: 0x2629823  subu        $s3, $s3, $v0
    ctx->pc = 0x168770u;
    SET_GPR_S32(ctx, 19, (int32_t)SUB32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x168774: 0x282a021  addu        $s4, $s4, $v0
    ctx->pc = 0x168774u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 2)));
label_168778:
    // 0x168778: 0x1a60001e  blez        $s3, . + 4 + (0x1E << 2)
    ctx->pc = 0x168778u;
    {
        const bool branch_taken_0x168778 = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x16877Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168778u;
            // 0x16877c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168778) {
            ctx->pc = 0x1687F4u;
            goto label_1687f4;
        }
    }
    ctx->pc = 0x168780u;
    // 0x168780: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x168780u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168784: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x168784u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168788: 0xc05a208  jal         func_168820
    ctx->pc = 0x168788u;
    SET_GPR_U32(ctx, 31, 0x168790u);
    ctx->pc = 0x16878Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168788u;
            // 0x16878c: 0x3c060004  lui         $a2, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4 << 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168820u;
    if (runtime->hasFunction(0x168820u)) {
        auto targetFn = runtime->lookupFunction(0x168820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168790u; }
        if (ctx->pc != 0x168790u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168820_0x168820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168790u; }
        if (ctx->pc != 0x168790u) { return; }
    }
    ctx->pc = 0x168790u;
label_168790:
    // 0x168790: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x168790u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168794: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x168794u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168798: 0x12400015  beqz        $s2, . + 4 + (0x15 << 2)
    ctx->pc = 0x168798u;
    {
        const bool branch_taken_0x168798 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x16879Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168798u;
            // 0x16879c: 0x2d22823  subu        $a1, $s6, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168798) {
            ctx->pc = 0x1687F0u;
            goto label_1687f0;
        }
    }
    ctx->pc = 0x1687A0u;
    // 0x1687a0: 0x92420003  lbu         $v0, 0x3($s2)
    ctx->pc = 0x1687a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 3)));
    // 0x1687a4: 0x24420040  addiu       $v0, $v0, 0x40
    ctx->pc = 0x1687a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 64));
    // 0x1687a8: 0x304200ff  andi        $v0, $v0, 0xFF
    ctx->pc = 0x1687a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1687ac: 0x2c420020  sltiu       $v0, $v0, 0x20
    ctx->pc = 0x1687acu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)32) ? 1 : 0);
    // 0x1687b0: 0x5040ffee  beql        $v0, $zero, . + 4 + (-0x12 << 2)
    ctx->pc = 0x1687B0u;
    {
        const bool branch_taken_0x1687b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1687b0) {
            ctx->pc = 0x1687B4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1687B0u;
            // 0x1687b4: 0x2541023  subu        $v0, $s2, $s4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x16876Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16876c;
        }
    }
    ctx->pc = 0x1687B8u;
    // 0x1687b8: 0xc05a222  jal         func_168888
    ctx->pc = 0x1687B8u;
    SET_GPR_U32(ctx, 31, 0x1687C0u);
    ctx->pc = 0x1687BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1687B8u;
            // 0x1687bc: 0x2e0802d  daddu       $s0, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168888u;
    if (runtime->hasFunction(0x168888u)) {
        auto targetFn = runtime->lookupFunction(0x168888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1687C0u; }
        if (ctx->pc != 0x1687C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168888_0x168888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1687C0u; }
        if (ctx->pc != 0x1687C0u) { return; }
    }
    ctx->pc = 0x1687C0u;
label_1687c0:
    // 0x1687c0: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x1687c0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1687c4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1687c4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1687c8: 0x2d11023  subu        $v0, $s6, $s1
    ctx->pc = 0x1687c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 17)));
    // 0x1687cc: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1687ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1687d0: 0x50182a  slt         $v1, $v0, $s0
    ctx->pc = 0x1687d0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1687d4: 0x43800b  movn        $s0, $v0, $v1
    ctx->pc = 0x1687d4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
    // 0x1687d8: 0xc05a242  jal         func_168908
    ctx->pc = 0x1687D8u;
    SET_GPR_U32(ctx, 31, 0x1687E0u);
    ctx->pc = 0x1687DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1687D8u;
            // 0x1687dc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168908u;
    if (runtime->hasFunction(0x168908u)) {
        auto targetFn = runtime->lookupFunction(0x168908u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1687E0u; }
        if (ctx->pc != 0x1687E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168908_0x168908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1687E0u; }
        if (ctx->pc != 0x1687E0u) { return; }
    }
    ctx->pc = 0x1687E0u;
label_1687e0:
    // 0x1687e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1687e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1687e4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1687e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1687e8: 0x1040ffdb  beqz        $v0, . + 4 + (-0x25 << 2)
    ctx->pc = 0x1687E8u;
    {
        const bool branch_taken_0x1687e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1687ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1687E8u;
            // 0x1687ec: 0x2a0302d  daddu       $a2, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1687e8) {
            ctx->pc = 0x168758u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_168758;
        }
    }
    ctx->pc = 0x1687F0u;
label_1687f0:
    // 0x1687f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1687f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1687f4:
    // 0x1687f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1687f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1687f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1687f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1687fc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1687fcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168800: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x168800u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x168804: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x168804u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x168808: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x168808u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16880c: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x16880cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x168810: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x168810u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x168814: 0x3e00008  jr          $ra
    ctx->pc = 0x168814u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168814u;
            // 0x168818: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168758u: goto label_168758;
            case 0x168760u: goto label_168760;
            case 0x16876Cu: goto label_16876c;
            case 0x168778u: goto label_168778;
            case 0x168790u: goto label_168790;
            case 0x1687C0u: goto label_1687c0;
            case 0x1687E0u: goto label_1687e0;
            case 0x1687F0u: goto label_1687f0;
            case 0x1687F4u: goto label_1687f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16881Cu;
    // 0x16881c: 0x0  nop
    ctx->pc = 0x16881cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
