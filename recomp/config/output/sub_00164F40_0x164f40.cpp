#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00164F40
// Address: 0x164f40 - 0x164fc8
void sub_00164F40_0x164f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00164F40_0x164f40");
#endif

    switch (ctx->pc) {
        case 0x164f78u: goto label_164f78;
        case 0x164f9cu: goto label_164f9c;
        default: break;
    }

    ctx->pc = 0x164f40u;

    // 0x164f40: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x164f40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x164f44: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x164f44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x164f48: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x164f48u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164f4c: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x164f4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x164f50: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x164f50u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164f54: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x164f54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x164f58: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x164f58u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164f5c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x164f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x164f60: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x164f60u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164f64: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x164f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x164f68: 0x24140001  addiu       $s4, $zero, 0x1
    ctx->pc = 0x164f68u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x164f6c: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x164f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x164f70: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x164F70u;
    {
        const bool branch_taken_0x164f70 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x164F74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164F70u;
            // 0x164f74: 0xae600000  sw          $zero, 0x0($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164f70) {
            ctx->pc = 0x164F7Cu;
            goto label_164f7c;
        }
    }
    ctx->pc = 0x164F78u;
label_164f78:
    // 0x164f78: 0x26310012  addiu       $s1, $s1, 0x12
    ctx->pc = 0x164f78u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 18));
label_164f7c:
    // 0x164f7c: 0x232102a  slt         $v0, $s1, $s2
    ctx->pc = 0x164f7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x164f80: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x164F80u;
    {
        const bool branch_taken_0x164f80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x164f80) {
            ctx->pc = 0x164F84u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x164F80u;
            // 0x164f84: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x164FA8u;
            goto label_164fa8;
        }
    }
    ctx->pc = 0x164F88u;
    // 0x164f88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x164f88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x164f8c: 0x26100012  addiu       $s0, $s0, 0x12
    ctx->pc = 0x164f8cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18));
    // 0x164f90: 0x24050012  addiu       $a1, $zero, 0x12
    ctx->pc = 0x164f90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 18));
    // 0x164f94: 0xc04cc90  jal         func_133240
    ctx->pc = 0x164F94u;
    SET_GPR_U32(ctx, 31, 0x164F9Cu);
    ctx->pc = 0x164F98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x164F94u;
            // 0x164f98: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x133240u;
    if (runtime->hasFunction(0x133240u)) {
        auto targetFn = runtime->lookupFunction(0x133240u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164F9Cu; }
        if (ctx->pc != 0x164F9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00133240_0x133240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x164F9Cu; }
        if (ctx->pc != 0x164F9Cu) { return; }
    }
    ctx->pc = 0x164F9Cu;
label_164f9c:
    // 0x164f9c: 0x1040fff6  beqz        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x164F9Cu;
    {
        const bool branch_taken_0x164f9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x164FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164F9Cu;
            // 0x164fa0: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x164f9c) {
            ctx->pc = 0x164F78u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_164f78;
        }
    }
    ctx->pc = 0x164FA4u;
    // 0x164fa4: 0xae740000  sw          $s4, 0x0($s3)
    ctx->pc = 0x164fa4u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 20));
label_164fa8:
    // 0x164fa8: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x164fa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x164fac: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x164facu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x164fb0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x164fb0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x164fb4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x164fb4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x164fb8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x164fb8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x164fbc: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x164fbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x164fc0: 0x3e00008  jr          $ra
    ctx->pc = 0x164FC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x164FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x164FC0u;
            // 0x164fc4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x164F78u: goto label_164f78;
            case 0x164F7Cu: goto label_164f7c;
            case 0x164F9Cu: goto label_164f9c;
            case 0x164FA8u: goto label_164fa8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x164FC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
