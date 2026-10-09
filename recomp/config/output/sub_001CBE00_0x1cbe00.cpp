#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBE00
// Address: 0x1cbe00 - 0x1cbea0
void sub_001CBE00_0x1cbe00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBE00_0x1cbe00");
#endif

    switch (ctx->pc) {
        case 0x1cbe60u: goto label_1cbe60;
        default: break;
    }

    ctx->pc = 0x1cbe00u;

    // 0x1cbe00: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cbe00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cbe04: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cbe08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cbe0c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbe0cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbe10: 0x8c23d9f8  lw          $v1, -0x2608($at)
    ctx->pc = 0x1cbe10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbe14: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1CBE14u;
    {
        const bool branch_taken_0x1cbe14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBE14u;
            // 0x1cbe18: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbe14) {
            ctx->pc = 0x1CBE90u;
            goto label_1cbe90;
        }
    }
    ctx->pc = 0x1CBE1Cu;
    // 0x1cbe1c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe20: 0x8c23da00  lw          $v1, -0x2600($at)
    ctx->pc = 0x1cbe20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbe24: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBE24u;
    {
        const bool branch_taken_0x1cbe24 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbe24) {
            ctx->pc = 0x1CBE34u;
            goto label_1cbe34;
        }
    }
    ctx->pc = 0x1CBE2Cu;
    // 0x1cbe2c: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CBE2Cu;
    {
        const bool branch_taken_0x1cbe2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBE2Cu;
            // 0x1cbe30: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbe2c) {
            ctx->pc = 0x1CBE94u;
            goto label_1cbe94;
        }
    }
    ctx->pc = 0x1CBE34u;
label_1cbe34:
    // 0x1cbe34: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbe34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbe38: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cbe38u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe3c: 0x96060004  lhu         $a2, 0x4($s0)
    ctx->pc = 0x1cbe3cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbe40: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1cbe40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1cbe44: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbe44u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbe48: 0x863821  addu        $a3, $a0, $a2
    ctx->pc = 0x1cbe48u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1cbe4c: 0xe3082b  sltu        $at, $a3, $v1
    ctx->pc = 0x1cbe4cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1cbe50: 0x1020000f  beqz        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1CBE50u;
    {
        const bool branch_taken_0x1cbe50 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbe50) {
            ctx->pc = 0x1CBE90u;
            goto label_1cbe90;
        }
    }
    ctx->pc = 0x1CBE58u;
    // 0x1cbe58: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CBE58u;
    SET_GPR_U32(ctx, 31, 0x1CBE60u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBE60u; }
        if (ctx->pc != 0x1CBE60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBE60u; }
        if (ctx->pc != 0x1CBE60u) { return; }
    }
    ctx->pc = 0x1CBE60u;
label_1cbe60:
    // 0x1cbe60: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbe60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbe64: 0x96050004  lhu         $a1, 0x4($s0)
    ctx->pc = 0x1cbe64u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbe68: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbe68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbe6c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe6cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe70: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1cbe70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1cbe74: 0x8c23d9f0  lw          $v1, -0x2610($at)
    ctx->pc = 0x1cbe74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbe78: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbe78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbe7c: 0xac245ff0  sw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbe7cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 4));
    // 0x1cbe80: 0x96040004  lhu         $a0, 0x4($s0)
    ctx->pc = 0x1cbe80u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbe84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbe84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbe88: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cbe88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cbe8c: 0xac23d9f0  sw          $v1, -0x2610($at)
    ctx->pc = 0x1cbe8cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 3));
label_1cbe90:
    // 0x1cbe90: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cbe90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1cbe94:
    // 0x1cbe94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbe94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbe98: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBE98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBE9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBE98u;
            // 0x1cbe9c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBE34u: goto label_1cbe34;
            case 0x1CBE60u: goto label_1cbe60;
            case 0x1CBE90u: goto label_1cbe90;
            case 0x1CBE94u: goto label_1cbe94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBEA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
