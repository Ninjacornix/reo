#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0A00
// Address: 0x1b0a00 - 0x1b0a80
void sub_001B0A00_0x1b0a00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0A00_0x1b0a00");
#endif

    switch (ctx->pc) {
        case 0x1b0a1cu: goto label_1b0a1c;
        case 0x1b0a58u: goto label_1b0a58;
        case 0x1b0a60u: goto label_1b0a60;
        default: break;
    }

    ctx->pc = 0x1b0a00u;

    // 0x1b0a00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b0a00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b0a04: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1b0a04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1b0a08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b0a08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b0a0c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1b0a0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b0a10: 0x8c25ffa8  lw          $a1, -0x58($at)
    ctx->pc = 0x1b0a10u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294967208)));
    // 0x1b0a14: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B0A14u;
    {
        const bool branch_taken_0x1b0a14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A14u;
            // 0x1b0a18: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0a14) {
            ctx->pc = 0x1B0A44u;
            goto label_1b0a44;
        }
    }
    ctx->pc = 0x1B0A1Cu;
label_1b0a1c:
    // 0x1b0a1c: 0x41100  sll         $v0, $a0, 4
    ctx->pc = 0x1b0a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 4));
    // 0x1b0a20: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x1b0a20u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1b0a24: 0x210c0  sll         $v0, $v0, 3
    ctx->pc = 0x1b0a24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1b0a28: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1b0a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1b0a2c: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1b0a2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1b0a30: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0A30u;
    {
        const bool branch_taken_0x1b0a30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1B0A34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A30u;
            // 0x1b0a34: 0x24c20001  addiu       $v0, $a2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0a30) {
            ctx->pc = 0x1B0A40u;
            goto label_1b0a40;
        }
    }
    ctx->pc = 0x1B0A38u;
    // 0x1b0a38: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1B0A38u;
    {
        const bool branch_taken_0x1b0a38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0A3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A38u;
            // 0x1b0a3c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0a38) {
            ctx->pc = 0x1B0A68u;
            goto label_1b0a68;
        }
    }
    ctx->pc = 0x1B0A40u;
label_1b0a40:
    // 0x1b0a40: 0x304600ff  andi        $a2, $v0, 0xFF
    ctx->pc = 0x1b0a40u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
label_1b0a44:
    // 0x1b0a44: 0x30c200ff  andi        $v0, $a2, 0xFF
    ctx->pc = 0x1b0a44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
    // 0x1b0a48: 0x1840fff4  blez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1B0A48u;
    {
        const bool branch_taken_0x1b0a48 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x1B0A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A48u;
            // 0x1b0a4c: 0x30c400ff  andi        $a0, $a2, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0a48) {
            ctx->pc = 0x1B0A1Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b0a1c;
        }
    }
    ctx->pc = 0x1B0A50u;
    // 0x1b0a50: 0xc068764  jal         func_1A1D90
    ctx->pc = 0x1B0A50u;
    SET_GPR_U32(ctx, 31, 0x1B0A58u);
    ctx->pc = 0x1B0A54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A50u;
            // 0x1b0a54: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1D90u;
    if (runtime->hasFunction(0x1A1D90u)) {
        auto targetFn = runtime->lookupFunction(0x1A1D90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0A58u; }
        if (ctx->pc != 0x1B0A58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1D90_0x1a1d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0A58u; }
        if (ctx->pc != 0x1B0A58u) { return; }
    }
    ctx->pc = 0x1B0A58u;
label_1b0a58:
    // 0x1b0a58: 0xc06874c  jal         func_1A1D30
    ctx->pc = 0x1B0A58u;
    SET_GPR_U32(ctx, 31, 0x1B0A60u);
    ctx->pc = 0x1A1D30u;
    if (runtime->hasFunction(0x1A1D30u)) {
        auto targetFn = runtime->lookupFunction(0x1A1D30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0A60u; }
        if (ctx->pc != 0x1B0A60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1D30_0x1a1d30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0A60u; }
        if (ctx->pc != 0x1B0A60u) { return; }
    }
    ctx->pc = 0x1B0A60u;
label_1b0a60:
    // 0x1b0a60: 0x2163c  dsll32      $v0, $v0, 24
    ctx->pc = 0x1b0a60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1b0a64: 0x2163f  dsra32      $v0, $v0, 24
    ctx->pc = 0x1b0a64u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 24));
label_1b0a68:
    // 0x1b0a68: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b0a68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b0a6c: 0x3e00008  jr          $ra
    ctx->pc = 0x1B0A6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B0A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0A6Cu;
            // 0x1b0a70: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0A1Cu: goto label_1b0a1c;
            case 0x1B0A40u: goto label_1b0a40;
            case 0x1B0A44u: goto label_1b0a44;
            case 0x1B0A58u: goto label_1b0a58;
            case 0x1B0A60u: goto label_1b0a60;
            case 0x1B0A68u: goto label_1b0a68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B0A74u;
    // 0x1b0a74: 0x0  nop
    ctx->pc = 0x1b0a74u;
    // NOP
    // 0x1b0a78: 0x0  nop
    ctx->pc = 0x1b0a78u;
    // NOP
    // 0x1b0a7c: 0x0  nop
    ctx->pc = 0x1b0a7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
