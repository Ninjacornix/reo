#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128B18
// Address: 0x128b18 - 0x128f28
void sub_00128B18_0x128b18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128B18_0x128b18");
#endif

    switch (ctx->pc) {
        case 0x128b88u: goto label_128b88;
        case 0x128b9cu: goto label_128b9c;
        case 0x128c0cu: goto label_128c0c;
        case 0x128d58u: goto label_128d58;
        case 0x128d60u: goto label_128d60;
        case 0x128d90u: goto label_128d90;
        case 0x128dd0u: goto label_128dd0;
        case 0x128e24u: goto label_128e24;
        case 0x128e9cu: goto label_128e9c;
        case 0x128eacu: goto label_128eac;
        case 0x128ec8u: goto label_128ec8;
        case 0x128ed0u: goto label_128ed0;
        default: break;
    }

    ctx->pc = 0x128b18u;

    // 0x128b18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128b18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128b1c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128b1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x128b20: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128b20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128b24: 0x804a2cc  j           func_128B30
    ctx->pc = 0x128B24u;
    ctx->pc = 0x128B28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128B24u;
            // 0x128b28: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128B30u;
    goto label_128b30;
    ctx->pc = 0x128B2Cu;
    // 0x128b2c: 0x0  nop
    ctx->pc = 0x128b2cu;
    // NOP
label_128b30:
    // 0x128b30: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128b30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128b34: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x128b34u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x128b38: 0x8c43d234  lw          $v1, -0x2DCC($v0)
    ctx->pc = 0x128b38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294955572)));
    // 0x128b3c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x128b3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x128b40: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x128b40u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128b44: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x128b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x128b48: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x128b48u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128b4c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x128b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x128b50: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x128b50u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128b54: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x128b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x128b58: 0xf02d  daddu       $fp, $zero, $zero
    ctx->pc = 0x128b58u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128b5c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x128b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x128b60: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x128b60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x128b64: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x128b64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x128b68: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x128b68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x128b6c: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x128b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x128b70: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x128b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x128b74: 0x12030006  beq         $s0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x128B74u;
    {
        const bool branch_taken_0x128b74 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        ctx->pc = 0x128B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128B74u;
            // 0x128b78: 0xafa00000  sw          $zero, 0x0($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128b74) {
            ctx->pc = 0x128B90u;
            goto label_128b90;
        }
    }
    ctx->pc = 0x128B7Cu;
    // 0x128b7c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x128b7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x128b80: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x128B80u;
    SET_GPR_U32(ctx, 31, 0x128B88u);
    ctx->pc = 0x128B84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128B80u;
            // 0x128b84: 0x24849d88  addiu       $a0, $a0, -0x6278 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128B88u; }
        if (ctx->pc != 0x128B88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128B88u; }
        if (ctx->pc != 0x128B88u) { return; }
    }
    ctx->pc = 0x128B88u;
label_128b88:
    // 0x128b88: 0x100000d5  b           . + 4 + (0xD5 << 2)
    ctx->pc = 0x128B88u;
    {
        const bool branch_taken_0x128b88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128B8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128B88u;
            // 0x128b8c: 0x2402fffd  addiu       $v0, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128b88) {
            ctx->pc = 0x128EE0u;
            goto label_128ee0;
        }
    }
    ctx->pc = 0x128B90u;
label_128b90:
    // 0x128b90: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128b90u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x128b94: 0xc04a752  jal         func_129D48
    ctx->pc = 0x128B94u;
    SET_GPR_U32(ctx, 31, 0x128B9Cu);
    ctx->pc = 0x128B98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128B94u;
            // 0x128b98: 0x8c44d230  lw          $a0, -0x2DD0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294955568)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128B9Cu; }
        if (ctx->pc != 0x128B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128B9Cu; }
        if (ctx->pc != 0x128B9Cu) { return; }
    }
    ctx->pc = 0x128B9Cu;
label_128b9c:
    // 0x128b9c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x128b9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x128ba0: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x128ba0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128ba4: 0x56c300cf  bnel        $s6, $v1, . + 4 + (0xCF << 2)
    ctx->pc = 0x128BA4u;
    {
        const bool branch_taken_0x128ba4 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 3));
        if (branch_taken_0x128ba4) {
            ctx->pc = 0x128BA8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128BA4u;
            // 0x128ba8: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128EE4u;
            goto label_128ee4;
        }
    }
    ctx->pc = 0x128BACu;
    // 0x128bac: 0x101080  sll         $v0, $s0, 2
    ctx->pc = 0x128bacu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x128bb0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x128bb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128bb4: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x128bb4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x128bb8: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x128bb8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x128bbc: 0x8e10cd00  lw          $s0, -0x3300($s0)
    ctx->pc = 0x128bbcu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4294954240)));
    // 0x128bc0: 0x8203000f  lb          $v1, 0xF($s0)
    ctx->pc = 0x128bc0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 15)));
    // 0x128bc4: 0x14640004  bne         $v1, $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x128BC4u;
    {
        const bool branch_taken_0x128bc4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x128BC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128BC4u;
            // 0x128bc8: 0x2603011a  addiu       $v1, $s0, 0x11A (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 282));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128bc4) {
            ctx->pc = 0x128BD8u;
            goto label_128bd8;
        }
    }
    ctx->pc = 0x128BCCu;
    // 0x128bcc: 0x26130118  addiu       $s3, $s0, 0x118
    ctx->pc = 0x128bccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 280));
    // 0x128bd0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x128BD0u;
    {
        const bool branch_taken_0x128bd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128BD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128BD0u;
            // 0x128bd4: 0x261e011c  addiu       $fp, $s0, 0x11C (Delay Slot)
        SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 16), 284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128bd0) {
            ctx->pc = 0x128BE0u;
            goto label_128be0;
        }
    }
    ctx->pc = 0x128BD8u;
label_128bd8:
    // 0x128bd8: 0x26140118  addiu       $s4, $s0, 0x118
    ctx->pc = 0x128bd8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 280));
    // 0x128bdc: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x128bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
label_128be0:
    // 0x128be0: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x128be0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x128be4: 0x14400060  bnez        $v0, . + 4 + (0x60 << 2)
    ctx->pc = 0x128BE4u;
    {
        const bool branch_taken_0x128be4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x128BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128BE4u;
            // 0x128be8: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128be4) {
            ctx->pc = 0x128D68u;
            goto label_128d68;
        }
    }
    ctx->pc = 0x128BECu;
    // 0x128bec: 0x3c170021  lui         $s7, 0x21
    ctx->pc = 0x128becu;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)33 << 16));
    // 0x128bf0: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x128bf0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x128bf4: 0x26f1d238  addiu       $s1, $s7, -0x2DC8
    ctx->pc = 0x128bf4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 23), 4294955576));
    // 0x128bf8: 0x24a59dc0  addiu       $a1, $a1, -0x6240
    ctx->pc = 0x128bf8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294942144));
    // 0x128bfc: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x128bfcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x128c00: 0x24060003  addiu       $a2, $zero, 0x3
    ctx->pc = 0x128c00u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x128c04: 0xc041e86  jal         func_107A18
    ctx->pc = 0x128C04u;
    SET_GPR_U32(ctx, 31, 0x128C0Cu);
    ctx->pc = 0x128C08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128C04u;
            // 0x128c08: 0x2e0902d  daddu       $s2, $s7, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128C0Cu; }
        if (ctx->pc != 0x128C0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128C0Cu; }
        if (ctx->pc != 0x128C0Cu) { return; }
    }
    ctx->pc = 0x128C0Cu;
label_128c0c:
    // 0x128c0c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x128C0Cu;
    {
        const bool branch_taken_0x128c0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x128C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128C0Cu;
            // 0x128c10: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128c0c) {
            ctx->pc = 0x128C20u;
            goto label_128c20;
        }
    }
    ctx->pc = 0x128C14u;
    // 0x128c14: 0x100000aa  b           . + 4 + (0xAA << 2)
    ctx->pc = 0x128C14u;
    {
        const bool branch_taken_0x128c14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128C14u;
            // 0x128c18: 0x24849dc8  addiu       $a0, $a0, -0x6238 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942152));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128c14) {
            ctx->pc = 0x128EC0u;
            goto label_128ec0;
        }
    }
    ctx->pc = 0x128C1Cu;
    // 0x128c1c: 0x0  nop
    ctx->pc = 0x128c1cu;
    // NOP
label_128c20:
    // 0x128c20: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x128c20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x128c24: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x128c24u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x128c28: 0x24480005  addiu       $t0, $v0, 0x5
    ctx->pc = 0x128c28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 2), 5));
    // 0x128c2c: 0x90450007  lbu         $a1, 0x7($v0)
    ctx->pc = 0x128c2cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 7)));
    // 0x128c30: 0x90430006  lbu         $v1, 0x6($v0)
    ctx->pc = 0x128c30u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x128c34: 0x24470004  addiu       $a3, $v0, 0x4
    ctx->pc = 0x128c34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 2), 4));
    // 0x128c38: 0x91040000  lbu         $a0, 0x0($t0)
    ctx->pc = 0x128c38u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x128c3c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x128c3cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x128c40: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x128c40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x128c44: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x128c44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x128c48: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x128c48u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x128c4c: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x128c4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x128c50: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x128c50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x128c54: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x128c54u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x128c58: 0xc2302a  slt         $a2, $a2, $v0
    ctx->pc = 0x128c58u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x128c5c: 0x10c00004  beqz        $a2, . + 4 + (0x4 << 2)
    ctx->pc = 0x128C5Cu;
    {
        const bool branch_taken_0x128c5c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x128C60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128C5Cu;
            // 0x128c60: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128c5c) {
            ctx->pc = 0x128C70u;
            goto label_128c70;
        }
    }
    ctx->pc = 0x128C64u;
    // 0x128c64: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x128c64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x128c68: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x128C68u;
    {
        const bool branch_taken_0x128c68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128C68u;
            // 0x128c6c: 0x24849e00  addiu       $a0, $a0, -0x6200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942208));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128c68) {
            ctx->pc = 0x128EC0u;
            goto label_128ec0;
        }
    }
    ctx->pc = 0x128C70u;
label_128c70:
    // 0x128c70: 0x91020000  lbu         $v0, 0x0($t0)
    ctx->pc = 0x128c70u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x128c74: 0x90e30000  lbu         $v1, 0x0($a3)
    ctx->pc = 0x128c74u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x128c78: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x128c78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x128c7c: 0x8204000f  lb          $a0, 0xF($s0)
    ctx->pc = 0x128c7cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 15)));
    // 0x128c80: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x128c80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x128c84: 0x9205000f  lbu         $a1, 0xF($s0)
    ctx->pc = 0x128c84u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 15)));
    // 0x128c88: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x128c88u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128c8c: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x128c8cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x128c90: 0x14910005  bne         $a0, $s1, . + 4 + (0x5 << 2)
    ctx->pc = 0x128C90u;
    {
        const bool branch_taken_0x128c90 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 17));
        ctx->pc = 0x128C94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128C90u;
            // 0x128c94: 0xae020008  sw          $v0, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128c90) {
            ctx->pc = 0x128CA8u;
            goto label_128ca8;
        }
    }
    ctx->pc = 0x128C98u;
    // 0x128c98: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x128c98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x128c9c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x128C9Cu;
    {
        const bool branch_taken_0x128c9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128C9Cu;
            // 0x128ca0: 0x24420120  addiu       $v0, $v0, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 288));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128c9c) {
            ctx->pc = 0x128CB8u;
            goto label_128cb8;
        }
    }
    ctx->pc = 0x128CA4u;
    // 0x128ca4: 0x0  nop
    ctx->pc = 0x128ca4u;
    // NOP
label_128ca8:
    // 0x128ca8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x128ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x128cac: 0x2442011c  addiu       $v0, $v0, 0x11C
    ctx->pc = 0x128cacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 284));
    // 0x128cb0: 0x21082  srl         $v0, $v0, 2
    ctx->pc = 0x128cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 2));
    // 0x128cb4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x128cb4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
label_128cb8:
    // 0x128cb8: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x128cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x128cbc: 0x51600  sll         $v0, $a1, 24
    ctx->pc = 0x128cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x128cc0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x128cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128cc4: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x128cc4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x128cc8: 0x14430011  bne         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x128CC8u;
    {
        const bool branch_taken_0x128cc8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x128CCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128CC8u;
            // 0x128ccc: 0x8e43d238  lw          $v1, -0x2DC8($s2) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4294955576)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128cc8) {
            ctx->pc = 0x128D10u;
            goto label_128d10;
        }
    }
    ctx->pc = 0x128CD0u;
    // 0x128cd0: 0x90660009  lbu         $a2, 0x9($v1)
    ctx->pc = 0x128cd0u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 9)));
    // 0x128cd4: 0x9065000b  lbu         $a1, 0xB($v1)
    ctx->pc = 0x128cd4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 11)));
    // 0x128cd8: 0x9064000a  lbu         $a0, 0xA($v1)
    ctx->pc = 0x128cd8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 10)));
    // 0x128cdc: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x128cdcu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x128ce0: 0x90620008  lbu         $v0, 0x8($v1)
    ctx->pc = 0x128ce0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x128ce4: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x128ce4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x128ce8: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x128ce8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x128cec: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x128cecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x128cf0: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x128cf0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x128cf4: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x128cf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x128cf8: 0x244507ff  addiu       $a1, $v0, 0x7FF
    ctx->pc = 0x128cf8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x128cfc: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x128cfcu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x128d00: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x128d00u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x128d04: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x128d04u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x128d08: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x128D08u;
    {
        const bool branch_taken_0x128d08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128D0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128D08u;
            // 0x128d0c: 0xae620000  sw          $v0, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128d08) {
            ctx->pc = 0x128D4Cu;
            goto label_128d4c;
        }
    }
    ctx->pc = 0x128D10u;
label_128d10:
    // 0x128d10: 0x90660009  lbu         $a2, 0x9($v1)
    ctx->pc = 0x128d10u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 9)));
    // 0x128d14: 0x9065000b  lbu         $a1, 0xB($v1)
    ctx->pc = 0x128d14u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 11)));
    // 0x128d18: 0x9064000a  lbu         $a0, 0xA($v1)
    ctx->pc = 0x128d18u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 10)));
    // 0x128d1c: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x128d1cu;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x128d20: 0x90620008  lbu         $v0, 0x8($v1)
    ctx->pc = 0x128d20u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x128d24: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x128d24u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x128d28: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x128d28u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x128d2c: 0x451025  or          $v0, $v0, $a1
    ctx->pc = 0x128d2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x128d30: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x128d30u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x128d34: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x128d34u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x128d38: 0x244507ff  addiu       $a1, $v0, 0x7FF
    ctx->pc = 0x128d38u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 2047));
    // 0x128d3c: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x128d3cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x128d40: 0xa3100b  movn        $v0, $a1, $v1
    ctx->pc = 0x128d40u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x128d44: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x128d44u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x128d48: 0xa6820000  sh          $v0, 0x0($s4)
    ctx->pc = 0x128d48u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 2));
label_128d4c:
    // 0x128d4c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x128D4Cu;
    {
        const bool branch_taken_0x128d4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128D50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128D4Cu;
            // 0x128d50: 0x24110003  addiu       $s1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128d4c) {
            ctx->pc = 0x128D6Cu;
            goto label_128d6c;
        }
    }
    ctx->pc = 0x128D54u;
    // 0x128d54: 0x0  nop
    ctx->pc = 0x128d54u;
    // NOP
label_128d58:
    // 0x128d58: 0xc04a298  jal         func_128A60
    ctx->pc = 0x128D58u;
    SET_GPR_U32(ctx, 31, 0x128D60u);
    ctx->pc = 0x128D5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128D58u;
            // 0x128d5c: 0x24160003  addiu       $s6, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128A60u;
    if (runtime->hasFunction(0x128A60u)) {
        auto targetFn = runtime->lookupFunction(0x128A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128D60u; }
        if (ctx->pc != 0x128D60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128A60_0x128a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128D60u; }
        if (ctx->pc != 0x128D60u) { return; }
    }
    ctx->pc = 0x128D60u;
label_128d60:
    // 0x128d60: 0x10000045  b           . + 4 + (0x45 << 2)
    ctx->pc = 0x128D60u;
    {
        const bool branch_taken_0x128d60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x128d60) {
            ctx->pc = 0x128E78u;
            goto label_128e78;
        }
    }
    ctx->pc = 0x128D68u;
label_128d68:
    // 0x128d68: 0x3c170021  lui         $s7, 0x21
    ctx->pc = 0x128d68u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)33 << 16));
label_128d6c:
    // 0x128d6c: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x128d6cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x128d70: 0x8cc2d23c  lw          $v0, -0x2DC4($a2)
    ctx->pc = 0x128d70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4294955580)));
    // 0x128d74: 0x2a240  sll         $s4, $v0, 9
    ctx->pc = 0x128d74u;
    SET_GPR_S32(ctx, 20, (int32_t)SLL32(GPR_U32(ctx, 2), 9));
    // 0x128d78: 0x234982a  slt         $s3, $s1, $s4
    ctx->pc = 0x128d78u;
    SET_GPR_U64(ctx, 19, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x128d7c: 0x12600041  beqz        $s3, . + 4 + (0x41 << 2)
    ctx->pc = 0x128D7Cu;
    {
        const bool branch_taken_0x128d7c = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x128D80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128D7Cu;
            // 0x128d80: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128d7c) {
            ctx->pc = 0x128E84u;
            goto label_128e84;
        }
    }
    ctx->pc = 0x128D84u;
    // 0x128d84: 0x3c150021  lui         $s5, 0x21
    ctx->pc = 0x128d84u;
    SET_GPR_S32(ctx, 21, (int32_t)((uint32_t)33 << 16));
    // 0x128d88: 0x26b2d22c  addiu       $s2, $s5, -0x2DD4
    ctx->pc = 0x128d88u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 21), 4294955564));
    // 0x128d8c: 0x8203000f  lb          $v1, 0xF($s0)
    ctx->pc = 0x128d8cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 15)));
label_128d90:
    // 0x128d90: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x128d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x128d94: 0x14620016  bne         $v1, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x128D94u;
    {
        const bool branch_taken_0x128d94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x128D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128D94u;
            // 0x128d98: 0x8ee3d238  lw          $v1, -0x2DC8($s7) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 4294955576)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128d94) {
            ctx->pc = 0x128DF0u;
            goto label_128df0;
        }
    }
    ctx->pc = 0x128D9Cu;
    // 0x128d9c: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x128d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x128da0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x128da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x128da4: 0x90460001  lbu         $a2, 0x1($v0)
    ctx->pc = 0x128da4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x128da8: 0x90450003  lbu         $a1, 0x3($v0)
    ctx->pc = 0x128da8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x128dac: 0x90440002  lbu         $a0, 0x2($v0)
    ctx->pc = 0x128dacu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x128db0: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x128db0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x128db4: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x128db4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x128db8: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x128db8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x128dbc: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x128dbcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x128dc0: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x128dc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x128dc4: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x128dc4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x128dc8: 0xc04a134  jal         func_1284D0
    ctx->pc = 0x128DC8u;
    SET_GPR_U32(ctx, 31, 0x128DD0u);
    ctx->pc = 0x128DCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128DC8u;
            // 0x128dcc: 0x642025  or          $a0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284D0u;
    if (runtime->hasFunction(0x1284D0u)) {
        auto targetFn = runtime->lookupFunction(0x1284D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128DD0u; }
        if (ctx->pc != 0x128DD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284D0_0x1284d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128DD0u; }
        if (ctx->pc != 0x128DD0u) { return; }
    }
    ctx->pc = 0x128DD0u;
label_128dd0:
    // 0x128dd0: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x128dd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128dd4: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x128dd4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x128dd8: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x128dd8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x128ddc: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x128ddcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x128de0: 0x7e1821  addu        $v1, $v1, $fp
    ctx->pc = 0x128de0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
    // 0x128de4: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x128de4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x128de8: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x128DE8u;
    {
        const bool branch_taken_0x128de8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128DECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128DE8u;
            // 0x128dec: 0xae440000  sw          $a0, 0x0($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128de8) {
            ctx->pc = 0x128E54u;
            goto label_128e54;
        }
    }
    ctx->pc = 0x128DF0u;
label_128df0:
    // 0x128df0: 0x111080  sll         $v0, $s1, 2
    ctx->pc = 0x128df0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x128df4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x128df4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x128df8: 0x90460001  lbu         $a2, 0x1($v0)
    ctx->pc = 0x128df8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x128dfc: 0x90450003  lbu         $a1, 0x3($v0)
    ctx->pc = 0x128dfcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 3)));
    // 0x128e00: 0x90440002  lbu         $a0, 0x2($v0)
    ctx->pc = 0x128e00u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2)));
    // 0x128e04: 0x63200  sll         $a2, $a2, 8
    ctx->pc = 0x128e04u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 8));
    // 0x128e08: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x128e08u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x128e0c: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x128e0cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x128e10: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x128e10u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x128e14: 0x651825  or          $v1, $v1, $a1
    ctx->pc = 0x128e14u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x128e18: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x128e18u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x128e1c: 0xc04a134  jal         func_1284D0
    ctx->pc = 0x128E1Cu;
    SET_GPR_U32(ctx, 31, 0x128E24u);
    ctx->pc = 0x128E20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128E1Cu;
            // 0x128e20: 0x642025  or          $a0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1284D0u;
    if (runtime->hasFunction(0x1284D0u)) {
        auto targetFn = runtime->lookupFunction(0x1284D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128E24u; }
        if (ctx->pc != 0x128E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001284D0_0x1284d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128E24u; }
        if (ctx->pc != 0x128E24u) { return; }
    }
    ctx->pc = 0x128E24u;
label_128e24:
    // 0x128e24: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x128e24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128e28: 0x3c02ffff  lui         $v0, 0xFFFF
    ctx->pc = 0x128e28u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65535 << 16));
    // 0x128e2c: 0x821024  and         $v0, $a0, $v0
    ctx->pc = 0x128e2cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & GPR_U64(ctx, 2));
    // 0x128e30: 0x14400021  bnez        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x128E30u;
    {
        const bool branch_taken_0x128e30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x128E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128E30u;
            // 0x128e34: 0x2a0282d  daddu       $a1, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128e30) {
            ctx->pc = 0x128EB8u;
            goto label_128eb8;
        }
    }
    ctx->pc = 0x128E38u;
    // 0x128e38: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x128e38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x128e3c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x128e3cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128e40: 0x31040  sll         $v0, $v1, 1
    ctx->pc = 0x128e40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x128e44: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x128e44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x128e48: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x128e48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x128e4c: 0xa4440000  sh          $a0, 0x0($v0)
    ctx->pc = 0x128e4cu;
    WRITE16(ADD32(GPR_U32(ctx, 2), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x128e50: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x128e50u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_128e54:
    // 0x128e54: 0x8ca2d22c  lw          $v0, -0x2DD4($a1)
    ctx->pc = 0x128e54u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 4294955564)));
    // 0x128e58: 0x8e030008  lw          $v1, 0x8($s0)
    ctx->pc = 0x128e58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x128e5c: 0x43102a  slt         $v0, $v0, $v1
    ctx->pc = 0x128e5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x128e60: 0x1040ffbd  beqz        $v0, . + 4 + (-0x43 << 2)
    ctx->pc = 0x128E60u;
    {
        const bool branch_taken_0x128e60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x128e60) {
            ctx->pc = 0x128D58u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_128d58;
        }
    }
    ctx->pc = 0x128E68u;
    // 0x128e68: 0x26310002  addiu       $s1, $s1, 0x2
    ctx->pc = 0x128e68u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 2));
    // 0x128e6c: 0x234982a  slt         $s3, $s1, $s4
    ctx->pc = 0x128e6cu;
    SET_GPR_U64(ctx, 19, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x128e70: 0x5660ffc7  bnel        $s3, $zero, . + 4 + (-0x39 << 2)
    ctx->pc = 0x128E70u;
    {
        const bool branch_taken_0x128e70 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        if (branch_taken_0x128e70) {
            ctx->pc = 0x128E74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128E70u;
            // 0x128e74: 0x8203000f  lb          $v1, 0xF($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 15)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128D90u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_128d90;
        }
    }
    ctx->pc = 0x128E78u;
label_128e78:
    // 0x128e78: 0x16600019  bnez        $s3, . + 4 + (0x19 << 2)
    ctx->pc = 0x128E78u;
    {
        const bool branch_taken_0x128e78 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x128E7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128E78u;
            // 0x128e7c: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128e78) {
            ctx->pc = 0x128EE0u;
            goto label_128ee0;
        }
    }
    ctx->pc = 0x128E80u;
    // 0x128e80: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x128e80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
label_128e84:
    // 0x128e84: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128e84u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128e88: 0x2450d230  addiu       $s0, $v0, -0x2DD0
    ctx->pc = 0x128e88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294955568));
    // 0x128e8c: 0x8c65d23c  lw          $a1, -0x2DC4($v1)
    ctx->pc = 0x128e8cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294955580)));
    // 0x128e90: 0x8ee6d238  lw          $a2, -0x2DC8($s7)
    ctx->pc = 0x128e90u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 4294955576)));
    // 0x128e94: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x128E94u;
    SET_GPR_U32(ctx, 31, 0x128E9Cu);
    ctx->pc = 0x128E98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128E94u;
            // 0x128e98: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128E9Cu; }
        if (ctx->pc != 0x128E9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128E9Cu; }
        if (ctx->pc != 0x128E9Cu) { return; }
    }
    ctx->pc = 0x128E9Cu;
label_128e9c:
    // 0x128e9c: 0x443000e  bgezl       $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x128E9Cu;
    {
        const bool branch_taken_0x128e9c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x128e9c) {
            ctx->pc = 0x128EA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x128E9Cu;
            // 0x128ea0: 0x8e020000  lw          $v0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x128ED8u;
            goto label_128ed8;
        }
    }
    ctx->pc = 0x128EA4u;
    // 0x128ea4: 0xc04a298  jal         func_128A60
    ctx->pc = 0x128EA4u;
    SET_GPR_U32(ctx, 31, 0x128EACu);
    ctx->pc = 0x128EA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128EA4u;
            // 0x128ea8: 0x24160004  addiu       $s6, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128A60u;
    if (runtime->hasFunction(0x128A60u)) {
        auto targetFn = runtime->lookupFunction(0x128A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128EACu; }
        if (ctx->pc != 0x128EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128A60_0x128a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128EACu; }
        if (ctx->pc != 0x128EACu) { return; }
    }
    ctx->pc = 0x128EACu;
label_128eac:
    // 0x128eac: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x128EACu;
    {
        const bool branch_taken_0x128eac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128EB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128EACu;
            // 0x128eb0: 0x2c0102d  daddu       $v0, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128eac) {
            ctx->pc = 0x128EE0u;
            goto label_128ee0;
        }
    }
    ctx->pc = 0x128EB4u;
    // 0x128eb4: 0x0  nop
    ctx->pc = 0x128eb4u;
    // NOP
label_128eb8:
    // 0x128eb8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x128eb8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x128ebc: 0x24849e38  addiu       $a0, $a0, -0x61C8
    ctx->pc = 0x128ebcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942264));
label_128ec0:
    // 0x128ec0: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x128EC0u;
    SET_GPR_U32(ctx, 31, 0x128EC8u);
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128EC8u; }
        if (ctx->pc != 0x128EC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128EC8u; }
        if (ctx->pc != 0x128EC8u) { return; }
    }
    ctx->pc = 0x128EC8u;
label_128ec8:
    // 0x128ec8: 0xc04a298  jal         func_128A60
    ctx->pc = 0x128EC8u;
    SET_GPR_U32(ctx, 31, 0x128ED0u);
    ctx->pc = 0x128A60u;
    if (runtime->hasFunction(0x128A60u)) {
        auto targetFn = runtime->lookupFunction(0x128A60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128ED0u; }
        if (ctx->pc != 0x128ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128A60_0x128a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128ED0u; }
        if (ctx->pc != 0x128ED0u) { return; }
    }
    ctx->pc = 0x128ED0u;
label_128ed0:
    // 0x128ed0: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x128ED0u;
    {
        const bool branch_taken_0x128ed0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128ED4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128ED0u;
            // 0x128ed4: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128ed0) {
            ctx->pc = 0x128EE0u;
            goto label_128ee0;
        }
    }
    ctx->pc = 0x128ED8u;
label_128ed8:
    // 0x128ed8: 0x80560001  lb          $s6, 0x1($v0)
    ctx->pc = 0x128ed8u;
    SET_GPR_S32(ctx, 22, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 1)));
    // 0x128edc: 0x2c0102d  daddu       $v0, $s6, $zero
    ctx->pc = 0x128edcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
label_128ee0:
    // 0x128ee0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x128ee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_128ee4:
    // 0x128ee4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x128ee4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x128ee8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x128ee8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x128eec: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x128eecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x128ef0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x128ef0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x128ef4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x128ef4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x128ef8: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x128ef8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x128efc: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x128efcu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x128f00: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x128f00u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x128f04: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x128f04u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x128f08: 0x3e00008  jr          $ra
    ctx->pc = 0x128F08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F08u;
            // 0x128f0c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128B30u: goto label_128b30;
            case 0x128B88u: goto label_128b88;
            case 0x128B90u: goto label_128b90;
            case 0x128B9Cu: goto label_128b9c;
            case 0x128BD8u: goto label_128bd8;
            case 0x128BE0u: goto label_128be0;
            case 0x128C0Cu: goto label_128c0c;
            case 0x128C20u: goto label_128c20;
            case 0x128C70u: goto label_128c70;
            case 0x128CA8u: goto label_128ca8;
            case 0x128CB8u: goto label_128cb8;
            case 0x128D10u: goto label_128d10;
            case 0x128D4Cu: goto label_128d4c;
            case 0x128D58u: goto label_128d58;
            case 0x128D60u: goto label_128d60;
            case 0x128D68u: goto label_128d68;
            case 0x128D6Cu: goto label_128d6c;
            case 0x128D90u: goto label_128d90;
            case 0x128DD0u: goto label_128dd0;
            case 0x128DF0u: goto label_128df0;
            case 0x128E24u: goto label_128e24;
            case 0x128E54u: goto label_128e54;
            case 0x128E78u: goto label_128e78;
            case 0x128E84u: goto label_128e84;
            case 0x128E9Cu: goto label_128e9c;
            case 0x128EACu: goto label_128eac;
            case 0x128EB8u: goto label_128eb8;
            case 0x128EC0u: goto label_128ec0;
            case 0x128EC8u: goto label_128ec8;
            case 0x128ED0u: goto label_128ed0;
            case 0x128ED8u: goto label_128ed8;
            case 0x128EE0u: goto label_128ee0;
            case 0x128EE4u: goto label_128ee4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128F10u;
    // 0x128f10: 0x42080  sll         $a0, $a0, 2
    ctx->pc = 0x128f10u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x128f14: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x128f14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x128f18: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x128f18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x128f1c: 0x8c63cd00  lw          $v1, -0x3300($v1)
    ctx->pc = 0x128f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294954240)));
    // 0x128f20: 0x3e00008  jr          $ra
    ctx->pc = 0x128F20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128F20u;
            // 0x128f24: 0x8c620004  lw          $v0, 0x4($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128B30u: goto label_128b30;
            case 0x128B88u: goto label_128b88;
            case 0x128B90u: goto label_128b90;
            case 0x128B9Cu: goto label_128b9c;
            case 0x128BD8u: goto label_128bd8;
            case 0x128BE0u: goto label_128be0;
            case 0x128C0Cu: goto label_128c0c;
            case 0x128C20u: goto label_128c20;
            case 0x128C70u: goto label_128c70;
            case 0x128CA8u: goto label_128ca8;
            case 0x128CB8u: goto label_128cb8;
            case 0x128D10u: goto label_128d10;
            case 0x128D4Cu: goto label_128d4c;
            case 0x128D58u: goto label_128d58;
            case 0x128D60u: goto label_128d60;
            case 0x128D68u: goto label_128d68;
            case 0x128D6Cu: goto label_128d6c;
            case 0x128D90u: goto label_128d90;
            case 0x128DD0u: goto label_128dd0;
            case 0x128DF0u: goto label_128df0;
            case 0x128E24u: goto label_128e24;
            case 0x128E54u: goto label_128e54;
            case 0x128E78u: goto label_128e78;
            case 0x128E84u: goto label_128e84;
            case 0x128E9Cu: goto label_128e9c;
            case 0x128EACu: goto label_128eac;
            case 0x128EB8u: goto label_128eb8;
            case 0x128EC0u: goto label_128ec0;
            case 0x128EC8u: goto label_128ec8;
            case 0x128ED0u: goto label_128ed0;
            case 0x128ED8u: goto label_128ed8;
            case 0x128EE0u: goto label_128ee0;
            case 0x128EE4u: goto label_128ee4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128F28u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
