#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101C38
// Address: 0x101c38 - 0x101d08
void sub_00101C38_0x101c38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101C38_0x101c38");
#endif

    switch (ctx->pc) {
        case 0x101c60u: goto label_101c60;
        case 0x101c7cu: goto label_101c7c;
        case 0x101cbcu: goto label_101cbc;
        case 0x101cd0u: goto label_101cd0;
        case 0x101cecu: goto label_101cec;
        default: break;
    }

    ctx->pc = 0x101c38u;

    // 0x101c38: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x101c38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x101c3c: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x101c3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x101c40: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x101c40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x101c44: 0x3c110021  lui         $s1, 0x21
    ctx->pc = 0x101c44u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)33 << 16));
    // 0x101c48: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x101c48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x101c4c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x101c4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101c50: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x101c50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x101c54: 0x26328f40  addiu       $s2, $s1, -0x70C0
    ctx->pc = 0x101c54u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 17), 4294938432));
    // 0x101c58: 0xc0403a2  jal         func_100E88
    ctx->pc = 0x101C58u;
    SET_GPR_U32(ctx, 31, 0x101C60u);
    ctx->pc = 0x101C5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101C58u;
            // 0x101c5c: 0x24040022  addiu       $a0, $zero, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E88u;
    if (runtime->hasFunction(0x100E88u)) {
        auto targetFn = runtime->lookupFunction(0x100E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C60u; }
        if (ctx->pc != 0x101C60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E88_0x100e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C60u; }
        if (ctx->pc != 0x101C60u) { return; }
    }
    ctx->pc = 0x101C60u;
label_101c60:
    // 0x101c60: 0x54400003  bnel        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x101C60u;
    {
        const bool branch_taken_0x101c60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x101c60) {
            ctx->pc = 0x101C64u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x101C60u;
            // 0x101c64: 0xae308f40  sw          $s0, -0x70C0($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 4294938432), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x101C70u;
            goto label_101c70;
        }
    }
    ctx->pc = 0x101C68u;
    // 0x101c68: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x101C68u;
    {
        const bool branch_taken_0x101c68 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101C6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101C68u;
            // 0x101c6c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101c68) {
            ctx->pc = 0x101CF0u;
            goto label_101cf0;
        }
    }
    ctx->pc = 0x101C70u;
label_101c70:
    // 0x101c70: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x101c70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101c74: 0xc045bf4  jal         func_116FD0
    ctx->pc = 0x101C74u;
    SET_GPR_U32(ctx, 31, 0x101C7Cu);
    ctx->pc = 0x101C78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101C74u;
            // 0x101c78: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116FD0u;
    if (runtime->hasFunction(0x116FD0u)) {
        auto targetFn = runtime->lookupFunction(0x116FD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C7Cu; }
        if (ctx->pc != 0x101C7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C7Cu; }
        if (ctx->pc != 0x101C7Cu) { return; }
    }
    ctx->pc = 0x101C7Cu;
label_101c7c:
    // 0x101c7c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x101c7cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x101c80: 0x3c060021  lui         $a2, 0x21
    ctx->pc = 0x101c80u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)33 << 16));
    // 0x101c84: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x101c84u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x101c88: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x101c88u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x101c8c: 0x8c8894ac  lw          $t0, -0x6B54($a0)
    ctx->pc = 0x101c8cu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294939820)));
    // 0x101c90: 0x24508b00  addiu       $s0, $v0, -0x7500
    ctx->pc = 0x101c90u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937344));
    // 0x101c94: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x101c94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x101c98: 0x8cca94b0  lw          $t2, -0x6B50($a2)
    ctx->pc = 0x101c98u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 4294939824)));
    // 0x101c9c: 0x8c6594a8  lw          $a1, -0x6B58($v1)
    ctx->pc = 0x101c9cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294939816)));
    // 0x101ca0: 0x24849480  addiu       $a0, $a0, -0x6B80
    ctx->pc = 0x101ca0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939776));
    // 0x101ca4: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x101ca4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101ca8: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x101ca8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x101cac: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x101cacu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101cb0: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x101cb0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101cb4: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101CB4u;
    SET_GPR_U32(ctx, 31, 0x101CBCu);
    ctx->pc = 0x101CB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101CB4u;
            // 0x101cb8: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101CBCu; }
        if (ctx->pc != 0x101CBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101CBCu; }
        if (ctx->pc != 0x101CBCu) { return; }
    }
    ctx->pc = 0x101CBCu;
label_101cbc:
    // 0x101cbc: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x101CBCu;
    {
        const bool branch_taken_0x101cbc = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x101CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101CBCu;
            // 0x101cc0: 0x3c030020  lui         $v1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101cbc) {
            ctx->pc = 0x101CD8u;
            goto label_101cd8;
        }
    }
    ctx->pc = 0x101CC4u;
    // 0x101cc4: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101cc8: 0xc045190  jal         func_114640
    ctx->pc = 0x101CC8u;
    SET_GPR_U32(ctx, 31, 0x101CD0u);
    ctx->pc = 0x101CCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101CC8u;
            // 0x101ccc: 0x8c44792c  lw          $a0, 0x792C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101CD0u; }
        if (ctx->pc != 0x101CD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101CD0u; }
        if (ctx->pc != 0x101CD0u) { return; }
    }
    ctx->pc = 0x101CD0u;
label_101cd0:
    // 0x101cd0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x101CD0u;
    {
        const bool branch_taken_0x101cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101CD0u;
            // 0x101cd4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101cd0) {
            ctx->pc = 0x101CF0u;
            goto label_101cf0;
        }
    }
    ctx->pc = 0x101CD8u;
label_101cd8:
    // 0x101cd8: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x101cd8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x101cdc: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x101cdcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x101ce0: 0x8c64792c  lw          $a0, 0x792C($v1)
    ctx->pc = 0x101ce0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31020)));
    // 0x101ce4: 0xc045190  jal         func_114640
    ctx->pc = 0x101CE4u;
    SET_GPR_U32(ctx, 31, 0x101CECu);
    ctx->pc = 0x101CE8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101CE4u;
            // 0x101ce8: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101CECu; }
        if (ctx->pc != 0x101CECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101CECu; }
        if (ctx->pc != 0x101CECu) { return; }
    }
    ctx->pc = 0x101CECu;
label_101cec:
    // 0x101cec: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101cecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101cf0:
    // 0x101cf0: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x101cf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101cf4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x101cf4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101cf8: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101cf8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101cfc: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101cfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101d00: 0x3e00008  jr          $ra
    ctx->pc = 0x101D00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101D00u;
            // 0x101d04: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101C60u: goto label_101c60;
            case 0x101C70u: goto label_101c70;
            case 0x101C7Cu: goto label_101c7c;
            case 0x101CBCu: goto label_101cbc;
            case 0x101CD0u: goto label_101cd0;
            case 0x101CD8u: goto label_101cd8;
            case 0x101CECu: goto label_101cec;
            case 0x101CF0u: goto label_101cf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101D08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
