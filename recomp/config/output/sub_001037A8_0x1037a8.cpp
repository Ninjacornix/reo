#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001037A8
// Address: 0x1037a8 - 0x103898
void sub_001037A8_0x1037a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001037A8_0x1037a8");
#endif

    switch (ctx->pc) {
        case 0x103820u: goto label_103820;
        case 0x103838u: goto label_103838;
        default: break;
    }

    ctx->pc = 0x1037a8u;

    // 0x1037a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1037a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1037ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1037acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1037b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1037b4: 0x2406000a  addiu       $a2, $zero, 0xA
    ctx->pc = 0x1037b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1037b8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1037b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1037bc: 0x80432c6  j           func_10CB18
    ctx->pc = 0x1037BCu;
    ctx->pc = 0x1037C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1037BCu;
            // 0x1037c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10CB18u;
    if (runtime->hasFunction(0x10CB18u)) {
        auto targetFn = runtime->lookupFunction(0x10CB18u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0010CB18_0x10cb18(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1037C4u;
    // 0x1037c4: 0x0  nop
    ctx->pc = 0x1037c4u;
    // NOP
    // 0x1037c8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1037c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1037cc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1037ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1037d0: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1037d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037d4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1037d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1037d8: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1037d8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037dc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1037dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1037e0: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1037e0u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037e4: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1037e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1037e8: 0x100a82d  daddu       $s5, $t0, $zero
    ctx->pc = 0x1037e8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037ec: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x1037ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x1037f0: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1037f0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037f4: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x1037f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x1037f8: 0x80b82d  daddu       $s7, $a0, $zero
    ctx->pc = 0x1037f8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1037fc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1037fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103800: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x103800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x103804: 0x12400017  beqz        $s2, . + 4 + (0x17 << 2)
    ctx->pc = 0x103804u;
    {
        const bool branch_taken_0x103804 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x103808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103804u;
            // 0x103808: 0xffbf0040  sd          $ra, 0x40($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103804) {
            ctx->pc = 0x103864u;
            goto label_103864;
        }
    }
    ctx->pc = 0x10380Cu;
    // 0x10380c: 0x12600016  beqz        $s3, . + 4 + (0x16 << 2)
    ctx->pc = 0x10380Cu;
    {
        const bool branch_taken_0x10380c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x103810u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10380Cu;
            // 0x103810: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10380c) {
            ctx->pc = 0x103868u;
            goto label_103868;
        }
    }
    ctx->pc = 0x103814u;
    // 0x103814: 0x12400015  beqz        $s2, . + 4 + (0x15 << 2)
    ctx->pc = 0x103814u;
    {
        const bool branch_taken_0x103814 = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        ctx->pc = 0x103818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103814u;
            // 0x103818: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103814) {
            ctx->pc = 0x10386Cu;
            goto label_10386c;
        }
    }
    ctx->pc = 0x10381Cu;
    // 0x10381c: 0x2921021  addu        $v0, $s4, $s2
    ctx->pc = 0x10381cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
label_103820:
    // 0x103820: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x103820u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103824: 0x28842  srl         $s1, $v0, 1
    ctx->pc = 0x103824u;
    SET_GPR_S32(ctx, 17, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x103828: 0x2331018  mult        $v0, $s1, $s3
    ctx->pc = 0x103828u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 19); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x10382c: 0x568021  addu        $s0, $v0, $s6
    ctx->pc = 0x10382cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x103830: 0x2a0f809  jalr        $s5
    ctx->pc = 0x103830u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 21);
        SET_GPR_U32(ctx, 31, 0x103838u);
        ctx->pc = 0x103834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103830u;
            // 0x103834: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x103838u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103820u: goto label_103820;
            case 0x103838u: goto label_103838;
            case 0x103850u: goto label_103850;
            case 0x103858u: goto label_103858;
            case 0x103864u: goto label_103864;
            case 0x103868u: goto label_103868;
            case 0x10386Cu: goto label_10386c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x103838u; }
            if (ctx->pc != 0x103838u) { return; }
        }
        }
    }
    ctx->pc = 0x103838u;
label_103838:
    // 0x103838: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x103838u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10383c: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x10383Cu;
    {
        const bool branch_taken_0x10383c = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x103840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10383Cu;
            // 0x103840: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10383c) {
            ctx->pc = 0x103850u;
            goto label_103850;
        }
    }
    ctx->pc = 0x103844u;
    // 0x103844: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x103844u;
    {
        const bool branch_taken_0x103844 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x103848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103844u;
            // 0x103848: 0x220902d  daddu       $s2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103844) {
            ctx->pc = 0x103858u;
            goto label_103858;
        }
    }
    ctx->pc = 0x10384Cu;
    // 0x10384c: 0x0  nop
    ctx->pc = 0x10384cu;
    // NOP
label_103850:
    // 0x103850: 0x18600005  blez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x103850u;
    {
        const bool branch_taken_0x103850 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x103854u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103850u;
            // 0x103854: 0x26340001  addiu       $s4, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x103850) {
            ctx->pc = 0x103868u;
            goto label_103868;
        }
    }
    ctx->pc = 0x103858u;
label_103858:
    // 0x103858: 0x292102b  sltu        $v0, $s4, $s2
    ctx->pc = 0x103858u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 18)) ? 1 : 0);
    // 0x10385c: 0x1440fff0  bnez        $v0, . + 4 + (-0x10 << 2)
    ctx->pc = 0x10385Cu;
    {
        const bool branch_taken_0x10385c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x103860u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10385Cu;
            // 0x103860: 0x2921021  addu        $v0, $s4, $s2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 18)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10385c) {
            ctx->pc = 0x103820u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_103820;
        }
    }
    ctx->pc = 0x103864u;
label_103864:
    // 0x103864: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x103864u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_103868:
    // 0x103868: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103868u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_10386c:
    // 0x10386c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x10386cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x103870: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x103870u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x103874: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x103874u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x103878: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x103878u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10387c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x10387cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x103880: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x103880u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x103884: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x103884u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x103888: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x103888u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10388c: 0x3e00008  jr          $ra
    ctx->pc = 0x10388Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x103890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10388Cu;
            // 0x103890: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103820u: goto label_103820;
            case 0x103838u: goto label_103838;
            case 0x103850u: goto label_103850;
            case 0x103858u: goto label_103858;
            case 0x103864u: goto label_103864;
            case 0x103868u: goto label_103868;
            case 0x10386Cu: goto label_10386c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103894u;
    // 0x103894: 0x0  nop
    ctx->pc = 0x103894u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
