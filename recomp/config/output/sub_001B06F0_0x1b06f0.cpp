#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B06F0
// Address: 0x1b06f0 - 0x1b0980
void sub_001B06F0_0x1b06f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B06F0_0x1b06f0");
#endif

    switch (ctx->pc) {
        case 0x1b0718u: goto label_1b0718;
        case 0x1b0844u: goto label_1b0844;
        case 0x1b0864u: goto label_1b0864;
        case 0x1b0880u: goto label_1b0880;
        case 0x1b0890u: goto label_1b0890;
        case 0x1b0910u: goto label_1b0910;
        case 0x1b0930u: goto label_1b0930;
        default: break;
    }

    ctx->pc = 0x1b06f0u;

    // 0x1b06f0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1b06f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1b06f4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1b06f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1b06f8: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b06f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b06fc: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b06fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b0700: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x1b0700u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0704: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b0704u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b0708: 0x27b3006c  addiu       $s3, $sp, 0x6C
    ctx->pc = 0x1b0708u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 29), 108));
    // 0x1b070c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b070cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b0710: 0x1000008b  b           . + 4 + (0x8B << 2)
    ctx->pc = 0x1B0710u;
    {
        const bool branch_taken_0x1b0710 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0710u;
            // 0x1b0714: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0710) {
            ctx->pc = 0x1B0940u;
            goto label_1b0940;
        }
    }
    ctx->pc = 0x1B0718u;
label_1b0718:
    // 0x1b0718: 0x141100  sll         $v0, $s4, 4
    ctx->pc = 0x1b0718u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 4));
    // 0x1b071c: 0x8c23ffa8  lw          $v1, -0x58($at)
    ctx->pc = 0x1b071cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1b0720: 0x542023  subu        $a0, $v0, $s4
    ctx->pc = 0x1b0720u;
    SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1b0724: 0x480c0  sll         $s0, $a0, 3
    ctx->pc = 0x1b0724u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1b0728: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1b0728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b072c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1b072cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b0730: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1b0730u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b0734: 0x10620021  beq         $v1, $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x1B0734u;
    {
        const bool branch_taken_0x1b0734 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1B0738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0734u;
            // 0x1b0738: 0x141840  sll         $v1, $s4, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0734) {
            ctx->pc = 0x1B07BCu;
            goto label_1b07bc;
        }
    }
    ctx->pc = 0x1B073Cu;
    // 0x1b073c: 0x141040  sll         $v0, $s4, 1
    ctx->pc = 0x1b073cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x1b0740: 0x3c030032  lui         $v1, 0x32
    ctx->pc = 0x1b0740u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)50 << 16));
    // 0x1b0744: 0x542021  addu        $a0, $v0, $s4
    ctx->pc = 0x1b0744u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1b0748: 0x24634300  addiu       $v1, $v1, 0x4300
    ctx->pc = 0x1b0748u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17152));
    // 0x1b074c: 0x42100  sll         $a0, $a0, 4
    ctx->pc = 0x1b074cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1b0750: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b0750u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b0754: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b0754u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b0758: 0x24424240  addiu       $v0, $v0, 0x4240
    ctx->pc = 0x1b0758u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16960));
    // 0x1b075c: 0xac600008  sw          $zero, 0x8($v1)
    ctx->pc = 0x1b075cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 0));
    // 0x1b0760: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1b0760u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1b0764: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x1b0764u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1b0768: 0xac600004  sw          $zero, 0x4($v1)
    ctx->pc = 0x1b0768u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 0));
    // 0x1b076c: 0xa4600020  sh          $zero, 0x20($v1)
    ctx->pc = 0x1b076cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 32), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b0770: 0xa4600028  sh          $zero, 0x28($v1)
    ctx->pc = 0x1b0770u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 40), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b0774: 0xa4600022  sh          $zero, 0x22($v1)
    ctx->pc = 0x1b0774u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 34), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b0778: 0xa460002a  sh          $zero, 0x2A($v1)
    ctx->pc = 0x1b0778u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 42), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b077c: 0xa4600024  sh          $zero, 0x24($v1)
    ctx->pc = 0x1b077cu;
    WRITE16(ADD32(GPR_U32(ctx, 3), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b0780: 0xa4600026  sh          $zero, 0x26($v1)
    ctx->pc = 0x1b0780u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b0784: 0xa460002c  sh          $zero, 0x2C($v1)
    ctx->pc = 0x1b0784u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 44), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b0788: 0xa460002e  sh          $zero, 0x2E($v1)
    ctx->pc = 0x1b0788u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 46), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b078c: 0xac400008  sw          $zero, 0x8($v0)
    ctx->pc = 0x1b078cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 0));
    // 0x1b0790: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x1b0790u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    // 0x1b0794: 0xac400004  sw          $zero, 0x4($v0)
    ctx->pc = 0x1b0794u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 0));
    // 0x1b0798: 0xa4400020  sh          $zero, 0x20($v0)
    ctx->pc = 0x1b0798u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 32), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b079c: 0xa4400028  sh          $zero, 0x28($v0)
    ctx->pc = 0x1b079cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 40), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07a0: 0xa4400022  sh          $zero, 0x22($v0)
    ctx->pc = 0x1b07a0u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 34), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07a4: 0xa440002a  sh          $zero, 0x2A($v0)
    ctx->pc = 0x1b07a4u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 42), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07a8: 0xa4400024  sh          $zero, 0x24($v0)
    ctx->pc = 0x1b07a8u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07ac: 0xa4400026  sh          $zero, 0x26($v0)
    ctx->pc = 0x1b07acu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07b0: 0xa440002c  sh          $zero, 0x2C($v0)
    ctx->pc = 0x1b07b0u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 44), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07b4: 0xa440002e  sh          $zero, 0x2E($v0)
    ctx->pc = 0x1b07b4u;
    WRITE16(ADD32(GPR_U32(ctx, 2), 46), (uint16_t)GPR_U32(ctx, 0));
    // 0x1b07b8: 0x141840  sll         $v1, $s4, 1
    ctx->pc = 0x1b07b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
label_1b07bc:
    // 0x1b07bc: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b07bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b07c0: 0x741821  addu        $v1, $v1, $s4
    ctx->pc = 0x1b07c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 20)));
    // 0x1b07c4: 0x24424300  addiu       $v0, $v0, 0x4300
    ctx->pc = 0x1b07c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17152));
    // 0x1b07c8: 0x39100  sll         $s2, $v1, 4
    ctx->pc = 0x1b07c8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b07cc: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1b07ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1b07d0: 0x528821  addu        $s1, $v0, $s2
    ctx->pc = 0x1b07d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1b07d4: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x1b07d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1b07d8: 0xae220014  sw          $v0, 0x14($s1)
    ctx->pc = 0x1b07d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x1b07dc: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1b07dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b07e0: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x1b07e0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x1b07e4: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1b07e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b07e8: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x1b07e8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1b07ec: 0x8c22ffa8  lw          $v0, -0x58($at)
    ctx->pc = 0x1b07ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1b07f0: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1b07f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b07f4: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x1b07f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1b07f8: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1b07f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1b07fc: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x1b07fcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1b0800: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1b0800u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1b0804: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x1b0804u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x1b0808: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1b0808u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1b080c: 0x8462001c  lh          $v0, 0x1C($v1)
    ctx->pc = 0x1b080cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1b0810: 0xa6220024  sh          $v0, 0x24($s1)
    ctx->pc = 0x1b0810u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0814: 0x8462001e  lh          $v0, 0x1E($v1)
    ctx->pc = 0x1b0814u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 30)));
    // 0x1b0818: 0xa6220026  sh          $v0, 0x26($s1)
    ctx->pc = 0x1b0818u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b081c: 0x84620028  lh          $v0, 0x28($v1)
    ctx->pc = 0x1b081cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x1b0820: 0xa622002c  sh          $v0, 0x2C($s1)
    ctx->pc = 0x1b0820u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 44), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0824: 0x8462002a  lh          $v0, 0x2A($v1)
    ctx->pc = 0x1b0824u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 42)));
    // 0x1b0828: 0xa622002e  sh          $v0, 0x2E($s1)
    ctx->pc = 0x1b0828u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 46), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b082c: 0x84620020  lh          $v0, 0x20($v1)
    ctx->pc = 0x1b082cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1b0830: 0xa6220020  sh          $v0, 0x20($s1)
    ctx->pc = 0x1b0830u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 32), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0834: 0x8462002c  lh          $v0, 0x2C($v1)
    ctx->pc = 0x1b0834u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 44)));
    // 0x1b0838: 0xa6220028  sh          $v0, 0x28($s1)
    ctx->pc = 0x1b0838u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b083c: 0xc0647bc  jal         func_191EF0
    ctx->pc = 0x1B083Cu;
    SET_GPR_U32(ctx, 31, 0x1B0844u);
    ctx->pc = 0x1B0840u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B083Cu;
            // 0x1b0840: 0xc46c0024  lwc1        $f12, 0x24($v1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191EF0u;
    if (runtime->hasFunction(0x191EF0u)) {
        auto targetFn = runtime->lookupFunction(0x191EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0844u; }
        if (ctx->pc != 0x1B0844u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191EF0_0x191ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0844u; }
        if (ctx->pc != 0x1B0844u) { return; }
    }
    ctx->pc = 0x1B0844u;
label_1b0844:
    // 0x1b0844: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1b0844u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b0848: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1b0848u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1b084c: 0x2442c000  addiu       $v0, $v0, -0x4000
    ctx->pc = 0x1b084cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294950912));
    // 0x1b0850: 0xa6220022  sh          $v0, 0x22($s1)
    ctx->pc = 0x1b0850u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 34), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0854: 0x8c22ffa8  lw          $v0, -0x58($at)
    ctx->pc = 0x1b0854u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1b0858: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b0858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b085c: 0xc0647bc  jal         func_191EF0
    ctx->pc = 0x1B085Cu;
    SET_GPR_U32(ctx, 31, 0x1B0864u);
    ctx->pc = 0x1B0860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B085Cu;
            // 0x1b0860: 0xc44c0030  lwc1        $f12, 0x30($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191EF0u;
    if (runtime->hasFunction(0x191EF0u)) {
        auto targetFn = runtime->lookupFunction(0x191EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0864u; }
        if (ctx->pc != 0x1B0864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191EF0_0x191ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0864u; }
        if (ctx->pc != 0x1B0864u) { return; }
    }
    ctx->pc = 0x1B0864u;
label_1b0864:
    // 0x1b0864: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1b0864u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b0868: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b0868u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b086c: 0x2442c000  addiu       $v0, $v0, -0x4000
    ctx->pc = 0x1b086cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294950912));
    // 0x1b0870: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b0870u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0874: 0xa622002a  sh          $v0, 0x2A($s1)
    ctx->pc = 0x1b0874u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 42), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0878: 0xc06865c  jal         func_1A1970
    ctx->pc = 0x1B0878u;
    SET_GPR_U32(ctx, 31, 0x1B0880u);
    ctx->pc = 0x1B087Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0878u;
            // 0x1b087c: 0x27a60060  addiu       $a2, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1970u;
    if (runtime->hasFunction(0x1A1970u)) {
        auto targetFn = runtime->lookupFunction(0x1A1970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0880u; }
        if (ctx->pc != 0x1B0880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1970_0x1a1970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0880u; }
        if (ctx->pc != 0x1B0880u) { return; }
    }
    ctx->pc = 0x1B0880u;
label_1b0880:
    // 0x1b0880: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1b0880u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0884: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1b0884u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b0888: 0xc06865c  jal         func_1A1970
    ctx->pc = 0x1B0888u;
    SET_GPR_U32(ctx, 31, 0x1B0890u);
    ctx->pc = 0x1B088Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0888u;
            // 0x1b088c: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1970u;
    if (runtime->hasFunction(0x1A1970u)) {
        auto targetFn = runtime->lookupFunction(0x1A1970u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0890u; }
        if (ctx->pc != 0x1B0890u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1970_0x1a1970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0890u; }
        if (ctx->pc != 0x1B0890u) { return; }
    }
    ctx->pc = 0x1B0890u;
label_1b0890:
    // 0x1b0890: 0x3c020032  lui         $v0, 0x32
    ctx->pc = 0x1b0890u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)50 << 16));
    // 0x1b0894: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1b0894u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1b0898: 0x24424240  addiu       $v0, $v0, 0x4240
    ctx->pc = 0x1b0898u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16960));
    // 0x1b089c: 0x528821  addu        $s1, $v0, $s2
    ctx->pc = 0x1b089cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x1b08a0: 0x8e220010  lw          $v0, 0x10($s1)
    ctx->pc = 0x1b08a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1b08a4: 0xae220014  sw          $v0, 0x14($s1)
    ctx->pc = 0x1b08a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 2));
    // 0x1b08a8: 0x8e22000c  lw          $v0, 0xC($s1)
    ctx->pc = 0x1b08a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b08ac: 0xae220010  sw          $v0, 0x10($s1)
    ctx->pc = 0x1b08acu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x1b08b0: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x1b08b0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x1b08b4: 0xae22000c  sw          $v0, 0xC($s1)
    ctx->pc = 0x1b08b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 2));
    // 0x1b08b8: 0x8c22ffac  lw          $v0, -0x54($at)
    ctx->pc = 0x1b08b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967212)));
    // 0x1b08bc: 0x501821  addu        $v1, $v0, $s0
    ctx->pc = 0x1b08bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b08c0: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x1b08c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1b08c4: 0xae220008  sw          $v0, 0x8($s1)
    ctx->pc = 0x1b08c4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 2));
    // 0x1b08c8: 0x8c620010  lw          $v0, 0x10($v1)
    ctx->pc = 0x1b08c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1b08cc: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x1b08ccu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x1b08d0: 0x8c620014  lw          $v0, 0x14($v1)
    ctx->pc = 0x1b08d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x1b08d4: 0xae220004  sw          $v0, 0x4($s1)
    ctx->pc = 0x1b08d4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 2));
    // 0x1b08d8: 0x8462001c  lh          $v0, 0x1C($v1)
    ctx->pc = 0x1b08d8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1b08dc: 0xa6220024  sh          $v0, 0x24($s1)
    ctx->pc = 0x1b08dcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 36), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b08e0: 0x8462001e  lh          $v0, 0x1E($v1)
    ctx->pc = 0x1b08e0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 30)));
    // 0x1b08e4: 0xa6220026  sh          $v0, 0x26($s1)
    ctx->pc = 0x1b08e4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 38), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b08e8: 0x84620028  lh          $v0, 0x28($v1)
    ctx->pc = 0x1b08e8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 40)));
    // 0x1b08ec: 0xa622002c  sh          $v0, 0x2C($s1)
    ctx->pc = 0x1b08ecu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 44), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b08f0: 0x8462002a  lh          $v0, 0x2A($v1)
    ctx->pc = 0x1b08f0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 42)));
    // 0x1b08f4: 0xa622002e  sh          $v0, 0x2E($s1)
    ctx->pc = 0x1b08f4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 46), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b08f8: 0x84620020  lh          $v0, 0x20($v1)
    ctx->pc = 0x1b08f8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x1b08fc: 0xa6220020  sh          $v0, 0x20($s1)
    ctx->pc = 0x1b08fcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 32), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0900: 0x8462002c  lh          $v0, 0x2C($v1)
    ctx->pc = 0x1b0900u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 44)));
    // 0x1b0904: 0xa6220028  sh          $v0, 0x28($s1)
    ctx->pc = 0x1b0904u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 40), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0908: 0xc0647bc  jal         func_191EF0
    ctx->pc = 0x1B0908u;
    SET_GPR_U32(ctx, 31, 0x1B0910u);
    ctx->pc = 0x1B090Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0908u;
            // 0x1b090c: 0xc46c0024  lwc1        $f12, 0x24($v1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191EF0u;
    if (runtime->hasFunction(0x191EF0u)) {
        auto targetFn = runtime->lookupFunction(0x191EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0910u; }
        if (ctx->pc != 0x1B0910u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191EF0_0x191ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0910u; }
        if (ctx->pc != 0x1B0910u) { return; }
    }
    ctx->pc = 0x1B0910u;
label_1b0910:
    // 0x1b0910: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1b0910u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b0914: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1b0914u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1b0918: 0x2442c000  addiu       $v0, $v0, -0x4000
    ctx->pc = 0x1b0918u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294950912));
    // 0x1b091c: 0xa6220022  sh          $v0, 0x22($s1)
    ctx->pc = 0x1b091cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 34), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b0920: 0x8c22ffac  lw          $v0, -0x54($at)
    ctx->pc = 0x1b0920u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967212)));
    // 0x1b0924: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1b0924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1b0928: 0xc0647bc  jal         func_191EF0
    ctx->pc = 0x1B0928u;
    SET_GPR_U32(ctx, 31, 0x1B0930u);
    ctx->pc = 0x1B092Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0928u;
            // 0x1b092c: 0xc44c0030  lwc1        $f12, 0x30($v0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 48)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x191EF0u;
    if (runtime->hasFunction(0x191EF0u)) {
        auto targetFn = runtime->lookupFunction(0x191EF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0930u; }
        if (ctx->pc != 0x1B0930u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00191EF0_0x191ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0930u; }
        if (ctx->pc != 0x1B0930u) { return; }
    }
    ctx->pc = 0x1B0930u;
label_1b0930:
    // 0x1b0930: 0x3043ffff  andi        $v1, $v0, 0xFFFF
    ctx->pc = 0x1b0930u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1b0934: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x1b0934u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x1b0938: 0x2463c000  addiu       $v1, $v1, -0x4000
    ctx->pc = 0x1b0938u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294950912));
    // 0x1b093c: 0xa623002a  sh          $v1, 0x2A($s1)
    ctx->pc = 0x1b093cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 42), (uint16_t)GPR_U32(ctx, 3));
label_1b0940:
    // 0x1b0940: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b0940u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b0944: 0x802341f0  lb          $v1, 0x41F0($at)
    ctx->pc = 0x1b0944u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 16880)));
    // 0x1b0948: 0x283182a  slt         $v1, $s4, $v1
    ctx->pc = 0x1b0948u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1b094c: 0x1460ff72  bnez        $v1, . + 4 + (-0x8E << 2)
    ctx->pc = 0x1B094Cu;
    {
        const bool branch_taken_0x1b094c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B0950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B094Cu;
            // 0x1b0950: 0x3c01002b  lui         $at, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b094c) {
            ctx->pc = 0x1B0718u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0718;
        }
    }
    ctx->pc = 0x1B0954u;
    // 0x1b0954: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1b0954u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b0958: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b0958u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b095c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b095cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b0960: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b0960u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b0964: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b0964u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b0968: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b0968u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b096c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B096Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B096Cu;
            // 0x1b0970: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0718u: goto label_1b0718;
            case 0x1B07BCu: goto label_1b07bc;
            case 0x1B0844u: goto label_1b0844;
            case 0x1B0864u: goto label_1b0864;
            case 0x1B0880u: goto label_1b0880;
            case 0x1B0890u: goto label_1b0890;
            case 0x1B0910u: goto label_1b0910;
            case 0x1B0930u: goto label_1b0930;
            case 0x1B0940u: goto label_1b0940;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0974u;
    // 0x1b0974: 0x0  nop
    ctx->pc = 0x1b0974u;
    // NOP
    // 0x1b0978: 0x0  nop
    ctx->pc = 0x1b0978u;
    // NOP
    // 0x1b097c: 0x0  nop
    ctx->pc = 0x1b097cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
