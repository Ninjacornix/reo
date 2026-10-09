#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00136760
// Address: 0x136760 - 0x1367b8
void sub_00136760_0x136760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00136760_0x136760");
#endif

    switch (ctx->pc) {
        case 0x136778u: goto label_136778;
        case 0x136798u: goto label_136798;
        case 0x1367a8u: goto label_1367a8;
        default: break;
    }

    ctx->pc = 0x136760u;

    // 0x136760: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x136760u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x136764: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136764u;
    {
        const bool branch_taken_0x136764 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136764u;
            // 0x136768: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136764) {
            ctx->pc = 0x136780u;
            goto label_136780;
        }
    }
    ctx->pc = 0x13676Cu;
    // 0x13676c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13676cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136770: 0xc04d480  jal         func_135200
    ctx->pc = 0x136770u;
    SET_GPR_U32(ctx, 31, 0x136778u);
    ctx->pc = 0x136774u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136770u;
            // 0x136774: 0x2484be90  addiu       $a0, $a0, -0x4170 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950544));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136778u; }
        if (ctx->pc != 0x136778u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136778u; }
        if (ctx->pc != 0x136778u) { return; }
    }
    ctx->pc = 0x136778u;
label_136778:
    // 0x136778: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136778u;
    {
        const bool branch_taken_0x136778 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13677Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136778u;
            // 0x13677c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136778) {
            ctx->pc = 0x1367ACu;
            goto label_1367ac;
        }
    }
    ctx->pc = 0x136780u;
label_136780:
    // 0x136780: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136780u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136784: 0x8c42004c  lw          $v0, 0x4C($v0)
    ctx->pc = 0x136784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 76)));
    // 0x136788: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136788u;
    {
        const bool branch_taken_0x136788 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136788) {
            ctx->pc = 0x13678Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136788u;
            // 0x13678c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1367A0u;
            goto label_1367a0;
        }
    }
    ctx->pc = 0x136790u;
    // 0x136790: 0x40f809  jalr        $v0
    ctx->pc = 0x136790u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136798u);
        ctx->pc = 0x136794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136790u;
            // 0x136794: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136798u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136798u; }
            if (ctx->pc != 0x136798u) { return; }
        }
        }
    }
    ctx->pc = 0x136798u;
label_136798:
    // 0x136798: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x136798u;
    {
        const bool branch_taken_0x136798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13679Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136798u;
            // 0x13679c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136798) {
            ctx->pc = 0x1367B0u;
            goto label_1367b0;
        }
    }
    ctx->pc = 0x1367A0u;
label_1367a0:
    // 0x1367a0: 0xc04d480  jal         func_135200
    ctx->pc = 0x1367A0u;
    SET_GPR_U32(ctx, 31, 0x1367A8u);
    ctx->pc = 0x1367A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1367A0u;
            // 0x1367a4: 0x2484beb8  addiu       $a0, $a0, -0x4148 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950584));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367A8u; }
        if (ctx->pc != 0x1367A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367A8u; }
        if (ctx->pc != 0x1367A8u) { return; }
    }
    ctx->pc = 0x1367A8u;
label_1367a8:
    // 0x1367a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1367a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1367ac:
    // 0x1367ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1367acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1367b0:
    // 0x1367b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1367B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1367B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367B0u;
            // 0x1367b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136778u: goto label_136778;
            case 0x136780u: goto label_136780;
            case 0x136798u: goto label_136798;
            case 0x1367A0u: goto label_1367a0;
            case 0x1367A8u: goto label_1367a8;
            case 0x1367ACu: goto label_1367ac;
            case 0x1367B0u: goto label_1367b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1367B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
