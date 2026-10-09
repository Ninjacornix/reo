#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BBA0
// Address: 0x15bba0 - 0x15bc88
void sub_0015BBA0_0x15bba0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BBA0_0x15bba0");
#endif

    ctx->pc = 0x15bba0u;

    // 0x15bba0: 0x8c8d0014  lw          $t5, 0x14($a0)
    ctx->pc = 0x15bba0u;
    SET_GPR_S32(ctx, 13, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x15bba4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x15bba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15bba8: 0x8c8e0000  lw          $t6, 0x0($a0)
    ctx->pc = 0x15bba8u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x15bbac: 0x240b0002  addiu       $t3, $zero, 0x2
    ctx->pc = 0x15bbacu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15bbb0: 0xd102a  slt         $v0, $zero, $t5
    ctx->pc = 0x15bbb0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 13)) ? 1 : 0);
    // 0x15bbb4: 0xa0782d  daddu       $t7, $a1, $zero
    ctx->pc = 0x15bbb4u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bbb8: 0xc0c02d  daddu       $t8, $a2, $zero
    ctx->pc = 0x15bbb8u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bbbc: 0x62680a  movz        $t5, $v1, $v0
    ctx->pc = 0x15bbbcu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 13, GPR_VEC(ctx, 3));
    // 0x15bbc0: 0xe0c82d  daddu       $t9, $a3, $zero
    ctx->pc = 0x15bbc0u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bbc4: 0x15cb000c  bne         $t6, $t3, . + 4 + (0xC << 2)
    ctx->pc = 0x15BBC4u;
    {
        const bool branch_taken_0x15bbc4 = (GPR_U64(ctx, 14) != GPR_U64(ctx, 11));
        ctx->pc = 0x15BBC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BBC4u;
            // 0x15bbc8: 0x8c8c0004  lw          $t4, 0x4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bbc4) {
            ctx->pc = 0x15BBF8u;
            goto label_15bbf8;
        }
    }
    ctx->pc = 0x15BBCCu;
    // 0x15bbcc: 0x25843fff  addiu       $a0, $t4, 0x3FFF
    ctx->pc = 0x15bbccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), 16383));
    // 0x15bbd0: 0x29830000  slti        $v1, $t4, 0x0
    ctx->pc = 0x15bbd0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 12) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15bbd4: 0x83600b  movn        $t4, $a0, $v1
    ctx->pc = 0x15bbd4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 12, GPR_VEC(ctx, 4));
    // 0x15bbd8: 0xc1383  sra         $v0, $t4, 14
    ctx->pc = 0x15bbd8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 12), 14));
    // 0x15bbdc: 0x4d1018  mult        $v0, $v0, $t5
    ctx->pc = 0x15bbdcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x15bbe0: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x15bbe0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x15bbe4: 0xade20000  sw          $v0, 0x0($t7)
    ctx->pc = 0x15bbe4u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 0), GPR_U32(ctx, 2));
    // 0x15bbe8: 0xaf000000  sw          $zero, 0x0($t8)
    ctx->pc = 0x15bbe8u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 0));
    // 0x15bbec: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x15BBECu;
    {
        const bool branch_taken_0x15bbec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BBF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BBECu;
            // 0x15bbf0: 0xaf200000  sw          $zero, 0x0($t9) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 25), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bbec) {
            ctx->pc = 0x15BC30u;
            goto label_15bc30;
        }
    }
    ctx->pc = 0x15BBF4u;
    // 0x15bbf4: 0x0  nop
    ctx->pc = 0x15bbf4u;
    // NOP
label_15bbf8:
    // 0x15bbf8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x15bbf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15bbfc: 0x15c20010  bne         $t6, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x15BBFCu;
    {
        const bool branch_taken_0x15bbfc = (GPR_U64(ctx, 14) != GPR_U64(ctx, 2));
        ctx->pc = 0x15BC00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BBFCu;
            // 0x15bc00: 0x29830000  slti        $v1, $t4, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 12) < (int64_t)(int32_t)0) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bbfc) {
            ctx->pc = 0x15BC40u;
            goto label_15bc40;
        }
    }
    ctx->pc = 0x15BC04u;
    // 0x15bc04: 0x29820000  slti        $v0, $t4, 0x0
    ctx->pc = 0x15bc04u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 12) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x15bc08: 0x25843fff  addiu       $a0, $t4, 0x3FFF
    ctx->pc = 0x15bc08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), 16383));
    // 0x15bc0c: 0x82600b  movn        $t4, $a0, $v0
    ctx->pc = 0x15bc0cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 12, GPR_VEC(ctx, 4));
    // 0x15bc10: 0xc1b83  sra         $v1, $t4, 14
    ctx->pc = 0x15bc10u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 12), 14));
    // 0x15bc14: 0x6d1018  mult        $v0, $v1, $t5
    ctx->pc = 0x15bc14u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x15bc18: 0x31a80  sll         $v1, $v1, 10
    ctx->pc = 0x15bc18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 10));
    // 0x15bc1c: 0x24630800  addiu       $v1, $v1, 0x800
    ctx->pc = 0x15bc1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2048));
    // 0x15bc20: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x15bc20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x15bc24: 0xade20000  sw          $v0, 0x0($t7)
    ctx->pc = 0x15bc24u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 0), GPR_U32(ctx, 2));
    // 0x15bc28: 0xaf000000  sw          $zero, 0x0($t8)
    ctx->pc = 0x15bc28u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 0));
    // 0x15bc2c: 0xaf230000  sw          $v1, 0x0($t9)
    ctx->pc = 0x15bc2cu;
    WRITE32(ADD32(GPR_U32(ctx, 25), 0), GPR_U32(ctx, 3));
label_15bc30:
    // 0x15bc30: 0xad000000  sw          $zero, 0x0($t0)
    ctx->pc = 0x15bc30u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 0));
    // 0x15bc34: 0xad200000  sw          $zero, 0x0($t1)
    ctx->pc = 0x15bc34u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 0));
    // 0x15bc38: 0x3e00008  jr          $ra
    ctx->pc = 0x15BC38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BC3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BC38u;
            // 0x15bc3c: 0xad400000  sw          $zero, 0x0($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BBF8u: goto label_15bbf8;
            case 0x15BC30u: goto label_15bc30;
            case 0x15BC40u: goto label_15bc40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BC40u;
label_15bc40:
    // 0x15bc40: 0x25843fff  addiu       $a0, $t4, 0x3FFF
    ctx->pc = 0x15bc40u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), 16383));
    // 0x15bc44: 0x83600b  movn        $t4, $a0, $v1
    ctx->pc = 0x15bc44u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 12, GPR_VEC(ctx, 4));
    // 0x15bc48: 0x24055dcc  addiu       $a1, $zero, 0x5DCC
    ctx->pc = 0x15bc48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 24012));
    // 0x15bc4c: 0xc1383  sra         $v0, $t4, 14
    ctx->pc = 0x15bc4cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 12), 14));
    // 0x15bc50: 0x24065f0c  addiu       $a2, $zero, 0x5F0C
    ctx->pc = 0x15bc50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 24332));
    // 0x15bc54: 0x4d1818  mult        $v1, $v0, $t5
    ctx->pc = 0x15bc54u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x15bc58: 0x21280  sll         $v0, $v0, 10
    ctx->pc = 0x15bc58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 10));
    // 0x15bc5c: 0x340781c0  ori         $a3, $zero, 0x81C0
    ctx->pc = 0x15bc5cu;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33216);
    // 0x15bc60: 0x24420800  addiu       $v0, $v0, 0x800
    ctx->pc = 0x15bc60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2048));
    // 0x15bc64: 0x31ac0  sll         $v1, $v1, 11
    ctx->pc = 0x15bc64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x15bc68: 0xade30000  sw          $v1, 0x0($t7)
    ctx->pc = 0x15bc68u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 0), GPR_U32(ctx, 3));
    // 0x15bc6c: 0xaf000000  sw          $zero, 0x0($t8)
    ctx->pc = 0x15bc6cu;
    WRITE32(ADD32(GPR_U32(ctx, 24), 0), GPR_U32(ctx, 0));
    // 0x15bc70: 0xaf220000  sw          $v0, 0x0($t9)
    ctx->pc = 0x15bc70u;
    WRITE32(ADD32(GPR_U32(ctx, 25), 0), GPR_U32(ctx, 2));
    // 0x15bc74: 0xad050000  sw          $a1, 0x0($t0)
    ctx->pc = 0x15bc74u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 5));
    // 0x15bc78: 0xad260000  sw          $a2, 0x0($t1)
    ctx->pc = 0x15bc78u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 0), GPR_U32(ctx, 6));
    // 0x15bc7c: 0x3e00008  jr          $ra
    ctx->pc = 0x15BC7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BC80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BC7Cu;
            // 0x15bc80: 0xad470000  sw          $a3, 0x0($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BBF8u: goto label_15bbf8;
            case 0x15BC30u: goto label_15bc30;
            case 0x15BC40u: goto label_15bc40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BC84u;
    // 0x15bc84: 0x0  nop
    ctx->pc = 0x15bc84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
