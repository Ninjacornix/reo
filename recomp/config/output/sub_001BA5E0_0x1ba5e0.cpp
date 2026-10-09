#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA5E0
// Address: 0x1ba5e0 - 0x1ba680
void sub_001BA5E0_0x1ba5e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA5E0_0x1ba5e0");
#endif

    switch (ctx->pc) {
        case 0x1ba614u: goto label_1ba614;
        case 0x1ba644u: goto label_1ba644;
        case 0x1ba65cu: goto label_1ba65c;
        case 0x1ba674u: goto label_1ba674;
        default: break;
    }

    ctx->pc = 0x1ba5e0u;

    // 0x1ba5e0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1ba5e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1ba5e4: 0x10800023  beqz        $a0, . + 4 + (0x23 << 2)
    ctx->pc = 0x1BA5E4u;
    {
        const bool branch_taken_0x1ba5e4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA5E4u;
            // 0x1ba5e8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba5e4) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA5ECu;
    // 0x1ba5ec: 0x90860002  lbu         $a2, 0x2($a0)
    ctx->pc = 0x1ba5ecu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1ba5f0: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x1ba5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1ba5f4: 0x10c30009  beq         $a2, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1BA5F4u;
    {
        const bool branch_taken_0x1ba5f4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ba5f4) {
            ctx->pc = 0x1BA61Cu;
            goto label_1ba61c;
        }
    }
    ctx->pc = 0x1BA5FCu;
    // 0x1ba5fc: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA5FCu;
    {
        const bool branch_taken_0x1ba5fc = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba5fc) {
            ctx->pc = 0x1BA60Cu;
            goto label_1ba60c;
        }
    }
    ctx->pc = 0x1BA604u;
    // 0x1ba604: 0x10000017  b           . + 4 + (0x17 << 2)
    ctx->pc = 0x1BA604u;
    {
        const bool branch_taken_0x1ba604 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA608u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA604u;
            // 0x1ba608: 0x30a200ff  andi        $v0, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba604) {
            ctx->pc = 0x1BA664u;
            goto label_1ba664;
        }
    }
    ctx->pc = 0x1BA60Cu;
label_1ba60c:
    // 0x1ba60c: 0xc06e930  jal         func_1BA4C0
    ctx->pc = 0x1BA60Cu;
    SET_GPR_U32(ctx, 31, 0x1BA614u);
    ctx->pc = 0x1BA4C0u;
    if (runtime->hasFunction(0x1BA4C0u)) {
        auto targetFn = runtime->lookupFunction(0x1BA4C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA614u; }
        if (ctx->pc != 0x1BA614u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA4C0_0x1ba4c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA614u; }
        if (ctx->pc != 0x1BA614u) { return; }
    }
    ctx->pc = 0x1BA614u;
label_1ba614:
    // 0x1ba614: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1BA614u;
    {
        const bool branch_taken_0x1ba614 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA618u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA614u;
            // 0x1ba618: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba614) {
            ctx->pc = 0x1BA678u;
            goto label_1ba678;
        }
    }
    ctx->pc = 0x1BA61Cu;
label_1ba61c:
    // 0x1ba61c: 0x8c840028  lw          $a0, 0x28($a0)
    ctx->pc = 0x1ba61cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1ba620: 0x10800014  beqz        $a0, . + 4 + (0x14 << 2)
    ctx->pc = 0x1BA620u;
    {
        const bool branch_taken_0x1ba620 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba620) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA628u;
    // 0x1ba628: 0x90820002  lbu         $v0, 0x2($a0)
    ctx->pc = 0x1ba628u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1ba62c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA62Cu;
    {
        const bool branch_taken_0x1ba62c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba62c) {
            ctx->pc = 0x1BA63Cu;
            goto label_1ba63c;
        }
    }
    ctx->pc = 0x1BA634u;
    // 0x1ba634: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA634u;
    {
        const bool branch_taken_0x1ba634 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA638u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA634u;
            // 0x1ba638: 0x30a200ff  andi        $v0, $a1, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba634) {
            ctx->pc = 0x1BA64Cu;
            goto label_1ba64c;
        }
    }
    ctx->pc = 0x1BA63Cu;
label_1ba63c:
    // 0x1ba63c: 0xc06e930  jal         func_1BA4C0
    ctx->pc = 0x1BA63Cu;
    SET_GPR_U32(ctx, 31, 0x1BA644u);
    ctx->pc = 0x1BA4C0u;
    if (runtime->hasFunction(0x1BA4C0u)) {
        auto targetFn = runtime->lookupFunction(0x1BA4C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA644u; }
        if (ctx->pc != 0x1BA644u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA4C0_0x1ba4c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA644u; }
        if (ctx->pc != 0x1BA644u) { return; }
    }
    ctx->pc = 0x1BA644u;
label_1ba644:
    // 0x1ba644: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1BA644u;
    {
        const bool branch_taken_0x1ba644 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba644) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA64Cu;
label_1ba64c:
    // 0x1ba64c: 0x3045007f  andi        $a1, $v0, 0x7F
    ctx->pc = 0x1ba64cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x1ba650: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1ba650u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1ba654: 0xc06e478  jal         func_1B91E0
    ctx->pc = 0x1BA654u;
    SET_GPR_U32(ctx, 31, 0x1BA65Cu);
    ctx->pc = 0x1BA658u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA654u;
            // 0x1ba658: 0x2302b  sltu        $a2, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B91E0u;
    if (runtime->hasFunction(0x1B91E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B91E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA65Cu; }
        if (ctx->pc != 0x1BA65Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B91E0_0x1b91e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA65Cu; }
        if (ctx->pc != 0x1BA65Cu) { return; }
    }
    ctx->pc = 0x1BA65Cu;
label_1ba65c:
    // 0x1ba65c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1BA65Cu;
    {
        const bool branch_taken_0x1ba65c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba65c) {
            ctx->pc = 0x1BA674u;
            goto label_1ba674;
        }
    }
    ctx->pc = 0x1BA664u;
label_1ba664:
    // 0x1ba664: 0x3045007f  andi        $a1, $v0, 0x7F
    ctx->pc = 0x1ba664u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)127);
    // 0x1ba668: 0x30420080  andi        $v0, $v0, 0x80
    ctx->pc = 0x1ba668u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)128);
    // 0x1ba66c: 0xc06e478  jal         func_1B91E0
    ctx->pc = 0x1BA66Cu;
    SET_GPR_U32(ctx, 31, 0x1BA674u);
    ctx->pc = 0x1BA670u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA66Cu;
            // 0x1ba670: 0x2302b  sltu        $a2, $zero, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B91E0u;
    if (runtime->hasFunction(0x1B91E0u)) {
        auto targetFn = runtime->lookupFunction(0x1B91E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA674u; }
        if (ctx->pc != 0x1BA674u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B91E0_0x1b91e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA674u; }
        if (ctx->pc != 0x1BA674u) { return; }
    }
    ctx->pc = 0x1BA674u;
label_1ba674:
    // 0x1ba674: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1ba674u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1ba678:
    // 0x1ba678: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA678u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA678u;
            // 0x1ba67c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA60Cu: goto label_1ba60c;
            case 0x1BA614u: goto label_1ba614;
            case 0x1BA61Cu: goto label_1ba61c;
            case 0x1BA63Cu: goto label_1ba63c;
            case 0x1BA644u: goto label_1ba644;
            case 0x1BA64Cu: goto label_1ba64c;
            case 0x1BA65Cu: goto label_1ba65c;
            case 0x1BA664u: goto label_1ba664;
            case 0x1BA674u: goto label_1ba674;
            case 0x1BA678u: goto label_1ba678;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA680u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
