#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00141DB0
// Address: 0x141db0 - 0x141df0
void sub_00141DB0_0x141db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00141DB0_0x141db0");
#endif

    switch (ctx->pc) {
        case 0x141dccu: goto label_141dcc;
        default: break;
    }

    ctx->pc = 0x141db0u;

    // 0x141db0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x141db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x141db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x141db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x141db8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x141db8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x141dbc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x141dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x141dc0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x141dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x141dc4: 0xc0505b4  jal         func_1416D0
    ctx->pc = 0x141DC4u;
    SET_GPR_U32(ctx, 31, 0x141DCCu);
    ctx->pc = 0x141DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141DC4u;
            // 0x141dc8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416D0u;
    if (runtime->hasFunction(0x1416D0u)) {
        auto targetFn = runtime->lookupFunction(0x1416D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141DCCu; }
        if (ctx->pc != 0x141DCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001416D0_0x1416d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141DCCu; }
        if (ctx->pc != 0x141DCCu) { return; }
    }
    ctx->pc = 0x141DCCu;
label_141dcc:
    // 0x141dcc: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x141dccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x141dd0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x141dd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141dd4: 0x244249f0  addiu       $v0, $v0, 0x49F0
    ctx->pc = 0x141dd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 18928));
    // 0x141dd8: 0xac500004  sw          $s0, 0x4($v0)
    ctx->pc = 0x141dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x141ddc: 0xac510000  sw          $s1, 0x0($v0)
    ctx->pc = 0x141ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 17));
    // 0x141de0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141de0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x141de4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141de4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x141de8: 0x80505ba  j           func_1416E8
    ctx->pc = 0x141DE8u;
    ctx->pc = 0x141DECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141DE8u;
            // 0x141dec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1416E8u;
    if (runtime->hasFunction(0x1416E8u)) {
        auto targetFn = runtime->lookupFunction(0x1416E8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141DF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
