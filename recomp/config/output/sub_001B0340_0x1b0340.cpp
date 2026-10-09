#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B0340
// Address: 0x1b0340 - 0x1b03b4
void sub_001B0340_0x1b0340(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B0340_0x1b0340");
#endif

    switch (ctx->pc) {
        case 0x1b0368u: goto label_1b0368;
        default: break;
    }

    ctx->pc = 0x1b0340u;

    // 0x1b0340: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b0340u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b0344: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b0344u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b0348: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b0348u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b034c: 0x90820002  lbu         $v0, 0x2($a0)
    ctx->pc = 0x1b034cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1b0350: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0350u;
    {
        const bool branch_taken_0x1b0350 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0354u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0350u;
            // 0x1b0354: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0350) {
            ctx->pc = 0x1B0360u;
            goto label_1b0360;
        }
    }
    ctx->pc = 0x1B0358u;
    // 0x1b0358: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1B0358u;
    {
        const bool branch_taken_0x1b0358 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B035Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0358u;
            // 0x1b035c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0358) {
            ctx->pc = 0x1B03A4u;
            goto label_1b03a4;
        }
    }
    ctx->pc = 0x1B0360u;
label_1b0360:
    // 0x1b0360: 0xc06c0b4  jal         func_1B02D0
    ctx->pc = 0x1B0360u;
    SET_GPR_U32(ctx, 31, 0x1B0368u);
    ctx->pc = 0x1B02D0u;
    if (runtime->hasFunction(0x1B02D0u)) {
        auto targetFn = runtime->lookupFunction(0x1B02D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0368u; }
        if (ctx->pc != 0x1B0368u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B0368u; }
        if (ctx->pc != 0x1B0368u) { return; }
    }
    ctx->pc = 0x1B0368u;
label_1b0368:
    // 0x1b0368: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b0368u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b036c: 0x14440006  bne         $v0, $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B036Cu;
    {
        const bool branch_taken_0x1b036c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1B0370u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B036Cu;
            // 0x1b0370: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b036c) {
            ctx->pc = 0x1B0388u;
            goto label_1b0388;
        }
    }
    ctx->pc = 0x1B0374u;
    // 0x1b0374: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1b0374u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b0378: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1B0378u;
    {
        const bool branch_taken_0x1b0378 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B037Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0378u;
            // 0x1b037c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0378) {
            ctx->pc = 0x1B03A4u;
            goto label_1b03a4;
        }
    }
    ctx->pc = 0x1B0380u;
    // 0x1b0380: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1B0380u;
    {
        const bool branch_taken_0x1b0380 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B0384u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0380u;
            // 0x1b0384: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0380) {
            ctx->pc = 0x1B03A4u;
            goto label_1b03a4;
        }
    }
    ctx->pc = 0x1B0388u;
label_1b0388:
    // 0x1b0388: 0x92020003  lbu         $v0, 0x3($s0)
    ctx->pc = 0x1b0388u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x1b038c: 0x9023aded  lbu         $v1, -0x5213($at)
    ctx->pc = 0x1b038cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946285)));
    // 0x1b0390: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0390u;
    {
        const bool branch_taken_0x1b0390 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B0394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0390u;
            // 0x1b0394: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0390) {
            ctx->pc = 0x1B03A0u;
            goto label_1b03a0;
        }
    }
    ctx->pc = 0x1B0398u;
    // 0x1b0398: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1B0398u;
    {
        const bool branch_taken_0x1b0398 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B039Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B0398u;
            // 0x1b039c: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b0398) {
            ctx->pc = 0x1B03A8u;
            goto label_1b03a8;
        }
    }
    ctx->pc = 0x1B03A0u;
label_1b03a0:
    // 0x1b03a0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1b03a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1b03a4:
    // 0x1b03a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b03a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1b03a8:
    // 0x1b03a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b03a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b03ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1B03ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B03B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B03ACu;
            // 0x1b03b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B0360u: goto label_1b0360;
            case 0x1B0368u: goto label_1b0368;
            case 0x1B0388u: goto label_1b0388;
            case 0x1B03A0u: goto label_1b03a0;
            case 0x1B03A4u: goto label_1b03a4;
            case 0x1B03A8u: goto label_1b03a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B03B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
