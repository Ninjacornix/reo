#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DD08
// Address: 0x11dd08 - 0x11dd80
void sub_0011DD08_0x11dd08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DD08_0x11dd08");
#endif

    switch (ctx->pc) {
        case 0x11dd1cu: goto label_11dd1c;
        case 0x11dd54u: goto label_11dd54;
        case 0x11dd5cu: goto label_11dd5c;
        default: break;
    }

    ctx->pc = 0x11dd08u;

    // 0x11dd08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11dd08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11dd0c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11dd0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11dd10: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11dd10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11dd14: 0xc047712  jal         func_11DC48
    ctx->pc = 0x11DD14u;
    SET_GPR_U32(ctx, 31, 0x11DD1Cu);
    ctx->pc = 0x11DD18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DD14u;
            // 0x11dd18: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DC48u;
    if (runtime->hasFunction(0x11DC48u)) {
        auto targetFn = runtime->lookupFunction(0x11DC48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DD1Cu; }
        if (ctx->pc != 0x11DD1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DC48_0x11dc48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DD1Cu; }
        if (ctx->pc != 0x11DD1Cu) { return; }
    }
    ctx->pc = 0x11DD1Cu;
label_11dd1c:
    // 0x11dd1c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11dd1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dd20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11dd20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dd24: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11dd24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dd28: 0x8045090  j           func_114240
    ctx->pc = 0x11DD28u;
    ctx->pc = 0x11DD2Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DD28u;
            // 0x11dd2c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114240u;
    if (runtime->hasFunction(0x114240u)) {
        auto targetFn = runtime->lookupFunction(0x114240u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114240_0x114240(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11DD30u;
    // 0x11dd30: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x11dd30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11dd34: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x11dd34u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dd38: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11dd38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11dd3c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x11dd3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dd40: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11dd40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11dd44: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x11dd44u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11dd48: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11dd48u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dd4c: 0xc0476cc  jal         func_11DB30
    ctx->pc = 0x11DD4Cu;
    SET_GPR_U32(ctx, 31, 0x11DD54u);
    ctx->pc = 0x11DD50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DD4Cu;
            // 0x11dd50: 0x24848c50  addiu       $a0, $a0, -0x73B0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DB30u;
    if (runtime->hasFunction(0x11DB30u)) {
        auto targetFn = runtime->lookupFunction(0x11DB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DD54u; }
        if (ctx->pc != 0x11DD54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DB30_0x11db30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DD54u; }
        if (ctx->pc != 0x11DD54u) { return; }
    }
    ctx->pc = 0x11DD54u;
label_11dd54:
    // 0x11dd54: 0xc047712  jal         func_11DC48
    ctx->pc = 0x11DD54u;
    SET_GPR_U32(ctx, 31, 0x11DD5Cu);
    ctx->pc = 0x11DC48u;
    if (runtime->hasFunction(0x11DC48u)) {
        auto targetFn = runtime->lookupFunction(0x11DC48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DD5Cu; }
        if (ctx->pc != 0x11DD5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DC48_0x11dc48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DD5Cu; }
        if (ctx->pc != 0x11DD5Cu) { return; }
    }
    ctx->pc = 0x11DD5Cu;
label_11dd5c:
    // 0x11dd5c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11dd5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11dd60: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11dd60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dd64: 0x8c45a180  lw          $a1, -0x5E80($v0)
    ctx->pc = 0x11dd64u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943104)));
    // 0x11dd68: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x11dd68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dd6c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11dd6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dd70: 0x24a50004  addiu       $a1, $a1, 0x4
    ctx->pc = 0x11dd70u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4));
    // 0x11dd74: 0x8045290  j           func_114A40
    ctx->pc = 0x11DD74u;
    ctx->pc = 0x11DD78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DD74u;
            // 0x11dd78: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A40u;
    if (runtime->hasFunction(0x114A40u)) {
        auto targetFn = runtime->lookupFunction(0x114A40u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114A40_0x114a40(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11DD7Cu;
    // 0x11dd7c: 0x0  nop
    ctx->pc = 0x11dd7cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
