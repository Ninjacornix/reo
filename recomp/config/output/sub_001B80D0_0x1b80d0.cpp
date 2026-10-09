#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B80D0
// Address: 0x1b80d0 - 0x1b8170
void sub_001B80D0_0x1b80d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B80D0_0x1b80d0");
#endif

    switch (ctx->pc) {
        case 0x1b8158u: goto label_1b8158;
        case 0x1b8164u: goto label_1b8164;
        default: break;
    }

    ctx->pc = 0x1b80d0u;

label_1b80d0:
    // 0x1b80d0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b80d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b80d4: 0x4363c  dsll32      $a2, $a0, 24
    ctx->pc = 0x1b80d4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 24));
    // 0x1b80d8: 0x902343f8  lbu         $v1, 0x43F8($at)
    ctx->pc = 0x1b80d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17400)));
    // 0x1b80dc: 0x6363f  dsra32      $a2, $a2, 24
    ctx->pc = 0x1b80dcu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 24));
    // 0x1b80e0: 0x10c30006  beq         $a2, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B80E0u;
    {
        const bool branch_taken_0x1b80e0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B80E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B80E0u;
            // 0x1b80e4: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b80e0) {
            ctx->pc = 0x1B80FCu;
            goto label_1b80fc;
        }
    }
    ctx->pc = 0x1B80E8u;
    // 0x1b80e8: 0x802347f0  lb          $v1, 0x47F0($at)
    ctx->pc = 0x1b80e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18416)));
    // 0x1b80ec: 0x10660003  beq         $v1, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B80ECu;
    {
        const bool branch_taken_0x1b80ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 6));
        if (branch_taken_0x1b80ec) {
            ctx->pc = 0x1B80FCu;
            goto label_1b80fc;
        }
    }
    ctx->pc = 0x1B80F4u;
    // 0x1b80f4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b80f4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b80f8: 0xa02447f0  sb          $a0, 0x47F0($at)
    ctx->pc = 0x1b80f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18416), (uint8_t)GPR_U32(ctx, 4));
label_1b80fc:
    // 0x1b80fc: 0x5263c  dsll32      $a0, $a1, 24
    ctx->pc = 0x1b80fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) << (32 + 24));
    // 0x1b8100: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1b8100u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1b8104: 0x4263f  dsra32      $a0, $a0, 24
    ctx->pc = 0x1b8104u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 24));
    // 0x1b8108: 0x10830009  beq         $a0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1B8108u;
    {
        const bool branch_taken_0x1b8108 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1B810Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8108u;
            // 0x1b810c: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8108) {
            ctx->pc = 0x1B8130u;
            goto label_1b8130;
        }
    }
    ctx->pc = 0x1B8110u;
    // 0x1b8110: 0x902343f9  lbu         $v1, 0x43F9($at)
    ctx->pc = 0x1b8110u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17401)));
    // 0x1b8114: 0x10830006  beq         $a0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B8114u;
    {
        const bool branch_taken_0x1b8114 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1b8114) {
            ctx->pc = 0x1B8130u;
            goto label_1b8130;
        }
    }
    ctx->pc = 0x1B811Cu;
    // 0x1b811c: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1b811cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1b8120: 0x802347f8  lb          $v1, 0x47F8($at)
    ctx->pc = 0x1b8120u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 18424)));
    // 0x1b8124: 0x10640002  beq         $v1, $a0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1B8124u;
    {
        const bool branch_taken_0x1b8124 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1B8128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8124u;
            // 0x1b8128: 0x3c010023  lui         $at, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b8124) {
            ctx->pc = 0x1B8130u;
            goto label_1b8130;
        }
    }
    ctx->pc = 0x1B812Cu;
    // 0x1b812c: 0xa02547f8  sb          $a1, 0x47F8($at)
    ctx->pc = 0x1b812cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 18424), (uint8_t)GPR_U32(ctx, 5));
label_1b8130:
    // 0x1b8130: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B80D0u: goto label_1b80d0;
            case 0x1B80FCu: goto label_1b80fc;
            case 0x1B8130u: goto label_1b8130;
            case 0x1B8158u: goto label_1b8158;
            case 0x1B8164u: goto label_1b8164;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8138u;
    // 0x1b8138: 0x0  nop
    ctx->pc = 0x1b8138u;
    // NOP
    // 0x1b813c: 0x0  nop
    ctx->pc = 0x1b813cu;
    // NOP
    // 0x1b8140: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b8140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b8144: 0x3c040058  lui         $a0, 0x58
    ctx->pc = 0x1b8144u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)88 << 16));
    // 0x1b8148: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b8148u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b814c: 0x2484f1f0  addiu       $a0, $a0, -0xE10
    ctx->pc = 0x1b814cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294963696));
    // 0x1b8150: 0xc06dfd0  jal         func_1B7F40
    ctx->pc = 0x1B8150u;
    SET_GPR_U32(ctx, 31, 0x1B8158u);
    ctx->pc = 0x1B8154u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8150u;
            // 0x1b8154: 0x24050004  addiu       $a1, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B7F40u;
    if (runtime->hasFunction(0x1B7F40u)) {
        auto targetFn = runtime->lookupFunction(0x1B7F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8158u; }
        if (ctx->pc != 0x1B8158u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B7F40_0x1b7f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B8158u; }
        if (ctx->pc != 0x1B8158u) { return; }
    }
    ctx->pc = 0x1B8158u;
label_1b8158:
    // 0x1b8158: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1b8158u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1b815c: 0xc06e034  jal         func_1B80D0
    ctx->pc = 0x1B815Cu;
    SET_GPR_U32(ctx, 31, 0x1B8164u);
    ctx->pc = 0x1B8160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B815Cu;
            // 0x1b8160: 0x2405ffff  addiu       $a1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B80D0u;
    goto label_1b80d0;
    ctx->pc = 0x1B8164u;
label_1b8164:
    // 0x1b8164: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b8164u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b8168: 0x3e00008  jr          $ra
    ctx->pc = 0x1B8168u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B816Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B8168u;
            // 0x1b816c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B80D0u: goto label_1b80d0;
            case 0x1B80FCu: goto label_1b80fc;
            case 0x1B8130u: goto label_1b8130;
            case 0x1B8158u: goto label_1b8158;
            case 0x1B8164u: goto label_1b8164;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B8170u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
