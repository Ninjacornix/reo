#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142078
// Address: 0x142078 - 0x1420f8
void sub_00142078_0x142078(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142078_0x142078");
#endif

    switch (ctx->pc) {
        case 0x142094u: goto label_142094;
        case 0x1420a8u: goto label_1420a8;
        case 0x1420bcu: goto label_1420bc;
        case 0x1420c8u: goto label_1420c8;
        default: break;
    }

    ctx->pc = 0x142078u;

    // 0x142078: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x142078u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x14207c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x14207cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x142080: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x142080u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142084: 0x2484a618  addiu       $a0, $a0, -0x59E8
    ctx->pc = 0x142084u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294944280));
    // 0x142088: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x142088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x14208c: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x14208Cu;
    SET_GPR_U32(ctx, 31, 0x142094u);
    ctx->pc = 0x142090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14208Cu;
            // 0x142090: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142094u; }
        if (ctx->pc != 0x142094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142094u; }
        if (ctx->pc != 0x142094u) { return; }
    }
    ctx->pc = 0x142094u;
label_142094:
    // 0x142094: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x142094u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x142098: 0x248449e0  addiu       $a0, $a0, 0x49E0
    ctx->pc = 0x142098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18912));
    // 0x14209c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x14209cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1420a0: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1420A0u;
    SET_GPR_U32(ctx, 31, 0x1420A8u);
    ctx->pc = 0x1420A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1420A0u;
            // 0x1420a4: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1420A8u; }
        if (ctx->pc != 0x1420A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1420A8u; }
        if (ctx->pc != 0x1420A8u) { return; }
    }
    ctx->pc = 0x1420A8u;
label_1420a8:
    // 0x1420a8: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1420a8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1420ac: 0x248449e8  addiu       $a0, $a0, 0x49E8
    ctx->pc = 0x1420acu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18920));
    // 0x1420b0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1420b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1420b4: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1420B4u;
    SET_GPR_U32(ctx, 31, 0x1420BCu);
    ctx->pc = 0x1420B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1420B4u;
            // 0x1420b8: 0x24060008  addiu       $a2, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1420BCu; }
        if (ctx->pc != 0x1420BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1420BCu; }
        if (ctx->pc != 0x1420BCu) { return; }
    }
    ctx->pc = 0x1420BCu;
label_1420bc:
    // 0x1420bc: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1420bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1420c0: 0x2463a5f8  addiu       $v1, $v1, -0x5A08
    ctx->pc = 0x1420c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294944248));
    // 0x1420c4: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1420c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
label_1420c8:
    // 0x1420c8: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1420c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1420cc: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1420ccu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1420d0: 0x0  nop
    ctx->pc = 0x1420d0u;
    // NOP
    // 0x1420d4: 0x0  nop
    ctx->pc = 0x1420d4u;
    // NOP
    // 0x1420d8: 0x0  nop
    ctx->pc = 0x1420d8u;
    // NOP
    // 0x1420dc: 0x441fffa  bgez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1420DCu;
    {
        const bool branch_taken_0x1420dc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1420E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1420DCu;
            // 0x1420e0: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1420dc) {
            ctx->pc = 0x1420C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1420c8;
        }
    }
    ctx->pc = 0x1420E4u;
    // 0x1420e4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1420e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1420e8: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x1420e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x1420ec: 0xac4049f8  sw          $zero, 0x49F8($v0)
    ctx->pc = 0x1420ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 18936), GPR_U32(ctx, 0));
    // 0x1420f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1420F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1420F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1420F0u;
            // 0x1420f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x142094u: goto label_142094;
            case 0x1420A8u: goto label_1420a8;
            case 0x1420BCu: goto label_1420bc;
            case 0x1420C8u: goto label_1420c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1420F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
