#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F0B8
// Address: 0x15f0b8 - 0x15f140
void sub_0015F0B8_0x15f0b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F0B8_0x15f0b8");
#endif

    switch (ctx->pc) {
        case 0x15f0d4u: goto label_15f0d4;
        default: break;
    }

    ctx->pc = 0x15f0b8u;

    // 0x15f0b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15f0b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15f0bc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f0c0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15f0c0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f0c4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f0c8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15f0c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15f0cc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15F0CCu;
    SET_GPR_U32(ctx, 31, 0x15F0D4u);
    ctx->pc = 0x15F0D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0CCu;
            // 0x15f0d0: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F0D4u; }
        if (ctx->pc != 0x15F0D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F0D4u; }
        if (ctx->pc != 0x15F0D4u) { return; }
    }
    ctx->pc = 0x15F0D4u;
label_15f0d4:
    // 0x15f0d4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f0d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f0d8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15F0D8u;
    {
        const bool branch_taken_0x15f0d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F0DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0D8u;
            // 0x15f0dc: 0x2484f0c0  addiu       $a0, $a0, -0xF40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963392));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f0d8) {
            ctx->pc = 0x15F0F8u;
            goto label_15f0f8;
        }
    }
    ctx->pc = 0x15F0E0u;
    // 0x15f0e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f0e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f0e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f0e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f0e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f0e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f0ec: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F0ECu;
    ctx->pc = 0x15F0F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0ECu;
            // 0x15f0f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F0F4u;
    // 0x15f0f4: 0x0  nop
    ctx->pc = 0x15f0f4u;
    // NOP
label_15f0f8:
    // 0x15f0f8: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x15F0F8u;
    {
        const bool branch_taken_0x15f0f8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x15F0FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F0F8u;
            // 0x15f0fc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f0f8) {
            ctx->pc = 0x15F120u;
            goto label_15f120;
        }
    }
    ctx->pc = 0x15F100u;
    // 0x15f100: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15f100u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15f104: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f104u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f108: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f108u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f10c: 0x2484f0f0  addiu       $a0, $a0, -0xF10
    ctx->pc = 0x15f10cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963440));
    // 0x15f110: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f110u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f114: 0x8058dd4  j           func_163750
    ctx->pc = 0x15F114u;
    ctx->pc = 0x15F118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F114u;
            // 0x15f118: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F11Cu;
    // 0x15f11c: 0x0  nop
    ctx->pc = 0x15f11cu;
    // NOP
label_15f120:
    // 0x15f120: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f120u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f124: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x15f124u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f128: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f128u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f12c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15f12cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f130: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x15f130u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f134: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x15f134u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x15f138: 0x8057c50  j           func_15F140
    ctx->pc = 0x15F138u;
    ctx->pc = 0x15F13Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F138u;
            // 0x15f13c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F140u;
    if (runtime->hasFunction(0x15F140u)) {
        auto targetFn = runtime->lookupFunction(0x15F140u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F140_0x15f140(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F140u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
