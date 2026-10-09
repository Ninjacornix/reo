#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D68F0
// Address: 0x1d68f0 - 0x1d6930
void sub_001D68F0_0x1d68f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D68F0_0x1d68f0");
#endif

    switch (ctx->pc) {
        case 0x1d690cu: goto label_1d690c;
        case 0x1d6918u: goto label_1d6918;
        default: break;
    }

    ctx->pc = 0x1d68f0u;

    // 0x1d68f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d68f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d68f4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1d68f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d68f8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d68f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d68fc: 0x94450004  lhu         $a1, 0x4($v0)
    ctx->pc = 0x1d68fcu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1d6900: 0x94460006  lhu         $a2, 0x6($v0)
    ctx->pc = 0x1d6900u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x1d6904: 0xc075ec0  jal         func_1D7B00
    ctx->pc = 0x1D6904u;
    SET_GPR_U32(ctx, 31, 0x1D690Cu);
    ctx->pc = 0x1D6908u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6904u;
            // 0x1d6908: 0x8c840000  lw          $a0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7B00u;
    if (runtime->hasFunction(0x1D7B00u)) {
        auto targetFn = runtime->lookupFunction(0x1D7B00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D690Cu; }
        if (ctx->pc != 0x1D690Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7B00_0x1d7b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D690Cu; }
        if (ctx->pc != 0x1D690Cu) { return; }
    }
    ctx->pc = 0x1D690Cu;
label_1d690c:
    // 0x1d690c: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x1d690cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6910: 0xc0759b4  jal         func_1D66D0
    ctx->pc = 0x1D6910u;
    SET_GPR_U32(ctx, 31, 0x1D6918u);
    ctx->pc = 0x1D6914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6910u;
            // 0x1d6914: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D66D0u;
    if (runtime->hasFunction(0x1D66D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D66D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6918u; }
        if (ctx->pc != 0x1D6918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D66D0_0x1d66d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6918u; }
        if (ctx->pc != 0x1D6918u) { return; }
    }
    ctx->pc = 0x1D6918u;
label_1d6918:
    // 0x1d6918: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6918u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d691c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D691Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D691Cu;
            // 0x1d6920: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D690Cu: goto label_1d690c;
            case 0x1D6918u: goto label_1d6918;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6924u;
    // 0x1d6924: 0x0  nop
    ctx->pc = 0x1d6924u;
    // NOP
    // 0x1d6928: 0x0  nop
    ctx->pc = 0x1d6928u;
    // NOP
    // 0x1d692c: 0x0  nop
    ctx->pc = 0x1d692cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
