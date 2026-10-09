#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106F38
// Address: 0x106f38 - 0x106f80
void sub_00106F38_0x106f38(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106F38_0x106f38");
#endif

    switch (ctx->pc) {
        case 0x106f5cu: goto label_106f5c;
        case 0x106f68u: goto label_106f68;
        default: break;
    }

    ctx->pc = 0x106f38u;

    // 0x106f38: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x106f38u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106f3c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106f3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106f40: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x106f40u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x106f44: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106f44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106f48: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x106f48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106f4c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x106f4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x106f50: 0x261097f0  addiu       $s0, $s0, -0x6810
    ctx->pc = 0x106f50u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x106f54: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x106F54u;
    SET_GPR_U32(ctx, 31, 0x106F5Cu);
    ctx->pc = 0x106F58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106F54u;
            // 0x106f58: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F5Cu; }
        if (ctx->pc != 0x106F5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F5Cu; }
        if (ctx->pc != 0x106F5Cu) { return; }
    }
    ctx->pc = 0x106F5Cu;
label_106f5c:
    // 0x106f5c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106f5cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106f60: 0xc041636  jal         func_1058D8
    ctx->pc = 0x106F60u;
    SET_GPR_U32(ctx, 31, 0x106F68u);
    ctx->pc = 0x106F64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106F60u;
            // 0x106f64: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1058D8u;
    if (runtime->hasFunction(0x1058D8u)) {
        auto targetFn = runtime->lookupFunction(0x1058D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F68u; }
        if (ctx->pc != 0x106F68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001058D8_0x1058d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F68u; }
        if (ctx->pc != 0x106F68u) { return; }
    }
    ctx->pc = 0x106F68u;
label_106f68:
    // 0x106f68: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106f68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106f6c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106f6cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106f70: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106f70u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106f74: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x106f74u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106f78: 0x8041f6a  j           func_107DA8
    ctx->pc = 0x106F78u;
    ctx->pc = 0x106F7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106F78u;
            // 0x106f7c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107DA8_0x107da8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x106F80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
