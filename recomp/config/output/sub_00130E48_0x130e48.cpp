#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130E48
// Address: 0x130e48 - 0x130f20
void sub_00130E48_0x130e48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130E48_0x130e48");
#endif

    switch (ctx->pc) {
        case 0x130e70u: goto label_130e70;
        case 0x130eacu: goto label_130eac;
        case 0x130f04u: goto label_130f04;
        default: break;
    }

    ctx->pc = 0x130e48u;

    // 0x130e48: 0x3e00008  jr          $ra
    ctx->pc = 0x130E48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E48u;
            // 0x130e4c: 0xa0850040  sb          $a1, 0x40($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 64), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E50u;
    // 0x130e50: 0x3e00008  jr          $ra
    ctx->pc = 0x130E50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E50u;
            // 0x130e54: 0x80820040  lb          $v0, 0x40($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 64)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E58u;
    // 0x130e58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130e58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130e5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130e5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130e60: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x130e60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130e64: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130e68: 0xc04d7d4  jal         func_135F50
    ctx->pc = 0x130E68u;
    SET_GPR_U32(ctx, 31, 0x130E70u);
    ctx->pc = 0x130E6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130E68u;
            // 0x130e6c: 0x8c840008  lw          $a0, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135F50u;
    if (runtime->hasFunction(0x135F50u)) {
        auto targetFn = runtime->lookupFunction(0x135F50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130E70u; }
        if (ctx->pc != 0x130E70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135F50_0x135f50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130E70u; }
        if (ctx->pc != 0x130E70u) { return; }
    }
    ctx->pc = 0x130E70u;
label_130e70:
    // 0x130e70: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x130e70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x130e74: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130e74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130e78: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130e78u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130e7c: 0x3e00008  jr          $ra
    ctx->pc = 0x130E7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E7Cu;
            // 0x130e80: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E84u;
    // 0x130e84: 0x0  nop
    ctx->pc = 0x130e84u;
    // NOP
    // 0x130e88: 0xaca00000  sw          $zero, 0x0($a1)
    ctx->pc = 0x130e88u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 0));
    // 0x130e8c: 0x3e00008  jr          $ra
    ctx->pc = 0x130E8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130E8Cu;
            // 0x130e90: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130E94u;
    // 0x130e94: 0x0  nop
    ctx->pc = 0x130e94u;
    // NOP
    // 0x130e98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130e9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130ea0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130ea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130ea4: 0xc04d7ee  jal         func_135FB8
    ctx->pc = 0x130EA4u;
    SET_GPR_U32(ctx, 31, 0x130EACu);
    ctx->pc = 0x130EA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130EA4u;
            // 0x130ea8: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135FB8u;
    if (runtime->hasFunction(0x135FB8u)) {
        auto targetFn = runtime->lookupFunction(0x135FB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130EACu; }
        if (ctx->pc != 0x130EACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135FB8_0x135fb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130EACu; }
        if (ctx->pc != 0x130EACu) { return; }
    }
    ctx->pc = 0x130EACu;
label_130eac:
    // 0x130eac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x130eacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130eb0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130eb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130eb4: 0x24a607ff  addiu       $a2, $a1, 0x7FF
    ctx->pc = 0x130eb4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 5), 2047));
    // 0x130eb8: 0x28a40000  slti        $a0, $a1, 0x0
    ctx->pc = 0x130eb8u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x130ebc: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x130ebcu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130ec0: 0xc4180b  movn        $v1, $a2, $a0
    ctx->pc = 0x130ec0u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 6));
    // 0x130ec4: 0x31ac3  sra         $v1, $v1, 11
    ctx->pc = 0x130ec4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 11));
    // 0x130ec8: 0x322c0  sll         $a0, $v1, 11
    ctx->pc = 0x130ec8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x130ecc: 0x24660001  addiu       $a2, $v1, 0x1
    ctx->pc = 0x130eccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x130ed0: 0xa42823  subu        $a1, $a1, $a0
    ctx->pc = 0x130ed0u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x130ed4: 0x18a00002  blez        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x130ED4u;
    {
        const bool branch_taken_0x130ed4 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x130ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130ED4u;
            // 0x130ed8: 0xae030000  sw          $v1, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x130ed4) {
            ctx->pc = 0x130EE0u;
            goto label_130ee0;
        }
    }
    ctx->pc = 0x130EDCu;
    // 0x130edc: 0xae060000  sw          $a2, 0x0($s0)
    ctx->pc = 0x130edcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 6));
label_130ee0:
    // 0x130ee0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130ee0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130ee4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130ee4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130ee8: 0x3e00008  jr          $ra
    ctx->pc = 0x130EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130EE8u;
            // 0x130eec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130EF0u;
    // 0x130ef0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130ef4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130ef8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x130ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x130efc: 0xc04d7ee  jal         func_135FB8
    ctx->pc = 0x130EFCu;
    SET_GPR_U32(ctx, 31, 0x130F04u);
    ctx->pc = 0x130F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130EFCu;
            // 0x130f00: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135FB8u;
    if (runtime->hasFunction(0x135FB8u)) {
        auto targetFn = runtime->lookupFunction(0x135FB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F04u; }
        if (ctx->pc != 0x130F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135FB8_0x135fb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F04u; }
        if (ctx->pc != 0x130F04u) { return; }
    }
    ctx->pc = 0x130F04u;
label_130f04:
    // 0x130f04: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x130f04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x130f08: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x130f08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x130f0c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130f0cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130f10: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x130f10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130f14: 0x3e00008  jr          $ra
    ctx->pc = 0x130F14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130F14u;
            // 0x130f18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130E70u: goto label_130e70;
            case 0x130EACu: goto label_130eac;
            case 0x130EE0u: goto label_130ee0;
            case 0x130F04u: goto label_130f04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130F1Cu;
    // 0x130f1c: 0x0  nop
    ctx->pc = 0x130f1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
