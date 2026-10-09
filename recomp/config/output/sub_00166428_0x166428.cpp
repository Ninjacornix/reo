#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166428
// Address: 0x166428 - 0x166498
void sub_00166428_0x166428(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166428_0x166428");
#endif

    switch (ctx->pc) {
        case 0x166448u: goto label_166448;
        case 0x166458u: goto label_166458;
        default: break;
    }

    ctx->pc = 0x166428u;

    // 0x166428: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166428u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16642c: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x16642cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x166430: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166430u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166434: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166434u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166438: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166438u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16643c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x16643cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x166440: 0xc05df12  jal         func_177C48
    ctx->pc = 0x166440u;
    SET_GPR_U32(ctx, 31, 0x166448u);
    ctx->pc = 0x166444u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166440u;
            // 0x166444: 0x24110001  addiu       $s1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C48u;
    if (runtime->hasFunction(0x177C48u)) {
        auto targetFn = runtime->lookupFunction(0x177C48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166448u; }
        if (ctx->pc != 0x166448u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00177C48_0x177c48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166448u; }
        if (ctx->pc != 0x166448u) { return; }
    }
    ctx->pc = 0x166448u;
label_166448:
    // 0x166448: 0x1051000d  beq         $v0, $s1, . + 4 + (0xD << 2)
    ctx->pc = 0x166448u;
    {
        const bool branch_taken_0x166448 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 17));
        ctx->pc = 0x16644Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166448u;
            // 0x16644c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166448) {
            ctx->pc = 0x166480u;
            goto label_166480;
        }
    }
    ctx->pc = 0x166450u;
    // 0x166450: 0xc059f30  jal         func_167CC0
    ctx->pc = 0x166450u;
    SET_GPR_U32(ctx, 31, 0x166458u);
    ctx->pc = 0x166454u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166450u;
            // 0x166454: 0x8e051c8c  lw          $a1, 0x1C8C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7308)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x167CC0u;
    if (runtime->hasFunction(0x167CC0u)) {
        auto targetFn = runtime->lookupFunction(0x167CC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166458u; }
        if (ctx->pc != 0x166458u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167CC0_0x167cc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166458u; }
        if (ctx->pc != 0x166458u) { return; }
    }
    ctx->pc = 0x166458u;
label_166458:
    // 0x166458: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166458u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16645c: 0x24050007  addiu       $a1, $zero, 0x7
    ctx->pc = 0x16645cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x166460: 0x14510007  bne         $v0, $s1, . + 4 + (0x7 << 2)
    ctx->pc = 0x166460u;
    {
        const bool branch_taken_0x166460 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x166464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166460u;
            // 0x166464: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x166460) {
            ctx->pc = 0x166480u;
            goto label_166480;
        }
    }
    ctx->pc = 0x166468u;
    // 0x166468: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166468u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16646c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16646cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166470: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166470u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x166474: 0x805df0c  j           func_177C30
    ctx->pc = 0x166474u;
    ctx->pc = 0x166478u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166474u;
            // 0x166478: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177C30u;
    if (runtime->hasFunction(0x177C30u)) {
        auto targetFn = runtime->lookupFunction(0x177C30u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177C30_0x177c30(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16647Cu;
    // 0x16647c: 0x0  nop
    ctx->pc = 0x16647cu;
    // NOP
label_166480:
    // 0x166480: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166480u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166484: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166484u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166488: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x166488u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16648c: 0x3e00008  jr          $ra
    ctx->pc = 0x16648Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x166490u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16648Cu;
            // 0x166490: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x166448u: goto label_166448;
            case 0x166458u: goto label_166458;
            case 0x166480u: goto label_166480;
            default: break;
        }
        return;
    }
    ctx->pc = 0x166494u;
    // 0x166494: 0x0  nop
    ctx->pc = 0x166494u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
