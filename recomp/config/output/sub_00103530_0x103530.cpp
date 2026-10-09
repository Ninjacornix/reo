#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00103530
// Address: 0x103530 - 0x103630
void sub_00103530_0x103530(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00103530_0x103530");
#endif

    switch (ctx->pc) {
        case 0x103554u: goto label_103554;
        case 0x103560u: goto label_103560;
        case 0x1035d4u: goto label_1035d4;
        case 0x1035e0u: goto label_1035e0;
        default: break;
    }

    ctx->pc = 0x103530u;

    // 0x103530: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x103530u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x103534: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x103534u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x103538: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x103538u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10353c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10353cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x103540: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x103540u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x103544: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x103544u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103548: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x103548u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x10354c: 0xc040c00  jal         func_103000
    ctx->pc = 0x10354Cu;
    SET_GPR_U32(ctx, 31, 0x103554u);
    ctx->pc = 0x103550u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10354Cu;
            // 0x103550: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103000u;
    if (runtime->hasFunction(0x103000u)) {
        auto targetFn = runtime->lookupFunction(0x103000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103554u; }
        if (ctx->pc != 0x103554u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103000_0x103000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103554u; }
        if (ctx->pc != 0x103554u) { return; }
    }
    ctx->pc = 0x103554u;
label_103554:
    // 0x103554: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x103554u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x103558: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x103558u;
    SET_GPR_U32(ctx, 31, 0x103560u);
    ctx->pc = 0x10355Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x103558u;
            // 0x10355c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103560u; }
        if (ctx->pc != 0x103560u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x103560u; }
        if (ctx->pc != 0x103560u) { return; }
    }
    ctx->pc = 0x103560u;
label_103560:
    // 0x103560: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x103560u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x103564: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x103564u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x103568: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x103568u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x10356c: 0x54620001  bnel        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x10356Cu;
    {
        const bool branch_taken_0x10356c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x10356c) {
            ctx->pc = 0x103570u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10356Cu;
            // 0x103570: 0xae110010  sw          $s1, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x103574u;
            goto label_103574;
        }
    }
    ctx->pc = 0x103574u;
label_103574:
    // 0x103574: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x103574u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x103578: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x103578u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x10357c: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x10357cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x103580: 0xae120020  sw          $s2, 0x20($s0)
    ctx->pc = 0x103580u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 18));
    // 0x103584: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x103584u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x103588: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x103588u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10358c: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x10358cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x103590: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x103590u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x103594: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x103594u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x103598: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x103598u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10359c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x10359cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1035a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1035a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1035a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1035A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1035A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1035A4u;
            // 0x1035a8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103554u: goto label_103554;
            case 0x103560u: goto label_103560;
            case 0x103574u: goto label_103574;
            case 0x1035D4u: goto label_1035d4;
            case 0x1035E0u: goto label_1035e0;
            case 0x1035F4u: goto label_1035f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1035ACu;
    // 0x1035ac: 0x0  nop
    ctx->pc = 0x1035acu;
    // NOP
    // 0x1035b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1035b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1035b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1035b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1035b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1035b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1035bc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1035bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1035c0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x1035c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1035c4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1035c4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1035c8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1035c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1035cc: 0xc040c00  jal         func_103000
    ctx->pc = 0x1035CCu;
    SET_GPR_U32(ctx, 31, 0x1035D4u);
    ctx->pc = 0x1035D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1035CCu;
            // 0x1035d0: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x103000u;
    if (runtime->hasFunction(0x103000u)) {
        auto targetFn = runtime->lookupFunction(0x103000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1035D4u; }
        if (ctx->pc != 0x1035D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00103000_0x103000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1035D4u; }
        if (ctx->pc != 0x1035D4u) { return; }
    }
    ctx->pc = 0x1035D4u;
label_1035d4:
    // 0x1035d4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1035d4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1035d8: 0xc040bc2  jal         func_102F08
    ctx->pc = 0x1035D8u;
    SET_GPR_U32(ctx, 31, 0x1035E0u);
    ctx->pc = 0x1035DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1035D8u;
            // 0x1035dc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x102F08u;
    if (runtime->hasFunction(0x102F08u)) {
        auto targetFn = runtime->lookupFunction(0x102F08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1035E0u; }
        if (ctx->pc != 0x1035E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00102F08_0x102f08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1035E0u; }
        if (ctx->pc != 0x1035E0u) { return; }
    }
    ctx->pc = 0x1035E0u;
label_1035e0:
    // 0x1035e0: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x1035e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x1035e4: 0x8e030010  lw          $v1, 0x10($s0)
    ctx->pc = 0x1035e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1035e8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1035e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1035ec: 0x54620001  bnel        $v1, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x1035ECu;
    {
        const bool branch_taken_0x1035ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1035ec) {
            ctx->pc = 0x1035F0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1035ECu;
            // 0x1035f0: 0xae110010  sw          $s1, 0x10($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1035F4u;
            goto label_1035f4;
        }
    }
    ctx->pc = 0x1035F4u;
label_1035f4:
    // 0x1035f4: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1035f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1035f8: 0x2403fff3  addiu       $v1, $zero, -0xD
    ctx->pc = 0x1035f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967283));
    // 0x1035fc: 0x2404fffe  addiu       $a0, $zero, -0x2
    ctx->pc = 0x1035fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x103600: 0xae120020  sw          $s2, 0x20($s0)
    ctx->pc = 0x103600u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 18));
    // 0x103604: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x103604u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x103608: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x103608u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10360c: 0x34420008  ori         $v0, $v0, 0x8
    ctx->pc = 0x10360cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8);
    // 0x103610: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x103610u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x103614: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x103614u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x103618: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x103618u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10361c: 0x34420100  ori         $v0, $v0, 0x100
    ctx->pc = 0x10361cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)256);
    // 0x103620: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x103620u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x103624: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x103624u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x103628: 0x3e00008  jr          $ra
    ctx->pc = 0x103628u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10362Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x103628u;
            // 0x10362c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x103554u: goto label_103554;
            case 0x103560u: goto label_103560;
            case 0x103574u: goto label_103574;
            case 0x1035D4u: goto label_1035d4;
            case 0x1035E0u: goto label_1035e0;
            case 0x1035F4u: goto label_1035f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x103630u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
