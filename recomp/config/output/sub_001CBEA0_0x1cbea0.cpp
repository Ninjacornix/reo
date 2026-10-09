#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CBEA0
// Address: 0x1cbea0 - 0x1cbf40
void sub_001CBEA0_0x1cbea0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CBEA0_0x1cbea0");
#endif

    switch (ctx->pc) {
        case 0x1cbf00u: goto label_1cbf00;
        default: break;
    }

    ctx->pc = 0x1cbea0u;

    // 0x1cbea0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cbea0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cbea4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbea4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbea8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cbea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cbeac: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cbeacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cbeb0: 0x8c23d9f8  lw          $v1, -0x2608($at)
    ctx->pc = 0x1cbeb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957560)));
    // 0x1cbeb4: 0x1460001e  bnez        $v1, . + 4 + (0x1E << 2)
    ctx->pc = 0x1CBEB4u;
    {
        const bool branch_taken_0x1cbeb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CBEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBEB4u;
            // 0x1cbeb8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbeb4) {
            ctx->pc = 0x1CBF30u;
            goto label_1cbf30;
        }
    }
    ctx->pc = 0x1CBEBCu;
    // 0x1cbebc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbebcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbec0: 0x8c23da00  lw          $v1, -0x2600($at)
    ctx->pc = 0x1cbec0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957568)));
    // 0x1cbec4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CBEC4u;
    {
        const bool branch_taken_0x1cbec4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbec4) {
            ctx->pc = 0x1CBED4u;
            goto label_1cbed4;
        }
    }
    ctx->pc = 0x1CBECCu;
    // 0x1cbecc: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CBECCu;
    {
        const bool branch_taken_0x1cbecc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CBED0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBECCu;
            // 0x1cbed0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cbecc) {
            ctx->pc = 0x1CBF34u;
            goto label_1cbf34;
        }
    }
    ctx->pc = 0x1CBED4u;
label_1cbed4:
    // 0x1cbed4: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbed4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbed8: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1cbed8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1cbedc: 0x96060004  lhu         $a2, 0x4($s0)
    ctx->pc = 0x1cbedcu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbee0: 0x24630a20  addiu       $v1, $v1, 0xA20
    ctx->pc = 0x1cbee0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2592));
    // 0x1cbee4: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbee4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbee8: 0x863821  addu        $a3, $a0, $a2
    ctx->pc = 0x1cbee8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1cbeec: 0xe3082b  sltu        $at, $a3, $v1
    ctx->pc = 0x1cbeecu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1cbef0: 0x1020000f  beqz        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1CBEF0u;
    {
        const bool branch_taken_0x1cbef0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cbef0) {
            ctx->pc = 0x1CBF30u;
            goto label_1cbf30;
        }
    }
    ctx->pc = 0x1CBEF8u;
    // 0x1cbef8: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1CBEF8u;
    SET_GPR_U32(ctx, 31, 0x1CBF00u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF00u; }
        if (ctx->pc != 0x1CBF00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CBF00u; }
        if (ctx->pc != 0x1CBF00u) { return; }
    }
    ctx->pc = 0x1CBF00u;
label_1cbf00:
    // 0x1cbf00: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbf00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbf04: 0x96050004  lhu         $a1, 0x4($s0)
    ctx->pc = 0x1cbf04u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbf08: 0x8c245ff0  lw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbf08u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 24560)));
    // 0x1cbf0c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf10: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1cbf10u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1cbf14: 0x8c23d9f0  lw          $v1, -0x2610($at)
    ctx->pc = 0x1cbf14u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294957552)));
    // 0x1cbf18: 0x3c010023  lui         $at, 0x23
    ctx->pc = 0x1cbf18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)35 << 16));
    // 0x1cbf1c: 0xac245ff0  sw          $a0, 0x5FF0($at)
    ctx->pc = 0x1cbf1cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 24560), GPR_U32(ctx, 4));
    // 0x1cbf20: 0x96040004  lhu         $a0, 0x4($s0)
    ctx->pc = 0x1cbf20u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1cbf24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cbf24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cbf28: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1cbf28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1cbf2c: 0xac23d9f0  sw          $v1, -0x2610($at)
    ctx->pc = 0x1cbf2cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957552), GPR_U32(ctx, 3));
label_1cbf30:
    // 0x1cbf30: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cbf30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1cbf34:
    // 0x1cbf34: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cbf34u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cbf38: 0x3e00008  jr          $ra
    ctx->pc = 0x1CBF38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CBF3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CBF38u;
            // 0x1cbf3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CBED4u: goto label_1cbed4;
            case 0x1CBF00u: goto label_1cbf00;
            case 0x1CBF30u: goto label_1cbf30;
            case 0x1CBF34u: goto label_1cbf34;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CBF40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
