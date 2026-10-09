#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E138
// Address: 0x12e138 - 0x12e1d0
void sub_0012E138_0x12e138(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E138_0x12e138");
#endif

    switch (ctx->pc) {
        case 0x12e158u: goto label_12e158;
        default: break;
    }

    ctx->pc = 0x12e138u;

    // 0x12e138: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x12e138u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x12e13c: 0x24639ee0  addiu       $v1, $v1, -0x6120
    ctx->pc = 0x12e13cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294942432));
    // 0x12e140: 0x80620000  lb          $v0, 0x0($v1)
    ctx->pc = 0x12e140u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12e144: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x12E144u;
    {
        const bool branch_taken_0x12e144 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E144u;
            // 0x12e148: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e144) {
            ctx->pc = 0x12E188u;
            goto label_12e188;
        }
    }
    ctx->pc = 0x12E14Cu;
    // 0x12e14c: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x12e14cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e150: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x12e150u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e154: 0x0  nop
    ctx->pc = 0x12e154u;
    // NOP
label_12e158:
    // 0x12e158: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12e158u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x12e15c: 0x24c6000c  addiu       $a2, $a2, 0xC
    ctx->pc = 0x12e15cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 12));
    // 0x12e160: 0x28e40010  slti        $a0, $a3, 0x10
    ctx->pc = 0x12e160u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 7) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x12e164: 0x10800009  beqz        $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12E164u;
    {
        const bool branch_taken_0x12e164 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E164u;
            // 0x12e168: 0x24a5000c  addiu       $a1, $a1, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e164) {
            ctx->pc = 0x12E18Cu;
            goto label_12e18c;
        }
    }
    ctx->pc = 0x12E16Cu;
    // 0x12e16c: 0x80c20000  lb          $v0, 0x0($a2)
    ctx->pc = 0x12e16cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12e170: 0x0  nop
    ctx->pc = 0x12e170u;
    // NOP
    // 0x12e174: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x12E174u;
    {
        const bool branch_taken_0x12e174 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x12E178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E174u;
            // 0x12e178: 0xa0182d  daddu       $v1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e174) {
            ctx->pc = 0x12E158u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_12e158;
        }
    }
    ctx->pc = 0x12E17Cu;
    // 0x12e17c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x12E17Cu;
    {
        const bool branch_taken_0x12e17c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E17Cu;
            // 0x12e180: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e17c) {
            ctx->pc = 0x12E190u;
            goto label_12e190;
        }
    }
    ctx->pc = 0x12E184u;
    // 0x12e184: 0x0  nop
    ctx->pc = 0x12e184u;
    // NOP
label_12e188:
    // 0x12e188: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x12e188u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_12e18c:
    // 0x12e18c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x12e18cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12e190:
    // 0x12e190: 0x3e00008  jr          $ra
    ctx->pc = 0x12E190u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E194u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E190u;
            // 0x12e194: 0x64100b  movn        $v0, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E158u: goto label_12e158;
            case 0x12E188u: goto label_12e188;
            case 0x12E18Cu: goto label_12e18c;
            case 0x12E190u: goto label_12e190;
            case 0x12E1C0u: goto label_12e1c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E198u;
    // 0x12e198: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12e198u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12e19c: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x12e19cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e1a0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x12E1A0u;
    {
        const bool branch_taken_0x12e1a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12E1A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1A0u;
            // 0x12e1a4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12e1a0) {
            ctx->pc = 0x12E1C0u;
            goto label_12e1c0;
        }
    }
    ctx->pc = 0x12E1A8u;
    // 0x12e1a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e1a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e1ac: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12e1acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e1b0: 0x2406000c  addiu       $a2, $zero, 0xC
    ctx->pc = 0x12e1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x12e1b4: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x12e1b4u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x12e1b8: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12E1B8u;
    ctx->pc = 0x12E1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1B8u;
            // 0x12e1bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12E1C0u;
label_12e1c0:
    // 0x12e1c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12e1c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e1c4: 0x3e00008  jr          $ra
    ctx->pc = 0x12E1C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E1C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E1C4u;
            // 0x12e1c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E158u: goto label_12e158;
            case 0x12E188u: goto label_12e188;
            case 0x12E18Cu: goto label_12e18c;
            case 0x12E190u: goto label_12e190;
            case 0x12E1C0u: goto label_12e1c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E1CCu;
    // 0x12e1cc: 0x0  nop
    ctx->pc = 0x12e1ccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
