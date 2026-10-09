#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175460
// Address: 0x175460 - 0x1754b0
void sub_00175460_0x175460(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175460_0x175460");
#endif

    switch (ctx->pc) {
        case 0x175484u: goto label_175484;
        default: break;
    }

    ctx->pc = 0x175460u;

    // 0x175460: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x175460u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x175464: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175464u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175468: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x175468u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17546c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17546cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x175470: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x175470u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175474: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x175474u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x175478: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x175478u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17547c: 0xc05d540  jal         func_175500
    ctx->pc = 0x17547Cu;
    SET_GPR_U32(ctx, 31, 0x175484u);
    ctx->pc = 0x175480u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17547Cu;
            // 0x175480: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175500u;
    if (runtime->hasFunction(0x175500u)) {
        auto targetFn = runtime->lookupFunction(0x175500u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175484u; }
        if (ctx->pc != 0x175484u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175500_0x175500(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175484u; }
        if (ctx->pc != 0x175484u) { return; }
    }
    ctx->pc = 0x175484u;
label_175484:
    // 0x175484: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x175484u;
    {
        const bool branch_taken_0x175484 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x175488u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175484u;
            // 0x175488: 0x108080  sll         $s0, $s0, 2 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175484) {
            ctx->pc = 0x175494u;
            goto label_175494;
        }
    }
    ctx->pc = 0x17548Cu;
    // 0x17548c: 0x2121021  addu        $v0, $s0, $s2
    ctx->pc = 0x17548cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
    // 0x175490: 0xac5109a0  sw          $s1, 0x9A0($v0)
    ctx->pc = 0x175490u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 2464), GPR_U32(ctx, 17));
label_175494:
    // 0x175494: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175494u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175498: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x175498u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17549c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17549cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1754a0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1754a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1754a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1754A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1754A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1754A4u;
            // 0x1754a8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175484u: goto label_175484;
            case 0x175494u: goto label_175494;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1754ACu;
    // 0x1754ac: 0x0  nop
    ctx->pc = 0x1754acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
