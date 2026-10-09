#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00146EE8
// Address: 0x146ee8 - 0x1470a0
void sub_00146EE8_0x146ee8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00146EE8_0x146ee8");
#endif

    switch (ctx->pc) {
        case 0x146f60u: goto label_146f60;
        case 0x146f88u: goto label_146f88;
        case 0x146ff0u: goto label_146ff0;
        case 0x147030u: goto label_147030;
        case 0x147040u: goto label_147040;
        default: break;
    }

    ctx->pc = 0x146ee8u;

    // 0x146ee8: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x146ee8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x146eec: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x146eecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x146ef0: 0xffb60060  sd          $s6, 0x60($sp)
    ctx->pc = 0x146ef0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 22));
    // 0x146ef4: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x146ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x146ef8: 0xb02d  daddu       $s6, $zero, $zero
    ctx->pc = 0x146ef8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146efc: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x146efcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x146f00: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x146f00u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f04: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x146f04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x146f08: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x146f08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x146f0c: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x146f0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f10: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x146f10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x146f14: 0xffb30030  sd          $s3, 0x30($sp)
    ctx->pc = 0x146f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x146f18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x146f18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x146f1c: 0x8e23018c  lw          $v1, 0x18C($s1)
    ctx->pc = 0x146f1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 396)));
    // 0x146f20: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x146F20u;
    {
        const bool branch_taken_0x146f20 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x146F24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146F20u;
            // 0x146f24: 0xa0902d  daddu       $s2, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146f20) {
            ctx->pc = 0x146F38u;
            goto label_146f38;
        }
    }
    ctx->pc = 0x146F28u;
    // 0x146f28: 0x240982d  daddu       $s3, $s2, $zero
    ctx->pc = 0x146f28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f2c: 0x2a0a02d  daddu       $s4, $s5, $zero
    ctx->pc = 0x146f2cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f30: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x146F30u;
    {
        const bool branch_taken_0x146f30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x146F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146F30u;
            // 0x146f34: 0x24160040  addiu       $s6, $zero, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146f30) {
            ctx->pc = 0x146F40u;
            goto label_146f40;
        }
    }
    ctx->pc = 0x146F38u;
label_146f38:
    // 0x146f38: 0x2a0982d  daddu       $s3, $s5, $zero
    ctx->pc = 0x146f38u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f3c: 0x240a02d  daddu       $s4, $s2, $zero
    ctx->pc = 0x146f3cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_146f40:
    // 0x146f40: 0x8e270870  lw          $a3, 0x870($s1)
    ctx->pc = 0x146f40u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x146f44: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x146f44u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f48: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x146f48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f4c: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x146f4cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x146f50: 0x24e80020  addiu       $t0, $a3, 0x20
    ctx->pc = 0x146f50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 32));
    // 0x146f54: 0x24e60010  addiu       $a2, $a3, 0x10
    ctx->pc = 0x146f54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 16));
    // 0x146f58: 0xc051b18  jal         func_146C60
    ctx->pc = 0x146F58u;
    SET_GPR_U32(ctx, 31, 0x146F60u);
    ctx->pc = 0x146F5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146F58u;
            // 0x146f5c: 0x24e70018  addiu       $a3, $a3, 0x18 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146C60u;
    if (runtime->hasFunction(0x146C60u)) {
        auto targetFn = runtime->lookupFunction(0x146C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146F60u; }
        if (ctx->pc != 0x146F60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146C60_0x146c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146F60u; }
        if (ctx->pc != 0x146F60u) { return; }
    }
    ctx->pc = 0x146F60u;
label_146f60:
    // 0x146f60: 0x8e270870  lw          $a3, 0x870($s1)
    ctx->pc = 0x146f60u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x146f64: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x146f64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f68: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x146f68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f6c: 0x8ce20010  lw          $v0, 0x10($a3)
    ctx->pc = 0x146f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x146f70: 0x24e80038  addiu       $t0, $a3, 0x38
    ctx->pc = 0x146f70u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), 56));
    // 0x146f74: 0x24e60028  addiu       $a2, $a3, 0x28
    ctx->pc = 0x146f74u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 40));
    // 0x146f78: 0xfe3000a0  sd          $s0, 0xA0($s1)
    ctx->pc = 0x146f78u;
    WRITE64(ADD32(GPR_U32(ctx, 17), 160), GPR_U64(ctx, 16));
    // 0x146f7c: 0xae220098  sw          $v0, 0x98($s1)
    ctx->pc = 0x146f7cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 152), GPR_U32(ctx, 2));
    // 0x146f80: 0xc051b18  jal         func_146C60
    ctx->pc = 0x146F80u;
    SET_GPR_U32(ctx, 31, 0x146F88u);
    ctx->pc = 0x146F84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146F80u;
            // 0x146f84: 0x24e70030  addiu       $a3, $a3, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146C60u;
    if (runtime->hasFunction(0x146C60u)) {
        auto targetFn = runtime->lookupFunction(0x146C60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146F88u; }
        if (ctx->pc != 0x146F88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146C60_0x146c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146F88u; }
        if (ctx->pc != 0x146F88u) { return; }
    }
    ctx->pc = 0x146F88u;
label_146f88:
    // 0x146f88: 0x8e270870  lw          $a3, 0x870($s1)
    ctx->pc = 0x146f88u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x146f8c: 0x2c0402d  daddu       $t0, $s6, $zero
    ctx->pc = 0x146f8cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f90: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x146f90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f94: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x146f94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146f98: 0x8ce30028  lw          $v1, 0x28($a3)
    ctx->pc = 0x146f98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x146f9c: 0xfe3000a0  sd          $s0, 0xA0($s1)
    ctx->pc = 0x146f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 17), 160), GPR_U64(ctx, 16));
    // 0x146fa0: 0xae230098  sw          $v1, 0x98($s1)
    ctx->pc = 0x146fa0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 152), GPR_U32(ctx, 3));
    // 0x146fa4: 0xdce20020  ld          $v0, 0x20($a3)
    ctx->pc = 0x146fa4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x146fa8: 0x8e66005c  lw          $a2, 0x5C($s3)
    ctx->pc = 0x146fa8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 92)));
    // 0x146fac: 0x481025  or          $v0, $v0, $t0
    ctx->pc = 0x146facu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 8));
    // 0x146fb0: 0xdce30038  ld          $v1, 0x38($a3)
    ctx->pc = 0x146fb0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x146fb4: 0xae2600e4  sw          $a2, 0xE4($s1)
    ctx->pc = 0x146fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 228), GPR_U32(ctx, 6));
    // 0x146fb8: 0xfce20020  sd          $v0, 0x20($a3)
    ctx->pc = 0x146fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 7), 32), GPR_U64(ctx, 2));
    // 0x146fbc: 0x681825  or          $v1, $v1, $t0
    ctx->pc = 0x146fbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 8));
    // 0x146fc0: 0x8e660060  lw          $a2, 0x60($s3)
    ctx->pc = 0x146fc0u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 96)));
    // 0x146fc4: 0xfce30038  sd          $v1, 0x38($a3)
    ctx->pc = 0x146fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 7), 56), GPR_U64(ctx, 3));
    // 0x146fc8: 0xae2600e8  sw          $a2, 0xE8($s1)
    ctx->pc = 0x146fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 232), GPR_U32(ctx, 6));
    // 0x146fcc: 0x8e620044  lw          $v0, 0x44($s3)
    ctx->pc = 0x146fccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 68)));
    // 0x146fd0: 0xae2200cc  sw          $v0, 0xCC($s1)
    ctx->pc = 0x146fd0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 204), GPR_U32(ctx, 2));
    // 0x146fd4: 0x8e830048  lw          $v1, 0x48($s4)
    ctx->pc = 0x146fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 72)));
    // 0x146fd8: 0xae2300d0  sw          $v1, 0xD0($s1)
    ctx->pc = 0x146fd8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 208), GPR_U32(ctx, 3));
    // 0x146fdc: 0x8e620050  lw          $v0, 0x50($s3)
    ctx->pc = 0x146fdcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 80)));
    // 0x146fe0: 0xae2200d8  sw          $v0, 0xD8($s1)
    ctx->pc = 0x146fe0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 216), GPR_U32(ctx, 2));
    // 0x146fe4: 0x8e830054  lw          $v1, 0x54($s4)
    ctx->pc = 0x146fe4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 20), 84)));
    // 0x146fe8: 0xc051a42  jal         func_146908
    ctx->pc = 0x146FE8u;
    SET_GPR_U32(ctx, 31, 0x146FF0u);
    ctx->pc = 0x146FECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x146FE8u;
            // 0x146fec: 0xae2300dc  sw          $v1, 0xDC($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 220), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146908u;
    if (runtime->hasFunction(0x146908u)) {
        auto targetFn = runtime->lookupFunction(0x146908u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146FF0u; }
        if (ctx->pc != 0x146FF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146908_0x146908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146FF0u; }
        if (ctx->pc != 0x146FF0u) { return; }
    }
    ctx->pc = 0x146FF0u;
label_146ff0:
    // 0x146ff0: 0x10400021  beqz        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x146FF0u;
    {
        const bool branch_taken_0x146ff0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x146FF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146FF0u;
            // 0x146ff4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146ff0) {
            ctx->pc = 0x147078u;
            goto label_147078;
        }
    }
    ctx->pc = 0x146FF8u;
    // 0x146ff8: 0x8e430028  lw          $v1, 0x28($s2)
    ctx->pc = 0x146ff8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 40)));
    // 0x146ffc: 0x1462001f  bne         $v1, $v0, . + 4 + (0x1F << 2)
    ctx->pc = 0x146FFCu;
    {
        const bool branch_taken_0x146ffc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x147000u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x146FFCu;
            // 0x147000: 0xdfbf0070  ld          $ra, 0x70($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x146ffc) {
            ctx->pc = 0x14707Cu;
            goto label_14707c;
        }
    }
    ctx->pc = 0x147004u;
    // 0x147004: 0x8ea20028  lw          $v0, 0x28($s5)
    ctx->pc = 0x147004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x147008: 0x1443001d  bne         $v0, $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x147008u;
    {
        const bool branch_taken_0x147008 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x14700Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147008u;
            // 0x14700c: 0xdfb60060  ld          $s6, 0x60($sp) (Delay Slot)
        SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147008) {
            ctx->pc = 0x147080u;
            goto label_147080;
        }
    }
    ctx->pc = 0x147010u;
    // 0x147010: 0x8e420010  lw          $v0, 0x10($s2)
    ctx->pc = 0x147010u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x147014: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x147014u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x147018: 0xae420010  sw          $v0, 0x10($s2)
    ctx->pc = 0x147018u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x14701c: 0x8e2300c8  lw          $v1, 0xC8($s1)
    ctx->pc = 0x14701cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 200)));
    // 0x147020: 0x10600005  beqz        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x147020u;
    {
        const bool branch_taken_0x147020 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x147024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147020u;
            // 0x147024: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147020) {
            ctx->pc = 0x147038u;
            goto label_147038;
        }
    }
    ctx->pc = 0x147028u;
    // 0x147028: 0xc051de8  jal         func_1477A0
    ctx->pc = 0x147028u;
    SET_GPR_U32(ctx, 31, 0x147030u);
    ctx->pc = 0x14702Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147028u;
            // 0x14702c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1477A0u;
    if (runtime->hasFunction(0x1477A0u)) {
        auto targetFn = runtime->lookupFunction(0x1477A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147030u; }
        if (ctx->pc != 0x147030u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001477A0_0x1477a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147030u; }
        if (ctx->pc != 0x147030u) { return; }
    }
    ctx->pc = 0x147030u;
label_147030:
    // 0x147030: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x147030u;
    {
        const bool branch_taken_0x147030 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x147034u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147030u;
            // 0x147034: 0x8e420010  lw          $v0, 0x10($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x147030) {
            ctx->pc = 0x147044u;
            goto label_147044;
        }
    }
    ctx->pc = 0x147038u;
label_147038:
    // 0x147038: 0xc051a6a  jal         func_1469A8
    ctx->pc = 0x147038u;
    SET_GPR_U32(ctx, 31, 0x147040u);
    ctx->pc = 0x14703Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147038u;
            // 0x14703c: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1469A8u;
    if (runtime->hasFunction(0x1469A8u)) {
        auto targetFn = runtime->lookupFunction(0x1469A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147040u; }
        if (ctx->pc != 0x147040u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001469A8_0x1469a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147040u; }
        if (ctx->pc != 0x147040u) { return; }
    }
    ctx->pc = 0x147040u;
label_147040:
    // 0x147040: 0x8e420010  lw          $v0, 0x10($s2)
    ctx->pc = 0x147040u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
label_147044:
    // 0x147044: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x147044u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147048: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x147048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x14704c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x14704cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x147050: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x147050u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x147054: 0xae420010  sw          $v0, 0x10($s2)
    ctx->pc = 0x147054u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 16), GPR_U32(ctx, 2));
    // 0x147058: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x147058u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14705c: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x14705cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x147060: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x147060u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x147064: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x147064u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x147068: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x147068u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14706c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14706cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147070: 0x8051b0e  j           func_146C38
    ctx->pc = 0x147070u;
    ctx->pc = 0x147074u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x147070u;
            // 0x147074: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146C38u;
    {
        auto targetFn = runtime->lookupFunction(0x146C38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x147078u;
label_147078:
    // 0x147078: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x147078u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
label_14707c:
    // 0x14707c: 0xdfb60060  ld          $s6, 0x60($sp)
    ctx->pc = 0x14707cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_147080:
    // 0x147080: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x147080u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x147084: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x147084u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x147088: 0xdfb30030  ld          $s3, 0x30($sp)
    ctx->pc = 0x147088u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14708c: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x14708cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x147090: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x147090u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147094: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x147094u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147098: 0x3e00008  jr          $ra
    ctx->pc = 0x147098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14709Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x147098u;
            // 0x14709c: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146F38u: goto label_146f38;
            case 0x146F40u: goto label_146f40;
            case 0x146F60u: goto label_146f60;
            case 0x146F88u: goto label_146f88;
            case 0x146FF0u: goto label_146ff0;
            case 0x147030u: goto label_147030;
            case 0x147038u: goto label_147038;
            case 0x147040u: goto label_147040;
            case 0x147044u: goto label_147044;
            case 0x147078u: goto label_147078;
            case 0x14707Cu: goto label_14707c;
            case 0x147080u: goto label_147080;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1470A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
