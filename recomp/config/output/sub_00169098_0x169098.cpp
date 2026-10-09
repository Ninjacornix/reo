#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169098
// Address: 0x169098 - 0x1690f0
void sub_00169098_0x169098(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169098_0x169098");
#endif

    switch (ctx->pc) {
        case 0x1690acu: goto label_1690ac;
        case 0x1690c4u: goto label_1690c4;
        case 0x1690d8u: goto label_1690d8;
        default: break;
    }

    ctx->pc = 0x169098u;

    // 0x169098: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169098u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16909c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16909cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1690a0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1690a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1690a4: 0xc05e43c  jal         func_1790F0
    ctx->pc = 0x1690A4u;
    SET_GPR_U32(ctx, 31, 0x1690ACu);
    ctx->pc = 0x1790F0u;
    if (runtime->hasFunction(0x1790F0u)) {
        auto targetFn = runtime->lookupFunction(0x1790F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1690ACu; }
        if (ctx->pc != 0x1690ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001790F0_0x1790f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1690ACu; }
        if (ctx->pc != 0x1690ACu) { return; }
    }
    ctx->pc = 0x1690ACu;
label_1690ac:
    // 0x1690ac: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1690acu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1690b0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1690b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1690b4: 0x12000009  beqz        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1690B4u;
    {
        const bool branch_taken_0x1690b4 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x1690B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1690B4u;
            // 0x1690b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1690b4) {
            ctx->pc = 0x1690DCu;
            goto label_1690dc;
        }
    }
    ctx->pc = 0x1690BCu;
    // 0x1690bc: 0xc05e4c2  jal         func_179308
    ctx->pc = 0x1690BCu;
    SET_GPR_U32(ctx, 31, 0x1690C4u);
    ctx->pc = 0x179308u;
    if (runtime->hasFunction(0x179308u)) {
        auto targetFn = runtime->lookupFunction(0x179308u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1690C4u; }
        if (ctx->pc != 0x1690C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179308_0x179308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1690C4u; }
        if (ctx->pc != 0x1690C4u) { return; }
    }
    ctx->pc = 0x1690C4u;
label_1690c4:
    // 0x1690c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1690c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1690c8: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x1690c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1690cc: 0x2180a  movz        $v1, $zero, $v0
    ctx->pc = 0x1690ccu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 0));
    // 0x1690d0: 0xc05e46e  jal         func_1791B8
    ctx->pc = 0x1690D0u;
    SET_GPR_U32(ctx, 31, 0x1690D8u);
    ctx->pc = 0x1690D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1690D0u;
            // 0x1690d4: 0xafa30000  sw          $v1, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1791B8u;
    if (runtime->hasFunction(0x1791B8u)) {
        auto targetFn = runtime->lookupFunction(0x1791B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1690D8u; }
        if (ctx->pc != 0x1690D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001791B8_0x1791b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1690D8u; }
        if (ctx->pc != 0x1690D8u) { return; }
    }
    ctx->pc = 0x1690D8u;
label_1690d8:
    // 0x1690d8: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1690d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_1690dc:
    // 0x1690dc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1690dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1690e0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1690e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1690e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1690E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1690E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1690E4u;
            // 0x1690e8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1690ACu: goto label_1690ac;
            case 0x1690C4u: goto label_1690c4;
            case 0x1690D8u: goto label_1690d8;
            case 0x1690DCu: goto label_1690dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1690ECu;
    // 0x1690ec: 0x0  nop
    ctx->pc = 0x1690ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
