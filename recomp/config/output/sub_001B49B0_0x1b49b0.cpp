#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B49B0
// Address: 0x1b49b0 - 0x1b4a20
void sub_001B49B0_0x1b49b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B49B0_0x1b49b0");
#endif

    switch (ctx->pc) {
        case 0x1b49d4u: goto label_1b49d4;
        case 0x1b49e8u: goto label_1b49e8;
        default: break;
    }

    ctx->pc = 0x1b49b0u;

    // 0x1b49b0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b49b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b49b4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b49b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b49b8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b49b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b49bc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b49bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b49c0: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1b49c0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b49c4: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b49c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b49c8: 0x3c110031  lui         $s1, 0x31
    ctx->pc = 0x1b49c8u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)49 << 16));
    // 0x1b49cc: 0x263151d0  addiu       $s1, $s1, 0x51D0
    ctx->pc = 0x1b49ccu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 20944));
    // 0x1b49d0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1b49d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b49d4:
    // 0x1b49d4: 0x86230000  lh          $v1, 0x0($s1)
    ctx->pc = 0x1b49d4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1b49d8: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B49D8u;
    {
        const bool branch_taken_0x1b49d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B49DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B49D8u;
            // 0x1b49dc: 0x2624000c  addiu       $a0, $s1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b49d8) {
            ctx->pc = 0x1B49F4u;
            goto label_1b49f4;
        }
    }
    ctx->pc = 0x1B49E0u;
    // 0x1b49e0: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1B49E0u;
    SET_GPR_U32(ctx, 31, 0x1B49E8u);
    ctx->pc = 0x1B49E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B49E0u;
            // 0x1b49e4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B49E8u; }
        if (ctx->pc != 0x1B49E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B49E8u; }
        if (ctx->pc != 0x1B49E8u) { return; }
    }
    ctx->pc = 0x1B49E8u;
label_1b49e8:
    // 0x1b49e8: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B49E8u;
    {
        const bool branch_taken_0x1b49e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b49e8) {
            ctx->pc = 0x1B49F4u;
            goto label_1b49f4;
        }
    }
    ctx->pc = 0x1B49F0u;
    // 0x1b49f0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1b49f0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
label_1b49f4:
    // 0x1b49f4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1b49f4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1b49f8: 0x2a030020  slti        $v1, $s0, 0x20
    ctx->pc = 0x1b49f8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b49fc: 0x1460fff5  bnez        $v1, . + 4 + (-0xB << 2)
    ctx->pc = 0x1B49FCu;
    {
        const bool branch_taken_0x1b49fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B49FCu;
            // 0x1b4a00: 0x2631008c  addiu       $s1, $s1, 0x8C (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 140));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b49fc) {
            ctx->pc = 0x1B49D4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b49d4;
        }
    }
    ctx->pc = 0x1B4A04u;
    // 0x1b4a04: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b4a04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b4a08: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b4a08u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b4a0c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b4a0cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4a10: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4a10u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4a14: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4A14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4A14u;
            // 0x1b4a18: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B49D4u: goto label_1b49d4;
            case 0x1B49E8u: goto label_1b49e8;
            case 0x1B49F4u: goto label_1b49f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B4A1Cu;
    // 0x1b4a1c: 0x0  nop
    ctx->pc = 0x1b4a1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
