#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010EA10
// Address: 0x10ea10 - 0x10eaf0
void sub_0010EA10_0x10ea10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010EA10_0x10ea10");
#endif

    switch (ctx->pc) {
        case 0x10ea58u: goto label_10ea58;
        case 0x10eaa0u: goto label_10eaa0;
        default: break;
    }

    ctx->pc = 0x10ea10u;

    // 0x10ea10: 0xa0860000  sb          $a2, 0x0($a0)
    ctx->pc = 0x10ea10u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x10ea14: 0x24860001  addiu       $a2, $a0, 0x1
    ctx->pc = 0x10ea14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10ea18: 0x4a10005  bgez        $a1, . + 4 + (0x5 << 2)
    ctx->pc = 0x10EA18u;
    {
        const bool branch_taken_0x10ea18 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x10EA1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA18u;
            // 0x10ea1c: 0x27bdfec0  addiu       $sp, $sp, -0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966976));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ea18) {
            ctx->pc = 0x10EA30u;
            goto label_10ea30;
        }
    }
    ctx->pc = 0x10EA20u;
    // 0x10ea20: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10ea20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10ea24: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10EA24u;
    {
        const bool branch_taken_0x10ea24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EA28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA24u;
            // 0x10ea28: 0x52823  negu        $a1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ea24) {
            ctx->pc = 0x10EA34u;
            goto label_10ea34;
        }
    }
    ctx->pc = 0x10EA2Cu;
    // 0x10ea2c: 0x0  nop
    ctx->pc = 0x10ea2cu;
    // NOP
label_10ea30:
    // 0x10ea30: 0x2402002b  addiu       $v0, $zero, 0x2B
    ctx->pc = 0x10ea30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
label_10ea34:
    // 0x10ea34: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x10ea34u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10ea38: 0x24860002  addiu       $a2, $a0, 0x2
    ctx->pc = 0x10ea38u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x10ea3c: 0x27a70134  addiu       $a3, $sp, 0x134
    ctx->pc = 0x10ea3cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 308));
    // 0x10ea40: 0x28a2000a  slti        $v0, $a1, 0xA
    ctx->pc = 0x10ea40u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x10ea44: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x10EA44u;
    {
        const bool branch_taken_0x10ea44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EA48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA44u;
            // 0x10ea48: 0xe0482d  daddu       $t1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ea44) {
            ctx->pc = 0x10EAC8u;
            goto label_10eac8;
        }
    }
    ctx->pc = 0x10EA4Cu;
    // 0x10ea4c: 0x2408000a  addiu       $t0, $zero, 0xA
    ctx->pc = 0x10ea4cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x10ea50: 0xa8001a  div         $zero, $a1, $t0
    ctx->pc = 0x10ea50u;
    { int32_t divisor = GPR_S32(ctx, 8);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x10ea54: 0x0  nop
    ctx->pc = 0x10ea54u;
    // NOP
label_10ea58:
    // 0x10ea58: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10ea58u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10ea5c: 0x51000001  beql        $t0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x10EA5Cu;
    {
        const bool branch_taken_0x10ea5c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ea5c) {
            ctx->pc = 0x10EA60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA5Cu;
            // 0x10ea60: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EA64u;
            goto label_10ea64;
        }
    }
    ctx->pc = 0x10EA64u;
label_10ea64:
    // 0x10ea64: 0x1812  mflo        $v1
    ctx->pc = 0x10ea64u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x10ea68: 0x1010  mfhi        $v0
    ctx->pc = 0x10ea68u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x10ea6c: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x10ea6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ea70: 0x24420030  addiu       $v0, $v0, 0x30
    ctx->pc = 0x10ea70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 48));
    // 0x10ea74: 0x28a3000a  slti        $v1, $a1, 0xA
    ctx->pc = 0x10ea74u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x10ea78: 0xa0e20000  sb          $v0, 0x0($a3)
    ctx->pc = 0x10ea78u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10ea7c: 0x5060fff6  beql        $v1, $zero, . + 4 + (-0xA << 2)
    ctx->pc = 0x10EA7Cu;
    {
        const bool branch_taken_0x10ea7c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ea7c) {
            ctx->pc = 0x10EA80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA7Cu;
            // 0x10ea80: 0xa8001a  div         $zero, $a1, $t0 (Delay Slot)
        { int32_t divisor = GPR_S32(ctx, 8);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
        ctx->in_delay_slot = false;
            ctx->pc = 0x10EA58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ea58;
        }
    }
    ctx->pc = 0x10EA84u;
    // 0x10ea84: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x10ea84u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x10ea88: 0x24a20030  addiu       $v0, $a1, 0x30
    ctx->pc = 0x10ea88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x10ea8c: 0xe9182b  sltu        $v1, $a3, $t1
    ctx->pc = 0x10ea8cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x10ea90: 0x10600013  beqz        $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x10EA90u;
    {
        const bool branch_taken_0x10ea90 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EA94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EA90u;
            // 0x10ea94: 0xa0e20000  sb          $v0, 0x0($a3) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 7), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ea90) {
            ctx->pc = 0x10EAE0u;
            goto label_10eae0;
        }
    }
    ctx->pc = 0x10EA98u;
    // 0x10ea98: 0x120282d  daddu       $a1, $t1, $zero
    ctx->pc = 0x10ea98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ea9c: 0x0  nop
    ctx->pc = 0x10ea9cu;
    // NOP
label_10eaa0:
    // 0x10eaa0: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x10eaa0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10eaa4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x10eaa4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x10eaa8: 0xe5182b  sltu        $v1, $a3, $a1
    ctx->pc = 0x10eaa8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x10eaac: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x10eaacu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10eab0: 0x0  nop
    ctx->pc = 0x10eab0u;
    // NOP
    // 0x10eab4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10EAB4u;
    {
        const bool branch_taken_0x10eab4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10EAB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EAB4u;
            // 0x10eab8: 0x24c60001  addiu       $a2, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eab4) {
            ctx->pc = 0x10EAA0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10eaa0;
        }
    }
    ctx->pc = 0x10EABCu;
    // 0x10eabc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x10EABCu;
    {
        const bool branch_taken_0x10eabc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10EAC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EABCu;
            // 0x10eac0: 0xc41023  subu        $v0, $a2, $a0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10eabc) {
            ctx->pc = 0x10EAE4u;
            goto label_10eae4;
        }
    }
    ctx->pc = 0x10EAC4u;
    // 0x10eac4: 0x0  nop
    ctx->pc = 0x10eac4u;
    // NOP
label_10eac8:
    // 0x10eac8: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x10eac8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10eacc: 0x24a30030  addiu       $v1, $a1, 0x30
    ctx->pc = 0x10eaccu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), 48));
    // 0x10ead0: 0xa0c20000  sb          $v0, 0x0($a2)
    ctx->pc = 0x10ead0u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x10ead4: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10ead4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x10ead8: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x10ead8u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x10eadc: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x10eadcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
label_10eae0:
    // 0x10eae0: 0xc41023  subu        $v0, $a2, $a0
    ctx->pc = 0x10eae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
label_10eae4:
    // 0x10eae4: 0x3e00008  jr          $ra
    ctx->pc = 0x10EAE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10EAE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10EAE4u;
            // 0x10eae8: 0x27bd0140  addiu       $sp, $sp, 0x140 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 320));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10EA30u: goto label_10ea30;
            case 0x10EA34u: goto label_10ea34;
            case 0x10EA58u: goto label_10ea58;
            case 0x10EA64u: goto label_10ea64;
            case 0x10EAA0u: goto label_10eaa0;
            case 0x10EAC8u: goto label_10eac8;
            case 0x10EAE0u: goto label_10eae0;
            case 0x10EAE4u: goto label_10eae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10EAECu;
    // 0x10eaec: 0x0  nop
    ctx->pc = 0x10eaecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
