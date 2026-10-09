#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017DEB0
// Address: 0x17deb0 - 0x17e120
void sub_0017DEB0_0x17deb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017DEB0_0x17deb0");
#endif

    switch (ctx->pc) {
        case 0x17ded8u: goto label_17ded8;
        case 0x17df48u: goto label_17df48;
        case 0x17df60u: goto label_17df60;
        case 0x17df98u: goto label_17df98;
        case 0x17dfa4u: goto label_17dfa4;
        case 0x17dfb8u: goto label_17dfb8;
        case 0x17dfccu: goto label_17dfcc;
        case 0x17dfe0u: goto label_17dfe0;
        case 0x17dfecu: goto label_17dfec;
        case 0x17dffcu: goto label_17dffc;
        case 0x17e008u: goto label_17e008;
        case 0x17e014u: goto label_17e014;
        case 0x17e018u: goto label_17e018;
        case 0x17e034u: goto label_17e034;
        case 0x17e048u: goto label_17e048;
        case 0x17e058u: goto label_17e058;
        case 0x17e06cu: goto label_17e06c;
        case 0x17e078u: goto label_17e078;
        case 0x17e084u: goto label_17e084;
        case 0x17e08cu: goto label_17e08c;
        case 0x17e0f8u: goto label_17e0f8;
        case 0x17e10cu: goto label_17e10c;
        default: break;
    }

    ctx->pc = 0x17deb0u;

    // 0x17deb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17deb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17deb4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17deb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17deb8: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x17deb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17debc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17debcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17dec0: 0x26500200  addiu       $s0, $s2, 0x200
    ctx->pc = 0x17dec0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 512));
    // 0x17dec4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x17dec4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dec8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17dec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17decc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17deccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17ded0: 0xc05f6bc  jal         func_17DAF0
    ctx->pc = 0x17DED0u;
    SET_GPR_U32(ctx, 31, 0x17DED8u);
    ctx->pc = 0x17DED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DED0u;
            // 0x17ded4: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17DAF0u;
    if (runtime->hasFunction(0x17DAF0u)) {
        auto targetFn = runtime->lookupFunction(0x17DAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DED8u; }
        if (ctx->pc != 0x17DED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017DAF0_0x17daf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DED8u; }
        if (ctx->pc != 0x17DED8u) { return; }
    }
    ctx->pc = 0x17DED8u;
label_17ded8:
    // 0x17ded8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17ded8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dedc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17dedcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dee0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17dee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17dee4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x17dee4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dee8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17dee8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17deec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17deecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17def0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17def0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17def4: 0x805f7c0  j           func_17DF00
    ctx->pc = 0x17DEF4u;
    ctx->pc = 0x17DEF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DEF4u;
            // 0x17def8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17DF00u;
    goto label_17df00;
    ctx->pc = 0x17DEFCu;
    // 0x17defc: 0x0  nop
    ctx->pc = 0x17defcu;
    // NOP
label_17df00:
    // 0x17df00: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x17df00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x17df04: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17df04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17df08: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17df08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17df0c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x17df0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x17df10: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x17df10u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17df14: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17df14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17df18: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17df18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17df1c: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x17df1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x17df20: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x17df20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17df24: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x17df24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x17df28: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x17df28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x17df2c: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x17df2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x17df30: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x17df30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x17df34: 0xe7b50058  swc1        $f21, 0x58($sp)
    ctx->pc = 0x17df34u;
    { float f = ctx->f[21]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x17df38: 0xe7b40050  swc1        $f20, 0x50($sp)
    ctx->pc = 0x17df38u;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x17df3c: 0xc4950040  lwc1        $f21, 0x40($a0)
    ctx->pc = 0x17df3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 64)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17df40: 0xc05f8ea  jal         func_17E3A8
    ctx->pc = 0x17DF40u;
    SET_GPR_U32(ctx, 31, 0x17DF48u);
    ctx->pc = 0x17DF44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DF40u;
            // 0x17df44: 0xc494003c  lwc1        $f20, 0x3C($a0) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 60)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E3A8u;
    if (runtime->hasFunction(0x17E3A8u)) {
        auto targetFn = runtime->lookupFunction(0x17E3A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DF48u; }
        if (ctx->pc != 0x17DF48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E3A8_0x17e3a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DF48u; }
        if (ctx->pc != 0x17DF48u) { return; }
    }
    ctx->pc = 0x17DF48u;
label_17df48:
    // 0x17df48: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x17df48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17df4c: 0x1443000e  bne         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x17DF4Cu;
    {
        const bool branch_taken_0x17df4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x17DF50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DF4Cu;
            // 0x17df50: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17df4c) {
            ctx->pc = 0x17DF88u;
            goto label_17df88;
        }
    }
    ctx->pc = 0x17DF54u;
    // 0x17df54: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x17df54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17df58: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x17df58u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17df5c: 0x0  nop
    ctx->pc = 0x17df5cu;
    // NOP
label_17df60:
    // 0x17df60: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x17df60u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x17df64: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x17df64u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x17df68: 0x26940001  addiu       $s4, $s4, 0x1
    ctx->pc = 0x17df68u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 1));
    // 0x17df6c: 0x213c2  srl         $v0, $v0, 15
    ctx->pc = 0x17df6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 15));
    // 0x17df70: 0x2a830100  slti        $v1, $s4, 0x100
    ctx->pc = 0x17df70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 20) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x17df74: 0xa4c20000  sh          $v0, 0x0($a2)
    ctx->pc = 0x17df74u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x17df78: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x17DF78u;
    {
        const bool branch_taken_0x17df78 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x17DF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DF78u;
            // 0x17df7c: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17df78) {
            ctx->pc = 0x17DF60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17df60;
        }
    }
    ctx->pc = 0x17DF80u;
    // 0x17df80: 0x10000046  b           . + 4 + (0x46 << 2)
    ctx->pc = 0x17DF80u;
    {
        const bool branch_taken_0x17df80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17DF84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17DF80u;
            // 0x17df84: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17df80) {
            ctx->pc = 0x17E09Cu;
            goto label_17e09c;
        }
    }
    ctx->pc = 0x17DF88u;
label_17df88:
    // 0x17df88: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x17df88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x17df8c: 0xdc301488  ld          $s0, 0x1488($at)
    ctx->pc = 0x17df8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 1), 5256)));
    // 0x17df90: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x17DF90u;
    SET_GPR_U32(ctx, 31, 0x17DF98u);
    ctx->pc = 0x17DF94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DF90u;
            // 0x17df94: 0x4600a306  mov.s       $f12, $f20 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[20]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DF98u; }
        if (ctx->pc != 0x17DF98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DF98u; }
        if (ctx->pc != 0x17DF98u) { return; }
    }
    ctx->pc = 0x17DF98u;
label_17df98:
    // 0x17df98: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x17df98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17df9c: 0xc04462e  jal         func_1118B8
    ctx->pc = 0x17DF9Cu;
    SET_GPR_U32(ctx, 31, 0x17DFA4u);
    ctx->pc = 0x17DFA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DF9Cu;
            // 0x17dfa0: 0x4600ab06  mov.s       $f12, $f21 (Delay Slot)
        ctx->f[12] = FPU_MOV_S(ctx->f[21]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1118B8u;
    if (runtime->hasFunction(0x1118B8u)) {
        auto targetFn = runtime->lookupFunction(0x1118B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFA4u; }
        if (ctx->pc != 0x17DFA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001118B8_0x1118b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFA4u; }
        if (ctx->pc != 0x17DFA4u) { return; }
    }
    ctx->pc = 0x17DFA4u;
label_17dfa4:
    // 0x17dfa4: 0x40b02d  daddu       $s6, $v0, $zero
    ctx->pc = 0x17dfa4u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfa8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17dfa8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfac: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x17dfacu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfb0: 0xc044752  jal         func_111D48
    ctx->pc = 0x17DFB0u;
    SET_GPR_U32(ctx, 31, 0x17DFB8u);
    ctx->pc = 0x17DFB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DFB0u;
            // 0x17dfb4: 0x220a82d  daddu       $s5, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFB8u; }
        if (ctx->pc != 0x17DFB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFB8u; }
        if (ctx->pc != 0x17DFB8u) { return; }
    }
    ctx->pc = 0x17DFB8u;
label_17dfb8:
    // 0x17dfb8: 0x3404ffc0  ori         $a0, $zero, 0xFFC0
    ctx->pc = 0x17dfb8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65472);
    // 0x17dfbc: 0x423bc  dsll32      $a0, $a0, 14
    ctx->pc = 0x17dfbcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 14));
    // 0x17dfc0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x17dfc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfc4: 0xc04480e  jal         func_112038
    ctx->pc = 0x17DFC4u;
    SET_GPR_U32(ctx, 31, 0x17DFCCu);
    ctx->pc = 0x17DFC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DFC4u;
            // 0x17dfc8: 0x24170001  addiu       $s7, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFCCu; }
        if (ctx->pc != 0x17DFCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFCCu; }
        if (ctx->pc != 0x17DFCCu) { return; }
    }
    ctx->pc = 0x17DFCCu;
label_17dfcc:
    // 0x17dfcc: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x17dfccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfd0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17dfd0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfd4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17dfd4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfd8: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x17DFD8u;
    SET_GPR_U32(ctx, 31, 0x17DFE0u);
    ctx->pc = 0x17DFDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DFD8u;
            // 0x17dfdc: 0x241400ff  addiu       $s4, $zero, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFE0u; }
        if (ctx->pc != 0x17DFE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFE0u; }
        if (ctx->pc != 0x17DFE0u) { return; }
    }
    ctx->pc = 0x17DFE0u;
label_17dfe0:
    // 0x17dfe0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x17dfe0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dfe4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x17DFE4u;
    SET_GPR_U32(ctx, 31, 0x17DFECu);
    ctx->pc = 0x17DFE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DFE4u;
            // 0x17dfe8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFECu; }
        if (ctx->pc != 0x17DFECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFECu; }
        if (ctx->pc != 0x17DFECu) { return; }
    }
    ctx->pc = 0x17DFECu;
label_17dfec:
    // 0x17dfec: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17dfecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dff0: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17dff0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17dff4: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x17DFF4u;
    SET_GPR_U32(ctx, 31, 0x17DFFCu);
    ctx->pc = 0x17DFF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17DFF4u;
            // 0x17dff8: 0x40f02d  daddu       $fp, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFFCu; }
        if (ctx->pc != 0x17DFFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17DFFCu; }
        if (ctx->pc != 0x17DFFCu) { return; }
    }
    ctx->pc = 0x17DFFCu;
label_17dffc:
    // 0x17dffc: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x17dffcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e000: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x17E000u;
    SET_GPR_U32(ctx, 31, 0x17E008u);
    ctx->pc = 0x17E004u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E000u;
            // 0x17e004: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E008u; }
        if (ctx->pc != 0x17E008u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E008u; }
        if (ctx->pc != 0x17E008u) { return; }
    }
    ctx->pc = 0x17E008u;
label_17e008:
    // 0x17e008: 0x2c0282d  daddu       $a1, $s6, $zero
    ctx->pc = 0x17e008u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e00c: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x17E00Cu;
    SET_GPR_U32(ctx, 31, 0x17E014u);
    ctx->pc = 0x17E010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E00Cu;
            // 0x17e010: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E014u; }
        if (ctx->pc != 0x17E014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E014u; }
        if (ctx->pc != 0x17E014u) { return; }
    }
    ctx->pc = 0x17E014u;
label_17e014:
    // 0x17e014: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17e014u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_17e018:
    // 0x17e018: 0x8e700000  lw          $s0, 0x0($s3)
    ctx->pc = 0x17e018u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x17e01c: 0x16000003  bnez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E01Cu;
    {
        const bool branch_taken_0x17e01c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x17e01c) {
            ctx->pc = 0x17E02Cu;
            goto label_17e02c;
        }
    }
    ctx->pc = 0x17E024u;
    // 0x17e024: 0xae770000  sw          $s7, 0x0($s3)
    ctx->pc = 0x17e024u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 23));
    // 0x17e028: 0x2e0802d  daddu       $s0, $s7, $zero
    ctx->pc = 0x17e028u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
label_17e02c:
    // 0x17e02c: 0xc0448ba  jal         func_1122E8
    ctx->pc = 0x17E02Cu;
    SET_GPR_U32(ctx, 31, 0x17E034u);
    ctx->pc = 0x17E030u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E02Cu;
            // 0x17e030: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1122E8u;
    if (runtime->hasFunction(0x1122E8u)) {
        auto targetFn = runtime->lookupFunction(0x1122E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E034u; }
        if (ctx->pc != 0x17E034u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E034u; }
        if (ctx->pc != 0x17E034u) { return; }
    }
    ctx->pc = 0x17E034u;
label_17e034:
    // 0x17e034: 0x340583e0  ori         $a1, $zero, 0x83E0
    ctx->pc = 0x17e034u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)33760);
    // 0x17e038: 0x6010003  bgez        $s0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E038u;
    {
        const bool branch_taken_0x17e038 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x17E03Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E038u;
            // 0x17e03c: 0x52bfc  dsll32      $a1, $a1, 15 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e038) {
            ctx->pc = 0x17E048u;
            goto label_17e048;
        }
    }
    ctx->pc = 0x17E040u;
    // 0x17e040: 0xc04473c  jal         func_111CF0
    ctx->pc = 0x17E040u;
    SET_GPR_U32(ctx, 31, 0x17E048u);
    ctx->pc = 0x17E044u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E040u;
            // 0x17e044: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111CF0u;
    if (runtime->hasFunction(0x111CF0u)) {
        auto targetFn = runtime->lookupFunction(0x111CF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E048u; }
        if (ctx->pc != 0x17E048u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E048u; }
        if (ctx->pc != 0x17E048u) { return; }
    }
    ctx->pc = 0x17E048u;
label_17e048:
    // 0x17e048: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x17e048u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e04c: 0x2c0202d  daddu       $a0, $s6, $zero
    ctx->pc = 0x17e04cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e050: 0xc04476c  jal         func_111DB0
    ctx->pc = 0x17E050u;
    SET_GPR_U32(ctx, 31, 0x17E058u);
    ctx->pc = 0x17E054u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E050u;
            // 0x17e054: 0x2694ffff  addiu       $s4, $s4, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 20), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111DB0u;
    if (runtime->hasFunction(0x111DB0u)) {
        auto targetFn = runtime->lookupFunction(0x111DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E058u; }
        if (ctx->pc != 0x17E058u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E058u; }
        if (ctx->pc != 0x17E058u) { return; }
    }
    ctx->pc = 0x17E058u;
label_17e058:
    // 0x17e058: 0x3c010024  lui         $at, 0x24
    ctx->pc = 0x17e058u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)36 << 16));
    // 0x17e05c: 0xdc251490  ld          $a1, 0x1490($at)
    ctx->pc = 0x17e05cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 5264)));
    // 0x17e060: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x17e060u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e064: 0xc04480e  jal         func_112038
    ctx->pc = 0x17E064u;
    SET_GPR_U32(ctx, 31, 0x17E06Cu);
    ctx->pc = 0x17E068u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E064u;
            // 0x17e068: 0x26730004  addiu       $s3, $s3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E06Cu; }
        if (ctx->pc != 0x17E06Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E06Cu; }
        if (ctx->pc != 0x17E06Cu) { return; }
    }
    ctx->pc = 0x17E06Cu;
label_17e06c:
    // 0x17e06c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x17e06cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e070: 0xc04480e  jal         func_112038
    ctx->pc = 0x17E070u;
    SET_GPR_U32(ctx, 31, 0x17E078u);
    ctx->pc = 0x17E074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E070u;
            // 0x17e074: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x112038u;
    if (runtime->hasFunction(0x112038u)) {
        auto targetFn = runtime->lookupFunction(0x112038u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E078u; }
        if (ctx->pc != 0x17E078u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E078u; }
        if (ctx->pc != 0x17E078u) { return; }
    }
    ctx->pc = 0x17E078u;
label_17e078:
    // 0x17e078: 0x3c0202d  daddu       $a0, $fp, $zero
    ctx->pc = 0x17e078u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e07c: 0xc044752  jal         func_111D48
    ctx->pc = 0x17E07Cu;
    SET_GPR_U32(ctx, 31, 0x17E084u);
    ctx->pc = 0x17E080u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E07Cu;
            // 0x17e080: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x111D48u;
    if (runtime->hasFunction(0x111D48u)) {
        auto targetFn = runtime->lookupFunction(0x111D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E084u; }
        if (ctx->pc != 0x17E084u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00111D48_0x111d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E084u; }
        if (ctx->pc != 0x17E084u) { return; }
    }
    ctx->pc = 0x17E084u;
label_17e084:
    // 0x17e084: 0xc044932  jal         func_1124C8
    ctx->pc = 0x17E084u;
    SET_GPR_U32(ctx, 31, 0x17E08Cu);
    ctx->pc = 0x17E088u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E084u;
            // 0x17e088: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1124C8u;
    if (runtime->hasFunction(0x1124C8u)) {
        auto targetFn = runtime->lookupFunction(0x1124C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E08Cu; }
        if (ctx->pc != 0x17E08Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001124C8_0x1124c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E08Cu; }
        if (ctx->pc != 0x17E08Cu) { return; }
    }
    ctx->pc = 0x17E08Cu;
label_17e08c:
    // 0x17e08c: 0xa6a20000  sh          $v0, 0x0($s5)
    ctx->pc = 0x17e08cu;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x17e090: 0x681ffe1  bgez        $s4, . + 4 + (-0x1F << 2)
    ctx->pc = 0x17E090u;
    {
        const bool branch_taken_0x17e090 = (GPR_S64(ctx, 20) >= 0);
        ctx->pc = 0x17E094u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E090u;
            // 0x17e094: 0x26b50002  addiu       $s5, $s5, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 21), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e090) {
            ctx->pc = 0x17E018u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_17e018;
        }
    }
    ctx->pc = 0x17E098u;
    // 0x17e098: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17e098u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17e09c:
    // 0x17e09c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17e09cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17e0a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17e0a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e0a4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17e0a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e0a8: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x17e0a8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17e0ac: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x17e0acu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x17e0b0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x17e0b0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17e0b4: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x17e0b4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17e0b8: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x17e0b8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x17e0bc: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x17e0bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x17e0c0: 0xc7b50058  lwc1        $f21, 0x58($sp)
    ctx->pc = 0x17e0c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 88)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[21] = f; }
    // 0x17e0c4: 0xc7b40050  lwc1        $f20, 0x50($sp)
    ctx->pc = 0x17e0c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 80)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x17e0c8: 0x3e00008  jr          $ra
    ctx->pc = 0x17E0C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E0CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E0C8u;
            // 0x17e0cc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17DED8u: goto label_17ded8;
            case 0x17DF00u: goto label_17df00;
            case 0x17DF48u: goto label_17df48;
            case 0x17DF60u: goto label_17df60;
            case 0x17DF88u: goto label_17df88;
            case 0x17DF98u: goto label_17df98;
            case 0x17DFA4u: goto label_17dfa4;
            case 0x17DFB8u: goto label_17dfb8;
            case 0x17DFCCu: goto label_17dfcc;
            case 0x17DFE0u: goto label_17dfe0;
            case 0x17DFECu: goto label_17dfec;
            case 0x17DFFCu: goto label_17dffc;
            case 0x17E008u: goto label_17e008;
            case 0x17E014u: goto label_17e014;
            case 0x17E018u: goto label_17e018;
            case 0x17E02Cu: goto label_17e02c;
            case 0x17E034u: goto label_17e034;
            case 0x17E048u: goto label_17e048;
            case 0x17E058u: goto label_17e058;
            case 0x17E06Cu: goto label_17e06c;
            case 0x17E078u: goto label_17e078;
            case 0x17E084u: goto label_17e084;
            case 0x17E08Cu: goto label_17e08c;
            case 0x17E09Cu: goto label_17e09c;
            case 0x17E0F8u: goto label_17e0f8;
            case 0x17E10Cu: goto label_17e10c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E0D0u;
    // 0x17e0d0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17e0d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17e0d4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17e0d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x17e0d8: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17e0d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0dc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x17e0dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17e0e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17e0e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17e0e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17e0e8: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17e0e8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0ec: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x17e0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x17e0f0: 0xc05f65a  jal         func_17D968
    ctx->pc = 0x17E0F0u;
    SET_GPR_U32(ctx, 31, 0x17E0F8u);
    ctx->pc = 0x17E0F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E0F0u;
            // 0x17e0f4: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D968u;
    if (runtime->hasFunction(0x17D968u)) {
        auto targetFn = runtime->lookupFunction(0x17D968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E0F8u; }
        if (ctx->pc != 0x17E0F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D968_0x17d968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E0F8u; }
        if (ctx->pc != 0x17E0F8u) { return; }
    }
    ctx->pc = 0x17E0F8u;
label_17e0f8:
    // 0x17e0f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17e0f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e0fc: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x17e0fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e100: 0x220382d  daddu       $a3, $s1, $zero
    ctx->pc = 0x17e100u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17e104: 0xc05f848  jal         func_17E120
    ctx->pc = 0x17E104u;
    SET_GPR_U32(ctx, 31, 0x17E10Cu);
    ctx->pc = 0x17E108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E104u;
            // 0x17e108: 0x8fa60004  lw          $a2, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17E120u;
    if (runtime->hasFunction(0x17E120u)) {
        auto targetFn = runtime->lookupFunction(0x17E120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E10Cu; }
        if (ctx->pc != 0x17E10Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017E120_0x17e120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E10Cu; }
        if (ctx->pc != 0x17E10Cu) { return; }
    }
    ctx->pc = 0x17E10Cu;
label_17e10c:
    // 0x17e10c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x17e10cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17e110: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x17e110u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17e114: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17e114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17e118: 0x3e00008  jr          $ra
    ctx->pc = 0x17E118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E11Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E118u;
            // 0x17e11c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17DED8u: goto label_17ded8;
            case 0x17DF00u: goto label_17df00;
            case 0x17DF48u: goto label_17df48;
            case 0x17DF60u: goto label_17df60;
            case 0x17DF88u: goto label_17df88;
            case 0x17DF98u: goto label_17df98;
            case 0x17DFA4u: goto label_17dfa4;
            case 0x17DFB8u: goto label_17dfb8;
            case 0x17DFCCu: goto label_17dfcc;
            case 0x17DFE0u: goto label_17dfe0;
            case 0x17DFECu: goto label_17dfec;
            case 0x17DFFCu: goto label_17dffc;
            case 0x17E008u: goto label_17e008;
            case 0x17E014u: goto label_17e014;
            case 0x17E018u: goto label_17e018;
            case 0x17E02Cu: goto label_17e02c;
            case 0x17E034u: goto label_17e034;
            case 0x17E048u: goto label_17e048;
            case 0x17E058u: goto label_17e058;
            case 0x17E06Cu: goto label_17e06c;
            case 0x17E078u: goto label_17e078;
            case 0x17E084u: goto label_17e084;
            case 0x17E08Cu: goto label_17e08c;
            case 0x17E09Cu: goto label_17e09c;
            case 0x17E0F8u: goto label_17e0f8;
            case 0x17E10Cu: goto label_17e10c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E120u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
