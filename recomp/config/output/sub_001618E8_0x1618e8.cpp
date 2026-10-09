#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001618E8
// Address: 0x1618e8 - 0x161948
void sub_001618E8_0x1618e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001618E8_0x1618e8");
#endif

    switch (ctx->pc) {
        case 0x161900u: goto label_161900;
        case 0x161914u: goto label_161914;
        case 0x161928u: goto label_161928;
        case 0x161930u: goto label_161930;
        default: break;
    }

    ctx->pc = 0x1618e8u;

    // 0x1618e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1618e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1618ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1618ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1618f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1618f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1618f4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1618f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1618f8: 0xc058630  jal         func_1618C0
    ctx->pc = 0x1618F8u;
    SET_GPR_U32(ctx, 31, 0x161900u);
    ctx->pc = 0x1618FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1618F8u;
            // 0x1618fc: 0x2604000c  addiu       $a0, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1618C0u;
    if (runtime->hasFunction(0x1618C0u)) {
        auto targetFn = runtime->lookupFunction(0x1618C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161900u; }
        if (ctx->pc != 0x161900u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001618C0_0x1618c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161900u; }
        if (ctx->pc != 0x161900u) { return; }
    }
    ctx->pc = 0x161900u;
label_161900:
    // 0x161900: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x161900u;
    {
        const bool branch_taken_0x161900 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x161904u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161900u;
            // 0x161904: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161900) {
            ctx->pc = 0x161934u;
            goto label_161934;
        }
    }
    ctx->pc = 0x161908u;
    // 0x161908: 0x8e0400ec  lw          $a0, 0xEC($s0)
    ctx->pc = 0x161908u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 236)));
    // 0x16190c: 0xc04fe2a  jal         func_13F8A8
    ctx->pc = 0x16190Cu;
    SET_GPR_U32(ctx, 31, 0x161914u);
    ctx->pc = 0x161910u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16190Cu;
            // 0x161910: 0x8e0500f0  lw          $a1, 0xF0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F8A8u;
    if (runtime->hasFunction(0x13F8A8u)) {
        auto targetFn = runtime->lookupFunction(0x13F8A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161914u; }
        if (ctx->pc != 0x161914u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F8A8_0x13f8a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161914u; }
        if (ctx->pc != 0x161914u) { return; }
    }
    ctx->pc = 0x161914u;
label_161914:
    // 0x161914: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x161914u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161918: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161918u;
    {
        const bool branch_taken_0x161918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16191Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161918u;
            // 0x16191c: 0x2484fe80  addiu       $a0, $a0, -0x180 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966912));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161918) {
            ctx->pc = 0x161934u;
            goto label_161934;
        }
    }
    ctx->pc = 0x161920u;
    // 0x161920: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161920u;
    SET_GPR_U32(ctx, 31, 0x161928u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161928u; }
        if (ctx->pc != 0x161928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161928u; }
        if (ctx->pc != 0x161928u) { return; }
    }
    ctx->pc = 0x161928u;
label_161928:
    // 0x161928: 0xc057474  jal         func_15D1D0
    ctx->pc = 0x161928u;
    SET_GPR_U32(ctx, 31, 0x161930u);
    ctx->pc = 0x16192Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161928u;
            // 0x16192c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15D1D0u;
    if (runtime->hasFunction(0x15D1D0u)) {
        auto targetFn = runtime->lookupFunction(0x15D1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161930u; }
        if (ctx->pc != 0x161930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015D1D0_0x15d1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161930u; }
        if (ctx->pc != 0x161930u) { return; }
    }
    ctx->pc = 0x161930u;
label_161930:
    // 0x161930: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x161930u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_161934:
    // 0x161934: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161934u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161938: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161938u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16193c: 0x3e00008  jr          $ra
    ctx->pc = 0x16193Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16193Cu;
            // 0x161940: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161900u: goto label_161900;
            case 0x161914u: goto label_161914;
            case 0x161928u: goto label_161928;
            case 0x161930u: goto label_161930;
            case 0x161934u: goto label_161934;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161944u;
    // 0x161944: 0x0  nop
    ctx->pc = 0x161944u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
