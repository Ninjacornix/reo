#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D3B00
// Address: 0x1d3b00 - 0x1d3b84
void sub_001D3B00_0x1d3b00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D3B00_0x1d3b00");
#endif

    switch (ctx->pc) {
        case 0x1d3b2cu: goto label_1d3b2c;
        case 0x1d3b4cu: goto label_1d3b4c;
        case 0x1d3b60u: goto label_1d3b60;
        case 0x1d3b70u: goto label_1d3b70;
        default: break;
    }

    ctx->pc = 0x1d3b00u;

    // 0x1d3b00: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x1d3b00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d3b04: 0x240300ff  addiu       $v1, $zero, 0xFF
    ctx->pc = 0x1d3b04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1d3b08: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1d3b08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3b0c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d3b0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3b10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d3b10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3b14: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d3b14u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3b18: 0x90840c7c  lbu         $a0, 0xC7C($a0)
    ctx->pc = 0x1d3b18u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3196)));
    // 0x1d3b1c: 0x10830014  beq         $a0, $v1, . + 4 + (0x14 << 2)
    ctx->pc = 0x1D3B1Cu;
    {
        const bool branch_taken_0x1d3b1c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3b1c) {
            ctx->pc = 0x1D3B70u;
            goto label_1d3b70;
        }
    }
    ctx->pc = 0x1D3B24u;
    // 0x1d3b24: 0xc16d338  jal         func_5B4CE0
    ctx->pc = 0x1D3B24u;
    SET_GPR_U32(ctx, 31, 0x1D3B2Cu);
    ctx->pc = 0x1D3B28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B24u;
            // 0x1d3b28: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x5B4CE0u;
    {
        auto targetFn = runtime->lookupFunction(0x5B4CE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B2Cu; }
        if (ctx->pc != 0x1D3B2Cu) { return; }
    }
    ctx->pc = 0x1D3B2Cu;
label_1d3b2c:
    // 0x1d3b2c: 0x2863c  dsll32      $s0, $v0, 24
    ctx->pc = 0x1d3b2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) << (32 + 24));
    // 0x1d3b30: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d3b30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d3b34: 0x10863f  dsra32      $s0, $s0, 24
    ctx->pc = 0x1d3b34u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 24));
    // 0x1d3b38: 0x1203000d  beq         $s0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1D3B38u;
    {
        const bool branch_taken_0x1d3b38 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 3));
        if (branch_taken_0x1d3b38) {
            ctx->pc = 0x1D3B70u;
            goto label_1d3b70;
        }
    }
    ctx->pc = 0x1D3B40u;
    // 0x1d3b40: 0x92240003  lbu         $a0, 0x3($s1)
    ctx->pc = 0x1d3b40u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3b44: 0xc1ad2b8  jal         func_6B4AE0
    ctx->pc = 0x1D3B44u;
    SET_GPR_U32(ctx, 31, 0x1D3B4Cu);
    ctx->pc = 0x1D3B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B44u;
            // 0x1d3b48: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x6B4AE0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B4AE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B4Cu; }
        if (ctx->pc != 0x1D3B4Cu) { return; }
    }
    ctx->pc = 0x1D3B4Cu;
label_1d3b4c:
    // 0x1d3b4c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d3b4cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d3b50: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x1d3b50u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3b54: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3b54u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3b58: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D3B58u;
    SET_GPR_U32(ctx, 31, 0x1D3B60u);
    ctx->pc = 0x1D3B5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B58u;
            // 0x1d3b5c: 0x24a56648  addiu       $a1, $a1, 0x6648 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 26184));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B60u; }
        if (ctx->pc != 0x1D3B60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B60u; }
        if (ctx->pc != 0x1D3B60u) { return; }
    }
    ctx->pc = 0x1D3B60u;
label_1d3b60:
    // 0x1d3b60: 0x92220003  lbu         $v0, 0x3($s1)
    ctx->pc = 0x1d3b60u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x1d3b64: 0x27a40030  addiu       $a0, $sp, 0x30
    ctx->pc = 0x1d3b64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3b68: 0xc06b584  jal         func_1AD610
    ctx->pc = 0x1D3B68u;
    SET_GPR_U32(ctx, 31, 0x1D3B70u);
    ctx->pc = 0x1D3B6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B68u;
            // 0x1d3b6c: 0x24450008  addiu       $a1, $v0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AD610u;
    if (runtime->hasFunction(0x1AD610u)) {
        auto targetFn = runtime->lookupFunction(0x1AD610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B70u; }
        if (ctx->pc != 0x1D3B70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AD610_0x1ad610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3B70u; }
        if (ctx->pc != 0x1D3B70u) { return; }
    }
    ctx->pc = 0x1D3B70u;
label_1d3b70:
    // 0x1d3b70: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1d3b70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3b74: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d3b74u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3b78: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d3b78u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3b7c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D3B7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3B80u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D3B7Cu;
            // 0x1d3b80: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3B2Cu: goto label_1d3b2c;
            case 0x1D3B4Cu: goto label_1d3b4c;
            case 0x1D3B60u: goto label_1d3b60;
            case 0x1D3B70u: goto label_1d3b70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3B84u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
