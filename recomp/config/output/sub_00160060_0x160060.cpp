#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160060
// Address: 0x160060 - 0x1600e8
void sub_00160060_0x160060(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160060_0x160060");
#endif

    switch (ctx->pc) {
        case 0x160074u: goto label_160074;
        case 0x160088u: goto label_160088;
        case 0x160094u: goto label_160094;
        case 0x1600b4u: goto label_1600b4;
        default: break;
    }

    ctx->pc = 0x160060u;

    // 0x160060: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x160060u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x160064: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x160064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160068: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x160068u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16006c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16006Cu;
    SET_GPR_U32(ctx, 31, 0x160074u);
    ctx->pc = 0x160070u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16006Cu;
            // 0x160070: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160074u; }
        if (ctx->pc != 0x160074u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160074u; }
        if (ctx->pc != 0x160074u) { return; }
    }
    ctx->pc = 0x160074u;
label_160074:
    // 0x160074: 0x2404fff4  addiu       $a0, $zero, -0xC
    ctx->pc = 0x160074u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967284));
    // 0x160078: 0x14400009  bnez        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x160078u;
    {
        const bool branch_taken_0x160078 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16007Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160078u;
            // 0x16007c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160078) {
            ctx->pc = 0x1600A0u;
            goto label_1600a0;
        }
    }
    ctx->pc = 0x160080u;
    // 0x160080: 0xc057abc  jal         func_15EAF0
    ctx->pc = 0x160080u;
    SET_GPR_U32(ctx, 31, 0x160088u);
    ctx->pc = 0x15EAF0u;
    if (runtime->hasFunction(0x15EAF0u)) {
        auto targetFn = runtime->lookupFunction(0x15EAF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160088u; }
        if (ctx->pc != 0x160088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EAF0_0x15eaf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160088u; }
        if (ctx->pc != 0x160088u) { return; }
    }
    ctx->pc = 0x160088u;
label_160088:
    // 0x160088: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160088u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16008c: 0xc058dd4  jal         func_163750
    ctx->pc = 0x16008Cu;
    SET_GPR_U32(ctx, 31, 0x160094u);
    ctx->pc = 0x160090u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16008Cu;
            // 0x160090: 0x2484f518  addiu       $a0, $a0, -0xAE8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964504));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160094u; }
        if (ctx->pc != 0x160094u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160094u; }
        if (ctx->pc != 0x160094u) { return; }
    }
    ctx->pc = 0x160094u;
label_160094:
    // 0x160094: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x160094u;
    {
        const bool branch_taken_0x160094 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x160098u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160094u;
            // 0x160098: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160094) {
            ctx->pc = 0x1600D8u;
            goto label_1600d8;
        }
    }
    ctx->pc = 0x16009Cu;
    // 0x16009c: 0x0  nop
    ctx->pc = 0x16009cu;
    // NOP
label_1600a0:
    // 0x1600a0: 0x8e020008  lw          $v0, 0x8($s0)
    ctx->pc = 0x1600a0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1600a4: 0x5443000d  bnel        $v0, $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1600A4u;
    {
        const bool branch_taken_0x1600a4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1600a4) {
            ctx->pc = 0x1600A8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1600A4u;
            // 0x1600a8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1600DCu;
            goto label_1600dc;
        }
    }
    ctx->pc = 0x1600ACu;
    // 0x1600ac: 0xc05d4be  jal         func_1752F8
    ctx->pc = 0x1600ACu;
    SET_GPR_U32(ctx, 31, 0x1600B4u);
    ctx->pc = 0x1600B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1600ACu;
            // 0x1600b0: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1752F8u;
    if (runtime->hasFunction(0x1752F8u)) {
        auto targetFn = runtime->lookupFunction(0x1752F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1600B4u; }
        if (ctx->pc != 0x1600B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001752F8_0x1752f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1600B4u; }
        if (ctx->pc != 0x1600B4u) { return; }
    }
    ctx->pc = 0x1600B4u;
label_1600b4:
    // 0x1600b4: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x1600b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1600b8: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x1600b8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1600bc: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1600bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1600c0: 0x10650004  beq         $v1, $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1600C0u;
    {
        const bool branch_taken_0x1600c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1600C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1600C0u;
            // 0x1600c4: 0x28640000  slti        $a0, $v1, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1600c0) {
            ctx->pc = 0x1600D4u;
            goto label_1600d4;
        }
    }
    ctx->pc = 0x1600C8u;
    // 0x1600c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1600c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1600cc: 0x14660002  bne         $v1, $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x1600CCu;
    {
        const bool branch_taken_0x1600cc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        ctx->pc = 0x1600D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1600CCu;
            // 0x1600d0: 0xa4100b  movn        $v0, $a1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1600cc) {
            ctx->pc = 0x1600D8u;
            goto label_1600d8;
        }
    }
    ctx->pc = 0x1600D4u;
label_1600d4:
    // 0x1600d4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1600d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1600d8:
    // 0x1600d8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1600d8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1600dc:
    // 0x1600dc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1600dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1600e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1600E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1600E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1600E0u;
            // 0x1600e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x160074u: goto label_160074;
            case 0x160088u: goto label_160088;
            case 0x160094u: goto label_160094;
            case 0x1600A0u: goto label_1600a0;
            case 0x1600B4u: goto label_1600b4;
            case 0x1600D4u: goto label_1600d4;
            case 0x1600D8u: goto label_1600d8;
            case 0x1600DCu: goto label_1600dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1600E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
