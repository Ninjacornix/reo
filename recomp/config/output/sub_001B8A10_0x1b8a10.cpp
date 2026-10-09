#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B8A10
// Address: 0x1b8a10 - 0x1b8b20
void sub_001B8A10_0x1b8a10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B8A10_0x1b8a10");
#endif

    switch (ctx->pc) {
        case 0x1b8a2cu: goto label_1b8a2c;
        case 0x1b8a4cu: goto label_1b8a4c;
        case 0x1b8af4u: goto label_1b8af4;
        case 0x1b8b08u: goto label_1b8b08;
        default: break;
    }

    ctx->pc = 0x1b8a10u;

label_1b8a10:
    // 0x1b8a10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8a10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8a14: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1b8a14u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8a18: 0x14e00006  bnez        $a3, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B8A18u;
    {
        const bool branch_taken_0x1b8a18 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B8A1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A18u;
            // 0x1b8a1c: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8a18) {
            ctx->pc = 0x1B8A34u;
            goto label_1b8a34;
        }
    }
    ctx->pc = 0x1B8A20u;
    // 0x1b8a20: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b8a20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8a24: 0xc06e4ec  jal         func_1B93B0
    ctx->pc = 0x1B8A24u;
    SET_GPR_U32(ctx, 31, 0x1B8A2Cu);
    ctx->pc = 0x1B8A28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A24u;
            // 0x1b8a28: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93B0u;
    if (runtime->hasFunction(0x1B93B0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8A2Cu; }
        if (ctx->pc != 0x1B8A2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93B0_0x1b93b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8A2Cu; }
        if (ctx->pc != 0x1B8A2Cu) { return; }
    }
    ctx->pc = 0x1B8A2Cu;
label_1b8a2c:
    // 0x1b8a2c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B8A2Cu;
    {
        const bool branch_taken_0x1b8a2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A2Cu;
            // 0x1b8a30: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8a2c) {
            ctx->pc = 0x1B8A50u;
            goto label_1b8a50;
        }
    }
    ctx->pc = 0x1B8A34u;
label_1b8a34:
    // 0x1b8a34: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b8a34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b8a38: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b8a38u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8a3c: 0x80402d  daddu       $t0, $a0, $zero
    ctx->pc = 0x1b8a3cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8a40: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x1b8a40u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b8a44: 0xc06e4f4  jal         func_1B93D0
    ctx->pc = 0x1B8A44u;
    SET_GPR_U32(ctx, 31, 0x1B8A4Cu);
    ctx->pc = 0x1B8A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A44u;
            // 0x1b8a48: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B93D0u;
    if (runtime->hasFunction(0x1B93D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B93D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8A4Cu; }
        if (ctx->pc != 0x1B8A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B93D0_0x1b93d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8A4Cu; }
        if (ctx->pc != 0x1B8A4Cu) { return; }
    }
    ctx->pc = 0x1B8A4Cu;
label_1b8a4c:
    // 0x1b8a4c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8a4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b8a50:
    // 0x1b8a50: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8A50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8A50u;
            // 0x1b8a54: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8A10u: goto label_1b8a10;
            case 0x1B8A2Cu: goto label_1b8a2c;
            case 0x1B8A34u: goto label_1b8a34;
            case 0x1B8A4Cu: goto label_1b8a4c;
            case 0x1B8A50u: goto label_1b8a50;
            case 0x1B8AE4u: goto label_1b8ae4;
            case 0x1B8AF4u: goto label_1b8af4;
            case 0x1B8AFCu: goto label_1b8afc;
            case 0x1B8B08u: goto label_1b8b08;
            case 0x1B8B0Cu: goto label_1b8b0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8A58u;
    // 0x1b8a58: 0x0  nop
    ctx->pc = 0x1b8a58u;
    // NOP
    // 0x1b8a5c: 0x0  nop
    ctx->pc = 0x1b8a5cu;
    // NOP
    // 0x1b8a60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8a60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8a64: 0x3c024220  lui         $v0, 0x4220
    ctx->pc = 0x1b8a64u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16928 << 16));
    // 0x1b8a68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8a68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b8a6c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b8a6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b8a70: 0x9027aded  lbu         $a3, -0x5213($at)
    ctx->pc = 0x1b8a70u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b8a74: 0x3c0342c8  lui         $v1, 0x42C8
    ctx->pc = 0x1b8a74u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17096 << 16));
    // 0x1b8a78: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1b8a78u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1b8a7c: 0x3c06004a  lui         $a2, 0x4A
    ctx->pc = 0x1b8a7cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)74 << 16));
    // 0x1b8a80: 0x3c05004a  lui         $a1, 0x4A
    ctx->pc = 0x1b8a80u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)74 << 16));
    // 0x1b8a84: 0x24c66174  addiu       $a2, $a2, 0x6174
    ctx->pc = 0x1b8a84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 24948));
    // 0x1b8a88: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1b8a88u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1b8a8c: 0x24a56176  addiu       $a1, $a1, 0x6176
    ctx->pc = 0x1b8a8cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 24950));
    // 0x1b8a90: 0x71100  sll         $v0, $a3, 4
    ctx->pc = 0x1b8a90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
    // 0x1b8a94: 0x471823  subu        $v1, $v0, $a3
    ctx->pc = 0x1b8a94u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1b8a98: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x1b8a98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1b8a9c: 0x621021  addu        $v0, $v1, $v0
    ctx->pc = 0x1b8a9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b8aa0: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x1b8aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x1b8aa4: 0xc21821  addu        $v1, $a2, $v0
    ctx->pc = 0x1b8aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1b8aa8: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1b8aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1b8aac: 0x84630000  lh          $v1, 0x0($v1)
    ctx->pc = 0x1b8aacu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b8ab0: 0x84420000  lh          $v0, 0x0($v0)
    ctx->pc = 0x1b8ab0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b8ab4: 0x44831800  mtc1        $v1, $f3
    ctx->pc = 0x1b8ab4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[3], &bits, sizeof(bits)); }
    // 0x1b8ab8: 0x44821000  mtc1        $v0, $f2
    ctx->pc = 0x1b8ab8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[2], &bits, sizeof(bits)); }
    // 0x1b8abc: 0x0  nop
    ctx->pc = 0x1b8abcu;
    // NOP
    // 0x1b8ac0: 0x468018e0  cvt.s.w     $f3, $f3
    ctx->pc = 0x1b8ac0u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[3], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
    // 0x1b8ac4: 0x468010a0  cvt.s.w     $f2, $f2
    ctx->pc = 0x1b8ac4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[2], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1b8ac8: 0x46021883  div.s       $f2, $f3, $f2
    ctx->pc = 0x1b8ac8u;
    if (ctx->f[2] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[3]) ^ std::bit_cast<uint32_t>(ctx->f[2])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[2] = std::bit_cast<float>(__maxf); } else ctx->f[2] = ctx->f[3] / ctx->f[2];
    // 0x1b8acc: 0x0  nop
    ctx->pc = 0x1b8accu;
    // NOP
    // 0x1b8ad0: 0x46020842  mul.s       $f1, $f1, $f2
    ctx->pc = 0x1b8ad0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b8ad4: 0x46000834  c.lt.s      $f1, $f0
    ctx->pc = 0x1b8ad4u;
    ctx->fcr31 = (FPU_C_OLT_S(ctx->f[1], ctx->f[0])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b8ad8: 0x45000002  bc1f        . + 4 + (0x2 << 2)
    ctx->pc = 0x1B8AD8u;
    {
        const bool branch_taken_0x1b8ad8 = (!(ctx->fcr31 & 0x800000));
        ctx->pc = 0x1B8ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8AD8u;
            // 0x1b8adc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8ad8) {
            ctx->pc = 0x1B8AE4u;
            goto label_1b8ae4;
        }
    }
    ctx->pc = 0x1B8AE0u;
    // 0x1b8ae0: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1b8ae0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1b8ae4:
    // 0x1b8ae4: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B8AE4u;
    {
        const bool branch_taken_0x1b8ae4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b8ae4) {
            ctx->pc = 0x1B8AFCu;
            goto label_1b8afc;
        }
    }
    ctx->pc = 0x1B8AECu;
    // 0x1b8aec: 0xc06e284  jal         func_1B8A10
    ctx->pc = 0x1B8AECu;
    SET_GPR_U32(ctx, 31, 0x1B8AF4u);
    ctx->pc = 0x1B8AF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8AECu;
            // 0x1b8af0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8A10u;
    goto label_1b8a10;
    ctx->pc = 0x1B8AF4u;
label_1b8af4:
    // 0x1b8af4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B8AF4u;
    {
        const bool branch_taken_0x1b8af4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B8AF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8AF4u;
            // 0x1b8af8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8af4) {
            ctx->pc = 0x1B8B0Cu;
            goto label_1b8b0c;
        }
    }
    ctx->pc = 0x1B8AFCu;
label_1b8afc:
    // 0x1b8afc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b8afcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1b8b00: 0xc06e284  jal         func_1B8A10
    ctx->pc = 0x1B8B00u;
    SET_GPR_U32(ctx, 31, 0x1B8B08u);
    ctx->pc = 0x1B8B04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8B00u;
            // 0x1b8b04: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8A10u;
    goto label_1b8a10;
    ctx->pc = 0x1B8B08u;
label_1b8b08:
    // 0x1b8b08: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8b08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1b8b0c:
    // 0x1b8b0c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8B0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B8B10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8B0Cu;
            // 0x1b8b10: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B8A10u: goto label_1b8a10;
            case 0x1B8A2Cu: goto label_1b8a2c;
            case 0x1B8A34u: goto label_1b8a34;
            case 0x1B8A4Cu: goto label_1b8a4c;
            case 0x1B8A50u: goto label_1b8a50;
            case 0x1B8AE4u: goto label_1b8ae4;
            case 0x1B8AF4u: goto label_1b8af4;
            case 0x1B8AFCu: goto label_1b8afc;
            case 0x1B8B08u: goto label_1b8b08;
            case 0x1B8B0Cu: goto label_1b8b0c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8B14u;
    // 0x1b8b14: 0x0  nop
    ctx->pc = 0x1b8b14u;
    // NOP
    // 0x1b8b18: 0x0  nop
    ctx->pc = 0x1b8b18u;
    // NOP
    // 0x1b8b1c: 0x0  nop
    ctx->pc = 0x1b8b1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
