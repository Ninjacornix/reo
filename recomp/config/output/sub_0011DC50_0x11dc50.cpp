#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DC50
// Address: 0x11dc50 - 0x11dcc0
void sub_0011DC50_0x11dc50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DC50_0x11dc50");
#endif

    switch (ctx->pc) {
        case 0x11dc84u: goto label_11dc84;
        case 0x11dc8cu: goto label_11dc8c;
        case 0x11dca8u: goto label_11dca8;
        default: break;
    }

    ctx->pc = 0x11dc50u;

    // 0x11dc50: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x11dc50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11dc54: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11dc54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11dc58: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x11dc58u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc5c: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x11dc5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11dc60: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11dc60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11dc64: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x11dc64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc68: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x11dc68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc6c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x11dc6cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11dc70: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x11dc70u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc74: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x11dc74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11dc78: 0x24848c50  addiu       $a0, $a0, -0x73B0
    ctx->pc = 0x11dc78u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294937680));
    // 0x11dc7c: 0xc0476cc  jal         func_11DB30
    ctx->pc = 0x11DC7Cu;
    SET_GPR_U32(ctx, 31, 0x11DC84u);
    ctx->pc = 0x11DC80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DC7Cu;
            // 0x11dc80: 0xe0302d  daddu       $a2, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DB30u;
    if (runtime->hasFunction(0x11DB30u)) {
        auto targetFn = runtime->lookupFunction(0x11DB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DC84u; }
        if (ctx->pc != 0x11DC84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DB30_0x11db30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DC84u; }
        if (ctx->pc != 0x11DC84u) { return; }
    }
    ctx->pc = 0x11DC84u;
label_11dc84:
    // 0x11dc84: 0xc047712  jal         func_11DC48
    ctx->pc = 0x11DC84u;
    SET_GPR_U32(ctx, 31, 0x11DC8Cu);
    ctx->pc = 0x11DC48u;
    if (runtime->hasFunction(0x11DC48u)) {
        auto targetFn = runtime->lookupFunction(0x11DC48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DC8Cu; }
        if (ctx->pc != 0x11DC8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DC48_0x11dc48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DC8Cu; }
        if (ctx->pc != 0x11DC8Cu) { return; }
    }
    ctx->pc = 0x11DC8Cu;
label_11dc8c:
    // 0x11dc8c: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11dc8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11dc90: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x11dc90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc94: 0x8c47a180  lw          $a3, -0x5E80($v0)
    ctx->pc = 0x11dc94u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943104)));
    // 0x11dc98: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x11dc98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dc9c: 0x200302d  daddu       $a2, $s0, $zero
    ctx->pc = 0x11dc9cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dca0: 0xc04509c  jal         func_114270
    ctx->pc = 0x11DCA0u;
    SET_GPR_U32(ctx, 31, 0x11DCA8u);
    ctx->pc = 0x11DCA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DCA0u;
            // 0x11dca4: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114270u;
    if (runtime->hasFunction(0x114270u)) {
        auto targetFn = runtime->lookupFunction(0x114270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCA8u; }
        if (ctx->pc != 0x11DCA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114270_0x114270(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCA8u; }
        if (ctx->pc != 0x11DCA8u) { return; }
    }
    ctx->pc = 0x11DCA8u;
label_11dca8:
    // 0x11dca8: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x11dca8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x11dcac: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x11dcacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11dcb0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11dcb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dcb4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11dcb4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dcb8: 0x3e00008  jr          $ra
    ctx->pc = 0x11DCB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DCBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11DCB8u;
            // 0x11dcbc: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DC84u: goto label_11dc84;
            case 0x11DC8Cu: goto label_11dc8c;
            case 0x11DCA8u: goto label_11dca8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DCC0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
