#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CF960
// Address: 0x1cf960 - 0x1cf9d0
void sub_001CF960_0x1cf960(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CF960_0x1cf960");
#endif

    switch (ctx->pc) {
        case 0x1cf984u: goto label_1cf984;
        case 0x1cf9a8u: goto label_1cf9a8;
        default: break;
    }

    ctx->pc = 0x1cf960u;

    // 0x1cf960: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1cf960u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1cf964: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1cf964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1cf968: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cf968u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cf96c: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1cf96cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf970: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cf970u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cf974: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1cf974u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf978: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1cf978u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf97c: 0xc073e40  jal         func_1CF900
    ctx->pc = 0x1CF97Cu;
    SET_GPR_U32(ctx, 31, 0x1CF984u);
    ctx->pc = 0x1CF980u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF97Cu;
            // 0x1cf980: 0xc0282d  daddu       $a1, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CF900u;
    if (runtime->hasFunction(0x1CF900u)) {
        auto targetFn = runtime->lookupFunction(0x1CF900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF984u; }
        if (ctx->pc != 0x1CF984u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CF900_0x1cf900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF984u; }
        if (ctx->pc != 0x1CF984u) { return; }
    }
    ctx->pc = 0x1CF984u;
label_1cf984:
    // 0x1cf984: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1cf984u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf988: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CF988u;
    {
        const bool branch_taken_0x1cf988 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cf988) {
            ctx->pc = 0x1CF998u;
            goto label_1cf998;
        }
    }
    ctx->pc = 0x1CF990u;
    // 0x1cf990: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CF990u;
    {
        const bool branch_taken_0x1cf990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CF994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF990u;
            // 0x1cf994: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cf990) {
            ctx->pc = 0x1CF9B0u;
            goto label_1cf9b0;
        }
    }
    ctx->pc = 0x1CF998u;
label_1cf998:
    // 0x1cf998: 0x8e050004  lw          $a1, 0x4($s0)
    ctx->pc = 0x1cf998u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cf99c: 0xe0202d  daddu       $a0, $a3, $zero
    ctx->pc = 0x1cf99cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cf9a0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CF9A0u;
    SET_GPR_U32(ctx, 31, 0x1CF9A8u);
    ctx->pc = 0x1CF9A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF9A0u;
            // 0x1cf9a4: 0x24060c84  addiu       $a2, $zero, 0xC84 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3204));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF9A8u; }
        if (ctx->pc != 0x1CF9A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CF9A8u; }
        if (ctx->pc != 0x1CF9A8u) { return; }
    }
    ctx->pc = 0x1CF9A8u;
label_1cf9a8:
    // 0x1cf9a8: 0xa611000a  sh          $s1, 0xA($s0)
    ctx->pc = 0x1cf9a8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 10), (uint16_t)GPR_U32(ctx, 17));
    // 0x1cf9ac: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cf9acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1cf9b0:
    // 0x1cf9b0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1cf9b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cf9b4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cf9b4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cf9b8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cf9b8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cf9bc: 0x3e00008  jr          $ra
    ctx->pc = 0x1CF9BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CF9C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CF9BCu;
            // 0x1cf9c0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CF984u: goto label_1cf984;
            case 0x1CF998u: goto label_1cf998;
            case 0x1CF9A8u: goto label_1cf9a8;
            case 0x1CF9B0u: goto label_1cf9b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CF9C4u;
    // 0x1cf9c4: 0x0  nop
    ctx->pc = 0x1cf9c4u;
    // NOP
    // 0x1cf9c8: 0x0  nop
    ctx->pc = 0x1cf9c8u;
    // NOP
    // 0x1cf9cc: 0x0  nop
    ctx->pc = 0x1cf9ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
