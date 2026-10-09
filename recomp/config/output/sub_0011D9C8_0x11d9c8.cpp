#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D9C8
// Address: 0x11d9c8 - 0x11da30
void sub_0011D9C8_0x11d9c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D9C8_0x11d9c8");
#endif

    switch (ctx->pc) {
        case 0x11d9dcu: goto label_11d9dc;
        case 0x11da00u: goto label_11da00;
        case 0x11da08u: goto label_11da08;
        case 0x11da10u: goto label_11da10;
        default: break;
    }

    ctx->pc = 0x11d9c8u;

    // 0x11d9c8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11d9c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11d9cc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x11d9ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x11d9d0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11d9d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11d9d4: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x11D9D4u;
    SET_GPR_U32(ctx, 31, 0x11D9DCu);
    ctx->pc = 0x11D9D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D9D4u;
            // 0x11d9d8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D9DCu; }
        if (ctx->pc != 0x11D9DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D9DCu; }
        if (ctx->pc != 0x11D9DCu) { return; }
    }
    ctx->pc = 0x11D9DCu;
label_11d9dc:
    // 0x11d9dc: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x11d9dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11d9e0: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x11d9e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x11d9e4: 0x34421fff  ori         $v0, $v0, 0x1FFF
    ctx->pc = 0x11d9e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8191);
    // 0x11d9e8: 0x27b00004  addiu       $s0, $sp, 0x4
    ctx->pc = 0x11d9e8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x11d9ec: 0x621824  and         $v1, $v1, $v0
    ctx->pc = 0x11d9ecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x11d9f0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11d9f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d9f4: 0x34632000  ori         $v1, $v1, 0x2000
    ctx->pc = 0x11d9f4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)8192);
    // 0x11d9f8: 0xc0451b0  jal         func_1146C0
    ctx->pc = 0x11D9F8u;
    SET_GPR_U32(ctx, 31, 0x11DA00u);
    ctx->pc = 0x11D9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D9F8u;
            // 0x11d9fc: 0xafa30004  sw          $v1, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146C0u;
    if (runtime->hasFunction(0x1146C0u)) {
        auto targetFn = runtime->lookupFunction(0x1146C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA00u; }
        if (ctx->pc != 0x11DA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146C0_0x1146c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA00u; }
        if (ctx->pc != 0x11DA00u) { return; }
    }
    ctx->pc = 0x11DA00u;
label_11da00:
    // 0x11da00: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x11DA00u;
    SET_GPR_U32(ctx, 31, 0x11DA08u);
    ctx->pc = 0x11DA04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA00u;
            // 0x11da04: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA08u; }
        if (ctx->pc != 0x11DA08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA08u; }
        if (ctx->pc != 0x11DA08u) { return; }
    }
    ctx->pc = 0x11DA08u;
label_11da08:
    // 0x11da08: 0xc0451b0  jal         func_1146C0
    ctx->pc = 0x11DA08u;
    SET_GPR_U32(ctx, 31, 0x11DA10u);
    ctx->pc = 0x11DA0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA08u;
            // 0x11da0c: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146C0u;
    if (runtime->hasFunction(0x1146C0u)) {
        auto targetFn = runtime->lookupFunction(0x1146C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA10u; }
        if (ctx->pc != 0x11DA10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146C0_0x1146c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DA10u; }
        if (ctx->pc != 0x11DA10u) { return; }
    }
    ctx->pc = 0x11DA10u;
label_11da10:
    // 0x11da10: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x11da10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x11da14: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11da14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11da18: 0x21342  srl         $v0, $v0, 13
    ctx->pc = 0x11da18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 13));
    // 0x11da1c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x11da1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11da20: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x11da20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x11da24: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x11da24u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x11da28: 0x3e00008  jr          $ra
    ctx->pc = 0x11DA28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DA2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DA28u;
            // 0x11da2c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D9DCu: goto label_11d9dc;
            case 0x11DA00u: goto label_11da00;
            case 0x11DA08u: goto label_11da08;
            case 0x11DA10u: goto label_11da10;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DA30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
