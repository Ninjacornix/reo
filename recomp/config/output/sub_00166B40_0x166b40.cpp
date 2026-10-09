#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166B40
// Address: 0x166b40 - 0x166c68
void sub_00166B40_0x166b40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166B40_0x166b40");
#endif

    switch (ctx->pc) {
        case 0x166b90u: goto label_166b90;
        default: break;
    }

    ctx->pc = 0x166b40u;

    // 0x166b40: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x166b40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x166b44: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166b44u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x166b48: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x166b48u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x166b4c: 0x71880  sll         $v1, $a3, 2
    ctx->pc = 0x166b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x166b50: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166b54: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166b54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166b58: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166b58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166b5c: 0xa38821  addu        $s1, $a1, $v1
    ctx->pc = 0x166b5cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x166b60: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x166b60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x166b64: 0xc39021  addu        $s2, $a2, $v1
    ctx->pc = 0x166b64u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x166b68: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x166b68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x166b6c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x166b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x166b70: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166b70u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166b74: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x166b74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x166b78: 0x8e460000  lw          $a2, 0x0($s2)
    ctx->pc = 0x166b78u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x166b7c: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x166b7cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x166b80: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166b80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166b84: 0x26100010  addiu       $s0, $s0, 0x10
    ctx->pc = 0x166b84u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x166b88: 0xc059b2e  jal         func_166CB8
    ctx->pc = 0x166B88u;
    SET_GPR_U32(ctx, 31, 0x166B90u);
    ctx->pc = 0x166B8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166B88u;
            // 0x166b8c: 0x6302b  sltu        $a2, $zero, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x166CB8u;
    if (runtime->hasFunction(0x166CB8u)) {
        auto targetFn = runtime->lookupFunction(0x166CB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166B90u; }
        if (ctx->pc != 0x166B90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166CB8_0x166cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166B90u; }
        if (ctx->pc != 0x166B90u) { return; }
    }
    ctx->pc = 0x166B90u;
label_166b90:
    // 0x166b90: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x166b90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x166b94: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x166b94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x166b98: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x166b98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x166b9c: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x166b9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x166ba0: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x166ba0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x166ba4: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x166ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x166ba8: 0xae00000c  sw          $zero, 0xC($s0)
    ctx->pc = 0x166ba8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x166bac: 0xae000010  sw          $zero, 0x10($s0)
    ctx->pc = 0x166bacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 0));
    // 0x166bb0: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x166bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x166bb4: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x166bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x166bb8: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x166bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x166bbc: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x166bbcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x166bc0: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x166bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x166bc4: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x166bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x166bc8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166bc8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166bcc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166bccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166bd0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x166bd0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166bd4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x166bd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x166bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x166BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166BD8u;
            // 0x166bdc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166B90u: goto label_166b90;
            case 0x166C34u: goto label_166c34;
            case 0x166C38u: goto label_166c38;
            case 0x166C5Cu: goto label_166c5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166BE0u;
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
            case 0x166B90u: goto label_166b90;
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
