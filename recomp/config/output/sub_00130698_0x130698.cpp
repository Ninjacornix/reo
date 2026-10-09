#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00130698
// Address: 0x130698 - 0x1306e0
void sub_00130698_0x130698(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00130698_0x130698");
#endif

    switch (ctx->pc) {
        case 0x1306b4u: goto label_1306b4;
        case 0x1306bcu: goto label_1306bc;
        case 0x1306c4u: goto label_1306c4;
        default: break;
    }

    ctx->pc = 0x130698u;

    // 0x130698: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x130698u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13069c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13069cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1306a0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1306a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1306a4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1306a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1306a8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1306a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1306ac: 0xc049938  jal         func_1264E0
    ctx->pc = 0x1306ACu;
    SET_GPR_U32(ctx, 31, 0x1306B4u);
    ctx->pc = 0x1306B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1306ACu;
            // 0x1306b0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306B4u; }
        if (ctx->pc != 0x1306B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306B4u; }
        if (ctx->pc != 0x1306B4u) { return; }
    }
    ctx->pc = 0x1306B4u;
label_1306b4:
    // 0x1306b4: 0xc04c188  jal         func_130620
    ctx->pc = 0x1306B4u;
    SET_GPR_U32(ctx, 31, 0x1306BCu);
    ctx->pc = 0x1306B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1306B4u;
            // 0x1306b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130620u;
    if (runtime->hasFunction(0x130620u)) {
        auto targetFn = runtime->lookupFunction(0x130620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306BCu; }
        if (ctx->pc != 0x1306BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130620_0x130620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306BCu; }
        if (ctx->pc != 0x1306BCu) { return; }
    }
    ctx->pc = 0x1306BCu;
label_1306bc:
    // 0x1306bc: 0xc04993e  jal         func_1264F8
    ctx->pc = 0x1306BCu;
    SET_GPR_U32(ctx, 31, 0x1306C4u);
    ctx->pc = 0x1306C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1306BCu;
            // 0x1306c0: 0xae110058  sw          $s1, 0x58($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306C4u; }
        if (ctx->pc != 0x1306C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1306C4u; }
        if (ctx->pc != 0x1306C4u) { return; }
    }
    ctx->pc = 0x1306C4u;
label_1306c4:
    // 0x1306c4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1306c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1306c8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1306c8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1306cc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1306ccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1306d0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1306d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1306d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1306D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1306D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1306D4u;
            // 0x1306d8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1306B4u: goto label_1306b4;
            case 0x1306BCu: goto label_1306bc;
            case 0x1306C4u: goto label_1306c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1306DCu;
    // 0x1306dc: 0x0  nop
    ctx->pc = 0x1306dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
