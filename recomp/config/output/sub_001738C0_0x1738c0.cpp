#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001738C0
// Address: 0x1738c0 - 0x173928
void sub_001738C0_0x1738c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001738C0_0x1738c0");
#endif

    switch (ctx->pc) {
        case 0x1738f4u: goto label_1738f4;
        case 0x17390cu: goto label_17390c;
        default: break;
    }

    ctx->pc = 0x1738c0u;

    // 0x1738c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1738c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1738c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1738c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1738c8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1738c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1738cc: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1738ccu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1738d0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1738d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1738d4: 0xc0902d  daddu       $s2, $a2, $zero
    ctx->pc = 0x1738d4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1738d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1738d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1738dc: 0x2630094c  addiu       $s0, $s1, 0x94C
    ctx->pc = 0x1738dcu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 2380));
    // 0x1738e0: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x1738e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1738e4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1738e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1738e8: 0x24050024  addiu       $a1, $zero, 0x24
    ctx->pc = 0x1738e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x1738ec: 0xc05d58a  jal         func_175628
    ctx->pc = 0x1738ECu;
    SET_GPR_U32(ctx, 31, 0x1738F4u);
    ctx->pc = 0x1738F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1738ECu;
            // 0x1738f0: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1738F4u; }
        if (ctx->pc != 0x1738F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1738F4u; }
        if (ctx->pc != 0x1738F4u) { return; }
    }
    ctx->pc = 0x1738F4u;
label_1738f4:
    // 0x1738f4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1738f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1738f8: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1738f8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1738fc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1738FCu;
    {
        const bool branch_taken_0x1738fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173900u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1738FCu;
            // 0x173900: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1738fc) {
            ctx->pc = 0x17390Cu;
            goto label_17390c;
        }
    }
    ctx->pc = 0x173904u;
    // 0x173904: 0x40f809  jalr        $v0
    ctx->pc = 0x173904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x17390Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x17390Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1738F4u: goto label_1738f4;
            case 0x17390Cu: goto label_17390c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x17390Cu; }
            if (ctx->pc != 0x17390Cu) { return; }
        }
        }
    }
    ctx->pc = 0x17390Cu;
label_17390c:
    // 0x17390c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17390cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173910: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x173910u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173914: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x173914u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173918: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x173918u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17391c: 0x3e00008  jr          $ra
    ctx->pc = 0x17391Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17391Cu;
            // 0x173920: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1738F4u: goto label_1738f4;
            case 0x17390Cu: goto label_17390c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173924u;
    // 0x173924: 0x0  nop
    ctx->pc = 0x173924u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
