#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C8C30
// Address: 0x1c8c30 - 0x1c8d60
void sub_001C8C30_0x1c8c30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C8C30_0x1c8c30");
#endif

    switch (ctx->pc) {
        case 0x1c8c70u: goto label_1c8c70;
        case 0x1c8c90u: goto label_1c8c90;
        case 0x1c8cc0u: goto label_1c8cc0;
        case 0x1c8ce8u: goto label_1c8ce8;
        case 0x1c8d14u: goto label_1c8d14;
        case 0x1c8d24u: goto label_1c8d24;
        default: break;
    }

    ctx->pc = 0x1c8c30u;

    // 0x1c8c30: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1c8c30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1c8c34: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8c34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8c38: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1c8c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1c8c3c: 0x8022b650  lb          $v0, -0x49B0($at)
    ctx->pc = 0x1c8c3cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294948432)));
    // 0x1c8c40: 0x2c410006  sltiu       $at, $v0, 0x6
    ctx->pc = 0x1c8c40u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)6) ? 1 : 0);
    // 0x1c8c44: 0x1020003a  beqz        $at, . + 4 + (0x3A << 2)
    ctx->pc = 0x1C8C44u;
    {
        const bool branch_taken_0x1c8c44 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8c44) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8C4Cu;
    // 0x1c8c4c: 0x3c030025  lui         $v1, 0x25
    ctx->pc = 0x1c8c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
    // 0x1c8c50: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c8c50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c8c54: 0x24632de0  addiu       $v1, $v1, 0x2DE0
    ctx->pc = 0x1c8c54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11744));
    // 0x1c8c58: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c8c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c8c5c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c8c5cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c8c60: 0x400008  jr          $v0
    ctx->pc = 0x1C8C60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8C68u: goto label_1c8c68;
            case 0x1C8C88u: goto label_1c8c88;
            case 0x1C8CE0u: goto label_1c8ce0;
            case 0x1C8D00u: goto label_1c8d00;
            case 0x1C8D30u: goto label_1c8d30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8C68u;
label_1c8c68:
    // 0x1c8c68: 0xc0723ac  jal         func_1C8EB0
    ctx->pc = 0x1C8C68u;
    SET_GPR_U32(ctx, 31, 0x1C8C70u);
    ctx->pc = 0x1C8EB0u;
    if (runtime->hasFunction(0x1C8EB0u)) {
        auto targetFn = runtime->lookupFunction(0x1C8EB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8C70u; }
        if (ctx->pc != 0x1C8C70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8EB0_0x1c8eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8C70u; }
        if (ctx->pc != 0x1C8C70u) { return; }
    }
    ctx->pc = 0x1C8C70u;
label_1c8c70:
    // 0x1c8c70: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8c70u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8c74: 0x8022b650  lb          $v0, -0x49B0($at)
    ctx->pc = 0x1c8c74u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294948432)));
    // 0x1c8c78: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c8c78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c8c7c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8c7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8c80: 0x1000002b  b           . + 4 + (0x2B << 2)
    ctx->pc = 0x1C8C80u;
    {
        const bool branch_taken_0x1c8c80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8C84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8C80u;
            // 0x1c8c84: 0xa022b650  sb          $v0, -0x49B0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294948432), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8c80) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8C88u;
label_1c8c88:
    // 0x1c8c88: 0xc072410  jal         func_1C9040
    ctx->pc = 0x1C8C88u;
    SET_GPR_U32(ctx, 31, 0x1C8C90u);
    ctx->pc = 0x1C9040u;
    if (runtime->hasFunction(0x1C9040u)) {
        auto targetFn = runtime->lookupFunction(0x1C9040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8C90u; }
        if (ctx->pc != 0x1C8C90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9040_0x1c9040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8C90u; }
        if (ctx->pc != 0x1C8C90u) { return; }
    }
    ctx->pc = 0x1C8C90u;
label_1c8c90:
    // 0x1c8c90: 0x10400027  beqz        $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x1C8C90u;
    {
        const bool branch_taken_0x1c8c90 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8c90) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8C98u;
    // 0x1c8c98: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1c8c98u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c8c9c: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1C8C9Cu;
    {
        const bool branch_taken_0x1c8c9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C8CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8C9Cu;
            // 0x1c8ca0: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8c9c) {
            ctx->pc = 0x1C8CD8u;
            goto label_1c8cd8;
        }
    }
    ctx->pc = 0x1C8CA4u;
    // 0x1c8ca4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c8ca4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c8ca8: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C8CA8u;
    {
        const bool branch_taken_0x1c8ca8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C8CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8CA8u;
            // 0x1c8cac: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8ca8) {
            ctx->pc = 0x1C8CB8u;
            goto label_1c8cb8;
        }
    }
    ctx->pc = 0x1C8CB0u;
    // 0x1c8cb0: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1C8CB0u;
    {
        const bool branch_taken_0x1c8cb0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8cb0) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8CB8u;
label_1c8cb8:
    // 0x1c8cb8: 0xc072304  jal         func_1C8C10
    ctx->pc = 0x1C8CB8u;
    SET_GPR_U32(ctx, 31, 0x1C8CC0u);
    ctx->pc = 0x1C8CBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8CB8u;
            // 0x1c8cbc: 0x8c24c810  lw          $a0, -0x37F0($at) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952976)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8C10u;
    if (runtime->hasFunction(0x1C8C10u)) {
        auto targetFn = runtime->lookupFunction(0x1C8C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8CC0u; }
        if (ctx->pc != 0x1C8CC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8C10_0x1c8c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8CC0u; }
        if (ctx->pc != 0x1C8CC0u) { return; }
    }
    ctx->pc = 0x1C8CC0u;
label_1c8cc0:
    // 0x1c8cc0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8cc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8cc4: 0x8022b650  lb          $v0, -0x49B0($at)
    ctx->pc = 0x1c8cc4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294948432)));
    // 0x1c8cc8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1c8cc8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1c8ccc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8cccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8cd0: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1C8CD0u;
    {
        const bool branch_taken_0x1c8cd0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8CD0u;
            // 0x1c8cd4: 0xa022b650  sb          $v0, -0x49B0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294948432), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8cd0) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8CD8u;
label_1c8cd8:
    // 0x1c8cd8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1C8CD8u;
    {
        const bool branch_taken_0x1c8cd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8CDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8CD8u;
            // 0x1c8cdc: 0xa023b650  sb          $v1, -0x49B0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294948432), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8cd8) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8CE0u;
label_1c8ce0:
    // 0x1c8ce0: 0xc075a28  jal         func_1D68A0
    ctx->pc = 0x1C8CE0u;
    SET_GPR_U32(ctx, 31, 0x1C8CE8u);
    ctx->pc = 0x1D68A0u;
    if (runtime->hasFunction(0x1D68A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D68A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8CE8u; }
        if (ctx->pc != 0x1C8CE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D68A0_0x1d68a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8CE8u; }
        if (ctx->pc != 0x1C8CE8u) { return; }
    }
    ctx->pc = 0x1C8CE8u;
label_1c8ce8:
    // 0x1c8ce8: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1C8CE8u;
    {
        const bool branch_taken_0x1c8ce8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8ce8) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8CF0u;
    // 0x1c8cf0: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c8cf0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c8cf4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8cf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8cf8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1C8CF8u;
    {
        const bool branch_taken_0x1c8cf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C8CFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8CF8u;
            // 0x1c8cfc: 0xa022b650  sb          $v0, -0x49B0($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294948432), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c8cf8) {
            ctx->pc = 0x1C8D38u;
            goto label_1c8d38;
        }
    }
    ctx->pc = 0x1C8D00u;
label_1c8d00:
    // 0x1c8d00: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c8d00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d04: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1c8d04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d08: 0x2484b653  addiu       $a0, $a0, -0x49AD
    ctx->pc = 0x1c8d08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948435));
    // 0x1c8d0c: 0xc072c60  jal         func_1CB180
    ctx->pc = 0x1C8D0Cu;
    SET_GPR_U32(ctx, 31, 0x1C8D14u);
    ctx->pc = 0x1C8D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8D0Cu;
            // 0x1c8d10: 0x24a5b654  addiu       $a1, $a1, -0x49AC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294948436));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB180u;
    if (runtime->hasFunction(0x1CB180u)) {
        auto targetFn = runtime->lookupFunction(0x1CB180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8D14u; }
        if (ctx->pc != 0x1C8D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB180_0x1cb180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8D14u; }
        if (ctx->pc != 0x1C8D14u) { return; }
    }
    ctx->pc = 0x1C8D14u;
label_1c8d14:
    // 0x1c8d14: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1C8D14u;
    {
        const bool branch_taken_0x1c8d14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c8d14) {
            ctx->pc = 0x1C8D30u;
            goto label_1c8d30;
        }
    }
    ctx->pc = 0x1C8D1Cu;
    // 0x1c8d1c: 0xc072034  jal         func_1C80D0
    ctx->pc = 0x1C8D1Cu;
    SET_GPR_U32(ctx, 31, 0x1C8D24u);
    ctx->pc = 0x1C80D0u;
    if (runtime->hasFunction(0x1C80D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C80D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8D24u; }
        if (ctx->pc != 0x1C8D24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C80D0_0x1c80d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C8D24u; }
        if (ctx->pc != 0x1C8D24u) { return; }
    }
    ctx->pc = 0x1C8D24u;
label_1c8d24:
    // 0x1c8d24: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c8d24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c8d28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8d28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d2c: 0xa022b650  sb          $v0, -0x49B0($at)
    ctx->pc = 0x1c8d2cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294948432), (uint8_t)GPR_U32(ctx, 2));
label_1c8d30:
    // 0x1c8d30: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c8d30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c8d34: 0x8022b650  lb          $v0, -0x49B0($at)
    ctx->pc = 0x1c8d34u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294948432)));
label_1c8d38:
    // 0x1c8d38: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1c8d38u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c8d3c: 0x3e00008  jr          $ra
    ctx->pc = 0x1C8D3Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C8D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C8D3Cu;
            // 0x1c8d40: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C8C68u: goto label_1c8c68;
            case 0x1C8C70u: goto label_1c8c70;
            case 0x1C8C88u: goto label_1c8c88;
            case 0x1C8C90u: goto label_1c8c90;
            case 0x1C8CB8u: goto label_1c8cb8;
            case 0x1C8CC0u: goto label_1c8cc0;
            case 0x1C8CD8u: goto label_1c8cd8;
            case 0x1C8CE0u: goto label_1c8ce0;
            case 0x1C8CE8u: goto label_1c8ce8;
            case 0x1C8D00u: goto label_1c8d00;
            case 0x1C8D14u: goto label_1c8d14;
            case 0x1C8D24u: goto label_1c8d24;
            case 0x1C8D30u: goto label_1c8d30;
            case 0x1C8D38u: goto label_1c8d38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C8D44u;
    // 0x1c8d44: 0x0  nop
    ctx->pc = 0x1c8d44u;
    // NOP
    // 0x1c8d48: 0x0  nop
    ctx->pc = 0x1c8d48u;
    // NOP
    // 0x1c8d4c: 0x0  nop
    ctx->pc = 0x1c8d4cu;
    // NOP
    // 0x1c8d50: 0x807204c  j           func_1C8130
    ctx->pc = 0x1C8D50u;
    ctx->pc = 0x1C8130u;
    if (runtime->hasFunction(0x1C8130u)) {
        auto targetFn = runtime->lookupFunction(0x1C8130u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001C8130_0x1c8130(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1C8D58u;
    // 0x1c8d58: 0x0  nop
    ctx->pc = 0x1c8d58u;
    // NOP
    // 0x1c8d5c: 0x0  nop
    ctx->pc = 0x1c8d5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
