#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DBB0
// Address: 0x18dbb0 - 0x18dc00
void sub_0018DBB0_0x18dbb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DBB0_0x18dbb0");
#endif

    switch (ctx->pc) {
        case 0x18dbb8u: goto label_18dbb8;
        default: break;
    }

    ctx->pc = 0x18dbb0u;

    // 0x18dbb0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x18DBB0u;
    {
        const bool branch_taken_0x18dbb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18DBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DBB0u;
            // 0x18dbb4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18dbb0) {
            ctx->pc = 0x18DBCCu;
            goto label_18dbcc;
        }
    }
    ctx->pc = 0x18DBB8u;
label_18dbb8:
    // 0x18dbb8: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x18dbb8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x18dbbc: 0x24650001  addiu       $a1, $v1, 0x1
    ctx->pc = 0x18dbbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x18dbc0: 0x80630000  lb          $v1, 0x0($v1)
    ctx->pc = 0x18dbc0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18dbc4: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x18dbc4u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x18dbc8: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x18dbc8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
label_18dbcc:
    // 0x18dbcc: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x18dbccu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x18dbd0: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x18DBD0u;
    {
        const bool branch_taken_0x18dbd0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x18DBD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DBD0u;
            // 0x18dbd4: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18dbd0) {
            ctx->pc = 0x18DBB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18dbb8;
        }
    }
    ctx->pc = 0x18DBD8u;
    // 0x18dbd8: 0x3e00008  jr          $ra
    ctx->pc = 0x18DBD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DBB8u: goto label_18dbb8;
            case 0x18DBCCu: goto label_18dbcc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DBE0u;
    // 0x18dbe0: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x18dbe0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dbe4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x18dbe4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dbe8: 0x3c04002a  lui         $a0, 0x2A
    ctx->pc = 0x18dbe8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)42 << 16));
    // 0x18dbec: 0x806267c  j           func_1899F0
    ctx->pc = 0x18DBECu;
    ctx->pc = 0x18DBF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DBECu;
            // 0x18dbf0: 0x2484fe50  addiu       $a0, $a0, -0x1B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966864));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1899F0u;
    if (runtime->hasFunction(0x1899F0u)) {
        auto targetFn = runtime->lookupFunction(0x1899F0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001899F0_0x1899f0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x18DBF4u;
    // 0x18dbf4: 0x0  nop
    ctx->pc = 0x18dbf4u;
    // NOP
    // 0x18dbf8: 0x0  nop
    ctx->pc = 0x18dbf8u;
    // NOP
    // 0x18dbfc: 0x0  nop
    ctx->pc = 0x18dbfcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
