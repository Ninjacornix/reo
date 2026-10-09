#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161C78
// Address: 0x161c78 - 0x161d20
void sub_00161C78_0x161c78(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161C78_0x161c78");
#endif

    switch (ctx->pc) {
        case 0x161cacu: goto label_161cac;
        case 0x161cdcu: goto label_161cdc;
        case 0x161cf4u: goto label_161cf4;
        case 0x161d10u: goto label_161d10;
        default: break;
    }

    ctx->pc = 0x161c78u;

    // 0x161c78: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x161c78u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x161c7c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x161c7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161c80: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x161c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x161c84: 0x24430100  addiu       $v1, $v0, 0x100
    ctx->pc = 0x161c84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x161c88: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x161c88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x161c8c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x161c8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161c90: 0x8c680004  lw          $t0, 0x4($v1)
    ctx->pc = 0x161c90u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x161c94: 0x15000008  bnez        $t0, . + 4 + (0x8 << 2)
    ctx->pc = 0x161C94u;
    {
        const bool branch_taken_0x161c94 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x161C98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161C94u;
            // 0x161c98: 0x8c5000a8  lw          $s0, 0xA8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 168)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161c94) {
            ctx->pc = 0x161CB8u;
            goto label_161cb8;
        }
    }
    ctx->pc = 0x161C9Cu;
    // 0x161c9c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161c9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ca0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x161ca0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ca4: 0xc05f4be  jal         func_17D2F8
    ctx->pc = 0x161CA4u;
    SET_GPR_U32(ctx, 31, 0x161CACu);
    ctx->pc = 0x161CA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161CA4u;
            // 0x161ca8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2F8u;
    if (runtime->hasFunction(0x17D2F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CACu; }
        if (ctx->pc != 0x161CACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2F8_0x17d2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CACu; }
        if (ctx->pc != 0x161CACu) { return; }
    }
    ctx->pc = 0x161CACu;
label_161cac:
    // 0x161cac: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x161CACu;
    {
        const bool branch_taken_0x161cac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161CB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161CACu;
            // 0x161cb0: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161cac) {
            ctx->pc = 0x161D14u;
            goto label_161d14;
        }
    }
    ctx->pc = 0x161CB4u;
    // 0x161cb4: 0x0  nop
    ctx->pc = 0x161cb4u;
    // NOP
label_161cb8:
    // 0x161cb8: 0x8c620008  lw          $v0, 0x8($v1)
    ctx->pc = 0x161cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x161cbc: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x161cbcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x161cc0: 0x3c060024  lui         $a2, 0x24
    ctx->pc = 0x161cc0u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)36 << 16));
    // 0x161cc4: 0x24a5fef8  addiu       $a1, $a1, -0x108
    ctx->pc = 0x161cc4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967032));
    // 0x161cc8: 0x24c6ff00  addiu       $a2, $a2, -0x100
    ctx->pc = 0x161cc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967040));
    // 0x161ccc: 0x27a70010  addiu       $a3, $sp, 0x10
    ctx->pc = 0x161cccu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x161cd0: 0xafa80000  sw          $t0, 0x0($sp)
    ctx->pc = 0x161cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
    // 0x161cd4: 0xc050288  jal         func_140A20
    ctx->pc = 0x161CD4u;
    SET_GPR_U32(ctx, 31, 0x161CDCu);
    ctx->pc = 0x161CD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161CD4u;
            // 0x161cd8: 0xafa20004  sw          $v0, 0x4($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x140A20u;
    if (runtime->hasFunction(0x140A20u)) {
        auto targetFn = runtime->lookupFunction(0x140A20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CDCu; }
        if (ctx->pc != 0x161CDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00140A20_0x140a20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CDCu; }
        if (ctx->pc != 0x161CDCu) { return; }
    }
    ctx->pc = 0x161CDCu;
label_161cdc:
    // 0x161cdc: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161cdcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ce0: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x161ce0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161ce4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x161CE4u;
    {
        const bool branch_taken_0x161ce4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161CE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161CE4u;
            // 0x161ce8: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161ce4) {
            ctx->pc = 0x161D00u;
            goto label_161d00;
        }
    }
    ctx->pc = 0x161CECu;
    // 0x161cec: 0xc05f4be  jal         func_17D2F8
    ctx->pc = 0x161CECu;
    SET_GPR_U32(ctx, 31, 0x161CF4u);
    ctx->pc = 0x17D2F8u;
    if (runtime->hasFunction(0x17D2F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CF4u; }
        if (ctx->pc != 0x161CF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2F8_0x17d2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161CF4u; }
        if (ctx->pc != 0x161CF4u) { return; }
    }
    ctx->pc = 0x161CF4u;
label_161cf4:
    // 0x161cf4: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x161CF4u;
    {
        const bool branch_taken_0x161cf4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x161CF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161CF4u;
            // 0x161cf8: 0xdfb00020  ld          $s0, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161cf4) {
            ctx->pc = 0x161D14u;
            goto label_161d14;
        }
    }
    ctx->pc = 0x161CFCu;
    // 0x161cfc: 0x0  nop
    ctx->pc = 0x161cfcu;
    // NOP
label_161d00:
    // 0x161d00: 0x8fa50010  lw          $a1, 0x10($sp)
    ctx->pc = 0x161d00u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x161d04: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x161d04u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x161d08: 0xc05f4be  jal         func_17D2F8
    ctx->pc = 0x161D08u;
    SET_GPR_U32(ctx, 31, 0x161D10u);
    ctx->pc = 0x161D0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161D08u;
            // 0x161d0c: 0x8fa60014  lw          $a2, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D2F8u;
    if (runtime->hasFunction(0x17D2F8u)) {
        auto targetFn = runtime->lookupFunction(0x17D2F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D10u; }
        if (ctx->pc != 0x161D10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017D2F8_0x17d2f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161D10u; }
        if (ctx->pc != 0x161D10u) { return; }
    }
    ctx->pc = 0x161D10u;
label_161d10:
    // 0x161d10: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x161d10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_161d14:
    // 0x161d14: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x161d14u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x161d18: 0x3e00008  jr          $ra
    ctx->pc = 0x161D18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161D1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161D18u;
            // 0x161d1c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161CACu: goto label_161cac;
            case 0x161CB8u: goto label_161cb8;
            case 0x161CDCu: goto label_161cdc;
            case 0x161CF4u: goto label_161cf4;
            case 0x161D00u: goto label_161d00;
            case 0x161D10u: goto label_161d10;
            case 0x161D14u: goto label_161d14;
            default: break;
        }
        return;
    }
    ctx->pc = 0x161D20u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
