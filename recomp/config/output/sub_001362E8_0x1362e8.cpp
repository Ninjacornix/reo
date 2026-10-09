#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001362E8
// Address: 0x1362e8 - 0x13634c
void sub_001362E8_0x1362e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001362E8_0x1362e8");
#endif

    switch (ctx->pc) {
        case 0x136308u: goto label_136308;
        case 0x136328u: goto label_136328;
        case 0x136338u: goto label_136338;
        default: break;
    }

    ctx->pc = 0x1362e8u;

    // 0x1362e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1362e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1362ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1362ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1362f0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1362f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1362f4: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1362F4u;
    {
        const bool branch_taken_0x1362f4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1362F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1362F4u;
            // 0x1362f8: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1362f4) {
            ctx->pc = 0x136310u;
            goto label_136310;
        }
    }
    ctx->pc = 0x1362FCu;
    // 0x1362fc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1362fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136300: 0xc04d480  jal         func_135200
    ctx->pc = 0x136300u;
    SET_GPR_U32(ctx, 31, 0x136308u);
    ctx->pc = 0x136304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136300u;
            // 0x136304: 0x2484bca0  addiu       $a0, $a0, -0x4360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950048));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136308u; }
        if (ctx->pc != 0x136308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136308u; }
        if (ctx->pc != 0x136308u) { return; }
    }
    ctx->pc = 0x136308u;
label_136308:
    // 0x136308: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x136308u;
    {
        const bool branch_taken_0x136308 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13630Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136308u;
            // 0x13630c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136308) {
            ctx->pc = 0x13633Cu;
            goto label_13633c;
        }
    }
    ctx->pc = 0x136310u;
label_136310:
    // 0x136310: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x136310u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136314: 0x8c420030  lw          $v0, 0x30($v0)
    ctx->pc = 0x136314u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 48)));
    // 0x136318: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136318u;
    {
        const bool branch_taken_0x136318 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136318) {
            ctx->pc = 0x13631Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136318u;
            // 0x13631c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136330u;
            goto label_136330;
        }
    }
    ctx->pc = 0x136320u;
    // 0x136320: 0x40f809  jalr        $v0
    ctx->pc = 0x136320u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136328u);
        ctx->pc = 0x136324u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136320u;
            // 0x136324: 0x8c840004  lw          $a0, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136328u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136328u; }
            if (ctx->pc != 0x136328u) { return; }
        }
        }
    }
    ctx->pc = 0x136328u;
label_136328:
    // 0x136328: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x136328u;
    {
        const bool branch_taken_0x136328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13632Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136328u;
            // 0x13632c: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136328) {
            ctx->pc = 0x136338u;
            goto label_136338;
        }
    }
    ctx->pc = 0x136330u;
label_136330:
    // 0x136330: 0xc04d480  jal         func_135200
    ctx->pc = 0x136330u;
    SET_GPR_U32(ctx, 31, 0x136338u);
    ctx->pc = 0x136334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136330u;
            // 0x136334: 0x2484bcc0  addiu       $a0, $a0, -0x4340 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950080));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136338u; }
        if (ctx->pc != 0x136338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136338u; }
        if (ctx->pc != 0x136338u) { return; }
    }
    ctx->pc = 0x136338u;
label_136338:
    // 0x136338: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x136338u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_13633c:
    // 0x13633c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13633cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136340: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x136340u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x136344: 0x3e00008  jr          $ra
    ctx->pc = 0x136344u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136348u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136344u;
            // 0x136348: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136308u: goto label_136308;
            case 0x136310u: goto label_136310;
            case 0x136328u: goto label_136328;
            case 0x136330u: goto label_136330;
            case 0x136338u: goto label_136338;
            case 0x13633Cu: goto label_13633c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13634Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
