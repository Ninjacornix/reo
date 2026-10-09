#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001602C8
// Address: 0x1602c8 - 0x160330
void sub_001602C8_0x1602c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001602C8_0x1602c8");
#endif

    switch (ctx->pc) {
        case 0x1602dcu: goto label_1602dc;
        case 0x1602f4u: goto label_1602f4;
        case 0x160308u: goto label_160308;
        case 0x16031cu: goto label_16031c;
        default: break;
    }

    ctx->pc = 0x1602c8u;

    // 0x1602c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1602c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1602cc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1602ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1602d0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1602d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1602d4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1602D4u;
    SET_GPR_U32(ctx, 31, 0x1602DCu);
    ctx->pc = 0x1602D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1602D4u;
            // 0x1602d8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1602DCu; }
        if (ctx->pc != 0x1602DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1602DCu; }
        if (ctx->pc != 0x1602DCu) { return; }
    }
    ctx->pc = 0x1602DCu;
label_1602dc:
    // 0x1602dc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1602dcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1602e0: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1602e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1602e4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1602E4u;
    {
        const bool branch_taken_0x1602e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1602E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1602E4u;
            // 0x1602e8: 0x2484f5d0  addiu       $a0, $a0, -0xA30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964688));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1602e4) {
            ctx->pc = 0x160300u;
            goto label_160300;
        }
    }
    ctx->pc = 0x1602ECu;
    // 0x1602ec: 0xc058dd4  jal         func_163750
    ctx->pc = 0x1602ECu;
    SET_GPR_U32(ctx, 31, 0x1602F4u);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1602F4u; }
        if (ctx->pc != 0x1602F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1602F4u; }
        if (ctx->pc != 0x1602F4u) { return; }
    }
    ctx->pc = 0x1602F4u;
label_1602f4:
    // 0x1602f4: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x1602F4u;
    {
        const bool branch_taken_0x1602f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1602F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1602F4u;
            // 0x1602f8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1602f4) {
            ctx->pc = 0x160320u;
            goto label_160320;
        }
    }
    ctx->pc = 0x1602FCu;
    // 0x1602fc: 0x0  nop
    ctx->pc = 0x1602fcu;
    // NOP
label_160300:
    // 0x160300: 0xc05afe0  jal         func_16BF80
    ctx->pc = 0x160300u;
    SET_GPR_U32(ctx, 31, 0x160308u);
    ctx->pc = 0x160304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160300u;
            // 0x160304: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BF80u;
    if (runtime->hasFunction(0x16BF80u)) {
        auto targetFn = runtime->lookupFunction(0x16BF80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160308u; }
        if (ctx->pc != 0x160308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016BF80_0x16bf80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x160308u; }
        if (ctx->pc != 0x160308u) { return; }
    }
    ctx->pc = 0x160308u;
label_160308:
    // 0x160308: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160308u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x16030c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16030Cu;
    {
        const bool branch_taken_0x16030c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x160310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16030Cu;
            // 0x160310: 0x2484f608  addiu       $a0, $a0, -0x9F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964744));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16030c) {
            ctx->pc = 0x16031Cu;
            goto label_16031c;
        }
    }
    ctx->pc = 0x160314u;
    // 0x160314: 0xc058dd4  jal         func_163750
    ctx->pc = 0x160314u;
    SET_GPR_U32(ctx, 31, 0x16031Cu);
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16031Cu; }
        if (ctx->pc != 0x16031Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16031Cu; }
        if (ctx->pc != 0x16031Cu) { return; }
    }
    ctx->pc = 0x16031Cu;
label_16031c:
    // 0x16031c: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x16031cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_160320:
    // 0x160320: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x160320u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160324: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160324u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160328: 0x3e00008  jr          $ra
    ctx->pc = 0x160328u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16032Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160328u;
            // 0x16032c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1602DCu: goto label_1602dc;
            case 0x1602F4u: goto label_1602f4;
            case 0x160300u: goto label_160300;
            case 0x160308u: goto label_160308;
            case 0x16031Cu: goto label_16031c;
            case 0x160320u: goto label_160320;
            default: break;
        }
        return;
    }
    ctx->pc = 0x160330u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
