#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00150A78
// Address: 0x150a78 - 0x150c40
void sub_00150A78_0x150a78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00150A78_0x150a78");
#endif

    switch (ctx->pc) {
        case 0x150a98u: goto label_150a98;
        case 0x150b4cu: goto label_150b4c;
        case 0x150b80u: goto label_150b80;
        default: break;
    }

    ctx->pc = 0x150a78u;

    // 0x150a78: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x150a78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x150a7c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x150a7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150a80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150a80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150a84: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x150a84u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x150a88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x150a88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150a8c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x150a8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x150a90: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x150A90u;
    SET_GPR_U32(ctx, 31, 0x150A98u);
    ctx->pc = 0x150A94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150A90u;
            // 0x150a94: 0x24060560  addiu       $a2, $zero, 0x560 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1376));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150A98u; }
        if (ctx->pc != 0x150A98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150A98u; }
        if (ctx->pc != 0x150A98u) { return; }
    }
    ctx->pc = 0x150A98u;
label_150a98:
    // 0x150a98: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x150a98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150a9c: 0xae0004c8  sw          $zero, 0x4C8($s0)
    ctx->pc = 0x150a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1224), GPR_U32(ctx, 0));
    // 0x150aa0: 0xae000424  sw          $zero, 0x424($s0)
    ctx->pc = 0x150aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1060), GPR_U32(ctx, 0));
    // 0x150aa4: 0xae0004cc  sw          $zero, 0x4CC($s0)
    ctx->pc = 0x150aa4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1228), GPR_U32(ctx, 0));
    // 0x150aa8: 0xae0004d0  sw          $zero, 0x4D0($s0)
    ctx->pc = 0x150aa8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1232), GPR_U32(ctx, 0));
    // 0x150aac: 0xae0004d4  sw          $zero, 0x4D4($s0)
    ctx->pc = 0x150aacu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1236), GPR_U32(ctx, 0));
    // 0x150ab0: 0xae0004d8  sw          $zero, 0x4D8($s0)
    ctx->pc = 0x150ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1240), GPR_U32(ctx, 0));
    // 0x150ab4: 0xae0004dc  sw          $zero, 0x4DC($s0)
    ctx->pc = 0x150ab4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1244), GPR_U32(ctx, 0));
    // 0x150ab8: 0xae0004e0  sw          $zero, 0x4E0($s0)
    ctx->pc = 0x150ab8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 1248), GPR_U32(ctx, 0));
    // 0x150abc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150abcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150ac0: 0x3e00008  jr          $ra
    ctx->pc = 0x150AC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150AC0u;
            // 0x150ac4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150A98u: goto label_150a98;
            case 0x150B18u: goto label_150b18;
            case 0x150B28u: goto label_150b28;
            case 0x150B4Cu: goto label_150b4c;
            case 0x150B78u: goto label_150b78;
            case 0x150B80u: goto label_150b80;
            case 0x150B98u: goto label_150b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150AC8u;
    // 0x150ac8: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x150ac8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x150acc: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x150accu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x150ad0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x150ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x150ad4: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x150ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x150ad8: 0x248400ec  addiu       $a0, $a0, 0xEC
    ctx->pc = 0x150ad8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 236));
    // 0x150adc: 0xac880008  sw          $t0, 0x8($a0)
    ctx->pc = 0x150adcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 8));
    // 0x150ae0: 0xac860000  sw          $a2, 0x0($a0)
    ctx->pc = 0x150ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 6));
    // 0x150ae4: 0x3e00008  jr          $ra
    ctx->pc = 0x150AE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150AE4u;
            // 0x150ae8: 0xac870004  sw          $a3, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150A98u: goto label_150a98;
            case 0x150B18u: goto label_150b18;
            case 0x150B28u: goto label_150b28;
            case 0x150B4Cu: goto label_150b4c;
            case 0x150B78u: goto label_150b78;
            case 0x150B80u: goto label_150b80;
            case 0x150B98u: goto label_150b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150AECu;
    // 0x150aec: 0x0  nop
    ctx->pc = 0x150aecu;
    // NOP
    // 0x150af0: 0x2484011c  addiu       $a0, $a0, 0x11C
    ctx->pc = 0x150af0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 284));
    // 0x150af4: 0xac850000  sw          $a1, 0x0($a0)
    ctx->pc = 0x150af4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x150af8: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x150af8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
    // 0x150afc: 0x3e00008  jr          $ra
    ctx->pc = 0x150AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150AFCu;
            // 0x150b00: 0xac800008  sw          $zero, 0x8($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150A98u: goto label_150a98;
            case 0x150B18u: goto label_150b18;
            case 0x150B28u: goto label_150b28;
            case 0x150B4Cu: goto label_150b4c;
            case 0x150B78u: goto label_150b78;
            case 0x150B80u: goto label_150b80;
            case 0x150B98u: goto label_150b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150B04u;
    // 0x150b04: 0x0  nop
    ctx->pc = 0x150b04u;
    // NOP
    // 0x150b08: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x150B08u;
    {
        const bool branch_taken_0x150b08 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x150B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150B08u;
            // 0x150b0c: 0x2484011c  addiu       $a0, $a0, 0x11C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150b08) {
            ctx->pc = 0x150B18u;
            goto label_150b18;
        }
    }
    ctx->pc = 0x150B10u;
    // 0x150b10: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x150b10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x150b14: 0xaca20000  sw          $v0, 0x0($a1)
    ctx->pc = 0x150b14u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_150b18:
    // 0x150b18: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x150B18u;
    {
        const bool branch_taken_0x150b18 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x150b18) {
            ctx->pc = 0x150B28u;
            goto label_150b28;
        }
    }
    ctx->pc = 0x150B20u;
    // 0x150b20: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x150b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x150b24: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x150b24u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
label_150b28:
    // 0x150b28: 0x3e00008  jr          $ra
    ctx->pc = 0x150B28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150A98u: goto label_150a98;
            case 0x150B18u: goto label_150b18;
            case 0x150B28u: goto label_150b28;
            case 0x150B4Cu: goto label_150b4c;
            case 0x150B78u: goto label_150b78;
            case 0x150B80u: goto label_150b80;
            case 0x150B98u: goto label_150b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150B30u;
    // 0x150b30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x150b30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x150b34: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x150b34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x150b38: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x150b38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150b3c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x150b3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x150b40: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x150b40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x150b44: 0xc05578e  jal         func_155E38
    ctx->pc = 0x150B44u;
    SET_GPR_U32(ctx, 31, 0x150B4Cu);
    ctx->pc = 0x150B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150B44u;
            // 0x150b48: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150B4Cu; }
        if (ctx->pc != 0x150B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150B4Cu; }
        if (ctx->pc != 0x150B4Cu) { return; }
    }
    ctx->pc = 0x150B4Cu;
label_150b4c:
    // 0x150b4c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x150b4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150b50: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x150B50u;
    {
        const bool branch_taken_0x150b50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150B50u;
            // 0x150b54: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x150b50) {
            ctx->pc = 0x150B78u;
            goto label_150b78;
        }
    }
    ctx->pc = 0x150B58u;
    // 0x150b58: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x150b58u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x150b5c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150b5cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150b60: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150b60u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150b64: 0x34a5020c  ori         $a1, $a1, 0x20C
    ctx->pc = 0x150b64u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)524);
    // 0x150b68: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150b68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150b6c: 0x805419c  j           func_150670
    ctx->pc = 0x150B6Cu;
    ctx->pc = 0x150B70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150B6Cu;
            // 0x150b70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150B74u;
    // 0x150b74: 0x0  nop
    ctx->pc = 0x150b74u;
    // NOP
label_150b78:
    // 0x150b78: 0xc054310  jal         func_150C40
    ctx->pc = 0x150B78u;
    SET_GPR_U32(ctx, 31, 0x150B80u);
    ctx->pc = 0x150B7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150B78u;
            // 0x150b7c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150C40u;
    if (runtime->hasFunction(0x150C40u)) {
        auto targetFn = runtime->lookupFunction(0x150C40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150B80u; }
        if (ctx->pc != 0x150B80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150C40_0x150c40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x150B80u; }
        if (ctx->pc != 0x150B80u) { return; }
    }
    ctx->pc = 0x150B80u;
label_150b80:
    // 0x150b80: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x150b80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x150b84: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150b84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150b88: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150b88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150b8c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x150b8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150b90: 0x80542e6  j           func_150B98
    ctx->pc = 0x150B90u;
    ctx->pc = 0x150B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150B90u;
            // 0x150b94: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150B98u;
    goto label_150b98;
    ctx->pc = 0x150B98u;
label_150b98:
    // 0x150b98: 0x24820128  addiu       $v0, $a0, 0x128
    ctx->pc = 0x150b98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x150b9c: 0x24840058  addiu       $a0, $a0, 0x58
    ctx->pc = 0x150b9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 88));
    // 0x150ba0: 0x8c4302c4  lw          $v1, 0x2C4($v0)
    ctx->pc = 0x150ba0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 708)));
    // 0x150ba4: 0xac830000  sw          $v1, 0x0($a0)
    ctx->pc = 0x150ba4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3));
    // 0x150ba8: 0x8c4502c8  lw          $a1, 0x2C8($v0)
    ctx->pc = 0x150ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 712)));
    // 0x150bac: 0xac850004  sw          $a1, 0x4($a0)
    ctx->pc = 0x150bacu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
    // 0x150bb0: 0x8c4302cc  lw          $v1, 0x2CC($v0)
    ctx->pc = 0x150bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 716)));
    // 0x150bb4: 0xac830008  sw          $v1, 0x8($a0)
    ctx->pc = 0x150bb4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x150bb8: 0x8c4502d0  lw          $a1, 0x2D0($v0)
    ctx->pc = 0x150bb8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 720)));
    // 0x150bbc: 0xac85000c  sw          $a1, 0xC($a0)
    ctx->pc = 0x150bbcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
    // 0x150bc0: 0x8c4300dc  lw          $v1, 0xDC($v0)
    ctx->pc = 0x150bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 220)));
    // 0x150bc4: 0x8c450010  lw          $a1, 0x10($v0)
    ctx->pc = 0x150bc4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x150bc8: 0xac830014  sw          $v1, 0x14($a0)
    ctx->pc = 0x150bc8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x150bcc: 0xac850010  sw          $a1, 0x10($a0)
    ctx->pc = 0x150bccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 5));
    // 0x150bd0: 0x8c4300bc  lw          $v1, 0xBC($v0)
    ctx->pc = 0x150bd0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 188)));
    // 0x150bd4: 0x8c4500e0  lw          $a1, 0xE0($v0)
    ctx->pc = 0x150bd4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 224)));
    // 0x150bd8: 0xac83001c  sw          $v1, 0x1C($a0)
    ctx->pc = 0x150bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x150bdc: 0xac850018  sw          $a1, 0x18($a0)
    ctx->pc = 0x150bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 5));
    // 0x150be0: 0x8c4300c0  lw          $v1, 0xC0($v0)
    ctx->pc = 0x150be0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 192)));
    // 0x150be4: 0xac830020  sw          $v1, 0x20($a0)
    ctx->pc = 0x150be4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 3));
    // 0x150be8: 0x8c4500c4  lw          $a1, 0xC4($v0)
    ctx->pc = 0x150be8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 196)));
    // 0x150bec: 0xac850024  sw          $a1, 0x24($a0)
    ctx->pc = 0x150becu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 5));
    // 0x150bf0: 0x8c4300c8  lw          $v1, 0xC8($v0)
    ctx->pc = 0x150bf0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 200)));
    // 0x150bf4: 0xac830028  sw          $v1, 0x28($a0)
    ctx->pc = 0x150bf4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 3));
    // 0x150bf8: 0x8c4500cc  lw          $a1, 0xCC($v0)
    ctx->pc = 0x150bf8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 204)));
    // 0x150bfc: 0xac85002c  sw          $a1, 0x2C($a0)
    ctx->pc = 0x150bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 5));
    // 0x150c00: 0x8c4304f4  lw          $v1, 0x4F4($v0)
    ctx->pc = 0x150c00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1268)));
    // 0x150c04: 0xac830030  sw          $v1, 0x30($a0)
    ctx->pc = 0x150c04u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 3));
    // 0x150c08: 0x8c4504e4  lw          $a1, 0x4E4($v0)
    ctx->pc = 0x150c08u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1252)));
    // 0x150c0c: 0xac850034  sw          $a1, 0x34($a0)
    ctx->pc = 0x150c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 52), GPR_U32(ctx, 5));
    // 0x150c10: 0x8c430118  lw          $v1, 0x118($v0)
    ctx->pc = 0x150c10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 280)));
    // 0x150c14: 0x8c45004c  lw          $a1, 0x4C($v0)
    ctx->pc = 0x150c14u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 76)));
    // 0x150c18: 0x8c46013c  lw          $a2, 0x13C($v0)
    ctx->pc = 0x150c18u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 316)));
    // 0x150c1c: 0xac830038  sw          $v1, 0x38($a0)
    ctx->pc = 0x150c1cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 56), GPR_U32(ctx, 3));
    // 0x150c20: 0xac85003c  sw          $a1, 0x3C($a0)
    ctx->pc = 0x150c20u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 60), GPR_U32(ctx, 5));
    // 0x150c24: 0xac860040  sw          $a2, 0x40($a0)
    ctx->pc = 0x150c24u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 64), GPR_U32(ctx, 6));
    // 0x150c28: 0x8c43011c  lw          $v1, 0x11C($v0)
    ctx->pc = 0x150c28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 284)));
    // 0x150c2c: 0xac830044  sw          $v1, 0x44($a0)
    ctx->pc = 0x150c2cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 68), GPR_U32(ctx, 3));
    // 0x150c30: 0x8c450134  lw          $a1, 0x134($v0)
    ctx->pc = 0x150c30u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 308)));
    // 0x150c34: 0x3e00008  jr          $ra
    ctx->pc = 0x150C34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150C38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150C34u;
            // 0x150c38: 0xac850048  sw          $a1, 0x48($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 72), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x150A98u: goto label_150a98;
            case 0x150B18u: goto label_150b18;
            case 0x150B28u: goto label_150b28;
            case 0x150B4Cu: goto label_150b4c;
            case 0x150B78u: goto label_150b78;
            case 0x150B80u: goto label_150b80;
            case 0x150B98u: goto label_150b98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150C3Cu;
    // 0x150c3c: 0x0  nop
    ctx->pc = 0x150c3cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
