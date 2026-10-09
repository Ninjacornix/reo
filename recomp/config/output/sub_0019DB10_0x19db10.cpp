#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019DB10
// Address: 0x19db10 - 0x19dbb0
void sub_0019DB10_0x19db10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019DB10_0x19db10");
#endif

    switch (ctx->pc) {
        case 0x19db30u: goto label_19db30;
        default: break;
    }

    ctx->pc = 0x19db10u;

    // 0x19db10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x19db10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19db14: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x19db14u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19db18: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x19db18u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19db1c: 0x24090002  addiu       $t1, $zero, 0x2
    ctx->pc = 0x19db1cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x19db20: 0x240a000a  addiu       $t2, $zero, 0xA
    ctx->pc = 0x19db20u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x19db24: 0x240b0013  addiu       $t3, $zero, 0x13
    ctx->pc = 0x19db24u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 19));
    // 0x19db28: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x19DB28u;
    {
        const bool branch_taken_0x19db28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DB2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB28u;
            // 0x19db2c: 0x240c0014  addiu       $t4, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db28) {
            ctx->pc = 0x19DB9Cu;
            goto label_19db9c;
        }
    }
    ctx->pc = 0x19DB30u;
label_19db30:
    // 0x19db30: 0x108c0015  beq         $a0, $t4, . + 4 + (0x15 << 2)
    ctx->pc = 0x19DB30u;
    {
        const bool branch_taken_0x19db30 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 12));
        ctx->pc = 0x19DB34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB30u;
            // 0x19db34: 0xa61818  mult        $v1, $a1, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db30) {
            ctx->pc = 0x19DB88u;
            goto label_19db88;
        }
    }
    ctx->pc = 0x19DB38u;
    // 0x19db38: 0x108b0011  beq         $a0, $t3, . + 4 + (0x11 << 2)
    ctx->pc = 0x19DB38u;
    {
        const bool branch_taken_0x19db38 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 11));
        ctx->pc = 0x19DB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB38u;
            // 0x19db3c: 0xa61818  mult        $v1, $a1, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db38) {
            ctx->pc = 0x19DB80u;
            goto label_19db80;
        }
    }
    ctx->pc = 0x19DB40u;
    // 0x19db40: 0x108a000c  beq         $a0, $t2, . + 4 + (0xC << 2)
    ctx->pc = 0x19DB40u;
    {
        const bool branch_taken_0x19db40 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 10));
        ctx->pc = 0x19DB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB40u;
            // 0x19db44: 0xa61818  mult        $v1, $a1, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db40) {
            ctx->pc = 0x19DB74u;
            goto label_19db74;
        }
    }
    ctx->pc = 0x19DB48u;
    // 0x19db48: 0x1089000a  beq         $a0, $t1, . + 4 + (0xA << 2)
    ctx->pc = 0x19DB48u;
    {
        const bool branch_taken_0x19db48 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 9));
        if (branch_taken_0x19db48) {
            ctx->pc = 0x19DB74u;
            goto label_19db74;
        }
    }
    ctx->pc = 0x19DB50u;
    // 0x19db50: 0x10880005  beq         $a0, $t0, . + 4 + (0x5 << 2)
    ctx->pc = 0x19DB50u;
    {
        const bool branch_taken_0x19db50 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 8));
        ctx->pc = 0x19DB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB50u;
            // 0x19db54: 0xa61818  mult        $v1, $a1, $a2 (Delay Slot)
        { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 6); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db50) {
            ctx->pc = 0x19DB68u;
            goto label_19db68;
        }
    }
    ctx->pc = 0x19DB58u;
    // 0x19db58: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19DB58u;
    {
        const bool branch_taken_0x19db58 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x19db58) {
            ctx->pc = 0x19DB68u;
            goto label_19db68;
        }
    }
    ctx->pc = 0x19DB60u;
    // 0x19db60: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x19DB60u;
    {
        const bool branch_taken_0x19db60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB60u;
            // 0x19db64: 0x52843  sra         $a1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db60) {
            ctx->pc = 0x19DB94u;
            goto label_19db94;
        }
    }
    ctx->pc = 0x19DB68u;
label_19db68:
    // 0x19db68: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x19db68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x19db6c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x19DB6Cu;
    {
        const bool branch_taken_0x19db6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DB70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB6Cu;
            // 0x19db70: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db6c) {
            ctx->pc = 0x19DB90u;
            goto label_19db90;
        }
    }
    ctx->pc = 0x19DB74u;
label_19db74:
    // 0x19db74: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x19db74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x19db78: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x19DB78u;
    {
        const bool branch_taken_0x19db78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DB7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB78u;
            // 0x19db7c: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db78) {
            ctx->pc = 0x19DB90u;
            goto label_19db90;
        }
    }
    ctx->pc = 0x19DB80u;
label_19db80:
    // 0x19db80: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x19DB80u;
    {
        const bool branch_taken_0x19db80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19DB84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19DB80u;
            // 0x19db84: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19db80) {
            ctx->pc = 0x19DB90u;
            goto label_19db90;
        }
    }
    ctx->pc = 0x19DB88u;
label_19db88:
    // 0x19db88: 0x31843  sra         $v1, $v1, 1
    ctx->pc = 0x19db88u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
    // 0x19db8c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x19db8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_19db90:
    // 0x19db90: 0x52843  sra         $a1, $a1, 1
    ctx->pc = 0x19db90u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 1));
label_19db94:
    // 0x19db94: 0x63043  sra         $a2, $a2, 1
    ctx->pc = 0x19db94u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 1));
    // 0x19db98: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x19db98u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
label_19db9c:
    // 0x19db9c: 0x1a7182a  slt         $v1, $t5, $a3
    ctx->pc = 0x19db9cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x19dba0: 0x1460ffe3  bnez        $v1, . + 4 + (-0x1D << 2)
    ctx->pc = 0x19DBA0u;
    {
        const bool branch_taken_0x19dba0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x19dba0) {
            ctx->pc = 0x19DB30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19db30;
        }
    }
    ctx->pc = 0x19DBA8u;
    // 0x19dba8: 0x3e00008  jr          $ra
    ctx->pc = 0x19DBA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19DB30u: goto label_19db30;
            case 0x19DB68u: goto label_19db68;
            case 0x19DB74u: goto label_19db74;
            case 0x19DB80u: goto label_19db80;
            case 0x19DB88u: goto label_19db88;
            case 0x19DB90u: goto label_19db90;
            case 0x19DB94u: goto label_19db94;
            case 0x19DB9Cu: goto label_19db9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19DBB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
