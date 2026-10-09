#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001604A0
// Address: 0x1604a0 - 0x1604f8
void sub_001604A0_0x1604a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001604A0_0x1604a0");
#endif

    switch (ctx->pc) {
        case 0x1604bcu: goto label_1604bc;
        default: break;
    }

    ctx->pc = 0x1604a0u;

    // 0x1604a0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1604a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1604a4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1604a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1604a8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1604a8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1604ac: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1604acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1604b0: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1604b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1604b4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1604B4u;
    SET_GPR_U32(ctx, 31, 0x1604BCu);
    ctx->pc = 0x1604B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1604B4u;
            // 0x1604b8: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1604BCu; }
        if (ctx->pc != 0x1604BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1604BCu; }
        if (ctx->pc != 0x1604BCu) { return; }
    }
    ctx->pc = 0x1604BCu;
label_1604bc:
    // 0x1604bc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1604bcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1604c0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1604c0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1604c4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1604C4u;
    {
        const bool branch_taken_0x1604c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1604C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1604C4u;
            // 0x1604c8: 0x2484f6b8  addiu       $a0, $a0, -0x948 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964920));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1604c4) {
            ctx->pc = 0x1604E0u;
            goto label_1604e0;
        }
    }
    ctx->pc = 0x1604CCu;
    // 0x1604cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1604ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1604d0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1604d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1604d4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1604d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1604d8: 0x8058dd4  j           func_163750
    ctx->pc = 0x1604D8u;
    ctx->pc = 0x1604DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1604D8u;
            // 0x1604dc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1604E0u;
label_1604e0:
    // 0x1604e0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1604e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1604e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1604e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1604e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1604e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1604ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1604ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1604f0: 0x8057de4  j           func_15F790
    ctx->pc = 0x1604F0u;
    ctx->pc = 0x1604F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1604F0u;
            // 0x1604f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F790u;
    if (runtime->hasFunction(0x15F790u)) {
        auto targetFn = runtime->lookupFunction(0x15F790u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F790_0x15f790(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1604F8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
