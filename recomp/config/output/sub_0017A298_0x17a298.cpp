#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A298
// Address: 0x17a298 - 0x17a308
void sub_0017A298_0x17a298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A298_0x17a298");
#endif

    switch (ctx->pc) {
        case 0x17a2bcu: goto label_17a2bc;
        case 0x17a2d4u: goto label_17a2d4;
        default: break;
    }

    ctx->pc = 0x17a298u;

    // 0x17a298: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a29c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a29cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a2a0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a2a0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a2a4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a2a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a2a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a2a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a2ac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a2acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a2b0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a2b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a2b4: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A2B4u;
    SET_GPR_U32(ctx, 31, 0x17A2BCu);
    ctx->pc = 0x17A2B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A2B4u;
            // 0x17a2b8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2BCu; }
        if (ctx->pc != 0x17A2BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2BCu; }
        if (ctx->pc != 0x17A2BCu) { return; }
    }
    ctx->pc = 0x17A2BCu;
label_17a2bc:
    // 0x17a2bc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a2bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a2c0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a2c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a2c4: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x17A2C4u;
    {
        const bool branch_taken_0x17a2c4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A2C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A2C4u;
            // 0x17a2c8: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a2c4) {
            ctx->pc = 0x17A2F0u;
            goto label_17a2f0;
        }
    }
    ctx->pc = 0x17A2CCu;
    // 0x17a2cc: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A2CCu;
    SET_GPR_U32(ctx, 31, 0x17A2D4u);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2D4u; }
        if (ctx->pc != 0x17A2D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A2D4u; }
        if (ctx->pc != 0x17A2D4u) { return; }
    }
    ctx->pc = 0x17A2D4u;
label_17a2d4:
    // 0x17a2d4: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17A2D4u;
    {
        const bool branch_taken_0x17a2d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A2D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A2D4u;
            // 0x17a2d8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a2d4) {
            ctx->pc = 0x17A2F4u;
            goto label_17a2f4;
        }
    }
    ctx->pc = 0x17A2DCu;
    // 0x17a2dc: 0x92230023  lbu         $v1, 0x23($s1)
    ctx->pc = 0x17a2dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 35)));
    // 0x17a2e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a2e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a2e4: 0x30630010  andi        $v1, $v1, 0x10
    ctx->pc = 0x17a2e4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)16);
    // 0x17a2e8: 0x3182b  sltu        $v1, $zero, $v1
    ctx->pc = 0x17a2e8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x17a2ec: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a2ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a2f0:
    // 0x17a2f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a2f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a2f4:
    // 0x17a2f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a2f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a2f8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a2f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a2fc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a2fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a300: 0x3e00008  jr          $ra
    ctx->pc = 0x17A300u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A300u;
            // 0x17a304: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A2BCu: goto label_17a2bc;
            case 0x17A2D4u: goto label_17a2d4;
            case 0x17A2F0u: goto label_17a2f0;
            case 0x17A2F4u: goto label_17a2f4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A308u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
