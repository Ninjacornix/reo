#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017C940
// Address: 0x17c940 - 0x17c9a8
void sub_0017C940_0x17c940(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017C940_0x17c940");
#endif

    switch (ctx->pc) {
        case 0x17c960u: goto label_17c960;
        default: break;
    }

    ctx->pc = 0x17c940u;

    // 0x17c940: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17c940u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17c944: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17c944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17c948: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17c948u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c94c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17c94cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17c950: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x17c950u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c954: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x17c954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x17c958: 0xc05f8da  jal         func_17E368
    ctx->pc = 0x17C958u;
    SET_GPR_U32(ctx, 31, 0x17C960u);
    ctx->pc = 0x17C95Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C958u;
            // 0x17c95c: 0x8e040024  lw          $a0, 0x24($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E368u;
    if (runtime->hasFunction(0x17E368u)) {
        auto targetFn = runtime->lookupFunction(0x17E368u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C960u; }
        if (ctx->pc != 0x17C960u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E368_0x17e368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17C960u; }
        if (ctx->pc != 0x17C960u) { return; }
    }
    ctx->pc = 0x17C960u;
label_17c960:
    // 0x17c960: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x17c960u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x17c964: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17c964u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17c968: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17c968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c96c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c96cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c970: 0x10430007  beq         $v0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x17C970u;
    {
        const bool branch_taken_0x17c970 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x17C974u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17C970u;
            // 0x17c974: 0x24c612c8  addiu       $a2, $a2, 0x12C8 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4808));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17c970) {
            ctx->pc = 0x17C990u;
            goto label_17c990;
        }
    }
    ctx->pc = 0x17C978u;
    // 0x17c978: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c978u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c97c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c97cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c980: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17c980u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c984: 0x805f472  j           func_17D1C8
    ctx->pc = 0x17C984u;
    ctx->pc = 0x17C988u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C984u;
            // 0x17c988: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D1C8u;
    if (runtime->hasFunction(0x17D1C8u)) {
        auto targetFn = runtime->lookupFunction(0x17D1C8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D1C8_0x17d1c8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C98Cu;
    // 0x17c98c: 0x0  nop
    ctx->pc = 0x17c98cu;
    // NOP
label_17c990:
    // 0x17c990: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17c990u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17c994: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17c994u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17c998: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17c998u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17c99c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x17c99cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17c9a0: 0x805f1f0  j           func_17C7C0
    ctx->pc = 0x17C9A0u;
    ctx->pc = 0x17C9A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17C9A0u;
            // 0x17c9a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17C7C0u;
    if (runtime->hasFunction(0x17C7C0u)) {
        auto targetFn = runtime->lookupFunction(0x17C7C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017C7C0_0x17c7c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17C9A8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
