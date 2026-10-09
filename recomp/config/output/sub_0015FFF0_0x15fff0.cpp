#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015FFF0
// Address: 0x15fff0 - 0x160060
void sub_0015FFF0_0x15fff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015FFF0_0x15fff0");
#endif

    switch (ctx->pc) {
        case 0x16000cu: goto label_16000c;
        default: break;
    }

    ctx->pc = 0x15fff0u;

    // 0x15fff0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15fff0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15fff4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15fff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15fff8: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x15fff8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15fffc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15fffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x160000: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x160000u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x160004: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x160004u;
    SET_GPR_U32(ctx, 31, 0x16000Cu);
    ctx->pc = 0x160008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160004u;
            // 0x160008: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16000Cu; }
        if (ctx->pc != 0x16000Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16000Cu; }
        if (ctx->pc != 0x16000Cu) { return; }
    }
    ctx->pc = 0x16000Cu;
label_16000c:
    // 0x16000c: 0x101940  sll         $v1, $s0, 5
    ctx->pc = 0x16000cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 16), 5));
    // 0x160010: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x160010u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x160014: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x160014u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x160018: 0x2484f4e8  addiu       $a0, $a0, -0xB18
    ctx->pc = 0x160018u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294964456));
    // 0x16001c: 0x24050036  addiu       $a1, $zero, 0x36
    ctx->pc = 0x16001cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 54));
    // 0x160020: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x160020u;
    {
        const bool branch_taken_0x160020 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x160024u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x160020u;
            // 0x160024: 0x31880  sll         $v1, $v1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x160020) {
            ctx->pc = 0x160040u;
            goto label_160040;
        }
    }
    ctx->pc = 0x160028u;
    // 0x160028: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160028u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16002c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16002cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160030: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160034: 0x8058dd4  j           func_163750
    ctx->pc = 0x160034u;
    ctx->pc = 0x160038u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160034u;
            // 0x160038: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16003Cu;
    // 0x16003c: 0x0  nop
    ctx->pc = 0x16003cu;
    // NOP
label_160040:
    // 0x160040: 0x703021  addu        $a2, $v1, $s0
    ctx->pc = 0x160040u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x160044: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x160044u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x160048: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x160048u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16004c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x16004cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x160050: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x160050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x160054: 0x630c0  sll         $a2, $a2, 3
    ctx->pc = 0x160054u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 3));
    // 0x160058: 0x8057fae  j           func_15FEB8
    ctx->pc = 0x160058u;
    ctx->pc = 0x16005Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x160058u;
            // 0x16005c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FEB8u;
    if (runtime->hasFunction(0x15FEB8u)) {
        auto targetFn = runtime->lookupFunction(0x15FEB8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015FEB8_0x15feb8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x160060u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
