#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128128
// Address: 0x128128 - 0x128198
void sub_00128128_0x128128(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128128_0x128128");
#endif

    switch (ctx->pc) {
        case 0x128154u: goto label_128154;
        case 0x128164u: goto label_128164;
        case 0x128180u: goto label_128180;
        default: break;
    }

    ctx->pc = 0x128128u;

    // 0x128128: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x128128u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12812c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12812cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128130: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x128130u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x128134: 0x2451c7b8  addiu       $s1, $v0, -0x3848
    ctx->pc = 0x128134u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294952888));
    // 0x128138: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x128138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12813c: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x12813cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128140: 0x240600ff  addiu       $a2, $zero, 0xFF
    ctx->pc = 0x128140u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x128144: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x128144u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128148: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x128148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12814c: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x12814Cu;
    SET_GPR_U32(ctx, 31, 0x128154u);
    ctx->pc = 0x128150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12814Cu;
            // 0x128150: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128154u; }
        if (ctx->pc != 0x128154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128154u; }
        if (ctx->pc != 0x128154u) { return; }
    }
    ctx->pc = 0x128154u;
label_128154:
    // 0x128154: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x128154u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128158: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x128158u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12815c: 0xc042ca4  jal         func_10B290
    ctx->pc = 0x12815Cu;
    SET_GPR_U32(ctx, 31, 0x128164u);
    ctx->pc = 0x128160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12815Cu;
            // 0x128160: 0x240600ff  addiu       $a2, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B290u;
    if (runtime->hasFunction(0x10B290u)) {
        auto targetFn = runtime->lookupFunction(0x10B290u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128164u; }
        if (ctx->pc != 0x128164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B290_0x10b290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128164u; }
        if (ctx->pc != 0x128164u) { return; }
    }
    ctx->pc = 0x128164u;
label_128164:
    // 0x128164: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128164u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128168: 0x8c63c7b0  lw          $v1, -0x3850($v1)
    ctx->pc = 0x128168u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294952880)));
    // 0x12816c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x12816Cu;
    {
        const bool branch_taken_0x12816c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x128170u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12816Cu;
            // 0x128170: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12816c) {
            ctx->pc = 0x128180u;
            goto label_128180;
        }
    }
    ctx->pc = 0x128174u;
    // 0x128174: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128174u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128178: 0x60f809  jalr        $v1
    ctx->pc = 0x128178u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x128180u);
        ctx->pc = 0x12817Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128178u;
            // 0x12817c: 0x8c44c7b4  lw          $a0, -0x384C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294952884)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x128180u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128154u: goto label_128154;
            case 0x128164u: goto label_128164;
            case 0x128180u: goto label_128180;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x128180u; }
            if (ctx->pc != 0x128180u) { return; }
        }
        }
    }
    ctx->pc = 0x128180u;
label_128180:
    // 0x128180: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x128180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128184: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x128184u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x128188: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x128188u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12818c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12818cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x128190: 0x8050600  j           func_141800
    ctx->pc = 0x128190u;
    ctx->pc = 0x128194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128190u;
            // 0x128194: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141800u;
    if (runtime->hasFunction(0x141800u)) {
        auto targetFn = runtime->lookupFunction(0x141800u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141800_0x141800(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x128198u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
