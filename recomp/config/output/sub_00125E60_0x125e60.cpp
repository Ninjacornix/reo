#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125E60
// Address: 0x125e60 - 0x125f5c
void sub_00125E60_0x125e60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125E60_0x125e60");
#endif

    switch (ctx->pc) {
        case 0x125eccu: goto label_125ecc;
        default: break;
    }

    ctx->pc = 0x125e60u;

    // 0x125e60: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x125e60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x125e64: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x125e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x125e68: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x125e68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125e6c: 0xffb40050  sd          $s4, 0x50($sp)
    ctx->pc = 0x125e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x125e70: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x125e70u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x125e74: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x125e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x125e78: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x125e78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x125e7c: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x125e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x125e80: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x125e80u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x125e84: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x125e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x125e88: 0x2613000f  addiu       $s3, $s0, 0xF
    ctx->pc = 0x125e88u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x125e8c: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x125e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x125e90: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x125e90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125e94: 0xa6140002  sh          $s4, 0x2($s0)
    ctx->pc = 0x125e94u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 20));
    // 0x125e98: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x125e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x125e9c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x125e9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125ea0: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x125ea0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x125ea4: 0x2603009a  addiu       $v1, $s0, 0x9A
    ctx->pc = 0x125ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 154));
    // 0x125ea8: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x125ea8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x125eac: 0x2608000d  addiu       $t0, $s0, 0xD
    ctx->pc = 0x125eacu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x125eb0: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x125eb0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125eb4: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x125eb4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x125eb8: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x125eb8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x125ebc: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x125ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x125ec0: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x125ec0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x125ec4: 0xc04970c  jal         func_125C30
    ctx->pc = 0x125EC4u;
    SET_GPR_U32(ctx, 31, 0x125ECCu);
    ctx->pc = 0x125EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x125EC4u;
            // 0x125ec8: 0xafb20008  sw          $s2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125C30u;
    if (runtime->hasFunction(0x125C30u)) {
        auto targetFn = runtime->lookupFunction(0x125C30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125ECCu; }
        if (ctx->pc != 0x125ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125C30_0x125c30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125ECCu; }
        if (ctx->pc != 0x125ECCu) { return; }
    }
    ctx->pc = 0x125ECCu;
label_125ecc:
    // 0x125ecc: 0x4430004  bgezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x125ECCu;
    {
        const bool branch_taken_0x125ecc = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x125ecc) {
            ctx->pc = 0x125ED0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125ECCu;
            // 0x125ed0: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125EE0u;
            goto label_125ee0;
        }
    }
    ctx->pc = 0x125ED4u;
    // 0x125ed4: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x125ED4u;
    {
        const bool branch_taken_0x125ed4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125ED4u;
            // 0x125ed8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125ed4) {
            ctx->pc = 0x125F3Cu;
            goto label_125f3c;
        }
    }
    ctx->pc = 0x125EDCu;
    // 0x125edc: 0x0  nop
    ctx->pc = 0x125edcu;
    // NOP
label_125ee0:
    // 0x125ee0: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x125ee0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x125ee4: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x125ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x125ee8: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x125ee8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x125eec: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x125eecu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x125ef0: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x125ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x125ef4: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x125ef4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x125ef8: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x125ef8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x125efc: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x125efcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x125f00: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x125f00u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x125f04: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x125f04u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x125f08: 0xae030050  sw          $v1, 0x50($s0)
    ctx->pc = 0x125f08u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 3));
    // 0x125f0c: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x125f0cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x125f10: 0x82640000  lb          $a0, 0x0($s3)
    ctx->pc = 0x125f10u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x125f14: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x125f14u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125f18: 0xae040054  sw          $a0, 0x54($s0)
    ctx->pc = 0x125f18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 4));
    // 0x125f1c: 0xa6140098  sh          $s4, 0x98($s0)
    ctx->pc = 0x125f1cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 20));
    // 0x125f20: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x125f20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x125f24: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x125f24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x125f28: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x125f28u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x125f2c: 0xae030058  sw          $v1, 0x58($s0)
    ctx->pc = 0x125f2cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 3));
    // 0x125f30: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x125f30u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x125f34: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x125f34u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x125f38: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x125f38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_125f3c:
    // 0x125f3c: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x125f3cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125f40: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x125f40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125f44: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x125f44u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125f48: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x125f48u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125f4c: 0xdfb40050  ld          $s4, 0x50($sp)
    ctx->pc = 0x125f4cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x125f50: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x125f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x125f54: 0x3e00008  jr          $ra
    ctx->pc = 0x125F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125F54u;
            // 0x125f58: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125ECCu: goto label_125ecc;
            case 0x125EE0u: goto label_125ee0;
            case 0x125F3Cu: goto label_125f3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125F5Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
