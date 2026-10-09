#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169B38
// Address: 0x169b38 - 0x169be0
void sub_00169B38_0x169b38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169B38_0x169b38");
#endif

    switch (ctx->pc) {
        case 0x169b60u: goto label_169b60;
        case 0x169b74u: goto label_169b74;
        case 0x169b94u: goto label_169b94;
        case 0x169b9cu: goto label_169b9c;
        case 0x169ba4u: goto label_169ba4;
        case 0x169bacu: goto label_169bac;
        case 0x169bb4u: goto label_169bb4;
        case 0x169bbcu: goto label_169bbc;
        default: break;
    }

    ctx->pc = 0x169b38u;

    // 0x169b38: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x169b38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x169b3c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x169b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x169b40: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x169b40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x169b44: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x169b44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x169b48: 0x24100007  addiu       $s0, $zero, 0x7
    ctx->pc = 0x169b48u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x169b4c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x169b4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169b50: 0x2451f18c  addiu       $s1, $v0, -0xE74
    ctx->pc = 0x169b50u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963596));
    // 0x169b54: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x169b54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x169b58: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x169b58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169b5c: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x169b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_169b60:
    // 0x169b60: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x169b60u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
    // 0x169b64: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x169B64u;
    {
        const bool branch_taken_0x169b64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x169B68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169B64u;
            // 0x169b68: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x169b64) {
            ctx->pc = 0x169B78u;
            goto label_169b78;
        }
    }
    ctx->pc = 0x169B6Cu;
    // 0x169b6c: 0xc05ce6a  jal         func_1739A8
    ctx->pc = 0x169B6Cu;
    SET_GPR_U32(ctx, 31, 0x169B74u);
    ctx->pc = 0x1739A8u;
    if (runtime->hasFunction(0x1739A8u)) {
        auto targetFn = runtime->lookupFunction(0x1739A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B74u; }
        if (ctx->pc != 0x169B74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001739A8_0x1739a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B74u; }
        if (ctx->pc != 0x169B74u) { return; }
    }
    ctx->pc = 0x169B74u;
label_169b74:
    // 0x169b74: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x169b74u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_169b78:
    // 0x169b78: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x169b78u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x169b7c: 0x603fff8  bgezl       $s0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x169B7Cu;
    {
        const bool branch_taken_0x169b7c = (GPR_S64(ctx, 16) >= 0);
        if (branch_taken_0x169b7c) {
            ctx->pc = 0x169B80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x169B7Cu;
            // 0x169b80: 0x8e220000  lw          $v0, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x169B60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_169b60;
        }
    }
    ctx->pc = 0x169B84u;
    // 0x169b84: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x169b84u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x169b88: 0x2610f138  addiu       $s0, $s0, -0xEC8
    ctx->pc = 0x169b88u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294963512));
    // 0x169b8c: 0xc05d692  jal         func_175A48
    ctx->pc = 0x169B8Cu;
    SET_GPR_U32(ctx, 31, 0x169B94u);
    ctx->pc = 0x169B90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169B8Cu;
            // 0x169b90: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175A48u;
    if (runtime->hasFunction(0x175A48u)) {
        auto targetFn = runtime->lookupFunction(0x175A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B94u; }
        if (ctx->pc != 0x169B94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175A48_0x175a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B94u; }
        if (ctx->pc != 0x169B94u) { return; }
    }
    ctx->pc = 0x169B94u;
label_169b94:
    // 0x169b94: 0xc0599c6  jal         func_166718
    ctx->pc = 0x169B94u;
    SET_GPR_U32(ctx, 31, 0x169B9Cu);
    ctx->pc = 0x169B98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169B94u;
            // 0x169b98: 0x2604000c  addiu       $a0, $s0, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166718u;
    if (runtime->hasFunction(0x166718u)) {
        auto targetFn = runtime->lookupFunction(0x166718u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B9Cu; }
        if (ctx->pc != 0x169B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166718_0x166718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169B9Cu; }
        if (ctx->pc != 0x169B9Cu) { return; }
    }
    ctx->pc = 0x169B9Cu;
label_169b9c:
    // 0x169b9c: 0xc05dd52  jal         func_177548
    ctx->pc = 0x169B9Cu;
    SET_GPR_U32(ctx, 31, 0x169BA4u);
    ctx->pc = 0x169BA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169B9Cu;
            // 0x169ba0: 0x26040010  addiu       $a0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177548u;
    if (runtime->hasFunction(0x177548u)) {
        auto targetFn = runtime->lookupFunction(0x177548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BA4u; }
        if (ctx->pc != 0x169BA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177548_0x177548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BA4u; }
        if (ctx->pc != 0x169BA4u) { return; }
    }
    ctx->pc = 0x169BA4u;
label_169ba4:
    // 0x169ba4: 0xc05a7b0  jal         func_169EC0
    ctx->pc = 0x169BA4u;
    SET_GPR_U32(ctx, 31, 0x169BACu);
    ctx->pc = 0x169BA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x169BA4u;
            // 0x169ba8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EC0u;
    if (runtime->hasFunction(0x169EC0u)) {
        auto targetFn = runtime->lookupFunction(0x169EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BACu; }
        if (ctx->pc != 0x169BACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC0_0x169ec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BACu; }
        if (ctx->pc != 0x169BACu) { return; }
    }
    ctx->pc = 0x169BACu;
label_169bac:
    // 0x169bac: 0xc05a7a8  jal         func_169EA0
    ctx->pc = 0x169BACu;
    SET_GPR_U32(ctx, 31, 0x169BB4u);
    ctx->pc = 0x169EA0u;
    if (runtime->hasFunction(0x169EA0u)) {
        auto targetFn = runtime->lookupFunction(0x169EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BB4u; }
        if (ctx->pc != 0x169BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EA0_0x169ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BB4u; }
        if (ctx->pc != 0x169BB4u) { return; }
    }
    ctx->pc = 0x169BB4u;
label_169bb4:
    // 0x169bb4: 0xc05a79a  jal         func_169E68
    ctx->pc = 0x169BB4u;
    SET_GPR_U32(ctx, 31, 0x169BBCu);
    ctx->pc = 0x169E68u;
    if (runtime->hasFunction(0x169E68u)) {
        auto targetFn = runtime->lookupFunction(0x169E68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BBCu; }
        if (ctx->pc != 0x169BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E68_0x169e68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169BBCu; }
        if (ctx->pc != 0x169BBCu) { return; }
    }
    ctx->pc = 0x169BBCu;
label_169bbc:
    // 0x169bbc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x169bbcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169bc0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x169bc0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x169bc4: 0x250100a  movz        $v0, $s2, $s0
    ctx->pc = 0x169bc4u;
    if (GPR_U64(ctx, 16) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 18));
    // 0x169bc8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x169bc8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169bcc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x169bccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x169bd0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x169bd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x169bd4: 0x3e00008  jr          $ra
    ctx->pc = 0x169BD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x169BD4u;
            // 0x169bd8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169B60u: goto label_169b60;
            case 0x169B74u: goto label_169b74;
            case 0x169B78u: goto label_169b78;
            case 0x169B94u: goto label_169b94;
            case 0x169B9Cu: goto label_169b9c;
            case 0x169BA4u: goto label_169ba4;
            case 0x169BACu: goto label_169bac;
            case 0x169BB4u: goto label_169bb4;
            case 0x169BBCu: goto label_169bbc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169BDCu;
    // 0x169bdc: 0x0  nop
    ctx->pc = 0x169bdcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
