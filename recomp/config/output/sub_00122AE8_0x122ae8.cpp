#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122AE8
// Address: 0x122ae8 - 0x122d80
void sub_00122AE8_0x122ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122AE8_0x122ae8");
#endif

    switch (ctx->pc) {
        case 0x122b60u: goto label_122b60;
        case 0x122b7cu: goto label_122b7c;
        case 0x122bacu: goto label_122bac;
        case 0x122be0u: goto label_122be0;
        case 0x122bf8u: goto label_122bf8;
        case 0x122c14u: goto label_122c14;
        case 0x122c30u: goto label_122c30;
        case 0x122c70u: goto label_122c70;
        case 0x122c9cu: goto label_122c9c;
        case 0x122ca8u: goto label_122ca8;
        case 0x122d04u: goto label_122d04;
        default: break;
    }

    ctx->pc = 0x122ae8u;

    // 0x122ae8: 0x3e00008  jr          $ra
    ctx->pc = 0x122AE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122AE8u;
            // 0x122aec: 0xa0800001  sb          $zero, 0x1($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122AF0u;
    // 0x122af0: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x122af0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x122af4: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x122af4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x122af8: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x122af8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x122afc: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x122afcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122b00: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x122b00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x122b04: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x122b04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x122b08: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x122b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x122b0c: 0xffb50058  sd          $s5, 0x58($sp)
    ctx->pc = 0x122b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 21));
    // 0x122b10: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x122b10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x122b14: 0xffb70068  sd          $s7, 0x68($sp)
    ctx->pc = 0x122b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 104), GPR_U64(ctx, 23));
    // 0x122b18: 0xffbe0070  sd          $fp, 0x70($sp)
    ctx->pc = 0x122b18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 30));
    // 0x122b1c: 0xffbf0078  sd          $ra, 0x78($sp)
    ctx->pc = 0x122b1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 120), GPR_U64(ctx, 31));
    // 0x122b20: 0xafa00020  sw          $zero, 0x20($sp)
    ctx->pc = 0x122b20u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    // 0x122b24: 0xc6800020  lwc1        $f0, 0x20($s4)
    ctx->pc = 0x122b24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 32)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x122b28: 0x46800020  cvt.s.w     $f0, $f0
    ctx->pc = 0x122b28u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[0] = FPU_CVT_S_W(tmp); }
    // 0x122b2c: 0xc6810024  lwc1        $f1, 0x24($s4)
    ctx->pc = 0x122b2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 20), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x122b30: 0x8e82001c  lw          $v0, 0x1C($s4)
    ctx->pc = 0x122b30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 28)));
    // 0x122b34: 0x46010002  mul.s       $f0, $f0, $f1
    ctx->pc = 0x122b34u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x122b38: 0x46000064  .word       0x46000064                   # cvt.w.s     $f1, $f0 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x122b38u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[0]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x122b3c: 0x44120800  mfc1        $s2, $f1
    ctx->pc = 0x122b3cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 18, bits); }
    // 0x122b40: 0x18400083  blez        $v0, . + 4 + (0x83 << 2)
    ctx->pc = 0x122B40u;
    {
        const bool branch_taken_0x122b40 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x122B44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122B40u;
            // 0x122b44: 0xdfb00030  ld          $s0, 0x30($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122b40) {
            ctx->pc = 0x122D50u;
            goto label_122d50;
        }
    }
    ctx->pc = 0x122B48u;
    // 0x122b48: 0x2697000c  addiu       $s7, $s4, 0xC
    ctx->pc = 0x122b48u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 20), 12));
    // 0x122b4c: 0x26820014  addiu       $v0, $s4, 0x14
    ctx->pc = 0x122b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 20), 20));
    // 0x122b50: 0xafb70028  sw          $s7, 0x28($sp)
    ctx->pc = 0x122b50u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 23));
    // 0x122b54: 0x269e0004  addiu       $fp, $s4, 0x4
    ctx->pc = 0x122b54u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 20), 4));
    // 0x122b58: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x122b58u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x122b5c: 0x0  nop
    ctx->pc = 0x122b5cu;
    // NOP
label_122b60:
    // 0x122b60: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x122b60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x122b64: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x122b64u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x122b68: 0x38880  sll         $s1, $v1, 2
    ctx->pc = 0x122b68u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x122b6c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x122b6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x122b70: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x122b70u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x122b74: 0x40f809  jalr        $v0
    ctx->pc = 0x122B74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122B7Cu);
        ctx->pc = 0x122B78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122B74u;
            // 0x122b78: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122B7Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122B7Cu; }
            if (ctx->pc != 0x122B7Cu) { return; }
        }
        }
    }
    ctx->pc = 0x122B7Cu;
label_122b7c:
    // 0x122b7c: 0x52400001  beql        $s2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x122B7Cu;
    {
        const bool branch_taken_0x122b7c = (GPR_U64(ctx, 18) == GPR_U64(ctx, 0));
        if (branch_taken_0x122b7c) {
            ctx->pc = 0x122B80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122B7Cu;
            // 0x122b80: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x122B84u;
            goto label_122b84;
        }
    }
    ctx->pc = 0x122B84u;
label_122b84:
    // 0x122b84: 0x287c2  srl         $s0, $v0, 31
    ctx->pc = 0x122b84u;
    SET_GPR_S32(ctx, 16, (int32_t)SRL32(GPR_U32(ctx, 2), 31));
    // 0x122b88: 0x8ee40000  lw          $a0, 0x0($s7)
    ctx->pc = 0x122b88u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x122b8c: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x122b8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x122b90: 0x108043  sra         $s0, $s0, 1
    ctx->pc = 0x122b90u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 16), 1));
    // 0x122b94: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x122b94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x122b98: 0x212001a  div         $zero, $s0, $s2
    ctx->pc = 0x122b98u;
    { int32_t divisor = GPR_S32(ctx, 18);    int32_t dividend = GPR_S32(ctx, 16);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x122b9c: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x122b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x122ba0: 0x8012  mflo        $s0
    ctx->pc = 0x122ba0u;
    SET_GPR_U64(ctx, 16, ctx->lo);
    // 0x122ba4: 0x40f809  jalr        $v0
    ctx->pc = 0x122BA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122BACu);
        ctx->pc = 0x122BA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122BA4u;
            // 0x122ba8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122BACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122BACu; }
            if (ctx->pc != 0x122BACu) { return; }
        }
        }
    }
    ctx->pc = 0x122BACu;
label_122bac:
    // 0x122bac: 0x28430000  slti        $v1, $v0, 0x0
    ctx->pc = 0x122bacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x122bb0: 0x2444000f  addiu       $a0, $v0, 0xF
    ctx->pc = 0x122bb0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), 15));
    // 0x122bb4: 0x83100b  movn        $v0, $a0, $v1
    ctx->pc = 0x122bb4u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x122bb8: 0x21903  sra         $v1, $v0, 4
    ctx->pc = 0x122bb8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 2), 4));
    // 0x122bbc: 0x203102a  slt         $v0, $s0, $v1
    ctx->pc = 0x122bbcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x122bc0: 0x202180b  movn        $v1, $s0, $v0
    ctx->pc = 0x122bc0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 16));
    // 0x122bc4: 0x58600057  blezl       $v1, . + 4 + (0x57 << 2)
    ctx->pc = 0x122BC4u;
    {
        const bool branch_taken_0x122bc4 = (GPR_S64(ctx, 3) <= 0);
        if (branch_taken_0x122bc4) {
            ctx->pc = 0x122BC8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122BC4u;
            // 0x122bc8: 0x8fa30020  lw          $v1, 0x20($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122D24u;
            goto label_122d24;
        }
    }
    ctx->pc = 0x122BCCu;
    // 0x122bcc: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x122bccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x122bd0: 0x60b02d  daddu       $s6, $v1, $zero
    ctx->pc = 0x122bd0u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122bd4: 0x8fb5002c  lw          $s5, 0x2C($sp)
    ctx->pc = 0x122bd4u;
    SET_GPR_S32(ctx, 21, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x122bd8: 0x518821  addu        $s1, $v0, $s1
    ctx->pc = 0x122bd8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x122bdc: 0xafb10024  sw          $s1, 0x24($sp)
    ctx->pc = 0x122bdcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 17));
label_122be0:
    // 0x122be0: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x122be0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122be4: 0x1a400025  blez        $s2, . + 4 + (0x25 << 2)
    ctx->pc = 0x122BE4u;
    {
        const bool branch_taken_0x122be4 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x122BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122BE4u;
            // 0x122be8: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122be4) {
            ctx->pc = 0x122C7Cu;
            goto label_122c7c;
        }
    }
    ctx->pc = 0x122BECu;
    // 0x122bec: 0x3c0882d  daddu       $s1, $fp, $zero
    ctx->pc = 0x122becu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122bf0: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x122bf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x122bf4: 0x0  nop
    ctx->pc = 0x122bf4u;
    // NOP
label_122bf8:
    // 0x122bf8: 0x2503023  subu        $a2, $s2, $s0
    ctx->pc = 0x122bf8u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x122bfc: 0x3a0382d  daddu       $a3, $sp, $zero
    ctx->pc = 0x122bfcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122c00: 0x63040  sll         $a2, $a2, 1
    ctx->pc = 0x122c00u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x122c04: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x122c04u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x122c08: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x122c08u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x122c0c: 0x40f809  jalr        $v0
    ctx->pc = 0x122C0Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122C14u);
        ctx->pc = 0x122C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122C0Cu;
            // 0x122c10: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122C14u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122C14u; }
            if (ctx->pc != 0x122C14u) { return; }
        }
        }
    }
    ctx->pc = 0x122C14u;
label_122c14:
    // 0x122c14: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x122c14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x122c18: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x122c18u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x122c1c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x122c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x122c20: 0x34043  sra         $t0, $v1, 1
    ctx->pc = 0x122c20u;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 3), 1));
    // 0x122c24: 0x1900000b  blez        $t0, . + 4 + (0xB << 2)
    ctx->pc = 0x122C24u;
    {
        const bool branch_taken_0x122c24 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x122C28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122C24u;
            // 0x122c28: 0x8fa70000  lw          $a3, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122c24) {
            ctx->pc = 0x122C54u;
            goto label_122c54;
        }
    }
    ctx->pc = 0x122C2Cu;
    // 0x122c2c: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x122c2cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
label_122c30:
    // 0x122c30: 0x84e40000  lh          $a0, 0x0($a3)
    ctx->pc = 0x122c30u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x122c34: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x122c34u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x122c38: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x122c38u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x122c3c: 0x42823  negu        $a1, $a0
    ctx->pc = 0x122c3cu;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 4)));
    // 0x122c40: 0x28820000  slti        $v0, $a0, 0x0
    ctx->pc = 0x122c40u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x122c44: 0xa2200b  movn        $a0, $a1, $v0
    ctx->pc = 0x122c44u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 5));
    // 0x122c48: 0x264182a  slt         $v1, $s3, $a0
    ctx->pc = 0x122c48u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x122c4c: 0x14c0fff8  bnez        $a2, . + 4 + (-0x8 << 2)
    ctx->pc = 0x122C4Cu;
    {
        const bool branch_taken_0x122c4c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x122C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122C4Cu;
            // 0x122c50: 0x83980b  movn        $s3, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122c4c) {
            ctx->pc = 0x122C30u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122c30;
        }
    }
    ctx->pc = 0x122C54u;
label_122c54:
    // 0x122c54: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x122c54u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x122c58: 0x2088021  addu        $s0, $s0, $t0
    ctx->pc = 0x122c58u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 8)));
    // 0x122c5c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122c5cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122c60: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x122c60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x122c64: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x122c64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x122c68: 0x40f809  jalr        $v0
    ctx->pc = 0x122C68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122C70u);
        ctx->pc = 0x122C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122C68u;
            // 0x122c6c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122C70u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122C70u; }
            if (ctx->pc != 0x122C70u) { return; }
        }
        }
    }
    ctx->pc = 0x122C70u;
label_122c70:
    // 0x122c70: 0x212182a  slt         $v1, $s0, $s2
    ctx->pc = 0x122c70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x122c74: 0x5460ffe0  bnel        $v1, $zero, . + 4 + (-0x20 << 2)
    ctx->pc = 0x122C74u;
    {
        const bool branch_taken_0x122c74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x122c74) {
            ctx->pc = 0x122C78u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122C74u;
            // 0x122c78: 0x8e240000  lw          $a0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x122BF8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122bf8;
        }
    }
    ctx->pc = 0x122C7Cu;
label_122c7c:
    // 0x122c7c: 0x8ee40000  lw          $a0, 0x0($s7)
    ctx->pc = 0x122c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x122c80: 0x27a30010  addiu       $v1, $sp, 0x10
    ctx->pc = 0x122c80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x122c84: 0x60382d  daddu       $a3, $v1, $zero
    ctx->pc = 0x122c84u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122c88: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x122c88u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122c8c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x122c8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x122c90: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x122c90u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x122c94: 0x40f809  jalr        $v0
    ctx->pc = 0x122C94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x122C9Cu);
        ctx->pc = 0x122C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122C94u;
            // 0x122c98: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122C9Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122C9Cu; }
            if (ctx->pc != 0x122C9Cu) { return; }
        }
        }
    }
    ctx->pc = 0x122C9Cu;
label_122c9c:
    // 0x122c9c: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x122c9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x122ca0: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x122CA0u;
    {
        const bool branch_taken_0x122ca0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x122CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122CA0u;
            // 0x122ca4: 0x8fa70010  lw          $a3, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122ca0) {
            ctx->pc = 0x122CC8u;
            goto label_122cc8;
        }
    }
    ctx->pc = 0x122CA8u;
label_122ca8:
    // 0x122ca8: 0x0  nop
    ctx->pc = 0x122ca8u;
    // NOP
    // 0x122cac: 0x0  nop
    ctx->pc = 0x122cacu;
    // NOP
    // 0x122cb0: 0x0  nop
    ctx->pc = 0x122cb0u;
    // NOP
    // 0x122cb4: 0x0  nop
    ctx->pc = 0x122cb4u;
    // NOP
    // 0x122cb8: 0x0  nop
    ctx->pc = 0x122cb8u;
    // NOP
    // 0x122cbc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x122CBCu;
    {
        const bool branch_taken_0x122cbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x122cbc) {
            ctx->pc = 0x122CA8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122ca8;
        }
    }
    ctx->pc = 0x122CC4u;
    // 0x122cc4: 0x0  nop
    ctx->pc = 0x122cc4u;
    // NOP
label_122cc8:
    // 0x122cc8: 0x27a30010  addiu       $v1, $sp, 0x10
    ctx->pc = 0x122cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x122ccc: 0x8fa20024  lw          $v0, 0x24($sp)
    ctx->pc = 0x122cccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x122cd0: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x122cd0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x122cd4: 0xacf30000  sw          $s3, 0x0($a3)
    ctx->pc = 0x122cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 19));
    // 0x122cd8: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x122cd8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x122cdc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x122cdcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x122ce0: 0x26d6ffff  addiu       $s6, $s6, -0x1
    ctx->pc = 0x122ce0u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 4294967295));
    // 0x122ce4: 0x8ea20000  lw          $v0, 0x0($s5)
    ctx->pc = 0x122ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x122ce8: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x122ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x122cec: 0xace20004  sw          $v0, 0x4($a3)
    ctx->pc = 0x122cecu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 2));
    // 0x122cf0: 0x8c680020  lw          $t0, 0x20($v1)
    ctx->pc = 0x122cf0u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x122cf4: 0x8e830020  lw          $v1, 0x20($s4)
    ctx->pc = 0x122cf4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 32)));
    // 0x122cf8: 0xacf2000c  sw          $s2, 0xC($a3)
    ctx->pc = 0x122cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 12), GPR_U32(ctx, 18));
    // 0x122cfc: 0x100f809  jalr        $t0
    ctx->pc = 0x122CFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 8);
        SET_GPR_U32(ctx, 31, 0x122D04u);
        ctx->pc = 0x122D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122CFCu;
            // 0x122d00: 0xace30008  sw          $v1, 0x8($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 8), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x122D04u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x122D04u; }
            if (ctx->pc != 0x122D04u) { return; }
        }
        }
    }
    ctx->pc = 0x122D04u;
label_122d04:
    // 0x122d04: 0x8ea20000  lw          $v0, 0x0($s5)
    ctx->pc = 0x122d04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x122d08: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x122d08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x122d0c: 0xaea20000  sw          $v0, 0x0($s5)
    ctx->pc = 0x122d0cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
    // 0x122d10: 0x8e83002c  lw          $v1, 0x2C($s4)
    ctx->pc = 0x122d10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 44)));
    // 0x122d14: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x122d14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x122d18: 0x16c0ffb1  bnez        $s6, . + 4 + (-0x4F << 2)
    ctx->pc = 0x122D18u;
    {
        const bool branch_taken_0x122d18 = (GPR_U64(ctx, 22) != GPR_U64(ctx, 0));
        ctx->pc = 0x122D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122D18u;
            // 0x122d1c: 0xae83002c  sw          $v1, 0x2C($s4) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 20), 44), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122d18) {
            ctx->pc = 0x122BE0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122be0;
        }
    }
    ctx->pc = 0x122D20u;
    // 0x122d20: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x122d20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_122d24:
    // 0x122d24: 0x26f70004  addiu       $s7, $s7, 0x4
    ctx->pc = 0x122d24u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 4));
    // 0x122d28: 0x8e82001c  lw          $v0, 0x1C($s4)
    ctx->pc = 0x122d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 28)));
    // 0x122d2c: 0x27de0004  addiu       $fp, $fp, 0x4
    ctx->pc = 0x122d2cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x122d30: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x122d30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x122d34: 0xafa30020  sw          $v1, 0x20($sp)
    ctx->pc = 0x122d34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 3));
    // 0x122d38: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x122d38u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x122d3c: 0x8fa3002c  lw          $v1, 0x2C($sp)
    ctx->pc = 0x122d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x122d40: 0x24630004  addiu       $v1, $v1, 0x4
    ctx->pc = 0x122d40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x122d44: 0x1440ff86  bnez        $v0, . + 4 + (-0x7A << 2)
    ctx->pc = 0x122D44u;
    {
        const bool branch_taken_0x122d44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x122D48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122D44u;
            // 0x122d48: 0xafa3002c  sw          $v1, 0x2C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x122d44) {
            ctx->pc = 0x122B60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_122b60;
        }
    }
    ctx->pc = 0x122D4Cu;
    // 0x122d4c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x122d4cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_122d50:
    // 0x122d50: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x122d50u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x122d54: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x122d54u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x122d58: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x122d58u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x122d5c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x122d5cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x122d60: 0xdfb50058  ld          $s5, 0x58($sp)
    ctx->pc = 0x122d60u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x122d64: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x122d64u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x122d68: 0xdfb70068  ld          $s7, 0x68($sp)
    ctx->pc = 0x122d68u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 104)));
    // 0x122d6c: 0xdfbe0070  ld          $fp, 0x70($sp)
    ctx->pc = 0x122d6cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x122d70: 0xdfbf0078  ld          $ra, 0x78($sp)
    ctx->pc = 0x122d70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x122d74: 0x3e00008  jr          $ra
    ctx->pc = 0x122D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122D74u;
            // 0x122d78: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122B60u: goto label_122b60;
            case 0x122B7Cu: goto label_122b7c;
            case 0x122B84u: goto label_122b84;
            case 0x122BACu: goto label_122bac;
            case 0x122BE0u: goto label_122be0;
            case 0x122BF8u: goto label_122bf8;
            case 0x122C14u: goto label_122c14;
            case 0x122C30u: goto label_122c30;
            case 0x122C54u: goto label_122c54;
            case 0x122C70u: goto label_122c70;
            case 0x122C7Cu: goto label_122c7c;
            case 0x122C9Cu: goto label_122c9c;
            case 0x122CA8u: goto label_122ca8;
            case 0x122CC8u: goto label_122cc8;
            case 0x122D04u: goto label_122d04;
            case 0x122D24u: goto label_122d24;
            case 0x122D50u: goto label_122d50;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122D7Cu;
    // 0x122d7c: 0x0  nop
    ctx->pc = 0x122d7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
