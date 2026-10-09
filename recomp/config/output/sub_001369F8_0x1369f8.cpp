#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001369F8
// Address: 0x1369f8 - 0x136a7c
void sub_001369F8_0x1369f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001369F8_0x1369f8");
#endif

    switch (ctx->pc) {
        case 0x136a10u: goto label_136a10;
        case 0x136a40u: goto label_136a40;
        default: break;
    }

    ctx->pc = 0x1369f8u;

    // 0x1369f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1369f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1369fc: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1369FCu;
    {
        const bool branch_taken_0x1369fc = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x136A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1369FCu;
            // 0x136a00: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1369fc) {
            ctx->pc = 0x136A18u;
            goto label_136a18;
        }
    }
    ctx->pc = 0x136A04u;
    // 0x136a04: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x136a04u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x136a08: 0xc04d480  jal         func_135200
    ctx->pc = 0x136A08u;
    SET_GPR_U32(ctx, 31, 0x136A10u);
    ctx->pc = 0x136A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x136A08u;
            // 0x136a0c: 0x2484c0a0  addiu       $a0, $a0, -0x3F60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294951072));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136A10u; }
        if (ctx->pc != 0x136A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136A10u; }
        if (ctx->pc != 0x136A10u) { return; }
    }
    ctx->pc = 0x136A10u;
label_136a10:
    // 0x136a10: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x136A10u;
    {
        const bool branch_taken_0x136a10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x136A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A10u;
            // 0x136a14: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a10) {
            ctx->pc = 0x136A70u;
            goto label_136a70;
        }
    }
    ctx->pc = 0x136A18u;
label_136a18:
    // 0x136a18: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x136a18u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x136a1c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x136a1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x136a20: 0x24432068  addiu       $v1, $v0, 0x2068
    ctx->pc = 0x136a20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 8296));
    // 0x136a24: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x136a24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136a28: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x136a28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x136a2c: 0x1044000d  beq         $v0, $a0, . + 4 + (0xD << 2)
    ctx->pc = 0x136A2Cu;
    {
        const bool branch_taken_0x136a2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x136A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A2Cu;
            // 0x136a30: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a2c) {
            ctx->pc = 0x136A64u;
            goto label_136a64;
        }
    }
    ctx->pc = 0x136A34u;
    // 0x136a34: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x136a34u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x136a38: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x136a38u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x136a3c: 0x0  nop
    ctx->pc = 0x136a3cu;
    // NOP
label_136a40:
    // 0x136a40: 0x62900  sll         $a1, $a2, 4
    ctx->pc = 0x136a40u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 4));
    // 0x136a44: 0x28c20020  slti        $v0, $a2, 0x20
    ctx->pc = 0x136a44u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x136a48: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x136A48u;
    {
        const bool branch_taken_0x136a48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x136A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A48u;
            // 0x136a4c: 0xa71821  addu        $v1, $a1, $a3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x136a48) {
            ctx->pc = 0x136A64u;
            goto label_136a64;
        }
    }
    ctx->pc = 0x136A50u;
    // 0x136a50: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x136a50u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x136a54: 0x0  nop
    ctx->pc = 0x136a54u;
    // NOP
    // 0x136a58: 0x0  nop
    ctx->pc = 0x136a58u;
    // NOP
    // 0x136a5c: 0x5444fff8  bnel        $v0, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x136A5Cu;
    {
        const bool branch_taken_0x136a5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        if (branch_taken_0x136a5c) {
            ctx->pc = 0x136A60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x136A5Cu;
            // 0x136a60: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x136A40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_136a40;
        }
    }
    ctx->pc = 0x136A64u;
label_136a64:
    // 0x136a64: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x136a64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x136a68: 0x2442206c  addiu       $v0, $v0, 0x206C
    ctx->pc = 0x136a68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8300));
    // 0x136a6c: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x136a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_136a70:
    // 0x136a70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x136a70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x136a74: 0x3e00008  jr          $ra
    ctx->pc = 0x136A74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x136A74u;
            // 0x136a78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A10u: goto label_136a10;
            case 0x136A18u: goto label_136a18;
            case 0x136A40u: goto label_136a40;
            case 0x136A64u: goto label_136a64;
            case 0x136A70u: goto label_136a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136A7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
