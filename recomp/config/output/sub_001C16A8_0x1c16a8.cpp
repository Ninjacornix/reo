#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C16A8
// Address: 0x1c16a8 - 0x1c16e8
void sub_001C16A8_0x1c16a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C16A8_0x1c16a8");
#endif

    switch (ctx->pc) {
        case 0x1c16b8u: goto label_1c16b8;
        case 0x1c16d0u: goto label_1c16d0;
        default: break;
    }

    ctx->pc = 0x1c16a8u;

    // 0x1c16a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c16a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c16ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c16acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c16b0: 0xc07057a  jal         func_1C15E8
    ctx->pc = 0x1C16B0u;
    SET_GPR_U32(ctx, 31, 0x1C16B8u);
    ctx->pc = 0x1C15E8u;
    if (runtime->hasFunction(0x1C15E8u)) {
        auto targetFn = runtime->lookupFunction(0x1C15E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16B8u; }
        if (ctx->pc != 0x1C16B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C15E8_0x1c15e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16B8u; }
        if (ctx->pc != 0x1C16B8u) { return; }
    }
    ctx->pc = 0x1C16B8u;
label_1c16b8:
    // 0x1c16b8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C16B8u;
    {
        const bool branch_taken_0x1c16b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C16BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16B8u;
            // 0x1c16bc: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c16b8) {
            ctx->pc = 0x1C16C8u;
            goto label_1c16c8;
        }
    }
    ctx->pc = 0x1C16C0u;
    // 0x1c16c0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1C16C0u;
    {
        const bool branch_taken_0x1c16c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C16C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16C0u;
            // 0x1c16c4: 0x906252d2  lbu         $v0, 0x52D2($v1) (Delay Slot)
        SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 21202)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c16c0) {
            ctx->pc = 0x1C16DCu;
            goto label_1c16dc;
        }
    }
    ctx->pc = 0x1C16C8u;
label_1c16c8:
    // 0x1c16c8: 0xc0451b4  jal         func_1146D0
    ctx->pc = 0x1C16C8u;
    SET_GPR_U32(ctx, 31, 0x1C16D0u);
    ctx->pc = 0x1C16CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16C8u;
            // 0x1c16cc: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1146D0u;
    if (runtime->hasFunction(0x1146D0u)) {
        auto targetFn = runtime->lookupFunction(0x1146D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16D0u; }
        if (ctx->pc != 0x1C16D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001146D0_0x1146d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C16D0u; }
        if (ctx->pc != 0x1C16D0u) { return; }
    }
    ctx->pc = 0x1C16D0u;
label_1c16d0:
    // 0x1c16d0: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x1c16d0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c16d4: 0x21042  srl         $v0, $v0, 1
    ctx->pc = 0x1c16d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 1));
    // 0x1c16d8: 0x30420003  andi        $v0, $v0, 0x3
    ctx->pc = 0x1c16d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3);
label_1c16dc:
    // 0x1c16dc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c16dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c16e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C16E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C16E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C16E0u;
            // 0x1c16e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C16B8u: goto label_1c16b8;
            case 0x1C16C8u: goto label_1c16c8;
            case 0x1C16D0u: goto label_1c16d0;
            case 0x1C16DCu: goto label_1c16dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C16E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
