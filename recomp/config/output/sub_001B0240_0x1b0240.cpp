#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0240
// Address: 0x1b0240 - 0x1b02cc
void sub_001B0240_0x1b0240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0240_0x1b0240");
#endif

    switch (ctx->pc) {
        case 0x1b0254u: goto label_1b0254;
        case 0x1b0290u: goto label_1b0290;
        case 0x1b02a0u: goto label_1b02a0;
        default: break;
    }

    ctx->pc = 0x1b0240u;

    // 0x1b0240: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0240u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0244: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0248: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0248u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b024c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1B024Cu;
    SET_GPR_U32(ctx, 31, 0x1B0254u);
    ctx->pc = 0x1B0250u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B024Cu;
            // 0x1b0250: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0254u; }
        if (ctx->pc != 0x1B0254u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0254u; }
        if (ctx->pc != 0x1B0254u) { return; }
    }
    ctx->pc = 0x1B0254u;
label_1b0254:
    // 0x1b0254: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1b0254u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b0258: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1B0258u;
    {
        const bool branch_taken_0x1b0258 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0258) {
            ctx->pc = 0x1B02A8u;
            goto label_1b02a8;
        }
    }
    ctx->pc = 0x1B0260u;
    // 0x1b0260: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1b0260u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1b0264: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B0264u;
    {
        const bool branch_taken_0x1b0264 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b0264) {
            ctx->pc = 0x1B02A8u;
            goto label_1b02a8;
        }
    }
    ctx->pc = 0x1B026Cu;
    // 0x1b026c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1b026cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0270: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B0270u;
    {
        const bool branch_taken_0x1b0270 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B0274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0270u;
            // 0x1b0274: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0270) {
            ctx->pc = 0x1B0298u;
            goto label_1b0298;
        }
    }
    ctx->pc = 0x1B0278u;
    // 0x1b0278: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0278u;
    {
        const bool branch_taken_0x1b0278 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B027Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0278u;
            // 0x1b027c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0278) {
            ctx->pc = 0x1B0288u;
            goto label_1b0288;
        }
    }
    ctx->pc = 0x1B0280u;
    // 0x1b0280: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B0280u;
    {
        const bool branch_taken_0x1b0280 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b0280) {
            ctx->pc = 0x1B02A8u;
            goto label_1b02a8;
        }
    }
    ctx->pc = 0x1B0288u;
label_1b0288:
    // 0x1b0288: 0xc204750  jal         func_811D40
    ctx->pc = 0x1B0288u;
    SET_GPR_U32(ctx, 31, 0x1B0290u);
    ctx->pc = 0x811D40u;
    {
        auto targetFn = runtime->lookupFunction(0x811D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0290u; }
        if (ctx->pc != 0x1B0290u) { return; }
    }
    ctx->pc = 0x1B0290u;
label_1b0290:
    // 0x1b0290: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B0290u;
    {
        const bool branch_taken_0x1b0290 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0290u;
            // 0x1b0294: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0290) {
            ctx->pc = 0x1B02C0u;
            goto label_1b02c0;
        }
    }
    ctx->pc = 0x1B0298u;
label_1b0298:
    // 0x1b0298: 0xc20457c  jal         func_8115F0
    ctx->pc = 0x1B0298u;
    SET_GPR_U32(ctx, 31, 0x1B02A0u);
    ctx->pc = 0x8115F0u;
    {
        auto targetFn = runtime->lookupFunction(0x8115F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B02A0u; }
        if (ctx->pc != 0x1B02A0u) { return; }
    }
    ctx->pc = 0x1B02A0u;
label_1b02a0:
    // 0x1b02a0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B02A0u;
    {
        const bool branch_taken_0x1b02a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b02a0) {
            ctx->pc = 0x1B02BCu;
            goto label_1b02bc;
        }
    }
    ctx->pc = 0x1B02A8u;
label_1b02a8:
    // 0x1b02a8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b02a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b02ac: 0x942243dc  lhu         $v0, 0x43DC($at)
    ctx->pc = 0x1b02acu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b02b0: 0x501026  xor         $v0, $v0, $s0
    ctx->pc = 0x1b02b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 16));
    // 0x1b02b4: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x1b02b4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1b02b8: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1b02b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
label_1b02bc:
    // 0x1b02bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b02bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b02c0:
    // 0x1b02c0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b02c0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b02c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B02C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B02C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B02C4u;
            // 0x1b02c8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0254u: goto label_1b0254;
            case 0x1B0288u: goto label_1b0288;
            case 0x1B0290u: goto label_1b0290;
            case 0x1B0298u: goto label_1b0298;
            case 0x1B02A0u: goto label_1b02a0;
            case 0x1B02A8u: goto label_1b02a8;
            case 0x1B02BCu: goto label_1b02bc;
            case 0x1B02C0u: goto label_1b02c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B02CCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
