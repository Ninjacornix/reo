#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00168908
// Address: 0x168908 - 0x1689a0
void sub_00168908_0x168908(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00168908_0x168908");
#endif

    switch (ctx->pc) {
        case 0x16892cu: goto label_16892c;
        case 0x168944u: goto label_168944;
        case 0x16895cu: goto label_16895c;
        case 0x168980u: goto label_168980;
        default: break;
    }

    ctx->pc = 0x168908u;

    // 0x168908: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x168908u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16890c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16890cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x168910: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x168910u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x168914: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x168914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x168918: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x168918u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16891c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16891cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x168920: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x168920u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x168924: 0xc05a268  jal         func_1689A0
    ctx->pc = 0x168924u;
    SET_GPR_U32(ctx, 31, 0x16892Cu);
    ctx->pc = 0x168928u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168924u;
            // 0x168928: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1689A0u;
    if (runtime->hasFunction(0x1689A0u)) {
        auto targetFn = runtime->lookupFunction(0x1689A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16892Cu; }
        if (ctx->pc != 0x16892Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001689A0_0x1689a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16892Cu; }
        if (ctx->pc != 0x16892Cu) { return; }
    }
    ctx->pc = 0x16892Cu;
label_16892c:
    // 0x16892c: 0x26040002  addiu       $a0, $s0, 0x2
    ctx->pc = 0x16892cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 2));
    // 0x168930: 0x2625fffe  addiu       $a1, $s1, -0x2
    ctx->pc = 0x168930u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967294));
    // 0x168934: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x168934u;
    {
        const bool branch_taken_0x168934 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x168938u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168934u;
            // 0x168938: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168934) {
            ctx->pc = 0x16896Cu;
            goto label_16896c;
        }
    }
    ctx->pc = 0x16893Cu;
    // 0x16893c: 0xc05a268  jal         func_1689A0
    ctx->pc = 0x16893Cu;
    SET_GPR_U32(ctx, 31, 0x168944u);
    ctx->pc = 0x1689A0u;
    if (runtime->hasFunction(0x1689A0u)) {
        auto targetFn = runtime->lookupFunction(0x1689A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168944u; }
        if (ctx->pc != 0x168944u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001689A0_0x1689a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168944u; }
        if (ctx->pc != 0x168944u) { return; }
    }
    ctx->pc = 0x168944u;
label_168944:
    // 0x168944: 0x5440000f  bnel        $v0, $zero, . + 4 + (0xF << 2)
    ctx->pc = 0x168944u;
    {
        const bool branch_taken_0x168944 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x168944) {
            ctx->pc = 0x168948u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x168944u;
            // 0x168948: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x168984u;
            goto label_168984;
        }
    }
    ctx->pc = 0x16894Cu;
    // 0x16894c: 0x26040001  addiu       $a0, $s0, 0x1
    ctx->pc = 0x16894cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x168950: 0x2625ffff  addiu       $a1, $s1, -0x1
    ctx->pc = 0x168950u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x168954: 0xc05a268  jal         func_1689A0
    ctx->pc = 0x168954u;
    SET_GPR_U32(ctx, 31, 0x16895Cu);
    ctx->pc = 0x168958u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x168954u;
            // 0x168958: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1689A0u;
    if (runtime->hasFunction(0x1689A0u)) {
        auto targetFn = runtime->lookupFunction(0x1689A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16895Cu; }
        if (ctx->pc != 0x16895Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001689A0_0x1689a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16895Cu; }
        if (ctx->pc != 0x16895Cu) { return; }
    }
    ctx->pc = 0x16895Cu;
label_16895c:
    // 0x16895c: 0x26040003  addiu       $a0, $s0, 0x3
    ctx->pc = 0x16895cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 3));
    // 0x168960: 0x2625fffd  addiu       $a1, $s1, -0x3
    ctx->pc = 0x168960u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967293));
    // 0x168964: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x168964u;
    {
        const bool branch_taken_0x168964 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x168968u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168964u;
            // 0x168968: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x168964) {
            ctx->pc = 0x168978u;
            goto label_168978;
        }
    }
    ctx->pc = 0x16896Cu;
label_16896c:
    // 0x16896c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x16896Cu;
    {
        const bool branch_taken_0x16896c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x168970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16896Cu;
            // 0x168970: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16896c) {
            ctx->pc = 0x168984u;
            goto label_168984;
        }
    }
    ctx->pc = 0x168974u;
    // 0x168974: 0x0  nop
    ctx->pc = 0x168974u;
    // NOP
label_168978:
    // 0x168978: 0xc05a268  jal         func_1689A0
    ctx->pc = 0x168978u;
    SET_GPR_U32(ctx, 31, 0x168980u);
    ctx->pc = 0x1689A0u;
    if (runtime->hasFunction(0x1689A0u)) {
        auto targetFn = runtime->lookupFunction(0x1689A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168980u; }
        if (ctx->pc != 0x168980u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001689A0_0x1689a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x168980u; }
        if (ctx->pc != 0x168980u) { return; }
    }
    ctx->pc = 0x168980u;
label_168980:
    // 0x168980: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x168980u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_168984:
    // 0x168984: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x168984u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x168988: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x168988u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16898c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16898cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x168990: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x168990u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x168994: 0x3e00008  jr          $ra
    ctx->pc = 0x168994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x168998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x168994u;
            // 0x168998: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16892Cu: goto label_16892c;
            case 0x168944u: goto label_168944;
            case 0x16895Cu: goto label_16895c;
            case 0x16896Cu: goto label_16896c;
            case 0x168978u: goto label_168978;
            case 0x168980u: goto label_168980;
            case 0x168984u: goto label_168984;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16899Cu;
    // 0x16899c: 0x0  nop
    ctx->pc = 0x16899cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
