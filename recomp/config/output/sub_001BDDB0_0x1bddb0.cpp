#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BDDB0
// Address: 0x1bddb0 - 0x1bde54
void sub_001BDDB0_0x1bddb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BDDB0_0x1bddb0");
#endif

    switch (ctx->pc) {
        case 0x1bddd8u: goto label_1bddd8;
        case 0x1bddf0u: goto label_1bddf0;
        case 0x1bddfcu: goto label_1bddfc;
        case 0x1bde04u: goto label_1bde04;
        case 0x1bde14u: goto label_1bde14;
        default: break;
    }

    ctx->pc = 0x1bddb0u;

    // 0x1bddb0: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1bddb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1bddb4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1bddb4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1bddb8: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1bddb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1bddbc: 0x24a50440  addiu       $a1, $a1, 0x440
    ctx->pc = 0x1bddbcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1088));
    // 0x1bddc0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1bddc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1bddc4: 0x24061234  addiu       $a2, $zero, 0x1234
    ctx->pc = 0x1bddc4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4660));
    // 0x1bddc8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1bddc8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bddcc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1bddccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1bddd0: 0xc06f918  jal         func_1BE460
    ctx->pc = 0x1BDDD0u;
    SET_GPR_U32(ctx, 31, 0x1BDDD8u);
    ctx->pc = 0x1BDDD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDDD0u;
            // 0x1bddd4: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE460u;
    if (runtime->hasFunction(0x1BE460u)) {
        auto targetFn = runtime->lookupFunction(0x1BE460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDDD8u; }
        if (ctx->pc != 0x1BDDD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE460_0x1be460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDDD8u; }
        if (ctx->pc != 0x1BDDD8u) { return; }
    }
    ctx->pc = 0x1BDDD8u;
label_1bddd8:
    // 0x1bddd8: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1bddd8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1bdddc: 0x27a50030  addiu       $a1, $sp, 0x30
    ctx->pc = 0x1bdddcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1bdde0: 0x24840420  addiu       $a0, $a0, 0x420
    ctx->pc = 0x1bdde0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1056));
    // 0x1bdde4: 0x26260010  addiu       $a2, $s1, 0x10
    ctx->pc = 0x1bdde4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 17), 16));
    // 0x1bdde8: 0xc0467b0  jal         func_119EC0
    ctx->pc = 0x1BDDE8u;
    SET_GPR_U32(ctx, 31, 0x1BDDF0u);
    ctx->pc = 0x1BDDECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDDE8u;
            // 0x1bddec: 0x24070004  addiu       $a3, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x119EC0u;
    if (runtime->hasFunction(0x119EC0u)) {
        auto targetFn = runtime->lookupFunction(0x119EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDDF0u; }
        if (ctx->pc != 0x1BDDF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00119EC0_0x119ec0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDDF0u; }
        if (ctx->pc != 0x1BDDF0u) { return; }
    }
    ctx->pc = 0x1BDDF0u;
label_1bddf0:
    // 0x1bddf0: 0x4410006  bgez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1BDDF0u;
    {
        const bool branch_taken_0x1bddf0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1BDDF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDDF0u;
            // 0x1bddf4: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bddf0) {
            ctx->pc = 0x1BDE0Cu;
            goto label_1bde0c;
        }
    }
    ctx->pc = 0x1BDDF8u;
    // 0x1bddf8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1bddf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1bddfc:
    // 0x1bddfc: 0xc06f660  jal         func_1BD980
    ctx->pc = 0x1BDDFCu;
    SET_GPR_U32(ctx, 31, 0x1BDE04u);
    ctx->pc = 0x1BDE00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDDFCu;
            // 0x1bde00: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BD980u;
    if (runtime->hasFunction(0x1BD980u)) {
        auto targetFn = runtime->lookupFunction(0x1BD980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDE04u; }
        if (ctx->pc != 0x1BDE04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD980_0x1bd980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDE04u; }
        if (ctx->pc != 0x1BDE04u) { return; }
    }
    ctx->pc = 0x1BDE04u;
label_1bde04:
    // 0x1bde04: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1BDE04u;
    {
        const bool branch_taken_0x1bde04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BDE08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDE04u;
            // 0x1bde08: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bde04) {
            ctx->pc = 0x1BDE44u;
            goto label_1bde44;
        }
    }
    ctx->pc = 0x1BDE0Cu;
label_1bde0c:
    // 0x1bde0c: 0xc06f8ec  jal         func_1BE3B0
    ctx->pc = 0x1BDE0Cu;
    SET_GPR_U32(ctx, 31, 0x1BDE14u);
    ctx->pc = 0x1BDE10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDE0Cu;
            // 0x1bde10: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE3B0u;
    if (runtime->hasFunction(0x1BE3B0u)) {
        auto targetFn = runtime->lookupFunction(0x1BE3B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDE14u; }
        if (ctx->pc != 0x1BDE14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE3B0_0x1be3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BDE14u; }
        if (ctx->pc != 0x1BDE14u) { return; }
    }
    ctx->pc = 0x1BDE14u;
label_1bde14:
    // 0x1bde14: 0x440fff9  bltz        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1BDE14u;
    {
        const bool branch_taken_0x1bde14 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1BDE18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDE14u;
            // 0x1bde18: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1bde14) {
            ctx->pc = 0x1BDDFCu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1bddfc;
        }
    }
    ctx->pc = 0x1BDE1Cu;
    // 0x1bde1c: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1bde1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1bde20: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1bde20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1bde24: 0xae230000  sw          $v1, 0x0($s1)
    ctx->pc = 0x1bde24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x1bde28: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x1bde28u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x1bde2c: 0xae200024  sw          $zero, 0x24($s1)
    ctx->pc = 0x1bde2cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 36), GPR_U32(ctx, 0));
    // 0x1bde30: 0xae200028  sw          $zero, 0x28($s1)
    ctx->pc = 0x1bde30u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 40), GPR_U32(ctx, 0));
    // 0x1bde34: 0xae20002c  sw          $zero, 0x2C($s1)
    ctx->pc = 0x1bde34u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 44), GPR_U32(ctx, 0));
    // 0x1bde38: 0xae200034  sw          $zero, 0x34($s1)
    ctx->pc = 0x1bde38u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 0));
    // 0x1bde3c: 0xae200038  sw          $zero, 0x38($s1)
    ctx->pc = 0x1bde3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 56), GPR_U32(ctx, 0));
    // 0x1bde40: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1bde40u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_1bde44:
    // 0x1bde44: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1bde44u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1bde48: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1bde48u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bde4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1BDE4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BDE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BDE4Cu;
            // 0x1bde50: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BDDD8u: goto label_1bddd8;
            case 0x1BDDF0u: goto label_1bddf0;
            case 0x1BDDFCu: goto label_1bddfc;
            case 0x1BDE04u: goto label_1bde04;
            case 0x1BDE0Cu: goto label_1bde0c;
            case 0x1BDE14u: goto label_1bde14;
            case 0x1BDE44u: goto label_1bde44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BDE54u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
