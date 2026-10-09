#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FF60
// Address: 0x12ff60 - 0x12fff4
void sub_0012FF60_0x12ff60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FF60_0x12ff60");
#endif

    switch (ctx->pc) {
        case 0x12ff74u: goto label_12ff74;
        case 0x12ff88u: goto label_12ff88;
        case 0x12ffb0u: goto label_12ffb0;
        case 0x12ffd0u: goto label_12ffd0;
        default: break;
    }

    ctx->pc = 0x12ff60u;

    // 0x12ff60: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12ff60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12ff64: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12ff64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12ff68: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x12ff68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x12ff6c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12ff6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12ff70: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12ff70u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_12ff74:
    // 0x12ff74: 0x82020003  lb          $v0, 0x3($s0)
    ctx->pc = 0x12ff74u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x12ff78: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x12FF78u;
    {
        const bool branch_taken_0x12ff78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FF7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF78u;
            // 0x12ff7c: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ff78) {
            ctx->pc = 0x12FFC8u;
            goto label_12ffc8;
        }
    }
    ctx->pc = 0x12FF80u;
    // 0x12ff80: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x12FF80u;
    {
        const bool branch_taken_0x12ff80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x12ff80) {
            ctx->pc = 0x12FFA8u;
            goto label_12ffa8;
        }
    }
    ctx->pc = 0x12FF88u;
label_12ff88:
    // 0x12ff88: 0x8e030030  lw          $v1, 0x30($s0)
    ctx->pc = 0x12ff88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x12ff8c: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x12ff8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x12ff90: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x12ff90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x12ff94: 0x64182a  slt         $v1, $v1, $a0
    ctx->pc = 0x12ff94u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x12ff98: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x12FF98u;
    {
        const bool branch_taken_0x12ff98 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x12FF9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FF98u;
            // 0x12ff9c: 0xae02002c  sw          $v0, 0x2C($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ff98) {
            ctx->pc = 0x12FFA8u;
            goto label_12ffa8;
        }
    }
    ctx->pc = 0x12FFA0u;
    // 0x12ffa0: 0x1000fff4  b           . + 4 + (-0xC << 2)
    ctx->pc = 0x12FFA0u;
    {
        const bool branch_taken_0x12ffa0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FFA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFA0u;
            // 0x12ffa4: 0xa2110003  sb          $s1, 0x3($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ffa0) {
            ctx->pc = 0x12FF74u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ff74;
        }
    }
    ctx->pc = 0x12FFA8u;
label_12ffa8:
    // 0x12ffa8: 0xc04bbb8  jal         func_12EEE0
    ctx->pc = 0x12FFA8u;
    SET_GPR_U32(ctx, 31, 0x12FFB0u);
    ctx->pc = 0x12FFACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFA8u;
            // 0x12ffac: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12EEE0u;
    if (runtime->hasFunction(0x12EEE0u)) {
        auto targetFn = runtime->lookupFunction(0x12EEE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFB0u; }
        if (ctx->pc != 0x12FFB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012EEE0_0x12eee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFB0u; }
        if (ctx->pc != 0x12FFB0u) { return; }
    }
    ctx->pc = 0x12FFB0u;
label_12ffb0:
    // 0x12ffb0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x12ffb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12ffb4: 0x54a0fff4  bnel        $a1, $zero, . + 4 + (-0xC << 2)
    ctx->pc = 0x12FFB4u;
    {
        const bool branch_taken_0x12ffb4 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        if (branch_taken_0x12ffb4) {
            ctx->pc = 0x12FFB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFB4u;
            // 0x12ffb8: 0x8e02002c  lw          $v0, 0x2C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 44)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FF88u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12ff88;
        }
    }
    ctx->pc = 0x12FFBCu;
    // 0x12ffbc: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x12FFBCu;
    {
        const bool branch_taken_0x12ffbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FFC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFBCu;
            // 0x12ffc0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12ffbc) {
            ctx->pc = 0x12FFE4u;
            goto label_12ffe4;
        }
    }
    ctx->pc = 0x12FFC4u;
    // 0x12ffc4: 0x0  nop
    ctx->pc = 0x12ffc4u;
    // NOP
label_12ffc8:
    // 0x12ffc8: 0xc04bbe4  jal         func_12EF90
    ctx->pc = 0x12FFC8u;
    SET_GPR_U32(ctx, 31, 0x12FFD0u);
    ctx->pc = 0x12FFCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFC8u;
            // 0x12ffcc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12EF90u;
    if (runtime->hasFunction(0x12EF90u)) {
        auto targetFn = runtime->lookupFunction(0x12EF90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFD0u; }
        if (ctx->pc != 0x12FFD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012EF90_0x12ef90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12FFD0u; }
        if (ctx->pc != 0x12FFD0u) { return; }
    }
    ctx->pc = 0x12FFD0u;
label_12ffd0:
    // 0x12ffd0: 0x58400004  blezl       $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x12FFD0u;
    {
        const bool branch_taken_0x12ffd0 = (GPR_S64(ctx, 2) <= 0);
        if (branch_taken_0x12ffd0) {
            ctx->pc = 0x12FFD4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFD0u;
            // 0x12ffd4: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12FFE4u;
            goto label_12ffe4;
        }
    }
    ctx->pc = 0x12FFD8u;
    // 0x12ffd8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x12ffd8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12ffdc: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x12ffdcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12ffe0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12ffe0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12ffe4:
    // 0x12ffe4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12ffe4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12ffe8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x12ffe8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12ffec: 0x3e00008  jr          $ra
    ctx->pc = 0x12FFECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12FFF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FFECu;
            // 0x12fff0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FF74u: goto label_12ff74;
            case 0x12FF88u: goto label_12ff88;
            case 0x12FFA8u: goto label_12ffa8;
            case 0x12FFB0u: goto label_12ffb0;
            case 0x12FFC8u: goto label_12ffc8;
            case 0x12FFD0u: goto label_12ffd0;
            case 0x12FFE4u: goto label_12ffe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FFF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
