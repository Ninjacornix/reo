#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015BF48
// Address: 0x15bf48 - 0x15bfa4
void sub_0015BF48_0x15bf48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015BF48_0x15bf48");
#endif

    switch (ctx->pc) {
        case 0x15bf6cu: goto label_15bf6c;
        case 0x15bf80u: goto label_15bf80;
        case 0x15bf8cu: goto label_15bf8c;
        default: break;
    }

    ctx->pc = 0x15bf48u;

    // 0x15bf48: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15bf48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15bf4c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15bf4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15bf50: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x15bf50u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bf54: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15bf54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15bf58: 0x16200007  bnez        $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x15BF58u;
    {
        const bool branch_taken_0x15bf58 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x15BF5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BF58u;
            // 0x15bf5c: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bf58) {
            ctx->pc = 0x15BF78u;
            goto label_15bf78;
        }
    }
    ctx->pc = 0x15BF60u;
    // 0x15bf60: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15bf60u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15bf64: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15BF64u;
    SET_GPR_U32(ctx, 31, 0x15BF6Cu);
    ctx->pc = 0x15BF68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BF64u;
            // 0x15bf68: 0x2484e740  addiu       $a0, $a0, -0x18C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294960960));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BF6Cu; }
        if (ctx->pc != 0x15BF6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BF6Cu; }
        if (ctx->pc != 0x15BF6Cu) { return; }
    }
    ctx->pc = 0x15BF6Cu;
label_15bf6c:
    // 0x15bf6c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x15BF6Cu;
    {
        const bool branch_taken_0x15bf6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15BF70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BF6Cu;
            // 0x15bf70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15bf6c) {
            ctx->pc = 0x15BF90u;
            goto label_15bf90;
        }
    }
    ctx->pc = 0x15BF74u;
    // 0x15bf74: 0x0  nop
    ctx->pc = 0x15bf74u;
    // NOP
label_15bf78:
    // 0x15bf78: 0xc056f8e  jal         func_15BE38
    ctx->pc = 0x15BF78u;
    SET_GPR_U32(ctx, 31, 0x15BF80u);
    ctx->pc = 0x15BE38u;
    if (runtime->hasFunction(0x15BE38u)) {
        auto targetFn = runtime->lookupFunction(0x15BE38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BF80u; }
        if (ctx->pc != 0x15BF80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BE38_0x15be38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BF80u; }
        if (ctx->pc != 0x15BF80u) { return; }
    }
    ctx->pc = 0x15BF80u;
label_15bf80:
    // 0x15bf80: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x15bf80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15bf84: 0xc056fbc  jal         func_15BEF0
    ctx->pc = 0x15BF84u;
    SET_GPR_U32(ctx, 31, 0x15BF8Cu);
    ctx->pc = 0x15BF88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15BF84u;
            // 0x15bf88: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BEF0u;
    if (runtime->hasFunction(0x15BEF0u)) {
        auto targetFn = runtime->lookupFunction(0x15BEF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BF8Cu; }
        if (ctx->pc != 0x15BF8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BEF0_0x15bef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15BF8Cu; }
        if (ctx->pc != 0x15BF8Cu) { return; }
    }
    ctx->pc = 0x15BF8Cu;
label_15bf8c:
    // 0x15bf8c: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x15bf8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
label_15bf90:
    // 0x15bf90: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15bf90u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15bf94: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15bf94u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15bf98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15bf98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15bf9c: 0x3e00008  jr          $ra
    ctx->pc = 0x15BF9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15BFA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15BF9Cu;
            // 0x15bfa0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15BF6Cu: goto label_15bf6c;
            case 0x15BF78u: goto label_15bf78;
            case 0x15BF80u: goto label_15bf80;
            case 0x15BF8Cu: goto label_15bf8c;
            case 0x15BF90u: goto label_15bf90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15BFA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
