#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00174030
// Address: 0x174030 - 0x1740a0
void sub_00174030_0x174030(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00174030_0x174030");
#endif

    switch (ctx->pc) {
        case 0x17404cu: goto label_17404c;
        default: break;
    }

    ctx->pc = 0x174030u;

    // 0x174030: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x174030u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x174034: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x174034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x174038: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x174038u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17403c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17403cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x174040: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x174040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x174044: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x174044u;
    SET_GPR_U32(ctx, 31, 0x17404Cu);
    ctx->pc = 0x174048u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174044u;
            // 0x174048: 0x80882d  daddu       $s1, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17404Cu; }
        if (ctx->pc != 0x17404Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17404Cu; }
        if (ctx->pc != 0x17404Cu) { return; }
    }
    ctx->pc = 0x17404Cu;
label_17404c:
    // 0x17404c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x17404cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x174050: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x174050u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174054: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x174054u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174058: 0x34a50137  ori         $a1, $a1, 0x137
    ctx->pc = 0x174058u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)311);
    // 0x17405c: 0x2406000c  addiu       $a2, $zero, 0xC
    ctx->pc = 0x17405cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x174060: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x174060u;
    {
        const bool branch_taken_0x174060 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x174064u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x174060u;
            // 0x174064: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x174060) {
            ctx->pc = 0x174080u;
            goto label_174080;
        }
    }
    ctx->pc = 0x174068u;
    // 0x174068: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174068u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17406c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17406cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174070: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174070u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174074: 0x805a704  j           func_169C10
    ctx->pc = 0x174074u;
    ctx->pc = 0x174078u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174074u;
            // 0x174078: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17407Cu;
    // 0x17407c: 0x0  nop
    ctx->pc = 0x17407cu;
    // NOP
label_174080:
    // 0x174080: 0xae200960  sw          $zero, 0x960($s1)
    ctx->pc = 0x174080u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2400), GPR_U32(ctx, 0));
    // 0x174084: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x174084u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x174088: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x174088u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17408c: 0x24050006  addiu       $a1, $zero, 0x6
    ctx->pc = 0x17408cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x174090: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x174090u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x174094: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x174094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x174098: 0x805def8  j           func_177BE0
    ctx->pc = 0x174098u;
    ctx->pc = 0x17409Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x174098u;
            // 0x17409c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x177BE0u;
    if (runtime->hasFunction(0x177BE0u)) {
        auto targetFn = runtime->lookupFunction(0x177BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00177BE0_0x177be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1740A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
