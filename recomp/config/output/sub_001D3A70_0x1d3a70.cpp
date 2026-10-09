#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3A70
// Address: 0x1d3a70 - 0x1d3af4
void sub_001D3A70_0x1d3a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3A70_0x1d3a70");
#endif

    switch (ctx->pc) {
        case 0x1d3a9cu: goto label_1d3a9c;
        case 0x1d3abcu: goto label_1d3abc;
        case 0x1d3ad0u: goto label_1d3ad0;
        case 0x1d3ae0u: goto label_1d3ae0;
        default: break;
    }

    ctx->pc = 0x1d3a70u;

    // 0x1d3a70: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1d3a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d3a74: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1d3a74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d3a78: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3a7c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3a7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3a80: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3a80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3a84: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3a84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3a88: 0x90840c7c  lbu         $a0, 0xC7C($a0)
    ctx->pc = 0x1d3a88u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3196)));
    // 0x1d3a8c: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1D3A8Cu;
    {
        const bool branch_taken_0x1d3a8c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3a8c) {
            ctx->pc = 0x1D3AE0u;
            goto label_1d3ae0;
        }
    }
    ctx->pc = 0x1D3A94u;
    // 0x1d3a94: 0xc16d338  jal         func_5B4CE0
    ctx->pc = 0x1D3A94u;
    SET_GPR_U32(ctx, 31, 0x1D3A9Cu);
    ctx->pc = 0x1D3A98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3A94u;
            // 0x1d3a98: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x5B4CE0u;
    {
        auto targetFn = runtime->lookupFunction(0x5B4CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3A9Cu; }
        if (ctx->pc != 0x1D3A9Cu) { return; }
    }
    ctx->pc = 0x1D3A9Cu;
label_1d3a9c:
    // 0x1d3a9c: 0x2863c  dsll32      $s0, $v0, 24
    ctx->pc = 0x1d3a9cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1d3aa0: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d3aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d3aa4: 0x10863f  dsra32      $s0, $s0, 24
    ctx->pc = 0x1d3aa4u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 24));
    // 0x1d3aa8: 0x1203000d  beq         $s0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1D3AA8u;
    {
        const bool branch_taken_0x1d3aa8 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3aa8) {
            ctx->pc = 0x1D3AE0u;
            goto label_1d3ae0;
        }
    }
    ctx->pc = 0x1D3AB0u;
    // 0x1d3ab0: 0x92240003  lbu         $a0, 0x3($s1)
    ctx->pc = 0x1d3ab0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3ab4: 0xc1ad2b8  jal         func_6B4AE0
    ctx->pc = 0x1D3AB4u;
    SET_GPR_U32(ctx, 31, 0x1D3ABCu);
    ctx->pc = 0x1D3AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AB4u;
            // 0x1d3ab8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B4AE0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B4AE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3ABCu; }
        if (ctx->pc != 0x1D3ABCu) { return; }
    }
    ctx->pc = 0x1D3ABCu;
label_1d3abc:
    // 0x1d3abc: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3abcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3ac0: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d3ac0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3ac4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3ac8: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3AC8u;
    SET_GPR_U32(ctx, 31, 0x1D3AD0u);
    ctx->pc = 0x1D3ACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AC8u;
            // 0x1d3acc: 0x24a56648  addiu       $a1, $a1, 0x6648 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AD0u; }
        if (ctx->pc != 0x1D3AD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AD0u; }
        if (ctx->pc != 0x1D3AD0u) { return; }
    }
    ctx->pc = 0x1D3AD0u;
label_1d3ad0:
    // 0x1d3ad0: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1d3ad0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3ad4: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3ad4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3ad8: 0xc074f70  jal         func_1D3DC0
    ctx->pc = 0x1D3AD8u;
    SET_GPR_U32(ctx, 31, 0x1D3AE0u);
    ctx->pc = 0x1D3ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AD8u;
            // 0x1d3adc: 0x24450008  addiu       $a1, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D3DC0u;
    if (runtime->hasFunction(0x1D3DC0u)) {
        auto targetFn = runtime->lookupFunction(0x1D3DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AE0u; }
        if (ctx->pc != 0x1D3AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D3DC0_0x1d3dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3AE0u; }
        if (ctx->pc != 0x1D3AE0u) { return; }
    }
    ctx->pc = 0x1D3AE0u;
label_1d3ae0:
    // 0x1d3ae0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d3ae0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3ae4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3ae4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3ae8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3ae8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3aec: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3AECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3AECu;
            // 0x1d3af0: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3A9Cu: goto label_1d3a9c;
            case 0x1D3ABCu: goto label_1d3abc;
            case 0x1D3AD0u: goto label_1d3ad0;
            case 0x1D3AE0u: goto label_1d3ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3AF4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
