#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001605B8
// Address: 0x1605b8 - 0x16061c
void sub_001605B8_0x1605b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001605B8_0x1605b8");
#endif

    switch (ctx->pc) {
        case 0x1605d4u: goto label_1605d4;
        case 0x1605ecu: goto label_1605ec;
        default: break;
    }

    ctx->pc = 0x1605b8u;

    // 0x1605b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1605b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1605bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1605bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1605c0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1605c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1605c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1605c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1605c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1605c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1605cc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1605CCu;
    SET_GPR_U32(ctx, 31, 0x1605D4u);
    ctx->pc = 0x1605D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1605CCu;
            // 0x1605d0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1605D4u; }
        if (ctx->pc != 0x1605D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1605D4u; }
        if (ctx->pc != 0x1605D4u) { return; }
    }
    ctx->pc = 0x1605D4u;
label_1605d4:
    // 0x1605d4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1605d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1605d8: 0x1440000b  bnez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1605D8u;
    {
        const bool branch_taken_0x1605d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1605DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1605D8u;
            // 0x1605dc: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1605d8) {
            ctx->pc = 0x160608u;
            goto label_160608;
        }
    }
    ctx->pc = 0x1605E0u;
    // 0x1605e0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1605e0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1605e4: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1605E4u;
    SET_GPR_U32(ctx, 31, 0x1605ECu);
    ctx->pc = 0x1605E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1605E4u;
            // 0x1605e8: 0x2484f748  addiu       $a0, $a0, -0x8B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965064));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1605ECu; }
        if (ctx->pc != 0x1605ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1605ECu; }
        if (ctx->pc != 0x1605ECu) { return; }
    }
    ctx->pc = 0x1605ECu;
label_1605ec:
    // 0x1605ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1605ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1605f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1605f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1605f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1605f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1605f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1605f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1605fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1605FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x160600u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1605FCu;
            // 0x160600: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1605D4u: goto label_1605d4;
            case 0x1605ECu: goto label_1605ec;
            case 0x160608u: goto label_160608;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160604u;
    // 0x160604: 0x0  nop
    ctx->pc = 0x160604u;
    // NOP
label_160608:
    // 0x160608: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160608u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16060c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16060cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160610: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160610u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160614: 0x8057df6  j           func_15F7D8
    ctx->pc = 0x160614u;
    ctx->pc = 0x160618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160614u;
            // 0x160618: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F7D8u;
    if (runtime->hasFunction(0x15F7D8u)) {
        auto targetFn = runtime->lookupFunction(0x15F7D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F7D8_0x15f7d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16061Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
