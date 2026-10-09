#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001384A0
// Address: 0x1384a0 - 0x138518
void sub_001384A0_0x1384a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001384A0_0x1384a0");
#endif

    switch (ctx->pc) {
        case 0x1384c4u: goto label_1384c4;
        case 0x1384d4u: goto label_1384d4;
        case 0x1384f0u: goto label_1384f0;
        case 0x1384f8u: goto label_1384f8;
        default: break;
    }

    ctx->pc = 0x1384a0u;

    // 0x1384a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1384a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1384a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1384a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1384a8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1384a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1384ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1384acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1384b0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1384b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1384b4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1384b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1384b8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1384b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1384bc: 0xc04e0bc  jal         func_1382F0
    ctx->pc = 0x1384BCu;
    SET_GPR_U32(ctx, 31, 0x1384C4u);
    ctx->pc = 0x1384C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1384BCu;
            // 0x1384c0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1382F0u;
    if (runtime->hasFunction(0x1382F0u)) {
        auto targetFn = runtime->lookupFunction(0x1382F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384C4u; }
        if (ctx->pc != 0x1384C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001382F0_0x1382f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384C4u; }
        if (ctx->pc != 0x1384C4u) { return; }
    }
    ctx->pc = 0x1384C4u;
label_1384c4:
    // 0x1384c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1384c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1384c8: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1384c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1384cc: 0xc046574  jal         func_1195D0
    ctx->pc = 0x1384CCu;
    SET_GPR_U32(ctx, 31, 0x1384D4u);
    ctx->pc = 0x1384D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1384CCu;
            // 0x1384d0: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1195D0u;
    if (runtime->hasFunction(0x1195D0u)) {
        auto targetFn = runtime->lookupFunction(0x1195D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384D4u; }
        if (ctx->pc != 0x1384D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001195D0_0x1195d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384D4u; }
        if (ctx->pc != 0x1384D4u) { return; }
    }
    ctx->pc = 0x1384D4u;
label_1384d4:
    // 0x1384d4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1384d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1384d8: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1384d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1384dc: 0x2484c740  addiu       $a0, $a0, -0x38C0
    ctx->pc = 0x1384dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952768));
    // 0x1384e0: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1384E0u;
    {
        const bool branch_taken_0x1384e0 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1384E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1384E0u;
            // 0x1384e4: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1384e0) {
            ctx->pc = 0x1384F0u;
            goto label_1384f0;
        }
    }
    ctx->pc = 0x1384E8u;
    // 0x1384e8: 0xc045a12  jal         func_116848
    ctx->pc = 0x1384E8u;
    SET_GPR_U32(ctx, 31, 0x1384F0u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384F0u; }
        if (ctx->pc != 0x1384F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384F0u; }
        if (ctx->pc != 0x1384F0u) { return; }
    }
    ctx->pc = 0x1384F0u;
label_1384f0:
    // 0x1384f0: 0xc04e0ca  jal         func_138328
    ctx->pc = 0x1384F0u;
    SET_GPR_U32(ctx, 31, 0x1384F8u);
    ctx->pc = 0x138328u;
    if (runtime->hasFunction(0x138328u)) {
        auto targetFn = runtime->lookupFunction(0x138328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384F8u; }
        if (ctx->pc != 0x1384F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138328_0x138328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1384F8u; }
        if (ctx->pc != 0x1384F8u) { return; }
    }
    ctx->pc = 0x1384F8u;
label_1384f8:
    // 0x1384f8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1384f8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1384fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1384fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138500: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138500u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138504: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x138504u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138508: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x138508u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13850c: 0x3e00008  jr          $ra
    ctx->pc = 0x13850Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13850Cu;
            // 0x138510: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1384C4u: goto label_1384c4;
            case 0x1384D4u: goto label_1384d4;
            case 0x1384F0u: goto label_1384f0;
            case 0x1384F8u: goto label_1384f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138514u;
    // 0x138514: 0x0  nop
    ctx->pc = 0x138514u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
