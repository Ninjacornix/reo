#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00106EE0
// Address: 0x106ee0 - 0x106f38
void sub_00106EE0_0x106ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00106EE0_0x106ee0");
#endif

    switch (ctx->pc) {
        case 0x106f04u: goto label_106f04;
        case 0x106f10u: goto label_106f10;
        case 0x106f1cu: goto label_106f1c;
        default: break;
    }

    ctx->pc = 0x106ee0u;

    // 0x106ee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x106ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x106ee4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x106ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x106ee8: 0x3c100021  lui         $s0, 0x21
    ctx->pc = 0x106ee8u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)33 << 16));
    // 0x106eec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x106eecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x106ef0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x106ef0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106ef4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x106ef4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x106ef8: 0x261097f0  addiu       $s0, $s0, -0x6810
    ctx->pc = 0x106ef8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294940656));
    // 0x106efc: 0xc041f4a  jal         func_107D28
    ctx->pc = 0x106EFCu;
    SET_GPR_U32(ctx, 31, 0x106F04u);
    ctx->pc = 0x106F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106EFCu;
            // 0x106f00: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107D28u;
    if (runtime->hasFunction(0x107D28u)) {
        auto targetFn = runtime->lookupFunction(0x107D28u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F04u; }
        if (ctx->pc != 0x106F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F04u; }
        if (ctx->pc != 0x106F04u) { return; }
    }
    ctx->pc = 0x106F04u;
label_106f04:
    // 0x106f04: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106f04u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106f08: 0xc041c76  jal         func_1071D8
    ctx->pc = 0x106F08u;
    SET_GPR_U32(ctx, 31, 0x106F10u);
    ctx->pc = 0x106F0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106F08u;
            // 0x106f0c: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1071D8u;
    if (runtime->hasFunction(0x1071D8u)) {
        auto targetFn = runtime->lookupFunction(0x1071D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F10u; }
        if (ctx->pc != 0x106F10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001071D8_0x1071d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F10u; }
        if (ctx->pc != 0x106F10u) { return; }
    }
    ctx->pc = 0x106F10u;
label_106f10:
    // 0x106f10: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x106f10u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x106f14: 0xc041f6a  jal         func_107DA8
    ctx->pc = 0x106F14u;
    SET_GPR_U32(ctx, 31, 0x106F1Cu);
    ctx->pc = 0x106F18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x106F14u;
            // 0x106f18: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DA8u;
    if (runtime->hasFunction(0x107DA8u)) {
        auto targetFn = runtime->lookupFunction(0x107DA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F1Cu; }
        if (ctx->pc != 0x106F1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x106F1Cu; }
        if (ctx->pc != 0x106F1Cu) { return; }
    }
    ctx->pc = 0x106F1Cu;
label_106f1c:
    // 0x106f1c: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x106f1cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x106f20: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x106f20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x106f24: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x106f24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x106f28: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x106f28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x106f2c: 0x3e00008  jr          $ra
    ctx->pc = 0x106F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x106F30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x106F2Cu;
            // 0x106f30: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x106F04u: goto label_106f04;
            case 0x106F10u: goto label_106f10;
            case 0x106F1Cu: goto label_106f1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x106F34u;
    // 0x106f34: 0x0  nop
    ctx->pc = 0x106f34u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
