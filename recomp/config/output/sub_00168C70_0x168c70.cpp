#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168C70
// Address: 0x168c70 - 0x168d40
void sub_00168C70_0x168c70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168C70_0x168c70");
#endif

    switch (ctx->pc) {
        case 0x168cb8u: goto label_168cb8;
        case 0x168ce0u: goto label_168ce0;
        default: break;
    }

    ctx->pc = 0x168c70u;

    // 0x168c70: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x168c70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x168c74: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x168c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x168c78: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x168c78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168c7c: 0x2a420004  slti        $v0, $s2, 0x4
    ctx->pc = 0x168c7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x168c80: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x168c80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x168c84: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x168c84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x168c88: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x168c88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168c8c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x168c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x168c90: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x168c90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168c94: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x168c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x168c98: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x168c98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x168c9c: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x168c9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x168ca0: 0x1440001c  bnez        $v0, . + 4 + (0x1C << 2)
    ctx->pc = 0x168CA0u;
    {
        const bool branch_taken_0x168ca0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168CA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168CA0u;
            // 0x168ca4: 0xffbf0038  sd          $ra, 0x38($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168ca0) {
            ctx->pc = 0x168D14u;
            goto label_168d14;
        }
    }
    ctx->pc = 0x168CA8u;
    // 0x168ca8: 0x241600ff  addiu       $s6, $zero, 0xFF
    ctx->pc = 0x168ca8u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x168cac: 0x241500f8  addiu       $s5, $zero, 0xF8
    ctx->pc = 0x168cacu;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 248));
    // 0x168cb0: 0x2414000f  addiu       $s4, $zero, 0xF
    ctx->pc = 0x168cb0u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x168cb4: 0x24130003  addiu       $s3, $zero, 0x3
    ctx->pc = 0x168cb4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_168cb8:
    // 0x168cb8: 0x92020000  lbu         $v0, 0x0($s0)
    ctx->pc = 0x168cb8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x168cbc: 0x54560012  bnel        $v0, $s6, . + 4 + (0x12 << 2)
    ctx->pc = 0x168CBCu;
    {
        const bool branch_taken_0x168cbc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 22));
        if (branch_taken_0x168cbc) {
            ctx->pc = 0x168CC0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168CBCu;
            // 0x168cc0: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168D08u;
            goto label_168d08;
        }
    }
    ctx->pc = 0x168CC4u;
    // 0x168cc4: 0x92020001  lbu         $v0, 0x1($s0)
    ctx->pc = 0x168cc4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x168cc8: 0x304200f8  andi        $v0, $v0, 0xF8
    ctx->pc = 0x168cc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)248);
    // 0x168ccc: 0x5455000e  bnel        $v0, $s5, . + 4 + (0xE << 2)
    ctx->pc = 0x168CCCu;
    {
        const bool branch_taken_0x168ccc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 21));
        if (branch_taken_0x168ccc) {
            ctx->pc = 0x168CD0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168CCCu;
            // 0x168cd0: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168D08u;
            goto label_168d08;
        }
    }
    ctx->pc = 0x168CD4u;
    // 0x168cd4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x168cd4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168cd8: 0xc05a350  jal         func_168D40
    ctx->pc = 0x168CD8u;
    SET_GPR_U32(ctx, 31, 0x168CE0u);
    ctx->pc = 0x168CDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168CD8u;
            // 0x168cdc: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x168D40u;
    if (runtime->hasFunction(0x168D40u)) {
        auto targetFn = runtime->lookupFunction(0x168D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168CE0u; }
        if (ctx->pc != 0x168CE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00168D40_0x168d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168CE0u; }
        if (ctx->pc != 0x168CE0u) { return; }
    }
    ctx->pc = 0x168CE0u;
label_168ce0:
    // 0x168ce0: 0x92220000  lbu         $v0, 0x0($s1)
    ctx->pc = 0x168ce0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x168ce4: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x168CE4u;
    {
        const bool branch_taken_0x168ce4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x168ce4) {
            ctx->pc = 0x168CE8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168CE4u;
            // 0x168ce8: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168D08u;
            goto label_168d08;
        }
    }
    ctx->pc = 0x168CECu;
    // 0x168cec: 0x92220002  lbu         $v0, 0x2($s1)
    ctx->pc = 0x168cecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
    // 0x168cf0: 0x50540005  beql        $v0, $s4, . + 4 + (0x5 << 2)
    ctx->pc = 0x168CF0u;
    {
        const bool branch_taken_0x168cf0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 20));
        if (branch_taken_0x168cf0) {
            ctx->pc = 0x168CF4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168CF0u;
            // 0x168cf4: 0x2652ffff  addiu       $s2, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168D08u;
            goto label_168d08;
        }
    }
    ctx->pc = 0x168CF8u;
    // 0x168cf8: 0x92230003  lbu         $v1, 0x3($s1)
    ctx->pc = 0x168cf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 3)));
    // 0x168cfc: 0x14730006  bne         $v1, $s3, . + 4 + (0x6 << 2)
    ctx->pc = 0x168CFCu;
    {
        const bool branch_taken_0x168cfc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 19));
        ctx->pc = 0x168D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168CFCu;
            // 0x168d00: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168cfc) {
            ctx->pc = 0x168D18u;
            goto label_168d18;
        }
    }
    ctx->pc = 0x168D04u;
    // 0x168d04: 0x2652ffff  addiu       $s2, $s2, -0x1
    ctx->pc = 0x168d04u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
label_168d08:
    // 0x168d08: 0x2a420004  slti        $v0, $s2, 0x4
    ctx->pc = 0x168d08u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)(int32_t)4) ? 1 : 0);
    // 0x168d0c: 0x1040ffea  beqz        $v0, . + 4 + (-0x16 << 2)
    ctx->pc = 0x168D0Cu;
    {
        const bool branch_taken_0x168d0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168D10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168D0Cu;
            // 0x168d10: 0x26100001  addiu       $s0, $s0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168d0c) {
            ctx->pc = 0x168CB8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_168cb8;
        }
    }
    ctx->pc = 0x168D14u;
label_168d14:
    // 0x168d14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x168d14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_168d18:
    // 0x168d18: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x168d18u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168d1c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x168d1cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x168d20: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x168d20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168d24: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x168d24u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168d28: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x168d28u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x168d2c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x168d2cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x168d30: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x168d30u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x168d34: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x168d34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x168d38: 0x3e00008  jr          $ra
    ctx->pc = 0x168D38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168D38u;
            // 0x168d3c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x168CB8u: goto label_168cb8;
            case 0x168CE0u: goto label_168ce0;
            case 0x168D08u: goto label_168d08;
            case 0x168D14u: goto label_168d14;
            case 0x168D18u: goto label_168d18;
            default: break;
        }
        return;
    }
    ctx->pc = 0x168D40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
