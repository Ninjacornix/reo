#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F30F0
// Address: 0x1f30f0 - 0x1f3190
void sub_001F30F0_0x1f30f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F30F0_0x1f30f0");
#endif

    switch (ctx->pc) {
        case 0x1f311cu: goto label_1f311c;
        case 0x1f3130u: goto label_1f3130;
        case 0x1f3144u: goto label_1f3144;
        case 0x1f3160u: goto label_1f3160;
        default: break;
    }

    ctx->pc = 0x1f30f0u;

    // 0x1f30f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f30f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f30f4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f30f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f30f8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f30f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f30fc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f30fcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3100: 0xafc40004  sw          $a0, 0x4($fp)
    ctx->pc = 0x1f3100u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 4));
    // 0x1f3104: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1f3104u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3108: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f3108u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f310c: 0xafc20008  sw          $v0, 0x8($fp)
    ctx->pc = 0x1f310cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1f3110: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3110u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3114: 0xc07cc13  jal         func_1F304C
    ctx->pc = 0x1F3114u;
    SET_GPR_U32(ctx, 31, 0x1F311Cu);
    ctx->pc = 0x1F304Cu;
    if (runtime->hasFunction(0x1F304Cu)) {
        auto targetFn = runtime->lookupFunction(0x1F304Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F311Cu; }
        if (ctx->pc != 0x1F311Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F304C_0x1f304c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F311Cu; }
        if (ctx->pc != 0x1F311Cu) { return; }
    }
    ctx->pc = 0x1F311Cu;
label_1f311c:
    // 0x1f311c: 0xafc20000  sw          $v0, 0x0($fp)
    ctx->pc = 0x1f311cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 2));
    // 0x1f3120: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3120u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3124: 0x8fc50008  lw          $a1, 0x8($fp)
    ctx->pc = 0x1f3124u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3128: 0xc07cc64  jal         func_1F3190
    ctx->pc = 0x1F3128u;
    SET_GPR_U32(ctx, 31, 0x1F3130u);
    ctx->pc = 0x1F3190u;
    if (runtime->hasFunction(0x1F3190u)) {
        auto targetFn = runtime->lookupFunction(0x1F3190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3130u; }
        if (ctx->pc != 0x1F3130u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3190_0x1f3190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3130u; }
        if (ctx->pc != 0x1F3130u) { return; }
    }
    ctx->pc = 0x1F3130u;
label_1f3130:
    // 0x1f3130: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F3130u;
    {
        const bool branch_taken_0x1f3130 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3130) {
            ctx->pc = 0x1F3168u;
            goto label_1f3168;
        }
    }
    ctx->pc = 0x1F3138u;
    // 0x1f3138: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3138u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f313c: 0xc07c6b6  jal         func_1F1AD8
    ctx->pc = 0x1F313Cu;
    SET_GPR_U32(ctx, 31, 0x1F3144u);
    ctx->pc = 0x1F1AD8u;
    if (runtime->hasFunction(0x1F1AD8u)) {
        auto targetFn = runtime->lookupFunction(0x1F1AD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3144u; }
        if (ctx->pc != 0x1F3144u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1AD8_0x1f1ad8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3144u; }
        if (ctx->pc != 0x1F3144u) { return; }
    }
    ctx->pc = 0x1F3144u;
label_1f3144:
    // 0x1f3144: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x1f3144u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1f3148: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1f3148u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f314c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1f314cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1f3150: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f3150u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f3154: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f3154u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f3158: 0xc07c6c0  jal         func_1F1B00
    ctx->pc = 0x1F3158u;
    SET_GPR_U32(ctx, 31, 0x1F3160u);
    ctx->pc = 0x1F1B00u;
    if (runtime->hasFunction(0x1F1B00u)) {
        auto targetFn = runtime->lookupFunction(0x1F1B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3160u; }
        if (ctx->pc != 0x1F3160u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B00_0x1f1b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F3160u; }
        if (ctx->pc != 0x1F3160u) { return; }
    }
    ctx->pc = 0x1F3160u;
label_1f3160:
    // 0x1f3160: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1F3160u;
    {
        const bool branch_taken_0x1f3160 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f3160) {
            ctx->pc = 0x1F3174u;
            goto label_1f3174;
        }
    }
    ctx->pc = 0x1F3168u;
label_1f3168:
    // 0x1f3168: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3168u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f316c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1F316Cu;
    {
        const bool branch_taken_0x1f316c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f316c) {
            ctx->pc = 0x1F3178u;
            goto label_1f3178;
        }
    }
    ctx->pc = 0x1F3174u;
label_1f3174:
    // 0x1f3174: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f3174u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
label_1f3178:
    // 0x1f3178: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f3178u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f317c: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f317cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f3180: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f3180u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f3184: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f3184u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f3188: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F311Cu: goto label_1f311c;
            case 0x1F3130u: goto label_1f3130;
            case 0x1F3144u: goto label_1f3144;
            case 0x1F3160u: goto label_1f3160;
            case 0x1F3168u: goto label_1f3168;
            case 0x1F3174u: goto label_1f3174;
            case 0x1F3178u: goto label_1f3178;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3190u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
