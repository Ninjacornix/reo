#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00160548
// Address: 0x160548 - 0x1605b8
void sub_00160548_0x160548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00160548_0x160548");
#endif

    switch (ctx->pc) {
        case 0x16056cu: goto label_16056c;
        default: break;
    }

    ctx->pc = 0x160548u;

    // 0x160548: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x160548u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16054c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16054cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x160550: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x160550u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160554: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x160554u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160558: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x160558u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16055c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x16055cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x160560: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x160560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x160564: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160564u;
    SET_GPR_U32(ctx, 31, 0x16056Cu);
    ctx->pc = 0x160568u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160564u;
            // 0x160568: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16056Cu; }
        if (ctx->pc != 0x16056Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16056Cu; }
        if (ctx->pc != 0x16056Cu) { return; }
    }
    ctx->pc = 0x16056Cu;
label_16056c:
    // 0x16056c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16056cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160570: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x160570u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x160574: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x160574u;
    {
        const bool branch_taken_0x160574 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160574u;
            // 0x160578: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160574) {
            ctx->pc = 0x1605A0u;
            goto label_1605a0;
        }
    }
    ctx->pc = 0x16057Cu;
    // 0x16057c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16057cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160580: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160580u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160584: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x160584u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160588: 0x2484f718  addiu       $a0, $a0, -0x8E8
    ctx->pc = 0x160588u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294965016));
    // 0x16058c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x16058cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160590: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x160590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x160594: 0x8058dd4  j           func_163750
    ctx->pc = 0x160594u;
    ctx->pc = 0x160598u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160594u;
            // 0x160598: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16059Cu;
    // 0x16059c: 0x0  nop
    ctx->pc = 0x16059cu;
    // NOP
label_1605a0:
    // 0x1605a0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1605a0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1605a4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1605a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1605a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1605a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1605ac: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1605acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1605b0: 0x8057df0  j           func_15F7C0
    ctx->pc = 0x1605B0u;
    ctx->pc = 0x1605B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1605B0u;
            // 0x1605b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F7C0u;
    if (runtime->hasFunction(0x15F7C0u)) {
        auto targetFn = runtime->lookupFunction(0x15F7C0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015F7C0_0x15f7c0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1605B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
