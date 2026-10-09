#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166BE0
// Address: 0x166be0 - 0x166c68
void sub_00166BE0_0x166be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166BE0_0x166be0");
#endif

    ctx->pc = 0x166be0u;

    // 0x166be0: 0x510c0  sll         $v0, $a1, 3
    ctx->pc = 0x166be0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x166be4: 0xc0582d  daddu       $t3, $a2, $zero
    ctx->pc = 0x166be4u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166be8: 0x451023  subu        $v0, $v0, $a1
    ctx->pc = 0x166be8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x166bec: 0x25630007  addiu       $v1, $t3, 0x7
    ctx->pc = 0x166becu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 11), 7));
    // 0x166bf0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166bf0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166bf4: 0xe0502d  daddu       $t2, $a3, $zero
    ctx->pc = 0x166bf4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166bf8: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x166bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x166bfc: 0x28660000  slti        $a2, $v1, 0x0
    ctx->pc = 0x166bfcu;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x166c00: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166c00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166c04: 0x2567000e  addiu       $a3, $t3, 0xE
    ctx->pc = 0x166c04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 11), 14));
    // 0x166c08: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x166c08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x166c0c: 0xe6180b  movn        $v1, $a3, $a2
    ctx->pc = 0x166c0cu;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x166c10: 0x24841150  addiu       $a0, $a0, 0x1150
    ctx->pc = 0x166c10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4432));
    // 0x166c14: 0x29490002  slti        $t1, $t2, 0x2
    ctx->pc = 0x166c14u;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 10) < (int64_t)(int32_t)2) ? 1 : 0);
    // 0x166c18: 0x328c3  sra         $a1, $v1, 3
    ctx->pc = 0x166c18u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 3));
    // 0x166c1c: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x166c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x166c20: 0x15200005  bnez        $t1, . + 4 + (0x5 << 2)
    ctx->pc = 0x166C20u;
    {
        const bool branch_taken_0x166c20 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x166C24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166C20u;
            // 0x166c24: 0x8c860000  lw          $a2, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166c20) {
            ctx->pc = 0x166C38u;
            goto label_166c38;
        }
    }
    ctx->pc = 0x166C28u;
    // 0x166c28: 0x4a001a  div         $zero, $v0, $t2
    ctx->pc = 0x166c28u;
    { int32_t divisor = GPR_S32(ctx, 10);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x166c2c: 0x51400001  beql        $t2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x166C2Cu;
    {
        const bool branch_taken_0x166c2c = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        if (branch_taken_0x166c2c) {
            ctx->pc = 0x166C30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x166C2Cu;
            // 0x166c30: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x166C34u;
            goto label_166c34;
        }
    }
    ctx->pc = 0x166C34u;
label_166c34:
    // 0x166c34: 0x1012  mflo        $v0
    ctx->pc = 0x166c34u;
    SET_GPR_U64(ctx, 2, ctx->lo);
label_166c38:
    // 0x166c38: 0x45001a  div         $zero, $v0, $a1
    ctx->pc = 0x166c38u;
    { int32_t divisor = GPR_S32(ctx, 5);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x166c3c: 0xc21021  addu        $v0, $a2, $v0
    ctx->pc = 0x166c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x166c40: 0xac8b000c  sw          $t3, 0xC($a0)
    ctx->pc = 0x166c40u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 11));
    // 0x166c44: 0xac8a0010  sw          $t2, 0x10($a0)
    ctx->pc = 0x166c44u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 10));
    // 0x166c48: 0xac880008  sw          $t0, 0x8($a0)
    ctx->pc = 0x166c48u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x166c4c: 0xac860014  sw          $a2, 0x14($a0)
    ctx->pc = 0x166c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 6));
    // 0x166c50: 0xac820018  sw          $v0, 0x18($a0)
    ctx->pc = 0x166c50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 2));
    // 0x166c54: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x166C54u;
    {
        const bool branch_taken_0x166c54 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x166c54) {
            ctx->pc = 0x166C58u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x166C54u;
            // 0x166c58: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x166C5Cu;
            goto label_166c5c;
        }
    }
    ctx->pc = 0x166C5Cu;
label_166c5c:
    // 0x166c5c: 0x1812  mflo        $v1
    ctx->pc = 0x166c5cu;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x166c60: 0x3e00008  jr          $ra
    ctx->pc = 0x166C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166C60u;
            // 0x166c64: 0xac83001c  sw          $v1, 0x1C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166C34u: goto label_166c34;
            case 0x166C38u: goto label_166c38;
            case 0x166C5Cu: goto label_166c5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166C68u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
