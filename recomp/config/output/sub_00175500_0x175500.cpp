#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175500
// Address: 0x175500 - 0x175588
void sub_00175500_0x175500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175500_0x175500");
#endif

    switch (ctx->pc) {
        case 0x17553cu: goto label_17553c;
        case 0x175564u: goto label_175564;
        default: break;
    }

    ctx->pc = 0x175500u;

    // 0x175500: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x175504: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x175504u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x175508: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17550c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x17550cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175510: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x175510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175514: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x175514u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175518: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x175518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17551c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x17551cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175520: 0x16020008  bne         $s0, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x175520u;
    {
        const bool branch_taken_0x175520 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x175524u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175520u;
            // 0x175524: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175520) {
            ctx->pc = 0x175544u;
            goto label_175544;
        }
    }
    ctx->pc = 0x175528u;
    // 0x175528: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x175528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17552c: 0x56220006  bnel        $s1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x17552Cu;
    {
        const bool branch_taken_0x17552c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x17552c) {
            ctx->pc = 0x175530u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17552Cu;
            // 0x175530: 0x24020005  addiu       $v0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x175548u;
            goto label_175548;
        }
    }
    ctx->pc = 0x175534u;
    // 0x175534: 0xc05df24  jal         func_177C90
    ctx->pc = 0x175534u;
    SET_GPR_U32(ctx, 31, 0x17553Cu);
    ctx->pc = 0x175538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175534u;
            // 0x175538: 0x24050003  addiu       $a1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17553Cu; }
        if (ctx->pc != 0x17553Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17553Cu; }
        if (ctx->pc != 0x17553Cu) { return; }
    }
    ctx->pc = 0x17553Cu;
label_17553c:
    // 0x17553c: 0x5040000d  beql        $v0, $zero, . + 4 + (0xD << 2)
    ctx->pc = 0x17553Cu;
    {
        const bool branch_taken_0x17553c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x17553c) {
            ctx->pc = 0x175540u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17553Cu;
            // 0x175540: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x175574u;
            goto label_175574;
        }
    }
    ctx->pc = 0x175544u;
label_175544:
    // 0x175544: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x175544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
label_175548:
    // 0x175548: 0x16020009  bne         $s0, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x175548u;
    {
        const bool branch_taken_0x175548 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 2));
        ctx->pc = 0x17554Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175548u;
            // 0x17554c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175548) {
            ctx->pc = 0x175570u;
            goto label_175570;
        }
    }
    ctx->pc = 0x175550u;
    // 0x175550: 0x56220008  bnel        $s1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x175550u;
    {
        const bool branch_taken_0x175550 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x175550) {
            ctx->pc = 0x175554u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x175550u;
            // 0x175554: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x175574u;
            goto label_175574;
        }
    }
    ctx->pc = 0x175558u;
    // 0x175558: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x175558u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17555c: 0xc05df24  jal         func_177C90
    ctx->pc = 0x17555Cu;
    SET_GPR_U32(ctx, 31, 0x175564u);
    ctx->pc = 0x175560u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17555Cu;
            // 0x175560: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C90u;
    if (runtime->hasFunction(0x177C90u)) {
        auto targetFn = runtime->lookupFunction(0x177C90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175564u; }
        if (ctx->pc != 0x175564u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C90_0x177c90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175564u; }
        if (ctx->pc != 0x175564u) { return; }
    }
    ctx->pc = 0x175564u;
label_175564:
    // 0x175564: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x175564u;
    {
        const bool branch_taken_0x175564 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175564u;
            // 0x175568: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175564) {
            ctx->pc = 0x175574u;
            goto label_175574;
        }
    }
    ctx->pc = 0x17556Cu;
    // 0x17556c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17556cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_175570:
    // 0x175570: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175570u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_175574:
    // 0x175574: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175574u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x175578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17557c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17557cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x175580: 0x3e00008  jr          $ra
    ctx->pc = 0x175580u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175584u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175580u;
            // 0x175584: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17553Cu: goto label_17553c;
            case 0x175544u: goto label_175544;
            case 0x175548u: goto label_175548;
            case 0x175564u: goto label_175564;
            case 0x175570u: goto label_175570;
            case 0x175574u: goto label_175574;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175588u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
