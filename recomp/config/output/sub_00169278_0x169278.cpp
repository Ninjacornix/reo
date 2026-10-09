#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169278
// Address: 0x169278 - 0x1692e0
void sub_00169278_0x169278(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169278_0x169278");
#endif

    switch (ctx->pc) {
        case 0x169294u: goto label_169294;
        case 0x1692a8u: goto label_1692a8;
        case 0x1692b0u: goto label_1692b0;
        default: break;
    }

    ctx->pc = 0x169278u;

    // 0x169278: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169278u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16927c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x16927cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169280: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x169280u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169284: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169288: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x169288u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16928c: 0xc05a4b8  jal         func_1692E0
    ctx->pc = 0x16928Cu;
    SET_GPR_U32(ctx, 31, 0x169294u);
    ctx->pc = 0x169290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16928Cu;
            // 0x169290: 0x26300078  addiu       $s0, $s1, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1692E0u;
    if (runtime->hasFunction(0x1692E0u)) {
        auto targetFn = runtime->lookupFunction(0x1692E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169294u; }
        if (ctx->pc != 0x169294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001692E0_0x1692e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169294u; }
        if (ctx->pc != 0x169294u) { return; }
    }
    ctx->pc = 0x169294u;
label_169294:
    // 0x169294: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x169294u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169298: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x169298u;
    {
        const bool branch_taken_0x169298 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16929Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169298u;
            // 0x16929c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169298) {
            ctx->pc = 0x1692C8u;
            goto label_1692c8;
        }
    }
    ctx->pc = 0x1692A0u;
    // 0x1692a0: 0xc05a46a  jal         func_1691A8
    ctx->pc = 0x1692A0u;
    SET_GPR_U32(ctx, 31, 0x1692A8u);
    ctx->pc = 0x1691A8u;
    if (runtime->hasFunction(0x1691A8u)) {
        auto targetFn = runtime->lookupFunction(0x1691A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1692A8u; }
        if (ctx->pc != 0x1692A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001691A8_0x1691a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1692A8u; }
        if (ctx->pc != 0x1692A8u) { return; }
    }
    ctx->pc = 0x1692A8u;
label_1692a8:
    // 0x1692a8: 0xc05a4cc  jal         func_169330
    ctx->pc = 0x1692A8u;
    SET_GPR_U32(ctx, 31, 0x1692B0u);
    ctx->pc = 0x1692ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1692A8u;
            // 0x1692ac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169330u;
    if (runtime->hasFunction(0x169330u)) {
        auto targetFn = runtime->lookupFunction(0x169330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1692B0u; }
        if (ctx->pc != 0x1692B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169330_0x169330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1692B0u; }
        if (ctx->pc != 0x1692B0u) { return; }
    }
    ctx->pc = 0x1692B0u;
label_1692b0:
    // 0x1692b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1692b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1692b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1692b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1692b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1692b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1692bc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1692bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1692c0: 0x805a654  j           func_169950
    ctx->pc = 0x1692C0u;
    ctx->pc = 0x1692C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1692C0u;
            // 0x1692c4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169950u;
    if (runtime->hasFunction(0x169950u)) {
        auto targetFn = runtime->lookupFunction(0x169950u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169950_0x169950(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1692C8u;
label_1692c8:
    // 0x1692c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1692c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1692cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1692ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1692d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1692d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1692d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1692D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1692D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1692D4u;
            // 0x1692d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169294u: goto label_169294;
            case 0x1692A8u: goto label_1692a8;
            case 0x1692B0u: goto label_1692b0;
            case 0x1692C8u: goto label_1692c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1692DCu;
    // 0x1692dc: 0x0  nop
    ctx->pc = 0x1692dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
