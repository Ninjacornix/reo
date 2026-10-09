#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB310
// Address: 0x1ab310 - 0x1ab3c0
void sub_001AB310_0x1ab310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB310_0x1ab310");
#endif

    switch (ctx->pc) {
        case 0x1ab34cu: goto label_1ab34c;
        case 0x1ab364u: goto label_1ab364;
        case 0x1ab390u: goto label_1ab390;
        case 0x1ab3a8u: goto label_1ab3a8;
        default: break;
    }

    ctx->pc = 0x1ab310u;

    // 0x1ab310: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1ab310u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab314: 0x240501a6  addiu       $a1, $zero, 0x1A6
    ctx->pc = 0x1ab314u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 422));
    // 0x1ab318: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1ab318u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1ab31c: 0x806ac14  j           func_1AB050
    ctx->pc = 0x1AB31Cu;
    ctx->pc = 0x1AB320u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB31Cu;
            // 0x1ab320: 0x248437c0  addiu       $a0, $a0, 0x37C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 14272));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB050u;
    if (runtime->hasFunction(0x1AB050u)) {
        auto targetFn = runtime->lookupFunction(0x1AB050u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AB050_0x1ab050(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1AB324u;
    // 0x1ab324: 0x0  nop
    ctx->pc = 0x1ab324u;
    // NOP
    // 0x1ab328: 0x0  nop
    ctx->pc = 0x1ab328u;
    // NOP
    // 0x1ab32c: 0x0  nop
    ctx->pc = 0x1ab32cu;
    // NOP
    // 0x1ab330: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ab330u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ab334: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1ab334u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab338: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ab338u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ab33c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ab33cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ab340: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1ab340u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ab344: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AB344u;
    SET_GPR_U32(ctx, 31, 0x1AB34Cu);
    ctx->pc = 0x1AB348u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB344u;
            // 0x1ab348: 0x24a5fcd8  addiu       $a1, $a1, -0x328 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966488));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB34Cu; }
        if (ctx->pc != 0x1AB34Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB34Cu; }
        if (ctx->pc != 0x1AB34Cu) { return; }
    }
    ctx->pc = 0x1AB34Cu;
label_1ab34c:
    // 0x1ab34c: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1ab34cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1ab350: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1ab350u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ab354: 0x24a52970  addiu       $a1, $a1, 0x2970
    ctx->pc = 0x1ab354u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 10608));
    // 0x1ab358: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1ab358u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1ab35c: 0xc06a6b0  jal         func_1A9AC0
    ctx->pc = 0x1AB35Cu;
    SET_GPR_U32(ctx, 31, 0x1AB364u);
    ctx->pc = 0x1AB360u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB35Cu;
            // 0x1ab360: 0x24070001  addiu       $a3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9AC0u;
    if (runtime->hasFunction(0x1A9AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A9AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB364u; }
        if (ctx->pc != 0x1AB364u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9AC0_0x1a9ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB364u; }
        if (ctx->pc != 0x1AB364u) { return; }
    }
    ctx->pc = 0x1AB364u;
label_1ab364:
    // 0x1ab364: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ab364u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab368: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB368u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB36Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB368u;
            // 0x1ab36c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB34Cu: goto label_1ab34c;
            case 0x1AB364u: goto label_1ab364;
            case 0x1AB390u: goto label_1ab390;
            case 0x1AB3A8u: goto label_1ab3a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB370u;
    // 0x1ab370: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ab370u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ab374: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ab374u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ab378: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1ab378u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1ab37c: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ab37cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ab380: 0x942643da  lhu         $a2, 0x43DA($at)
    ctx->pc = 0x1ab380u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1ab384: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1ab384u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ab388: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AB388u;
    SET_GPR_U32(ctx, 31, 0x1AB390u);
    ctx->pc = 0x1AB38Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB388u;
            // 0x1ab38c: 0x24a5fce8  addiu       $a1, $a1, -0x318 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB390u; }
        if (ctx->pc != 0x1AB390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB390u; }
        if (ctx->pc != 0x1AB390u) { return; }
    }
    ctx->pc = 0x1AB390u;
label_1ab390:
    // 0x1ab390: 0x3c050057  lui         $a1, 0x57
    ctx->pc = 0x1ab390u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)87 << 16));
    // 0x1ab394: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1ab394u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ab398: 0x27a40010  addiu       $a0, $sp, 0x10
    ctx->pc = 0x1ab398u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x1ab39c: 0x24a5ac40  addiu       $a1, $a1, -0x53C0
    ctx->pc = 0x1ab39cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294945856));
    // 0x1ab3a0: 0xc06a6b0  jal         func_1A9AC0
    ctx->pc = 0x1AB3A0u;
    SET_GPR_U32(ctx, 31, 0x1AB3A8u);
    ctx->pc = 0x1AB3A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB3A0u;
            // 0x1ab3a4: 0xc0382d  daddu       $a3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A9AC0u;
    if (runtime->hasFunction(0x1A9AC0u)) {
        auto targetFn = runtime->lookupFunction(0x1A9AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB3A8u; }
        if (ctx->pc != 0x1AB3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9AC0_0x1a9ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB3A8u; }
        if (ctx->pc != 0x1AB3A8u) { return; }
    }
    ctx->pc = 0x1AB3A8u;
label_1ab3a8:
    // 0x1ab3a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ab3a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab3ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB3ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB3B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB3ACu;
            // 0x1ab3b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB34Cu: goto label_1ab34c;
            case 0x1AB364u: goto label_1ab364;
            case 0x1AB390u: goto label_1ab390;
            case 0x1AB3A8u: goto label_1ab3a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB3B4u;
    // 0x1ab3b4: 0x0  nop
    ctx->pc = 0x1ab3b4u;
    // NOP
    // 0x1ab3b8: 0x0  nop
    ctx->pc = 0x1ab3b8u;
    // NOP
    // 0x1ab3bc: 0x0  nop
    ctx->pc = 0x1ab3bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
