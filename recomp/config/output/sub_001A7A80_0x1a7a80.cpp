#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A7A80
// Address: 0x1a7a80 - 0x1a7b04
void sub_001A7A80_0x1a7a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A7A80_0x1a7a80");
#endif

    switch (ctx->pc) {
        case 0x1a7ac0u: goto label_1a7ac0;
        default: break;
    }

    ctx->pc = 0x1a7a80u;

    // 0x1a7a80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a7a80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a7a84: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1a7a84u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1a7a88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a7a88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a7a8c: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7a8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7a90: 0x8c240a68  lw          $a0, 0xA68($at)
    ctx->pc = 0x1a7a90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7a94: 0x24420a80  addiu       $v0, $v0, 0xA80
    ctx->pc = 0x1a7a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2688));
    // 0x1a7a98: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1a7a98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1a7a9c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1a7a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a7aa0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1a7aa0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a7aa4: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1a7aa4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a7aa8: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1a7aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a7aac: 0x4400006  bltz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1A7AACu;
    {
        const bool branch_taken_0x1a7aac = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1A7AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AACu;
            // 0x1a7ab0: 0x3c024000  lui         $v0, 0x4000 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7aac) {
            ctx->pc = 0x1A7AC8u;
            goto label_1a7ac8;
        }
    }
    ctx->pc = 0x1A7AB4u;
    // 0x1a7ab4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1a7ab4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1a7ab8: 0xc0423b4  jal         func_108ED0
    ctx->pc = 0x1A7AB8u;
    SET_GPR_U32(ctx, 31, 0x1A7AC0u);
    ctx->pc = 0x1A7ABCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AB8u;
            // 0x1a7abc: 0x248422c0  addiu       $a0, $a0, 0x22C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x108ED0u;
    if (runtime->hasFunction(0x108ED0u)) {
        auto targetFn = runtime->lookupFunction(0x108ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7AC0u; }
        if (ctx->pc != 0x1A7AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00108ED0_0x108ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A7AC0u; }
        if (ctx->pc != 0x1A7AC0u) { return; }
    }
    ctx->pc = 0x1A7AC0u;
label_1a7ac0:
    // 0x1a7ac0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1A7AC0u;
    {
        const bool branch_taken_0x1a7ac0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AC0u;
            // 0x1a7ac4: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7ac0) {
            ctx->pc = 0x1A7AF8u;
            goto label_1a7af8;
        }
    }
    ctx->pc = 0x1A7AC8u;
label_1a7ac8:
    // 0x1a7ac8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7ac8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7acc: 0xac620000  sw          $v0, 0x0($v1)
    ctx->pc = 0x1a7accu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1a7ad0: 0x8c220a68  lw          $v0, 0xA68($at)
    ctx->pc = 0x1a7ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a7ad4: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1a7ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1a7ad8: 0x4610004  bgez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7AD8u;
    {
        const bool branch_taken_0x1a7ad8 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1A7ADCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AD8u;
            // 0x1a7adc: 0x3062001f  andi        $v0, $v1, 0x1F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)31);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7ad8) {
            ctx->pc = 0x1A7AECu;
            goto label_1a7aec;
        }
    }
    ctx->pc = 0x1A7AE0u;
    // 0x1a7ae0: 0x10400002  beqz        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A7AE0u;
    {
        const bool branch_taken_0x1a7ae0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a7ae0) {
            ctx->pc = 0x1A7AECu;
            goto label_1a7aec;
        }
    }
    ctx->pc = 0x1A7AE8u;
    // 0x1a7ae8: 0x2442ffe0  addiu       $v0, $v0, -0x20
    ctx->pc = 0x1a7ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967264));
label_1a7aec:
    // 0x1a7aec: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a7aecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a7af0: 0xac220a68  sw          $v0, 0xA68($at)
    ctx->pc = 0x1a7af0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 2));
    // 0x1a7af4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1a7af4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a7af8:
    // 0x1a7af8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a7af8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a7afc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A7AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A7B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7AFCu;
            // 0x1a7b00: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7AC0u: goto label_1a7ac0;
            case 0x1A7AC8u: goto label_1a7ac8;
            case 0x1A7AECu: goto label_1a7aec;
            case 0x1A7AF8u: goto label_1a7af8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A7B04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
