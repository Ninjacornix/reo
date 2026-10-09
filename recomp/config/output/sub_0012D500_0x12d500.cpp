#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012D500
// Address: 0x12d500 - 0x12d58c
void sub_0012D500_0x12d500(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012D500_0x12d500");
#endif

    switch (ctx->pc) {
        case 0x12d528u: goto label_12d528;
        case 0x12d534u: goto label_12d534;
        case 0x12d540u: goto label_12d540;
        default: break;
    }

    ctx->pc = 0x12d500u;

    // 0x12d500: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x12d500u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12d504: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12d504u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12d508: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12d508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12d50c: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x12d50cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d510: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x12d510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x12d514: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x12d514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x12d518: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12d518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12d51c: 0x8e510004  lw          $s1, 0x4($s2)
    ctx->pc = 0x12d51cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x12d520: 0xc0493be  jal         func_124EF8
    ctx->pc = 0x12D520u;
    SET_GPR_U32(ctx, 31, 0x12D528u);
    ctx->pc = 0x12D524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D520u;
            // 0x12d524: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124EF8u;
    if (runtime->hasFunction(0x124EF8u)) {
        auto targetFn = runtime->lookupFunction(0x124EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D528u; }
        if (ctx->pc != 0x12D528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124EF8_0x124ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D528u; }
        if (ctx->pc != 0x12D528u) { return; }
    }
    ctx->pc = 0x12D528u;
label_12d528:
    // 0x12d528: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d528u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d52c: 0xc0494ae  jal         func_1252B8
    ctx->pc = 0x12D52Cu;
    SET_GPR_U32(ctx, 31, 0x12D534u);
    ctx->pc = 0x12D530u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D52Cu;
            // 0x12d530: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252B8u;
    if (runtime->hasFunction(0x1252B8u)) {
        auto targetFn = runtime->lookupFunction(0x1252B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D534u; }
        if (ctx->pc != 0x12D534u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001252B8_0x1252b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D534u; }
        if (ctx->pc != 0x12D534u) { return; }
    }
    ctx->pc = 0x12D534u;
label_12d534:
    // 0x12d534: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x12d534u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12d538: 0xc0494b0  jal         func_1252C0
    ctx->pc = 0x12D538u;
    SET_GPR_U32(ctx, 31, 0x12D540u);
    ctx->pc = 0x12D53Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12D538u;
            // 0x12d53c: 0x40982d  daddu       $s3, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1252C0u;
    if (runtime->hasFunction(0x1252C0u)) {
        auto targetFn = runtime->lookupFunction(0x1252C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D540u; }
        if (ctx->pc != 0x12D540u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001252C0_0x1252c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12D540u; }
        if (ctx->pc != 0x12D540u) { return; }
    }
    ctx->pc = 0x12D540u;
label_12d540:
    // 0x12d540: 0x8e440034  lw          $a0, 0x34($s2)
    ctx->pc = 0x12d540u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 52)));
    // 0x12d544: 0x8e46002c  lw          $a2, 0x2C($s2)
    ctx->pc = 0x12d544u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 44)));
    // 0x12d548: 0x2048023  subu        $s0, $s0, $a0
    ctx->pc = 0x12d548u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 4)));
    // 0x12d54c: 0x8e450030  lw          $a1, 0x30($s2)
    ctx->pc = 0x12d54cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 48)));
    // 0x12d550: 0x50182a  slt         $v1, $v0, $s0
    ctx->pc = 0x12d550u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x12d554: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12d554u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12d558: 0x43800b  movn        $s0, $v0, $v1
    ctx->pc = 0x12d558u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 2));
    // 0x12d55c: 0xb32821  addu        $a1, $a1, $s3
    ctx->pc = 0x12d55cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 19)));
    // 0x12d560: 0x902021  addu        $a0, $a0, $s0
    ctx->pc = 0x12d560u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x12d564: 0xd03021  addu        $a2, $a2, $s0
    ctx->pc = 0x12d564u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x12d568: 0xae440034  sw          $a0, 0x34($s2)
    ctx->pc = 0x12d568u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 4));
    // 0x12d56c: 0xae46002c  sw          $a2, 0x2C($s2)
    ctx->pc = 0x12d56cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 6));
    // 0x12d570: 0xae450030  sw          $a1, 0x30($s2)
    ctx->pc = 0x12d570u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 5));
    // 0x12d574: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12d574u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12d578: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12d578u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12d57c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x12d57cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12d580: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x12d580u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12d584: 0x3e00008  jr          $ra
    ctx->pc = 0x12D584u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12D588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12D584u;
            // 0x12d588: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12D528u: goto label_12d528;
            case 0x12D534u: goto label_12d534;
            case 0x12D540u: goto label_12d540;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12D58Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
