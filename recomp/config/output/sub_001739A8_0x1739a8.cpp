#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001739A8
// Address: 0x1739a8 - 0x173a48
void sub_001739A8_0x1739a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001739A8_0x1739a8");
#endif

    switch (ctx->pc) {
        case 0x1739bcu: goto label_1739bc;
        case 0x1739e8u: goto label_1739e8;
        case 0x1739f0u: goto label_1739f0;
        case 0x1739f8u: goto label_1739f8;
        case 0x173a00u: goto label_173a00;
        case 0x173a10u: goto label_173a10;
        default: break;
    }

    ctx->pc = 0x1739a8u;

    // 0x1739a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1739a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1739ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1739acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1739b0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1739b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1739b4: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1739B4u;
    SET_GPR_U32(ctx, 31, 0x1739BCu);
    ctx->pc = 0x1739B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739B4u;
            // 0x1739b8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739BCu; }
        if (ctx->pc != 0x1739BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739BCu; }
        if (ctx->pc != 0x1739BCu) { return; }
    }
    ctx->pc = 0x1739BCu;
label_1739bc:
    // 0x1739bc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1739BCu;
    {
        const bool branch_taken_0x1739bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1739C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1739BCu;
            // 0x1739c0: 0xdfbf0008  ld          $ra, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1739bc) {
            ctx->pc = 0x1739E0u;
            goto label_1739e0;
        }
    }
    ctx->pc = 0x1739C4u;
    // 0x1739c4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1739c4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1739c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1739c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1739cc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1739ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1739d0: 0x34a50131  ori         $a1, $a1, 0x131
    ctx->pc = 0x1739d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)305);
    // 0x1739d4: 0x805a704  j           func_169C10
    ctx->pc = 0x1739D4u;
    ctx->pc = 0x1739D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739D4u;
            // 0x1739d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1739DCu;
    // 0x1739dc: 0x0  nop
    ctx->pc = 0x1739dcu;
    // NOP
label_1739e0:
    // 0x1739e0: 0xc05cee0  jal         func_173B80
    ctx->pc = 0x1739E0u;
    SET_GPR_U32(ctx, 31, 0x1739E8u);
    ctx->pc = 0x1739E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739E0u;
            // 0x1739e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173B80u;
    if (runtime->hasFunction(0x173B80u)) {
        auto targetFn = runtime->lookupFunction(0x173B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739E8u; }
        if (ctx->pc != 0x1739E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173B80_0x173b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739E8u; }
        if (ctx->pc != 0x1739E8u) { return; }
    }
    ctx->pc = 0x1739E8u;
label_1739e8:
    // 0x1739e8: 0xc05a3de  jal         func_168F78
    ctx->pc = 0x1739E8u;
    SET_GPR_U32(ctx, 31, 0x1739F0u);
    ctx->pc = 0x1739ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739E8u;
            // 0x1739ec: 0x26040078  addiu       $a0, $s0, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 120));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168F78u;
    if (runtime->hasFunction(0x168F78u)) {
        auto targetFn = runtime->lookupFunction(0x168F78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739F0u; }
        if (ctx->pc != 0x1739F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168F78_0x168f78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739F0u; }
        if (ctx->pc != 0x1739F0u) { return; }
    }
    ctx->pc = 0x1739F0u;
label_1739f0:
    // 0x1739f0: 0xc059a78  jal         func_1669E0
    ctx->pc = 0x1739F0u;
    SET_GPR_U32(ctx, 31, 0x1739F8u);
    ctx->pc = 0x1739F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739F0u;
            // 0x1739f4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1669E0u;
    if (runtime->hasFunction(0x1669E0u)) {
        auto targetFn = runtime->lookupFunction(0x1669E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739F8u; }
        if (ctx->pc != 0x1739F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001669E0_0x1669e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1739F8u; }
        if (ctx->pc != 0x1739F8u) { return; }
    }
    ctx->pc = 0x1739F8u;
label_1739f8:
    // 0x1739f8: 0xc05ce92  jal         func_173A48
    ctx->pc = 0x1739F8u;
    SET_GPR_U32(ctx, 31, 0x173A00u);
    ctx->pc = 0x1739FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1739F8u;
            // 0x1739fc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173A48u;
    if (runtime->hasFunction(0x173A48u)) {
        auto targetFn = runtime->lookupFunction(0x173A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173A00u; }
        if (ctx->pc != 0x173A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173A48_0x173a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173A00u; }
        if (ctx->pc != 0x173A00u) { return; }
    }
    ctx->pc = 0x173A00u;
label_173a00:
    // 0x173a00: 0x24040007  addiu       $a0, $zero, 0x7
    ctx->pc = 0x173a00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x173a04: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x173a04u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173a08: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x173a08u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x173a0c: 0x2443f18c  addiu       $v1, $v0, -0xE74
    ctx->pc = 0x173a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
label_173a10:
    // 0x173a10: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x173a10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x173a14: 0x50500001  beql        $v0, $s0, . + 4 + (0x1 << 2)
    ctx->pc = 0x173A14u;
    {
        const bool branch_taken_0x173a14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 16));
        if (branch_taken_0x173a14) {
            ctx->pc = 0x173A18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173A14u;
            // 0x173a18: 0xac600000  sw          $zero, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173A1Cu;
            goto label_173a1c;
        }
    }
    ctx->pc = 0x173A1Cu;
label_173a1c:
    // 0x173a1c: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x173a1cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x173a20: 0x0  nop
    ctx->pc = 0x173a20u;
    // NOP
    // 0x173a24: 0x0  nop
    ctx->pc = 0x173a24u;
    // NOP
    // 0x173a28: 0x0  nop
    ctx->pc = 0x173a28u;
    // NOP
    // 0x173a2c: 0x481fff8  bgez        $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x173A2Cu;
    {
        const bool branch_taken_0x173a2c = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x173A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173A2Cu;
            // 0x173a30: 0x24630004  addiu       $v1, $v1, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173a2c) {
            ctx->pc = 0x173A10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_173a10;
        }
    }
    ctx->pc = 0x173A34u;
    // 0x173a34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173a38: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x173a38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173a3c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173a3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173a40: 0x3e00008  jr          $ra
    ctx->pc = 0x173A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173A40u;
            // 0x173a44: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1739BCu: goto label_1739bc;
            case 0x1739E0u: goto label_1739e0;
            case 0x1739E8u: goto label_1739e8;
            case 0x1739F0u: goto label_1739f0;
            case 0x1739F8u: goto label_1739f8;
            case 0x173A00u: goto label_173a00;
            case 0x173A10u: goto label_173a10;
            case 0x173A1Cu: goto label_173a1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173A48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
