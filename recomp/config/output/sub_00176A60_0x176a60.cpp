#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176A60
// Address: 0x176a60 - 0x176d08
void sub_00176A60_0x176a60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176A60_0x176a60");
#endif

    switch (ctx->pc) {
        case 0x176af0u: goto label_176af0;
        case 0x176b28u: goto label_176b28;
        case 0x176b60u: goto label_176b60;
        default: break;
    }

    ctx->pc = 0x176a60u;

label_176a60:
    // 0x176a60: 0x8caa0008  lw          $t2, 0x8($a1)
    ctx->pc = 0x176a60u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176a64: 0x8cab000c  lw          $t3, 0xC($a1)
    ctx->pc = 0x176a64u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176a68: 0x1445018  mult        $t2, $t2, $a0
    ctx->pc = 0x176a68u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176a6c: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x176a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176a70: 0x8ca90014  lw          $t1, 0x14($a1)
    ctx->pc = 0x176a70u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176a74: 0x1645818  mult        $t3, $t3, $a0
    ctx->pc = 0x176a74u;
    { int64_t result = (int64_t)GPR_S32(ctx, 11) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 11, (int32_t)result); }
    // 0x176a78: 0x8ca80010  lw          $t0, 0x10($a1)
    ctx->pc = 0x176a78u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176a7c: 0x1224821  addu        $t1, $t1, $v0
    ctx->pc = 0x176a7cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x176a80: 0x91940  sll         $v1, $t1, 5
    ctx->pc = 0x176a80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 5));
    // 0x176a84: 0xa10c0  sll         $v0, $t2, 3
    ctx->pc = 0x176a84u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x176a88: 0x1044018  mult        $t0, $t0, $a0
    ctx->pc = 0x176a88u;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 8, (int32_t)result); }
    // 0x176a8c: 0x691823  subu        $v1, $v1, $t1
    ctx->pc = 0x176a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x176a90: 0x4a1023  subu        $v0, $v0, $t2
    ctx->pc = 0x176a90u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x176a94: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x176a94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x176a98: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x176a98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x176a9c: 0xb2900  sll         $a1, $t3, 4
    ctx->pc = 0x176a9cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 11), 4));
    // 0x176aa0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x176aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x176aa4: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x176aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x176aa8: 0xab2823  subu        $a1, $a1, $t3
    ctx->pc = 0x176aa8u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 11)));
    // 0x176aac: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x176aacu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x176ab0: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x176ab0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x176ab4: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x176ab4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x176ab8: 0x1034021  addu        $t0, $t0, $v1
    ctx->pc = 0x176ab8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x176abc: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x176abcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x176ac0: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x176ac0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x176ac4: 0xacc80000  sw          $t0, 0x0($a2)
    ctx->pc = 0x176ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 8));
    // 0x176ac8: 0x3e00008  jr          $ra
    ctx->pc = 0x176AC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176ACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176AC8u;
            // 0x176acc: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176AD0u;
    // 0x176ad0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176ad0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176ad4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176ad8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176ad8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176adc: 0x24045dc0  addiu       $a0, $zero, 0x5DC0
    ctx->pc = 0x176adcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24000));
    // 0x176ae0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176ae0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176ae4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176ae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176ae8: 0xc05da98  jal         func_176A60
    ctx->pc = 0x176AE8u;
    SET_GPR_U32(ctx, 31, 0x176AF0u);
    ctx->pc = 0x176AECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176AE8u;
            // 0x176aec: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176A60u;
    goto label_176a60;
    ctx->pc = 0x176AF0u;
label_176af0:
    // 0x176af0: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x176af0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x176af4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176af4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176af8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176af8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176afc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176afcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176b00: 0x3e00008  jr          $ra
    ctx->pc = 0x176B00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176B04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176B00u;
            // 0x176b04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176B08u;
    // 0x176b08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176b08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176b0c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176b10: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176b10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176b14: 0x24047530  addiu       $a0, $zero, 0x7530
    ctx->pc = 0x176b14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 30000));
    // 0x176b18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176b1c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176b1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176b20: 0xc05da98  jal         func_176A60
    ctx->pc = 0x176B20u;
    SET_GPR_U32(ctx, 31, 0x176B28u);
    ctx->pc = 0x176B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176B20u;
            // 0x176b24: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176A60u;
    goto label_176a60;
    ctx->pc = 0x176B28u;
label_176b28:
    // 0x176b28: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x176b28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x176b2c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176b2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176b30: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176b30u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176b34: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176b34u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176b38: 0x3e00008  jr          $ra
    ctx->pc = 0x176B38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176B38u;
            // 0x176b3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176B40u;
    // 0x176b40: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x176b40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x176b44: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x176b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x176b48: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x176b48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176b4c: 0x3404ea60  ori         $a0, $zero, 0xEA60
    ctx->pc = 0x176b4cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)60000);
    // 0x176b50: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176b54: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x176b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x176b58: 0xc05da98  jal         func_176A60
    ctx->pc = 0x176B58u;
    SET_GPR_U32(ctx, 31, 0x176B60u);
    ctx->pc = 0x176B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176B58u;
            // 0x176b5c: 0xe0802d  daddu       $s0, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176A60u;
    goto label_176a60;
    ctx->pc = 0x176B60u;
label_176b60:
    // 0x176b60: 0xae110000  sw          $s1, 0x0($s0)
    ctx->pc = 0x176b60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 17));
    // 0x176b64: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x176b64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x176b68: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176b68u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176b6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x176b6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176b70: 0x3e00008  jr          $ra
    ctx->pc = 0x176B70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176B74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176B70u;
            // 0x176b74: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176B78u;
    // 0x176b78: 0x8caa000c  lw          $t2, 0xC($a1)
    ctx->pc = 0x176b78u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176b7c: 0x240b000a  addiu       $t3, $zero, 0xA
    ctx->pc = 0x176b7cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x176b80: 0x8cac0010  lw          $t4, 0x10($a1)
    ctx->pc = 0x176b80u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176b84: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x176b84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x176b88: 0x14b001a  div         $zero, $t2, $t3
    ctx->pc = 0x176b88u;
    { int32_t divisor = GPR_S32(ctx, 11);    int32_t dividend = GPR_S32(ctx, 10);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x176b8c: 0x8ca90008  lw          $t1, 0x8($a1)
    ctx->pc = 0x176b8cu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176b90: 0x34425114  ori         $v0, $v0, 0x5114
    ctx->pc = 0x176b90u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)20756);
    // 0x176b94: 0x2408059e  addiu       $t0, $zero, 0x59E
    ctx->pc = 0x176b94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1438));
    // 0x176b98: 0xc1840  sll         $v1, $t4, 1
    ctx->pc = 0x176b98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x176b9c: 0x51600001  beql        $t3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176B9Cu;
    {
        const bool branch_taken_0x176b9c = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x176b9c) {
            ctx->pc = 0x176BA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176B9Cu;
            // 0x176ba0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x176BA4u;
            goto label_176ba4;
        }
    }
    ctx->pc = 0x176BA4u;
label_176ba4:
    // 0x176ba4: 0x6c1821  addu        $v1, $v1, $t4
    ctx->pc = 0x176ba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x176ba8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x176ba8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x176bac: 0x6812  mflo        $t5
    ctx->pc = 0x176bacu;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x176bb0: 0x1224818  mult        $t1, $t1, $v0
    ctx->pc = 0x176bb0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x176bb4: 0x1485018  mult        $t2, $t2, $t0
    ctx->pc = 0x176bb4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176bb8: 0x8ca80014  lw          $t0, 0x14($a1)
    ctx->pc = 0x176bb8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176bbc: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x176bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176bc0: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x176bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x176bc4: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176bc4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176bc8: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x176bc8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x176bcc: 0x12a4821  addu        $t1, $t1, $t2
    ctx->pc = 0x176bccu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 10)));
    // 0x176bd0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x176bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x176bd4: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x176bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x176bd8: 0x31140  sll         $v0, $v1, 5
    ctx->pc = 0x176bd8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x176bdc: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x176bdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176be0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176be0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176be4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176be8: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x176be8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x176bec: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x176becu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x176bf0: 0x3e00008  jr          $ra
    ctx->pc = 0x176BF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176BF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176BF0u;
            // 0x176bf4: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176BF8u;
    // 0x176bf8: 0x8ca9000c  lw          $t1, 0xC($a1)
    ctx->pc = 0x176bf8u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176bfc: 0x240c000a  addiu       $t4, $zero, 0xA
    ctx->pc = 0x176bfcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x176c00: 0x8caa0008  lw          $t2, 0x8($a1)
    ctx->pc = 0x176c00u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176c04: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x176c04u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x176c08: 0x12c001a  div         $zero, $t1, $t4
    ctx->pc = 0x176c08u;
    { int32_t divisor = GPR_S32(ctx, 12);    int32_t dividend = GPR_S32(ctx, 9);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x176c0c: 0x8cab0010  lw          $t3, 0x10($a1)
    ctx->pc = 0x176c0cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176c10: 0x3442a574  ori         $v0, $v0, 0xA574
    ctx->pc = 0x176c10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)42356);
    // 0x176c14: 0x24080706  addiu       $t0, $zero, 0x706
    ctx->pc = 0x176c14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1798));
    // 0x176c18: 0x71284818  mult1       $t1, $t1, $t0
    ctx->pc = 0x176c18u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 8); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 9, (int32_t)result); }
    // 0x176c1c: 0x8ca80014  lw          $t0, 0x14($a1)
    ctx->pc = 0x176c1cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176c20: 0xb1900  sll         $v1, $t3, 4
    ctx->pc = 0x176c20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 11), 4));
    // 0x176c24: 0x51800001  beql        $t4, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176C24u;
    {
        const bool branch_taken_0x176c24 = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        if (branch_taken_0x176c24) {
            ctx->pc = 0x176C28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176C24u;
            // 0x176c28: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x176C2Cu;
            goto label_176c2c;
        }
    }
    ctx->pc = 0x176C2Cu;
label_176c2c:
    // 0x176c2c: 0x6b1823  subu        $v1, $v1, $t3
    ctx->pc = 0x176c2cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x176c30: 0x6812  mflo        $t5
    ctx->pc = 0x176c30u;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x176c34: 0x1425018  mult        $t2, $t2, $v0
    ctx->pc = 0x176c34u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176c38: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x176c38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x176c3c: 0x8ca20018  lw          $v0, 0x18($a1)
    ctx->pc = 0x176c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176c40: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176c40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176c44: 0x1024021  addu        $t0, $t0, $v0
    ctx->pc = 0x176c44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x176c48: 0x1495021  addu        $t2, $t2, $t1
    ctx->pc = 0x176c48u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x176c4c: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x176c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x176c50: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x176c50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x176c54: 0x31140  sll         $v0, $v1, 5
    ctx->pc = 0x176c54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x176c58: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x176c58u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176c5c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176c60: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176c60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176c64: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x176c64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x176c68: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x176c68u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x176c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x176C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176C6Cu;
            // 0x176c70: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176C74u;
    // 0x176c74: 0x0  nop
    ctx->pc = 0x176c74u;
    // NOP
    // 0x176c78: 0x8ca8000c  lw          $t0, 0xC($a1)
    ctx->pc = 0x176c78u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x176c7c: 0x240b000a  addiu       $t3, $zero, 0xA
    ctx->pc = 0x176c7cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x176c80: 0x8cac0010  lw          $t4, 0x10($a1)
    ctx->pc = 0x176c80u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x176c84: 0x3c090003  lui         $t1, 0x3
    ctx->pc = 0x176c84u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)3 << 16));
    // 0x176c88: 0x10b001a  div         $zero, $t0, $t3
    ctx->pc = 0x176c88u;
    { int32_t divisor = GPR_S32(ctx, 11);    int32_t dividend = GPR_S32(ctx, 8);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x176c8c: 0x8caa0008  lw          $t2, 0x8($a1)
    ctx->pc = 0x176c8cu;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x176c90: 0x35294b54  ori         $t1, $t1, 0x4B54
    ctx->pc = 0x176c90u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 9) | (uint64_t)(uint16_t)19284);
    // 0x176c94: 0x810c0  sll         $v0, $t0, 3
    ctx->pc = 0x176c94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x176c98: 0x481023  subu        $v0, $v0, $t0
    ctx->pc = 0x176c98u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x176c9c: 0xc1900  sll         $v1, $t4, 4
    ctx->pc = 0x176c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 12), 4));
    // 0x176ca0: 0x24200  sll         $t0, $v0, 8
    ctx->pc = 0x176ca0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x176ca4: 0x6c1823  subu        $v1, $v1, $t4
    ctx->pc = 0x176ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x176ca8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x176ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x176cac: 0x8ca80014  lw          $t0, 0x14($a1)
    ctx->pc = 0x176cacu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 20)));
    // 0x176cb0: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176cb4: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x176cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x176cb8: 0x51600001  beql        $t3, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176CB8u;
    {
        const bool branch_taken_0x176cb8 = (GPR_U64(ctx, 11) == GPR_U64(ctx, 0));
        if (branch_taken_0x176cb8) {
            ctx->pc = 0x176CBCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176CB8u;
            // 0x176cbc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x176CC0u;
            goto label_176cc0;
        }
    }
    ctx->pc = 0x176CC0u;
label_176cc0:
    // 0x176cc0: 0x6812  mflo        $t5
    ctx->pc = 0x176cc0u;
    SET_GPR_U64(ctx, 13, ctx->lo);
    // 0x176cc4: 0x1495018  mult        $t2, $t2, $t1
    ctx->pc = 0x176cc4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 10, (int32_t)result); }
    // 0x176cc8: 0x6d1821  addu        $v1, $v1, $t5
    ctx->pc = 0x176cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 13)));
    // 0x176ccc: 0x8ca90018  lw          $t1, 0x18($a1)
    ctx->pc = 0x176cccu;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 24)));
    // 0x176cd0: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x176cd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x176cd4: 0x1094021  addu        $t0, $t0, $t1
    ctx->pc = 0x176cd4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 9)));
    // 0x176cd8: 0x1425021  addu        $t2, $t2, $v0
    ctx->pc = 0x176cd8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0x176cdc: 0x6a1821  addu        $v1, $v1, $t2
    ctx->pc = 0x176cdcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x176ce0: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x176ce0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x176ce4: 0x31140  sll         $v0, $v1, 5
    ctx->pc = 0x176ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x176ce8: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x176ce8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176cec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x176cecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x176cf0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x176cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x176cf4: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x176cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x176cf8: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x176cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x176cfc: 0x3e00008  jr          $ra
    ctx->pc = 0x176CFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176CFCu;
            // 0x176d00: 0xace40000  sw          $a0, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176A60u: goto label_176a60;
            case 0x176AF0u: goto label_176af0;
            case 0x176B28u: goto label_176b28;
            case 0x176B60u: goto label_176b60;
            case 0x176BA4u: goto label_176ba4;
            case 0x176C2Cu: goto label_176c2c;
            case 0x176CC0u: goto label_176cc0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176D04u;
    // 0x176d04: 0x0  nop
    ctx->pc = 0x176d04u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
