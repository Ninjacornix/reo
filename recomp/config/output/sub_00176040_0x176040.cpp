#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176040
// Address: 0x176040 - 0x1760c0
void sub_00176040_0x176040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176040_0x176040");
#endif

    switch (ctx->pc) {
        case 0x17605cu: goto label_17605c;
        case 0x176070u: goto label_176070;
        case 0x176090u: goto label_176090;
        default: break;
    }

    ctx->pc = 0x176040u;

    // 0x176040: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x176040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x176044: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x176044u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x176048: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x176048u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x17604c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x17604cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x176050: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x176050u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x176054: 0xc05d58a  jal         func_175628
    ctx->pc = 0x176054u;
    SET_GPR_U32(ctx, 31, 0x17605Cu);
    ctx->pc = 0x176058u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176054u;
            // 0x176058: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17605Cu; }
        if (ctx->pc != 0x17605Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17605Cu; }
        if (ctx->pc != 0x17605Cu) { return; }
    }
    ctx->pc = 0x17605Cu;
label_17605c:
    // 0x17605c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17605cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176060: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x176060u;
    {
        const bool branch_taken_0x176060 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x176064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176060u;
            // 0x176064: 0x24050033  addiu       $a1, $zero, 0x33 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 51));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176060) {
            ctx->pc = 0x1760ACu;
            goto label_1760ac;
        }
    }
    ctx->pc = 0x176068u;
    // 0x176068: 0xc05d58a  jal         func_175628
    ctx->pc = 0x176068u;
    SET_GPR_U32(ctx, 31, 0x176070u);
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176070u; }
        if (ctx->pc != 0x176070u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176070u; }
        if (ctx->pc != 0x176070u) { return; }
    }
    ctx->pc = 0x176070u;
label_176070:
    // 0x176070: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x176070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176074: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x176074u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176078: 0x24850cc0  addiu       $a1, $a0, 0xCC0
    ctx->pc = 0x176078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 3264));
    // 0x17607c: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x17607cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x176080: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x176080u;
    {
        const bool branch_taken_0x176080 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x176084u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176080u;
            // 0x176084: 0x27a70004  addiu       $a3, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x176080) {
            ctx->pc = 0x1760ACu;
            goto label_1760ac;
        }
    }
    ctx->pc = 0x176088u;
    // 0x176088: 0xc05d7da  jal         func_175F68
    ctx->pc = 0x176088u;
    SET_GPR_U32(ctx, 31, 0x176090u);
    ctx->pc = 0x175F68u;
    if (runtime->hasFunction(0x175F68u)) {
        auto targetFn = runtime->lookupFunction(0x175F68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176090u; }
        if (ctx->pc != 0x176090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175F68_0x175f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176090u; }
        if (ctx->pc != 0x176090u) { return; }
    }
    ctx->pc = 0x176090u;
label_176090:
    // 0x176090: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x176090u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x176094: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x176094u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176098: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x176098u;
    {
        const bool branch_taken_0x176098 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x176098) {
            ctx->pc = 0x17609Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x176098u;
            // 0x17609c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1760A0u;
            goto label_1760a0;
        }
    }
    ctx->pc = 0x1760A0u;
label_1760a0:
    // 0x1760a0: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x1760a0u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1760a4: 0x1012  mflo        $v0
    ctx->pc = 0x1760a4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1760a8: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1760a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
label_1760ac:
    // 0x1760ac: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1760acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1760b0: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1760b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1760b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1760b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1760b8: 0x3e00008  jr          $ra
    ctx->pc = 0x1760B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1760BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1760B8u;
            // 0x1760bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17605Cu: goto label_17605c;
            case 0x176070u: goto label_176070;
            case 0x176090u: goto label_176090;
            case 0x1760A0u: goto label_1760a0;
            case 0x1760ACu: goto label_1760ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1760C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
