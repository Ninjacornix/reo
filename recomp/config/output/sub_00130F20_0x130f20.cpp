#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130F20
// Address: 0x130f20 - 0x130fe8
void sub_00130F20_0x130f20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130F20_0x130f20");
#endif

    switch (ctx->pc) {
        case 0x130f44u: goto label_130f44;
        case 0x130f58u: goto label_130f58;
        case 0x130f70u: goto label_130f70;
        case 0x130f7cu: goto label_130f7c;
        default: break;
    }

    ctx->pc = 0x130f20u;

    // 0x130f20: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x130f20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x130f24: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x130f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x130f28: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x130f28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130f2c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x130f2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x130f30: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x130f30u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130f34: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x130f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x130f38: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x130f38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x130f3c: 0xc049938  jal         func_1264E0
    ctx->pc = 0x130F3Cu;
    SET_GPR_U32(ctx, 31, 0x130F44u);
    ctx->pc = 0x130F40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130F3Cu;
            // 0x130f40: 0xae500004  sw          $s0, 0x4($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F44u; }
        if (ctx->pc != 0x130F44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F44u; }
        if (ctx->pc != 0x130F44u) { return; }
    }
    ctx->pc = 0x130F44u;
label_130f44:
    // 0x130f44: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x130f44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130f48: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x130f48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130f4c: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x130f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x130f50: 0x40f809  jalr        $v0
    ctx->pc = 0x130F50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130F58u);
        ctx->pc = 0x130F54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130F50u;
            // 0x130f54: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130F58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F44u: goto label_130f44;
            case 0x130F58u: goto label_130f58;
            case 0x130F70u: goto label_130f70;
            case 0x130F7Cu: goto label_130f7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130F58u; }
            if (ctx->pc != 0x130F58u) { return; }
        }
        }
    }
    ctx->pc = 0x130F58u;
label_130f58:
    // 0x130f58: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x130f58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x130f5c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x130f5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130f60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x130f60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130f64: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x130f64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x130f68: 0x40f809  jalr        $v0
    ctx->pc = 0x130F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130F70u);
        ctx->pc = 0x130F6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130F68u;
            // 0x130f6c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x130F70u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F44u: goto label_130f44;
            case 0x130F58u: goto label_130f58;
            case 0x130F70u: goto label_130f70;
            case 0x130F7Cu: goto label_130f7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130F70u; }
            if (ctx->pc != 0x130F70u) { return; }
        }
        }
    }
    ctx->pc = 0x130F70u;
label_130f70:
    // 0x130f70: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x130f70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x130f74: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x130F74u;
    SET_GPR_U32(ctx, 31, 0x130F7Cu);
    ctx->pc = 0x130F78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130F74u;
            // 0x130f78: 0xae51003c  sw          $s1, 0x3C($s2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 18), 60), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F7Cu; }
        if (ctx->pc != 0x130F7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F7Cu; }
        if (ctx->pc != 0x130F7Cu) { return; }
    }
    ctx->pc = 0x130F7Cu;
label_130f7c:
    // 0x130f7c: 0x8e42003c  lw          $v0, 0x3C($s2)
    ctx->pc = 0x130f7cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 60)));
    // 0x130f80: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130f80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130f84: 0xae420018  sw          $v0, 0x18($s2)
    ctx->pc = 0x130f84u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
    // 0x130f88: 0xae420014  sw          $v0, 0x14($s2)
    ctx->pc = 0x130f88u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x130f8c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x130f8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x130f90: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x130f90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x130f94: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x130f94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x130f98: 0x3e00008  jr          $ra
    ctx->pc = 0x130F98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130F9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130F98u;
            // 0x130f9c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F44u: goto label_130f44;
            case 0x130F58u: goto label_130f58;
            case 0x130F70u: goto label_130f70;
            case 0x130F7Cu: goto label_130f7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FA0u;
    // 0x130fa0: 0x52ac0  sll         $a1, $a1, 11
    ctx->pc = 0x130fa0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 11));
    // 0x130fa4: 0x3e00008  jr          $ra
    ctx->pc = 0x130FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130FA4u;
            // 0x130fa8: 0xac850010  sw          $a1, 0x10($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F44u: goto label_130f44;
            case 0x130F58u: goto label_130f58;
            case 0x130F70u: goto label_130f70;
            case 0x130F7Cu: goto label_130f7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FACu;
    // 0x130fac: 0x0  nop
    ctx->pc = 0x130facu;
    // NOP
    // 0x130fb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x130fb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x130fb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x130fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x130fb8: 0xac85000c  sw          $a1, 0xC($a0)
    ctx->pc = 0x130fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
    // 0x130fbc: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x130fbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x130fc0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x130fc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130fc4: 0x804c170  j           func_1305C0
    ctx->pc = 0x130FC4u;
    ctx->pc = 0x130FC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x130FC4u;
            // 0x130fc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001305C0_0x1305c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x130FCCu;
    // 0x130fcc: 0x0  nop
    ctx->pc = 0x130fccu;
    // NOP
    // 0x130fd0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x130fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x130fd4: 0x3e00008  jr          $ra
    ctx->pc = 0x130FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130FD4u;
            // 0x130fd8: 0xac44a8b4  sw          $a0, -0x574C($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944948), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F44u: goto label_130f44;
            case 0x130F58u: goto label_130f58;
            case 0x130F70u: goto label_130f70;
            case 0x130F7Cu: goto label_130f7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FDCu;
    // 0x130fdc: 0x0  nop
    ctx->pc = 0x130fdcu;
    // NOP
    // 0x130fe0: 0x3e00008  jr          $ra
    ctx->pc = 0x130FE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130FE0u;
            // 0x130fe4: 0x80820002  lb          $v0, 0x2($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F44u: goto label_130f44;
            case 0x130F58u: goto label_130f58;
            case 0x130F70u: goto label_130f70;
            case 0x130F7Cu: goto label_130f7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FE8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
