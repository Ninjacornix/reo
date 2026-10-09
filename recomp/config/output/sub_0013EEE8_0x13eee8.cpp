#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013EEE8
// Address: 0x13eee8 - 0x13ef58
void sub_0013EEE8_0x13eee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013EEE8_0x13eee8");
#endif

    switch (ctx->pc) {
        case 0x13ef08u: goto label_13ef08;
        case 0x13ef10u: goto label_13ef10;
        case 0x13ef24u: goto label_13ef24;
        case 0x13ef38u: goto label_13ef38;
        case 0x13ef40u: goto label_13ef40;
        default: break;
    }

    ctx->pc = 0x13eee8u;

    // 0x13eee8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13eee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13eeec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13eeecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13eef0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13eef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13eef4: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x13eef4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13eef8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13eef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13eefc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13eefcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13ef00: 0xc04fc86  jal         func_13F218
    ctx->pc = 0x13EF00u;
    SET_GPR_U32(ctx, 31, 0x13EF08u);
    ctx->pc = 0x13EF04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF00u;
            // 0x13ef04: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F218u;
    if (runtime->hasFunction(0x13F218u)) {
        auto targetFn = runtime->lookupFunction(0x13F218u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF08u; }
        if (ctx->pc != 0x13EF08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F218_0x13f218(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF08u; }
        if (ctx->pc != 0x13EF08u) { return; }
    }
    ctx->pc = 0x13EF08u;
label_13ef08:
    // 0x13ef08: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13ef08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13ef0c: 0x24503880  addiu       $s0, $v0, 0x3880
    ctx->pc = 0x13ef0cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 14464));
label_13ef10:
    // 0x13ef10: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x13ef10u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13ef14: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13EF14u;
    {
        const bool branch_taken_0x13ef14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13ef14) {
            ctx->pc = 0x13EF18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF14u;
            // 0x13ef18: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13EF28u;
            goto label_13ef28;
        }
    }
    ctx->pc = 0x13EF1Cu;
    // 0x13ef1c: 0xc04fb4a  jal         func_13ED28
    ctx->pc = 0x13EF1Cu;
    SET_GPR_U32(ctx, 31, 0x13EF24u);
    ctx->pc = 0x13EF20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF1Cu;
            // 0x13ef20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ED28u;
    if (runtime->hasFunction(0x13ED28u)) {
        auto targetFn = runtime->lookupFunction(0x13ED28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF24u; }
        if (ctx->pc != 0x13EF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013ED28_0x13ed28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF24u; }
        if (ctx->pc != 0x13EF24u) { return; }
    }
    ctx->pc = 0x13EF24u;
label_13ef24:
    // 0x13ef24: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13ef24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_13ef28:
    // 0x13ef28: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13EF28u;
    {
        const bool branch_taken_0x13ef28 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13EF2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF28u;
            // 0x13ef2c: 0x26100060  addiu       $s0, $s0, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13ef28) {
            ctx->pc = 0x13EF10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13ef10;
        }
    }
    ctx->pc = 0x13EF30u;
    // 0x13ef30: 0xc04fc8c  jal         func_13F230
    ctx->pc = 0x13EF30u;
    SET_GPR_U32(ctx, 31, 0x13EF38u);
    ctx->pc = 0x13F230u;
    if (runtime->hasFunction(0x13F230u)) {
        auto targetFn = runtime->lookupFunction(0x13F230u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF38u; }
        if (ctx->pc != 0x13EF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F230_0x13f230(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF38u; }
        if (ctx->pc != 0x13EF38u) { return; }
    }
    ctx->pc = 0x13EF38u;
label_13ef38:
    // 0x13ef38: 0xc04e276  jal         func_1389D8
    ctx->pc = 0x13EF38u;
    SET_GPR_U32(ctx, 31, 0x13EF40u);
    ctx->pc = 0x1389D8u;
    if (runtime->hasFunction(0x1389D8u)) {
        auto targetFn = runtime->lookupFunction(0x1389D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF40u; }
        if (ctx->pc != 0x13EF40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001389D8_0x1389d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13EF40u; }
        if (ctx->pc != 0x13EF40u) { return; }
    }
    ctx->pc = 0x13EF40u;
label_13ef40:
    // 0x13ef40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13ef40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ef44: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13ef44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13ef48: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13ef48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13ef4c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13ef4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13ef50: 0x805049a  j           func_141268
    ctx->pc = 0x13EF50u;
    ctx->pc = 0x13EF54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13EF50u;
            // 0x13ef54: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141268u;
    if (runtime->hasFunction(0x141268u)) {
        auto targetFn = runtime->lookupFunction(0x141268u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141268_0x141268(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13EF58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
