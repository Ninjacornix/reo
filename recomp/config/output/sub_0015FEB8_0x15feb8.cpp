#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FEB8
// Address: 0x15feb8 - 0x15ffc0
void sub_0015FEB8_0x15feb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FEB8_0x15feb8");
#endif

    switch (ctx->pc) {
        case 0x15ff38u: goto label_15ff38;
        default: break;
    }

    ctx->pc = 0x15feb8u;

    // 0x15feb8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15feb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15febc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15febcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fec0: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x15FEC0u;
    {
        const bool branch_taken_0x15fec0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FEC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FEC0u;
            // 0x15fec4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fec0) {
            ctx->pc = 0x15FECCu;
            goto label_15fecc;
        }
    }
    ctx->pc = 0x15FEC8u;
    // 0x15fec8: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x15fec8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
label_15fecc:
    // 0x15fecc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15feccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fed0: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15fed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fed4: 0x805d4ce  j           func_175338
    ctx->pc = 0x15FED4u;
    ctx->pc = 0x15FED8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FED4u;
            // 0x15fed8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FEDCu;
    // 0x15fedc: 0x0  nop
    ctx->pc = 0x15fedcu;
    // NOP
    // 0x15fee0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15fee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15fee4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15fee4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fee8: 0x10800002  beqz        $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x15FEE8u;
    {
        const bool branch_taken_0x15fee8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x15FEECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FEE8u;
            // 0x15feec: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15fee8) {
            ctx->pc = 0x15FEF4u;
            goto label_15fef4;
        }
    }
    ctx->pc = 0x15FEF0u;
    // 0x15fef0: 0x8c820040  lw          $v0, 0x40($a0)
    ctx->pc = 0x15fef0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
label_15fef4:
    // 0x15fef4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15fef4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15fef8: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15fef8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fefc: 0x805d562  j           func_175588
    ctx->pc = 0x15FEFCu;
    ctx->pc = 0x15FF00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FEFCu;
            // 0x15ff00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175588u;
    if (runtime->hasFunction(0x175588u)) {
        auto targetFn = runtime->lookupFunction(0x175588u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175588_0x175588(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF04u;
    // 0x15ff04: 0x0  nop
    ctx->pc = 0x15ff04u;
    // NOP
    // 0x15ff08: 0x3e00008  jr          $ra
    ctx->pc = 0x15FF08u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF08u;
            // 0x15ff0c: 0x8c820044  lw          $v0, 0x44($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FECCu: goto label_15fecc;
            case 0x15FEF4u: goto label_15fef4;
            case 0x15FF38u: goto label_15ff38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FF10u;
    // 0x15ff10: 0x3e00008  jr          $ra
    ctx->pc = 0x15FF10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15FF14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF10u;
            // 0x15ff14: 0x8c820134  lw          $v0, 0x134($a0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 308)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15FECCu: goto label_15fecc;
            case 0x15FEF4u: goto label_15fef4;
            case 0x15FF38u: goto label_15ff38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15FF18u;
    // 0x15ff18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15ff18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15ff1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ff1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ff20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15ff20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ff24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ff28: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15ff28u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff2c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15ff2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15ff30: 0xc059150  jal         func_164540
    ctx->pc = 0x15FF30u;
    SET_GPR_U32(ctx, 31, 0x15FF38u);
    ctx->pc = 0x15FF34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF30u;
            // 0x15ff34: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164540u;
    if (runtime->hasFunction(0x164540u)) {
        auto targetFn = runtime->lookupFunction(0x164540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FF38u; }
        if (ctx->pc != 0x15FF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164540_0x164540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FF38u; }
        if (ctx->pc != 0x15FF38u) { return; }
    }
    ctx->pc = 0x15FF38u;
label_15ff38:
    // 0x15ff38: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ff38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff3c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15ff3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff40: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15ff40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15ff44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15ff44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15ff48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15ff4c: 0x8058aa6  j           func_162A98
    ctx->pc = 0x15FF4Cu;
    ctx->pc = 0x15FF50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF4Cu;
            // 0x15ff50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162A98u;
    if (runtime->hasFunction(0x162A98u)) {
        auto targetFn = runtime->lookupFunction(0x162A98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00162A98_0x162a98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF54u;
    // 0x15ff54: 0x0  nop
    ctx->pc = 0x15ff54u;
    // NOP
    // 0x15ff58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ff58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ff5c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ff5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ff60: 0x8c840044  lw          $a0, 0x44($a0)
    ctx->pc = 0x15ff60u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15ff64: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ff64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff68: 0x805915a  j           func_164568
    ctx->pc = 0x15FF68u;
    ctx->pc = 0x15FF6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF68u;
            // 0x15ff6c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164568u;
    if (runtime->hasFunction(0x164568u)) {
        auto targetFn = runtime->lookupFunction(0x164568u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00164568_0x164568(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF70u;
    // 0x15ff70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ff70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ff74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ff74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ff78: 0x8c840044  lw          $a0, 0x44($a0)
    ctx->pc = 0x15ff78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15ff7c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ff7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff80: 0x8059108  j           func_164420
    ctx->pc = 0x15FF80u;
    ctx->pc = 0x15FF84u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF80u;
            // 0x15ff84: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164420u;
    if (runtime->hasFunction(0x164420u)) {
        auto targetFn = runtime->lookupFunction(0x164420u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00164420_0x164420(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF88u;
    // 0x15ff88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ff88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ff8c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ff8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ff90: 0x8c840044  lw          $a0, 0x44($a0)
    ctx->pc = 0x15ff90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 68)));
    // 0x15ff94: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ff94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff98: 0x8059112  j           func_164448
    ctx->pc = 0x15FF98u;
    ctx->pc = 0x15FF9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF98u;
            // 0x15ff9c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164448u;
    {
        auto targetFn = runtime->lookupFunction(0x164448u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x15FFA0u;
    // 0x15ffa0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15ffa0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15ffa4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x15ffa4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ffa8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x15ffa8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x15ffac: 0x2405002c  addiu       $a1, $zero, 0x2C
    ctx->pc = 0x15ffacu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x15ffb0: 0x8c840040  lw          $a0, 0x40($a0)
    ctx->pc = 0x15ffb0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x15ffb4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x15ffb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ffb8: 0x805d4ce  j           func_175338
    ctx->pc = 0x15FFB8u;
    ctx->pc = 0x15FFBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FFB8u;
            // 0x15ffbc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175338u;
    if (runtime->hasFunction(0x175338u)) {
        auto targetFn = runtime->lookupFunction(0x175338u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00175338_0x175338(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FFC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
