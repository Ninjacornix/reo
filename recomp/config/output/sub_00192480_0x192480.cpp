#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00192480
// Address: 0x192480 - 0x192500
void sub_00192480_0x192480(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00192480_0x192480");
#endif

    switch (ctx->pc) {
        case 0x1924a0u: goto label_1924a0;
        case 0x1924acu: goto label_1924ac;
        case 0x1924b8u: goto label_1924b8;
        default: break;
    }

    ctx->pc = 0x192480u;

    // 0x192480: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x192480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x192484: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x192484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x192488: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x192488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19248c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x19248cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192490: 0x8c910008  lw          $s1, 0x8($a0)
    ctx->pc = 0x192490u;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x192494: 0x8e24000c  lw          $a0, 0xC($s1)
    ctx->pc = 0x192494u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x192498: 0xc063714  jal         func_18DC50
    ctx->pc = 0x192498u;
    SET_GPR_U32(ctx, 31, 0x1924A0u);
    ctx->pc = 0x19249Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x192498u;
            // 0x19249c: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1924A0u; }
        if (ctx->pc != 0x1924A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1924A0u; }
        if (ctx->pc != 0x1924A0u) { return; }
    }
    ctx->pc = 0x1924A0u;
label_1924a0:
    // 0x1924a0: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1924a0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1924a4: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x1924A4u;
    SET_GPR_U32(ctx, 31, 0x1924ACu);
    ctx->pc = 0x1924A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1924A4u;
            // 0x1924a8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1924ACu; }
        if (ctx->pc != 0x1924ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1924ACu; }
        if (ctx->pc != 0x1924ACu) { return; }
    }
    ctx->pc = 0x1924ACu;
label_1924ac:
    // 0x1924ac: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1924acu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1924b0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1924B0u;
    {
        const bool branch_taken_0x1924b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1924B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1924B0u;
            // 0x1924b4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1924b0) {
            ctx->pc = 0x1924CCu;
            goto label_1924cc;
        }
    }
    ctx->pc = 0x1924B8u;
label_1924b8:
    // 0x1924b8: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x1924b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1924bc: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1924bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1924c0: 0xa0430000  sb          $v1, 0x0($v0)
    ctx->pc = 0x1924c0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1924c4: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1924c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1924c8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1924c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1924cc:
    // 0x1924cc: 0x8e23000c  lw          $v1, 0xC($s1)
    ctx->pc = 0x1924ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1924d0: 0xa3182b  sltu        $v1, $a1, $v1
    ctx->pc = 0x1924d0u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1924d4: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x1924D4u;
    {
        const bool branch_taken_0x1924d4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1924d4) {
            ctx->pc = 0x1924B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1924b8;
        }
    }
    ctx->pc = 0x1924DCu;
    // 0x1924dc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1924dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1924e0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1924e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1924e4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1924e4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1924e8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1924e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1924ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1924ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1924F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1924ECu;
            // 0x1924f0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1924A0u: goto label_1924a0;
            case 0x1924ACu: goto label_1924ac;
            case 0x1924B8u: goto label_1924b8;
            case 0x1924CCu: goto label_1924cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1924F4u;
    // 0x1924f4: 0x0  nop
    ctx->pc = 0x1924f4u;
    // NOP
    // 0x1924f8: 0x0  nop
    ctx->pc = 0x1924f8u;
    // NOP
    // 0x1924fc: 0x0  nop
    ctx->pc = 0x1924fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
