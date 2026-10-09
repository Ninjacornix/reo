#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F6B10
// Address: 0x1f6b10 - 0x1f6f50
void sub_001F6B10_0x1f6b10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F6B10_0x1f6b10");
#endif

    switch (ctx->pc) {
        case 0x1f6b50u: goto label_1f6b50;
        case 0x1f6b58u: goto label_1f6b58;
        case 0x1f6b9cu: goto label_1f6b9c;
        case 0x1f6bb4u: goto label_1f6bb4;
        case 0x1f6bbcu: goto label_1f6bbc;
        case 0x1f6c14u: goto label_1f6c14;
        case 0x1f6c1cu: goto label_1f6c1c;
        case 0x1f6c58u: goto label_1f6c58;
        case 0x1f6cbcu: goto label_1f6cbc;
        case 0x1f6cf4u: goto label_1f6cf4;
        case 0x1f6d58u: goto label_1f6d58;
        case 0x1f6e1cu: goto label_1f6e1c;
        case 0x1f6e3cu: goto label_1f6e3c;
        case 0x1f6e4cu: goto label_1f6e4c;
        case 0x1f6e5cu: goto label_1f6e5c;
        case 0x1f6e84u: goto label_1f6e84;
        case 0x1f6ea8u: goto label_1f6ea8;
        case 0x1f6eccu: goto label_1f6ecc;
        case 0x1f6ee8u: goto label_1f6ee8;
        case 0x1f6f00u: goto label_1f6f00;
        default: break;
    }

    ctx->pc = 0x1f6b10u;

    // 0x1f6b10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f6b10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f6b14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1f6b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1f6b18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1f6b18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1f6b1c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f6b1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f6b20: 0x84820004  lh          $v0, 0x4($a0)
    ctx->pc = 0x1f6b20u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1f6b24: 0x8c900024  lw          $s0, 0x24($a0)
    ctx->pc = 0x1f6b24u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f6b28: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1f6b28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1f6b2c: 0xa4820004  sh          $v0, 0x4($a0)
    ctx->pc = 0x1f6b2cu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f6b30: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1f6b30u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1f6b34: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1f6b34u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1f6b38: 0x1c400014  bgtz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6B38u;
    {
        const bool branch_taken_0x1f6b38 = (GPR_S64(ctx, 2) > 0);
        ctx->pc = 0x1F6B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B38u;
            // 0x1f6b3c: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6b38) {
            ctx->pc = 0x1F6B8Cu;
            goto label_1f6b8c;
        }
    }
    ctx->pc = 0x1F6B40u;
    // 0x1f6b40: 0x24020009  addiu       $v0, $zero, 0x9
    ctx->pc = 0x1f6b40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1f6b44: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6b44u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6b48: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6B48u;
    SET_GPR_U32(ctx, 31, 0x1F6B50u);
    ctx->pc = 0x1F6B4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B48u;
            // 0x1f6b4c: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B50u; }
        if (ctx->pc != 0x1F6B50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B50u; }
        if (ctx->pc != 0x1F6B50u) { return; }
    }
    ctx->pc = 0x1F6B50u;
label_1f6b50:
    // 0x1f6b50: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6B50u;
    SET_GPR_U32(ctx, 31, 0x1F6B58u);
    ctx->pc = 0x1F6B54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B50u;
            // 0x1f6b54: 0x26240010  addiu       $a0, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B58u; }
        if (ctx->pc != 0x1F6B58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B58u; }
        if (ctx->pc != 0x1F6B58u) { return; }
    }
    ctx->pc = 0x1F6B58u;
label_1f6b58:
    // 0x1f6b58: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1f6b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1f6b5c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f6b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6b60: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6b60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6b64: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f6b64u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6b68: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6b68u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6b6c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6b6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6b70: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6b70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6b74: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6b74u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6b78: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6b78u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6b7c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6b7cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6b80: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6b80u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6b84: 0x100000ed  b           . + 4 + (0xED << 2)
    ctx->pc = 0x1F6B84u;
    {
        const bool branch_taken_0x1f6b84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6B88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B84u;
            // 0x1f6b88: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6b84) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6B8Cu;
label_1f6b8c:
    // 0x1f6b8c: 0x8e240010  lw          $a0, 0x10($s1)
    ctx->pc = 0x1f6b8cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x1f6b90: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1f6b90u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1f6b94: 0xc075a4c  jal         func_1D6930
    ctx->pc = 0x1F6B94u;
    SET_GPR_U32(ctx, 31, 0x1F6B9Cu);
    ctx->pc = 0x1F6B98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6B94u;
            // 0x1f6b98: 0x24a5b6b4  addiu       $a1, $a1, -0x494C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948532));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6930u;
    if (runtime->hasFunction(0x1D6930u)) {
        auto targetFn = runtime->lookupFunction(0x1D6930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B9Cu; }
        if (ctx->pc != 0x1F6B9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6930_0x1d6930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6B9Cu; }
        if (ctx->pc != 0x1F6B9Cu) { return; }
    }
    ctx->pc = 0x1F6B9Cu;
label_1f6b9c:
    // 0x1f6b9c: 0x4410014  bgez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6B9Cu;
    {
        const bool branch_taken_0x1f6b9c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1f6b9c) {
            ctx->pc = 0x1F6BF0u;
            goto label_1f6bf0;
        }
    }
    ctx->pc = 0x1F6BA4u;
    // 0x1f6ba4: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1f6ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1f6ba8: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6ba8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6bac: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6BACu;
    SET_GPR_U32(ctx, 31, 0x1F6BB4u);
    ctx->pc = 0x1F6BB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BACu;
            // 0x1f6bb0: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BB4u; }
        if (ctx->pc != 0x1F6BB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BB4u; }
        if (ctx->pc != 0x1F6BB4u) { return; }
    }
    ctx->pc = 0x1F6BB4u;
label_1f6bb4:
    // 0x1f6bb4: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6BB4u;
    SET_GPR_U32(ctx, 31, 0x1F6BBCu);
    ctx->pc = 0x1F6BB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BB4u;
            // 0x1f6bb8: 0x26240010  addiu       $a0, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BBCu; }
        if (ctx->pc != 0x1F6BBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6BBCu; }
        if (ctx->pc != 0x1F6BBCu) { return; }
    }
    ctx->pc = 0x1F6BBCu;
label_1f6bbc:
    // 0x1f6bbc: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1f6bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1f6bc0: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f6bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6bc4: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6bc8: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f6bc8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6bcc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6bccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6bd0: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6bd0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6bd4: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6bd4u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6bd8: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6bd8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6bdc: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6bdcu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6be0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6be0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6be4: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6be4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6be8: 0x100000d4  b           . + 4 + (0xD4 << 2)
    ctx->pc = 0x1F6BE8u;
    {
        const bool branch_taken_0x1f6be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BE8u;
            // 0x1f6bec: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6be8) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6BF0u;
label_1f6bf0:
    // 0x1f6bf0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1f6bf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1f6bf4: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f6bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f6bf8: 0x8423b6b4  lh          $v1, -0x494C($at)
    ctx->pc = 0x1f6bf8u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948532)));
    // 0x1f6bfc: 0x10620014  beq         $v1, $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6BFCu;
    {
        const bool branch_taken_0x1f6bfc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6C00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6BFCu;
            // 0x1f6c00: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6bfc) {
            ctx->pc = 0x1F6C50u;
            goto label_1f6c50;
        }
    }
    ctx->pc = 0x1F6C04u;
    // 0x1f6c04: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x1f6c04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1f6c08: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6c08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6c0c: 0xc075ad4  jal         func_1D6B50
    ctx->pc = 0x1F6C0Cu;
    SET_GPR_U32(ctx, 31, 0x1F6C14u);
    ctx->pc = 0x1F6C10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C0Cu;
            // 0x1f6c10: 0x8e240010  lw          $a0, 0x10($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B50u;
    if (runtime->hasFunction(0x1D6B50u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C14u; }
        if (ctx->pc != 0x1F6C14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B50_0x1d6b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C14u; }
        if (ctx->pc != 0x1F6C14u) { return; }
    }
    ctx->pc = 0x1F6C14u;
label_1f6c14:
    // 0x1f6c14: 0xc075ae0  jal         func_1D6B80
    ctx->pc = 0x1F6C14u;
    SET_GPR_U32(ctx, 31, 0x1F6C1Cu);
    ctx->pc = 0x1F6C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C14u;
            // 0x1f6c18: 0x26240010  addiu       $a0, $s1, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6B80u;
    if (runtime->hasFunction(0x1D6B80u)) {
        auto targetFn = runtime->lookupFunction(0x1D6B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C1Cu; }
        if (ctx->pc != 0x1F6C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6B80_0x1d6b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C1Cu; }
        if (ctx->pc != 0x1F6C1Cu) { return; }
    }
    ctx->pc = 0x1F6C1Cu;
label_1f6c1c:
    // 0x1f6c1c: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1f6c1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6c20: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6c20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6c24: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f6c24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f6c28: 0xa2230000  sb          $v1, 0x0($s1)
    ctx->pc = 0x1f6c28u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f6c2c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6c2cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c30: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6c30u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c34: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6c34u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c38: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6c38u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6c3c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6c3cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6c40: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6c40u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6c44: 0x100000bd  b           . + 4 + (0xBD << 2)
    ctx->pc = 0x1F6C44u;
    {
        const bool branch_taken_0x1f6c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C44u;
            // 0x1f6c48: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6c44) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6C4Cu;
    // 0x1f6c4c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6c4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1f6c50:
    // 0x1f6c50: 0xc07d180  jal         func_1F4600
    ctx->pc = 0x1F6C50u;
    SET_GPR_U32(ctx, 31, 0x1F6C58u);
    ctx->pc = 0x1F4600u;
    if (runtime->hasFunction(0x1F4600u)) {
        auto targetFn = runtime->lookupFunction(0x1F4600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C58u; }
        if (ctx->pc != 0x1F6C58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4600_0x1f4600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6C58u; }
        if (ctx->pc != 0x1F6C58u) { return; }
    }
    ctx->pc = 0x1F6C58u;
label_1f6c58:
    // 0x1f6c58: 0x10400014  beqz        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6C58u;
    {
        const bool branch_taken_0x1f6c58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6c58) {
            ctx->pc = 0x1F6CACu;
            goto label_1f6cac;
        }
    }
    ctx->pc = 0x1F6C60u;
    // 0x1f6c60: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1f6c60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1f6c64: 0x10430004  beq         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F6C64u;
    {
        const bool branch_taken_0x1f6c64 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1f6c64) {
            ctx->pc = 0x1F6C78u;
            goto label_1f6c78;
        }
    }
    ctx->pc = 0x1F6C6Cu;
    // 0x1f6c6c: 0x24020708  addiu       $v0, $zero, 0x708
    ctx->pc = 0x1f6c6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1800));
    // 0x1f6c70: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1F6C70u;
    {
        const bool branch_taken_0x1f6c70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6C74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6C70u;
            // 0x1f6c74: 0xa6220004  sh          $v0, 0x4($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6c70) {
            ctx->pc = 0x1F6CB4u;
            goto label_1f6cb4;
        }
    }
    ctx->pc = 0x1F6C78u;
label_1f6c78:
    // 0x1f6c78: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1f6c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1f6c7c: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1f6c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1f6c80: 0xae220090  sw          $v0, 0x90($s1)
    ctx->pc = 0x1f6c80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
    // 0x1f6c84: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6c84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6c88: 0xae23008c  sw          $v1, 0x8C($s1)
    ctx->pc = 0x1f6c88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 3));
    // 0x1f6c8c: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6c8cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6c90: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6c90u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c94: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6c94u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c98: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6c98u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6c9c: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6c9cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ca0: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6ca0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ca4: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6ca4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6ca8: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f6ca8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6cac:
    // 0x1f6cac: 0x100000a3  b           . + 4 + (0xA3 << 2)
    ctx->pc = 0x1F6CACu;
    {
        const bool branch_taken_0x1f6cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6CACu;
            // 0x1f6cb0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6cac) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6CB4u;
label_1f6cb4:
    // 0x1f6cb4: 0xc07d170  jal         func_1F45C0
    ctx->pc = 0x1F6CB4u;
    SET_GPR_U32(ctx, 31, 0x1F6CBCu);
    ctx->pc = 0x1F6CB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6CB4u;
            // 0x1f6cb8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F45C0u;
    if (runtime->hasFunction(0x1F45C0u)) {
        auto targetFn = runtime->lookupFunction(0x1F45C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6CBCu; }
        if (ctx->pc != 0x1F6CBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F45C0_0x1f45c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6CBCu; }
        if (ctx->pc != 0x1F6CBCu) { return; }
    }
    ctx->pc = 0x1F6CBCu;
label_1f6cbc:
    // 0x1f6cbc: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x1f6cbcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cc0: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x1f6cc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cc4: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x1f6cc4u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cc8: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x1f6cc8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x1f6ccc: 0x3c0a0023  lui         $t2, 0x23
    ctx->pc = 0x1f6cccu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)35 << 16));
    // 0x1f6cd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6cd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6cd4: 0x248473b0  addiu       $a0, $a0, 0x73B0
    ctx->pc = 0x1f6cd4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 29616));
    // 0x1f6cd8: 0x24c67350  addiu       $a2, $a2, 0x7350
    ctx->pc = 0x1f6cd8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 29520));
    // 0x1f6cdc: 0x24e77330  addiu       $a3, $a3, 0x7330
    ctx->pc = 0x1f6cdcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 29488));
    // 0x1f6ce0: 0x25087390  addiu       $t0, $t0, 0x7390
    ctx->pc = 0x1f6ce0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 29584));
    // 0x1f6ce4: 0x254a7370  addiu       $t2, $t2, 0x7370
    ctx->pc = 0x1f6ce4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 29552));
    // 0x1f6ce8: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1F6CE8u;
    {
        const bool branch_taken_0x1f6ce8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6CECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6CE8u;
            // 0x1f6cec: 0x24090008  addiu       $t1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ce8) {
            ctx->pc = 0x1F6DC4u;
            goto label_1f6dc4;
        }
    }
    ctx->pc = 0x1F6CF0u;
    // 0x1f6cf0: 0x1421821  addu        $v1, $t2, $v0
    ctx->pc = 0x1f6cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
label_1f6cf4:
    // 0x1f6cf4: 0x90630000  lbu         $v1, 0x0($v1)
    ctx->pc = 0x1f6cf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f6cf8: 0x10690031  beq         $v1, $t1, . + 4 + (0x31 << 2)
    ctx->pc = 0x1F6CF8u;
    {
        const bool branch_taken_0x1f6cf8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 9));
        if (branch_taken_0x1f6cf8) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D00u;
    // 0x1f6d00: 0x1022821  addu        $a1, $t0, $v0
    ctx->pc = 0x1f6d00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x1f6d04: 0x92030002  lbu         $v1, 0x2($s0)
    ctx->pc = 0x1f6d04u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1f6d08: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1f6d08u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1f6d0c: 0x14a3002c  bne         $a1, $v1, . + 4 + (0x2C << 2)
    ctx->pc = 0x1F6D0Cu;
    {
        const bool branch_taken_0x1f6d0c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d0c) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D14u;
    // 0x1f6d14: 0xe22821  addu        $a1, $a3, $v0
    ctx->pc = 0x1f6d14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1f6d18: 0x92030003  lbu         $v1, 0x3($s0)
    ctx->pc = 0x1f6d18u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1f6d1c: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1f6d1cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1f6d20: 0x14a30027  bne         $a1, $v1, . + 4 + (0x27 << 2)
    ctx->pc = 0x1F6D20u;
    {
        const bool branch_taken_0x1f6d20 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d20) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D28u;
    // 0x1f6d28: 0xc22821  addu        $a1, $a2, $v0
    ctx->pc = 0x1f6d28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1f6d2c: 0x92030004  lbu         $v1, 0x4($s0)
    ctx->pc = 0x1f6d2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1f6d30: 0x90a50000  lbu         $a1, 0x0($a1)
    ctx->pc = 0x1f6d30u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1f6d34: 0x14a30022  bne         $a1, $v1, . + 4 + (0x22 << 2)
    ctx->pc = 0x1F6D34u;
    {
        const bool branch_taken_0x1f6d34 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d34) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D3Cu;
    // 0x1f6d3c: 0x21880  sll         $v1, $v0, 2
    ctx->pc = 0x1f6d3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1f6d40: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1f6d40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1f6d44: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1f6d44u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f6d48: 0x1060001d  beqz        $v1, . + 4 + (0x1D << 2)
    ctx->pc = 0x1F6D48u;
    {
        const bool branch_taken_0x1f6d48 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6d48) {
            ctx->pc = 0x1F6DC0u;
            goto label_1f6dc0;
        }
    }
    ctx->pc = 0x1F6D50u;
    // 0x1f6d50: 0x60f809  jalr        $v1
    ctx->pc = 0x1F6D50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1F6D58u);
        ctx->pc = 0x1F6D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6D50u;
            // 0x1f6d54: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1F6D58u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1F6D58u; }
            if (ctx->pc != 0x1F6D58u) { return; }
        }
        }
    }
    ctx->pc = 0x1F6D58u;
label_1f6d58:
    // 0x1f6d58: 0x441000e  bgez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1F6D58u;
    {
        const bool branch_taken_0x1f6d58 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1F6D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6D58u;
            // 0x1f6d5c: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6d58) {
            ctx->pc = 0x1F6D94u;
            goto label_1f6d94;
        }
    }
    ctx->pc = 0x1F6D60u;
    // 0x1f6d60: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6d60u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6d64: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6d64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6d68: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6d68u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6d6c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6d6cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6d70: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6d70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6d74: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6d74u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6d78: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6d78u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6d7c: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6d7cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6d80: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6d80u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6d84: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6d84u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6d88: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1F6D88u;
    {
        const bool branch_taken_0x1f6d88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6D8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6D88u;
            // 0x1f6d8c: 0xa620000a  sh          $zero, 0xA($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6d88) {
            ctx->pc = 0x1F6F3Cu;
            goto label_1f6f3c;
        }
    }
    ctx->pc = 0x1F6D90u;
    // 0x1f6d90: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1f6d90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1f6d94:
    // 0x1f6d94: 0x1443000e  bne         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1F6D94u;
    {
        const bool branch_taken_0x1f6d94 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1f6d94) {
            ctx->pc = 0x1F6DD0u;
            goto label_1f6dd0;
        }
    }
    ctx->pc = 0x1F6D9Cu;
    // 0x1f6d9c: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x1f6d9cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1f6da0: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6da0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6da4: 0x10620004  beq         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1F6DA4u;
    {
        const bool branch_taken_0x1f6da4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1F6DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DA4u;
            // 0x1f6da8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6da4) {
            ctx->pc = 0x1F6DB8u;
            goto label_1f6db8;
        }
    }
    ctx->pc = 0x1F6DACu;
    // 0x1f6dac: 0x24620001  addiu       $v0, $v1, 0x1
    ctx->pc = 0x1f6dacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1f6db0: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6db0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6db4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6db4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6db8:
    // 0x1f6db8: 0x10000061  b           . + 4 + (0x61 << 2)
    ctx->pc = 0x1F6DB8u;
    {
        const bool branch_taken_0x1f6db8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6DBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DB8u;
            // 0x1f6dbc: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6db8) {
            ctx->pc = 0x1F6F40u;
            goto label_1f6f40;
        }
    }
    ctx->pc = 0x1F6DC0u;
label_1f6dc0:
    // 0x1f6dc0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f6dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1f6dc4:
    // 0x1f6dc4: 0x2843001c  slti        $v1, $v0, 0x1C
    ctx->pc = 0x1f6dc4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)28) ? 1 : 0);
    // 0x1f6dc8: 0x1460ffca  bnez        $v1, . + 4 + (-0x36 << 2)
    ctx->pc = 0x1F6DC8u;
    {
        const bool branch_taken_0x1f6dc8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F6DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DC8u;
            // 0x1f6dcc: 0x1421821  addu        $v1, $t2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6dc8) {
            ctx->pc = 0x1F6CF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f6cf4;
        }
    }
    ctx->pc = 0x1F6DD0u;
label_1f6dd0:
    // 0x1f6dd0: 0x82230001  lb          $v1, 0x1($s1)
    ctx->pc = 0x1f6dd0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 1)));
    // 0x1f6dd4: 0x2c610015  sltiu       $at, $v1, 0x15
    ctx->pc = 0x1f6dd4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)21) ? 1 : 0);
    // 0x1f6dd8: 0x1020004b  beqz        $at, . + 4 + (0x4B << 2)
    ctx->pc = 0x1F6DD8u;
    {
        const bool branch_taken_0x1f6dd8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6DDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6DD8u;
            // 0x1f6ddc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6dd8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6DE0u;
    // 0x1f6de0: 0x3c040026  lui         $a0, 0x26
    ctx->pc = 0x1f6de0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)38 << 16));
    // 0x1f6de4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1f6de4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1f6de8: 0x24849ba0  addiu       $a0, $a0, -0x6460
    ctx->pc = 0x1f6de8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941600));
    // 0x1f6dec: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1f6decu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1f6df0: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1f6df0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1f6df4: 0x600008  jr          $v1
    ctx->pc = 0x1F6DF4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F08u: goto label_1f6f08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6DFCu;
label_1f6dfc:
    // 0x1f6dfc: 0x24030010  addiu       $v1, $zero, 0x10
    ctx->pc = 0x1f6dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1f6e00: 0x10000041  b           . + 4 + (0x41 << 2)
    ctx->pc = 0x1F6E00u;
    {
        const bool branch_taken_0x1f6e00 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E00u;
            // 0x1f6e04: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e00) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E08u;
label_1f6e08:
    // 0x1f6e08: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x1f6e08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f6e0c: 0x1000003e  b           . + 4 + (0x3E << 2)
    ctx->pc = 0x1F6E0Cu;
    {
        const bool branch_taken_0x1f6e0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E0Cu;
            // 0x1f6e10: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e0c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E14u;
label_1f6e14:
    // 0x1f6e14: 0xc07d47c  jal         func_1F51F0
    ctx->pc = 0x1F6E14u;
    SET_GPR_U32(ctx, 31, 0x1F6E1Cu);
    ctx->pc = 0x1F6E18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E14u;
            // 0x1f6e18: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F51F0u;
    if (runtime->hasFunction(0x1F51F0u)) {
        auto targetFn = runtime->lookupFunction(0x1F51F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E1Cu; }
        if (ctx->pc != 0x1F6E1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F51F0_0x1f51f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E1Cu; }
        if (ctx->pc != 0x1F6E1Cu) { return; }
    }
    ctx->pc = 0x1F6E1Cu;
label_1f6e1c:
    // 0x1f6e1c: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x1f6e1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1f6e20: 0x10000039  b           . + 4 + (0x39 << 2)
    ctx->pc = 0x1F6E20u;
    {
        const bool branch_taken_0x1f6e20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E20u;
            // 0x1f6e24: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e20) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E28u;
label_1f6e28:
    // 0x1f6e28: 0x2403001e  addiu       $v1, $zero, 0x1E
    ctx->pc = 0x1f6e28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1f6e2c: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1F6E2Cu;
    {
        const bool branch_taken_0x1f6e2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E2Cu;
            // 0x1f6e30: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e2c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E34u;
label_1f6e34:
    // 0x1f6e34: 0xc07d514  jal         func_1F5450
    ctx->pc = 0x1F6E34u;
    SET_GPR_U32(ctx, 31, 0x1F6E3Cu);
    ctx->pc = 0x1F6E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E34u;
            // 0x1f6e38: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5450u;
    if (runtime->hasFunction(0x1F5450u)) {
        auto targetFn = runtime->lookupFunction(0x1F5450u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E3Cu; }
        if (ctx->pc != 0x1F6E3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5450_0x1f5450(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E3Cu; }
        if (ctx->pc != 0x1F6E3Cu) { return; }
    }
    ctx->pc = 0x1F6E3Cu;
label_1f6e3c:
    // 0x1f6e3c: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x1F6E3Cu;
    {
        const bool branch_taken_0x1f6e3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6e3c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E44u;
label_1f6e44:
    // 0x1f6e44: 0xc07d580  jal         func_1F5600
    ctx->pc = 0x1F6E44u;
    SET_GPR_U32(ctx, 31, 0x1F6E4Cu);
    ctx->pc = 0x1F6E48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E44u;
            // 0x1f6e48: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5600u;
    if (runtime->hasFunction(0x1F5600u)) {
        auto targetFn = runtime->lookupFunction(0x1F5600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E4Cu; }
        if (ctx->pc != 0x1F6E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5600_0x1f5600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E4Cu; }
        if (ctx->pc != 0x1F6E4Cu) { return; }
    }
    ctx->pc = 0x1F6E4Cu;
label_1f6e4c:
    // 0x1f6e4c: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x1F6E4Cu;
    {
        const bool branch_taken_0x1f6e4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6e4c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E54u;
label_1f6e54:
    // 0x1f6e54: 0xc07d640  jal         func_1F5900
    ctx->pc = 0x1F6E54u;
    SET_GPR_U32(ctx, 31, 0x1F6E5Cu);
    ctx->pc = 0x1F6E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E54u;
            // 0x1f6e58: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5900u;
    if (runtime->hasFunction(0x1F5900u)) {
        auto targetFn = runtime->lookupFunction(0x1F5900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E5Cu; }
        if (ctx->pc != 0x1F6E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5900_0x1f5900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E5Cu; }
        if (ctx->pc != 0x1F6E5Cu) { return; }
    }
    ctx->pc = 0x1F6E5Cu;
label_1f6e5c:
    // 0x1f6e5c: 0x24030037  addiu       $v1, $zero, 0x37
    ctx->pc = 0x1f6e5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 55));
    // 0x1f6e60: 0x10000029  b           . + 4 + (0x29 << 2)
    ctx->pc = 0x1F6E60u;
    {
        const bool branch_taken_0x1f6e60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E60u;
            // 0x1f6e64: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e60) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E68u;
label_1f6e68:
    // 0x1f6e68: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1f6e68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1f6e6c: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1F6E6Cu;
    {
        const bool branch_taken_0x1f6e6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E6Cu;
            // 0x1f6e70: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e6c) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E74u;
label_1f6e74:
    // 0x1f6e74: 0x24020046  addiu       $v0, $zero, 0x46
    ctx->pc = 0x1f6e74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1f6e78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6e78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6e7c: 0xc07d6d4  jal         func_1F5B50
    ctx->pc = 0x1F6E7Cu;
    SET_GPR_U32(ctx, 31, 0x1F6E84u);
    ctx->pc = 0x1F6E80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E7Cu;
            // 0x1f6e80: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5B50u;
    if (runtime->hasFunction(0x1F5B50u)) {
        auto targetFn = runtime->lookupFunction(0x1F5B50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E84u; }
        if (ctx->pc != 0x1F6E84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5B50_0x1f5b50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6E84u; }
        if (ctx->pc != 0x1F6E84u) { return; }
    }
    ctx->pc = 0x1F6E84u;
label_1f6e84:
    // 0x1f6e84: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1F6E84u;
    {
        const bool branch_taken_0x1f6e84 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6e84) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E8Cu;
label_1f6e8c:
    // 0x1f6e8c: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x1f6e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1f6e90: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1F6E90u;
    {
        const bool branch_taken_0x1f6e90 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6E94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6E90u;
            // 0x1f6e94: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6e90) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6E98u;
label_1f6e98:
    // 0x1f6e98: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x1f6e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x1f6e9c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6e9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6ea0: 0xc07d7dc  jal         func_1F5F70
    ctx->pc = 0x1F6EA0u;
    SET_GPR_U32(ctx, 31, 0x1F6EA8u);
    ctx->pc = 0x1F6EA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EA0u;
            // 0x1f6ea4: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F5F70u;
    if (runtime->hasFunction(0x1F5F70u)) {
        auto targetFn = runtime->lookupFunction(0x1F5F70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6EA8u; }
        if (ctx->pc != 0x1F6EA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F5F70_0x1f5f70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6EA8u; }
        if (ctx->pc != 0x1F6EA8u) { return; }
    }
    ctx->pc = 0x1F6EA8u;
label_1f6ea8:
    // 0x1f6ea8: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1F6EA8u;
    {
        const bool branch_taken_0x1f6ea8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6ea8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EB0u;
label_1f6eb0:
    // 0x1f6eb0: 0x24030028  addiu       $v1, $zero, 0x28
    ctx->pc = 0x1f6eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x1f6eb4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1F6EB4u;
    {
        const bool branch_taken_0x1f6eb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6EB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EB4u;
            // 0x1f6eb8: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6eb4) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EBCu;
label_1f6ebc:
    // 0x1f6ebc: 0x2402002c  addiu       $v0, $zero, 0x2C
    ctx->pc = 0x1f6ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 44));
    // 0x1f6ec0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6ec0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6ec4: 0xc07d8d4  jal         func_1F6350
    ctx->pc = 0x1F6EC4u;
    SET_GPR_U32(ctx, 31, 0x1F6ECCu);
    ctx->pc = 0x1F6EC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EC4u;
            // 0x1f6ec8: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F6350u;
    if (runtime->hasFunction(0x1F6350u)) {
        auto targetFn = runtime->lookupFunction(0x1F6350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6ECCu; }
        if (ctx->pc != 0x1F6ECCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F6350_0x1f6350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6ECCu; }
        if (ctx->pc != 0x1F6ECCu) { return; }
    }
    ctx->pc = 0x1F6ECCu;
label_1f6ecc:
    // 0x1f6ecc: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1F6ECCu;
    {
        const bool branch_taken_0x1f6ecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6ecc) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6ED4u;
label_1f6ed4:
    // 0x1f6ed4: 0x24030032  addiu       $v1, $zero, 0x32
    ctx->pc = 0x1f6ed4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 50));
    // 0x1f6ed8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1F6ED8u;
    {
        const bool branch_taken_0x1f6ed8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F6EDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6ED8u;
            // 0x1f6edc: 0xae230090  sw          $v1, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f6ed8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EE0u;
label_1f6ee0:
    // 0x1f6ee0: 0xc07d974  jal         func_1F65D0
    ctx->pc = 0x1F6EE0u;
    SET_GPR_U32(ctx, 31, 0x1F6EE8u);
    ctx->pc = 0x1F6EE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EE0u;
            // 0x1f6ee4: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F65D0u;
    if (runtime->hasFunction(0x1F65D0u)) {
        auto targetFn = runtime->lookupFunction(0x1F65D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6EE8u; }
        if (ctx->pc != 0x1F6EE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F65D0_0x1f65d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6EE8u; }
        if (ctx->pc != 0x1F6EE8u) { return; }
    }
    ctx->pc = 0x1F6EE8u;
label_1f6ee8:
    // 0x1f6ee8: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1F6EE8u;
    {
        const bool branch_taken_0x1f6ee8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1f6ee8) {
            ctx->pc = 0x1F6F08u;
            goto label_1f6f08;
        }
    }
    ctx->pc = 0x1F6EF0u;
label_1f6ef0:
    // 0x1f6ef0: 0x2402005a  addiu       $v0, $zero, 0x5A
    ctx->pc = 0x1f6ef0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1f6ef4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1f6ef4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f6ef8: 0xc07d3ec  jal         func_1F4FB0
    ctx->pc = 0x1F6EF8u;
    SET_GPR_U32(ctx, 31, 0x1F6F00u);
    ctx->pc = 0x1F6EFCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6EF8u;
            // 0x1f6efc: 0xae220090  sw          $v0, 0x90($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 144), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1F4FB0u;
    if (runtime->hasFunction(0x1F4FB0u)) {
        auto targetFn = runtime->lookupFunction(0x1F4FB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F00u; }
        if (ctx->pc != 0x1F6F00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F4FB0_0x1f4fb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F6F00u; }
        if (ctx->pc != 0x1F6F00u) { return; }
    }
    ctx->pc = 0x1F6F00u;
label_1f6f00:
    // 0x1f6f00: 0x24030014  addiu       $v1, $zero, 0x14
    ctx->pc = 0x1f6f00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
    // 0x1f6f04: 0xa2230001  sb          $v1, 0x1($s1)
    ctx->pc = 0x1f6f04u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 3));
label_1f6f08:
    // 0x1f6f08: 0x441000b  bgez        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1F6F08u;
    {
        const bool branch_taken_0x1f6f08 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1f6f08) {
            ctx->pc = 0x1F6F38u;
            goto label_1f6f38;
        }
    }
    ctx->pc = 0x1F6F10u;
    // 0x1f6f10: 0xae22008c  sw          $v0, 0x8C($s1)
    ctx->pc = 0x1f6f10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 140), GPR_U32(ctx, 2));
    // 0x1f6f14: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1f6f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1f6f18: 0xa2220000  sb          $v0, 0x0($s1)
    ctx->pc = 0x1f6f18u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f6f1c: 0xa2200001  sb          $zero, 0x1($s1)
    ctx->pc = 0x1f6f1cu;
    WRITE8(ADD32(GPR_U32(ctx, 17), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f20: 0xa2200002  sb          $zero, 0x2($s1)
    ctx->pc = 0x1f6f20u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f24: 0xa2200003  sb          $zero, 0x3($s1)
    ctx->pc = 0x1f6f24u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 3), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f6f28: 0xa6200004  sh          $zero, 0x4($s1)
    ctx->pc = 0x1f6f28u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f2c: 0xa6200006  sh          $zero, 0x6($s1)
    ctx->pc = 0x1f6f2cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 6), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f30: 0xa6200008  sh          $zero, 0x8($s1)
    ctx->pc = 0x1f6f30u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 8), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f6f34: 0xa620000a  sh          $zero, 0xA($s1)
    ctx->pc = 0x1f6f34u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 10), (uint16_t)GPR_U32(ctx, 0));
label_1f6f38:
    // 0x1f6f38: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f6f38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f6f3c:
    // 0x1f6f3c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1f6f3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1f6f40:
    // 0x1f6f40: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1f6f40u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f6f44: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f6f44u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f6f48: 0x3e00008  jr          $ra
    ctx->pc = 0x1F6F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F6F4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F6F48u;
            // 0x1f6f4c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F6B50u: goto label_1f6b50;
            case 0x1F6B58u: goto label_1f6b58;
            case 0x1F6B8Cu: goto label_1f6b8c;
            case 0x1F6B9Cu: goto label_1f6b9c;
            case 0x1F6BB4u: goto label_1f6bb4;
            case 0x1F6BBCu: goto label_1f6bbc;
            case 0x1F6BF0u: goto label_1f6bf0;
            case 0x1F6C14u: goto label_1f6c14;
            case 0x1F6C1Cu: goto label_1f6c1c;
            case 0x1F6C50u: goto label_1f6c50;
            case 0x1F6C58u: goto label_1f6c58;
            case 0x1F6C78u: goto label_1f6c78;
            case 0x1F6CACu: goto label_1f6cac;
            case 0x1F6CB4u: goto label_1f6cb4;
            case 0x1F6CBCu: goto label_1f6cbc;
            case 0x1F6CF4u: goto label_1f6cf4;
            case 0x1F6D58u: goto label_1f6d58;
            case 0x1F6D94u: goto label_1f6d94;
            case 0x1F6DB8u: goto label_1f6db8;
            case 0x1F6DC0u: goto label_1f6dc0;
            case 0x1F6DC4u: goto label_1f6dc4;
            case 0x1F6DD0u: goto label_1f6dd0;
            case 0x1F6DFCu: goto label_1f6dfc;
            case 0x1F6E08u: goto label_1f6e08;
            case 0x1F6E14u: goto label_1f6e14;
            case 0x1F6E1Cu: goto label_1f6e1c;
            case 0x1F6E28u: goto label_1f6e28;
            case 0x1F6E34u: goto label_1f6e34;
            case 0x1F6E3Cu: goto label_1f6e3c;
            case 0x1F6E44u: goto label_1f6e44;
            case 0x1F6E4Cu: goto label_1f6e4c;
            case 0x1F6E54u: goto label_1f6e54;
            case 0x1F6E5Cu: goto label_1f6e5c;
            case 0x1F6E68u: goto label_1f6e68;
            case 0x1F6E74u: goto label_1f6e74;
            case 0x1F6E84u: goto label_1f6e84;
            case 0x1F6E8Cu: goto label_1f6e8c;
            case 0x1F6E98u: goto label_1f6e98;
            case 0x1F6EA8u: goto label_1f6ea8;
            case 0x1F6EB0u: goto label_1f6eb0;
            case 0x1F6EBCu: goto label_1f6ebc;
            case 0x1F6ECCu: goto label_1f6ecc;
            case 0x1F6ED4u: goto label_1f6ed4;
            case 0x1F6EE0u: goto label_1f6ee0;
            case 0x1F6EE8u: goto label_1f6ee8;
            case 0x1F6EF0u: goto label_1f6ef0;
            case 0x1F6F00u: goto label_1f6f00;
            case 0x1F6F08u: goto label_1f6f08;
            case 0x1F6F38u: goto label_1f6f38;
            case 0x1F6F3Cu: goto label_1f6f3c;
            case 0x1F6F40u: goto label_1f6f40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F6F50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
