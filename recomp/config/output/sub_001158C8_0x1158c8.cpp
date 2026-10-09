#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001158C8
// Address: 0x1158c8 - 0x115980
void sub_001158C8_0x1158c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001158C8_0x1158c8");
#endif

    switch (ctx->pc) {
        case 0x1158f0u: goto label_1158f0;
        case 0x115924u: goto label_115924;
        case 0x115948u: goto label_115948;
        case 0x115970u: goto label_115970;
        default: break;
    }

    ctx->pc = 0x1158c8u;

    // 0x1158c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1158c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1158cc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1158ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1158d0: 0x30c6ffff  andi        $a2, $a2, 0xFFFF
    ctx->pc = 0x1158d0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)65535);
    // 0x1158d4: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x1158d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x1158d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1158d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1158dc: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x1158dcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1158e0: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x1158e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x1158e4: 0x2404fffa  addiu       $a0, $zero, -0x6
    ctx->pc = 0x1158e4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967290));
    // 0x1158e8: 0xc045294  jal         func_114A50
    ctx->pc = 0x1158E8u;
    SET_GPR_U32(ctx, 31, 0x1158F0u);
    ctx->pc = 0x1158ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1158E8u;
            // 0x1158ec: 0xafa60008  sw          $a2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1158F0u; }
        if (ctx->pc != 0x1158F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1158F0u; }
        if (ctx->pc != 0x1158F0u) { return; }
    }
    ctx->pc = 0x1158F0u;
label_1158f0:
    // 0x1158f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1158f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1158f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1158F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1158F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1158F4u;
            // 0x1158f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1158F0u: goto label_1158f0;
            case 0x115924u: goto label_115924;
            case 0x115948u: goto label_115948;
            case 0x115970u: goto label_115970;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1158FCu;
    // 0x1158fc: 0x0  nop
    ctx->pc = 0x1158fcu;
    // NOP
    // 0x115900: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x115900u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x115904: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115904u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x115908: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x115908u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x11590c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11590cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115910: 0xafa50004  sw          $a1, 0x4($sp)
    ctx->pc = 0x115910u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 5));
    // 0x115914: 0x2404fff9  addiu       $a0, $zero, -0x7
    ctx->pc = 0x115914u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967289));
    // 0x115918: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x115918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x11591c: 0xc045294  jal         func_114A50
    ctx->pc = 0x11591Cu;
    SET_GPR_U32(ctx, 31, 0x115924u);
    ctx->pc = 0x115920u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11591Cu;
            // 0x115920: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115924u; }
        if (ctx->pc != 0x115924u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115924u; }
        if (ctx->pc != 0x115924u) { return; }
    }
    ctx->pc = 0x115924u;
label_115924:
    // 0x115924: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115928: 0x3e00008  jr          $ra
    ctx->pc = 0x115928u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11592Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115928u;
            // 0x11592c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1158F0u: goto label_1158f0;
            case 0x115924u: goto label_115924;
            case 0x115948u: goto label_115948;
            case 0x115970u: goto label_115970;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115930u;
    // 0x115930: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x115934: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x115934u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115938: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115938u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11593c: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x11593cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x115940: 0xc045294  jal         func_114A50
    ctx->pc = 0x115940u;
    SET_GPR_U32(ctx, 31, 0x115948u);
    ctx->pc = 0x115944u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115940u;
            // 0x115944: 0x2404fff8  addiu       $a0, $zero, -0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967288));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115948u; }
        if (ctx->pc != 0x115948u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115948u; }
        if (ctx->pc != 0x115948u) { return; }
    }
    ctx->pc = 0x115948u;
label_115948:
    // 0x115948: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115948u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11594c: 0x3e00008  jr          $ra
    ctx->pc = 0x11594Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11594Cu;
            // 0x115950: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1158F0u: goto label_1158f0;
            case 0x115924u: goto label_115924;
            case 0x115948u: goto label_115948;
            case 0x115970u: goto label_115970;
            default: break;
        }
        return;
    }
    ctx->pc = 0x115954u;
    // 0x115954: 0x0  nop
    ctx->pc = 0x115954u;
    // NOP
    // 0x115958: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x115958u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x11595c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x11595cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x115960: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x115960u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x115964: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x115964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x115968: 0xc045294  jal         func_114A50
    ctx->pc = 0x115968u;
    SET_GPR_U32(ctx, 31, 0x115970u);
    ctx->pc = 0x11596Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x115968u;
            // 0x11596c: 0x2404fff7  addiu       $a0, $zero, -0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967287));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114A50u;
    if (runtime->hasFunction(0x114A50u)) {
        auto targetFn = runtime->lookupFunction(0x114A50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115970u; }
        if (ctx->pc != 0x115970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114A50_0x114a50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x115970u; }
        if (ctx->pc != 0x115970u) { return; }
    }
    ctx->pc = 0x115970u;
label_115970:
    // 0x115970: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x115970u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x115974: 0x3e00008  jr          $ra
    ctx->pc = 0x115974u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x115978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x115974u;
            // 0x115978: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1158F0u: goto label_1158f0;
            case 0x115924u: goto label_115924;
            case 0x115948u: goto label_115948;
            case 0x115970u: goto label_115970;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11597Cu;
    // 0x11597c: 0x0  nop
    ctx->pc = 0x11597cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
