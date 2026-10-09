#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4A10
// Address: 0x1f4a10 - 0x1f4b20
void sub_001F4A10_0x1f4a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4A10_0x1f4a10");
#endif

    switch (ctx->pc) {
        case 0x1f4a58u: goto label_1f4a58;
        default: break;
    }

    ctx->pc = 0x1f4a10u;

    // 0x1f4a10: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1f4a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1f4a14: 0xffbf0060  sd          $ra, 0x60($sp)
    ctx->pc = 0x1f4a14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x1f4a18: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1f4a18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1f4a1c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1f4a1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1f4a20: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1f4a20u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4a24: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1f4a24u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1f4a28: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x1f4a28u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4a2c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1f4a2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1f4a30: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1f4a30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4a34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f4a34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f4a38: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1f4a38u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4a3c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f4a3cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f4a40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1f4a40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f4a44: 0x8c91001c  lw          $s1, 0x1C($a0)
    ctx->pc = 0x1f4a44u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x1f4a48: 0x24060008  addiu       $a2, $zero, 0x8
    ctx->pc = 0x1f4a48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f4a4c: 0x8c900024  lw          $s0, 0x24($a0)
    ctx->pc = 0x1f4a4cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f4a50: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1F4A50u;
    SET_GPR_U32(ctx, 31, 0x1F4A58u);
    ctx->pc = 0x1F4A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4A50u;
            // 0x1f4a54: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4A58u; }
        if (ctx->pc != 0x1F4A58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4A58u; }
        if (ctx->pc != 0x1F4A58u) { return; }
    }
    ctx->pc = 0x1F4A58u;
label_1f4a58:
    // 0x1f4a58: 0x32a4ffff  andi        $a0, $s5, 0xFFFF
    ctx->pc = 0x1f4a58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)65535);
    // 0x1f4a5c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F4A5Cu;
    {
        const bool branch_taken_0x1f4a5c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F4A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4A5Cu;
            // 0x1f4a60: 0xa2330002  sb          $s3, 0x2($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4a5c) {
            ctx->pc = 0x1F4A78u;
            goto label_1f4a78;
        }
    }
    ctx->pc = 0x1F4A64u;
    // 0x1f4a64: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1f4a64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1f4a68: 0xa2220003  sb          $v0, 0x3($s1)
    ctx->pc = 0x1f4a68u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4a6c: 0x92020004  lbu         $v0, 0x4($s0)
    ctx->pc = 0x1f4a6cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1f4a70: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1F4A70u;
    {
        const bool branch_taken_0x1f4a70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4A74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4A70u;
            // 0x1f4a74: 0xa2220004  sb          $v0, 0x4($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4a70) {
            ctx->pc = 0x1F4AA0u;
            goto label_1f4aa0;
        }
    }
    ctx->pc = 0x1F4A78u;
label_1f4a78:
    // 0x1f4a78: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x1f4a78u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x1f4a7c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1f4a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1f4a80: 0x24637330  addiu       $v1, $v1, 0x7330
    ctx->pc = 0x1f4a80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 29488));
    // 0x1f4a84: 0x24427350  addiu       $v0, $v0, 0x7350
    ctx->pc = 0x1f4a84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 29520));
    // 0x1f4a88: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1f4a88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1f4a8c: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1f4a8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1f4a90: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1f4a90u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f4a94: 0xa2230003  sb          $v1, 0x3($s1)
    ctx->pc = 0x1f4a94u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f4a98: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1f4a98u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1f4a9c: 0xa2220004  sb          $v0, 0x4($s1)
    ctx->pc = 0x1f4a9cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 4), (uint8_t)GPR_U32(ctx, 2));
label_1f4aa0:
    // 0x1f4aa0: 0x326300ff  andi        $v1, $s3, 0xFF
    ctx->pc = 0x1f4aa0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)255);
    // 0x1f4aa4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1f4aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f4aa8: 0x1062000d  beq         $v1, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1F4AA8u;
    {
        const bool branch_taken_0x1f4aa8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F4AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4AA8u;
            // 0x1f4aac: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4aa8) {
            ctx->pc = 0x1F4AE0u;
            goto label_1f4ae0;
        }
    }
    ctx->pc = 0x1F4AB0u;
    // 0x1f4ab0: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1F4AB0u;
    {
        const bool branch_taken_0x1f4ab0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1f4ab0) {
            ctx->pc = 0x1F4ACCu;
            goto label_1f4acc;
        }
    }
    ctx->pc = 0x1F4AB8u;
    // 0x1f4ab8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1f4ab8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f4abc: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4ABCu;
    {
        const bool branch_taken_0x1f4abc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1f4abc) {
            ctx->pc = 0x1F4ACCu;
            goto label_1f4acc;
        }
    }
    ctx->pc = 0x1F4AC4u;
    // 0x1f4ac4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F4AC4u;
    {
        const bool branch_taken_0x1f4ac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4AC4u;
            // 0x1f4ac8: 0xa2320006  sb          $s2, 0x6($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 6), (uint8_t)GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4ac4) {
            ctx->pc = 0x1F4AECu;
            goto label_1f4aec;
        }
    }
    ctx->pc = 0x1F4ACCu;
label_1f4acc:
    // 0x1f4acc: 0x92830031  lbu         $v1, 0x31($s4)
    ctx->pc = 0x1f4accu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 20), 49)));
    // 0x1f4ad0: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1f4ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1f4ad4: 0xa2820031  sb          $v0, 0x31($s4)
    ctx->pc = 0x1f4ad4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 49), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4ad8: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1F4AD8u;
    {
        const bool branch_taken_0x1f4ad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F4ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4AD8u;
            // 0x1f4adc: 0xa2230005  sb          $v1, 0x5($s1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 17), 5), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f4ad8) {
            ctx->pc = 0x1F4AE8u;
            goto label_1f4ae8;
        }
    }
    ctx->pc = 0x1F4AE0u;
label_1f4ae0:
    // 0x1f4ae0: 0x92020005  lbu         $v0, 0x5($s0)
    ctx->pc = 0x1f4ae0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x1f4ae4: 0xa2220005  sb          $v0, 0x5($s1)
    ctx->pc = 0x1f4ae4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 5), (uint8_t)GPR_U32(ctx, 2));
label_1f4ae8:
    // 0x1f4ae8: 0xa2320006  sb          $s2, 0x6($s1)
    ctx->pc = 0x1f4ae8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 6), (uint8_t)GPR_U32(ctx, 18));
label_1f4aec:
    // 0x1f4aec: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1f4aecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1f4af0: 0xa2220007  sb          $v0, 0x7($s1)
    ctx->pc = 0x1f4af0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 7), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f4af4: 0xae80002c  sw          $zero, 0x2C($s4)
    ctx->pc = 0x1f4af4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 44), GPR_U32(ctx, 0));
    // 0x1f4af8: 0x8e820020  lw          $v0, 0x20($s4)
    ctx->pc = 0x1f4af8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 32)));
    // 0x1f4afc: 0xdfbf0060  ld          $ra, 0x60($sp)
    ctx->pc = 0x1f4afcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1f4b00: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1f4b00u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1f4b04: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1f4b04u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1f4b08: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1f4b08u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1f4b0c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f4b0cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f4b10: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1f4b10u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1f4b14: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f4b14u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4b18: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4B18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4B1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4B18u;
            // 0x1f4b1c: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4A58u: goto label_1f4a58;
            case 0x1F4A78u: goto label_1f4a78;
            case 0x1F4AA0u: goto label_1f4aa0;
            case 0x1F4ACCu: goto label_1f4acc;
            case 0x1F4AE0u: goto label_1f4ae0;
            case 0x1F4AE8u: goto label_1f4ae8;
            case 0x1F4AECu: goto label_1f4aec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4B20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
