#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179E98
// Address: 0x179e98 - 0x179f00
void sub_00179E98_0x179e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179E98_0x179e98");
#endif

    switch (ctx->pc) {
        case 0x179ebcu: goto label_179ebc;
        case 0x179ed0u: goto label_179ed0;
        default: break;
    }

    ctx->pc = 0x179e98u;

    // 0x179e98: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x179e98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x179e9c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x179e9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x179ea0: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x179ea0u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x179ea4: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x179ea4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ea8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x179ea8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x179eac: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x179eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x179eb0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x179eb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x179eb4: 0xc05e756  jal         func_179D58
    ctx->pc = 0x179EB4u;
    SET_GPR_U32(ctx, 31, 0x179EBCu);
    ctx->pc = 0x179EB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x179EB4u;
            // 0x179eb8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179EBCu; }
        if (ctx->pc != 0x179EBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179EBCu; }
        if (ctx->pc != 0x179EBCu) { return; }
    }
    ctx->pc = 0x179EBCu;
label_179ebc:
    // 0x179ebc: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x179ebcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x179ec0: 0x12200009  beqz        $s1, . + 4 + (0x9 << 2)
    ctx->pc = 0x179EC0u;
    {
        const bool branch_taken_0x179ec0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x179EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179EC0u;
            // 0x179ec4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ec0) {
            ctx->pc = 0x179EE8u;
            goto label_179ee8;
        }
    }
    ctx->pc = 0x179EC8u;
    // 0x179ec8: 0xc05e976  jal         func_17A5D8
    ctx->pc = 0x179EC8u;
    SET_GPR_U32(ctx, 31, 0x179ED0u);
    ctx->pc = 0x17A5D8u;
    if (runtime->hasFunction(0x17A5D8u)) {
        auto targetFn = runtime->lookupFunction(0x17A5D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179ED0u; }
        if (ctx->pc != 0x179ED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A5D8_0x17a5d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x179ED0u; }
        if (ctx->pc != 0x179ED0u) { return; }
    }
    ctx->pc = 0x179ED0u;
label_179ed0:
    // 0x179ed0: 0x240300c0  addiu       $v1, $zero, 0xC0
    ctx->pc = 0x179ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 192));
    // 0x179ed4: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x179ED4u;
    {
        const bool branch_taken_0x179ed4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x179ED8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179ED4u;
            // 0x179ed8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x179ed4) {
            ctx->pc = 0x179EE8u;
            goto label_179ee8;
        }
    }
    ctx->pc = 0x179EDCu;
    // 0x179edc: 0x9223001b  lbu         $v1, 0x1B($s1)
    ctx->pc = 0x179edcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 27)));
    // 0x179ee0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x179ee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x179ee4: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x179ee4u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_179ee8:
    // 0x179ee8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x179ee8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x179eec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x179eecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x179ef0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x179ef0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x179ef4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x179ef4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x179ef8: 0x3e00008  jr          $ra
    ctx->pc = 0x179EF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x179EFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x179EF8u;
            // 0x179efc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x179EBCu: goto label_179ebc;
            case 0x179ED0u: goto label_179ed0;
            case 0x179EE8u: goto label_179ee8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x179F00u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
