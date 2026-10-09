#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E9A8
// Address: 0x17e9a8 - 0x17e9e8
void sub_0017E9A8_0x17e9a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E9A8_0x17e9a8");
#endif

    switch (ctx->pc) {
        case 0x17e9dcu: goto label_17e9dc;
        default: break;
    }

    ctx->pc = 0x17e9a8u;

    // 0x17e9a8: 0x80182d  daddu       $v1, $a0, $zero
    ctx->pc = 0x17e9a8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e9ac: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x17e9acu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x17e9b0: 0x31178  dsll        $v0, $v1, 5
    ctx->pc = 0x17e9b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << 5);
    // 0x17e9b4: 0xdc85f980  ld          $a1, -0x680($a0)
    ctx->pc = 0x17e9b4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 4), 4294965632)));
    // 0x17e9b8: 0x43102f  dsubu       $v0, $v0, $v1
    ctx->pc = 0x17e9b8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x17e9bc: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e9bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17e9c0: 0x221b8  dsll        $a0, $v0, 6
    ctx->pc = 0x17e9c0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << 6);
    // 0x17e9c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17e9c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17e9c8: 0x82202f  dsubu       $a0, $a0, $v0
    ctx->pc = 0x17e9c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) - GPR_U64(ctx, 2));
    // 0x17e9cc: 0x420f8  dsll        $a0, $a0, 3
    ctx->pc = 0x17e9ccu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 3);
    // 0x17e9d0: 0x83202d  daddu       $a0, $a0, $v1
    ctx->pc = 0x17e9d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 3));
    // 0x17e9d4: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x17E9D4u;
    SET_GPR_U32(ctx, 31, 0x17E9DCu);
    ctx->pc = 0x17E9D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E9D4u;
            // 0x17e9d8: 0x421b8  dsll        $a0, $a0, 6 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 6);
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E9DCu; }
        if (ctx->pc != 0x17E9DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E9DCu; }
        if (ctx->pc != 0x17E9DCu) { return; }
    }
    ctx->pc = 0x17E9DCu;
label_17e9dc:
    // 0x17e9dc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17e9dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e9e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17E9E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E9E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E9E0u;
            // 0x17e9e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E9DCu: goto label_17e9dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E9E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
