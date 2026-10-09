#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001820D8
// Address: 0x1820d8 - 0x182114
void sub_001820D8_0x1820d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001820D8_0x1820d8");
#endif

    switch (ctx->pc) {
        case 0x1820e8u: goto label_1820e8;
        case 0x182104u: goto label_182104;
        default: break;
    }

    ctx->pc = 0x1820d8u;

    // 0x1820d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1820d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1820dc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1820dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1820e0: 0xc0605f2  jal         func_1817C8
    ctx->pc = 0x1820E0u;
    SET_GPR_U32(ctx, 31, 0x1820E8u);
    ctx->pc = 0x1820E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1820E0u;
            // 0x1820e4: 0x30c6ffff  andi        $a2, $a2, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1817C8u;
    if (runtime->hasFunction(0x1817C8u)) {
        auto targetFn = runtime->lookupFunction(0x1817C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820E8u; }
        if (ctx->pc != 0x1820E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001817C8_0x1817c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1820E8u; }
        if (ctx->pc != 0x1820E8u) { return; }
    }
    ctx->pc = 0x1820E8u;
label_1820e8:
    // 0x1820e8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1820e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820ec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1820ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1820f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1820f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1820f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1820F4u;
    {
        const bool branch_taken_0x1820f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1820F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1820F4u;
            // 0x1820f8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1820f4) {
            ctx->pc = 0x182108u;
            goto label_182108;
        }
    }
    ctx->pc = 0x1820FCu;
    // 0x1820fc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x1820FCu;
    SET_GPR_U32(ctx, 31, 0x182104u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182104u; }
        if (ctx->pc != 0x182104u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182104u; }
        if (ctx->pc != 0x182104u) { return; }
    }
    ctx->pc = 0x182104u;
label_182104:
    // 0x182104: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182104u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182108:
    // 0x182108: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182108u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18210c: 0x3e00008  jr          $ra
    ctx->pc = 0x18210Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18210Cu;
            // 0x182110: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1820E8u: goto label_1820e8;
            case 0x182104u: goto label_182104;
            case 0x182108u: goto label_182108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182114u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
