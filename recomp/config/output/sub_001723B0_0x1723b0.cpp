#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001723B0
// Address: 0x1723b0 - 0x172420
void sub_001723B0_0x1723b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001723B0_0x1723b0");
#endif

    switch (ctx->pc) {
        case 0x1723ccu: goto label_1723cc;
        case 0x172404u: goto label_172404;
        default: break;
    }

    ctx->pc = 0x1723b0u;

    // 0x1723b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1723b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1723b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1723b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1723b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1723b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1723bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1723bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1723c0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1723c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1723c4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1723C4u;
    SET_GPR_U32(ctx, 31, 0x1723CCu);
    ctx->pc = 0x1723C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1723C4u;
            // 0x1723c8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1723CCu; }
        if (ctx->pc != 0x1723CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1723CCu; }
        if (ctx->pc != 0x1723CCu) { return; }
    }
    ctx->pc = 0x1723CCu;
label_1723cc:
    // 0x1723cc: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1723ccu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1723d0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1723d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1723d4: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1723d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1723d8: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1723D8u;
    {
        const bool branch_taken_0x1723d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1723DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1723D8u;
            // 0x1723dc: 0x34a50146  ori         $a1, $a1, 0x146 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)326);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1723d8) {
            ctx->pc = 0x1723F8u;
            goto label_1723f8;
        }
    }
    ctx->pc = 0x1723E0u;
    // 0x1723e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1723e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1723e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1723e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1723e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1723e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1723ec: 0x805a704  j           func_169C10
    ctx->pc = 0x1723ECu;
    ctx->pc = 0x1723F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1723ECu;
            // 0x1723f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1723F4u;
    // 0x1723f4: 0x0  nop
    ctx->pc = 0x1723f4u;
    // NOP
label_1723f8:
    // 0x1723f8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1723f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1723fc: 0xc05d518  jal         func_175460
    ctx->pc = 0x1723FCu;
    SET_GPR_U32(ctx, 31, 0x172404u);
    ctx->pc = 0x172400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1723FCu;
            // 0x172400: 0x2405001d  addiu       $a1, $zero, 0x1D (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175460u;
    if (runtime->hasFunction(0x175460u)) {
        auto targetFn = runtime->lookupFunction(0x175460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172404u; }
        if (ctx->pc != 0x172404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175460_0x175460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x172404u; }
        if (ctx->pc != 0x172404u) { return; }
    }
    ctx->pc = 0x172404u;
label_172404:
    // 0x172404: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x172404u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x172408: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x172408u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17240c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17240cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x172410: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x172410u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x172414: 0x3e00008  jr          $ra
    ctx->pc = 0x172414u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x172418u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x172414u;
            // 0x172418: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1723CCu: goto label_1723cc;
            case 0x1723F8u: goto label_1723f8;
            case 0x172404u: goto label_172404;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17241Cu;
    // 0x17241c: 0x0  nop
    ctx->pc = 0x17241cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
