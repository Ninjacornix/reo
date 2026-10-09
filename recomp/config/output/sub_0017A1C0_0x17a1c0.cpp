#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A1C0
// Address: 0x17a1c0 - 0x17a228
void sub_0017A1C0_0x17a1c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A1C0_0x17a1c0");
#endif

    switch (ctx->pc) {
        case 0x17a1e4u: goto label_17a1e4;
        case 0x17a1fcu: goto label_17a1fc;
        default: break;
    }

    ctx->pc = 0x17a1c0u;

    // 0x17a1c0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x17a1c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x17a1c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a1c8: 0x30b000ff  andi        $s0, $a1, 0xFF
    ctx->pc = 0x17a1c8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x17a1cc: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x17a1ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a1d0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x17a1d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x17a1d4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x17a1d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17a1d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x17a1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x17a1dc: 0xc05e756  jal         func_179D58
    ctx->pc = 0x17A1DCu;
    SET_GPR_U32(ctx, 31, 0x17A1E4u);
    ctx->pc = 0x17A1E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1DCu;
            // 0x17a1e0: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x179D58u;
    if (runtime->hasFunction(0x179D58u)) {
        auto targetFn = runtime->lookupFunction(0x179D58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1E4u; }
        if (ctx->pc != 0x17A1E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00179D58_0x179d58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1E4u; }
        if (ctx->pc != 0x17A1E4u) { return; }
    }
    ctx->pc = 0x17A1E4u;
label_17a1e4:
    // 0x17a1e4: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x17a1e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a1e8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17a1e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a1ec: 0x12200008  beqz        $s1, . + 4 + (0x8 << 2)
    ctx->pc = 0x17A1ECu;
    {
        const bool branch_taken_0x17a1ec = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A1F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1ECu;
            // 0x17a1f0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a1ec) {
            ctx->pc = 0x17A210u;
            goto label_17a210;
        }
    }
    ctx->pc = 0x17A1F4u;
    // 0x17a1f4: 0xc05e966  jal         func_17A598
    ctx->pc = 0x17A1F4u;
    SET_GPR_U32(ctx, 31, 0x17A1FCu);
    ctx->pc = 0x17A598u;
    if (runtime->hasFunction(0x17A598u)) {
        auto targetFn = runtime->lookupFunction(0x17A598u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1FCu; }
        if (ctx->pc != 0x17A1FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017A598_0x17a598(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A1FCu; }
        if (ctx->pc != 0x17A1FCu) { return; }
    }
    ctx->pc = 0x17A1FCu;
label_17a1fc:
    // 0x17a1fc: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x17A1FCu;
    {
        const bool branch_taken_0x17a1fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x17A200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A1FCu;
            // 0x17a200: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17a1fc) {
            ctx->pc = 0x17A214u;
            goto label_17a214;
        }
    }
    ctx->pc = 0x17A204u;
    // 0x17a204: 0x92230022  lbu         $v1, 0x22($s1)
    ctx->pc = 0x17a204u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 34)));
    // 0x17a208: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17a208u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17a20c: 0xae430000  sw          $v1, 0x0($s2)
    ctx->pc = 0x17a20cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
label_17a210:
    // 0x17a210: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a210u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_17a214:
    // 0x17a214: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x17a214u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a218: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x17a218u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17a21c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x17a21cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17a220: 0x3e00008  jr          $ra
    ctx->pc = 0x17A220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A224u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A220u;
            // 0x17a224: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A1E4u: goto label_17a1e4;
            case 0x17A1FCu: goto label_17a1fc;
            case 0x17A210u: goto label_17a210;
            case 0x17A214u: goto label_17a214;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A228u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
