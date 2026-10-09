#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00126990
// Address: 0x126990 - 0x126ac8
void sub_00126990_0x126990(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00126990_0x126990");
#endif

    switch (ctx->pc) {
        case 0x1269c4u: goto label_1269c4;
        default: break;
    }

    ctx->pc = 0x126990u;

    // 0x126990: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x126990u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x126994: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x126994u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x126998: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x126998u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12699c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x12699cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1269a0: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1269a0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1269a4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x1269a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1269a8: 0x27a70001  addiu       $a3, $sp, 0x1
    ctx->pc = 0x1269a8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 1));
    // 0x1269ac: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1269acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1269b0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1269b0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1269b4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1269b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1269b8: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1269b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1269bc: 0xc049a46  jal         func_126918
    ctx->pc = 0x1269BCu;
    SET_GPR_U32(ctx, 31, 0x1269C4u);
    ctx->pc = 0x1269C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1269BCu;
            // 0x1269c0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126918u;
    if (runtime->hasFunction(0x126918u)) {
        auto targetFn = runtime->lookupFunction(0x126918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1269C4u; }
        if (ctx->pc != 0x1269C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126918_0x126918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1269C4u; }
        if (ctx->pc != 0x1269C4u) { return; }
    }
    ctx->pc = 0x1269C4u;
label_1269c4:
    // 0x1269c4: 0x14400038  bnez        $v0, . + 4 + (0x38 << 2)
    ctx->pc = 0x1269C4u;
    {
        const bool branch_taken_0x1269c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1269C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1269C4u;
            // 0x1269c8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1269c4) {
            ctx->pc = 0x126AA8u;
            goto label_126aa8;
        }
    }
    ctx->pc = 0x1269CCu;
    // 0x1269cc: 0x93a20000  lbu         $v0, 0x0($sp)
    ctx->pc = 0x1269ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1269d0: 0x2c420004  sltiu       $v0, $v0, 0x4
    ctx->pc = 0x1269d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)4) ? 1 : 0);
    // 0x1269d4: 0x54400030  bnel        $v0, $zero, . + 4 + (0x30 << 2)
    ctx->pc = 0x1269D4u;
    {
        const bool branch_taken_0x1269d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1269d4) {
            ctx->pc = 0x1269D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1269D4u;
            // 0x1269d8: 0xa6600002  sh          $zero, 0x2($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 2), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x126A98u;
            goto label_126a98;
        }
    }
    ctx->pc = 0x1269DCu;
    // 0x1269dc: 0x2a230020  slti        $v1, $s1, 0x20
    ctx->pc = 0x1269dcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1269e0: 0x14600031  bnez        $v1, . + 4 + (0x31 << 2)
    ctx->pc = 0x1269E0u;
    {
        const bool branch_taken_0x1269e0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1269E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1269E0u;
            // 0x1269e4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1269e0) {
            ctx->pc = 0x126AA8u;
            goto label_126aa8;
        }
    }
    ctx->pc = 0x1269E8u;
    // 0x1269e8: 0x96030000  lhu         $v1, 0x0($s0)
    ctx->pc = 0x1269e8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1269ec: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x1269ecu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1269f0: 0x2406ff00  addiu       $a2, $zero, -0x100
    ctx->pc = 0x1269f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1269f4: 0x32200  sll         $a0, $v1, 8
    ctx->pc = 0x1269f4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1269f8: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x1269f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x1269fc: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1269fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126a00: 0x3063ffff  andi        $v1, $v1, 0xFFFF
    ctx->pc = 0x126a00u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)65535);
    // 0x126a04: 0x14650028  bne         $v1, $a1, . + 4 + (0x28 << 2)
    ctx->pc = 0x126A04u;
    {
        const bool branch_taken_0x126a04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 5));
        ctx->pc = 0x126A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126A04u;
            // 0x126a08: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126a04) {
            ctx->pc = 0x126AA8u;
            goto label_126aa8;
        }
    }
    ctx->pc = 0x126A0Cu;
    // 0x126a0c: 0x96040002  lhu         $a0, 0x2($s0)
    ctx->pc = 0x126a0cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x126a10: 0x92030003  lbu         $v1, 0x3($s0)
    ctx->pc = 0x126a10u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x126a14: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x126a14u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x126a18: 0x862024  and         $a0, $a0, $a2
    ctx->pc = 0x126a18u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 6));
    // 0x126a1c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x126a1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x126a20: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x126a20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x126a24: 0x31c03  sra         $v1, $v1, 16
    ctx->pc = 0x126a24u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x126a28: 0x2863001c  slti        $v1, $v1, 0x1C
    ctx->pc = 0x126a28u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x126a2c: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x126A2Cu;
    {
        const bool branch_taken_0x126a2c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x126A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126A2Cu;
            // 0x126a30: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126a2c) {
            ctx->pc = 0x126AA8u;
            goto label_126aa8;
        }
    }
    ctx->pc = 0x126A34u;
    // 0x126a34: 0x96020018  lhu         $v0, 0x18($s0)
    ctx->pc = 0x126a34u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x126a38: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x126a38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126a3c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x126a3cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x126a40: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x126a40u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x126a44: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x126a44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x126a48: 0xa6420000  sh          $v0, 0x0($s2)
    ctx->pc = 0x126a48u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x126a4c: 0x9603001a  lhu         $v1, 0x1A($s0)
    ctx->pc = 0x126a4cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 26)));
    // 0x126a50: 0x31200  sll         $v0, $v1, 8
    ctx->pc = 0x126a50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126a54: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x126a54u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x126a58: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x126a58u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x126a5c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126a5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x126a60: 0xa6630000  sh          $v1, 0x0($s3)
    ctx->pc = 0x126a60u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x126a64: 0x9602001c  lhu         $v0, 0x1C($s0)
    ctx->pc = 0x126a64u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x126a68: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x126a68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x126a6c: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x126a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x126a70: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x126a70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x126a74: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x126a74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x126a78: 0xa6420002  sh          $v0, 0x2($s2)
    ctx->pc = 0x126a78u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x126a7c: 0x9603001e  lhu         $v1, 0x1E($s0)
    ctx->pc = 0x126a7cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 30)));
    // 0x126a80: 0x31200  sll         $v0, $v1, 8
    ctx->pc = 0x126a80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x126a84: 0x31a02  srl         $v1, $v1, 8
    ctx->pc = 0x126a84u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 8));
    // 0x126a88: 0x461024  and         $v0, $v0, $a2
    ctx->pc = 0x126a88u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 6));
    // 0x126a8c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x126a8cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x126a90: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x126A90u;
    {
        const bool branch_taken_0x126a90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x126A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126A90u;
            // 0x126a94: 0xa6630002  sh          $v1, 0x2($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 2), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x126a90) {
            ctx->pc = 0x126AA4u;
            goto label_126aa4;
        }
    }
    ctx->pc = 0x126A98u;
label_126a98:
    // 0x126a98: 0xa6400002  sh          $zero, 0x2($s2)
    ctx->pc = 0x126a98u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 2), (uint16_t)GPR_U32(ctx, 0));
    // 0x126a9c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x126a9cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x126aa0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x126aa0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
label_126aa4:
    // 0x126aa4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x126aa4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_126aa8:
    // 0x126aa8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x126aa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x126aac: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x126aacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x126ab0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x126ab0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x126ab4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x126ab4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x126ab8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x126ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x126abc: 0x3e00008  jr          $ra
    ctx->pc = 0x126ABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x126AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x126ABCu;
            // 0x126ac0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1269C4u: goto label_1269c4;
            case 0x126A98u: goto label_126a98;
            case 0x126AA4u: goto label_126aa4;
            case 0x126AA8u: goto label_126aa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x126AC4u;
    // 0x126ac4: 0x0  nop
    ctx->pc = 0x126ac4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
