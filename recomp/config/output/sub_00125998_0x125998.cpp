#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00125998
// Address: 0x125998 - 0x125a8c
void sub_00125998_0x125998(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00125998_0x125998");
#endif

    switch (ctx->pc) {
        case 0x125a00u: goto label_125a00;
        default: break;
    }

    ctx->pc = 0x125998u;

    // 0x125998: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x125998u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x12599c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12599cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1259a0: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x1259a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x1259a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1259a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259a8: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x1259a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x1259ac: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x1259acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x1259b0: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x1259b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x1259b4: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x1259b4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x1259b8: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x1259b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x1259bc: 0x2613000f  addiu       $s3, $s0, 0xF
    ctx->pc = 0x1259bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x1259c0: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1259c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1259c4: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x1259c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259c8: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x1259c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1259cc: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x1259ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x1259d0: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1259d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259d4: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x1259d4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1259d8: 0x2603009a  addiu       $v1, $s0, 0x9A
    ctx->pc = 0x1259d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 154));
    // 0x1259dc: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x1259dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x1259e0: 0x2608000d  addiu       $t0, $s0, 0xD
    ctx->pc = 0x1259e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x1259e4: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x1259e4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259e8: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x1259e8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1259ec: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x1259ecu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x1259f0: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1259f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1259f4: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x1259f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x1259f8: 0xc04961e  jal         func_125878
    ctx->pc = 0x1259F8u;
    SET_GPR_U32(ctx, 31, 0x125A00u);
    ctx->pc = 0x1259FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1259F8u;
            // 0x1259fc: 0xafb20008  sw          $s2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x125878u;
    if (runtime->hasFunction(0x125878u)) {
        auto targetFn = runtime->lookupFunction(0x125878u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125A00u; }
        if (ctx->pc != 0x125A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00125878_0x125878(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x125A00u; }
        if (ctx->pc != 0x125A00u) { return; }
    }
    ctx->pc = 0x125A00u;
label_125a00:
    // 0x125a00: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x125A00u;
    {
        const bool branch_taken_0x125a00 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x125a00) {
            ctx->pc = 0x125A04u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x125A00u;
            // 0x125a04: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x125A10u;
            goto label_125a10;
        }
    }
    ctx->pc = 0x125A08u;
    // 0x125a08: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x125A08u;
    {
        const bool branch_taken_0x125a08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x125A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125A08u;
            // 0x125a0c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x125a08) {
            ctx->pc = 0x125A70u;
            goto label_125a70;
        }
    }
    ctx->pc = 0x125A10u;
label_125a10:
    // 0x125a10: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x125a10u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x125a14: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x125a14u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x125a18: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x125a18u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x125a1c: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x125a1cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x125a20: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x125a20u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x125a24: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x125a24u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x125a28: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x125a28u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x125a2c: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x125a2cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x125a30: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x125a30u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x125a34: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x125a34u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x125a38: 0xae030050  sw          $v1, 0x50($s0)
    ctx->pc = 0x125a38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 3));
    // 0x125a3c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x125a3cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x125a40: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x125a40u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x125a44: 0x82640000  lb          $a0, 0x0($s3)
    ctx->pc = 0x125a44u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x125a48: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x125a48u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x125a4c: 0xae040054  sw          $a0, 0x54($s0)
    ctx->pc = 0x125a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 4));
    // 0x125a50: 0xa6030098  sh          $v1, 0x98($s0)
    ctx->pc = 0x125a50u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 3));
    // 0x125a54: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x125a54u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x125a58: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x125a58u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x125a5c: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x125a5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x125a60: 0xae030058  sw          $v1, 0x58($s0)
    ctx->pc = 0x125a60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 3));
    // 0x125a64: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x125a64u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x125a68: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x125a68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x125a6c: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x125a6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_125a70:
    // 0x125a70: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x125a70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x125a74: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x125a74u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x125a78: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x125a78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x125a7c: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x125a7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x125a80: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x125a80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x125a84: 0x3e00008  jr          $ra
    ctx->pc = 0x125A84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x125A88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x125A84u;
            // 0x125a88: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x125A00u: goto label_125a00;
            case 0x125A10u: goto label_125a10;
            case 0x125A70u: goto label_125a70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x125A8Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
