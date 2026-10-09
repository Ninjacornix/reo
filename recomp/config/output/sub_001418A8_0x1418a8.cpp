#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001418A8
// Address: 0x1418a8 - 0x141968
void sub_001418A8_0x1418a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001418A8_0x1418a8");
#endif

    switch (ctx->pc) {
        case 0x1418ccu: goto label_1418cc;
        case 0x1418e8u: goto label_1418e8;
        case 0x141924u: goto label_141924;
        case 0x141934u: goto label_141934;
        case 0x141950u: goto label_141950;
        default: break;
    }

    ctx->pc = 0x1418a8u;

    // 0x1418a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1418a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1418ac: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1418acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1418b0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1418b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1418b4: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1418b4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1418b8: 0x2610a638  addiu       $s0, $s0, -0x59C8
    ctx->pc = 0x1418b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294944312));
    // 0x1418bc: 0x2406007f  addiu       $a2, $zero, 0x7F
    ctx->pc = 0x1418bcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x1418c0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1418c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1418c4: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x1418C4u;
    SET_GPR_U32(ctx, 31, 0x1418CCu);
    ctx->pc = 0x1418C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1418C4u;
            // 0x1418c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1418CCu; }
        if (ctx->pc != 0x1418CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1418CCu; }
        if (ctx->pc != 0x1418CCu) { return; }
    }
    ctx->pc = 0x1418CCu;
label_1418cc:
    // 0x1418cc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1418ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1418d0: 0x244249f0  addiu       $v0, $v0, 0x49F0
    ctx->pc = 0x1418d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18928));
    // 0x1418d4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1418d4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1418d8: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1418D8u;
    {
        const bool branch_taken_0x1418d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1418DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1418D8u;
            // 0x1418dc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1418d8) {
            ctx->pc = 0x1418E8u;
            goto label_1418e8;
        }
    }
    ctx->pc = 0x1418E0u;
    // 0x1418e0: 0x60f809  jalr        $v1
    ctx->pc = 0x1418E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1418E8u);
        ctx->pc = 0x1418E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1418E0u;
            // 0x1418e4: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1418E8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1418CCu: goto label_1418cc;
            case 0x1418E8u: goto label_1418e8;
            case 0x141924u: goto label_141924;
            case 0x141934u: goto label_141934;
            case 0x141950u: goto label_141950;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1418E8u; }
            if (ctx->pc != 0x1418E8u) { return; }
        }
        }
    }
    ctx->pc = 0x1418E8u;
label_1418e8:
    // 0x1418e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1418e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1418ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1418ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1418f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1418F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1418F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1418F0u;
            // 0x1418f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1418CCu: goto label_1418cc;
            case 0x1418E8u: goto label_1418e8;
            case 0x141924u: goto label_141924;
            case 0x141934u: goto label_141934;
            case 0x141950u: goto label_141950;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1418F8u;
    // 0x1418f8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1418f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1418fc: 0x2406007f  addiu       $a2, $zero, 0x7F
    ctx->pc = 0x1418fcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
    // 0x141900: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141900u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141904: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x141904u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x141908: 0x2610a638  addiu       $s0, $s0, -0x59C8
    ctx->pc = 0x141908u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294944312));
    // 0x14190c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x14190cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141910: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x141910u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141914: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x141914u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141918: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x141918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x14191c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x14191Cu;
    SET_GPR_U32(ctx, 31, 0x141924u);
    ctx->pc = 0x141920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14191Cu;
            // 0x141920: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141924u; }
        if (ctx->pc != 0x141924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141924u; }
        if (ctx->pc != 0x141924u) { return; }
    }
    ctx->pc = 0x141924u;
label_141924:
    // 0x141924: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x141924u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141928: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x141928u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14192c: 0xc042ca4  jal         func_10B290
    ctx->pc = 0x14192Cu;
    SET_GPR_U32(ctx, 31, 0x141934u);
    ctx->pc = 0x141930u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14192Cu;
            // 0x141930: 0x2406007f  addiu       $a2, $zero, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B290u;
    if (runtime->hasFunction(0x10B290u)) {
        auto targetFn = runtime->lookupFunction(0x10B290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141934u; }
        if (ctx->pc != 0x141934u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B290_0x10b290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141934u; }
        if (ctx->pc != 0x141934u) { return; }
    }
    ctx->pc = 0x141934u;
label_141934:
    // 0x141934: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141934u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141938: 0x244249f0  addiu       $v0, $v0, 0x49F0
    ctx->pc = 0x141938u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18928));
    // 0x14193c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14193cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x141940: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x141940u;
    {
        const bool branch_taken_0x141940 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x141944u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141940u;
            // 0x141944: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x141940) {
            ctx->pc = 0x141950u;
            goto label_141950;
        }
    }
    ctx->pc = 0x141948u;
    // 0x141948: 0x60f809  jalr        $v1
    ctx->pc = 0x141948u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x141950u);
        ctx->pc = 0x14194Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141948u;
            // 0x14194c: 0x8c440004  lw          $a0, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141950u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1418CCu: goto label_1418cc;
            case 0x1418E8u: goto label_1418e8;
            case 0x141924u: goto label_141924;
            case 0x141934u: goto label_141934;
            case 0x141950u: goto label_141950;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141950u; }
            if (ctx->pc != 0x141950u) { return; }
        }
        }
    }
    ctx->pc = 0x141950u;
label_141950:
    // 0x141950: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141950u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141954: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141954u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141958: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x141958u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14195c: 0x3e00008  jr          $ra
    ctx->pc = 0x14195Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x141960u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14195Cu;
            // 0x141960: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1418CCu: goto label_1418cc;
            case 0x1418E8u: goto label_1418e8;
            case 0x141924u: goto label_141924;
            case 0x141934u: goto label_141934;
            case 0x141950u: goto label_141950;
            default: break;
        }
        return;
    }
    ctx->pc = 0x141964u;
    // 0x141964: 0x0  nop
    ctx->pc = 0x141964u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
