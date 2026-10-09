#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015C9A8
// Address: 0x15c9a8 - 0x15ca20
void sub_0015C9A8_0x15c9a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015C9A8_0x15c9a8");
#endif

    ctx->pc = 0x15c9a8u;

    // 0x15c9a8: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x15c9a8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15c9ac: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15c9acu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15c9b0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15c9b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15c9b4: 0x250300c8  addiu       $v1, $t0, 0xC8
    ctx->pc = 0x15c9b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 200));
    // 0x15c9b8: 0x14a00007  bnez        $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15C9B8u;
    {
        const bool branch_taken_0x15c9b8 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x15C9BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9B8u;
            // 0x15c9bc: 0x250200bc  addiu       $v0, $t0, 0xBC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 188));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c9b8) {
            ctx->pc = 0x15C9D8u;
            goto label_15c9d8;
        }
    }
    ctx->pc = 0x15C9C0u;
    // 0x15c9c0: 0xac600008  sw          $zero, 0x8($v1)
    ctx->pc = 0x15c9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 0));
    // 0x15c9c4: 0xad0200d4  sw          $v0, 0xD4($t0)
    ctx->pc = 0x15c9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 212), GPR_U32(ctx, 2));
    // 0x15c9c8: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x15c9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x15c9cc: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x15C9CCu;
    {
        const bool branch_taken_0x15c9cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15C9D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9CCu;
            // 0x15c9d0: 0xac600004  sw          $zero, 0x4($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15c9cc) {
            ctx->pc = 0x15CA14u;
            goto label_15ca14;
        }
    }
    ctx->pc = 0x15C9D4u;
    // 0x15c9d4: 0x0  nop
    ctx->pc = 0x15c9d4u;
    // NOP
label_15c9d8:
    // 0x15c9d8: 0x8d02001c  lw          $v0, 0x1C($t0)
    ctx->pc = 0x15c9d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 8), 28)));
    // 0x15c9dc: 0x24420004  addiu       $v0, $v0, 0x4
    ctx->pc = 0x15c9dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x15c9e0: 0x471018  mult        $v0, $v0, $a3
    ctx->pc = 0x15c9e0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 7); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x15c9e4: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x15c9e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x15c9e8: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x15C9E8u;
    {
        const bool branch_taken_0x15c9e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15c9e8) {
            ctx->pc = 0x15C9ECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9E8u;
            // 0x15c9ec: 0xac650000  sw          $a1, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15CA08u;
            goto label_15ca08;
        }
    }
    ctx->pc = 0x15C9F0u;
    // 0x15c9f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15c9f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15c9f4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15c9f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15c9f8: 0x2484e888  addiu       $a0, $a0, -0x1778
    ctx->pc = 0x15c9f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294961288));
    // 0x15c9fc: 0x8058dd4  j           func_163750
    ctx->pc = 0x15C9FCu;
    ctx->pc = 0x15CA00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15C9FCu;
            // 0x15ca00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15CA04u;
    // 0x15ca04: 0x0  nop
    ctx->pc = 0x15ca04u;
    // NOP
label_15ca08:
    // 0x15ca08: 0xac660004  sw          $a2, 0x4($v1)
    ctx->pc = 0x15ca08u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 6));
    // 0x15ca0c: 0xac670008  sw          $a3, 0x8($v1)
    ctx->pc = 0x15ca0cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 7));
    // 0x15ca10: 0xad0300d4  sw          $v1, 0xD4($t0)
    ctx->pc = 0x15ca10u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 212), GPR_U32(ctx, 3));
label_15ca14:
    // 0x15ca14: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ca14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ca18: 0x8057230  j           func_15C8C0
    ctx->pc = 0x15CA18u;
    ctx->pc = 0x15CA1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15CA18u;
            // 0x15ca1c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15C8C0u;
    if (runtime->hasFunction(0x15C8C0u)) {
        auto targetFn = runtime->lookupFunction(0x15C8C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015C8C0_0x15c8c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15CA20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
