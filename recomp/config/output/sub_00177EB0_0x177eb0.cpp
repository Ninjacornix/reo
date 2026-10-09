#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177EB0
// Address: 0x177eb0 - 0x178318
void sub_00177EB0_0x177eb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177EB0_0x177eb0");
#endif

    switch (ctx->pc) {
        case 0x177f94u: goto label_177f94;
        case 0x177facu: goto label_177fac;
        case 0x177fb8u: goto label_177fb8;
        case 0x177fd8u: goto label_177fd8;
        case 0x178030u: goto label_178030;
        case 0x17803cu: goto label_17803c;
        case 0x1780b8u: goto label_1780b8;
        case 0x1780c4u: goto label_1780c4;
        case 0x178110u: goto label_178110;
        case 0x178138u: goto label_178138;
        case 0x178148u: goto label_178148;
        case 0x178154u: goto label_178154;
        case 0x178184u: goto label_178184;
        case 0x1781a8u: goto label_1781a8;
        case 0x1781c8u: goto label_1781c8;
        case 0x1781f4u: goto label_1781f4;
        case 0x178218u: goto label_178218;
        case 0x178224u: goto label_178224;
        default: break;
    }

    ctx->pc = 0x177eb0u;

    // 0x177eb0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x177eb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x177eb4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x177eb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177eb8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177eb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177ebc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x177ebcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ec0: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x177ec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x177ec4: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x177ec4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ec8: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x177ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x177ecc: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x177eccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ed0: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x177ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x177ed4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x177ed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x177ed8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x177ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x177edc: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x177edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x177ee0: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x177ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x177ee4: 0xdea20008  ld          $v0, 0x8($s5)
    ctx->pc = 0x177ee4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x177ee8: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x177EE8u;
    {
        const bool branch_taken_0x177ee8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x177EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177EE8u;
            // 0x177eec: 0xe0b02d  daddu       $s6, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177ee8) {
            ctx->pc = 0x177EFCu;
            goto label_177efc;
        }
    }
    ctx->pc = 0x177EF0u;
    // 0x177ef0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x177ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x177ef4: 0x54400010  bnel        $v0, $zero, . + 4 + (0x10 << 2)
    ctx->pc = 0x177EF4u;
    {
        const bool branch_taken_0x177ef4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x177ef4) {
            ctx->pc = 0x177EF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x177EF4u;
            // 0x177ef8: 0xde650000  ld          $a1, 0x0($s3) (Delay Slot)
        SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x177F38u;
            goto label_177f38;
        }
    }
    ctx->pc = 0x177EFCu;
label_177efc:
    // 0x177efc: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x177efcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x177f00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177f00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177f04: 0xfec20000  sd          $v0, 0x0($s6)
    ctx->pc = 0x177f04u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 2));
    // 0x177f08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x177f08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177f0c: 0xde630008  ld          $v1, 0x8($s3)
    ctx->pc = 0x177f0cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x177f10: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x177f10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177f14: 0xfec30008  sd          $v1, 0x8($s6)
    ctx->pc = 0x177f14u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 8), GPR_U64(ctx, 3));
    // 0x177f18: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x177f18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177f1c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x177f1cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177f20: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x177f20u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x177f24: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x177f24u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x177f28: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x177f28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x177f2c: 0x3e00008  jr          $ra
    ctx->pc = 0x177F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177F2Cu;
            // 0x177f30: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177EFCu: goto label_177efc;
            case 0x177F38u: goto label_177f38;
            case 0x177F60u: goto label_177f60;
            case 0x177F94u: goto label_177f94;
            case 0x177FA0u: goto label_177fa0;
            case 0x177FACu: goto label_177fac;
            case 0x177FB0u: goto label_177fb0;
            case 0x177FB8u: goto label_177fb8;
            case 0x177FD8u: goto label_177fd8;
            case 0x177FE8u: goto label_177fe8;
            case 0x178000u: goto label_178000;
            case 0x178004u: goto label_178004;
            case 0x178008u: goto label_178008;
            case 0x178030u: goto label_178030;
            case 0x17803Cu: goto label_17803c;
            case 0x178048u: goto label_178048;
            case 0x17804Cu: goto label_17804c;
            case 0x178080u: goto label_178080;
            case 0x17808Cu: goto label_17808c;
            case 0x1780A0u: goto label_1780a0;
            case 0x1780B8u: goto label_1780b8;
            case 0x1780C4u: goto label_1780c4;
            case 0x1780E8u: goto label_1780e8;
            case 0x1780FCu: goto label_1780fc;
            case 0x178110u: goto label_178110;
            case 0x178128u: goto label_178128;
            case 0x178138u: goto label_178138;
            case 0x178148u: goto label_178148;
            case 0x178154u: goto label_178154;
            case 0x178164u: goto label_178164;
            case 0x178184u: goto label_178184;
            case 0x1781A0u: goto label_1781a0;
            case 0x1781A8u: goto label_1781a8;
            case 0x1781C0u: goto label_1781c0;
            case 0x1781C8u: goto label_1781c8;
            case 0x1781F4u: goto label_1781f4;
            case 0x1781F8u: goto label_1781f8;
            case 0x1781FCu: goto label_1781fc;
            case 0x178200u: goto label_178200;
            case 0x178218u: goto label_178218;
            case 0x178224u: goto label_178224;
            case 0x17822Cu: goto label_17822c;
            case 0x178258u: goto label_178258;
            case 0x1782C8u: goto label_1782c8;
            case 0x1782E4u: goto label_1782e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177F34u;
    // 0x177f34: 0x0  nop
    ctx->pc = 0x177f34u;
    // NOP
label_177f38:
    // 0x177f38: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x177f38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x177f3c: 0xde020188  ld          $v0, 0x188($s0)
    ctx->pc = 0x177f3cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x177f40: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x177f40u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x177f44: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x177f44u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x177f48: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x177f48u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
    // 0x177f4c: 0x14870004  bne         $a0, $a3, . + 4 + (0x4 << 2)
    ctx->pc = 0x177F4Cu;
    {
        const bool branch_taken_0x177f4c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 7));
        ctx->pc = 0x177F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177F4Cu;
            // 0x177f50: 0xfe650000  sd          $a1, 0x0($s3) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177f4c) {
            ctx->pc = 0x177F60u;
            goto label_177f60;
        }
    }
    ctx->pc = 0x177F54u;
    // 0x177f54: 0xae000008  sw          $zero, 0x8($s0)
    ctx->pc = 0x177f54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x177f58: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x177F58u;
    {
        const bool branch_taken_0x177f58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177F58u;
            // 0x177f5c: 0x902d  daddu       $s2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177f58) {
            ctx->pc = 0x178000u;
            goto label_178000;
        }
    }
    ctx->pc = 0x177F60u;
label_177f60:
    // 0x177f60: 0x8e120008  lw          $s2, 0x8($s0)
    ctx->pc = 0x177f60u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x177f64: 0x16400027  bnez        $s2, . + 4 + (0x27 << 2)
    ctx->pc = 0x177F64u;
    {
        const bool branch_taken_0x177f64 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        ctx->pc = 0x177F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177F64u;
            // 0x177f68: 0xde060188  ld          $a2, 0x188($s0) (Delay Slot)
        SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 392)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177f64) {
            ctx->pc = 0x178004u;
            goto label_178004;
        }
    }
    ctx->pc = 0x177F6Cu;
    // 0x177f6c: 0xc5102a  slt         $v0, $a2, $a1
    ctx->pc = 0x177f6cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x177f70: 0x5040001d  beql        $v0, $zero, . + 4 + (0x1D << 2)
    ctx->pc = 0x177F70u;
    {
        const bool branch_taken_0x177f70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x177f70) {
            ctx->pc = 0x177F74u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x177F70u;
            // 0x177f74: 0x8e02000c  lw          $v0, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x177FE8u;
            goto label_177fe8;
        }
    }
    ctx->pc = 0x177F78u;
    // 0x177f78: 0xde030178  ld          $v1, 0x178($s0)
    ctx->pc = 0x177f78u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x177f7c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x177f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x177f80: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x177F80u;
    {
        const bool branch_taken_0x177f80 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x177F84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177F80u;
            // 0x177f84: 0xae070008  sw          $a3, 0x8($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177f80) {
            ctx->pc = 0x177FA0u;
            goto label_177fa0;
        }
    }
    ctx->pc = 0x177F88u;
    // 0x177f88: 0xde050158  ld          $a1, 0x158($s0)
    ctx->pc = 0x177f88u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 344)));
    // 0x177f8c: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x177F8Cu;
    SET_GPR_U32(ctx, 31, 0x177F94u);
    ctx->pc = 0x177F90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177F8Cu;
            // 0x177f90: 0xde640008  ld          $a0, 0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177F94u; }
        if (ctx->pc != 0x177F94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177F94u; }
        if (ctx->pc != 0x177F94u) { return; }
    }
    ctx->pc = 0x177F94u;
label_177f94:
    // 0x177f94: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x177F94u;
    {
        const bool branch_taken_0x177f94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177F98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177F94u;
            // 0x177f98: 0xde050160  ld          $a1, 0x160($s0) (Delay Slot)
        SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 352)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177f94) {
            ctx->pc = 0x177FB0u;
            goto label_177fb0;
        }
    }
    ctx->pc = 0x177F9Cu;
    // 0x177f9c: 0x0  nop
    ctx->pc = 0x177f9cu;
    // NOP
label_177fa0:
    // 0x177fa0: 0xde050168  ld          $a1, 0x168($s0)
    ctx->pc = 0x177fa0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 360)));
    // 0x177fa4: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x177FA4u;
    SET_GPR_U32(ctx, 31, 0x177FACu);
    ctx->pc = 0x177FA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177FA4u;
            // 0x177fa8: 0xde640008  ld          $a0, 0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FACu; }
        if (ctx->pc != 0x177FACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FACu; }
        if (ctx->pc != 0x177FACu) { return; }
    }
    ctx->pc = 0x177FACu;
label_177fac:
    // 0x177fac: 0xde050170  ld          $a1, 0x170($s0)
    ctx->pc = 0x177facu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 368)));
label_177fb0:
    // 0x177fb0: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x177FB0u;
    SET_GPR_U32(ctx, 31, 0x177FB8u);
    ctx->pc = 0x177FB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177FB0u;
            // 0x177fb4: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FB8u; }
        if (ctx->pc != 0x177FB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FB8u; }
        if (ctx->pc != 0x177FB8u) { return; }
    }
    ctx->pc = 0x177FB8u;
label_177fb8:
    // 0x177fb8: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x177fb8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177fbc: 0xdea30000  ld          $v1, 0x0($s5)
    ctx->pc = 0x177fbcu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x177fc0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x177fc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177fc4: 0xfe030178  sd          $v1, 0x178($s0)
    ctx->pc = 0x177fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 3));
    // 0x177fc8: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x177fc8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x177fcc: 0x45102d  daddu       $v0, $v0, $a1
    ctx->pc = 0x177fccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 5));
    // 0x177fd0: 0xc05df64  jal         func_177D90
    ctx->pc = 0x177FD0u;
    SET_GPR_U32(ctx, 31, 0x177FD8u);
    ctx->pc = 0x177FD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177FD0u;
            // 0x177fd4: 0xfe020180  sd          $v0, 0x180($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177D90u;
    if (runtime->hasFunction(0x177D90u)) {
        auto targetFn = runtime->lookupFunction(0x177D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FD8u; }
        if (ctx->pc != 0x177FD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177D90_0x177d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FD8u; }
        if (ctx->pc != 0x177FD8u) { return; }
    }
    ctx->pc = 0x177FD8u;
label_177fd8:
    // 0x177fd8: 0xde060188  ld          $a2, 0x188($s0)
    ctx->pc = 0x177fd8u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x177fdc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x177FDCu;
    {
        const bool branch_taken_0x177fdc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177FDCu;
            // 0x177fe0: 0x8e120008  lw          $s2, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177fdc) {
            ctx->pc = 0x178004u;
            goto label_178004;
        }
    }
    ctx->pc = 0x177FE4u;
    // 0x177fe4: 0x0  nop
    ctx->pc = 0x177fe4u;
    // NOP
label_177fe8:
    // 0x177fe8: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x177FE8u;
    {
        const bool branch_taken_0x177fe8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x177fe8) {
            ctx->pc = 0x177FECu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x177FE8u;
            // 0x177fec: 0xde620000  ld          $v0, 0x0($s3) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x178008u;
            goto label_178008;
        }
    }
    ctx->pc = 0x177FF0u;
    // 0x177ff0: 0xae070008  sw          $a3, 0x8($s0)
    ctx->pc = 0x177ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
    // 0x177ff4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x177FF4u;
    {
        const bool branch_taken_0x177ff4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x177FF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177FF4u;
            // 0x177ff8: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x177ff4) {
            ctx->pc = 0x178004u;
            goto label_178004;
        }
    }
    ctx->pc = 0x177FFCu;
    // 0x177ffc: 0x0  nop
    ctx->pc = 0x177ffcu;
    // NOP
label_178000:
    // 0x178000: 0xde060188  ld          $a2, 0x188($s0)
    ctx->pc = 0x178000u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 392)));
label_178004:
    // 0x178004: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x178004u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
label_178008:
    // 0x178008: 0x2404ffff  addiu       $a0, $zero, -0x1
    ctx->pc = 0x178008u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17800c: 0xde110178  ld          $s1, 0x178($s0)
    ctx->pc = 0x17800cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x178010: 0x46182a  slt         $v1, $v0, $a2
    ctx->pc = 0x178010u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x178014: 0xc3100b  movn        $v0, $a2, $v1
    ctx->pc = 0x178014u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x178018: 0x1224000b  beq         $s1, $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x178018u;
    {
        const bool branch_taken_0x178018 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 4));
        ctx->pc = 0x17801Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178018u;
            // 0x17801c: 0xfe020188  sd          $v0, 0x188($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 392), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178018) {
            ctx->pc = 0x178048u;
            goto label_178048;
        }
    }
    ctx->pc = 0x178020u;
    // 0x178020: 0xdea50000  ld          $a1, 0x0($s5)
    ctx->pc = 0x178020u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x178024: 0xde640008  ld          $a0, 0x8($s3)
    ctx->pc = 0x178024u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178028: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x178028u;
    SET_GPR_U32(ctx, 31, 0x178030u);
    ctx->pc = 0x17802Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178028u;
            // 0x17802c: 0xb1282f  dsubu       $a1, $a1, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178030u; }
        if (ctx->pc != 0x178030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178030u; }
        if (ctx->pc != 0x178030u) { return; }
    }
    ctx->pc = 0x178030u;
label_178030:
    // 0x178030: 0xdea50008  ld          $a1, 0x8($s5)
    ctx->pc = 0x178030u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x178034: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x178034u;
    SET_GPR_U32(ctx, 31, 0x17803Cu);
    ctx->pc = 0x178038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178034u;
            // 0x178038: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17803Cu; }
        if (ctx->pc != 0x17803Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17803Cu; }
        if (ctx->pc != 0x17803Cu) { return; }
    }
    ctx->pc = 0x17803Cu;
label_17803c:
    // 0x17803c: 0xde030180  ld          $v1, 0x180($s0)
    ctx->pc = 0x17803cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 384)));
    // 0x178040: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x178040u;
    {
        const bool branch_taken_0x178040 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x178044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178040u;
            // 0x178044: 0x62a02d  daddu       $s4, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178040) {
            ctx->pc = 0x17804Cu;
            goto label_17804c;
        }
    }
    ctx->pc = 0x178048u;
label_178048:
    // 0x178048: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x178048u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17804c:
    // 0x17804c: 0x56400014  bnel        $s2, $zero, . + 4 + (0x14 << 2)
    ctx->pc = 0x17804Cu;
    {
        const bool branch_taken_0x17804c = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x17804c) {
            ctx->pc = 0x178050u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17804Cu;
            // 0x178050: 0x8e03000c  lw          $v1, 0xC($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1780A0u;
            goto label_1780a0;
        }
    }
    ctx->pc = 0x178054u;
    // 0x178054: 0xde030188  ld          $v1, 0x188($s0)
    ctx->pc = 0x178054u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x178058: 0x74102a  slt         $v0, $v1, $s4
    ctx->pc = 0x178058u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x17805c: 0x10400068  beqz        $v0, . + 4 + (0x68 << 2)
    ctx->pc = 0x17805Cu;
    {
        const bool branch_taken_0x17805c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17805Cu;
            // 0x178060: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17805c) {
            ctx->pc = 0x178200u;
            goto label_178200;
        }
    }
    ctx->pc = 0x178064u;
    // 0x178064: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x178064u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x178068: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x178068u;
    {
        const bool branch_taken_0x178068 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17806Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178068u;
            // 0x17806c: 0xdea20000  ld          $v0, 0x0($s5) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178068) {
            ctx->pc = 0x178080u;
            goto label_178080;
        }
    }
    ctx->pc = 0x178070u;
    // 0x178070: 0xfe030180  sd          $v1, 0x180($s0)
    ctx->pc = 0x178070u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 3));
    // 0x178074: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x178074u;
    {
        const bool branch_taken_0x178074 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x178078u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178074u;
            // 0x178078: 0xfe020178  sd          $v0, 0x178($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178074) {
            ctx->pc = 0x17808Cu;
            goto label_17808c;
        }
    }
    ctx->pc = 0x17807Cu;
    // 0x17807c: 0x0  nop
    ctx->pc = 0x17807cu;
    // NOP
label_178080:
    // 0x178080: 0xde030128  ld          $v1, 0x128($s0)
    ctx->pc = 0x178080u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x178084: 0xfe020178  sd          $v0, 0x178($s0)
    ctx->pc = 0x178084u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 2));
    // 0x178088: 0xfe030180  sd          $v1, 0x180($s0)
    ctx->pc = 0x178088u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 3));
label_17808c:
    // 0x17808c: 0x8e020190  lw          $v0, 0x190($s0)
    ctx->pc = 0x17808cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 400)));
    // 0x178090: 0xde110178  ld          $s1, 0x178($s0)
    ctx->pc = 0x178090u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x178094: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x178094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x178098: 0x10000058  b           . + 4 + (0x58 << 2)
    ctx->pc = 0x178098u;
    {
        const bool branch_taken_0x178098 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17809Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178098u;
            // 0x17809c: 0xae020190  sw          $v0, 0x190($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178098) {
            ctx->pc = 0x1781FCu;
            goto label_1781fc;
        }
    }
    ctx->pc = 0x1780A0u;
label_1780a0:
    // 0x1780a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1780a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1780a4: 0x14620056  bne         $v1, $v0, . + 4 + (0x56 << 2)
    ctx->pc = 0x1780A4u;
    {
        const bool branch_taken_0x1780a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1780A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1780A4u;
            // 0x1780a8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1780a4) {
            ctx->pc = 0x178200u;
            goto label_178200;
        }
    }
    ctx->pc = 0x1780ACu;
    // 0x1780ac: 0xde050148  ld          $a1, 0x148($s0)
    ctx->pc = 0x1780acu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 328)));
    // 0x1780b0: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x1780B0u;
    SET_GPR_U32(ctx, 31, 0x1780B8u);
    ctx->pc = 0x1780B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1780B0u;
            // 0x1780b4: 0xde640008  ld          $a0, 0x8($s3) (Delay Slot)
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1780B8u; }
        if (ctx->pc != 0x1780B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1780B8u; }
        if (ctx->pc != 0x1780B8u) { return; }
    }
    ctx->pc = 0x1780B8u;
label_1780b8:
    // 0x1780b8: 0xde050150  ld          $a1, 0x150($s0)
    ctx->pc = 0x1780b8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 336)));
    // 0x1780bc: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x1780BCu;
    SET_GPR_U32(ctx, 31, 0x1780C4u);
    ctx->pc = 0x1780C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1780BCu;
            // 0x1780c0: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1780C4u; }
        if (ctx->pc != 0x1780C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1780C4u; }
        if (ctx->pc != 0x1780C4u) { return; }
    }
    ctx->pc = 0x1780C4u;
label_1780c4:
    // 0x1780c4: 0xde650000  ld          $a1, 0x0($s3)
    ctx->pc = 0x1780c4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1780c8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1780c8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1780cc: 0xb4102f  dsubu       $v0, $a1, $s4
    ctx->pc = 0x1780ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) - GPR_U64(ctx, 20));
    // 0x1780d0: 0x4400005  bltz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1780D0u;
    {
        const bool branch_taken_0x1780d0 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1780D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1780D0u;
            // 0x1780d4: 0x62102a  slt         $v0, $v1, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1780d0) {
            ctx->pc = 0x1780E8u;
            goto label_1780e8;
        }
    }
    ctx->pc = 0x1780D8u;
    // 0x1780d8: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x1780D8u;
    {
        const bool branch_taken_0x1780d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1780d8) {
            ctx->pc = 0x1780DCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1780D8u;
            // 0x1780dc: 0xdea20000  ld          $v0, 0x0($s5) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1780FCu;
            goto label_1780fc;
        }
    }
    ctx->pc = 0x1780E0u;
    // 0x1780e0: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1780E0u;
    {
        const bool branch_taken_0x1780e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1780E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1780E0u;
            // 0x1780e4: 0xb4282f  dsubu       $a1, $a1, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1780e0) {
            ctx->pc = 0x178128u;
            goto label_178128;
        }
    }
    ctx->pc = 0x1780E8u;
label_1780e8:
    // 0x1780e8: 0x285102f  dsubu       $v0, $s4, $a1
    ctx->pc = 0x1780e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) - GPR_U64(ctx, 5));
    // 0x1780ec: 0x62102a  slt         $v0, $v1, $v0
    ctx->pc = 0x1780ecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1780f0: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1780F0u;
    {
        const bool branch_taken_0x1780f0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1780F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1780F0u;
            // 0x1780f4: 0xb4282f  dsubu       $a1, $a1, $s4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1780f0) {
            ctx->pc = 0x178128u;
            goto label_178128;
        }
    }
    ctx->pc = 0x1780F8u;
    // 0x1780f8: 0xdea20000  ld          $v0, 0x0($s5)
    ctx->pc = 0x1780f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
label_1780fc:
    // 0x1780fc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1780fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178100: 0xfe020178  sd          $v0, 0x178($s0)
    ctx->pc = 0x178100u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 2));
    // 0x178104: 0xde630000  ld          $v1, 0x0($s3)
    ctx->pc = 0x178104u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x178108: 0xc05df64  jal         func_177D90
    ctx->pc = 0x178108u;
    SET_GPR_U32(ctx, 31, 0x178110u);
    ctx->pc = 0x17810Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178108u;
            // 0x17810c: 0xfe030180  sd          $v1, 0x180($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177D90u;
    if (runtime->hasFunction(0x177D90u)) {
        auto targetFn = runtime->lookupFunction(0x177D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178110u; }
        if (ctx->pc != 0x178110u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177D90_0x177d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178110u; }
        if (ctx->pc != 0x178110u) { return; }
    }
    ctx->pc = 0x178110u;
label_178110:
    // 0x178110: 0x8e0201a0  lw          $v0, 0x1A0($s0)
    ctx->pc = 0x178110u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 416)));
    // 0x178114: 0x8e120008  lw          $s2, 0x8($s0)
    ctx->pc = 0x178114u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x178118: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x178118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x17811c: 0xde110178  ld          $s1, 0x178($s0)
    ctx->pc = 0x17811cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x178120: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x178120u;
    {
        const bool branch_taken_0x178120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x178124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178120u;
            // 0x178124: 0xae0201a0  sw          $v0, 0x1A0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178120) {
            ctx->pc = 0x1781FCu;
            goto label_1781fc;
        }
    }
    ctx->pc = 0x178128u;
label_178128:
    // 0x178128: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x178128u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x17812c: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x17812cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x178130: 0xc05e0c6  jal         func_178318
    ctx->pc = 0x178130u;
    SET_GPR_U32(ctx, 31, 0x178138u);
    ctx->pc = 0x178134u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178130u;
            // 0x178134: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178318u;
    if (runtime->hasFunction(0x178318u)) {
        auto targetFn = runtime->lookupFunction(0x178318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178138u; }
        if (ctx->pc != 0x178138u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178318_0x178318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178138u; }
        if (ctx->pc != 0x178138u) { return; }
    }
    ctx->pc = 0x178138u;
label_178138:
    // 0x178138: 0xde640008  ld          $a0, 0x8($s3)
    ctx->pc = 0x178138u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17813c: 0xde050138  ld          $a1, 0x138($s0)
    ctx->pc = 0x17813cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 312)));
    // 0x178140: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x178140u;
    SET_GPR_U32(ctx, 31, 0x178148u);
    ctx->pc = 0x178144u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178140u;
            // 0x178144: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178148u; }
        if (ctx->pc != 0x178148u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178148u; }
        if (ctx->pc != 0x178148u) { return; }
    }
    ctx->pc = 0x178148u;
label_178148:
    // 0x178148: 0xde050140  ld          $a1, 0x140($s0)
    ctx->pc = 0x178148u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 320)));
    // 0x17814c: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x17814Cu;
    SET_GPR_U32(ctx, 31, 0x178154u);
    ctx->pc = 0x178150u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17814Cu;
            // 0x178150: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178154u; }
        if (ctx->pc != 0x178154u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178154u; }
        if (ctx->pc != 0x178154u) { return; }
    }
    ctx->pc = 0x178154u;
label_178154:
    // 0x178154: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x178154u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178158: 0x6210002  bgez        $s1, . + 4 + (0x2 << 2)
    ctx->pc = 0x178158u;
    {
        const bool branch_taken_0x178158 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x17815Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178158u;
            // 0x17815c: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178158) {
            ctx->pc = 0x178164u;
            goto label_178164;
        }
    }
    ctx->pc = 0x178160u;
    // 0x178160: 0x2102f  dsubu       $v0, $zero, $v0
    ctx->pc = 0x178160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
label_178164:
    // 0x178164: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x178164u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x178168: 0x50400023  beql        $v0, $zero, . + 4 + (0x23 << 2)
    ctx->pc = 0x178168u;
    {
        const bool branch_taken_0x178168 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x178168) {
            ctx->pc = 0x17816Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x178168u;
            // 0x17816c: 0x8e120008  lw          $s2, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1781F8u;
            goto label_1781f8;
        }
    }
    ctx->pc = 0x178170u;
    // 0x178170: 0x251102a  slt         $v0, $s2, $s1
    ctx->pc = 0x178170u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x178174: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x178174u;
    {
        const bool branch_taken_0x178174 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x178178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178174u;
            // 0x178178: 0x112078  dsll        $a0, $s1, 1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << 1);
        ctx->in_delay_slot = false;
        if (branch_taken_0x178174) {
            ctx->pc = 0x1781A0u;
            goto label_1781a0;
        }
    }
    ctx->pc = 0x17817Cu;
    // 0x17817c: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x17817Cu;
    SET_GPR_U32(ctx, 31, 0x178184u);
    ctx->pc = 0x178180u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17817Cu;
            // 0x178180: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178184u; }
        if (ctx->pc != 0x178184u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178184u; }
        if (ctx->pc != 0x178184u) { return; }
    }
    ctx->pc = 0x178184u;
label_178184:
    // 0x178184: 0x8e030194  lw          $v1, 0x194($s0)
    ctx->pc = 0x178184u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 404)));
    // 0x178188: 0x6444ffff  daddiu      $a0, $v0, -0x1
    ctx->pc = 0x178188u;
    SET_GPR_S64(ctx, 4, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)4294967295);
    // 0x17818c: 0x4103c  dsll32      $v0, $a0, 0
    ctx->pc = 0x17818cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x178190: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x178190u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x178194: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x178194u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x178198: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x178198u;
    {
        const bool branch_taken_0x178198 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17819Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178198u;
            // 0x17819c: 0xae030194  sw          $v1, 0x194($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178198) {
            ctx->pc = 0x1781C0u;
            goto label_1781c0;
        }
    }
    ctx->pc = 0x1781A0u;
label_1781a0:
    // 0x1781a0: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x1781A0u;
    SET_GPR_U32(ctx, 31, 0x1781A8u);
    ctx->pc = 0x1781A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1781A0u;
            // 0x1781a4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781A8u; }
        if (ctx->pc != 0x1781A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781A8u; }
        if (ctx->pc != 0x1781A8u) { return; }
    }
    ctx->pc = 0x1781A8u;
label_1781a8:
    // 0x1781a8: 0x8e030198  lw          $v1, 0x198($s0)
    ctx->pc = 0x1781a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x1781ac: 0x64440001  daddiu      $a0, $v0, 0x1
    ctx->pc = 0x1781acu;
    SET_GPR_S64(ctx, 4, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)1);
    // 0x1781b0: 0x4103c  dsll32      $v0, $a0, 0
    ctx->pc = 0x1781b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1781b4: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x1781b4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1781b8: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x1781b8u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1781bc: 0xae030198  sw          $v1, 0x198($s0)
    ctx->pc = 0x1781bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 3));
label_1781c0:
    // 0x1781c0: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x1781C0u;
    SET_GPR_U32(ctx, 31, 0x1781C8u);
    ctx->pc = 0x1781C4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1781C0u;
            // 0x1781c4: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781C8u; }
        if (ctx->pc != 0x1781C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781C8u; }
        if (ctx->pc != 0x1781C8u) { return; }
    }
    ctx->pc = 0x1781C8u;
label_1781c8:
    // 0x1781c8: 0xdea30000  ld          $v1, 0x0($s5)
    ctx->pc = 0x1781c8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1781cc: 0x22ffe  dsrl32      $a1, $v0, 31
    ctx->pc = 0x1781ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 31));
    // 0x1781d0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1781d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1781d4: 0xa2282d  daddu       $a1, $a1, $v0
    ctx->pc = 0x1781d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 2));
    // 0x1781d8: 0xfe030178  sd          $v1, 0x178($s0)
    ctx->pc = 0x1781d8u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 3));
    // 0x1781dc: 0x5287b  dsra        $a1, $a1, 1
    ctx->pc = 0x1781dcu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> 1);
    // 0x1781e0: 0x285102d  daddu       $v0, $s4, $a1
    ctx->pc = 0x1781e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 5));
    // 0x1781e4: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1781e4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1781e8: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1781e8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1781ec: 0xc05e0de  jal         func_178378
    ctx->pc = 0x1781ECu;
    SET_GPR_U32(ctx, 31, 0x1781F4u);
    ctx->pc = 0x1781F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1781ECu;
            // 0x1781f0: 0xfe020180  sd          $v0, 0x180($s0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x178378u;
    if (runtime->hasFunction(0x178378u)) {
        auto targetFn = runtime->lookupFunction(0x178378u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781F4u; }
        if (ctx->pc != 0x1781F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00178378_0x178378(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781F4u; }
        if (ctx->pc != 0x1781F4u) { return; }
    }
    ctx->pc = 0x1781F4u;
label_1781f4:
    // 0x1781f4: 0x8e120008  lw          $s2, 0x8($s0)
    ctx->pc = 0x1781f4u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_1781f8:
    // 0x1781f8: 0xde110178  ld          $s1, 0x178($s0)
    ctx->pc = 0x1781f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
label_1781fc:
    // 0x1781fc: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1781fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_178200:
    // 0x178200: 0x5222000a  beql        $s1, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x178200u;
    {
        const bool branch_taken_0x178200 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x178200) {
            ctx->pc = 0x178204u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x178200u;
            // 0x178204: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x17822Cu;
            goto label_17822c;
        }
    }
    ctx->pc = 0x178208u;
    // 0x178208: 0xdea50000  ld          $a1, 0x0($s5)
    ctx->pc = 0x178208u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x17820c: 0xde640008  ld          $a0, 0x8($s3)
    ctx->pc = 0x17820cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178210: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x178210u;
    SET_GPR_U32(ctx, 31, 0x178218u);
    ctx->pc = 0x178214u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178210u;
            // 0x178214: 0xb1282f  dsubu       $a1, $a1, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178218u; }
        if (ctx->pc != 0x178218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178218u; }
        if (ctx->pc != 0x178218u) { return; }
    }
    ctx->pc = 0x178218u;
label_178218:
    // 0x178218: 0xdea50008  ld          $a1, 0x8($s5)
    ctx->pc = 0x178218u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x17821c: 0xc043ec6  jal         func_10FB18
    ctx->pc = 0x17821Cu;
    SET_GPR_U32(ctx, 31, 0x178224u);
    ctx->pc = 0x178220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17821Cu;
            // 0x178220: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FB18u;
    if (runtime->hasFunction(0x10FB18u)) {
        auto targetFn = runtime->lookupFunction(0x10FB18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178224u; }
        if (ctx->pc != 0x178224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178224u; }
        if (ctx->pc != 0x178224u) { return; }
    }
    ctx->pc = 0x178224u;
label_178224:
    // 0x178224: 0xde030180  ld          $v1, 0x180($s0)
    ctx->pc = 0x178224u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 384)));
    // 0x178228: 0x62182d  daddu       $v1, $v1, $v0
    ctx->pc = 0x178228u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 2));
label_17822c:
    // 0x17822c: 0xfec30000  sd          $v1, 0x0($s6)
    ctx->pc = 0x17822cu;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 3));
    // 0x178230: 0xde620008  ld          $v0, 0x8($s3)
    ctx->pc = 0x178230u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178234: 0xfec20008  sd          $v0, 0x8($s6)
    ctx->pc = 0x178234u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 8), GPR_U64(ctx, 2));
    // 0x178238: 0xde040128  ld          $a0, 0x128($s0)
    ctx->pc = 0x178238u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x17823c: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x17823cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x178240: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x178240u;
    {
        const bool branch_taken_0x178240 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x178240) {
            ctx->pc = 0x178244u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x178240u;
            // 0x178244: 0xde620000  ld          $v0, 0x0($s3) (Delay Slot)
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x178258u;
            goto label_178258;
        }
    }
    ctx->pc = 0x178248u;
    // 0x178248: 0xfec40000  sd          $a0, 0x0($s6)
    ctx->pc = 0x178248u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 4));
    // 0x17824c: 0xde020130  ld          $v0, 0x130($s0)
    ctx->pc = 0x17824cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x178250: 0xfec20008  sd          $v0, 0x8($s6)
    ctx->pc = 0x178250u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 8), GPR_U64(ctx, 2));
    // 0x178254: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x178254u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
label_178258:
    // 0x178258: 0xfe020108  sd          $v0, 0x108($s0)
    ctx->pc = 0x178258u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 264), GPR_U64(ctx, 2));
    // 0x17825c: 0xde630008  ld          $v1, 0x8($s3)
    ctx->pc = 0x17825cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178260: 0xfe030110  sd          $v1, 0x110($s0)
    ctx->pc = 0x178260u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 272), GPR_U64(ctx, 3));
    // 0x178264: 0xdea20000  ld          $v0, 0x0($s5)
    ctx->pc = 0x178264u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x178268: 0xfe020118  sd          $v0, 0x118($s0)
    ctx->pc = 0x178268u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 280), GPR_U64(ctx, 2));
    // 0x17826c: 0xdea30008  ld          $v1, 0x8($s5)
    ctx->pc = 0x17826cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x178270: 0xfe030120  sd          $v1, 0x120($s0)
    ctx->pc = 0x178270u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 288), GPR_U64(ctx, 3));
    // 0x178274: 0xdec20000  ld          $v0, 0x0($s6)
    ctx->pc = 0x178274u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x178278: 0xfe020128  sd          $v0, 0x128($s0)
    ctx->pc = 0x178278u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 296), GPR_U64(ctx, 2));
    // 0x17827c: 0xdec30008  ld          $v1, 0x8($s6)
    ctx->pc = 0x17827cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x178280: 0xfe030130  sd          $v1, 0x130($s0)
    ctx->pc = 0x178280u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 304), GPR_U64(ctx, 3));
    // 0x178284: 0xde620000  ld          $v0, 0x0($s3)
    ctx->pc = 0x178284u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x178288: 0xdec30000  ld          $v1, 0x0($s6)
    ctx->pc = 0x178288u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x17828c: 0x43102f  dsubu       $v0, $v0, $v1
    ctx->pc = 0x17828cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x178290: 0x2383c  dsll32      $a3, $v0, 0
    ctx->pc = 0x178290u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x178294: 0x7383f  dsra32      $a3, $a3, 0
    ctx->pc = 0x178294u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x178298: 0x5640000b  bnel        $s2, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x178298u;
    {
        const bool branch_taken_0x178298 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x178298) {
            ctx->pc = 0x17829Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x178298u;
            // 0x17829c: 0x8e0201b4  lw          $v0, 0x1B4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1782C8u;
            goto label_1782c8;
        }
    }
    ctx->pc = 0x1782A0u;
    // 0x1782a0: 0x8e0201ac  lw          $v0, 0x1AC($s0)
    ctx->pc = 0x1782a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 428)));
    // 0x1782a4: 0x8e0301b0  lw          $v1, 0x1B0($s0)
    ctx->pc = 0x1782a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 432)));
    // 0x1782a8: 0xe2202a  slt         $a0, $a3, $v0
    ctx->pc = 0x1782a8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1782ac: 0x67282a  slt         $a1, $v1, $a3
    ctx->pc = 0x1782acu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1782b0: 0xe4100a  movz        $v0, $a3, $a0
    ctx->pc = 0x1782b0u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 7));
    // 0x1782b4: 0xe5180a  movz        $v1, $a3, $a1
    ctx->pc = 0x1782b4u;
    if (GPR_U64(ctx, 5) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x1782b8: 0xae0201ac  sw          $v0, 0x1AC($s0)
    ctx->pc = 0x1782b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 2));
    // 0x1782bc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1782BCu;
    {
        const bool branch_taken_0x1782bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1782C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1782BCu;
            // 0x1782c0: 0xae0301b0  sw          $v1, 0x1B0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 432), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1782bc) {
            ctx->pc = 0x1782E4u;
            goto label_1782e4;
        }
    }
    ctx->pc = 0x1782C4u;
    // 0x1782c4: 0x0  nop
    ctx->pc = 0x1782c4u;
    // NOP
label_1782c8:
    // 0x1782c8: 0x8e0301b8  lw          $v1, 0x1B8($s0)
    ctx->pc = 0x1782c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x1782cc: 0xe2202a  slt         $a0, $a3, $v0
    ctx->pc = 0x1782ccu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1782d0: 0x67282a  slt         $a1, $v1, $a3
    ctx->pc = 0x1782d0u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x1782d4: 0xe4100a  movz        $v0, $a3, $a0
    ctx->pc = 0x1782d4u;
    if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 7));
    // 0x1782d8: 0xe5180a  movz        $v1, $a3, $a1
    ctx->pc = 0x1782d8u;
    if (GPR_U64(ctx, 5) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 7));
    // 0x1782dc: 0xae0201b4  sw          $v0, 0x1B4($s0)
    ctx->pc = 0x1782dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 436), GPR_U32(ctx, 2));
    // 0x1782e0: 0xae0301b8  sw          $v1, 0x1B8($s0)
    ctx->pc = 0x1782e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 440), GPR_U32(ctx, 3));
label_1782e4:
    // 0x1782e4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1782e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1782e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1782e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1782ec: 0xac50f1e0  sw          $s0, -0xE20($v0)
    ctx->pc = 0x1782ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963680), GPR_U32(ctx, 16));
    // 0x1782f0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1782f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1782f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1782f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1782f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1782f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1782fc: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1782fcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178300: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x178300u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178304: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x178304u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178308: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x178308u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17830c: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x17830cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x178310: 0x805e168  j           func_1785A0
    ctx->pc = 0x178310u;
    ctx->pc = 0x178314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178310u;
            // 0x178314: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1785A0u;
    if (runtime->hasFunction(0x1785A0u)) {
        auto targetFn = runtime->lookupFunction(0x1785A0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001785A0_0x1785a0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x178318u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
