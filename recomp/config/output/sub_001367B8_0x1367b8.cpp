#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001367B8
// Address: 0x1367b8 - 0x136874
void sub_001367B8_0x1367b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001367B8_0x1367b8");
#endif

    switch (ctx->pc) {
        case 0x1367f4u: goto label_1367f4;
        case 0x13681cu: goto label_13681c;
        case 0x136834u: goto label_136834;
        case 0x136848u: goto label_136848;
        case 0x13685cu: goto label_13685c;
        default: break;
    }

    ctx->pc = 0x1367b8u;

    // 0x1367b8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1367b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1367bc: 0xffb00060  sd          $s0, 0x60($sp)
    ctx->pc = 0x1367bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 16));
    // 0x1367c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1367c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1367c4: 0xffb10068  sd          $s1, 0x68($sp)
    ctx->pc = 0x1367c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 17));
    // 0x1367c8: 0x16000005  bnez        $s0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1367C8u;
    {
        const bool branch_taken_0x1367c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1367CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367C8u;
            // 0x1367cc: 0xffbf0070  sd          $ra, 0x70($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1367c8) {
            ctx->pc = 0x1367E0u;
            goto label_1367e0;
        }
    }
    ctx->pc = 0x1367D0u;
    // 0x1367d0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1367d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1367d4: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1367D4u;
    {
        const bool branch_taken_0x1367d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1367D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367D4u;
            // 0x1367d8: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1367d4) {
            ctx->pc = 0x136854u;
            goto label_136854;
        }
    }
    ctx->pc = 0x1367DCu;
    // 0x1367dc: 0x0  nop
    ctx->pc = 0x1367dcu;
    // NOP
label_1367e0:
    // 0x1367e0: 0x27b10030  addiu       $s1, $sp, 0x30
    ctx->pc = 0x1367e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1367e4: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1367e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1367e8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1367e8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1367ec: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x1367ECu;
    SET_GPR_U32(ctx, 31, 0x1367F4u);
    ctx->pc = 0x1367F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1367ECu;
            // 0x1367f0: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367F4u; }
        if (ctx->pc != 0x1367F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1367F4u; }
        if (ctx->pc != 0x1367F4u) { return; }
    }
    ctx->pc = 0x1367F4u;
label_1367f4:
    // 0x1367f4: 0x83a20030  lb          $v0, 0x30($sp)
    ctx->pc = 0x1367f4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1367f8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1367F8u;
    {
        const bool branch_taken_0x1367f8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1367FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1367F8u;
            // 0x1367fc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1367f8) {
            ctx->pc = 0x136810u;
            goto label_136810;
        }
    }
    ctx->pc = 0x136800u;
    // 0x136800: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136800u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136804: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x136804u;
    {
        const bool branch_taken_0x136804 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136804u;
            // 0x136808: 0x2484bee0  addiu       $a0, $a0, -0x4120 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950624));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136804) {
            ctx->pc = 0x136854u;
            goto label_136854;
        }
    }
    ctx->pc = 0x13680Cu;
    // 0x13680c: 0x0  nop
    ctx->pc = 0x13680cu;
    // NOP
label_136810:
    // 0x136810: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x136810u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136814: 0xc04d622  jal         func_135888
    ctx->pc = 0x136814u;
    SET_GPR_U32(ctx, 31, 0x13681Cu);
    ctx->pc = 0x136818u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136814u;
            // 0x136818: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13681Cu; }
        if (ctx->pc != 0x13681Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13681Cu; }
        if (ctx->pc != 0x13681Cu) { return; }
    }
    ctx->pc = 0x13681Cu;
label_13681c:
    // 0x13681c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13681cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136820: 0x56000005  bnel        $s0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136820u;
    {
        const bool branch_taken_0x136820 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x136820) {
            ctx->pc = 0x136824u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136820u;
            // 0x136824: 0x8e020050  lw          $v0, 0x50($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136838u;
            goto label_136838;
        }
    }
    ctx->pc = 0x136828u;
    // 0x136828: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136828u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13682c: 0xc04d480  jal         func_135200
    ctx->pc = 0x13682Cu;
    SET_GPR_U32(ctx, 31, 0x136834u);
    ctx->pc = 0x136830u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13682Cu;
            // 0x136830: 0x2484bf30  addiu       $a0, $a0, -0x40D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950704));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136834u; }
        if (ctx->pc != 0x136834u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136834u; }
        if (ctx->pc != 0x136834u) { return; }
    }
    ctx->pc = 0x136834u;
label_136834:
    // 0x136834: 0x8e020050  lw          $v0, 0x50($s0)
    ctx->pc = 0x136834u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 80)));
label_136838:
    // 0x136838: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x136838u;
    {
        const bool branch_taken_0x136838 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x136838) {
            ctx->pc = 0x13683Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136838u;
            // 0x13683c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136850u;
            goto label_136850;
        }
    }
    ctx->pc = 0x136840u;
    // 0x136840: 0x40f809  jalr        $v0
    ctx->pc = 0x136840u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136848u);
        ctx->pc = 0x136844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136840u;
            // 0x136844: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x136848u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136848u; }
            if (ctx->pc != 0x136848u) { return; }
        }
        }
    }
    ctx->pc = 0x136848u;
label_136848:
    // 0x136848: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x136848u;
    {
        const bool branch_taken_0x136848 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13684Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136848u;
            // 0x13684c: 0xdfb00060  ld          $s0, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136848) {
            ctx->pc = 0x136864u;
            goto label_136864;
        }
    }
    ctx->pc = 0x136850u;
label_136850:
    // 0x136850: 0x2484bf50  addiu       $a0, $a0, -0x40B0
    ctx->pc = 0x136850u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294950736));
label_136854:
    // 0x136854: 0xc04d480  jal         func_135200
    ctx->pc = 0x136854u;
    SET_GPR_U32(ctx, 31, 0x13685Cu);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13685Cu; }
        if (ctx->pc != 0x13685Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13685Cu; }
        if (ctx->pc != 0x13685Cu) { return; }
    }
    ctx->pc = 0x13685Cu;
label_13685c:
    // 0x13685c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x13685cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x136860: 0xdfb00060  ld          $s0, 0x60($sp)
    ctx->pc = 0x136860u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_136864:
    // 0x136864: 0xdfb10068  ld          $s1, 0x68($sp)
    ctx->pc = 0x136864u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x136868: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x136868u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x13686c: 0x3e00008  jr          $ra
    ctx->pc = 0x13686Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13686Cu;
            // 0x136870: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1367E0u: goto label_1367e0;
            case 0x1367F4u: goto label_1367f4;
            case 0x136810u: goto label_136810;
            case 0x13681Cu: goto label_13681c;
            case 0x136834u: goto label_136834;
            case 0x136838u: goto label_136838;
            case 0x136848u: goto label_136848;
            case 0x136850u: goto label_136850;
            case 0x136854u: goto label_136854;
            case 0x13685Cu: goto label_13685c;
            case 0x136864u: goto label_136864;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136874u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
