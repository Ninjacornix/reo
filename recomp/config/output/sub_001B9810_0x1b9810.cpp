#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B9810
// Address: 0x1b9810 - 0x1b98dc
void sub_001B9810_0x1b9810(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B9810_0x1b9810");
#endif

    switch (ctx->pc) {
        case 0x1b983cu: goto label_1b983c;
        case 0x1b9880u: goto label_1b9880;
        default: break;
    }

    ctx->pc = 0x1b9810u;

    // 0x1b9810: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1b9810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b9814: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1b9814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b9818: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b9818u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b981c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b981cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b9820: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1b9820u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9824: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1b9824u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9828: 0x3c06003c  lui         $a2, 0x3C
    ctx->pc = 0x1b9828u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)60 << 16));
    // 0x1b982c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b982cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b9830: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1b9830u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b9834: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1B9834u;
    {
        const bool branch_taken_0x1b9834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9834u;
            // 0x1b9838: 0x24c62750  addiu       $a2, $a2, 0x2750 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 10064));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9834) {
            ctx->pc = 0x1B98B8u;
            goto label_1b98b8;
        }
    }
    ctx->pc = 0x1B983Cu;
label_1b983c:
    // 0x1b983c: 0x671823  subu        $v1, $v1, $a3
    ctx->pc = 0x1b983cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b9840: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1b9840u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1b9844: 0xc38021  addu        $s0, $a2, $v1
    ctx->pc = 0x1b9844u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1b9848: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1b9848u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1b984c: 0x14600019  bnez        $v1, . + 4 + (0x19 << 2)
    ctx->pc = 0x1B984Cu;
    {
        const bool branch_taken_0x1b984c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B9850u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B984Cu;
            // 0x1b9850: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b984c) {
            ctx->pc = 0x1B98B4u;
            goto label_1b98b4;
        }
    }
    ctx->pc = 0x1B9854u;
    // 0x1b9854: 0x5163c  dsll32      $v0, $a1, 24
    ctx->pc = 0x1b9854u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) << (32 + 24));
    // 0x1b9858: 0xa2030000  sb          $v1, 0x0($s0)
    ctx->pc = 0x1b9858u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1b985c: 0x2163f  dsra32      $v0, $v0, 24
    ctx->pc = 0x1b985cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 24));
    // 0x1b9860: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B9860u;
    {
        const bool branch_taken_0x1b9860 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B9860u;
            // 0x1b9864: 0xa2050001  sb          $a1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b9860) {
            ctx->pc = 0x1B9874u;
            goto label_1b9874;
        }
    }
    ctx->pc = 0x1B9868u;
    // 0x1b9868: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1b9868u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b986c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B986Cu;
    {
        const bool branch_taken_0x1b986c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B9870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B986Cu;
            // 0x1b9870: 0xa2020003  sb          $v0, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b986c) {
            ctx->pc = 0x1B9878u;
            goto label_1b9878;
        }
    }
    ctx->pc = 0x1B9874u;
label_1b9874:
    // 0x1b9874: 0xa2000003  sb          $zero, 0x3($s0)
    ctx->pc = 0x1b9874u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 0));
label_1b9878:
    // 0x1b9878: 0xc06e21c  jal         func_1B8870
    ctx->pc = 0x1B9878u;
    SET_GPR_U32(ctx, 31, 0x1B9880u);
    ctx->pc = 0x1B8870u;
    if (runtime->hasFunction(0x1B8870u)) {
        auto targetFn = runtime->lookupFunction(0x1B8870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9880u; }
        if (ctx->pc != 0x1B9880u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8870_0x1b8870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B9880u; }
        if (ctx->pc != 0x1B9880u) { return; }
    }
    ctx->pc = 0x1B9880u;
label_1b9880:
    // 0x1b9880: 0x3c03001c  lui         $v1, 0x1C
    ctx->pc = 0x1b9880u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)28 << 16));
    // 0x1b9884: 0xa2020002  sb          $v0, 0x2($s0)
    ctx->pc = 0x1b9884u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 2));
    // 0x1b9888: 0x24639ba0  addiu       $v1, $v1, -0x6460
    ctx->pc = 0x1b9888u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941600));
    // 0x1b988c: 0xae030028  sw          $v1, 0x28($s0)
    ctx->pc = 0x1b988cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 3));
    // 0x1b9890: 0xc6220000  lwc1        $f2, 0x0($s1)
    ctx->pc = 0x1b9890u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1b9894: 0xc6210004  lwc1        $f1, 0x4($s1)
    ctx->pc = 0x1b9894u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1b9898: 0xc6200008  lwc1        $f0, 0x8($s1)
    ctx->pc = 0x1b9898u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b989c: 0xe602002c  swc1        $f2, 0x2C($s0)
    ctx->pc = 0x1b989cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 44), bits); }
    // 0x1b98a0: 0xe6010030  swc1        $f1, 0x30($s0)
    ctx->pc = 0x1b98a0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 48), bits); }
    // 0x1b98a4: 0xe6000034  swc1        $f0, 0x34($s0)
    ctx->pc = 0x1b98a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 52), bits); }
    // 0x1b98a8: 0xa6120038  sh          $s2, 0x38($s0)
    ctx->pc = 0x1b98a8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 56), (uint16_t)GPR_U32(ctx, 18));
    // 0x1b98ac: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1B98ACu;
    {
        const bool branch_taken_0x1b98ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B98B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B98ACu;
            // 0x1b98b0: 0xae000024  sw          $zero, 0x24($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b98ac) {
            ctx->pc = 0x1B98C4u;
            goto label_1b98c4;
        }
    }
    ctx->pc = 0x1B98B4u;
label_1b98b4:
    // 0x1b98b4: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1b98b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1b98b8:
    // 0x1b98b8: 0x28e30004  slti        $v1, $a3, 0x4
    ctx->pc = 0x1b98b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x1b98bc: 0x1460ffdf  bnez        $v1, . + 4 + (-0x21 << 2)
    ctx->pc = 0x1B98BCu;
    {
        const bool branch_taken_0x1b98bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B98C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B98BCu;
            // 0x1b98c0: 0x71900  sll         $v1, $a3, 4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b98bc) {
            ctx->pc = 0x1B983Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b983c;
        }
    }
    ctx->pc = 0x1B98C4u;
label_1b98c4:
    // 0x1b98c4: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1b98c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b98c8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b98c8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b98cc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b98ccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b98d0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b98d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b98d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1B98D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B98D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B98D4u;
            // 0x1b98d8: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B983Cu: goto label_1b983c;
            case 0x1B9874u: goto label_1b9874;
            case 0x1B9878u: goto label_1b9878;
            case 0x1B9880u: goto label_1b9880;
            case 0x1B98B4u: goto label_1b98b4;
            case 0x1B98B8u: goto label_1b98b8;
            case 0x1B98C4u: goto label_1b98c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B98DCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
