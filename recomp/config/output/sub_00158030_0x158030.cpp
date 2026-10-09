#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00158030
// Address: 0x158030 - 0x1580c0
void sub_00158030_0x158030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00158030_0x158030");
#endif

    switch (ctx->pc) {
        case 0x15804cu: goto label_15804c;
        case 0x158070u: goto label_158070;
        case 0x15807cu: goto label_15807c;
        case 0x158090u: goto label_158090;
        case 0x1580a0u: goto label_1580a0;
        case 0x1580a8u: goto label_1580a8;
        default: break;
    }

    ctx->pc = 0x158030u;

    // 0x158030: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x158030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x158034: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x158034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x158038: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x158038u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15803c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15803cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x158040: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x158040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x158044: 0xc056008  jal         func_158020
    ctx->pc = 0x158044u;
    SET_GPR_U32(ctx, 31, 0x15804Cu);
    ctx->pc = 0x158048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158044u;
            // 0x158048: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158020u;
    if (runtime->hasFunction(0x158020u)) {
        auto targetFn = runtime->lookupFunction(0x158020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15804Cu; }
        if (ctx->pc != 0x15804Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158020_0x158020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15804Cu; }
        if (ctx->pc != 0x15804Cu) { return; }
    }
    ctx->pc = 0x15804Cu;
label_15804c:
    // 0x15804c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15804cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x158050: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x158050u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x158054: 0x9086e5a8  lbu         $a2, -0x1A58($a0)
    ctx->pc = 0x158054u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4294960552)));
    // 0x158058: 0x24634c60  addiu       $v1, $v1, 0x4C60
    ctx->pc = 0x158058u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19552));
    // 0x15805c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x15805cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x158060: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x158060u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x158064: 0x10c50008  beq         $a2, $a1, . + 4 + (0x8 << 2)
    ctx->pc = 0x158064u;
    {
        const bool branch_taken_0x158064 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 5));
        ctx->pc = 0x158068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x158064u;
            // 0x158068: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x158064) {
            ctx->pc = 0x158088u;
            goto label_158088;
        }
    }
    ctx->pc = 0x15806Cu;
    // 0x15806c: 0x0  nop
    ctx->pc = 0x15806cu;
    // NOP
label_158070:
    // 0x158070: 0x2401ffff  addiu       $at, $zero, -0x1
    ctx->pc = 0x158070u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x158074: 0x20f809  jalr        $at
    ctx->pc = 0x158074u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x15807Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x15807Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15804Cu: goto label_15804c;
            case 0x158070u: goto label_158070;
            case 0x15807Cu: goto label_15807c;
            case 0x158088u: goto label_158088;
            case 0x158090u: goto label_158090;
            case 0x1580A0u: goto label_1580a0;
            case 0x1580A8u: goto label_1580a8;
            case 0x1580B0u: goto label_1580b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15807Cu; }
            if (ctx->pc != 0x15807Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15807Cu;
label_15807c:
    // 0x15807c: 0x1000fffc  b           . + 4 + (-0x4 << 2)
    ctx->pc = 0x15807Cu;
    {
        const bool branch_taken_0x15807c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x15807c) {
            ctx->pc = 0x158070u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_158070;
        }
    }
    ctx->pc = 0x158084u;
    // 0x158084: 0x0  nop
    ctx->pc = 0x158084u;
    // NOP
label_158088:
    // 0x158088: 0xc056030  jal         func_1580C0
    ctx->pc = 0x158088u;
    SET_GPR_U32(ctx, 31, 0x158090u);
    ctx->pc = 0x15808Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x158088u;
            // 0x15808c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1580C0u;
    if (runtime->hasFunction(0x1580C0u)) {
        auto targetFn = runtime->lookupFunction(0x1580C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158090u; }
        if (ctx->pc != 0x158090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001580C0_0x1580c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x158090u; }
        if (ctx->pc != 0x158090u) { return; }
    }
    ctx->pc = 0x158090u;
label_158090:
    // 0x158090: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x158090u;
    {
        const bool branch_taken_0x158090 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x158090) {
            ctx->pc = 0x158094u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x158090u;
            // 0x158094: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1580B0u;
            goto label_1580b0;
        }
    }
    ctx->pc = 0x158098u;
    // 0x158098: 0xc0558e6  jal         func_156398
    ctx->pc = 0x158098u;
    SET_GPR_U32(ctx, 31, 0x1580A0u);
    ctx->pc = 0x156398u;
    if (runtime->hasFunction(0x156398u)) {
        auto targetFn = runtime->lookupFunction(0x156398u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1580A0u; }
        if (ctx->pc != 0x1580A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00156398_0x156398(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1580A0u; }
        if (ctx->pc != 0x1580A0u) { return; }
    }
    ctx->pc = 0x1580A0u;
label_1580a0:
    // 0x1580a0: 0xc055f70  jal         func_157DC0
    ctx->pc = 0x1580A0u;
    SET_GPR_U32(ctx, 31, 0x1580A8u);
    ctx->pc = 0x157DC0u;
    if (runtime->hasFunction(0x157DC0u)) {
        auto targetFn = runtime->lookupFunction(0x157DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1580A8u; }
        if (ctx->pc != 0x1580A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00157DC0_0x157dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1580A8u; }
        if (ctx->pc != 0x1580A8u) { return; }
    }
    ctx->pc = 0x1580A8u;
label_1580a8:
    // 0x1580a8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1580a8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1580ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1580acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1580b0:
    // 0x1580b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1580b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1580b4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1580b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1580b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1580B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1580BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1580B8u;
            // 0x1580bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15804Cu: goto label_15804c;
            case 0x158070u: goto label_158070;
            case 0x15807Cu: goto label_15807c;
            case 0x158088u: goto label_158088;
            case 0x158090u: goto label_158090;
            case 0x1580A0u: goto label_1580a0;
            case 0x1580A8u: goto label_1580a8;
            case 0x1580B0u: goto label_1580b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1580C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
