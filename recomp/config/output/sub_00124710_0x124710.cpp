#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00124710
// Address: 0x124710 - 0x12477c
void sub_00124710_0x124710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00124710_0x124710");
#endif

    switch (ctx->pc) {
        case 0x124744u: goto label_124744;
        case 0x124760u: goto label_124760;
        default: break;
    }

    ctx->pc = 0x124710u;

    // 0x124710: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x124710u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x124714: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x124714u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x124718: 0x8c43b93c  lw          $v1, -0x46C4($v0)
    ctx->pc = 0x124718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949180)));
    // 0x12471c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12471cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124720: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124720u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124724: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x124724u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x124728: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x124728u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12472c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x12472cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x124730: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x124730u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124734: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x124734u;
    {
        const bool branch_taken_0x124734 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x124738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124734u;
            // 0x124738: 0xffbf0018  sd          $ra, 0x18($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124734) {
            ctx->pc = 0x124744u;
            goto label_124744;
        }
    }
    ctx->pc = 0x12473Cu;
    // 0x12473c: 0xc049146  jal         func_124518
    ctx->pc = 0x12473Cu;
    SET_GPR_U32(ctx, 31, 0x124744u);
    ctx->pc = 0x124518u;
    if (runtime->hasFunction(0x124518u)) {
        auto targetFn = runtime->lookupFunction(0x124518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124744u; }
        if (ctx->pc != 0x124744u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124518_0x124518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124744u; }
        if (ctx->pc != 0x124744u) { return; }
    }
    ctx->pc = 0x124744u;
label_124744:
    // 0x124744: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x124744u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x124748: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x124748u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12474c: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x12474cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124750: 0x240402d  daddu       $t0, $s2, $zero
    ctx->pc = 0x124750u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124754: 0x24849b60  addiu       $a0, $a0, -0x64A0
    ctx->pc = 0x124754u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941536));
    // 0x124758: 0xc049156  jal         func_124558
    ctx->pc = 0x124758u;
    SET_GPR_U32(ctx, 31, 0x124760u);
    ctx->pc = 0x12475Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124758u;
            // 0x12475c: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124558u;
    if (runtime->hasFunction(0x124558u)) {
        auto targetFn = runtime->lookupFunction(0x124558u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124760u; }
        if (ctx->pc != 0x124760u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00124558_0x124558(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x124760u; }
        if (ctx->pc != 0x124760u) { return; }
    }
    ctx->pc = 0x124760u;
label_124760:
    // 0x124760: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x124760u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124764: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124764u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124768: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124768u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12476c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x12476cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124770: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124770u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124774: 0x3e00008  jr          $ra
    ctx->pc = 0x124774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124774u;
            // 0x124778: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x124744u: goto label_124744;
            case 0x124760u: goto label_124760;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12477Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
