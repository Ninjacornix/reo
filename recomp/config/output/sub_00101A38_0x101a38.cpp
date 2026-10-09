#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101A38
// Address: 0x101a38 - 0x101ae4
void sub_00101A38_0x101a38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101A38_0x101a38");
#endif

    switch (ctx->pc) {
        case 0x101a4cu: goto label_101a4c;
        case 0x101a60u: goto label_101a60;
        case 0x101ab0u: goto label_101ab0;
        case 0x101accu: goto label_101acc;
        default: break;
    }

    ctx->pc = 0x101a38u;

    // 0x101a38: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x101a38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x101a3c: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x101a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x101a40: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x101a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x101a44: 0xc040338  jal         func_100CE0
    ctx->pc = 0x101A44u;
    SET_GPR_U32(ctx, 31, 0x101A4Cu);
    ctx->pc = 0x101A48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101A44u;
            // 0x101a48: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100CE0u;
    if (runtime->hasFunction(0x100CE0u)) {
        auto targetFn = runtime->lookupFunction(0x100CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A4Cu; }
        if (ctx->pc != 0x101A4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100CE0_0x100ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A4Cu; }
        if (ctx->pc != 0x101A4Cu) { return; }
    }
    ctx->pc = 0x101A4Cu;
label_101a4c:
    // 0x101a4c: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x101a4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x101a50: 0x1043001f  beq         $v0, $v1, . + 4 + (0x1F << 2)
    ctx->pc = 0x101A50u;
    {
        const bool branch_taken_0x101a50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x101A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101A50u;
            // 0x101a54: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101a50) {
            ctx->pc = 0x101AD0u;
            goto label_101ad0;
        }
    }
    ctx->pc = 0x101A58u;
    // 0x101a58: 0xc0402dc  jal         func_100B70
    ctx->pc = 0x101A58u;
    SET_GPR_U32(ctx, 31, 0x101A60u);
    ctx->pc = 0x101A5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101A58u;
            // 0x101a5c: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100B70u;
    if (runtime->hasFunction(0x100B70u)) {
        auto targetFn = runtime->lookupFunction(0x100B70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A60u; }
        if (ctx->pc != 0x101A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100B70_0x100b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A60u; }
        if (ctx->pc != 0x101A60u) { return; }
    }
    ctx->pc = 0x101A60u;
label_101a60:
    // 0x101a60: 0x1040001a  beqz        $v0, . + 4 + (0x1A << 2)
    ctx->pc = 0x101A60u;
    {
        const bool branch_taken_0x101a60 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x101A64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101A60u;
            // 0x101a64: 0x3c100020  lui         $s0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101a60) {
            ctx->pc = 0x101ACCu;
            goto label_101acc;
        }
    }
    ctx->pc = 0x101A68u;
    // 0x101a68: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x101a68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x101a6c: 0xae027958  sw          $v0, 0x7958($s0)
    ctx->pc = 0x101a6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 2));
    // 0x101a70: 0x26037958  addiu       $v1, $s0, 0x7958
    ctx->pc = 0x101a70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 16), 31064));
    // 0x101a74: 0x3c110020  lui         $s1, 0x20
    ctx->pc = 0x101a74u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)32 << 16));
    // 0x101a78: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x101a78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101a7c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x101a7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x101a80: 0x3c0b0010  lui         $t3, 0x10
    ctx->pc = 0x101a80u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)16 << 16));
    // 0x101a84: 0xae227934  sw          $v0, 0x7934($s1)
    ctx->pc = 0x101a84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 2));
    // 0x101a88: 0x24848ad0  addiu       $a0, $a0, -0x7530
    ctx->pc = 0x101a88u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937296));
    // 0x101a8c: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x101a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x101a90: 0x256b0298  addiu       $t3, $t3, 0x298
    ctx->pc = 0x101a90u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 664));
    // 0x101a94: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x101a94u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x101a98: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x101a98u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x101a9c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x101a9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101aa0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x101aa0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101aa4: 0x482d  daddu       $t1, $zero, $zero
    ctx->pc = 0x101aa4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101aa8: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101AA8u;
    SET_GPR_U32(ctx, 31, 0x101AB0u);
    ctx->pc = 0x101AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101AA8u;
            // 0x101aac: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101AB0u; }
        if (ctx->pc != 0x101AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101AB0u; }
        if (ctx->pc != 0x101AB0u) { return; }
    }
    ctx->pc = 0x101AB0u;
label_101ab0:
    // 0x101ab0: 0x4430007  bgezl       $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x101AB0u;
    {
        const bool branch_taken_0x101ab0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x101ab0) {
            ctx->pc = 0x101AB4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101AB0u;
            // 0x101ab4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x101AD0u;
            goto label_101ad0;
        }
    }
    ctx->pc = 0x101AB8u;
    // 0x101ab8: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x101ab8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101abc: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101abcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101ac0: 0xae207934  sw          $zero, 0x7934($s1)
    ctx->pc = 0x101ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 0));
    // 0x101ac4: 0xc045190  jal         func_114640
    ctx->pc = 0x101AC4u;
    SET_GPR_U32(ctx, 31, 0x101ACCu);
    ctx->pc = 0x101AC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101AC4u;
            // 0x101ac8: 0x8c447928  lw          $a0, 0x7928($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31016)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ACCu; }
        if (ctx->pc != 0x101ACCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ACCu; }
        if (ctx->pc != 0x101ACCu) { return; }
    }
    ctx->pc = 0x101ACCu;
label_101acc:
    // 0x101acc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x101accu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_101ad0:
    // 0x101ad0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x101ad0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101ad4: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101ad4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101ad8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101ad8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101adc: 0x3e00008  jr          $ra
    ctx->pc = 0x101ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101AE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101ADCu;
            // 0x101ae0: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101A4Cu: goto label_101a4c;
            case 0x101A60u: goto label_101a60;
            case 0x101AB0u: goto label_101ab0;
            case 0x101ACCu: goto label_101acc;
            case 0x101AD0u: goto label_101ad0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101AE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
