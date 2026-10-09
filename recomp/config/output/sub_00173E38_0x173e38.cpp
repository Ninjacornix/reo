#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173E38
// Address: 0x173e38 - 0x173ea8
void sub_00173E38_0x173e38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173E38_0x173e38");
#endif

    switch (ctx->pc) {
        case 0x173e54u: goto label_173e54;
        default: break;
    }

    ctx->pc = 0x173e38u;

    // 0x173e38: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173e38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173e3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173e40: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x173e40u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173e44: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x173e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x173e48: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x173e48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x173e4c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x173E4Cu;
    SET_GPR_U32(ctx, 31, 0x173E54u);
    ctx->pc = 0x173E50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173E4Cu;
            // 0x173e50: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173E54u; }
        if (ctx->pc != 0x173E54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173E54u; }
        if (ctx->pc != 0x173E54u) { return; }
    }
    ctx->pc = 0x173E54u;
label_173e54:
    // 0x173e54: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173e54u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173e58: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173e58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173e5c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x173e5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173e60: 0x34a50134  ori         $a1, $a1, 0x134
    ctx->pc = 0x173e60u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)308);
    // 0x173e64: 0x24060009  addiu       $a2, $zero, 0x9
    ctx->pc = 0x173e64u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x173e68: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x173E68u;
    {
        const bool branch_taken_0x173e68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173E68u;
            // 0x173e6c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173e68) {
            ctx->pc = 0x173E88u;
            goto label_173e88;
        }
    }
    ctx->pc = 0x173E70u;
    // 0x173e70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173e70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173e74: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173e74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173e78: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x173e78u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173e7c: 0x805a704  j           func_169C10
    ctx->pc = 0x173E7Cu;
    ctx->pc = 0x173E80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173E7Cu;
            // 0x173e80: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173E84u;
    // 0x173e84: 0x0  nop
    ctx->pc = 0x173e84u;
    // NOP
label_173e88:
    // 0x173e88: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x173e88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173e8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173e8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173e90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173e90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173e94: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x173e94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173e98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x173e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173e9c: 0x805def8  j           func_177BE0
    ctx->pc = 0x173E9Cu;
    ctx->pc = 0x173EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173E9Cu;
            // 0x173ea0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177BE0_0x177be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173EA4u;
    // 0x173ea4: 0x0  nop
    ctx->pc = 0x173ea4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
