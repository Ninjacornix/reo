#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123EC0
// Address: 0x123ec0 - 0x123fbc
void sub_00123EC0_0x123ec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123EC0_0x123ec0");
#endif

    switch (ctx->pc) {
        case 0x123f28u: goto label_123f28;
        default: break;
    }

    ctx->pc = 0x123ec0u;

    // 0x123ec0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x123ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x123ec4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123ec8: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x123ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x123ecc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x123eccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123ed0: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x123ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x123ed4: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x123ed4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x123ed8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x123ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x123edc: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x123edcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x123ee0: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x123ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x123ee4: 0x2613000f  addiu       $s3, $s0, 0xF
    ctx->pc = 0x123ee4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x123ee8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x123ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x123eec: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x123eecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123ef0: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x123ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x123ef4: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x123ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x123ef8: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x123ef8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123efc: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x123efcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x123f00: 0x27a30024  addiu       $v1, $sp, 0x24
    ctx->pc = 0x123f00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    // 0x123f04: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x123f04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x123f08: 0x2608000d  addiu       $t0, $s0, 0xD
    ctx->pc = 0x123f08u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x123f0c: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x123f0cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123f10: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x123f10u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123f14: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x123f14u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x123f18: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x123f18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x123f1c: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x123f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x123f20: 0xc048f6c  jal         func_123DB0
    ctx->pc = 0x123F20u;
    SET_GPR_U32(ctx, 31, 0x123F28u);
    ctx->pc = 0x123F24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123F20u;
            // 0x123f24: 0xafb20008  sw          $s2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123DB0u;
    if (runtime->hasFunction(0x123DB0u)) {
        auto targetFn = runtime->lookupFunction(0x123DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123F28u; }
        if (ctx->pc != 0x123F28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00123DB0_0x123db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123F28u; }
        if (ctx->pc != 0x123F28u) { return; }
    }
    ctx->pc = 0x123F28u;
label_123f28:
    // 0x123f28: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x123F28u;
    {
        const bool branch_taken_0x123f28 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x123f28) {
            ctx->pc = 0x123F2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123F28u;
            // 0x123f2c: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123F38u;
            goto label_123f38;
        }
    }
    ctx->pc = 0x123F30u;
    // 0x123f30: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x123F30u;
    {
        const bool branch_taken_0x123f30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123F30u;
            // 0x123f34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123f30) {
            ctx->pc = 0x123FA0u;
            goto label_123fa0;
        }
    }
    ctx->pc = 0x123F38u;
label_123f38:
    // 0x123f38: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x123f38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x123f3c: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x123f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x123f40: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x123f40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x123f44: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x123f44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x123f48: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x123f48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x123f4c: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x123f4cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x123f50: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x123f50u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x123f54: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x123f54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x123f58: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x123f58u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x123f5c: 0x97a40024  lhu         $a0, 0x24($sp)
    ctx->pc = 0x123f5cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x123f60: 0xae020050  sw          $v0, 0x50($s0)
    ctx->pc = 0x123f60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
    // 0x123f64: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x123f64u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x123f68: 0x82630000  lb          $v1, 0x0($s3)
    ctx->pc = 0x123f68u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x123f6c: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x123f6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x123f70: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x123f70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x123f74: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x123f74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x123f78: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x123f78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x123f7c: 0xa604009a  sh          $a0, 0x9A($s0)
    ctx->pc = 0x123f7cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 4));
    // 0x123f80: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x123f80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x123f84: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x123f84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x123f88: 0xa6030098  sh          $v1, 0x98($s0)
    ctx->pc = 0x123f88u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 3));
    // 0x123f8c: 0xae040058  sw          $a0, 0x58($s0)
    ctx->pc = 0x123f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 4));
    // 0x123f90: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x123f90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x123f94: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x123f94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x123f98: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x123f98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x123f9c: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x123f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_123fa0:
    // 0x123fa0: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x123fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x123fa4: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x123fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x123fa8: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x123fa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x123fac: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x123facu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x123fb0: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x123fb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x123fb4: 0x3e00008  jr          $ra
    ctx->pc = 0x123FB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123FB4u;
            // 0x123fb8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123FBCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
