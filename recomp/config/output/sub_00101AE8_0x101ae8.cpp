#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101AE8
// Address: 0x101ae8 - 0x101b80
void sub_00101AE8_0x101ae8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101AE8_0x101ae8");
#endif

    switch (ctx->pc) {
        case 0x101afcu: goto label_101afc;
        case 0x101b3cu: goto label_101b3c;
        case 0x101b50u: goto label_101b50;
        case 0x101b6cu: goto label_101b6c;
        default: break;
    }

    ctx->pc = 0x101ae8u;

    // 0x101ae8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x101ae8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x101aec: 0x24040003  addiu       $a0, $zero, 0x3
    ctx->pc = 0x101aecu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x101af0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x101af0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x101af4: 0xc0403a2  jal         func_100E88
    ctx->pc = 0x101AF4u;
    SET_GPR_U32(ctx, 31, 0x101AFCu);
    ctx->pc = 0x101AF8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101AF4u;
            // 0x101af8: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E88u;
    if (runtime->hasFunction(0x100E88u)) {
        auto targetFn = runtime->lookupFunction(0x100E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101AFCu; }
        if (ctx->pc != 0x101AFCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E88_0x100e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101AFCu; }
        if (ctx->pc != 0x101AFCu) { return; }
    }
    ctx->pc = 0x101AFCu;
label_101afc:
    // 0x101afc: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101AFCu;
    {
        const bool branch_taken_0x101afc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x101B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101AFCu;
            // 0x101b00: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101afc) {
            ctx->pc = 0x101B0Cu;
            goto label_101b0c;
        }
    }
    ctx->pc = 0x101B04u;
    // 0x101b04: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x101B04u;
    {
        const bool branch_taken_0x101b04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101B04u;
            // 0x101b08: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101b04) {
            ctx->pc = 0x101B70u;
            goto label_101b70;
        }
    }
    ctx->pc = 0x101B0Cu;
label_101b0c:
    // 0x101b0c: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x101b0cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x101b10: 0x24508b00  addiu       $s0, $v0, -0x7500
    ctx->pc = 0x101b10u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937344));
    // 0x101b14: 0x24849480  addiu       $a0, $a0, -0x6B80
    ctx->pc = 0x101b14u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939776));
    // 0x101b18: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x101b18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x101b1c: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x101b1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x101b20: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x101b20u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101b24: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x101b24u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101b28: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x101b28u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101b2c: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x101b2cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101b30: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x101b30u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x101b34: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101B34u;
    SET_GPR_U32(ctx, 31, 0x101B3Cu);
    ctx->pc = 0x101B38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101B34u;
            // 0x101b38: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B3Cu; }
        if (ctx->pc != 0x101B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B3Cu; }
        if (ctx->pc != 0x101B3Cu) { return; }
    }
    ctx->pc = 0x101B3Cu;
label_101b3c:
    // 0x101b3c: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x101B3Cu;
    {
        const bool branch_taken_0x101b3c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x101B40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101B3Cu;
            // 0x101b40: 0x3c030020  lui         $v1, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101b3c) {
            ctx->pc = 0x101B58u;
            goto label_101b58;
        }
    }
    ctx->pc = 0x101B44u;
    // 0x101b44: 0x3c020020  lui         $v0, 0x20
    ctx->pc = 0x101b44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
    // 0x101b48: 0xc045190  jal         func_114640
    ctx->pc = 0x101B48u;
    SET_GPR_U32(ctx, 31, 0x101B50u);
    ctx->pc = 0x101B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101B48u;
            // 0x101b4c: 0x8c44792c  lw          $a0, 0x792C($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B50u; }
        if (ctx->pc != 0x101B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B50u; }
        if (ctx->pc != 0x101B50u) { return; }
    }
    ctx->pc = 0x101B50u;
label_101b50:
    // 0x101b50: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x101B50u;
    {
        const bool branch_taken_0x101b50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101B54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101B50u;
            // 0x101b54: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101b50) {
            ctx->pc = 0x101B70u;
            goto label_101b70;
        }
    }
    ctx->pc = 0x101B58u;
label_101b58:
    // 0x101b58: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x101b58u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x101b5c: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x101b5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x101b60: 0x8c64792c  lw          $a0, 0x792C($v1)
    ctx->pc = 0x101b60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31020)));
    // 0x101b64: 0xc045190  jal         func_114640
    ctx->pc = 0x101B64u;
    SET_GPR_U32(ctx, 31, 0x101B6Cu);
    ctx->pc = 0x101B68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101B64u;
            // 0x101b68: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B6Cu; }
        if (ctx->pc != 0x101B6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B6Cu; }
        if (ctx->pc != 0x101B6Cu) { return; }
    }
    ctx->pc = 0x101B6Cu;
label_101b6c:
    // 0x101b6c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101b6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101b70:
    // 0x101b70: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x101b70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101b74: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101b74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101b78: 0x3e00008  jr          $ra
    ctx->pc = 0x101B78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101B7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101B78u;
            // 0x101b7c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101AFCu: goto label_101afc;
            case 0x101B0Cu: goto label_101b0c;
            case 0x101B3Cu: goto label_101b3c;
            case 0x101B50u: goto label_101b50;
            case 0x101B58u: goto label_101b58;
            case 0x101B6Cu: goto label_101b6c;
            case 0x101B70u: goto label_101b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101B80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
