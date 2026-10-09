#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00159710
// Address: 0x159710 - 0x159780
void sub_00159710_0x159710(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00159710_0x159710");
#endif

    switch (ctx->pc) {
        case 0x15973cu: goto label_15973c;
        case 0x159754u: goto label_159754;
        case 0x15976cu: goto label_15976c;
        default: break;
    }

    ctx->pc = 0x159710u;

    // 0x159710: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x159710u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x159714: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x159714u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x159718: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x159718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x15971c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15971cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159720: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x159720u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x159724: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x159724u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x159728: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x159728u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x15972c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15972cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x159730: 0x8c620018  lw          $v0, 0x18($v1)
    ctx->pc = 0x159730u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x159734: 0x40f809  jalr        $v0
    ctx->pc = 0x159734u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x15973Cu);
        ctx->pc = 0x159738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159734u;
            // 0x159738: 0x3a0382d  daddu       $a3, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x15973Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15973Cu: goto label_15973c;
            case 0x159754u: goto label_159754;
            case 0x15976Cu: goto label_15976c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x15973Cu; }
            if (ctx->pc != 0x15973Cu) { return; }
        }
        }
    }
    ctx->pc = 0x15973Cu;
label_15973c:
    // 0x15973c: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15973cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x159740: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x159740u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x159744: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x159744u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x159748: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x159748u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x15974c: 0x40f809  jalr        $v0
    ctx->pc = 0x15974Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x159754u);
        ctx->pc = 0x159750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15974Cu;
            // 0x159750: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x159754u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15973Cu: goto label_15973c;
            case 0x159754u: goto label_159754;
            case 0x15976Cu: goto label_15976c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x159754u; }
            if (ctx->pc != 0x159754u) { return; }
        }
        }
    }
    ctx->pc = 0x159754u;
label_159754:
    // 0x159754: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x159754u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x159758: 0x28630004  slti        $v1, $v1, 0x4
    ctx->pc = 0x159758u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x15975c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15975Cu;
    {
        const bool branch_taken_0x15975c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x159760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15975Cu;
            // 0x159760: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15975c) {
            ctx->pc = 0x15976Cu;
            goto label_15976c;
        }
    }
    ctx->pc = 0x159764u;
    // 0x159764: 0xc05616e  jal         func_1585B8
    ctx->pc = 0x159764u;
    SET_GPR_U32(ctx, 31, 0x15976Cu);
    ctx->pc = 0x159768u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x159764u;
            // 0x159768: 0x8fa40000  lw          $a0, 0x0($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1585B8u;
    if (runtime->hasFunction(0x1585B8u)) {
        auto targetFn = runtime->lookupFunction(0x1585B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15976Cu; }
        if (ctx->pc != 0x15976Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001585B8_0x1585b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15976Cu; }
        if (ctx->pc != 0x15976Cu) { return; }
    }
    ctx->pc = 0x15976Cu;
label_15976c:
    // 0x15976c: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x15976cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x159770: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x159770u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x159774: 0x3e00008  jr          $ra
    ctx->pc = 0x159774u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x159778u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x159774u;
            // 0x159778: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15973Cu: goto label_15973c;
            case 0x159754u: goto label_159754;
            case 0x15976Cu: goto label_15976c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15977Cu;
    // 0x15977c: 0x0  nop
    ctx->pc = 0x15977cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
