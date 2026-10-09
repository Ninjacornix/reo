#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C330
// Address: 0x16c330 - 0x16c3c4
void sub_0016C330_0x16c330(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C330_0x16c330");
#endif

    switch (ctx->pc) {
        case 0x16c364u: goto label_16c364;
        case 0x16c374u: goto label_16c374;
        case 0x16c390u: goto label_16c390;
        case 0x16c398u: goto label_16c398;
        case 0x16c3a4u: goto label_16c3a4;
        case 0x16c3acu: goto label_16c3ac;
        default: break;
    }

    ctx->pc = 0x16c330u;

    // 0x16c330: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c334: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16c334u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16c338: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x16c338u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c33c: 0x805b0d2  j           func_16C348
    ctx->pc = 0x16C33Cu;
    ctx->pc = 0x16C340u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C33Cu;
            // 0x16c340: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C348u;
    goto label_16c348;
    ctx->pc = 0x16C344u;
    // 0x16c344: 0x0  nop
    ctx->pc = 0x16c344u;
    // NOP
label_16c348:
    // 0x16c348: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16c348u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16c34c: 0x24050005  addiu       $a1, $zero, 0x5
    ctx->pc = 0x16c34cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x16c350: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16c350u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16c354: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c354u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c358: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16c358u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16c35c: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16C35Cu;
    SET_GPR_U32(ctx, 31, 0x16C364u);
    ctx->pc = 0x16C360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C35Cu;
            // 0x16c360: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C364u; }
        if (ctx->pc != 0x16C364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C364u; }
        if (ctx->pc != 0x16C364u) { return; }
    }
    ctx->pc = 0x16C364u;
label_16c364:
    // 0x16c364: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x16C364u;
    {
        const bool branch_taken_0x16c364 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C364u;
            // 0x16c368: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c364) {
            ctx->pc = 0x16C3B0u;
            goto label_16c3b0;
        }
    }
    ctx->pc = 0x16C36Cu;
    // 0x16c36c: 0xc05b10e  jal         func_16C438
    ctx->pc = 0x16C36Cu;
    SET_GPR_U32(ctx, 31, 0x16C374u);
    ctx->pc = 0x16C438u;
    if (runtime->hasFunction(0x16C438u)) {
        auto targetFn = runtime->lookupFunction(0x16C438u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C374u; }
        if (ctx->pc != 0x16C374u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C438_0x16c438(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C374u; }
        if (ctx->pc != 0x16C374u) { return; }
    }
    ctx->pc = 0x16C374u;
label_16c374:
    // 0x16c374: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x16c374u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16c378: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x16C378u;
    {
        const bool branch_taken_0x16c378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x16C37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C378u;
            // 0x16c37c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c378) {
            ctx->pc = 0x16C388u;
            goto label_16c388;
        }
    }
    ctx->pc = 0x16C380u;
    // 0x16c380: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x16C380u;
    {
        const bool branch_taken_0x16c380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C380u;
            // 0x16c384: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c380) {
            ctx->pc = 0x16C3B0u;
            goto label_16c3b0;
        }
    }
    ctx->pc = 0x16C388u;
label_16c388:
    // 0x16c388: 0xc05b0f2  jal         func_16C3C8
    ctx->pc = 0x16C388u;
    SET_GPR_U32(ctx, 31, 0x16C390u);
    ctx->pc = 0x16C3C8u;
    if (runtime->hasFunction(0x16C3C8u)) {
        auto targetFn = runtime->lookupFunction(0x16C3C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C390u; }
        if (ctx->pc != 0x16C390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C3C8_0x16c3c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C390u; }
        if (ctx->pc != 0x16C390u) { return; }
    }
    ctx->pc = 0x16C390u;
label_16c390:
    // 0x16c390: 0xc05b1e0  jal         func_16C780
    ctx->pc = 0x16C390u;
    SET_GPR_U32(ctx, 31, 0x16C398u);
    ctx->pc = 0x16C394u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C390u;
            // 0x16c394: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C780u;
    if (runtime->hasFunction(0x16C780u)) {
        auto targetFn = runtime->lookupFunction(0x16C780u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C398u; }
        if (ctx->pc != 0x16C398u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C780_0x16c780(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C398u; }
        if (ctx->pc != 0x16C398u) { return; }
    }
    ctx->pc = 0x16C398u;
label_16c398:
    // 0x16c398: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16c398u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c39c: 0xc05b114  jal         func_16C450
    ctx->pc = 0x16C39Cu;
    SET_GPR_U32(ctx, 31, 0x16C3A4u);
    ctx->pc = 0x16C3A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C39Cu;
            // 0x16c3a0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C450u;
    if (runtime->hasFunction(0x16C450u)) {
        auto targetFn = runtime->lookupFunction(0x16C450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3A4u; }
        if (ctx->pc != 0x16C3A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C450_0x16c450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3A4u; }
        if (ctx->pc != 0x16C3A4u) { return; }
    }
    ctx->pc = 0x16C3A4u;
label_16c3a4:
    // 0x16c3a4: 0xc05b1ae  jal         func_16C6B8
    ctx->pc = 0x16C3A4u;
    SET_GPR_U32(ctx, 31, 0x16C3ACu);
    ctx->pc = 0x16C3A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C3A4u;
            // 0x16c3a8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16C6B8u;
    if (runtime->hasFunction(0x16C6B8u)) {
        auto targetFn = runtime->lookupFunction(0x16C6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3ACu; }
        if (ctx->pc != 0x16C3ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C6B8_0x16c6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3ACu; }
        if (ctx->pc != 0x16C3ACu) { return; }
    }
    ctx->pc = 0x16C3ACu;
label_16c3ac:
    // 0x16c3ac: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x16c3acu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_16c3b0:
    // 0x16c3b0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c3b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c3b4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16c3b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c3b8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16c3b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c3bc: 0x3e00008  jr          $ra
    ctx->pc = 0x16C3BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C3C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C3BCu;
            // 0x16c3c0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C348u: goto label_16c348;
            case 0x16C364u: goto label_16c364;
            case 0x16C374u: goto label_16c374;
            case 0x16C388u: goto label_16c388;
            case 0x16C390u: goto label_16c390;
            case 0x16C398u: goto label_16c398;
            case 0x16C3A4u: goto label_16c3a4;
            case 0x16C3ACu: goto label_16c3ac;
            case 0x16C3B0u: goto label_16c3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C3C4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
