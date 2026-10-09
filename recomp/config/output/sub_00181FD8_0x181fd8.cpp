#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00181FD8
// Address: 0x181fd8 - 0x182014
void sub_00181FD8_0x181fd8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00181FD8_0x181fd8");
#endif

    switch (ctx->pc) {
        case 0x181fe8u: goto label_181fe8;
        case 0x182004u: goto label_182004;
        default: break;
    }

    ctx->pc = 0x181fd8u;

    // 0x181fd8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x181fd8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x181fdc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x181fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x181fe0: 0xc060622  jal         func_181888
    ctx->pc = 0x181FE0u;
    SET_GPR_U32(ctx, 31, 0x181FE8u);
    ctx->pc = 0x181888u;
    if (runtime->hasFunction(0x181888u)) {
        auto targetFn = runtime->lookupFunction(0x181888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FE8u; }
        if (ctx->pc != 0x181FE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181888_0x181888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x181FE8u; }
        if (ctx->pc != 0x181FE8u) { return; }
    }
    ctx->pc = 0x181FE8u;
label_181fe8:
    // 0x181fe8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x181fe8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181fec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x181fecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x181ff0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x181ff0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x181ff4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x181FF4u;
    {
        const bool branch_taken_0x181ff4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x181FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x181FF4u;
            // 0x181ff8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x181ff4) {
            ctx->pc = 0x182008u;
            goto label_182008;
        }
    }
    ctx->pc = 0x181FFCu;
    // 0x181ffc: 0xc06074a  jal         func_181D28
    ctx->pc = 0x181FFCu;
    SET_GPR_U32(ctx, 31, 0x182004u);
    ctx->pc = 0x181D28u;
    if (runtime->hasFunction(0x181D28u)) {
        auto targetFn = runtime->lookupFunction(0x181D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182004u; }
        if (ctx->pc != 0x182004u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00181D28_0x181d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182004u; }
        if (ctx->pc != 0x182004u) { return; }
    }
    ctx->pc = 0x182004u;
label_182004:
    // 0x182004: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x182004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_182008:
    // 0x182008: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x182008u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18200c: 0x3e00008  jr          $ra
    ctx->pc = 0x18200Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x182010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18200Cu;
            // 0x182010: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x181FE8u: goto label_181fe8;
            case 0x182004u: goto label_182004;
            case 0x182008u: goto label_182008;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182014u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
