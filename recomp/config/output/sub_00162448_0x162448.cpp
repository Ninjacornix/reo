#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162448
// Address: 0x162448 - 0x1624ac
void sub_00162448_0x162448(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162448_0x162448");
#endif

    switch (ctx->pc) {
        case 0x162464u: goto label_162464;
        case 0x162490u: goto label_162490;
        default: break;
    }

    ctx->pc = 0x162448u;

    // 0x162448: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x162448u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16244c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16244cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162450: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x162450u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162454: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x162454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x162458: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x162458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16245c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16245Cu;
    SET_GPR_U32(ctx, 31, 0x162464u);
    ctx->pc = 0x162460u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16245Cu;
            // 0x162460: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162464u; }
        if (ctx->pc != 0x162464u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162464u; }
        if (ctx->pc != 0x162464u) { return; }
    }
    ctx->pc = 0x162464u;
label_162464:
    // 0x162464: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x162464u;
    {
        const bool branch_taken_0x162464 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x162468u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162464u;
            // 0x162468: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162464) {
            ctx->pc = 0x162488u;
            goto label_162488;
        }
    }
    ctx->pc = 0x16246Cu;
    // 0x16246c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16246cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x162470: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162470u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162474: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162474u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162478: 0x248400a8  addiu       $a0, $a0, 0xA8
    ctx->pc = 0x162478u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 168));
    // 0x16247c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x16247cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162480: 0x8058dd4  j           func_163750
    ctx->pc = 0x162480u;
    ctx->pc = 0x162484u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162480u;
            // 0x162484: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162488u;
label_162488:
    // 0x162488: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x162488u;
    SET_GPR_U32(ctx, 31, 0x162490u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162490u; }
        if (ctx->pc != 0x162490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162490u; }
        if (ctx->pc != 0x162490u) { return; }
    }
    ctx->pc = 0x162490u;
label_162490:
    // 0x162490: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x162490u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162494: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162494u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162498: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x162498u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16249c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16249cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1624a0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1624a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1624a4: 0x805f57c  j           func_17D5F0
    ctx->pc = 0x1624A4u;
    ctx->pc = 0x1624A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1624A4u;
            // 0x1624a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D5F0u;
    if (runtime->hasFunction(0x17D5F0u)) {
        auto targetFn = runtime->lookupFunction(0x17D5F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D5F0_0x17d5f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1624ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
