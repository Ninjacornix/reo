#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FF18
// Address: 0x15ff18 - 0x15ff54
void sub_0015FF18_0x15ff18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FF18_0x15ff18");
#endif

    switch (ctx->pc) {
        case 0x15ff38u: goto label_15ff38;
        default: break;
    }

    ctx->pc = 0x15ff18u;

    // 0x15ff18: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15ff18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15ff1c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15ff1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15ff20: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15ff20u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff24: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15ff24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15ff28: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15ff28u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff2c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15ff2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15ff30: 0xc059150  jal         func_164540
    ctx->pc = 0x15FF30u;
    SET_GPR_U32(ctx, 31, 0x15FF38u);
    ctx->pc = 0x15FF34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF30u;
            // 0x15ff34: 0x8e040044  lw          $a0, 0x44($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x164540u;
    if (runtime->hasFunction(0x164540u)) {
        auto targetFn = runtime->lookupFunction(0x164540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FF38u; }
        if (ctx->pc != 0x15FF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00164540_0x164540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15FF38u; }
        if (ctx->pc != 0x15FF38u) { return; }
    }
    ctx->pc = 0x15FF38u;
label_15ff38:
    // 0x15ff38: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15ff38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff3c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x15ff3cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15ff40: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15ff40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15ff44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15ff44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15ff48: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15ff48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15ff4c: 0x8058aa6  j           func_162A98
    ctx->pc = 0x15FF4Cu;
    ctx->pc = 0x15FF50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15FF4Cu;
            // 0x15ff50: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162A98u;
    if (runtime->hasFunction(0x162A98u)) {
        auto targetFn = runtime->lookupFunction(0x162A98u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00162A98_0x162a98(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15FF54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
