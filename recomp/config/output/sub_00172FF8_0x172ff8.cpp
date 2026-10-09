#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00172FF8
// Address: 0x172ff8 - 0x1730b0
void sub_00172FF8_0x172ff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00172FF8_0x172ff8");
#endif

    switch (ctx->pc) {
        case 0x173044u: goto label_173044;
        case 0x173088u: goto label_173088;
        default: break;
    }

    ctx->pc = 0x172ff8u;

    // 0x172ff8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x172ff8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x172ffc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x172ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173000: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x173000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x173004: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x173004u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173008: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x173008u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17300c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17300cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173010: 0x8e221b38  lw          $v0, 0x1B38($s1)
    ctx->pc = 0x173010u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 6968)));
    // 0x173014: 0x280c0  sll         $s0, $v0, 3
    ctx->pc = 0x173014u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x173018: 0x2028023  subu        $s0, $s0, $v0
    ctx->pc = 0x173018u;
    SET_GPR_S32(ctx, 16, (int32_t)SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x17301c: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x17301cu;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x173020: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x173020u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x173024: 0x108080  sll         $s0, $s0, 2
    ctx->pc = 0x173024u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x173028: 0x2308021  addu        $s0, $s1, $s0
    ctx->pc = 0x173028u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x17302c: 0x26101150  addiu       $s0, $s0, 0x1150
    ctx->pc = 0x17302cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4432));
    // 0x173030: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x173030u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x173034: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x173034u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x173038: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x173038u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x17303c: 0x40f809  jalr        $v0
    ctx->pc = 0x17303Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x173044u);
        ctx->pc = 0x173040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17303Cu;
            // 0x173040: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x173044u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173044u: goto label_173044;
            case 0x173064u: goto label_173064;
            case 0x173088u: goto label_173088;
            case 0x173098u: goto label_173098;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x173044u; }
            if (ctx->pc != 0x173044u) { return; }
        }
        }
    }
    ctx->pc = 0x173044u;
label_173044:
    // 0x173044: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x173044u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173048: 0x8e06000c  lw          $a2, 0xC($s0)
    ctx->pc = 0x173048u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x17304c: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x17304cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173050: 0x24030064  addiu       $v1, $zero, 0x64
    ctx->pc = 0x173050u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x173054: 0x24050046  addiu       $a1, $zero, 0x46
    ctx->pc = 0x173054u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x173058: 0x61080  sll         $v0, $a2, 2
    ctx->pc = 0x173058u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x17305c: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x17305Cu;
    {
        const bool branch_taken_0x17305c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x17305c) {
            ctx->pc = 0x173060u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x17305Cu;
            // 0x173060: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x173064u;
            goto label_173064;
        }
    }
    ctx->pc = 0x173064u;
label_173064:
    // 0x173064: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x173064u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x173068: 0x21100  sll         $v0, $v0, 4
    ctx->pc = 0x173068u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 4));
    // 0x17306c: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x17306cu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x173070: 0x1012  mflo        $v0
    ctx->pc = 0x173070u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x173074: 0x242102a  slt         $v0, $s2, $v0
    ctx->pc = 0x173074u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x173078: 0x50400007  beql        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x173078u;
    {
        const bool branch_taken_0x173078 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x173078) {
            ctx->pc = 0x17307Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x173078u;
            // 0x17307c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x173098u;
            goto label_173098;
        }
    }
    ctx->pc = 0x173080u;
    // 0x173080: 0xc05d58a  jal         func_175628
    ctx->pc = 0x173080u;
    SET_GPR_U32(ctx, 31, 0x173088u);
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173088u; }
        if (ctx->pc != 0x173088u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173088u; }
        if (ctx->pc != 0x173088u) { return; }
    }
    ctx->pc = 0x173088u;
label_173088:
    // 0x173088: 0x242182a  slt         $v1, $s2, $v0
    ctx->pc = 0x173088u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x17308c: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x17308Cu;
    {
        const bool branch_taken_0x17308c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x173090u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17308Cu;
            // 0x173090: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17308c) {
            ctx->pc = 0x173098u;
            goto label_173098;
        }
    }
    ctx->pc = 0x173094u;
    // 0x173094: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x173094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_173098:
    // 0x173098: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173098u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17309c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17309cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1730a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1730a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1730a4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1730a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1730a8: 0x3e00008  jr          $ra
    ctx->pc = 0x1730A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1730ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1730A8u;
            // 0x1730ac: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173044u: goto label_173044;
            case 0x173064u: goto label_173064;
            case 0x173088u: goto label_173088;
            case 0x173098u: goto label_173098;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1730B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
