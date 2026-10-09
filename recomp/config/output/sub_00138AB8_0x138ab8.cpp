#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138AB8
// Address: 0x138ab8 - 0x138ba8
void sub_00138AB8_0x138ab8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138AB8_0x138ab8");
#endif

    switch (ctx->pc) {
        case 0x138adcu: goto label_138adc;
        case 0x138af8u: goto label_138af8;
        case 0x138b3cu: goto label_138b3c;
        case 0x138b58u: goto label_138b58;
        case 0x138b84u: goto label_138b84;
        default: break;
    }

    ctx->pc = 0x138ab8u;

    // 0x138ab8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x138ab8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x138abc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x138abcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x138ac0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x138ac0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x138ac4: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x138ac4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ac8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x138ac8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x138acc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x138accu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138ad0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x138ad0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x138ad4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x138AD4u;
    SET_GPR_U32(ctx, 31, 0x138ADCu);
    ctx->pc = 0x138AD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138AD4u;
            // 0x138ad8: 0xa0982d  daddu       $s3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138ADCu; }
        if (ctx->pc != 0x138ADCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138ADCu; }
        if (ctx->pc != 0x138ADCu) { return; }
    }
    ctx->pc = 0x138ADCu;
label_138adc:
    // 0x138adc: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x138adcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138ae0: 0x2451bc08  addiu       $s1, $v0, -0x43F8
    ctx->pc = 0x138ae0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294949896));
    // 0x138ae4: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x138ae4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x138ae8: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x138AE8u;
    {
        const bool branch_taken_0x138ae8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x138AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138AE8u;
            // 0x138aec: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138ae8) {
            ctx->pc = 0x138B1Cu;
            goto label_138b1c;
        }
    }
    ctx->pc = 0x138AF0u;
    // 0x138af0: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x138af0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138af4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x138af4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_138af8:
    // 0x138af8: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x138af8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x138afc: 0x24840040  addiu       $a0, $a0, 0x40
    ctx->pc = 0x138afcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 64));
    // 0x138b00: 0x28a20020  slti        $v0, $a1, 0x20
    ctx->pc = 0x138b00u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x138b04: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x138B04u;
    {
        const bool branch_taken_0x138b04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x138B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138B04u;
            // 0x138b08: 0x51980  sll         $v1, $a1, 6 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138b04) {
            ctx->pc = 0x138B1Cu;
            goto label_138b1c;
        }
    }
    ctx->pc = 0x138B0Cu;
    // 0x138b0c: 0x80820000  lb          $v0, 0x0($a0)
    ctx->pc = 0x138b0cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x138b10: 0x0  nop
    ctx->pc = 0x138b10u;
    // NOP
    // 0x138b14: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x138B14u;
    {
        const bool branch_taken_0x138b14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x138B18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138B14u;
            // 0x138b18: 0x668821  addu        $s1, $v1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138b14) {
            ctx->pc = 0x138AF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_138af8;
        }
    }
    ctx->pc = 0x138B1Cu;
label_138b1c:
    // 0x138b1c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x138b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x138b20: 0x14a20009  bne         $a1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x138B20u;
    {
        const bool branch_taken_0x138b20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 2));
        ctx->pc = 0x138B24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138B20u;
            // 0x138b24: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138b20) {
            ctx->pc = 0x138B48u;
            goto label_138b48;
        }
    }
    ctx->pc = 0x138B28u;
    // 0x138b28: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138b28u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138b2c: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x138b2cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x138b30: 0x2484c908  addiu       $a0, $a0, -0x36F8
    ctx->pc = 0x138b30u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294953224));
    // 0x138b34: 0xc045a12  jal         func_116848
    ctx->pc = 0x138B34u;
    SET_GPR_U32(ctx, 31, 0x138B3Cu);
    ctx->pc = 0x138B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138B34u;
            // 0x138b38: 0x24060020  addiu       $a2, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138B3Cu; }
        if (ctx->pc != 0x138B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138B3Cu; }
        if (ctx->pc != 0x138B3Cu) { return; }
    }
    ctx->pc = 0x138B3Cu;
label_138b3c:
    // 0x138b3c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x138B3Cu;
    {
        const bool branch_taken_0x138b3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x138B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138B3Cu;
            // 0x138b40: 0x882d  daddu       $s1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138b3c) {
            ctx->pc = 0x138B7Cu;
            goto label_138b7c;
        }
    }
    ctx->pc = 0x138B44u;
    // 0x138b44: 0x0  nop
    ctx->pc = 0x138b44u;
    // NOP
label_138b48:
    // 0x138b48: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x138b48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138b4c: 0x24060040  addiu       $a2, $zero, 0x40
    ctx->pc = 0x138b4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x138b50: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x138B50u;
    SET_GPR_U32(ctx, 31, 0x138B58u);
    ctx->pc = 0x138B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x138B50u;
            // 0x138b54: 0x24100040  addiu       $s0, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138B58u; }
        if (ctx->pc != 0x138B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138B58u; }
        if (ctx->pc != 0x138B58u) { return; }
    }
    ctx->pc = 0x138B58u;
label_138b58:
    // 0x138b58: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x138b58u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x138b5c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x138b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138b60: 0xae300038  sw          $s0, 0x38($s1)
    ctx->pc = 0x138b60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 16));
    // 0x138b64: 0xae320004  sw          $s2, 0x4($s1)
    ctx->pc = 0x138b64u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 18));
    // 0x138b68: 0xae330008  sw          $s3, 0x8($s1)
    ctx->pc = 0x138b68u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 19));
    // 0x138b6c: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x138b6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x138b70: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x138b70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x138b74: 0xae220030  sw          $v0, 0x30($s1)
    ctx->pc = 0x138b74u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 48), GPR_U32(ctx, 2));
    // 0x138b78: 0xae200034  sw          $zero, 0x34($s1)
    ctx->pc = 0x138b78u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 0));
label_138b7c:
    // 0x138b7c: 0xc04fc9c  jal         func_13F270
    ctx->pc = 0x138B7Cu;
    SET_GPR_U32(ctx, 31, 0x138B84u);
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138B84u; }
        if (ctx->pc != 0x138B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F270_0x13f270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138B84u; }
        if (ctx->pc != 0x138B84u) { return; }
    }
    ctx->pc = 0x138B84u;
label_138b84:
    // 0x138b84: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x138b84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138b88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x138b88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138b8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x138b8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138b90: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x138b90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138b94: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x138b94u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x138b98: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x138b98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x138b9c: 0x3e00008  jr          $ra
    ctx->pc = 0x138B9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138BA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138B9Cu;
            // 0x138ba0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138ADCu: goto label_138adc;
            case 0x138AF8u: goto label_138af8;
            case 0x138B1Cu: goto label_138b1c;
            case 0x138B3Cu: goto label_138b3c;
            case 0x138B48u: goto label_138b48;
            case 0x138B58u: goto label_138b58;
            case 0x138B7Cu: goto label_138b7c;
            case 0x138B84u: goto label_138b84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138BA4u;
    // 0x138ba4: 0x0  nop
    ctx->pc = 0x138ba4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
