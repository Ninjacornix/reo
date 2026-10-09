#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D190
// Address: 0x13d190 - 0x13d224
void sub_0013D190_0x13d190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D190_0x13d190");
#endif

    switch (ctx->pc) {
        case 0x13d1a8u: goto label_13d1a8;
        case 0x13d1c8u: goto label_13d1c8;
        case 0x13d204u: goto label_13d204;
        default: break;
    }

    ctx->pc = 0x13d190u;

    // 0x13d190: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13d190u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13d194: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13D194u;
    {
        const bool branch_taken_0x13d194 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D194u;
            // 0x13d198: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d194) {
            ctx->pc = 0x13D1B0u;
            goto label_13d1b0;
        }
    }
    ctx->pc = 0x13D19Cu;
    // 0x13d19c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d19cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d1a0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D1A0u;
    SET_GPR_U32(ctx, 31, 0x13D1A8u);
    ctx->pc = 0x13D1A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1A0u;
            // 0x13d1a4: 0x2484d368  addiu       $a0, $a0, -0x2C98 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955880));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D1A8u; }
        if (ctx->pc != 0x13D1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D1A8u; }
        if (ctx->pc != 0x13D1A8u) { return; }
    }
    ctx->pc = 0x13D1A8u;
label_13d1a8:
    // 0x13d1a8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x13D1A8u;
    {
        const bool branch_taken_0x13d1a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D1ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1A8u;
            // 0x13d1ac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d1a8) {
            ctx->pc = 0x13D218u;
            goto label_13d218;
        }
    }
    ctx->pc = 0x13D1B0u;
label_13d1b0:
    // 0x13d1b0: 0x24860038  addiu       $a2, $a0, 0x38
    ctx->pc = 0x13d1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 56));
    // 0x13d1b4: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d1b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d1b8: 0x1045000c  beq         $v0, $a1, . + 4 + (0xC << 2)
    ctx->pc = 0x13D1B8u;
    {
        const bool branch_taken_0x13d1b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        ctx->pc = 0x13D1BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1B8u;
            // 0x13d1bc: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d1b8) {
            ctx->pc = 0x13D1ECu;
            goto label_13d1ec;
        }
    }
    ctx->pc = 0x13D1C0u;
    // 0x13d1c0: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x13d1c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x13d1c4: 0x0  nop
    ctx->pc = 0x13d1c4u;
    // NOP
label_13d1c8:
    // 0x13d1c8: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x13d1c8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13d1cc: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D1CCu;
    {
        const bool branch_taken_0x13d1cc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D1D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1CCu;
            // 0x13d1d0: 0x24c60020  addiu       $a2, $a2, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d1cc) {
            ctx->pc = 0x13D1ECu;
            goto label_13d1ec;
        }
    }
    ctx->pc = 0x13D1D4u;
    // 0x13d1d4: 0x8cc20000  lw          $v0, 0x0($a2)
    ctx->pc = 0x13d1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x13d1d8: 0x0  nop
    ctx->pc = 0x13d1d8u;
    // NOP
    // 0x13d1dc: 0x0  nop
    ctx->pc = 0x13d1dcu;
    // NOP
    // 0x13d1e0: 0x0  nop
    ctx->pc = 0x13d1e0u;
    // NOP
    // 0x13d1e4: 0x5445fff8  bnel        $v0, $a1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13D1E4u;
    {
        const bool branch_taken_0x13d1e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        if (branch_taken_0x13d1e4) {
            ctx->pc = 0x13D1E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1E4u;
            // 0x13d1e8: 0x24630001  addiu       $v1, $v1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D1C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d1c8;
        }
    }
    ctx->pc = 0x13D1ECu;
label_13d1ec:
    // 0x13d1ec: 0x24020010  addiu       $v0, $zero, 0x10
    ctx->pc = 0x13d1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x13d1f0: 0x54620007  bnel        $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x13D1F0u;
    {
        const bool branch_taken_0x13d1f0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x13d1f0) {
            ctx->pc = 0x13D1F4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1F0u;
            // 0x13d1f4: 0x31940  sll         $v1, $v1, 5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D210u;
            goto label_13d210;
        }
    }
    ctx->pc = 0x13D1F8u;
    // 0x13d1f8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13d1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13d1fc: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13D1FCu;
    SET_GPR_U32(ctx, 31, 0x13D204u);
    ctx->pc = 0x13D200u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D1FCu;
            // 0x13d200: 0x2484d3d8  addiu       $a0, $a0, -0x2C28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955992));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D204u; }
        if (ctx->pc != 0x13D204u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D204u; }
        if (ctx->pc != 0x13D204u) { return; }
    }
    ctx->pc = 0x13D204u;
label_13d204:
    // 0x13d204: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x13D204u;
    {
        const bool branch_taken_0x13d204 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D208u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D204u;
            // 0x13d208: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d204) {
            ctx->pc = 0x13D218u;
            goto label_13d218;
        }
    }
    ctx->pc = 0x13D20Cu;
    // 0x13d20c: 0x0  nop
    ctx->pc = 0x13d20cu;
    // NOP
label_13d210:
    // 0x13d210: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x13d210u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x13d214: 0x8c62003c  lw          $v0, 0x3C($v1)
    ctx->pc = 0x13d214u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 60)));
label_13d218:
    // 0x13d218: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13d218u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d21c: 0x3e00008  jr          $ra
    ctx->pc = 0x13D21Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D21Cu;
            // 0x13d220: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D1A8u: goto label_13d1a8;
            case 0x13D1B0u: goto label_13d1b0;
            case 0x13D1C8u: goto label_13d1c8;
            case 0x13D1ECu: goto label_13d1ec;
            case 0x13D204u: goto label_13d204;
            case 0x13D210u: goto label_13d210;
            case 0x13D218u: goto label_13d218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D224u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
