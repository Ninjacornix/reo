#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001754B0
// Address: 0x1754b0 - 0x175500
void sub_001754B0_0x1754b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001754B0_0x1754b0");
#endif

    switch (ctx->pc) {
        case 0x1754d4u: goto label_1754d4;
        default: break;
    }

    ctx->pc = 0x1754b0u;

    // 0x1754b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1754b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1754b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1754b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1754b8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x1754b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1754bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1754bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1754c0: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1754c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1754c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1754c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1754c8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1754c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1754cc: 0xc05d540  jal         func_175500
    ctx->pc = 0x1754CCu;
    SET_GPR_U32(ctx, 31, 0x1754D4u);
    ctx->pc = 0x1754D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1754CCu;
            // 0x1754d0: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175500u;
    if (runtime->hasFunction(0x175500u)) {
        auto targetFn = runtime->lookupFunction(0x175500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1754D4u; }
        if (ctx->pc != 0x1754D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175500_0x175500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1754D4u; }
        if (ctx->pc != 0x1754D4u) { return; }
    }
    ctx->pc = 0x1754D4u;
label_1754d4:
    // 0x1754d4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1754D4u;
    {
        const bool branch_taken_0x1754d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1754D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1754D4u;
            // 0x1754d8: 0x108080  sll         $s0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1754d4) {
            ctx->pc = 0x1754E4u;
            goto label_1754e4;
        }
    }
    ctx->pc = 0x1754DCu;
    // 0x1754dc: 0x2121021  addu        $v0, $s0, $s2
    ctx->pc = 0x1754dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x1754e0: 0xac510b30  sw          $s1, 0xB30($v0)
    ctx->pc = 0x1754e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 2864), GPR_U32(ctx, 17));
label_1754e4:
    // 0x1754e4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1754e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1754e8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1754e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1754ec: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1754ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1754f0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1754f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1754f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1754F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1754F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1754F4u;
            // 0x1754f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1754D4u: goto label_1754d4;
            case 0x1754E4u: goto label_1754e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1754FCu;
    // 0x1754fc: 0x0  nop
    ctx->pc = 0x1754fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
