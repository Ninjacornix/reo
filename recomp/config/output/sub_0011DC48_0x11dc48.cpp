#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011DC48
// Address: 0x11dc48 - 0x11dd08
void sub_0011DC48_0x11dc48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011DC48_0x11dc48");
#endif

    switch (ctx->pc) {
        case 0x11dc84u: goto label_11dc84;
        case 0x11dc8cu: goto label_11dc8c;
        case 0x11dca8u: goto label_11dca8;
        case 0x11dcd8u: goto label_11dcd8;
        case 0x11dce0u: goto label_11dce0;
        default: break;
    }

    ctx->pc = 0x11dc48u;

label_11dc48:
    // 0x11dc48: 0x8047424  j           func_11D090
    ctx->pc = 0x11DC48u;
    ctx->pc = 0x11D090u;
    if (runtime->hasFunction(0x11D090u)) {
        auto targetFn = runtime->lookupFunction(0x11D090u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D090_0x11d090(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11DC50u;
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
    goto label_11dc48;
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
    {
        auto targetFn = runtime->lookupFunction(0x114270u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
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
            case 0x11DC48u: goto label_11dc48;
            case 0x11DC84u: goto label_11dc84;
            case 0x11DC8Cu: goto label_11dc8c;
            case 0x11DCA8u: goto label_11dca8;
            case 0x11DCD8u: goto label_11dcd8;
            case 0x11DCE0u: goto label_11dce0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DCC0u;
    // 0x11dcc0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11dcc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11dcc4: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11dcc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11dcc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11dcc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11dccc: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11dcccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11dcd0: 0xc0476cc  jal         func_11DB30
    ctx->pc = 0x11DCD0u;
    SET_GPR_U32(ctx, 31, 0x11DCD8u);
    ctx->pc = 0x11DCD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DCD0u;
            // 0x11dcd4: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DB30u;
    if (runtime->hasFunction(0x11DB30u)) {
        auto targetFn = runtime->lookupFunction(0x11DB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCD8u; }
        if (ctx->pc != 0x11DCD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DB30_0x11db30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DCD8u; }
        if (ctx->pc != 0x11DCD8u) { return; }
    }
    ctx->pc = 0x11DCD8u;
label_11dcd8:
    // 0x11dcd8: 0xc047712  jal         func_11DC48
    ctx->pc = 0x11DCD8u;
    SET_GPR_U32(ctx, 31, 0x11DCE0u);
    ctx->pc = 0x11DCDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DCD8u;
            // 0x11dcdc: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11DC48u;
    goto label_11dc48;
    ctx->pc = 0x11DCE0u;
label_11dce0:
    // 0x11dce0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x11dce0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x11dce4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11dce4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dce8: 0x8c46a180  lw          $a2, -0x5E80($v0)
    ctx->pc = 0x11dce8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294943104)));
    // 0x11dcec: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x11dcecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11dcf0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11dcf0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11dcf4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11dcf4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11dcf8: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x11dcf8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x11dcfc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11dcfcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11dd00: 0x8045098  j           func_114260
    ctx->pc = 0x11DD00u;
    ctx->pc = 0x11DD04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11DD00u;
            // 0x11dd04: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114260u;
    if (runtime->hasFunction(0x114260u)) {
        auto targetFn = runtime->lookupFunction(0x114260u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114260_0x114260(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x11DD08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
