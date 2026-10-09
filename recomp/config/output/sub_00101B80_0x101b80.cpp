#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00101B80
// Address: 0x101b80 - 0x101c38
void sub_00101B80_0x101b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00101B80_0x101b80");
#endif

    switch (ctx->pc) {
        case 0x101b98u: goto label_101b98;
        case 0x101be4u: goto label_101be4;
        case 0x101bf8u: goto label_101bf8;
        case 0x101c20u: goto label_101c20;
        default: break;
    }

    ctx->pc = 0x101b80u;

    // 0x101b80: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x101b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x101b84: 0x2404001e  addiu       $a0, $zero, 0x1E
    ctx->pc = 0x101b84u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x101b88: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x101b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x101b8c: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x101b8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x101b90: 0xc0403a2  jal         func_100E88
    ctx->pc = 0x101B90u;
    SET_GPR_U32(ctx, 31, 0x101B98u);
    ctx->pc = 0x101B94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101B90u;
            // 0x101b94: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x100E88u;
    if (runtime->hasFunction(0x100E88u)) {
        auto targetFn = runtime->lookupFunction(0x100E88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B98u; }
        if (ctx->pc != 0x101B98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E88_0x100e88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101B98u; }
        if (ctx->pc != 0x101B98u) { return; }
    }
    ctx->pc = 0x101B98u;
label_101b98:
    // 0x101b98: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x101B98u;
    {
        const bool branch_taken_0x101b98 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x101B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101B98u;
            // 0x101b9c: 0x3c020021  lui         $v0, 0x21 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101b98) {
            ctx->pc = 0x101BA8u;
            goto label_101ba8;
        }
    }
    ctx->pc = 0x101BA0u;
    // 0x101ba0: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x101BA0u;
    {
        const bool branch_taken_0x101ba0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101BA0u;
            // 0x101ba4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101ba0) {
            ctx->pc = 0x101C24u;
            goto label_101c24;
        }
    }
    ctx->pc = 0x101BA8u;
label_101ba8:
    // 0x101ba8: 0x3c100020  lui         $s0, 0x20
    ctx->pc = 0x101ba8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)32 << 16));
    // 0x101bac: 0x24518b00  addiu       $s1, $v0, -0x7500
    ctx->pc = 0x101bacu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937344));
    // 0x101bb0: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x101bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x101bb4: 0x3c040021  lui         $a0, 0x21
    ctx->pc = 0x101bb4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)33 << 16));
    // 0x101bb8: 0xae037958  sw          $v1, 0x7958($s0)
    ctx->pc = 0x101bb8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 3));
    // 0x101bbc: 0x24849480  addiu       $a0, $a0, -0x6B80
    ctx->pc = 0x101bbcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294939776));
    // 0x101bc0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x101bc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x101bc4: 0x24050016  addiu       $a1, $zero, 0x16
    ctx->pc = 0x101bc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x101bc8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x101bc8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bcc: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x101bccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bd0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x101bd0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bd4: 0x220482d  daddu       $t1, $s1, $zero
    ctx->pc = 0x101bd4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101bd8: 0x240a0004  addiu       $t2, $zero, 0x4
    ctx->pc = 0x101bd8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x101bdc: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x101BDCu;
    SET_GPR_U32(ctx, 31, 0x101BE4u);
    ctx->pc = 0x101BE0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101BDCu;
            // 0x101be0: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101BE4u; }
        if (ctx->pc != 0x101BE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101BE4u; }
        if (ctx->pc != 0x101BE4u) { return; }
    }
    ctx->pc = 0x101BE4u;
label_101be4:
    // 0x101be4: 0x4410007  bgez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x101BE4u;
    {
        const bool branch_taken_0x101be4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x101BE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101BE4u;
            // 0x101be8: 0x3c020020  lui         $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101be4) {
            ctx->pc = 0x101C04u;
            goto label_101c04;
        }
    }
    ctx->pc = 0x101BECu;
    // 0x101bec: 0x8c44792c  lw          $a0, 0x792C($v0)
    ctx->pc = 0x101becu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 31020)));
    // 0x101bf0: 0xc045190  jal         func_114640
    ctx->pc = 0x101BF0u;
    SET_GPR_U32(ctx, 31, 0x101BF8u);
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101BF8u; }
        if (ctx->pc != 0x101BF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101BF8u; }
        if (ctx->pc != 0x101BF8u) { return; }
    }
    ctx->pc = 0x101BF8u;
label_101bf8:
    // 0x101bf8: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x101bf8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101bfc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x101BFCu;
    {
        const bool branch_taken_0x101bfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x101C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101BFCu;
            // 0x101c00: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x101bfc) {
            ctx->pc = 0x101C24u;
            goto label_101c24;
        }
    }
    ctx->pc = 0x101C04u;
label_101c04:
    // 0x101c04: 0xae007958  sw          $zero, 0x7958($s0)
    ctx->pc = 0x101c04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101c08: 0x3c030020  lui         $v1, 0x20
    ctx->pc = 0x101c08u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32 << 16));
    // 0x101c0c: 0x3c022000  lui         $v0, 0x2000
    ctx->pc = 0x101c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)8192 << 16));
    // 0x101c10: 0x2221025  or          $v0, $s1, $v0
    ctx->pc = 0x101c10u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) | GPR_U64(ctx, 2));
    // 0x101c14: 0x8c64792c  lw          $a0, 0x792C($v1)
    ctx->pc = 0x101c14u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 31020)));
    // 0x101c18: 0xc045190  jal         func_114640
    ctx->pc = 0x101C18u;
    SET_GPR_U32(ctx, 31, 0x101C20u);
    ctx->pc = 0x101C1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x101C18u;
            // 0x101c1c: 0x8c500000  lw          $s0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C20u; }
        if (ctx->pc != 0x101C20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101C20u; }
        if (ctx->pc != 0x101C20u) { return; }
    }
    ctx->pc = 0x101C20u;
label_101c20:
    // 0x101c20: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x101c20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_101c24:
    // 0x101c24: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x101c24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101c28: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x101c28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101c2c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x101c2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101c30: 0x3e00008  jr          $ra
    ctx->pc = 0x101C30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x101C30u;
            // 0x101c34: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101B98u: goto label_101b98;
            case 0x101BA8u: goto label_101ba8;
            case 0x101BE4u: goto label_101be4;
            case 0x101BF8u: goto label_101bf8;
            case 0x101C04u: goto label_101c04;
            case 0x101C20u: goto label_101c20;
            case 0x101C24u: goto label_101c24;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101C38u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
