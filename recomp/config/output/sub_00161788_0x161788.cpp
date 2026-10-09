#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161788
// Address: 0x161788 - 0x1617e4
void sub_00161788_0x161788(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161788_0x161788");
#endif

    switch (ctx->pc) {
        case 0x16179cu: goto label_16179c;
        case 0x1617b0u: goto label_1617b0;
        case 0x1617d0u: goto label_1617d0;
        default: break;
    }

    ctx->pc = 0x161788u;

    // 0x161788: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161788u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16178c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16178cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161790: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x161794: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x161794u;
    SET_GPR_U32(ctx, 31, 0x16179Cu);
    ctx->pc = 0x161798u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161794u;
            // 0x161798: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16179Cu; }
        if (ctx->pc != 0x16179Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16179Cu; }
        if (ctx->pc != 0x16179Cu) { return; }
    }
    ctx->pc = 0x16179Cu;
label_16179c:
    // 0x16179c: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x16179Cu;
    {
        const bool branch_taken_0x16179c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1617A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16179Cu;
            // 0x1617a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16179c) {
            ctx->pc = 0x1617C8u;
            goto label_1617c8;
        }
    }
    ctx->pc = 0x1617A4u;
    // 0x1617a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1617a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1617a8: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1617A8u;
    SET_GPR_U32(ctx, 31, 0x1617B0u);
    ctx->pc = 0x1617ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1617A8u;
            // 0x1617ac: 0x2484fdd8  addiu       $a0, $a0, -0x228 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966744));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617B0u; }
        if (ctx->pc != 0x1617B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617B0u; }
        if (ctx->pc != 0x1617B0u) { return; }
    }
    ctx->pc = 0x1617B0u;
label_1617b0:
    // 0x1617b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1617b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1617b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1617b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1617b8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1617b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1617bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1617BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1617C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1617BCu;
            // 0x1617c0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16179Cu: goto label_16179c;
            case 0x1617B0u: goto label_1617b0;
            case 0x1617C8u: goto label_1617c8;
            case 0x1617D0u: goto label_1617d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1617C4u;
    // 0x1617c4: 0x0  nop
    ctx->pc = 0x1617c4u;
    // NOP
label_1617c8:
    // 0x1617c8: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x1617C8u;
    SET_GPR_U32(ctx, 31, 0x1617D0u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617D0u; }
        if (ctx->pc != 0x1617D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1617D0u; }
        if (ctx->pc != 0x1617D0u) { return; }
    }
    ctx->pc = 0x1617D0u;
label_1617d0:
    // 0x1617d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1617d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1617d4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1617d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1617d8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1617d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1617dc: 0x805f4f2  j           func_17D3C8
    ctx->pc = 0x1617DCu;
    ctx->pc = 0x1617E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1617DCu;
            // 0x1617e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3C8u;
    if (runtime->hasFunction(0x17D3C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D3C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D3C8_0x17d3c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1617E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
