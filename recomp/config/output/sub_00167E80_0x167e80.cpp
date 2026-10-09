#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00167E80
// Address: 0x167e80 - 0x167fc0
void sub_00167E80_0x167e80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00167E80_0x167e80");
#endif

    switch (ctx->pc) {
        case 0x167ea8u: goto label_167ea8;
        case 0x167ef0u: goto label_167ef0;
        case 0x167f40u: goto label_167f40;
        case 0x167f9cu: goto label_167f9c;
        default: break;
    }

    ctx->pc = 0x167e80u;

    // 0x167e80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x167e80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x167e84: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167e88: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x167e88u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167e8c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167e90: 0x26500cc0  addiu       $s0, $s2, 0xCC0
    ctx->pc = 0x167e90u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 18), 3264));
    // 0x167e94: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167e94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167e98: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167e9c: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x167e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x167ea0: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167EA0u;
    SET_GPR_U32(ctx, 31, 0x167EA8u);
    ctx->pc = 0x167EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167EA0u;
            // 0x167ea4: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167EA8u; }
        if (ctx->pc != 0x167EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167EA8u; }
        if (ctx->pc != 0x167EA8u) { return; }
    }
    ctx->pc = 0x167EA8u;
label_167ea8:
    // 0x167ea8: 0x8e060120  lw          $a2, 0x120($s0)
    ctx->pc = 0x167ea8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 288)));
    // 0x167eac: 0x8e030124  lw          $v1, 0x124($s0)
    ctx->pc = 0x167eacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 292)));
    // 0x167eb0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167eb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167eb4: 0xd13021  addu        $a2, $a2, $s1
    ctx->pc = 0x167eb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x167eb8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x167eb8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x167ebc: 0xae060120  sw          $a2, 0x120($s0)
    ctx->pc = 0x167ebcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 288), GPR_U32(ctx, 6));
    // 0x167ec0: 0x2467001f  addiu       $a3, $v1, 0x1F
    ctx->pc = 0x167ec0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), 31));
    // 0x167ec4: 0x28650000  slti        $a1, $v1, 0x0
    ctx->pc = 0x167ec4u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x167ec8: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x167ec8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167ecc: 0xe5100b  movn        $v0, $a3, $a1
    ctx->pc = 0x167eccu;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 7));
    // 0x167ed0: 0x21143  sra         $v0, $v0, 5
    ctx->pc = 0x167ed0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
    // 0x167ed4: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x167ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x167ed8: 0x621023  subu        $v0, $v1, $v0
    ctx->pc = 0x167ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x167edc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167edcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167ee0: 0x521021  addu        $v0, $v0, $s2
    ctx->pc = 0x167ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
    // 0x167ee4: 0xac460de8  sw          $a2, 0xDE8($v0)
    ctx->pc = 0x167ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3560), GPR_U32(ctx, 6));
    // 0x167ee8: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167EE8u;
    SET_GPR_U32(ctx, 31, 0x167EF0u);
    ctx->pc = 0x167EECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167EE8u;
            // 0x167eec: 0xae030124  sw          $v1, 0x124($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 292), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167EF0u; }
        if (ctx->pc != 0x167EF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167EF0u; }
        if (ctx->pc != 0x167EF0u) { return; }
    }
    ctx->pc = 0x167EF0u;
label_167ef0:
    // 0x167ef0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167ef0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x167ef4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167ef4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167ef8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167ef8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167efc: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x167efcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167f00: 0x3e00008  jr          $ra
    ctx->pc = 0x167F00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167F04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167F00u;
            // 0x167f04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167EA8u: goto label_167ea8;
            case 0x167EF0u: goto label_167ef0;
            case 0x167F40u: goto label_167f40;
            case 0x167F94u: goto label_167f94;
            case 0x167F9Cu: goto label_167f9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167F08u;
    // 0x167f08: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x167f08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x167f0c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x167f0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x167f10: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x167f10u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167f14: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x167f14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x167f18: 0x26300cc0  addiu       $s0, $s1, 0xCC0
    ctx->pc = 0x167f18u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 3264));
    // 0x167f1c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167f1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167f20: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x167f20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x167f24: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x167f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x167f28: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x167f28u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167f2c: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x167f2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x167f30: 0xa02d  daddu       $s4, $zero, $zero
    ctx->pc = 0x167f30u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167f34: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x167f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x167f38: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x167F38u;
    SET_GPR_U32(ctx, 31, 0x167F40u);
    ctx->pc = 0x167F3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x167F38u;
            // 0x167f3c: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167F40u; }
        if (ctx->pc != 0x167F40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167F40u; }
        if (ctx->pc != 0x167F40u) { return; }
    }
    ctx->pc = 0x167F40u;
label_167f40:
    // 0x167f40: 0x8e0701b0  lw          $a3, 0x1B0($s0)
    ctx->pc = 0x167f40u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 432)));
    // 0x167f44: 0x8e0301b4  lw          $v1, 0x1B4($s0)
    ctx->pc = 0x167f44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 436)));
    // 0x167f48: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x167f48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167f4c: 0x24e6001f  addiu       $a2, $a3, 0x1F
    ctx->pc = 0x167f4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 7), 31));
    // 0x167f50: 0x28e50000  slti        $a1, $a3, 0x0
    ctx->pc = 0x167f50u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x167f54: 0xe0102d  daddu       $v0, $a3, $zero
    ctx->pc = 0x167f54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167f58: 0xe31823  subu        $v1, $a3, $v1
    ctx->pc = 0x167f58u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x167f5c: 0xc5100b  movn        $v0, $a2, $a1
    ctx->pc = 0x167f5cu;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x167f60: 0x28630020  slti        $v1, $v1, 0x20
    ctx->pc = 0x167f60u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x167f64: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x167F64u;
    {
        const bool branch_taken_0x167f64 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x167F68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167F64u;
            // 0x167f68: 0x21143  sra         $v0, $v0, 5 (Delay Slot)
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167f64) {
            ctx->pc = 0x167F94u;
            goto label_167f94;
        }
    }
    ctx->pc = 0x167F6Cu;
    // 0x167f6c: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x167f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x167f70: 0xae1201a8  sw          $s2, 0x1A8($s0)
    ctx->pc = 0x167f70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 18));
    // 0x167f74: 0xe21023  subu        $v0, $a3, $v0
    ctx->pc = 0x167f74u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x167f78: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x167f78u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x167f7c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x167f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x167f80: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x167f80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x167f84: 0xac530e78  sw          $s3, 0xE78($v0)
    ctx->pc = 0x167f84u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3704), GPR_U32(ctx, 19));
    // 0x167f88: 0x8e0301b0  lw          $v1, 0x1B0($s0)
    ctx->pc = 0x167f88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 432)));
    // 0x167f8c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x167f8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x167f90: 0xae0301b0  sw          $v1, 0x1B0($s0)
    ctx->pc = 0x167f90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 432), GPR_U32(ctx, 3));
label_167f94:
    // 0x167f94: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x167F94u;
    SET_GPR_U32(ctx, 31, 0x167F9Cu);
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167F9Cu; }
        if (ctx->pc != 0x167F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x167F9Cu; }
        if (ctx->pc != 0x167F9Cu) { return; }
    }
    ctx->pc = 0x167F9Cu;
label_167f9c:
    // 0x167f9c: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x167f9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167fa0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x167fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x167fa4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x167fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x167fa8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x167fa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x167fac: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x167facu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x167fb0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x167fb0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x167fb4: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x167fb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x167fb8: 0x3e00008  jr          $ra
    ctx->pc = 0x167FB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x167FBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167FB8u;
            // 0x167fbc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167EA8u: goto label_167ea8;
            case 0x167EF0u: goto label_167ef0;
            case 0x167F40u: goto label_167f40;
            case 0x167F94u: goto label_167f94;
            case 0x167F9Cu: goto label_167f9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x167FC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
