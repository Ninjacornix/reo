#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176790
// Address: 0x176790 - 0x176808
void sub_00176790_0x176790(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176790_0x176790");
#endif

    switch (ctx->pc) {
        case 0x1767acu: goto label_1767ac;
        case 0x1767e0u: goto label_1767e0;
        case 0x1767f0u: goto label_1767f0;
        default: break;
    }

    ctx->pc = 0x176790u;

    // 0x176790: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176790u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176794: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176794u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176798: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x176798u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17679c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17679cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1767a0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1767a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1767a4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1767A4u;
    SET_GPR_U32(ctx, 31, 0x1767ACu);
    ctx->pc = 0x1767A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1767A4u;
            // 0x1767a8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1767ACu; }
        if (ctx->pc != 0x1767ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1767ACu; }
        if (ctx->pc != 0x1767ACu) { return; }
    }
    ctx->pc = 0x1767ACu;
label_1767ac:
    // 0x1767ac: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1767acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1767b0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1767b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1767b4: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1767B4u;
    {
        const bool branch_taken_0x1767b4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1767B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1767B4u;
            // 0x1767b8: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1767b4) {
            ctx->pc = 0x1767D8u;
            goto label_1767d8;
        }
    }
    ctx->pc = 0x1767BCu;
    // 0x1767bc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1767bcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1767c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1767c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1767c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1767c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1767c8: 0x34a50123  ori         $a1, $a1, 0x123
    ctx->pc = 0x1767c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)291);
    // 0x1767cc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1767ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1767d0: 0x805a704  j           func_169C10
    ctx->pc = 0x1767D0u;
    ctx->pc = 0x1767D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1767D0u;
            // 0x1767d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1767D8u;
label_1767d8:
    // 0x1767d8: 0xc05da6c  jal         func_1769B0
    ctx->pc = 0x1767D8u;
    SET_GPR_U32(ctx, 31, 0x1767E0u);
    ctx->pc = 0x1767DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1767D8u;
            // 0x1767dc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1769B0u;
    if (runtime->hasFunction(0x1769B0u)) {
        auto targetFn = runtime->lookupFunction(0x1769B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1767E0u; }
        if (ctx->pc != 0x1767E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001769B0_0x1769b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1767E0u; }
        if (ctx->pc != 0x1767E0u) { return; }
    }
    ctx->pc = 0x1767E0u;
label_1767e0:
    // 0x1767e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1767e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1767e4: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x1767e4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x1767e8: 0xc05d518  jal         func_175460
    ctx->pc = 0x1767E8u;
    SET_GPR_U32(ctx, 31, 0x1767F0u);
    ctx->pc = 0x1767ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1767E8u;
            // 0x1767ec: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1767F0u; }
        if (ctx->pc != 0x1767F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1767F0u; }
        if (ctx->pc != 0x1767F0u) { return; }
    }
    ctx->pc = 0x1767F0u;
label_1767f0:
    // 0x1767f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1767f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1767f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1767f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1767f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1767f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1767fc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1767fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176800: 0x3e00008  jr          $ra
    ctx->pc = 0x176800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176800u;
            // 0x176804: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1767ACu: goto label_1767ac;
            case 0x1767D8u: goto label_1767d8;
            case 0x1767E0u: goto label_1767e0;
            case 0x1767F0u: goto label_1767f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176808u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
