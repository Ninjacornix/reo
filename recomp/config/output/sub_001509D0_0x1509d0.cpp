#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001509D0
// Address: 0x1509d0 - 0x150a48
void sub_001509D0_0x1509d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001509D0_0x1509d0");
#endif

    switch (ctx->pc) {
        case 0x1509f4u: goto label_1509f4;
        default: break;
    }

    ctx->pc = 0x1509d0u;

    // 0x1509d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1509d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1509d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1509d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1509d8: 0x24900128  addiu       $s0, $a0, 0x128
    ctx->pc = 0x1509d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 296));
    // 0x1509dc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1509dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1509e0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1509e0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1509e4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1509e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1509e8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1509e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1509ec: 0xc05578e  jal         func_155E38
    ctx->pc = 0x1509ECu;
    SET_GPR_U32(ctx, 31, 0x1509F4u);
    ctx->pc = 0x1509F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1509ECu;
            // 0x1509f0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155E38u;
    if (runtime->hasFunction(0x155E38u)) {
        auto targetFn = runtime->lookupFunction(0x155E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1509F4u; }
        if (ctx->pc != 0x1509F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155E38_0x155e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1509F4u; }
        if (ctx->pc != 0x1509F4u) { return; }
    }
    ctx->pc = 0x1509F4u;
label_1509f4:
    // 0x1509f4: 0x3c05ff03  lui         $a1, 0xFF03
    ctx->pc = 0x1509f4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65283 << 16));
    // 0x1509f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1509f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1509fc: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1509FCu;
    {
        const bool branch_taken_0x1509fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x150A00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1509FCu;
            // 0x150a00: 0x34a5020e  ori         $a1, $a1, 0x20E (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)526);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1509fc) {
            ctx->pc = 0x150A20u;
            goto label_150a20;
        }
    }
    ctx->pc = 0x150A04u;
    // 0x150a04: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150a04u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150a08: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150a08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150a0c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150a0cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150a10: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x150a10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x150a14: 0x805419c  j           func_150670
    ctx->pc = 0x150A14u;
    ctx->pc = 0x150A18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x150A14u;
            // 0x150a18: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150670u;
    if (runtime->hasFunction(0x150670u)) {
        auto targetFn = runtime->lookupFunction(0x150670u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00150670_0x150670(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x150A1Cu;
    // 0x150a1c: 0x0  nop
    ctx->pc = 0x150a1cu;
    // NOP
label_150a20:
    // 0x150a20: 0x8e0200d0  lw          $v0, 0xD0($s0)
    ctx->pc = 0x150a20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 208)));
    // 0x150a24: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x150a24u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x150a28: 0xae220000  sw          $v0, 0x0($s1)
    ctx->pc = 0x150a28u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x150a2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x150a2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x150a30: 0x8e0300d4  lw          $v1, 0xD4($s0)
    ctx->pc = 0x150a30u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 212)));
    // 0x150a34: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x150a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x150a38: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x150a38u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
    // 0x150a3c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x150a3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x150a40: 0x3e00008  jr          $ra
    ctx->pc = 0x150A40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x150A44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x150A40u;
            // 0x150a44: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1509F4u: goto label_1509f4;
            case 0x150A20u: goto label_150a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x150A48u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
