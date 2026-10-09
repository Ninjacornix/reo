#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166158
// Address: 0x166158 - 0x1661e8
void sub_00166158_0x166158(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166158_0x166158");
#endif

    switch (ctx->pc) {
        case 0x16617cu: goto label_16617c;
        case 0x1661b0u: goto label_1661b0;
        case 0x1661d0u: goto label_1661d0;
        default: break;
    }

    ctx->pc = 0x166158u;

    // 0x166158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x166158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16615c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16615cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166160: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x166160u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166164: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x166164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x166168: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x166168u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16616c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16616cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x166170: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x166170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x166174: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x166174u;
    SET_GPR_U32(ctx, 31, 0x16617Cu);
    ctx->pc = 0x166178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166174u;
            // 0x166178: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16617Cu; }
        if (ctx->pc != 0x16617Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16617Cu; }
        if (ctx->pc != 0x16617Cu) { return; }
    }
    ctx->pc = 0x16617Cu;
label_16617c:
    // 0x16617c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16617cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x166180: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166184: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x166184u;
    {
        const bool branch_taken_0x166184 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x166188u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x166184u;
            // 0x166188: 0x34a501a1  ori         $a1, $a1, 0x1A1 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)417);
        ctx->in_delay_slot = false;
        if (branch_taken_0x166184) {
            ctx->pc = 0x1661A8u;
            goto label_1661a8;
        }
    }
    ctx->pc = 0x16618Cu;
    // 0x16618c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16618cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166190: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x166190u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166194: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x166194u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166198: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x166198u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16619c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16619cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1661a0: 0x805a704  j           func_169C10
    ctx->pc = 0x1661A0u;
    ctx->pc = 0x1661A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1661A0u;
            // 0x1661a4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1661A8u;
label_1661a8:
    // 0x1661a8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1661A8u;
    SET_GPR_U32(ctx, 31, 0x1661B0u);
    ctx->pc = 0x1661ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1661A8u;
            // 0x1661ac: 0x24050006  addiu       $a1, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1661B0u; }
        if (ctx->pc != 0x1661B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1661B0u; }
        if (ctx->pc != 0x1661B0u) { return; }
    }
    ctx->pc = 0x1661B0u;
label_1661b0:
    // 0x1661b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1661b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1661b4: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1661b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1661b8: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1661B8u;
    {
        const bool branch_taken_0x1661b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1661BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1661B8u;
            // 0x1661bc: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1661b8) {
            ctx->pc = 0x1661D0u;
            goto label_1661d0;
        }
    }
    ctx->pc = 0x1661C0u;
    // 0x1661c0: 0x8e021c84  lw          $v0, 0x1C84($s0)
    ctx->pc = 0x1661c0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 7300)));
    // 0x1661c4: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1661c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1661c8: 0x60f809  jalr        $v1
    ctx->pc = 0x1661C8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1661D0u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1661D0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1661D0u; }
            if (ctx->pc != 0x1661D0u) { return; }
        }
        }
    }
    ctx->pc = 0x1661D0u;
label_1661d0:
    // 0x1661d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1661d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1661d4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1661d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1661d8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1661d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1661dc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1661dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1661e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1661E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1661E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1661E0u;
            // 0x1661e4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16617Cu: goto label_16617c;
            case 0x1661A8u: goto label_1661a8;
            case 0x1661B0u: goto label_1661b0;
            case 0x1661D0u: goto label_1661d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1661E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
