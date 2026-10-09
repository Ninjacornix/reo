#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001410C8
// Address: 0x1410c8 - 0x141158
void sub_001410C8_0x1410c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001410C8_0x1410c8");
#endif

    switch (ctx->pc) {
        case 0x1410e0u: goto label_1410e0;
        case 0x141108u: goto label_141108;
        case 0x141110u: goto label_141110;
        case 0x141138u: goto label_141138;
        default: break;
    }

    ctx->pc = 0x1410c8u;

    // 0x1410c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1410c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1410cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1410ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1410d0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1410d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1410d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1410d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1410d8: 0x16000009  bnez        $s0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1410D8u;
    {
        const bool branch_taken_0x1410d8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1410DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1410D8u;
            // 0x1410dc: 0xffbf0010  sd          $ra, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1410d8) {
            ctx->pc = 0x141100u;
            goto label_141100;
        }
    }
    ctx->pc = 0x1410E0u;
label_1410e0:
    // 0x1410e0: 0x0  nop
    ctx->pc = 0x1410e0u;
    // NOP
    // 0x1410e4: 0x0  nop
    ctx->pc = 0x1410e4u;
    // NOP
    // 0x1410e8: 0x0  nop
    ctx->pc = 0x1410e8u;
    // NOP
    // 0x1410ec: 0x0  nop
    ctx->pc = 0x1410ecu;
    // NOP
    // 0x1410f0: 0x0  nop
    ctx->pc = 0x1410f0u;
    // NOP
    // 0x1410f4: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x1410F4u;
    {
        const bool branch_taken_0x1410f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1410f4) {
            ctx->pc = 0x1410E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1410e0;
        }
    }
    ctx->pc = 0x1410FCu;
    // 0x1410fc: 0x0  nop
    ctx->pc = 0x1410fcu;
    // NOP
label_141100:
    // 0x141100: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x141100u;
    SET_GPR_U32(ctx, 31, 0x141108u);
    ctx->pc = 0x141104u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141100u;
            // 0x141104: 0x8e110000  lw          $s1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141108u; }
        if (ctx->pc != 0x141108u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x141108u; }
        if (ctx->pc != 0x141108u) { return; }
    }
    ctx->pc = 0x141108u;
label_141108:
    // 0x141108: 0x5a20000f  blezl       $s1, . + 4 + (0xF << 2)
    ctx->pc = 0x141108u;
    {
        const bool branch_taken_0x141108 = (GPR_S64(ctx, 17) <= 0);
        if (branch_taken_0x141108) {
            ctx->pc = 0x14110Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141108u;
            // 0x14110c: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x141148u;
            goto label_141148;
        }
    }
    ctx->pc = 0x141110u;
label_141110:
    // 0x141110: 0x82020010  lb          $v0, 0x10($s0)
    ctx->pc = 0x141110u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x141114: 0x54400009  bnel        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x141114u;
    {
        const bool branch_taken_0x141114 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x141114) {
            ctx->pc = 0x141118u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x141114u;
            // 0x141118: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x14113Cu;
            goto label_14113c;
        }
    }
    ctx->pc = 0x14111Cu;
    // 0x14111c: 0x8e020014  lw          $v0, 0x14($s0)
    ctx->pc = 0x14111cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x141120: 0x26060018  addiu       $a2, $s0, 0x18
    ctx->pc = 0x141120u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x141124: 0x8c440004  lw          $a0, 0x4($v0)
    ctx->pc = 0x141124u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x141128: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x141128u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14112c: 0x8c620020  lw          $v0, 0x20($v1)
    ctx->pc = 0x14112cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32)));
    // 0x141130: 0x40f809  jalr        $v0
    ctx->pc = 0x141130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x141138u);
        ctx->pc = 0x141134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x141130u;
            // 0x141134: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x141138u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1410E0u: goto label_1410e0;
            case 0x141100u: goto label_141100;
            case 0x141108u: goto label_141108;
            case 0x141110u: goto label_141110;
            case 0x141138u: goto label_141138;
            case 0x14113Cu: goto label_14113c;
            case 0x141148u: goto label_141148;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x141138u; }
            if (ctx->pc != 0x141138u) { return; }
        }
        }
    }
    ctx->pc = 0x141138u;
label_141138:
    // 0x141138: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x141138u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_14113c:
    // 0x14113c: 0x1620fff4  bnez        $s1, . + 4 + (-0xC << 2)
    ctx->pc = 0x14113Cu;
    {
        const bool branch_taken_0x14113c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x141140u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14113Cu;
            // 0x141140: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14113c) {
            ctx->pc = 0x141110u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_141110;
        }
    }
    ctx->pc = 0x141144u;
    // 0x141144: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x141144u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_141148:
    // 0x141148: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x141148u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x14114c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x14114cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x141150: 0x804fc9c  j           func_13F270
    ctx->pc = 0x141150u;
    ctx->pc = 0x141154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x141150u;
            // 0x141154: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x141158u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
