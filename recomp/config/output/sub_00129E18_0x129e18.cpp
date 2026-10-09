#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00129E18
// Address: 0x129e18 - 0x129f70
void sub_00129E18_0x129e18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00129E18_0x129e18");
#endif

    switch (ctx->pc) {
        case 0x129e5cu: goto label_129e5c;
        case 0x129eb0u: goto label_129eb0;
        case 0x129ef0u: goto label_129ef0;
        case 0x129f2cu: goto label_129f2c;
        default: break;
    }

    ctx->pc = 0x129e18u;

    // 0x129e18: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x129e18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x129e1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x129e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x129e20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x129e20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e24: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x129e24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x129e28: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x129e28u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e2c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x129e2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x129e30: 0x120982d  daddu       $s3, $t1, $zero
    ctx->pc = 0x129e30u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e34: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x129e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x129e38: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x129e38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x129e3c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x129e3cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e40: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x129e40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x129e44: 0x100b02d  daddu       $s6, $t0, $zero
    ctx->pc = 0x129e44u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e48: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x129e48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x129e4c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x129e4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x129e50: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x129e50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x129e54: 0xc04a75e  jal         func_129D78
    ctx->pc = 0x129E54u;
    SET_GPR_U32(ctx, 31, 0x129E5Cu);
    ctx->pc = 0x129E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129E54u;
            // 0x129e58: 0xc0b82d  daddu       $s7, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D78u;
    if (runtime->hasFunction(0x129D78u)) {
        auto targetFn = runtime->lookupFunction(0x129D78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129E5Cu; }
        if (ctx->pc != 0x129E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D78_0x129d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129E5Cu; }
        if (ctx->pc != 0x129E5Cu) { return; }
    }
    ctx->pc = 0x129E5Cu;
label_129e5c:
    // 0x129e5c: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x129e5cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129e60: 0x6830007  bgezl       $s4, . + 4 + (0x7 << 2)
    ctx->pc = 0x129E60u;
    {
        const bool branch_taken_0x129e60 = (GPR_S64(ctx, 20) >= 0);
        if (branch_taken_0x129e60) {
            ctx->pc = 0x129E64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129E60u;
            // 0x129e64: 0x101080  sll         $v0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129E80u;
            goto label_129e80;
        }
    }
    ctx->pc = 0x129E68u;
    // 0x129e68: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x129e68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x129e6c: 0xaea00000  sw          $zero, 0x0($s5)
    ctx->pc = 0x129e6cu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x129e70: 0xaec30000  sw          $v1, 0x0($s6)
    ctx->pc = 0x129e70u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 3));
    // 0x129e74: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x129E74u;
    {
        const bool branch_taken_0x129e74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129E74u;
            // 0x129e78: 0xae630000  sw          $v1, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129e74) {
            ctx->pc = 0x129F44u;
            goto label_129f44;
        }
    }
    ctx->pc = 0x129E7Cu;
    // 0x129e7c: 0x0  nop
    ctx->pc = 0x129e7cu;
    // NOP
label_129e80:
    // 0x129e80: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x129e80u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x129e84: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x129e84u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x129e88: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x129e88u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x129e8c: 0x8e31cd00  lw          $s1, -0x3300($s1)
    ctx->pc = 0x129e8cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4294954240)));
    // 0x129e90: 0x8223000f  lb          $v1, 0xF($s1)
    ctx->pc = 0x129e90u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 15)));
    // 0x129e94: 0x54640012  bnel        $v1, $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x129E94u;
    {
        const bool branch_taken_0x129e94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x129e94) {
            ctx->pc = 0x129E98u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x129E94u;
            // 0x129e98: 0x96300118  lhu         $s0, 0x118($s1) (Delay Slot)
        SET_GPR_U32(ctx, 16, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 280)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x129EE0u;
            goto label_129ee0;
        }
    }
    ctx->pc = 0x129E9Cu;
    // 0x129e9c: 0x8e300118  lw          $s0, 0x118($s1)
    ctx->pc = 0x129e9cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 280)));
    // 0x129ea0: 0x1a40000a  blez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x129EA0u;
    {
        const bool branch_taken_0x129ea0 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x129EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129EA0u;
            // 0x129ea4: 0x2625011c  addiu       $a1, $s1, 0x11C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 284));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129ea0) {
            ctx->pc = 0x129ECCu;
            goto label_129ecc;
        }
    }
    ctx->pc = 0x129EA8u;
    // 0x129ea8: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x129ea8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129eac: 0x240182d  daddu       $v1, $s2, $zero
    ctx->pc = 0x129eacu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_129eb0:
    // 0x129eb0: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x129eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x129eb4: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x129eb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x129eb8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x129eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x129ebc: 0x0  nop
    ctx->pc = 0x129ebcu;
    // NOP
    // 0x129ec0: 0x0  nop
    ctx->pc = 0x129ec0u;
    // NOP
    // 0x129ec4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x129EC4u;
    {
        const bool branch_taken_0x129ec4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x129EC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129EC4u;
            // 0x129ec8: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129ec4) {
            ctx->pc = 0x129EB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_129eb0;
        }
    }
    ctx->pc = 0x129ECCu;
label_129ecc:
    // 0x129ecc: 0x121080  sll         $v0, $s2, 2
    ctx->pc = 0x129eccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 2));
    // 0x129ed0: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x129ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x129ed4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x129ED4u;
    {
        const bool branch_taken_0x129ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x129ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129ED4u;
            // 0x129ed8: 0x8c430000  lw          $v1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129ed4) {
            ctx->pc = 0x129F18u;
            goto label_129f18;
        }
    }
    ctx->pc = 0x129EDCu;
    // 0x129edc: 0x0  nop
    ctx->pc = 0x129edcu;
    // NOP
label_129ee0:
    // 0x129ee0: 0x1a40000a  blez        $s2, . + 4 + (0xA << 2)
    ctx->pc = 0x129EE0u;
    {
        const bool branch_taken_0x129ee0 = (GPR_S64(ctx, 18) <= 0);
        ctx->pc = 0x129EE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129EE0u;
            // 0x129ee4: 0x2625011a  addiu       $a1, $s1, 0x11A (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 282));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129ee0) {
            ctx->pc = 0x129F0Cu;
            goto label_129f0c;
        }
    }
    ctx->pc = 0x129EE8u;
    // 0x129ee8: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x129ee8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129eec: 0x240182d  daddu       $v1, $s2, $zero
    ctx->pc = 0x129eecu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_129ef0:
    // 0x129ef0: 0x94820000  lhu         $v0, 0x0($a0)
    ctx->pc = 0x129ef0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x129ef4: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x129ef4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x129ef8: 0x2463ffff  addiu       $v1, $v1, -0x1
    ctx->pc = 0x129ef8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x129efc: 0x0  nop
    ctx->pc = 0x129efcu;
    // NOP
    // 0x129f00: 0x0  nop
    ctx->pc = 0x129f00u;
    // NOP
    // 0x129f04: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x129F04u;
    {
        const bool branch_taken_0x129f04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x129F08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129F04u;
            // 0x129f08: 0x2028021  addu        $s0, $s0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x129f04) {
            ctx->pc = 0x129EF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_129ef0;
        }
    }
    ctx->pc = 0x129F0Cu;
label_129f0c:
    // 0x129f0c: 0x121040  sll         $v0, $s2, 1
    ctx->pc = 0x129f0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 18), 1));
    // 0x129f10: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x129f10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x129f14: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x129f14u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
label_129f18:
    // 0x129f18: 0xae630000  sw          $v1, 0x0($s3)
    ctx->pc = 0x129f18u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x129f1c: 0x2e0202d  daddu       $a0, $s7, $zero
    ctx->pc = 0x129f1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129f20: 0x26250010  addiu       $a1, $s1, 0x10
    ctx->pc = 0x129f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x129f24: 0xc042d7e  jal         func_10B5F8
    ctx->pc = 0x129F24u;
    SET_GPR_U32(ctx, 31, 0x129F2Cu);
    ctx->pc = 0x129F28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x129F24u;
            // 0x129f28: 0x24060100  addiu       $a2, $zero, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 256));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B5F8u;
    if (runtime->hasFunction(0x10B5F8u)) {
        auto targetFn = runtime->lookupFunction(0x10B5F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129F2Cu; }
        if (ctx->pc != 0x129F2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x129F2Cu; }
        if (ctx->pc != 0x129F2Cu) { return; }
    }
    ctx->pc = 0x129F2Cu;
label_129f2c:
    // 0x129f2c: 0x8e240110  lw          $a0, 0x110($s1)
    ctx->pc = 0x129f2cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 272)));
    // 0x129f30: 0x8e230114  lw          $v1, 0x114($s1)
    ctx->pc = 0x129f30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 276)));
    // 0x129f34: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x129f34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x129f38: 0xaea40000  sw          $a0, 0x0($s5)
    ctx->pc = 0x129f38u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 4));
    // 0x129f3c: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x129f3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x129f40: 0xaec30000  sw          $v1, 0x0($s6)
    ctx->pc = 0x129f40u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 3));
label_129f44:
    // 0x129f44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x129f44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x129f48: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x129f48u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x129f4c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x129f4cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x129f50: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x129f50u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x129f54: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x129f54u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x129f58: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x129f58u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x129f5c: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x129f5cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x129f60: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x129f60u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x129f64: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x129f64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x129f68: 0x3e00008  jr          $ra
    ctx->pc = 0x129F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x129F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x129F68u;
            // 0x129f6c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x129E5Cu: goto label_129e5c;
            case 0x129E80u: goto label_129e80;
            case 0x129EB0u: goto label_129eb0;
            case 0x129ECCu: goto label_129ecc;
            case 0x129EE0u: goto label_129ee0;
            case 0x129EF0u: goto label_129ef0;
            case 0x129F0Cu: goto label_129f0c;
            case 0x129F18u: goto label_129f18;
            case 0x129F2Cu: goto label_129f2c;
            case 0x129F44u: goto label_129f44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x129F70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
