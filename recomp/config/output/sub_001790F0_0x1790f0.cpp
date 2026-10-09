#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001790F0
// Address: 0x1790f0 - 0x1791b8
void sub_001790F0_0x1790f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001790F0_0x1790f0");
#endif

    switch (ctx->pc) {
        case 0x179148u: goto label_179148;
        case 0x179164u: goto label_179164;
        case 0x17917cu: goto label_17917c;
        default: break;
    }

    ctx->pc = 0x1790f0u;

    // 0x1790f0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1790f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1790f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1790f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1790f8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1790f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1790fc: 0x902d  daddu       $s2, $zero, $zero
    ctx->pc = 0x1790fcu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179100: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x179100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x179104: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x179104u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179108: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x179108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17910c: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x17910cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179110: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x179110u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x179114: 0x3c160027  lui         $s6, 0x27
    ctx->pc = 0x179114u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)39 << 16));
    // 0x179118: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179118u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17911c: 0x26c46138  addiu       $a0, $s6, 0x6138
    ctx->pc = 0x17911cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 24888));
    // 0x179120: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179124: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x179124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x179128: 0xffbf0038  sd          $ra, 0x38($sp)
    ctx->pc = 0x179128u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x17912c: 0x8c910000  lw          $s1, 0x0($a0)
    ctx->pc = 0x17912cu;
    SET_GPR_S32(ctx, 17, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x179130: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x179130u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179134: 0x71182a  slt         $v1, $v1, $s1
    ctx->pc = 0x179134u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x179138: 0x10600015  beqz        $v1, . + 4 + (0x15 << 2)
    ctx->pc = 0x179138u;
    {
        const bool branch_taken_0x179138 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x17913Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179138u;
            // 0x17913c: 0x8c930008  lw          $s3, 0x8($a0) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179138) {
            ctx->pc = 0x179190u;
            goto label_179190;
        }
    }
    ctx->pc = 0x179140u;
    // 0x179140: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x179140u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179144: 0x211102a  slt         $v0, $s0, $s1
    ctx->pc = 0x179144u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
label_179148:
    // 0x179148: 0x50400009  beql        $v0, $zero, . + 4 + (0x9 << 2)
    ctx->pc = 0x179148u;
    {
        const bool branch_taken_0x179148 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x179148) {
            ctx->pc = 0x17914Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x179148u;
            // 0x17914c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x179170u;
            goto label_179170;
        }
    }
    ctx->pc = 0x179150u;
    // 0x179150: 0x101100  sll         $v0, $s0, 4
    ctx->pc = 0x179150u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 4));
    // 0x179154: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x179154u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x179158: 0x2629021  addu        $s2, $s3, $v0
    ctx->pc = 0x179158u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    // 0x17915c: 0xc05e4a2  jal         func_179288
    ctx->pc = 0x17915Cu;
    SET_GPR_U32(ctx, 31, 0x179164u);
    ctx->pc = 0x179160u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17915Cu;
            // 0x179160: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179288u;
    if (runtime->hasFunction(0x179288u)) {
        auto targetFn = runtime->lookupFunction(0x179288u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179164u; }
        if (ctx->pc != 0x179164u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179288_0x179288(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179164u; }
        if (ctx->pc != 0x179164u) { return; }
    }
    ctx->pc = 0x179164u;
label_179164:
    // 0x179164: 0x1040fff8  beqz        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x179164u;
    {
        const bool branch_taken_0x179164 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x179168u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179164u;
            // 0x179168: 0x211102a  slt         $v0, $s0, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x179164) {
            ctx->pc = 0x179148u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_179148;
        }
    }
    ctx->pc = 0x17916Cu;
    // 0x17916c: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x17916cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_179170:
    // 0x179170: 0x2a0282d  daddu       $a1, $s5, $zero
    ctx->pc = 0x179170u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179174: 0xc05e488  jal         func_179220
    ctx->pc = 0x179174u;
    SET_GPR_U32(ctx, 31, 0x17917Cu);
    ctx->pc = 0x179178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179174u;
            // 0x179178: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179220u;
    if (runtime->hasFunction(0x179220u)) {
        auto targetFn = runtime->lookupFunction(0x179220u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17917Cu; }
        if (ctx->pc != 0x17917Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179220_0x179220(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17917Cu; }
        if (ctx->pc != 0x17917Cu) { return; }
    }
    ctx->pc = 0x17917Cu;
label_17917c:
    // 0x17917c: 0x26c46138  addiu       $a0, $s6, 0x6138
    ctx->pc = 0x17917cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 24888));
    // 0x179180: 0x8c830004  lw          $v1, 0x4($a0)
    ctx->pc = 0x179180u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x179184: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x179184u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179188: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x179188u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x17918c: 0xac830004  sw          $v1, 0x4($a0)
    ctx->pc = 0x17918cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
label_179190:
    // 0x179190: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179190u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179194: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179194u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179198: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179198u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17919c: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x17919cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1791a0: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1791a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1791a4: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1791a4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1791a8: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1791a8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1791ac: 0xdfbf0038  ld          $ra, 0x38($sp)
    ctx->pc = 0x1791acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1791b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1791B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1791B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1791B0u;
            // 0x1791b4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179148u: goto label_179148;
            case 0x179164u: goto label_179164;
            case 0x179170u: goto label_179170;
            case 0x17917Cu: goto label_17917c;
            case 0x179190u: goto label_179190;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1791B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
