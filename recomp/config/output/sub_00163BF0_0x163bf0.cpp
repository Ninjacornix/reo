#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163BF0
// Address: 0x163bf0 - 0x163c78
void sub_00163BF0_0x163bf0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163BF0_0x163bf0");
#endif

    switch (ctx->pc) {
        case 0x163c1cu: goto label_163c1c;
        case 0x163c2cu: goto label_163c2c;
        case 0x163c40u: goto label_163c40;
        case 0x163c4cu: goto label_163c4c;
        default: break;
    }

    ctx->pc = 0x163bf0u;

    // 0x163bf0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x163bf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x163bf4: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x163bf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163bf8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163bf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163bfc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x163bfcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163c00: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x163c00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x163c04: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x163c04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x163c08: 0x82020071  lb          $v0, 0x71($s0)
    ctx->pc = 0x163c08u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 113)));
    // 0x163c0c: 0x1443000d  bne         $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x163C0Cu;
    {
        const bool branch_taken_0x163c0c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x163C10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163C0Cu;
            // 0x163c10: 0x8e110040  lw          $s1, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163c0c) {
            ctx->pc = 0x163C44u;
            goto label_163c44;
        }
    }
    ctx->pc = 0x163C14u;
    // 0x163c14: 0xc04f434  jal         func_13D0D0
    ctx->pc = 0x163C14u;
    SET_GPR_U32(ctx, 31, 0x163C1Cu);
    ctx->pc = 0x163C18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163C14u;
            // 0x163c18: 0x8e04004c  lw          $a0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D0D0u;
    if (runtime->hasFunction(0x13D0D0u)) {
        auto targetFn = runtime->lookupFunction(0x13D0D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C1Cu; }
        if (ctx->pc != 0x163C1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D0D0_0x13d0d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C1Cu; }
        if (ctx->pc != 0x163C1Cu) { return; }
    }
    ctx->pc = 0x163C1Cu;
label_163c1c:
    // 0x163c1c: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x163C1Cu;
    {
        const bool branch_taken_0x163c1c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x163c1c) {
            ctx->pc = 0x163C44u;
            goto label_163c44;
        }
    }
    ctx->pc = 0x163C24u;
    // 0x163c24: 0xc05cfca  jal         func_173F28
    ctx->pc = 0x163C24u;
    SET_GPR_U32(ctx, 31, 0x163C2Cu);
    ctx->pc = 0x163C28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163C24u;
            // 0x163c28: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173F28u;
    if (runtime->hasFunction(0x173F28u)) {
        auto targetFn = runtime->lookupFunction(0x173F28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C2Cu; }
        if (ctx->pc != 0x163C2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173F28_0x173f28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C2Cu; }
        if (ctx->pc != 0x163C2Cu) { return; }
    }
    ctx->pc = 0x163C2Cu;
label_163c2c:
    // 0x163c2c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x163c2cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x163c30: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x163C30u;
    {
        const bool branch_taken_0x163c30 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x163C34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163C30u;
            // 0x163c34: 0x24840500  addiu       $a0, $a0, 0x500 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1280));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163c30) {
            ctx->pc = 0x163C40u;
            goto label_163c40;
        }
    }
    ctx->pc = 0x163C38u;
    // 0x163c38: 0xc058dd4  jal         func_163750
    ctx->pc = 0x163C38u;
    SET_GPR_U32(ctx, 31, 0x163C40u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C40u; }
        if (ctx->pc != 0x163C40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C40u; }
        if (ctx->pc != 0x163C40u) { return; }
    }
    ctx->pc = 0x163C40u;
label_163c40:
    // 0x163c40: 0xa2000071  sb          $zero, 0x71($s0)
    ctx->pc = 0x163c40u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 113), (uint8_t)GPR_U32(ctx, 0));
label_163c44:
    // 0x163c44: 0xc05d4be  jal         func_1752F8
    ctx->pc = 0x163C44u;
    SET_GPR_U32(ctx, 31, 0x163C4Cu);
    ctx->pc = 0x163C48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163C44u;
            // 0x163c48: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1752F8u;
    if (runtime->hasFunction(0x1752F8u)) {
        auto targetFn = runtime->lookupFunction(0x1752F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C4Cu; }
        if (ctx->pc != 0x163C4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752F8_0x1752f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163C4Cu; }
        if (ctx->pc != 0x163C4Cu) { return; }
    }
    ctx->pc = 0x163C4Cu;
label_163c4c:
    // 0x163c4c: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x163c4cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x163c50: 0x54430004  bnel        $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x163C50u;
    {
        const bool branch_taken_0x163c50 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x163c50) {
            ctx->pc = 0x163C54u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x163C50u;
            // 0x163c54: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x163C64u;
            goto label_163c64;
        }
    }
    ctx->pc = 0x163C58u;
    // 0x163c58: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x163c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x163c5c: 0xae020008  sw          $v0, 0x8($s0)
    ctx->pc = 0x163c5cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 2));
    // 0x163c60: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163c60u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_163c64:
    // 0x163c64: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x163c64u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163c68: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x163c68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x163c6c: 0x3e00008  jr          $ra
    ctx->pc = 0x163C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163C70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163C6Cu;
            // 0x163c70: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163C1Cu: goto label_163c1c;
            case 0x163C2Cu: goto label_163c2c;
            case 0x163C40u: goto label_163c40;
            case 0x163C44u: goto label_163c44;
            case 0x163C4Cu: goto label_163c4c;
            case 0x163C64u: goto label_163c64;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163C74u;
    // 0x163c74: 0x0  nop
    ctx->pc = 0x163c74u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
