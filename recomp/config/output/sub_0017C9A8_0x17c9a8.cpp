#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C9A8
// Address: 0x17c9a8 - 0x17ca10
void sub_0017C9A8_0x17c9a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C9A8_0x17c9a8");
#endif

    switch (ctx->pc) {
        case 0x17c9c8u: goto label_17c9c8;
        default: break;
    }

    ctx->pc = 0x17c9a8u;

    // 0x17c9a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17c9a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17c9ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17c9acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17c9b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17c9b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c9b4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17c9b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17c9b8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17c9b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c9bc: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17c9bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17c9c0: 0xc05f8da  jal         func_17E368
    ctx->pc = 0x17C9C0u;
    SET_GPR_U32(ctx, 31, 0x17C9C8u);
    ctx->pc = 0x17C9C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C9C0u;
            // 0x17c9c4: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E368u;
    if (runtime->hasFunction(0x17E368u)) {
        auto targetFn = runtime->lookupFunction(0x17E368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C9C8u; }
        if (ctx->pc != 0x17C9C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E368_0x17e368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C9C8u; }
        if (ctx->pc != 0x17C9C8u) { return; }
    }
    ctx->pc = 0x17C9C8u;
label_17c9c8:
    // 0x17c9c8: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17c9c8u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17c9cc: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17c9ccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17c9d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c9d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c9d4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c9d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c9d8: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17C9D8u;
    {
        const bool branch_taken_0x17c9d8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17C9DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C9D8u;
            // 0x17c9dc: 0x24c612f8  addiu       $a2, $a2, 0x12F8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4856));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c9d8) {
            ctx->pc = 0x17C9F8u;
            goto label_17c9f8;
        }
    }
    ctx->pc = 0x17C9E0u;
    // 0x17c9e0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c9e0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c9e4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c9e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c9e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17c9e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c9ec: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17C9ECu;
    ctx->pc = 0x17C9F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C9ECu;
            // 0x17c9f0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C9F4u;
    // 0x17c9f4: 0x0  nop
    ctx->pc = 0x17c9f4u;
    // NOP
label_17c9f8:
    // 0x17c9f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c9f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c9fc: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c9fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17ca00: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17ca00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17ca04: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17ca04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17ca08: 0x805f1f8  j           func_17C7E0
    ctx->pc = 0x17CA08u;
    ctx->pc = 0x17CA0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17CA08u;
            // 0x17ca0c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C7E0u;
    if (runtime->hasFunction(0x17C7E0u)) {
        auto targetFn = runtime->lookupFunction(0x17C7E0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C7E0_0x17c7e0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17CA10u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
