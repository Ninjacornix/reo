#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018F6A0
// Address: 0x18f6a0 - 0x18f710
void sub_0018F6A0_0x18f6a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018F6A0_0x18f6a0");
#endif

    switch (ctx->pc) {
        case 0x18f6c4u: goto label_18f6c4;
        case 0x18f6ccu: goto label_18f6cc;
        case 0x18f6e4u: goto label_18f6e4;
        case 0x18f700u: goto label_18f700;
        default: break;
    }

    ctx->pc = 0x18f6a0u;

    // 0x18f6a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18f6a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18f6a4: 0x3c017000  lui         $at, 0x7000
    ctx->pc = 0x18f6a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)28672 << 16));
    // 0x18f6a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18f6a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18f6ac: 0x41180  sll         $v0, $a0, 6
    ctx->pc = 0x18f6acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 6));
    // 0x18f6b0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18f6b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18f6b4: 0x34213700  ori         $at, $at, 0x3700
    ctx->pc = 0x18f6b4u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) | (uint64_t)(uint16_t)14080);
    // 0x18f6b8: 0x418021  addu        $s0, $v0, $at
    ctx->pc = 0x18f6b8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
    // 0x18f6bc: 0xc063dc4  jal         func_18F710
    ctx->pc = 0x18F6BCu;
    SET_GPR_U32(ctx, 31, 0x18F6C4u);
    ctx->pc = 0x18F6C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F6BCu;
            // 0x18f6c0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F710u;
    if (runtime->hasFunction(0x18F710u)) {
        auto targetFn = runtime->lookupFunction(0x18F710u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F6C4u; }
        if (ctx->pc != 0x18F6C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F710_0x18f710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F6C4u; }
        if (ctx->pc != 0x18F6C4u) { return; }
    }
    ctx->pc = 0x18F6C4u;
label_18f6c4:
    // 0x18f6c4: 0xc063df8  jal         func_18F7E0
    ctx->pc = 0x18F6C4u;
    SET_GPR_U32(ctx, 31, 0x18F6CCu);
    ctx->pc = 0x18F6C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F6C4u;
            // 0x18f6c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18F7E0u;
    if (runtime->hasFunction(0x18F7E0u)) {
        auto targetFn = runtime->lookupFunction(0x18F7E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F6CCu; }
        if (ctx->pc != 0x18F6CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018F7E0_0x18f7e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F6CCu; }
        if (ctx->pc != 0x18F6CCu) { return; }
    }
    ctx->pc = 0x18F6CCu;
label_18f6cc:
    // 0x18f6cc: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x18f6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x18f6d0: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18f6d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18f6d4: 0x24844d40  addiu       $a0, $a0, 0x4D40
    ctx->pc = 0x18f6d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19776));
    // 0x18f6d8: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x18f6d8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x18f6dc: 0xc0644a0  jal         func_191280
    ctx->pc = 0x18F6DCu;
    SET_GPR_U32(ctx, 31, 0x18F6E4u);
    ctx->pc = 0x18F6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F6DCu;
            // 0x18f6e0: 0x34463f80  ori         $a2, $v0, 0x3F80 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16256);
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F6E4u; }
        if (ctx->pc != 0x18F6E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F6E4u; }
        if (ctx->pc != 0x18F6E4u) { return; }
    }
    ctx->pc = 0x18F6E4u;
label_18f6e4:
    // 0x18f6e4: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x18f6e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x18f6e8: 0x3c027000  lui         $v0, 0x7000
    ctx->pc = 0x18f6e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)28672 << 16));
    // 0x18f6ec: 0x3c060029  lui         $a2, 0x29
    ctx->pc = 0x18f6ecu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)41 << 16));
    // 0x18f6f0: 0x24844d80  addiu       $a0, $a0, 0x4D80
    ctx->pc = 0x18f6f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 19840));
    // 0x18f6f4: 0x34453f00  ori         $a1, $v0, 0x3F00
    ctx->pc = 0x18f6f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16128);
    // 0x18f6f8: 0xc0644a0  jal         func_191280
    ctx->pc = 0x18F6F8u;
    SET_GPR_U32(ctx, 31, 0x18F700u);
    ctx->pc = 0x18F6FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18F6F8u;
            // 0x18f6fc: 0x24c64dc0  addiu       $a2, $a2, 0x4DC0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 19904));
        ctx->in_delay_slot = false;
    ctx->pc = 0x191280u;
    if (runtime->hasFunction(0x191280u)) {
        auto targetFn = runtime->lookupFunction(0x191280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F700u; }
        if (ctx->pc != 0x18F700u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191280_0x191280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18F700u; }
        if (ctx->pc != 0x18F700u) { return; }
    }
    ctx->pc = 0x18F700u;
label_18f700:
    // 0x18f700: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18f700u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18f704: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18f704u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18f708: 0x3e00008  jr          $ra
    ctx->pc = 0x18F708u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18F70Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18F708u;
            // 0x18f70c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18F6C4u: goto label_18f6c4;
            case 0x18F6CCu: goto label_18f6cc;
            case 0x18F6E4u: goto label_18f6e4;
            case 0x18F700u: goto label_18f700;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18F710u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
