#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164C28
// Address: 0x164c28 - 0x164cdc
void sub_00164C28_0x164c28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164C28_0x164c28");
#endif

    switch (ctx->pc) {
        case 0x164c6cu: goto label_164c6c;
        case 0x164c98u: goto label_164c98;
        case 0x164ca8u: goto label_164ca8;
        default: break;
    }

    ctx->pc = 0x164c28u;

    // 0x164c28: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x164c28u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x164c2c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x164c2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x164c30: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x164c30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x164c34: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x164c34u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164c38: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x164c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x164c3c: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x164c3cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164c40: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x164c40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x164c44: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x164c44u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164c48: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x164c48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x164c4c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x164c4cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164c50: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x164c50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x164c54: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x164c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x164c58: 0x8c911b74  lw          $s1, 0x1B74($a0)
    ctx->pc = 0x164c58u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 7028)));
    // 0x164c5c: 0x8e330004  lw          $s3, 0x4($s1)
    ctx->pc = 0x164c5cu;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x164c60: 0x8e250008  lw          $a1, 0x8($s1)
    ctx->pc = 0x164c60u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x164c64: 0xc0592dc  jal         func_164B70
    ctx->pc = 0x164C64u;
    SET_GPR_U32(ctx, 31, 0x164C6Cu);
    ctx->pc = 0x164C68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164C64u;
            // 0x164c68: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164B70u;
    if (runtime->hasFunction(0x164B70u)) {
        auto targetFn = runtime->lookupFunction(0x164B70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164C6Cu; }
        if (ctx->pc != 0x164C6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164B70_0x164b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164C6Cu; }
        if (ctx->pc != 0x164C6Cu) { return; }
    }
    ctx->pc = 0x164C6Cu;
label_164c6c:
    // 0x164c6c: 0x3c060001  lui         $a2, 0x1
    ctx->pc = 0x164c6cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)1 << 16));
    // 0x164c70: 0x8fb00004  lw          $s0, 0x4($sp)
    ctx->pc = 0x164c70u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x164c74: 0x34c69000  ori         $a2, $a2, 0x9000
    ctx->pc = 0x164c74u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)36864);
    // 0x164c78: 0x8fa40000  lw          $a0, 0x0($sp)
    ctx->pc = 0x164c78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x164c7c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x164c7cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164c80: 0x250102a  slt         $v0, $s2, $s0
    ctx->pc = 0x164c80u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x164c84: 0x242800b  movn        $s0, $s2, $v0
    ctx->pc = 0x164c84u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 18));
    // 0x164c88: 0xd0182a  slt         $v1, $a2, $s0
    ctx->pc = 0x164c88u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x164c8c: 0xc3800b  movn        $s0, $a2, $v1
    ctx->pc = 0x164c8cu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 6));
    // 0x164c90: 0xc055798  jal         func_155E60
    ctx->pc = 0x164C90u;
    SET_GPR_U32(ctx, 31, 0x164C98u);
    ctx->pc = 0x164C94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164C90u;
            // 0x164c94: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E60u;
    if (runtime->hasFunction(0x155E60u)) {
        auto targetFn = runtime->lookupFunction(0x155E60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164C98u; }
        if (ctx->pc != 0x164C98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E60_0x155e60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164C98u; }
        if (ctx->pc != 0x164C98u) { return; }
    }
    ctx->pc = 0x164C98u;
label_164c98:
    // 0x164c98: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x164c98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164c9c: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x164c9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164ca0: 0xc0592e8  jal         func_164BA0
    ctx->pc = 0x164CA0u;
    SET_GPR_U32(ctx, 31, 0x164CA8u);
    ctx->pc = 0x164CA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164CA0u;
            // 0x164ca4: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164BA0u;
    if (runtime->hasFunction(0x164BA0u)) {
        auto targetFn = runtime->lookupFunction(0x164BA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164CA8u; }
        if (ctx->pc != 0x164CA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164BA0_0x164ba0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164CA8u; }
        if (ctx->pc != 0x164CA8u) { return; }
    }
    ctx->pc = 0x164CA8u;
label_164ca8:
    // 0x164ca8: 0x8e220048  lw          $v0, 0x48($s1)
    ctx->pc = 0x164ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x164cac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x164cacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x164cb0: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x164cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x164cb4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x164cb4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x164cb8: 0xae220048  sw          $v0, 0x48($s1)
    ctx->pc = 0x164cb8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 72), GPR_U32(ctx, 2));
    // 0x164cbc: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x164cbcu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x164cc0: 0xaeb00000  sw          $s0, 0x0($s5)
    ctx->pc = 0x164cc0u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 16));
    // 0x164cc4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x164cc4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x164cc8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x164cc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164ccc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x164cccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x164cd0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x164cd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x164cd4: 0x3e00008  jr          $ra
    ctx->pc = 0x164CD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164CD4u;
            // 0x164cd8: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164C6Cu: goto label_164c6c;
            case 0x164C98u: goto label_164c98;
            case 0x164CA8u: goto label_164ca8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164CDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
